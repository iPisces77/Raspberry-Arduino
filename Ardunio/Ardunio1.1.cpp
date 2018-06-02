#include <Motor.h>
#include <Servo.h>
 
Motor L298N_0(10, 11, 12, 9, 8, 7);
Servo servo_0;
void Forword() {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
}
void Back() {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
}
void Right() {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
}
void Left() {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
}
void Stop() {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
}

void setup() {
    Serial.begin(9600);
    servo_0.attach(3);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    servo_0.write(90);
}

void loop() {
    if (Serial.available()) {
        char cmd = Serial.read();
        Serial.println(Serial.read());
        switch (cmd) {
            case '1':
                Forword();
                break;
            case '2':
                Back();
                break;
            case '3':
                Left();
                break;
            case '4':
                Right();
                break;
            case '5':
                servo_0.write(135);
                break;
            case '6':
                servo_0.write(45);
                break;
            case '7':
                servo_0.write(90);
                break;
            default:
                Stop();
                break;

        }
    }
}