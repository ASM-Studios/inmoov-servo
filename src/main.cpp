#include <pico/assert.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "Servo.hpp"

int main() {
    stdio_init_all();

    bool isRunning = true;
    control::Servo servo(MODEL_PDI_1109MG, 0);
    control::Servo servo2(MODEL_SG90, 1);

    while (isRunning) {
        servo.setAngle(0);
        servo2.setAngle(0);
        sleep_ms(1000);

        servo.setAngle(180);
        servo2.setAngle(180);
        sleep_ms(1000);
    }
}
