#pragma once

#include <cstdint>
#include <hardware/pwm.h>

namespace control {
    class PWMHandler {
    private:
        static const uint16_t _pwmWrap;
        static const float _clkDiv;
        static pwm_config _config;

        __attribute__((constructor)) static void init();

    public:
        static void initPort(uint gpioPin);
    };
}
