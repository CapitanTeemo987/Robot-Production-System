#ifndef INDUSTRIALROBOT_H
#define INDUSTRIALROBOT_H
#include "Robot.h"


class IndustrialRobot : public Robot{
   
    private:
        float precision; //This is the % of the presicion

    public:
        IndustrialRobot();
        IndustrialRobot(int, std::string, float);

        void setPrecision(float);
        std::string calibrate();

        //polymorphism 
        std::string performTask() override;
        std::string getInfo() override;
        std::string recharge() override; 
};

#endif