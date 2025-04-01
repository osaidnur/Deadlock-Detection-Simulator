# Deadlock Detection Simulator

A C++ program that simulates the **deadlock detection algorithm** in operating systems. It mimics how a system can check for circular wait conditions among processes and detect if a deadlock has occurred.

## 📚 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Files Included](#-files-included)
- [How to Run](#-how-to-run)
- [Example Use](#-example-use)
- [Author](#-author)

## 📘 Overview

This project implements a deadlock detection system using C++. It models resources and processes using matrices and vectors, and follows the algorithm used to determine whether any set of processes is in a deadlock state based on current allocations and requests.

## ✨ Features

- Input current allocation and request matrices
- Input available resources
- Deadlock detection based on system state
- Clear reporting of safe or unsafe state
- Identifies processes involved in a deadlock, if any

## 📁 Files Included

- `Task3_OsaidNur_1210733.cpp` – Source code implementing the simulator
- `ENCS3390_project3.pdf` – Project documentation and requirements

## 🔨 How to Run

1. Ensure you have a C++ compiler (e.g., g++) installed.
2. Compile the source file:
   ```bash
   g++ Task3_OsaidNur_1210733.cpp -o deadlock_sim
   ```
3. Run the program:
   ```bash
   ./deadlock_sim
   ```

## 🧪 Example Use

You will be prompted to enter:
- Number of processes and resources
- Allocation matrix
- Request matrix
- Available resource vector

The program will then output:
- Whether the system is in a safe state
- Any deadlock condition and which processes are affected

## 👨‍💻 Author

- **Osaid Nur**

## 📄 License

This project is intended for academic and learning purposes only.
