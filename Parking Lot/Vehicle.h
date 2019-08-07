#pragma once

#include <map>

enum VEHICLE_SIZE { SMALL = 1, COMPACT = 2, LARGE = 3 };

class Vehicle {
    protected:
        std::map<VEHICLE_SIZE, int> spotsNeeded;
        int floorNum;
        int rowNum;
        int startPos;
        int endPos;
        bool isParked;
    
    public:
        Vehicle();
        std::map<VEHICLE_SIZE, int> getSpotsNeeded();
        void parkVehicle(int floor, int row, int start, int end);
        void removeVehicle();
        void printParkingInfo();
};
