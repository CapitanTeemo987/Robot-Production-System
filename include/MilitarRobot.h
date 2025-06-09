#ifndef MILITARROBOT_H
#define MILITARROBOT_H
#include "Robot.h"


class MilitarRobot : public Robot{
   
    private:
        std::string weapon;
        std::string caliber;
        int ammo; 
        int maxAmmo = 100;
        int minAmmo = 15;

    public:
        MilitarRobot();
        MilitarRobot(int, std::string, std::string, std::string);

        std::string getWeapon() const;
        std::string getCaliber() const;
        int getAmmo() const;

        //setter (only ammo, the weapon is with the robot)
        void setAmmo(int);

        void rechargeAmmo();
        bool needsAmmoRecharge() const;


        //polymorphism 
        std::string performTask() override;
        std::string getInfo() const override;
        std::string recharge() override; 
};

#endif