#ifndef DOMESTICROBOT_H
#define DOMESTICROBOT_H
#include "C:\Users\V\Desktop\Progra\Robot\src\Robot.cpp"


class DomesticRobot : public Robot{
   
    private:
        bool isStuck;

    public:
        DomesticRobot();
        DomesticRobot(int, std::string, bool);

        //polymorphism 
        void performTask() override;
        void getInfo() override;
        void recharge() override; 
};

#endif