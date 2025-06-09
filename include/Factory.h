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
        Robot* createDomesticRobot(std::string , bool);
        Robot* createIndustrialRobot(std::string , float);
        Robot* createMilitarRobot(std::string , std::string, std::string); 

        //Method overloading
        Robot* createRobot(std::string , std::string , bool); //this creates a domestic robot
        Robot* createRobot(std::string , std::string , float); //this creates an industrial robot
        Robot* createRobot(std::string , std::string , std::string, std::string); //this creates a militar robot
        Robot* createRobot(std::string , std::string ); //creates the robot with the default values

        void addRobot(Robot*);
        void removeRobot(int);
        Robot* findRobotById(int);

        std::string showAllRobots();
        std::string showRobotsByType();

        int getTotalRobots();
        int getTotalProduced();
        std::vector<Robot*> getRobots();

};

#endif