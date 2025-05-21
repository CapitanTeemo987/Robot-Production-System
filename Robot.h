#ifndef ROBOT_H
#define ROBOT_H
#include <string>

class Robot{

    protected: 
        int battery;
        int id; 
        int operatingHours;
        std::string model; 
        std::string status; 

    
    public: 
        Robot();
        Robot(int, std::string);

        //common methods
        virtual void performTask();
        virtual void getInfo();
        virtual void recharge();

        //getters and setters
        int getBattery();
        int getId();
        int getOperatinHours();
        std::string getModel();
        std::string getStatus();

        void setStatus(std::string);
        void updateBatteryLevel(int);
        void incrementOperatingHours(int);
};

#endif