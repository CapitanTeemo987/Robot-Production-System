#ifndef DOMESTICROBOT_H
#define DOMESTICROBOT_H
#include "Robot.h"


class DomesticRobot : public Robot{
   
    private:
        bool isStuck;

    public:
        DomesticRobot();
        DomesticRobot(int, std::string, bool);

        void setStuckStatus(bool);

        //polymorphism 
        std::string performTask() override;
        std::string getInfo() override;
        std::string recharge() override; 
};

#endif