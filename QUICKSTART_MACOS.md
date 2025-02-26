##

1. Install pico-sdk 2.1.1
   https://github.com/raspberrypi/pico-sdk/releases/tag/2.1.1

2. Install arm-node-eabi
   https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads

3. Update your PICO_SDK_PATH and PICO_TOOLCHAIN_PATH environment variables to point to the pico-sdk directory

```
export PICO_SDK_PATH=/path/to/pico-sdk-2.1.1
export PICO_TOOLCHAIN_PATH="/Applications/ArmGNUToolchain/14.2.rel1/arm-none-eabi/bin/"
```

4. Change the path of CMAKE_C_COMPILER and CMAKE_CXX_COMPILER in CMakePresets.json to the installed binaries

```
"configurePresets": [
{
    "name": "rp2040",
    "generator": "Ninja",
    "binaryDir": "${sourceDir}/cmake-build-debug",
    "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "/Applications/ArmGNUToolchain/14.2.rel1/arm-none-eabi/bin/arm-none-eabi-gcc",
        "CMAKE_CXX_COMPILER": "/Applications/ArmGNUToolchain/14.2.rel1/arm-none-eabi/bin/arm-none-eabi-g++"
    }
},
```

5. Install picotool

```
brew install picotool
```

6. Build the project

```
./debug.sh rp2040_macos
```

7. Flash the project

```
./flash.sh
```
