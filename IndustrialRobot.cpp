#include "IndustrialRobot.h"

IndustrialRobot::IndustrialRobot(){
    precision = 100; 
}

IndustrialRobot::IndustrialRobot(int id, std::string model, float precision) : Robot(id, model){
    this->precision = precision;
}

void IndustrialRobot::setPrecision(float precision){
    this->precision = precision;
}

void IndustrialRobot::calibrate(){
    std::cout << "Calibrating..." << std::endl;
    precision = 100;
}

void IndustrialRobot::getInfo(){
    Robot::getInfo();
    std::cout << "Percentage of precision: " << precision;
}

void IndustrialRobot::performTask(){
    if(precision < 95){
        std::cout << "The robot can't work, please calibrate the robot";
        IndustrialRobot::calibrate();
    }
    else if(battery < 15){
        std::cout << "Low battery";
    }
    else{
        std::cout << "Working";
        battery -= 10;
        operatingHours += 1;
    }
}

void IndustrialRobot::recharge(){
    Robot::recharge();
}
