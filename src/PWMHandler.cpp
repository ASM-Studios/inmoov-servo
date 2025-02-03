#include <hardware/gpio.h>
#include <hardware/pwm.h>

#include "../include/PWMHandler.hpp"

namespace control {
    void PWMHandler::init() {
        _config = pwm_get_default_config();

        pwm_config_set_wrap(&_config, _pwmWrap);
        pwm_config_set_clkdiv(&_config, _clkDiv);
    }

    void PWMHandler::initPort(uint gpioPin) {
        gpio_set_function(gpioPin, GPIO_FUNC_PWM);

        uint sliceNum = pwm_gpio_to_slice_num(gpioPin);
        pwm_init(sliceNum, &_config, true);
    }

    constexpr uint16_t PWMHandler::_pwmWrap = 20000;
    constexpr float PWMHandler::_clkDiv = 125.0f;
    pwm_config PWMHandler::_config;
}
