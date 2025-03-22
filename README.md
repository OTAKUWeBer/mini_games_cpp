Below is the updated README file:

---

# Mini Games C++ (Learning Project)

This repository is a collection of C++ ports of my Python games from [mini_project_games](https://github.com/OTAKUWeBer/mini_project_games). It serves as a learning platform where I convert, experiment, and enhance my previous projects using C++.

## Overview

- **Purpose:**  
  Explore C++ programming by converting and expanding upon games originally written in Python.

- **Status:**  
  This is a work-in-progress project. More games and features will be added over time.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)
- (Optional) Make, if you choose to use the provided Makefile for building the project
- (Optional) VS Code with Code Runner for easy build and execution

### Building and Running

You can compile your code and run the executables manually using your terminal, or use the provided build configurations.

#### Manual Compilation Example

```bash
g++ -std=c++11 your_game.cpp -o bin/your_game
./bin/your_game
```

#### Using the Makefile

A Makefile is provided to automatically compile **all** `.cpp` files in the directory and place the executables in the `bin` folder.

- **Build All Executables:**  
  In your project directory, run:
  ```bash
  make
  ```
  This command finds all `.cpp` files and compiles each into an executable with the same name (without the `.cpp` extension) in the `bin` folder.

- **Run a Specific Game:**  
  To run a specific executable (for example, the game from `pig.cpp`), execute:
  ```bash
  make run TARGET_NAME=pig
  ```
  Replace `pig` with the name of the executable you wish to run.

- **Clean Up Build Files:**  
  To remove the `bin` directory and all compiled executables, run:
  ```bash
  make clean
  ```

#### Using Code Runner

If configured, Code Runner can compile and run your code directly from the editor. Make sure your settings point to the correct Makefile or compilation command.

## Repository Structure

```
mini_games_cpp/
├── *.cpp               # C++ source files for your games (e.g., pig.cpp, 1.cpp, etc.)
├── bin/                # Compiled executables (generated after building)
├── Makefile            # Build automation script (compiles all .cpp files)
├── README.md           # This file
└── .gitignore          # Git ignore file for binaries and object files
```

## Future Work

- Port more games from the [Python version](https://github.com/OTAKUWeBer/mini_project_games).
- Experiment with new C++ features and libraries.
- Enhance the overall gameplay and add additional features.

## Contributing

Your feedback and contributions are welcome! Feel free to open issues or submit pull requests.