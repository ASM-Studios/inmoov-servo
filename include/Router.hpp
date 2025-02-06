#pragma once

#include <WString.h>

#include "Servo.hpp"

namespace control {
    template <unsigned int N>
    class Router {
    private:
        struct Route {
            String route;
            Servo object;
        };

        Route _routes[N];

    public:
        Router() = default;
        Router(const Router& other) = delete;
        ~Router() = default;

        void defineRoute(String route, Servo& servo);
    };
}
