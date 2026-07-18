
#include <Arduino.h>

bool started = false;

void setup() {
  pinMode(2, INPUT);   // внешний pull-down резистор уже есть
  pinMode(5, OUTPUT);  // Красный
  pinMode(7, OUTPUT);  // Желтый
  pinMode(10, OUTPUT); // Зеленый
}

void loop() {
  // Ловим нажатие (HIGH, потому что кнопка замыкает на 5V)
  if (digitalRead(2) == HIGH) {
    started = true;
  }

  if (!started) {
    return;
  }

  // 1. Красный 4 сек
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  delay(4000);

  // 2. Зелёный 4 сек
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
  delay(4000);

  // 3. Зелёный мигает 4 раза
  for (int i = 0; i < 4; i++) {
    digitalWrite(10, LOW);
    delay(300);
    digitalWrite(10, HIGH);
    delay(300);
  }
  digitalWrite(10, LOW); // выключаем зелёный

  // 4. Жёлтый 2 сек
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(7, LOW);
}
