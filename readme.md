# Natural Selection Simulator

## Overview

This project is a Natural Selection Simulator where organisms are represented by blue circles and food by green circles. The simulation offers several features, such as enabling or disabling the vision radius of these blue organisms, and the ability to speed up or slow down the simulation.

## Features

- **Vision Radius:** You can toggle the visibility of the vision radius for the blue organisms.
- **Speed Control:** The simulation speed can be increased or decreased according to your preference.

## Simulation Rules

1. **Food Consumption:**
    - Each blue organism (representing an entity) seeks out green circles (food).
    - An organism must find and consume food to maintain its energy levels.

2. **Energy Management:**
    - If an organism eats one food item but fails to find another before its energy depletes, it will return to the base without the ability to reproduce.
    - If an organism eats two or more food items, it will reproduce.

3. **Reproduction and Mutation:**
    - When an organism consumes at least two food items, it will reproduce through self-replication.
    - The offspring have the potential for mutations in the following traits:
        - **Speed:** How fast the organism can move.
        - **Vision Range:** How far the organism can see.
        - **Size:** The physical size of the organism
- Organisms lose energy according to the formula:





## How to Use

1. **Starting the Simulation:**
    - Initiate the simulation to observe the blue organisms move towards green food items.

2. **Toggling Vision Radius:**
    - Enable or disable the vision radius to see how organisms perceive their environment.

3. **Adjusting Speed:**
    - Use the controls to speed up or slow down the simulation to better understand the behavior and interactions of the organisms.

## Development

- The simulation is built using the **raylib** library in **C++**.
- Future updates will include data visualization tools and a comprehensive menu system.

## Conclusion

This simulator provides a dynamic and interactive way to study the principles of natural selection, showcasing how organisms adapt, survive, and evolve based on their interactions with the environment and their traits. Enjoy exploring the intricate dance of survival and reproduction in this simplified model of natural selection!
