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

    while (isRunning) {
        printf("Hello world\n");
        sleep_ms(1000);

    }
}
