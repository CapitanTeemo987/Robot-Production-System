#include "DomesticRobot.h"
#include <sstream>

DomesticRobot::DomesticRobot(){
    bool isStuck = false;
}

DomesticRobot::DomesticRobot(int id, std::string model, bool isStuck) : Robot(id, model){
    this->isStuck = isStuck;
}

bool DomesticRobot::getStuckStatus() const{
    return isStuck;
}


void DomesticRobot::setStuckStatus(bool stuck){
    isStuck = stuck;
}

std::string DomesticRobot::getInfo() const{
    std::stringstream ss;
    ss << Robot::getInfo();
    ss << "\nState of stuck: " << isStuck;
    return ss.str();
}

std::string DomesticRobot::performTask(){
    std::stringstream ss;
    if(isStuck){
        ss << "The robot is stuck, please use unstuck function";
    }
    else if(battery < 15){
        ss << "Low battery";
    }
    else{
        status = "Cleaning";
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

std::string DomesticRobot::unstuck(){
    std::stringstream ss;
    if (isStuck) {
        isStuck = false;
        status = "Ready";
        ss << "Robot " << id << " has been unstuck and is ready to work\n";
    } else {
        ss << "Robot " << id << " is not stuck\n";
    }
    return ss.str();
}