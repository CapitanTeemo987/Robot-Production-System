#ifndef MILITARROBOT_H
#define MILITARROBOT_H
#include "Robot.cpp"


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

        void recharge();

        //polymorphism 
        void performTask() override;
        void getInfo() override;
        void recharge() override; 
};

#endif