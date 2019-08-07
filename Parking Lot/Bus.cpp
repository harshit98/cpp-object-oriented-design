#pragma once

#include "Bus.h"

Bus::Bus() {
    spotsNeeded[SMALL] = 0;
    spotsNeeded[COMPACT] = 0;
    spotsNeeded[LARGE] = 5;
}
