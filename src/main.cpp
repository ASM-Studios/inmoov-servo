#include <stdio.h>
#include <pico/assert.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "Servo.hpp"

int main() {
    stdio_init_all();

    int angle = 0;
    bool isRunning = true;
    control::Servo servo({0, 180}, 0);

    while (isRunning) {
        scanf("%d", &angle);
        servo.setAngle(angle);
        sleep_ms(1000);
    }
}
