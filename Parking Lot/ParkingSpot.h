#pragma once

#include "Vehicle.h"

class ParkingSpot {
    private:
        unsigned int floorNum;
        unsigned int rowNum;
        unsigned int posNum;
        VEHICLE_SIZE vehicleSize;
        bool isParkingAvailable;
    
    public:
        ParkingSpot(unsigned int floor, unsigned int row, unsigned int pos, VEHICLE_SIZE size);
        bool isAvailable();
        void setAvailability(bool a);
        void printSpotInfo();
        VEHICLE_SIZE getSpotType();
};
