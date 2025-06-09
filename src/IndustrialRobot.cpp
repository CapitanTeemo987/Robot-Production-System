#include "IndustrialRobot.h"
#include <sstream>

IndustrialRobot::IndustrialRobot(){
    precision = 100; 
}

IndustrialRobot::IndustrialRobot(int id, std::string model, float precision) : Robot(id, model){
    this->precision = precision;
}

float IndustrialRobot::getPrecision() const {
    return precision;
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

bool IndustrialRobot::needsCalibration() const{
    return precision < minPrecicion;
}

std::string IndustrialRobot::getInfo() const{
    std::stringstream ss;
    ss << Robot::getInfo();
    ss << "\nPercentage of precision: " << precision;
    return ss.str();
}

std::string IndustrialRobot::performTask(){
    std::stringstream ss;
    if (needsCalibration()) {
        ss << "Robot " << id << " cannot work, precision too low (" << precision << "%)\n";
        ss << "Minimum required precision: " << minPrecicion << "%\n";
        ss << "Please call calibrate() method to restore precision\n";
    } else if (battery < 15) {
        ss << "Low battery, cannot perform industrial task\n";
    } else {
        ss << "Working on industrial task...\n";
        battery -= 10;
        operatingHours += 1;
        status = "Working";
        
        if (precision > minPrecicion) {
            precision -= 0.5; // Precision degrades slightly with use
        }
    }
    
    return ss.str();
}

std::string IndustrialRobot::recharge(){
    std::stringstream ss;
    ss << Robot::recharge();
    return ss.str();
}
