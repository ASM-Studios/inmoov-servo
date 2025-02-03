#include <hardware/pwm.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>

#include "Servo.hpp"
#include "PWMHandler.hpp"
#include "utils.hpp"

namespace control {
    constexpr Servo::Model Servo::models[] = {
        {Model::Name::SG90, 0, 180},
        {Model::Name::PDI_1109MG, 0, 180}
    };

    void Servo::_writeAngle() {
        uint16_t us = map(static_cast<float>(this->_angle), static_cast<float>(this->_minAngle), static_cast<float>(this->_maxAngle),
                static_cast<float>(MIN_PULSE), static_cast<float>(MAX_PULSE));
        pwm_set_gpio_level(this->_pin, us);
    }

    Servo::Servo(Model model, uint8_t pin) :
        _pin(pin),
        _model(model),
        _minAngle(model.physicalMinAngle),
        _maxAngle(model.physicalMaxAngle) {
            PWMHandler::initPort(this->_pin);
        }

    Servo::Servo(Model model, uint8_t pin, int16_t minAngle, int16_t maxAngle) :
        _pin(pin),
        _model(model),
        _minAngle((minAngle < model.physicalMinAngle) ? model.physicalMinAngle : minAngle),
        _maxAngle((maxAngle > model.physicalMaxAngle) ? model.physicalMaxAngle : maxAngle) {
            PWMHandler::initPort(this->_pin);
        }

    uint8_t Servo::getPin() const {
        return this->_pin;
    }

    void Servo::setPin(uint8_t pin) {
        this->_pin = pin;
        PWMHandler::initPort(this->_pin);
    }

    int16_t Servo::getMinAngle() const {
        return this->_minAngle;
    }

    void Servo::setMinAngle(int16_t min) {
        this->_minAngle = min;
    }

    int16_t Servo::getMaxAngle() const {
        return this->_maxAngle;
    }

    void Servo::setMaxAngle(int16_t max) {
        this->_maxAngle = max;
    }

    float Servo::getAngle() const {
        return this->_angle;
    }

    void Servo::setAngle(float angle) {
        this->_angle = angle;
        this->_writeAngle();
    }

    void Servo::forceSetAngle(float angle) {
        this->_angle = angle;
        this->_writeAngle();
    }

    void Servo::addAngle(float angle) {
        this->setAngle(this->_angle + angle);
    }
}
