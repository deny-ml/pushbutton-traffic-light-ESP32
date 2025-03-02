#include <Arduino.h>

#define TOMBOL1 18
#define TOMBOL2 19
#define TOMBOL3 21

#define LAMPU_MERAH 17
#define LAMPU_KUNING 16
#define LAMPU_HIJAU 15

void setup() {
  Serial.begin(115200);
  Serial.println("Sistem Lampu Lalu Lintas");

  pinMode(TOMBOL1, INPUT_PULLUP);
  pinMode(TOMBOL2, INPUT_PULLUP);
  pinMode(TOMBOL3, INPUT_PULLUP);

  pinMode(LAMPU_MERAH, OUTPUT);
  pinMode(LAMPU_KUNING, OUTPUT);
  pinMode(LAMPU_HIJAU, OUTPUT);
}

void loop() {
  if (digitalRead(TOMBOL1) == LOW) {
    Serial.println("Tombol 1 ditekan: Lampu merah berkedip 5 kali");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LAMPU_MERAH, HIGH);
      delay(500);
      digitalWrite(LAMPU_MERAH, LOW);
      delay(500);
    }
  }

  if (digitalRead(TOMBOL2) == LOW) {
    Serial.println("Tombol 2 ditekan: Lampu merah & hijau berkedip bergantian");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LAMPU_MERAH, HIGH);
      digitalWrite(LAMPU_HIJAU, LOW);
      delay(500);
      digitalWrite(LAMPU_MERAH, LOW);
      digitalWrite(LAMPU_HIJAU, HIGH);
      delay(500);
    }
    digitalWrite(LAMPU_HIJAU, LOW);
  }

  if (digitalRead(TOMBOL3) == LOW) {
    Serial.println("Tombol 3 ditekan: Lampu merah, kuning, hijau berkedip bergantian");
    for (int i = 0; i < 5; i++) {
      digitalWrite(LAMPU_MERAH, HIGH);
      digitalWrite(LAMPU_KUNING, LOW);
      digitalWrite(LAMPU_HIJAU, LOW);
      delay(500);
      digitalWrite(LAMPU_MERAH, LOW);
      digitalWrite(LAMPU_KUNING, HIGH);
      digitalWrite(LAMPU_HIJAU, LOW);
      delay(500);
      digitalWrite(LAMPU_MERAH, LOW);
      digitalWrite(LAMPU_KUNING, LOW);
      digitalWrite(LAMPU_HIJAU, HIGH);
      delay(500);
    }
    digitalWrite(LAMPU_HIJAU, LOW);
  }
}