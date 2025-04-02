# 🧠 Deadlock Detection Simulator

This C++ project simulates deadlock detection in an operating system environment by analyzing process-resource allocation scenarios using CSV input files.

## 📚 Table of Contents

- [Overview](#-overview)
- [How It Works](#️-how-it-works)
- [Usage](#-usage)
- [Files](#-files)
- [License](#-license)

## 📁 Overview

The program reads three CSV files representing:
- **Request matrix**: Describes what resources each process is requesting.
- **Allocation matrix**: Describes what resources are currently allocated to each process.
- **Available resources**: Lists the total currently available resources in the system.

It then simulates a deadlock detection algorithm, analyzing whether processes can proceed safely, or if a deadlock will occur. The output includes the system status and any deadlocked processes.

## 🛠️ How It Works

1. Validates the format and size consistency of all three input files.
2. Uses Banker's-like safety algorithm to detect possible deadlocks.
3. Outputs the sequence of safe processes if the system is in a safe state, or lists the deadlocked processes.

## 🧪 Usage

1. Ensure the following files are in the correct path:
   - `Request.csv`
   - `Allocation.csv`
   - `Available.csv`

2. Compile the C++ file:
   ```bash
   g++ -o deadlock_simulator Task3_OsaidNur_1210733.cpp
   ```

3. Run the simulator:
   ```bash
   ./deadlock_simulator
   ```

## 📦 Files

- `Task3_OsaidNur_1210733.cpp` - Main implementation of the simulator
- `CSV files/` - Contains sample input CSV files for simulation
- `ENCS3390_project3.pdf` - Project specification document

## 📜 License

This project is for educational use and submitted as part of coursework.

---

*Developed by Osaid Hasan Nur - ID: 1210733, Section: 4*
