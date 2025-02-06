#include <Arduino.h>
#include "../include/Servo.hpp"
#include "pins_arduino.h"

__attribute__((constructor)) void initBoard() {
    init();
}

int main() {
    pinMode(LED_BUILTIN, OUTPUT);
    control::Servo servo(control::Servo::models[0], 7, 0, 180);

    while (true) {
        servo.setAngle(0);
        delay(1000);
        servo.setAngle(200);
        delay(1000);
    }
}
