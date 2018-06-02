#include <Motor.h>
#include <Servo.h>
 
Motor L298N_0(10, 9, 8, 11, 12, 13);
Servo servo_0;
void Forword() {
    L298N_0.run(1, true, 50);
    L298N_0.run(2, true, 50);
}
void Back() {
    L298N_0.run(1, false, 50);
    L298N_0.run(2, false, 50);
}
void Right() {
    L298N_0.run(1, true, 50);
    L298N_0.run(2, false, 50);
}
void Left() {
    L298N_0.run(1, false, 50);
    L298N_0.run(2, false, 50);
}
void Stop() {
    L298N_0.stop(1);
    L298N_0.stop(2);
}

void setup() {
    Serial.begin(9600);
    servo_0.attach(3);
    servo_0.write(90);
    L298N_0.stop(1);
    L298N_0.stop(2);
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
                Right();
                break;
            case '4':
                Left();
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