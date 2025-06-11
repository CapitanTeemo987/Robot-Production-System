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
        virtual std::string performTask() = 0; //This helps to make the class abstract
        virtual std::string getInfo() const;
        virtual std::string recharge();

        //getters and setters
        int getBattery() const;
        int getId() const;
        int getOperatingHours() const;
        std::string getModel() const;
        std::string getStatus() const;

        //operator overload 
        //i use references in ostream to work with the original
        friend std::ostream& operator<<(std::ostream& os, const Robot& robot);

        void setStatus(std::string);
        void updateBatteryLevel(int);
        void incrementOperatingHours(int);
};

#endif