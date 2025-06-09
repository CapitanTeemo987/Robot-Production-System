#include "Robot.h"
#include <sstream>
#include <iostream>

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


std::string Robot::getInfo() const{
    std::stringstream ss;
    ss << "\nRobot's id: " << id << "\nModel: " << model << "\nCurrent battery: " << battery << "% " << "\nOperating hours: " << operatingHours << "\nStatus: " << status;
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

int Robot::getBattery() const{
    return battery;
}

int Robot::getId() const{
    return id;
}

int Robot::getOperatingHours() const{
    return operatingHours;
}

std::string Robot::getModel() const{
    return model;
}

std::string Robot::getStatus() const{
    return status;
}

std::ostream& operator<<(std::ostream& os, const Robot& robot){
    os << robot.getInfo();
    return os;
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

