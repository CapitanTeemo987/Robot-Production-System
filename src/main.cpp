#include "Robot.h"
#include "DomesticRobot.h"
#include "MilitarRobot.h"
#include "IndustrialRobot.h"
#include "Factory.h"
#include <iostream>

void Menu();

int main() {
    int opcion; 
    Factory factory;

    while(true){
        std::cout << "\nWelcome to your robot's factory \n";
        Menu();
        std::cout << "\nSelect an option:\n";
        std::cin >> opcion;

        if(opcion == 0){
            std::cout << "Goodbye! Thanks for using Robot Factory.\n";
            break;
        }

        switch(opcion){
            case 1: {
                std::string type, model;
                std::cout << "\nEnter robot type: ";
                std::cin >> type;
                std::cout << "\nEnter robot model: ";
                std::cin >> model;

                Robot* robot = factory.createRobot(type, model);
                if(robot != nullptr){
                    std::cout << "Robot created succesfully";
                    std::cout << *robot;
                }else {
                    std::cout << "Invalid robot type. Please use: domestic, industrial, or militar\n";
                }
                break;
            }
            case 2: {
                std::string model;
                bool stuckOption;
                std::cout << "\nEnter domestic robot model: ";
                std::cin >> model;
                std::cout << "Is the robot stuck? (1 = Yes, 0 = No): ";
                std::cin >> stuckOption;

                Robot* robot = factory.createRobot("domestic", model, stuckOption);
                if(robot != nullptr) {
                    std::cout << "\nDomestic Robot created successfully";
                    std::cout << *robot << "\n";
                } else {
                    std::cout << "Error creating domestic robot.\n";
                }
                break;
            }
            case 3: {
                std::string model;
                float precision; 
                std::cout << "\nEnter industrial robot model: ";
                std::cin >> model;
                std::cout << "Enter precision percentage (0-100): ";
                std::cin >> precision;

                if(precision < 0 || precision > 100) {
                    std::cout << "Invalid precision. Setting to default (100%)\n";
                    precision = 100.0;
                }

                Robot* robot = factory.createIndustrialRobot(model, precision);
                if(robot != nullptr){
                    std::cout << "\nIndustrial Robot created successfully";
                    std::cout << *robot << "\n";
                } else {
                    std::cout << "Error creating industrial robot.\n";
                }
                break;
            }
            case 4: {
                std::string model, weapon, caliber;
                std::cout << "\nEnter military robot model: ";
                std::cin >> model;
                std::cout << "Enter weapon type (default: Rifle): ";
                std::cin >> weapon;
                std::cout << "Enter caliber (default: .223 Remington): ";
                std::getline(std::cin, caliber);
                
                if(weapon.empty()) weapon = "Rifle";
                if(caliber.empty()) caliber = ".223 Remington";

                Robot* robot = factory.createMilitarRobot(model, weapon, caliber);
                if(robot != nullptr){
                    std::cout << "\nMilitary Robot created successfully";
                    std::cout << *robot << "\n";
                } else {
                    std::cout << "Error creating military robot.\n";
                }
                break;
            }
            case 5: {
                std::vector<Robot*> robots = factory.getRobots();
                if(robots.empty()){
                    std::cout << "\nNo robots in factory";
                }else{
                    for(Robot* robot : robots){
                        std::cout << *robot << "\n";
                    }
                }    
                std::cout << "\nTotal robots: " << factory.getTotalRobots();
                std::cout << "\nTotal produced: " << factory.getTotalProduced();
                break;
            }
            case 6: {
                factory.showRobotsByType();
                break;
            }
            case 7: {
                int id; 
                std::cout << "Enter robot Id to search: ";
                std::cin >> id;

                Robot* robot = factory.findRobotById(id);
                if(robot != nullptr){
                    std::cout << "Robot found!\n";
                    std::cout << *robot;
                }else{
                    std::cout << "\nThere are no robot with id: " << id;
                }
                break;
            }
            case 8: {
                int id;
                std::cout << "\nEnter robot Id to perform task: ";
                std::cin >> id;

                Robot* robot = factory.findRobotById(id);
                if(robot != nullptr){
                    robot->performTask();
                    std::cout << *robot; 
                }else{
                    std::cout << "\nThere are no robot with id: " << id;
                }
                break;
            }
            case 9: {
                int id;
                std::cout << "\nEnter robot Id to recharge battery: ";
                std::cin >> id;

                Robot* robot = factory.findRobotById(id);
                if(robot != nullptr){
                    std::cout << "Robot before recharge: " << *robot;
                    robot->recharge();
                    std::cout << "Robot after recharge: " << *robot;
                }else{
                    std::cout << "\nThere are no robot with id: " << id;
                }
                break;
            }
            case 10: {
                int id;
                std::cout << "\nEnter robot Id to sprecial functions: ";
                std::cin >> id;
                Robot* robot = factory.findRobotById(id);

                //Each try to convert a specific type
                DomesticRobot* domesticRobot = dynamic_cast<DomesticRobot*>(robot);
                IndustrialRobot* industrialRobot = dynamic_cast<IndustrialRobot*>(robot);
                MilitarRobot* militarRobot = dynamic_cast<MilitarRobot*>(robot);

                if(robot != nullptr){
                    if(domesticRobot != nullptr){
                        std::cout << "\nDomestic Robot Special Functions\n";
                        std::cout << "1. Check if stuck\n";
                        std::cout << "2. Unstuck robot\n";
                        std::cout << "Choose function: ";
                        int choice;
                        std::cin >> choice;
                        if(choice == 1){
                            std::cout << "Stuck status " << (domesticRobot->getStuckStatus() ? "stuck" : "not stuck");
                        }else if(choice == 2){
                            std::cout << domesticRobot->unstuck();
                        }
                    }
                    else if(industrialRobot != nullptr){
                        std::cout << "\nIndustrial Robot Special Functions\n";
                        std::cout << "1. Check precision\n";
                        std::cout << "2. Calibrate robot\n";
                        std::cout << "3. Check if needs calibration\n";
                        std::cout << "Choose function: ";
                        int choice;
                        std::cin >> choice;

                        if(choice == 1){
                            std::cout << "Current precision: " << industrialRobot->getPrecision();
                        }
                        else if(choice == 2){
                            std::cout << industrialRobot->calibrate() << std::endl;
                        }
                        else if(choice == 3){
                            std::cout << "Needs calibration: " << (industrialRobot->needsCalibration() ? "Yes" : "No") << std::endl;
                        }
                    }
                    else if(militarRobot != nullptr){
                        std::cout << "\nMilitary Robot Special Functions\n";
                        std::cout << "1. Check ammo\n";
                        std::cout << "2. Recharge ammo\n";
                        std::cout << "3. Check weapon info\n";
                        std::cout << "Choose function: ";
                        int choice;
                        std::cin >> choice;

                        if(choice == 1){
                            std::cout << "Current ammo: " << militarRobot->getAmmo() << std::endl;
                        }
                        else if(choice == 2){
                            militarRobot->rechargeAmmo();
                            std::cout << "Ammo recharged successfully!\n";
                        }
                        else if(choice == 3){
                            std::cout << "Weapon: " << militarRobot->getWeapon() << std::endl;
                            std::cout << "Caliber: " << militarRobot->getCaliber() << std::endl;
                        }
                    }
                }else {
                    std::cout << "Robot with ID " << id << " not found.\n";
                }
                break;
            }
            case 11: {
                int id;
                std::cout << "\nEnter robot Id to remove: ";
                std::cin >> id;

                Robot* robot = factory.findRobotById(id);
                if(robot != nullptr){
                    std::cout << "Removing robot: " << *robot << std::endl;
                    factory.removeRobot(id);
                }else{
                    std::cout << "Robot with ID " << id << " not found.\n";
                }
                break;
            }
            case 12: {
                std::cout << "\nCreating Example Robots\n";
                
                Robot* domestic1 = factory.createDomesticRobot("Roomba-X1", false);
                Robot* domestic2 = factory.createDomesticRobot("CleanBot-Pro", true);
                Robot* industrial1 = factory.createIndustrialRobot("ManufacBot-2000", 98.5);
                Robot* industrial2 = factory.createIndustrialRobot("PrecisionBot-Ultra", 87.2);
                Robot* militar1 = factory.createMilitarRobot("Guardian-Alpha", "Assault Rifle", ".308 Winchester");
                Robot* militar2 = factory.createMilitarRobot("Defender-Beta", "Sniper Rifle", ".50 BMG");
                
                std::cout << *domestic1 << "\n";
                std::cout << *domestic2 << "\n";
                std::cout << *industrial1 << "\n";
                std::cout << *industrial2 << "\n";
                std::cout << *militar1 << "\n";
                std::cout << *militar2 << "\n";
                break;
            }
        }
    }
    return 0;
}

void Menu(){
    std::cout << "1.  Create robot (with default values)\n";
    std::cout << "2.  Create domestic robot\n";
    std::cout << "3.  Create industrial robot\n";
    std::cout << "4.  Create military robot\n";
    std::cout << "5.  Show all robots\n";
    std::cout << "6.  Show robots by type\n";
    std::cout << "7.  Find robot by ID\n";
    std::cout << "8.  Make robot perform task\n";
    std::cout << "9.  Recharge robot battery\n";
    std::cout << "10. Special robot functions\n";
    std::cout << "11. Remove robot\n";
    std::cout << "12. Create example robots\n";
    std::cout << "0.  Exit\n";
    std::cout << "----------------------------------------\n";
}