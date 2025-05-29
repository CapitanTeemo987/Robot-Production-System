#ifndef FACTORY_H
#define FACTORY_H


#include "IndustrialRobot.h"
#include "DomesticRobot.h"
#include "MilitarRobot.h"
#include "Robot.h"
#include <vector>

class Factory{
    private: 
        std::vector<Robot*> robots;
        int nextId;
        int totalProduced;

};

#endif