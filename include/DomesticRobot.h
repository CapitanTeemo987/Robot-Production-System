#ifndef DOMESTICROBOT_H
#define DOMESTICROBOT_H
#include "Robot.cpp"


class DomesticRobot : public Robot{
   
    private:
        bool isStuck;

    public:
        DomesticRobot();
        DomesticRobot(int, std::string, bool);

        void setStuckStatus(bool);

        //polymorphism 
        void performTask() override;
        void getInfo() override;
        void recharge() override; 
};

#endif