# Robot Production System

In an increasingly automated world, intelligent production systems have become a key component of modern industry. Today's factories not only produce goods, but also advanced technology such as robots that perform a wide variety of roles in society, from helping with household tasks to participating in industrial processes and even security operations.

This project simulates a virtual robot factory, where different types of robots are produced with specific functionalities. The simulation focuses on how a factory can create, organize, and control multiple robot types with different capabilities.

I think this proyect is interesting for this reasons:

- It applies core object-oriented programming concepts such as inheritance, polymorphism (i know we haven't seen this topic, but it is important), composition, and abstraction.
- It models a realistic and flexible system that can be easily expanded with more robot types or behaviors.
- It offers insight into how an automated production system might be structured.
- It can be related to fields like robotics, artificial intelligence, manufacturing, and industrial software systems.

## Class Structure

`Robot `(Abstract Class)
Purpose: Serves as the foundation for all robot types in the system, defining common attributes and behaviors that every robot must have.
Attributes:

- battery: Current battery level (0-100%)
- id: Unique identifier for each robot
- operatingHours: Total hours the robot has been active
- model: String representing the robot model
- status: Current operational status

Key Methods:

- performTask(): Pure virtual method that must be implemented by each robot type
- getInfo(): Virtual method that returns robot information
- recharge(): Virtual method for battery charging functionality
- All the getters and setters for attributes

`DomesticRobot` 
Purpose: Represents household robots designed for cleaning and domestic assistance tasks.
Key Attributes:

- isStuck: Boolean indicating if the robot is physically stuck and cannot move

Specialized Methods:

- performTask(): Implements cleaning functionality with battery and stuck state validation
- unstuck(): Allows the robot to recover from stuck situations
- getStuckStatus()/setStuckStatus(): Manages the stuck state

`IndustrialRobot` 
Purpose: Designed for manufacturing and production environments where precision is critical.
Key Attributes:

- precision: Current precision percentage 
- minPrecision: Minimum required precision threshold (95%)
- maxPrecision: Maximum achievable precision (100%)

Specialized Methods:

- performTask(): Executes industrial tasks while monitoring precision levels
- calibrate(): Restores precision to maximum level
- needsCalibration(): Checks if precision has fallen below minimum threshold

`MilitarRobot`
Purpose: Specialized for security and defense operations with weapon system management.
Key Attributes:

- weapon: Type of weapon .
- caliber: Ammunition caliber 
- ammo: Current ammunition 
- maxAmmo: Maximum ammunition capacity (100)
- minAmmo: Minimum ammunition limit (15)

Specialized Methods:

- performTask(): Executes military operations while consuming ammunition
- rechargeAmmo(): Restores ammunition to maximum capacity
- needsAmmoRecharge(): Checks if ammunition is below minimum limit

`Factory` 
Purpose: Implements the Factory design pattern to centralize robot creation, management, and organization.
Key Attributes:

- robots: Vector storing pointers to all created robots
- nextId: Auto-incrementing ID generator for new robots
- totalProduced: Counter tracking total robots ever created

Creation Methods:

Multiple overloaded createRobot() methods accepting different parameter combinations, 
specific creation methods for each robot type, 
default parameter handling for simplified robot creation.

Management Methods:

- addRobot()/removeRobot(): Manual robot collection management
- findRobotById(): Identification by unique id
- showAllRobots()/showRobotsByType(): Display and organization utilities
- getTotalRobots()/getTotalProduced(): Statistical information

### The system demonstrates several important object-oriented principles:

- Inheritance: All robot types inherit common functionality from the Robot base class
- Polymorphism: The same interface (performTask()) behaves differently for each robot type
- Abstraction: The Robot class defines what all robots should do without specifying how
- Encapsulation: Each class manages its own internal state and provides controlled access
- Factory Pattern: Centralized object creation with multiple creation strategies

### UML
![UML](https://github.com/user-attachments/assets/5bc4ce4f-5218-46f6-b609-c4f5ec83b158)
