#include <Arduino.h>
#include "../include/Servo.hpp"

namespace control {
    constexpr Servo::Model Servo::models[] = {
            {Model::Name::PDI_1109MG, 0, 180}
    };

    void Servo::_writeAngle() {
        int us = map(this->_angle, this->_model.physicalMinAngle, this->_model.physicalMaxAngle, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
        this->_servo.writeMicroseconds(us);
    }

    Servo::Servo(Model model) : _pin(0), _model(model), _minAngle(model.physicalMinAngle), _maxAngle(model.physicalMaxAngle) {}

    Servo::Servo(Model model, uint8_t pin) : _pin(pin), _model(model), _minAngle(model.physicalMinAngle), _maxAngle(model.physicalMaxAngle) {
        this->_servo.attach(pin);
    }

    Servo::Servo(Model model, uint8_t pin, int16_t minAngle, int16_t maxAngle) :
        _pin(pin),
        _model(model),
        _minAngle((minAngle < model.physicalMinAngle) ? model.physicalMinAngle : minAngle),
        _maxAngle((maxAngle > model.physicalMaxAngle) ? model.physicalMaxAngle : maxAngle) {
            if (this->_minAngle < this->_model.physicalMinAngle) {
                this->_minAngle = this->_model.physicalMinAngle;
            }
            if (this->_maxAngle > this->_model.physicalMaxAngle) {
                this->_maxAngle = this->_model.physicalMaxAngle;
            }
            this->_servo.attach(pin);
        }

    uint8_t Servo::getPin() const {
        return this->_pin;
    }

    void Servo::setPin(uint8_t pin) {
        this->_pin = pin;
        this->_servo.attach(pin);
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
        this->_angle = constrain(angle, this->_minAngle, this->_maxAngle);
        this->_writeAngle();
    }

    void Servo::forceSetAngle(float angle) {
        this->_angle = constrain(angle, this->_model.physicalMinAngle, this->_model.physicalMaxAngle);
        this->_writeAngle();
    }

    void Servo::addAngle(float angle) {
        this->setAngle(this->_angle + angle);
    }
}
