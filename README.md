# CMake-OpenCV-from-sources
Compile OpenCV with contrib modules from sources as part of the CMake build.

This is a small example that demonstrates how OpenCV including contrib modules can be compiled from sources only using CMake as part of the build.

Suggestions for improvements are welcome and appreciated.

# Caveat
Please note that building OpenCV from sources can take qutie a while, on my machine it took ~2h for both Debug and Release builds. Once OpenCV and the contrib modules are built you should know that deleting the build folder will force you to rebuild OpenCV again.
In addition, the build folder will grow huge (several gigabytes) so beware.

I am by no means an expert for CMake and therefor there may be better ways to work with OpenCV and C++. But working with third-party c++-libraries on Windows is quite painful for amateurs like me. I like this approach because I do not have to compile a library file for all plattforms myself and wire it into my projects and can easily update to a newer version of OpenCV. Anyone can checkout the project and have the version of OpenCV that the project was built with, not the version that is currently installed somewhere on his machine. There is also no need for any package manager or alike.

# Acknowledgement
This is heavily based on the article "[OpenCV + Visual Studio + CMake = Adventure time](http://www.graymatterdeveloper.com/2019/12/25/opencv-and-cmake-in-cpp/)" and corresponding [Github-Repo](https://github.com/myarichuk/OpenCV.CMake). My small contribution to this is the addition of the opencv contrib modules.
