#include "DomesticRobot.h"
#include <sstream>

DomesticRobot::DomesticRobot(){
    bool isStuck = false;
}

DomesticRobot::DomesticRobot(int id, std::string model, bool isStuck) : Robot(id, model){
    this->isStuck = isStuck;
}

void DomesticRobot::setStuckStatus(bool stuck){
    isStuck = stuck;
}

std::string DomesticRobot::getInfo(){
    std::stringstream ss;
    ss << Robot::getInfo();
    ss << "State of stuck: " << isStuck;
    return ss.str();
}

std::string DomesticRobot::performTask(){
    std::stringstream ss;
    if(isStuck){
        ss << "The robot is stuck";
    }
    else if(battery < 15){
        ss << "Low battery";
    }
    else{
        ss << "Cleaning";
        battery -= 10;
        operatingHours += 1;
    }
    return ss.str();
}

std::string DomesticRobot::recharge(){
    std::stringstream ss;
    ss << Robot::recharge();
    return ss.str();
}
