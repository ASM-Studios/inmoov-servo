#include <Arduino.h>
#include "../include/Servo.hpp"

namespace control {
    void Servo::_writeAngle() {
        int us = map(this->_angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
        this->_servo.writeMicroseconds(us);
    }

    Servo::Servo(uint8_t pin) {
        this->_servo.attach(pin);
    }

    float Servo::getAngle() const {
        return this->_angle;
    }

    void Servo::setAngle(float angle) {
        this->_angle = angle;
        if (this->_angle < 0) {
            this->_angle = 0;
        } else if (this->_angle > 180) {
            this->_angle = 180;
        }
        this->_writeAngle();
    }

    void Servo::addAngle(float angle) {
        this->setAngle(this->_angle + angle);
    }
}
