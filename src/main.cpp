#include <Arduino.h>
#include <Servo.h>


const int motor_left_pin = 12;
const int motor_right_pin = 11;

Servo motor_left;
Servo motor_right;

void setup() {
  motor_left.attach(motor_left_pin);
  motor_right.attach(motor_right_pin);

  pinMode(motor_left_pin, OUTPUT);
  pinMode(motor_right_pin, OUTPUT);
  Serial.begin(9600);
}

void leftMotorControl(int value) {
  motor_left.write(map(value, -100, 100, 1000, 2000));
}

void rightMotorControl(int value) {
  motor_right.write(map(value, -100, 100, 1000, 2000));
}


void adelante() {
  Serial.print("Adelante");
  leftMotorControl(100);
  rightMotorControl(-100);
}

void atras() {
  Serial.println("Atras");
  leftMotorControl(-100);
  rightMotorControl(100);
}

void izquierda() {
  Serial.println("Izquierda");
  leftMotorControl(-100);
  rightMotorControl(100);
}

void derecha() {
  Serial.println("Derecha");
  leftMotorControl(100);
  rightMotorControl(-100);
}

void detener() {
  leftMotorControl(0);
  rightMotorControl(0);
}

void loop() {

  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    switch (receivedChar) {
      case 'w':
        adelante();
        break;
      case 's':
        atras();
        break;
      case 'a':
        izquierda();
        break;
      case 'd':
        derecha();
        break;
      case 'x':
        detener();
        break;
    }
  }
}
