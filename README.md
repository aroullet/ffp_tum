# FFP-TUM

## Description
* This project was developed as part of an university assignment. It aims to simulate the spread of a virus using a simple SIR model.
The user is prompted to set values for some of the model's key parameters and a window will open.
* Blue dots represent sane individuals, red are infected and green recovered.
* Each person in the simulation has a chance to transition from any state to the other in the following order Susceptible &rarr; Infected &rarr; Recovered &rarr; Susceptible

## Installation
This project uses the external library SDL2 to create a GUI. \
For Debian-based operating systems, install them with the following command:\
```sudo apt update && sudo apt install -y libsdl2 libsdl2-image```\
For Arch-based distros, run ```sudo pacman -S sdl2 sdl2_image```\
For other platforms, refer to this link: https://wiki.libsdl.org/Installation \
To build the executable, clone the repository, make sure you have CMake installed and run:
`mkdir build && cd build && cmake .. && make all`\
This should create an executable named ffp_tum.
