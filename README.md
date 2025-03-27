# Zephyr Hello World Application

This project demonstrates a simple application running on Zephyr RTOS using QEMU emulation for x86 architecture.

## System Requirements
- Ubuntu/Debian Linux (or WSL on Windows)
- Python 3.10+
- 4GB RAM minimum
- 5GB disk space
## Project Structure
```
zephyr-hello-world/
├── application/       # Your application code
│   ├── src/
│   │   └── main.c     # Main application source
│   ├── CMakeLists.txt # Build configuration
│   └── prj.conf       # Zephyr settings
├── zephyr/            # Zephyr RTOS source
└── build/             # Generated build files (safe to delete)
```

## Complete Setup Guide

### 1. Install System Dependencies
These packages are required for building Zephyr applications:
```bash
sudo apt update && sudo apt install -y \
    git cmake ninja-build gperf \
    ccache dfu-util device-tree-compiler \
    qemu-system-x86  # The emulator we'll use to run our application
```
- `git`: Version control system
- `cmake`, `ninja-build`: Build system tools
- `gperf`: Perfect hash function generator
- `ccache`: Compiler cache for faster builds
- `dfu-util`: Device firmware update tool
- `device-tree-compiler`: For handling hardware configurations
- `qemu-system-x86`: Machine emulator for testing

### 2. Set Up Python Virtual Environment
We create an isolated Python environment to avoid conflicts with system packages:
```bash
python3 -m venv ~/.venv/zephyr  # Creates virtual environment
source ~/.venv/zephyr/bin/activate  # Activates the environment
pip install west pyelftools  # Installs Zephyr's build tool and ELF utilities
```
- Virtual environments keep Zephyr's dependencies separate
- `west`: Zephyr's meta-tool for project management
- `pyelftools`: For analyzing executable files

### 3. Install Zephyr SDK
The SDK contains all necessary cross-compilers and tools:
```bash
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.5/zephyr-sdk-0.16.5_linux-x86_64.tar.gz
tar xvf zephyr-sdk-0.16.5_linux-x86_64.tar.gz  # Extract the SDK
cd zephyr-sdk-0.16.5
./setup.sh  # Run the interactive setup
```
- Accept the license agreement when prompted
- The SDK will install to `~/zephyr-sdk-0.16.5` by default

### 4. Get the Project and Zephyr Dependencies
```bash
git clone https://github.com/Chitswaz/zephyr-hello-world.git
cd zephyr-hello-world
pip install -r zephyr/scripts/requirements.txt  # Install remaining Python dependencies
```
This clones the repository and installs additional tools needed for building Zephyr applications.

## Building and Running

### First-Time Setup
```bash
source ~/.venv/zephyr/bin/activate  # Always activate the environment first
source zephyr/zephyr-env.sh  # Sets up Zephyr environment variables
```

### Build the Application
```bash
west build -b qemu_x86 application
```
- Builds for the QEMU x86 target
- Output goes to the `build/` directory

### Run in QEMU Emulator
```bash
west build -t run
```
- Starts the emulator with your application
- Console output will appear in this terminal
- To exit: Press `Ctrl+A` then `x`


