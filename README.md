# ECS2
ECS2

cl /MP4 main.cc window/window1.cc window/loadbmp.cc window/destructor.cc window/createwindow.cc /EHsc /std:c++17  /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib /SUBSYSTEM:WINDOWS


FWIW, this was the correct answer, at least in my case. I had to download the SDL2 windows development libraries, then copy \SDL2\lib\x64\SDL2.dll to C:\Windows\System32 and \SDL2\lib\x86\SDL2.dll to C:\Windows\SysWOW64. Voila. 
