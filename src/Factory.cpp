#include "Factory.h"

Factory::Factory(){
    nextId = 0;
    totalProduced = 0; 
}

Robot* Factory::createDomesticRobot(std::string model, bool isStuck = false){
    Robot* robot = new DomesticRobot(nextId++, model, isStuck);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}

Robot* Factory::createIndustrialRobot(std::string model, float precision = 100.0){
    Robot* robot = new IndustrialRobot(nextId++, model, precision);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}

Robot* Factory::createMilitarRobot(std::string model, std::string weapon = "Rifle", std::string caliber = ".223 Remington"){
    Robot* robot = new MilitarRobot(nextId++, model, weapon, caliber);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}    

void Factory::addRobot(Robot* robot){
    robots.push_back(robot);
}

void Factory::removeRobot(int id){
    for(int i = 0; i < robots.size(); i++){
        if(robots[i]->getId() == id){
            delete robots[i];
            robots.erase(robots.begin() + i);
        }
    }
}

void Factory::showAllRobots(){
    for(Robot* robot : robots){
        robot->getInfo();
    }
}


