#include "MilitarRobot.h"
#include <sstream>

MilitarRobot::MilitarRobot() : Robot(){
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

void MilitarRobot::rechargeAmmo(){
    ammo = 100;
}

std::string MilitarRobot::getInfo(){
    std::stringstream ss;
    ss << Robot::getInfo();
    ss << "Total ammo: " << ammo;
    return ss.str();
}

std::string MilitarRobot::performTask(){
    std::stringstream ss;
    if(ammo < 15){
        ss << "The robot doesn't have enough ammunition, please recharge";
        MilitarRobot::rechargeAmmo();
    }
    else if(battery < 15){
        ss << "Low battery";
    }
    else{
        ss << "Ready for service";
        battery -= 10;
        operatingHours += 1;
    }
    return ss.str();
}

std::string MilitarRobot::recharge(){
    std::stringstream ss;
    ss << Robot::recharge();
    return ss.str();
}
