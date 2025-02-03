#pragma once

#include "Servo.h"

namespace control {
    class Servo {
    private:
        float _angle;
        ::Servo _servo;

        void _writeAngle();

    public:
        Servo(uint8_t pin);
        ~Servo() = default;

        float getAngle() const;
        void setAngle(float angle);

        void addAngle(float angle);
    };
}
