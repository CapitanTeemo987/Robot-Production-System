#include "C:\Users\V\Desktop\Progra\Robot\include\DomesticRobot.h"

DomesticRobot::DomesticRobot(){
    bool isStuck = false;
}

DomesticRobot::DomesticRobot(int id, std::string model, bool isStuck) : Robot(id, model){
    this->isStuck = false;
}

void DomesticRobot::getInfo(){
    Robot::getInfo();
    std::cout << "State of stuck: " << isStuck;
}

void DomesticRobot::performTask(){
    if(!isStuck){
        std::cout << "The robot is stuck";
    }
    else if(battery < 15){
        std::cout << "Low battery";
    }
    else{
        std::cout << "Cleaning";
        battery -= 10;
        operatingHours += 1;
    }
}

void DomesticRobot::recharge(){
    Robot::recharge();
}
