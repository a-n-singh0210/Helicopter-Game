# Helicopter-Game

A 2D Helicopter Game developed in C++ using the SFML (Simple and Fast Multimedia Library) framework.
This project demonstrates object-oriented programming, real-time graphics rendering, and the effective use of C++ Standard Template Library (STL) containers for game state management.
The game showcases clean architecture, efficient resource handling, and smooth gameplay mechanics — making it a strong example of C++ and SFML integration in a small-scale game project.

✨ Key Features

🎮 Real-time helicopter controls with smooth physics
🧱 Dynamic obstacle generation and collision detection
🪶 Lightweight 2D rendering using SFML
🧩 Modular OOP architecture with reusable components
⚙️ STL-based entity and state management (using vector, queue, map, etc.)
🖥️ Cross-platform and easy to build
🧠 Technical Highlights

Designed and implemented a game loop for consistent frame updates
Utilized SFML’s event system for real-time input handling
Managed textures, sprites, and entities efficiently using RAII principles
Applied C++17 features such as smart pointers and range-based loops
Structured code with a focus on readability, scalability, and maintainability

🧩 Tech Stack

Language: C++17
Framework: SFML (Simple and Fast Multimedia Library)
Libraries: STL (vectors, maps, queues, etc.)
IDE/Compiler: Visual Studio / CLion / g++

🚀 Build Instructions

Install SFML for your platform.
Clone the repository:
git clone https://github.com/<your-username>/helicopter-game.git
cd helicopter-game
Compile the project:
g++ -o helicopter main.cpp -lsfml-graphics -lsfml-window -lsfml-system
Run the executable:
./helicopter

🎯 Gameplay Overview

Control your helicopter to avoid obstacles and survive as long as possible.
Each passing second increases difficulty and score — challenging your reflexes and precision.
Controls:
Space / Up Arrow — Ascend
Release / Down Arrow — Descend
Esc — Exit Game

🧾 Learning Outcomes

This project reinforced my understanding of:
C++ game architecture and rendering pipelines
Event-driven programming
Resource management and memory safety in C++
Practical use of STL containers in game logic
