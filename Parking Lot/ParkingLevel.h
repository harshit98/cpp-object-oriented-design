#pragma once

#include <vector>
#include "ParkingSpot.h"

class ParkingLevel {
    private:
        unsigned int rowNum;
        unsigned int rowNumSize;
        unsigned int floorNum;
        std::vector<std::vector<ParkingSpot>> spots;
    
    public:
        ParkingLevel(unsigned int floor, unsigned int row, unsigned int rowSize);
        unsigned getRows();
        unsigned getRowSize();
        void setSpot(unsigned int large, unsigned int compact, unsigned int small);
        bool parkVehicle(Vehicle *vehicle, int row, int start, int end);
        void changeSpotState(bool availability, int row, int start, int end);
        void printLevelInfo();
};
