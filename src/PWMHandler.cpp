#include "../include/PWMHandler.hpp"
#include <hardware/pwm.h>

namespace control {
    void PWMHandler::init() {
        _config = pwm_get_default_config();

        pwm_config_set_wrap(&_config, _pwmWrap);
        pwm_config_set_clkdiv(&_config, _clkDiv);
    }

    void PWMHandler::initPort(uint gpioPin) {
        uint sliceNum = pwm_gpio_to_slice_num(gpioPin);
        pwm_init(sliceNum, &_config, true);
    }
}
