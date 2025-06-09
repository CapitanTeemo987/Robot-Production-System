#ifndef INDUSTRIALROBOT_H
#define INDUSTRIALROBOT_H
#include "Robot.h"


class IndustrialRobot : public Robot{
   
    private:
        float precision; //This is the % of the presicion
        const float minPrecicion = 95.0;
        const float maxPrecison = 100.0;

    public:
        IndustrialRobot();
        IndustrialRobot(int, std::string, float);

        float getPrecision() const;
        void setPrecision(float);

        std::string calibrate();
        bool needsCalibration() const;

        //polymorphism 
        std::string performTask() override;
        std::string getInfo() const override;
        std::string recharge() override; 
};

#endif