#include <iostream>
#include <string>

#include "Vehicle.h"

Vehicle::Vehicle() {
    isParked = false;
    floorNum = -1;
    rowNum = -1;
    startPos = -1;
    endPos = -1;
}

std::map<VEHICLE_SIZE, int> Vehicle::getSpotsNeeded() {
    return spotsNeeded;
}

void Vehicle::parkVehicle(int floor, int row, int start, int end) {
    isParked = true;
    floorNum = floor;
    rowNum = row;
    startPos = start;
    endPos = end;
}

void Vehicle::removeVehicle() {
    isParked = false;
    floorNum = -1;
    rowNum = -1;
    startPos = -1;
    endPos = -1;
}

void Vehicle::printParkingInfo() {
    if (isParked) {
        std::cout << "Parking at floor: " << floorNum
             << " row: " << rowNum
             << " from: " << startPos << " to: " << endPos << endl;
    } else {
        std::cout << "Cannot find available spot." << endl;
    }
}
