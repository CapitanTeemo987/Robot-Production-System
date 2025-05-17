# Robot Production System

In an increasingly automated world, intelligent production systems have become a key component of modern industry. Today's factories not only produce goods, but also advanced technology such as robots that perform a wide variety of roles in society, from helping with household tasks to participating in industrial processes and even security operations.

This project simulates a virtual robot factory, where different types of robots are produced with specific functionalities. The simulation focuses on how a factory can create, organize, and control multiple robot types with different capabilities.

I think this proyect is interesting for this reasons:

- It applies core object-oriented programming concepts such as inheritance, polymorphism (i know we haven't seen this topic, but it is important), composition, and abstraction.
- It models a realistic and flexible system that can be easily expanded with more robot types or behaviors.
- It offers insight into how an automated production system might be structured.
- It can be related to fields like robotics, artificial intelligence, manufacturing, and industrial software systems.

## Proposed Structure

- `Robot.h` – Base class defining common attributes and behaviors.
- `DomesticRobot.h` – Inherits from `Robot`, includes domestic tasks (cleaning, assistance).
- `IndustrialRobot.h` – Inherits from `Robot`, focuses on production and assembly tasks.
- `MilitarRobot.h` – Inherits from `Robot`, includes security or defense functions.
- `Fabric.h` – Class that manages the production, maintenance, and registration of robots.
- `controller.h` – Oversees the overall operation of the system.
- `main.cpp` – Entry point for running the simulation.

### Manuel Valentino Ortiz Sánchez - A01712296
