#include "Robot.h"
#include <sstream>


Robot::Robot(){
    battery = 100; 
    id = 0; 
    operatingHours = 0; 
    model = "Robot";
    status = "";
}

Robot::Robot(int id, std::string model){
    this->id = id;
    this->model = model; 
    this->battery = 100;      
    this->operatingHours = 0; 
    this->status = "";  
}

std::string Robot::performTask(){
    std::stringstream ss;
    if(battery < 15){
        ss << "Low battery";
    }
    else{
        ss << "Waiting";
        battery -= 10;
        operatingHours += 1;
    }
    return ss.str();
}

std::string Robot::getInfo(){
    std::stringstream ss;
    ss << "\nRobot's id: " << id << ", model: " << model;
    ss << "\ncurrent battery: " << battery << "%, " << "operating hours: " << operatingHours << ", status: " << status;
    return ss.str();
}

std::string Robot::recharge(){
    std::stringstream ss;
    status = "Charging";
    ss << "Robot " << id << " is charging...\n";

    battery = 100; 

    ss <<"Robot " << id << "is fully charged";
    return ss.str();
}

int Robot::getBattery(){
    return battery;
}

int Robot::getId(){
    return id;
}

int Robot::getOperatingHours(){
    return operatingHours;
}

std::string Robot::getModel(){
    return model;
}

std::string Robot::getStatus(){
    return status;
}

void Robot::setStatus(std::string status){
     this->status = status;
}

void Robot::updateBatteryLevel(int battery){
    this->battery = battery;
}

void Robot::incrementOperatingHours(int operatingHours){
    this->operatingHours = operatingHours;
}