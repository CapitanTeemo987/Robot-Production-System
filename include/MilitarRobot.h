#ifndef MILITARROBOT_H
#define MILITARROBOT_H
#include "Robot.h"


class MilitarRobot : public Robot{
   
    private:
        std::string weapon;
        std::string caliber;
        int ammo; 

    public:
        MilitarRobot();
        MilitarRobot(int, std::string, std::string, std::string);

        //setter (only ammo, the weapon is with the robot)
        void setAmmo(int);

        void rechargeAmmo();

        //polymorphism 
        std::string performTask() override;
        std::string getInfo() override;
        std::string recharge() override; 
};

#endif