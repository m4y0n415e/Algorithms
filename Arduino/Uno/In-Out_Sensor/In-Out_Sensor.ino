#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// KONFIGURACJA WYSWIETLACZA
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Adres I2C wyswietlacza (najczesciej 0x3C lub 0x3D)
#define OLED_RESET -1       
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
// I2C uzywa pinow A4 (SDA) i A5 (SCL)

// KONFIGURACJA CZUJNIKOW - ich piny
const int PIN_SENSOR_1 = 2;
const int PIN_SENSOR_2 = 3;

// Stan czujnikow (przerwana wiazka czujnika IR = LOW)
const int ACTIVE = LOW; 

// Maksymalny czas w milisekundach, w jakim obie aktywacje musza nastapic, aby interpretowac 1. przejscie
const unsigned long MAX_PASS_TIME = 1000;

// ZMIENNE GLOBALNE I VOLATILE
volatile int PeopleCounter = 0;

// Zmienne do sledzenia czasu i stanu
unsigned long time_S1 = 0;
unsigned long time_S2 = 0;

// Flagi informujace, czy czujnik byl aktywowany
volatile bool S1_Active = false;
volatile bool S2_Active = false;

void setDisplay(const char* event) {
  display.clearDisplay();

  display.setCursor(0, 0); 
  display.setTextSize(2);
  display.print(event); 
  
  display.setCursor(0, 18); 
  display.setTextSize(2); 
  display.print("OSOBY:");
  
  display.setTextSize(3); 
  display.setCursor(70, 18);
  
  // Pobranie aktualnej wartosci licznika
  noInterrupts();
  int currentCount = PeopleCounter;
  interrupts();
  
  display.print(currentCount); 

  display.display(); // Wyslanie i wyswietlenie
}

// OBSŁUGA PRZERWAŃ (ISR - Interrupt Service Routines)
// ----------------------------------------------------
// Wywolywane, gdy SENSOR_1 aktywuje sie (zbocze opadajace: HIGH -> LOW)
void operateS1() {
  if (!S1_Active) { // Sprawdzamy, czy juz nie jest aktywowany
    time_S1 = millis();
    S1_Active = true;
  }
}
// Wywolywane, gdy SENSOR_2 aktywuje sie (zbocze opadajace: HIGH -> LOW)
void operateS2() {
  if (!S2_Active) {
    time_S2 = millis();
    S2_Active = true;
  }
}

void setup() {
  Serial.begin(9600);
  
  // Konfiguracja pinow z wewnetrznym rezystorem podciagajacym
  // Zapewnia to stan HIGH, gdy wiazka jest nienaruszona
  pinMode(PIN_SENSOR_1, INPUT_PULLUP); 
  pinMode(PIN_SENSOR_2, INPUT_PULLUP);
  
  // Uruchomienie przerwań sprzętowych dla precyzyjnego pomiaru czasu
  // PIN 2 (Interrupt 0)
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_1), operateS1, FALLING); 
  // PIN 3 (Interrupt 1)
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_2), operateS2, FALLING);
  
  // INICJALIZACJA WYSWIETLACZA
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("ERROR: SSD1306 display NOT FOUND."));
    // Jesli wyswietlacz nie dziala, system nie rusza dalej
    for(;;); 
  }
  display.display(); 
  delay(2000); 
  display.clearDisplay();
  
  // Wstepne wyswietlenie stanu
  setDisplay("START"); 

  Serial.println("Counter system: at work.");
}

void loop() {
  
  // Czy czujniki zostaly aktywowane
  if (S1_Active && S2_Active) {
    
    // Pobranie aktualnej wartosci licznika
    noInterrupts();
    int currentCount = PeopleCounter;
    unsigned long local_time_S1 = time_S1;
    unsigned long local_time_S2 = time_S2;
    interrupts();
    
    // 1. Sprawdzenie czasu (czy jest 1. przejscie?)
    unsigned long timeDiff = max(local_time_S1, local_time_S2) - min(local_time_S1, local_time_S2);
    
    if (timeDiff < MAX_PASS_TIME) {
      
      // 2. Decyzja o kierunku
      if (local_time_S2 < local_time_S1) { 
        // SENSOR_2 aktywowany PIERWSZY: Wyjscie (S2 -> S1)
        
        if (aktualnyLicznik > 0) { 
            noInterrupts();
            PeopleCounter--; // Zmniejsz tylko, jesli w sali jest co najmniej 1. osoba
            interrupts();
            Serial.print("OUT (-)");
            setDisplay("WYJSCIE (-1)"); 
        } else {
            Serial.print("ERROR/IGNORED OUT (Counter = 0)");
            setDisplay("IGNOROWANE"); 
        }
        
      } else { 
        // SENSOR_1 aktywowany PIERWSZY: Wejscie (S1 -> S2)
        noInterrupts();
        PeopleCounter++; 
        interrupts();
        Serial.print("IN (+)");
        setDisplay("WEJSCIE (+1)"); 
      }
      
      // Ponowne pobranie (po modyfikacji) dla Serial Monitor
      noInterrupts();
      currentCount = PeopleCounter;
      interrupts();

      Serial.print("Number of people in the room: ");
      Serial.println(currentCount);
      
    } else {
      Serial.println("Movement ignored: Incorrect time difference.");
    }

    // 3. Reset flag po przetworzeniu zdarzenia
    noInterrupts();
    S1_Active = false; 
    S2_Active = false;
    time_S1 = 0;
    time_S2 = 0;
    interrupts();
    return;
  } 
  
  unsigned long currentTime = millis();
  
  // Sprawdzenie SENSOR_1
  if (S1_Active && !S2_Active && (currentTime - time_S1 > MAX_PASS_TIME)) {
    
    noInterrupts();
    S1_Aktywowany = false;
    czas_S1 = 0;
    interrupts();
    
    Serial.println("RESET: S1 active, no response from S2.");
    setDisplay("RESET", "S1");
  }
  
  // Sprawdzenie SENSOR_2
  if (S2_Active && !S1_Active && (currentTime - time_S2 > MAX_PASS_TIME)) {
    
    noInterrupts();
    S2_Active = false;
    time_S2 = 0;
    interrupts();
    
    Serial.println("RESET: S2 active, no response from S1.");
    setDisplay("RESET", "S2");
  }
}
