#pragma once

#include <cstdint>
#include <hardware/pwm.h>

namespace control {
    class PWMHandler {
    private:
        static constexpr uint16_t _pwmWrap = 20000;
        static constexpr float _clkDiv = 125.0f;
        static pwm_config _config;

        __attribute__((constructor)) static void init();

    public:
        static void initPort(uint gpioPin);
    };
}
