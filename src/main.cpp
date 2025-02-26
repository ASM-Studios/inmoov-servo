#include <stdio.h>
#include <pico/assert.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "Servo.hpp"

#include <vector>

int main() {
    stdio_init_all();

    int angle = 0;
    bool isRunning = true;
    std::vector<control::Servo> servos;
    for (int i = 0; i < 18; i++) {
        servos.push_back(control::Servo({0, 180}, i));
    }

    while (isRunning) {
        for (auto &servo : servos) {
            servo.setAngle(0);
        }
        sleep_ms(1000);
        for (auto &servo : servos) {
            servo.setAngle(180);
        }
        sleep_ms(1000);
    }
}
