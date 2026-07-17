
#include <Arduino.h>

bool started = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);  // Красный
  pinMode(7, OUTPUT);  // Желтый
  pinMode(10, OUTPUT);  // Зеленый
}

void loop() {

    if (digitalRead(2) == HIGH)
    {
    started = true;
    }

  // Пока кнопку ни разу не нажали - ничего не делаем
    if (!started)
    {
    return;
    } // Кнопка нажата

    {
        digitalWrite(5, HIGH); // Загорается красный
        delay(4000);
        for (int i = 0; i < 3; i++) // Загорается мигающий желтый
        {
            digitalWrite(7, HIGH);
            delay(300);
            digitalWrite(7, LOW);
            delay(300);
        }
        digitalWrite(5, LOW); // Красный погас, желтый тоже
        digitalWrite(10, HIGH); // Загорается зеленый
        delay(4000);
        for (int i = 0; i < 4; i++)
        {
            digitalWrite(10, HIGH);
            delay(300);
            digitalWrite(10, LOW);
            delay(300);
        }
        digitalWrite(7, HIGH);
        delay(2000);
        digitalWrite(7, LOW);
    }
}