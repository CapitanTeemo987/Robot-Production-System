#include "MilitarRobot.h"

MilitarRobot::MilitarRobot(){
    weapon = "Rifle";
    caliber = ".223 Remington";
    ammo = 100; 
}

MilitarRobot::MilitarRobot(int id, std::string model, std::string weapon, std::string caliber) : Robot(id, model){
    this->weapon = weapon;
    this->caliber = caliber;
    ammo = 100;
}

void MilitarRobot::setAmmo(int ammo){
    this->ammo = ammo; 
}

void MilitarRobot::recharge(){
    ammo = 100;
}

void MilitarRobot::getInfo(){
    Robot::getInfo();
    std::cout << "Total ammo: " << ammo;
}

void MilitarRobot::performTask(){
    if(ammo < 15){
        std::cout << "The robot doesn't have enough ammunition, please recharge";
        MilitarRobot::recharge();
    }
    else if(battery < 15){
        std::cout << "Low battery";
    }
    else{
        std::cout << "Ready for service";
        battery -= 10;
        operatingHours += 1;
    }
}

void MilitarRobot::recharge(){
    Robot::recharge();
}
