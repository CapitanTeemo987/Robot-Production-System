#ifndef FACTORY_H
#define FACTORY_H


#include "IndustrialRobot.h"
#include "DomesticRobot.h"
#include "MilitarRobot.h"
#include "Robot.h"
#include <string>
#include <vector>

class Factory{
    private: 
        std::vector<Robot*> robots;
        int nextId;
        int totalProduced;

    public: 
        Factory();
        Robot* createDomesticRobot(std::string model, bool isStuck = false);
        Robot* createIndustrialRobot(std::string model, float precision = 100.0);
        Robot* createMilitarRobot(std::string model, std::string weapon = "Rifle", std::string caliber = ".223 Remington");    

        void addRobot(Robot* robot);
        void removeRobot(int id);
        Robot* findRobotById(int);

        std::string showAllRobots();
        std::string showRobotsByType();

        int getTotalRobots();
        int getTotalProduced();
        std::vector<Robot*> getRobots();

};

#endif