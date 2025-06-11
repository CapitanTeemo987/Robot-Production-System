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

std::string MilitarRobot::getWeapon() const{
    return weapon;
}

std::string MilitarRobot::getCaliber() const{
    return caliber;
}

int MilitarRobot::getAmmo() const{
    return ammo;
}

void MilitarRobot::setAmmo(int ammo){
    this->ammo = ammo; 
}

void MilitarRobot::rechargeAmmo(){
    ammo = 100;
}

bool MilitarRobot::needsAmmoRecharge() const{
    return ammo < minAmmo;
}


std::string MilitarRobot::getInfo() const{
    std::stringstream ss;
    ss << Robot::getInfo(); 
    ss << "\nWeapon: " << weapon;
    ss << "\nCaliber: " << caliber;
    ss << "\nTotal ammo: " << ammo;
    return ss.str();
}

std::string MilitarRobot::performTask(){
    std::stringstream ss;
    if (needsAmmoRecharge()) {
        ss << "Robot " << id << " cannot perform military tasks, insufficient ammunition (" 
           << ammo << "/" << maxAmmo << ")\n";
        ss << "Please call rechargeAmmo() method to reload ammunition\n";
    } else if (battery < 15) {
        ss << "Low battery, cannot perform military task\n";
    } else {
        ss << "Ready for military service, " << weapon << " loaded with " 
           << ammo << " bullets\n";
        battery -= 10;
        operatingHours += 1;
        ammo -= 5; 
        status = "On duty";
    }
    
    return ss.str();
}

std::string MilitarRobot::recharge(){
    std::stringstream ss;
    ss << Robot::recharge();
    return ss.str();
}
