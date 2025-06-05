#include "IndustrialRobot.h"
#include <sstream>

IndustrialRobot::IndustrialRobot(){
    precision = 100; 
}

IndustrialRobot::IndustrialRobot(int id, std::string model, float precision) : Robot(id, model){
    this->precision = precision;
}

void IndustrialRobot::setPrecision(float precision){
    this->precision = precision;
}

std::string IndustrialRobot::calibrate(){
    std::stringstream ss;
    ss << "Calibrating...\n";
    precision = 100;
    return ss.str();
}

std::string IndustrialRobot::getInfo(){
    std::stringstream ss;
    ss << Robot::getInfo();
    ss << "Percentage of precision: " << precision;
    return ss.str();
}

std::string IndustrialRobot::performTask(){
    std::stringstream ss;
    if(precision < 95){
        ss << "The robot can't work, please calibrate the robot";
        ss << IndustrialRobot::calibrate();
    }
    else if(battery < 15){
        ss << "Low battery";
    }
    else{
        ss << "Working";
        battery -= 10;
        operatingHours += 1;
    }
    return ss.str();
}

std::string IndustrialRobot::recharge(){
    std::stringstream ss;
    ss << Robot::recharge();
    return ss.str();
}
