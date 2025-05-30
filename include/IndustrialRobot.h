#ifndef INDUSTRIALROBOT_H
#define INDUSTRIALROBOT_H
#include "Robot.cpp"


class IndustrialRobot : public Robot{
   
    private:
        float precision; //This is the % of the presicion

    public:
        IndustrialRobot();
        IndustrialRobot(int, std::string, float);

        void setPrecision(float);
        void calibrate();

        //polymorphism 
        void performTask() override;
        void getInfo() override;
        void recharge() override; 
};

#endif