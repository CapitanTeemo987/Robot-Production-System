#ifndef DOMESTICROBOT_H
#define DOMESTICROBOT_H
#include "Robot.h"


class DomesticRobot : public Robot{
   
    private:
        bool isStuck;

    public:
        DomesticRobot();
        DomesticRobot(int, std::string, bool);

        bool getStuckStatus() const;
        void setStuckStatus(bool);

        std::string performTask() override;
        std::string getInfo() const override;
        std::string recharge() override; 

        std::string unstuck();
};

#endif