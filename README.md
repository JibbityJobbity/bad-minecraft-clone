# How to build/run
- GNU/Linux

CMake is required to generate build configurations.
Please install GLFW from your distribution's repositories and run the following:
```
$ mkdir build
$ cd build
$ cmake ../
$ make
```
To run it, move the compiled binary to the repo's root directory and run
```
$ mv BadMinecraftClone ../
$ ./BadMinecraftClone
```

- Windows (MinGW or Visual Studio)

CMake is required to generate build configurations.
For Windows, you need to compile [GLFW](https://github.com/glfw/glfw) and place libglfw3 in the lib folder.
Other than that, use CMake to configure the project to the compiling environment of your choice.
Once you're done compiling, take BadMinecraftClone.exe and move it to the repo's root directory and run.
