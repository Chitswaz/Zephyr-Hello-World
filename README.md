# On Ubuntu/Debian:
sudo apt update && sudo apt install -y \
    git cmake ninja-build gperf \
    ccache dfu-util device-tree-compiler \
    qemu-system-x86  # For emulation

python3 -m venv ~/.venv/zephyr
source ~/.venv/zephyr/bin/activate
pip install west pyelftools

wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.5/zephyr-sdk-0.16.5_linux-x86_64.tar.gz
tar xvf zephyr-sdk-0.16.5_linux-x86_64.tar.gz
cd zephyr-sdk-0.16.5
./setup.sh

git clone https://github.com/your-repo/zephyr-hello-world.git
cd zephyr-hello-world
pip install -r zephyr/scripts/requirements.txt

    
    
