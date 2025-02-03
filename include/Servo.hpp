#pragma once

#include <pico/stdio.h>
#include <pico/stdlib.h>

#define MIN_PULSE 544
#define MAX_PULSE 2400

namespace control {
    class Servo {
    public:
        struct Model {
            const enum class Name {
                SG90,
                PDI_1109MG
            } name;
            const int16_t physicalMinAngle;
            const int16_t physicalMaxAngle;
        };

        static const Model models[];

    private:
        uint8_t _pin;
        Model _model;

        int16_t _minAngle;
        int16_t _maxAngle;

        float _angle;

        void _writeAngle();

    public:
        explicit Servo(Model model, uint8_t pin);
        explicit Servo(Model model, uint8_t pin, int16_t minAngle, int16_t maxAngle);
        ~Servo() = default;

        uint8_t getPin() const;
        void setPin(uint8_t pin);


        int16_t getMinAngle() const;
        void setMinAngle(int16_t minAngle);
        int16_t getMaxAngle() const;
        void setMaxAngle(int16_t maxAngle);

        float getAngle() const;
        void setAngle(float angle);
        void forceSetAngle(float angle);

        void addAngle(float angle);
    };
}

#define MODEL_SG90      control::Servo::models[0]
#define MODEL_PDI_1109MG    control::Servo::models[1]
