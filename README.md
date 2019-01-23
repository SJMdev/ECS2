# ECS2
ECS2

cl /MP4 main.cc window/window1.cc window/loadbmp.cc window/destructor.cc window/createwindow.cc /EHsc /std:c++17  /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib /SUBSYSTEM:WINDOWS


# with openGL
cl /MP4 main.cc window/window1.cc window/loadbmp.cc window/destructor.cc window/createwindow.cc window/initializeglew.cc window/initializeopengl.cc window/printprogramlog.cc window/printshaderlog.cc window/render.cc window/swapwindow.cc /EHsc /std:c++17  /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib libraries/glew/lib/win64/glew32.lib libraries/glew/lib/win64/glew32s.lib openGL32.lib /SUBSYSTEM:WINDOWS

# you can compile with wildcards!
cl /MP4 *.cc window/*.cc  /EHsc /std:c++17 /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib libraries/glew/lib/win64/glew32.lib libraries/glew/lib/win64/glew32s.lib openGL32.lib /SUBSYSTEM:WINDOWS

# Installing a library
link against the libraries using /link in the command line, e.g. /link libraries/sdl/lib/win64/sdl2.lib.

Usually, this is not enough, as they require a DLL to operate. the compiler searches for DLLs in C:\Windows\System32 and in C:\Windows\SysWOW64. We need to copy our DLLs to here. I don't know yet how to include DLLs from another location. We do this for SDL and for glew.


FWIW, this was the correct answer, at least in my case. I had to download the SDL2 windows development libraries, then copy \SDL2\lib\x64\SDL2.dll to C:\Windows\System32 and \SDL2\lib\x86\SDL2.dll to C:\Windows\SysWOW64. Voila. 

do this not only for SDL, but for GLEW too.

Additionally, use the x64 cl thing. in CMDer, settings->tasks, create a new task with the following command:

cmd /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" (e.g. the visual studio installer location.)
