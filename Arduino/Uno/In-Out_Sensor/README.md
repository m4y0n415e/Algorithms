# Licznik osób bazujący na synagle wejścia/wyjścia (Arduino Uno + wyswietlacz OLED)

Ten projekt implementuje inteligentny licznik osób wchodzących i wychodzących z pomieszczenia, wykorzystując Arduino Uno i dwa czujniki bariery podczerwieni (IR).

## Zasada działania

Kierunek przejścia jest określany na podstawie **kolejności aktywacji** dwóch czujników:
* **Wejście:** Czujnik bliżej wejścia aktywowany jako pierwszy.
* **Wyjście:** Czujnik bliżej sali aktywowany jako pierwszy (z zabezpieczeniem, aby licznik nie zszedł poniżej 0).

## Wymagany sprzęt

* Kontroler Arduino Uno
* Wyświetlacz OLED 128x64 (SSD1306, I2C)
* 2x Czujnik bariery podczerwieni (IR Beam Break Sensor)

## Wymagane biblioteki

Projekty wymagają zainstalowania bibliotek przez Menedżera Bibliotek Arduino IDE:
1.  `Adafruit SSD1306`
2.  `Adafruit GFX Library`

## Maja Rudnicka

[@m4y0n415e]