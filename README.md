# Zephyr Hello World

This repository contains a simple "Hello World" application for Zephyr RTOS using the recommended T2 topology.

## Prerequisites
1. Install `west`:
   ```sh
   pip install --user west
   ```
2. Initialize and update the Zephyr repository:
   ```sh
   west init -m https://github.com/zephyrproject-rtos/zephyr --manifest-rev main zephyrproject
   cd zephyrproject
   west update
   west zephyr-export
   pip install --user -r zephyr/scripts/requirements.txt
   ```

## Building the Application
1. Navigate to the `hello_world` directory:
   ```sh
   cd hello_world
   ```
2. Build for a specific board (e.g., `qemu_x86`):
   ```sh
   west build -b qemu_x86 .
   ```

## Running the Application
1. Run in QEMU (if using `qemu_x86`):
   ```sh
   west build -t run
   ```

You should see:
```
Hello, Zephyr!
```

