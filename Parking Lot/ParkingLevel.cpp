#include "ParkingLevel.h"

#include <iostream>
#include <string>

ParkingLevel::ParkingLevel(unsigned int floor, unsigned int rows, unsigned int row_size) {
    floorNum = floor;
    rowNum = rows;
    rowNumSize = row_size;
}

unsigned ParkingLevel::getRows() {
    return this->rowNum;
}

unsigned ParkingLevel::getRowSize() {
    return this->rowNumSize;
}

void ParkingLevel::setSpot(unsigned int large, unsigned int compact, unsigned int small) {
    for (int i=0; i < rowNum; i++) {
        std::vector<ParkingSpot> currentRow;
        int pos = 0;

        for (int j=0; j < small; j++) {
            ParkingSpot newSpot(floorNum, i, pos++, SMALL);
            currentRow.push_back(newSpot);
        }

        for (int j=0; j < compact; j++) {
            ParkingSpot newSpot(floorNum, i, pos++, COMPACT);
            currentRow.push_back(newSpot);
        }

        for (int j=0; j < large; j++) {
            ParkingSpot newSpot(floorNum, i, pos++, LARGE);
            currentRow.push_back(newSpot);
        }

        spots.push_back(currentRow);
    }
}

bool ParkingLevel::parkVehicle(Vehicle *vehicle, int row, int start, int end) {
    std::map<VEHICLE_SIZE, int> spotsNeeded = vehicle->getSpotsNeeded();

    for (int i=0; i < rowNum; i++) {
        int count = 0;
        int startPos = -1;

        std::vector<ParkingSpot> currentRow = spots[i];

        for (int j=0; j < currentRow.size(); j++) {
            if (currentRow[j].isAvailable()) {
                VEHICLE_SIZE spotType = currentRow[j].getSpotType();

                if (spotsNeeded[spotType] > 0) {
                    if (count == 0) {
                        start = j;
                    }
                    count++;

                    if (count == spotsNeeded[spotType]) {
                        row = i;
                        startPos = start;
                        end = j;

                        changeSpotState(false, row, startPos, end);
                        return true;
                    }
                } else {
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
    }

    row = -1;
    start = -1;
    end = -1;
    return false;
}

void ParkingLevel::changeSpotState(bool availability, int row, int start, int end) {
    for (int i=start; i <= end; i++) {
        spots[row][i].setAvailability(availability);
    }
}

void ParkingLevel::printLevelInfo() {
    std::cout << "Level " << floorNum << ": " << std::endl;

    for (int i=0; i < spots.size(); i++) {
        std::vector<ParkingSpot> currentRow = spots[i];

        for (int j=0; j < currentRow.size(); j++) {
            currentRow[j].printSpotInfo();
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}
