#include "Factory.h"
#include <sstream>
#include <algorithm>

Factory::Factory(){
    nextId = 0;
    totalProduced = 0; 
}

Robot* Factory::createDomesticRobot(std::string model, bool isStuck){
    Robot* robot = new DomesticRobot(nextId++, model, isStuck);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}

Robot* Factory::createIndustrialRobot(std::string model, float precision){
    Robot* robot = new IndustrialRobot(nextId++, model, precision);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}

Robot* Factory::createMilitarRobot(std::string model, std::string weapon, std::string caliber){
    Robot* robot = new MilitarRobot(nextId++, model, weapon, caliber);
    robots.push_back(robot);
    totalProduced++;
    return robot;
}    

//Domestic robot
Robot* Factory::createRobot(std::string type, std::string model, bool isStuck){
    Robot* robot = nullptr;
    std::transform(type.begin(), type.end(), type.begin(), ::tolower); //This is to convert the type to lowercase
    
    if(type == "domestic"){
        robot = new DomesticRobot(nextId++, model, isStuck);
        robots.push_back(robot);
        totalProduced++;
    }
    return robot;
}

//Industrial robot
Robot* Factory::createRobot(std::string type, std::string model, float presicion){
    Robot* robot = nullptr;
    std::transform(type.begin(), type.end(), type.begin(), ::tolower); //This is to convert the type to lowercase

    if(type == "industrial"){
        robot = new IndustrialRobot(nextId++, model, presicion);
        robots.push_back(robot);
        totalProduced++;
    }
    return robot;
}

//Militar robot
Robot* Factory::createRobot(std::string type, std::string model, std::string weapon, std::string caliber){
    Robot* robot = nullptr;
    std::transform(type.begin(), type.end(), type.begin(), ::tolower); 

    if(type == "militar"){
        robot = new MilitarRobot(nextId++, model, weapon, caliber);
        robots.push_back(robot);
        totalProduced++;
    }
    return robot;
}

Robot* Factory::createRobot(std::string type, std::string model){
    Robot* robot = nullptr;
    std::transform(type.begin(), type.end(), type.begin(), ::tolower); 

    if(type == "domestic"){
        robot = createRobot(type, model, false); 
    }
    else if(type == "industrial"){
        robot = createRobot(type, model, 100.0f); 
    }
    else if(type == "militar" || type == "military"){
        robot = createRobot(type, model, "Rifle", ".223 Remington"); 
    }
    
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

Robot* Factory::findRobotById(int id){
    for(Robot* robot : robots){
        if(robot->getId() == id){
            return robot;
        }
    }
    return nullptr;
}

std::string Factory::showAllRobots(){
    std::stringstream ss;
    if (robots.empty()) {
        ss << "No robots in factory.\n";
        return ss.str();
    }
    for(Robot* robot : robots){
        ss << robot->getInfo();
    }
    return ss.str();
}

std::string Factory::showRobotsByType(){
    std::stringstream ss;
    int domesticCount = 0;
    ss << "\nDomestic Robots\n";
    for(Robot* robot : robots){
        DomesticRobot* domesticPtr = dynamic_cast<DomesticRobot*>(robot);
        if(domesticPtr != nullptr){
            ss << robot->getInfo();
            domesticCount++;
        } 
    }

    int industrialCount = 0;
    ss << "\n\nIndustrial Robots\n";
    for(Robot* robot : robots){
        IndustrialRobot* industrialPtr = dynamic_cast<IndustrialRobot*>(robot);
        if(industrialPtr != nullptr){
            ss << robot->getInfo();
            industrialCount++;
        }
    }

    int militarCount = 0;
    ss << "\n\nMilitary Robots\n";
    for(Robot* robot : robots){
        MilitarRobot* militarPtr = dynamic_cast<MilitarRobot*>(robot);
        if(militarPtr != nullptr){
            ss << robot->getInfo();
            militarCount++;
        }
    }
    return ss.str();
}

int Factory::getTotalRobots(){
    return robots.size();
}

int Factory::getTotalProduced(){
    return totalProduced;
}

std::vector<Robot*> Factory::getRobots(){
    return robots; //This is useful when printing the robots out in the main
}

