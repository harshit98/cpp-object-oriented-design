#include <iostream>
#include <string>

#include "ParkingSpot.h"

using namespace std;

ParkingSpot::ParkingSpot(unsigned int floor, unsigned int row, unsigned int pos, VEHICLE_SIZE size) {
    this->floorNum = floor;
    this->posNum = pos;
    this->rowNum = row;
    this->isParkingAvailable = true;
}

bool ParkingSpot::isAvailable() {
    return this->isParkingAvailable;
}

void ParkingSpot::setAvailability(bool a) {
    this->isParkingAvailable = a; 
}

void ParkingSpot::printSpotInfo() {
    string state;

    if (isParkingAvailable) {
        state = "[ E ]"; // empty
    } else {
        state = "[ F ]"; // full
    }

    switch (vehicleSize) {
        case SMALL:
            cout << "S";
            state += " ";
            break;
        
        case COMPACT:
            cout << "C";
            state += "- ";
            break;

        case LARGE:
            cout << "L";
            state += "-- ";
            break;
        
        default:
            break;
    }

    cout << state;
}

VEHICLE_SIZE ParkingSpot::getSpotType() {
    return vehicleSize;
}
