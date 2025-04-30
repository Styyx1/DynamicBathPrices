# Dynamic Bath Prices 

Adjusts bath prices based on the room price. 
formula is:
```
BathPrice = RoomPrice / 2
but with a minimum of 20
```
## Requirements for Playing:
[Improved Innkeepers](https://www.nexusmods.com/skyrimspecialedition/mods/46659) (soft requirement, not actually needed but made for changing room costs)   
[Simple Inn Bath](https://www.nexusmods.com/skyrimspecialedition/mods/49014) (hard requirement. needs a global from the mod and is made for this mod)   
[Address Library](https://www.nexusmods.com/skyrimspecialedition/mods/32444)    

this mod only works on Skyrim 1.6.1170+

# Building the dll

### Requirements
* [XMake](https://xmake.io) [2.8.2+]
* C++23 Compiler (MSVC, Clang-CL)

## Getting Started
```bat
git clone --recurse-submodules https://github.com/Styyx1/DynamicBathPrices
cd DynamicBathPrices
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Build Output (Optional)
If you want to redirect the build output, set one of or both of the following environment variables:

- Path to a Skyrim install folder: `XSE_TES5_GAME_PATH`

- Path to a Mod Manager mods folder: `XSE_TES5_MODS_PATH`

### Project Generation (Optional)
If you want to generate a Visual Studio project, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*


