#include "Robot.h"
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
}

void Robot::performTask(){
    if(battery < 15){
        std::cout << "Low battery";
    }
    else{
        std::cout << "Waiting";
        battery -= 10;
        operatingHours += 1;
    }
}

void Robot::getInfo(){
    std::cout << "Robot's id: " << id << ", model: " << model << std::endl;
    std::cout << "current battery: " << battery << "%, " << "operating hours: " << operatingHours << ", status: " << status << std::endl;
}

void Robot::recharge(){
    status = "Charging";
    std::cout << "Robot " << id << " is charging...\n";

    battery = 100; 

    std::cout <<"Robot " << id << "is fully charged";
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