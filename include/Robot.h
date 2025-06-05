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
        virtual std::string performTask();
        virtual std::string getInfo();
        virtual std::string recharge();

        //getters and setters
        int getBattery();
        int getId();
        int getOperatingHours();
        std::string getModel();
        std::string getStatus();

        void setStatus(std::string);
        void updateBatteryLevel(int);
        void incrementOperatingHours(int);
};

#endif