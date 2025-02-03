#pragma once

#include <WString.h>

#include "Servo.hpp"

namespace control {
    template <unsigned int NoRoute>
    class Router {
    private:
        struct Route {
            String route;
            Servo& object;
            Route() = default;
        };

        Route _routes[NoRoute];

    public:
        Router() {

        };
        ~Router() = default;

        Servo& findRoute(String routeName) {
            for (auto& route: this->_routes) {
                if (route == routeName) {
                    return route.objet;
                }
            }
        }

        void createRoute(String route, Servo& servo) {
            Route set{route, servo};
            this->_routes[0] = set;
        }
    };
}
