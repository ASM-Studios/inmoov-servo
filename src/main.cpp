#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include "../include/macros.hpp"

const uint SERVO_GPIO = SERVO_18;
const uint16_t PWM_WRAP = 20000;
const float CLOCK_DIV = 125.0f;
const uint16_t MIN_PULSE = 500;
const uint16_t MAX_PULSE = 2500;

void setup_servo(uint gpio_pin) {
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, PWM_WRAP);
    pwm_config_set_clkdiv(&config, CLOCK_DIV);

    pwm_init(slice_num, &config, true);
}

void set_servo_angle(uint gpio_pin, float angle) {
    uint16_t pulse_width = MIN_PULSE + (angle / 180.0f) * (MAX_PULSE - MIN_PULSE);
    pwm_set_gpio_level(gpio_pin, pulse_width);
}

int main() {
    uint16_t a;
    setup_servo(SERVO_GPIO);

    while (true) {
        set_servo_angle(SERVO_GPIO, 180);
        sleep_ms(1000);
        set_servo_angle(SERVO_GPIO, 0);
        sleep_ms(1000);
    }
}
