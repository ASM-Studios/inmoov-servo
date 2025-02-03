#include "Arduino.h"
#include "../include/Servo.hpp"

__attribute__((constructor)) void initBoard() {
    init();
}

void loop(control::Servo& servo) {
    while (true) {
        for (float i = 0; i < 180; i += 0.1) {
            servo.setAngle(i);
            delay(1);
        }
        for (float i = 180; i > 0; i -= 0.1) {
            servo.setAngle(i);
            delay(1);
        }
    }
}

int main() {
    control::Servo servo(13);

    loop(servo);
    return 0;
}
