#include "Servo.hpp"
#include <hardware/pwm.h>
#include <pico/assert.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <stdio.h>
#include <vector>

#include <hardware/adc.h>

int main() {
    stdio_init_all();

    int angle = 0;
    bool isRunning = true;

    adc_init();

    // Assuming Sensor1 is connected to GP26 (ADC0)
    // Verify in your Servo2040 documentation if Sensor1 is indeed on GP26.
    const uint sensor1_pin = 26; // GP26 supports ADC input (channel 0)
    adc_gpio_init(sensor1_pin);

    // Select ADC channel 0 which corresponds to GP26
    adc_select_input(0);

    control::Servo servo({0, 180}, 1);

    while (true) {
        // Read the 12-bit ADC value (range 0-4095)
        uint16_t raw_value = adc_read();

        // Convert the raw ADC reading to voltage (3.3V reference)
        float voltage = (raw_value * 3.3f) / 4095.0f;
        printf("Raw ADC Value: %u, Voltage: %.2fV\n", raw_value, voltage);

        servo.setAngle(voltage * 180 / 3.3);

        sleep_ms(20);
    }

    return 0;
}
