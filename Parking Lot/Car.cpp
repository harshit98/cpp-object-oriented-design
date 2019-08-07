#pragma once

#include "Car.h"

Car::Car() {
    spotsNeeded[SMALL] = 0;
    spotsNeeded[COMPACT] = 1;
    spotsNeeded[LARGE] = 1;
}
