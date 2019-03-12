# ECS2
ECS2

cl /MP4 main.cc window/window1.cc window/loadbmp.cc window/destructor.cc window/createwindow.cc /EHsc /std:c++17  /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib /SUBSYSTEM:WINDOWS


# with openGL
cl /MP4 main.cc window/window1.cc window/loadbmp.cc window/destructor.cc window/createwindow.cc window/initializeglew.cc window/initializeopengl.cc window/printprogramlog.cc window/printshaderlog.cc window/render.cc window/swapwindow.cc /EHsc /std:c++17  /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib libraries/glew/lib/win64/glew32.lib libraries/glew/lib/win64/glew32s.lib openGL32.lib /SUBSYSTEM:WINDOWS

# you can compile with wildcards!
cl /MP4 *.cc window/*.cc  /EHsc /std:c++17 /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib libraries/glew/lib/win64/glew32.lib libraries/glew/lib/win64/glew32s.lib openGL32.lib /SUBSYSTEM:WINDOWS

#update: refactor to use scene!
cl /MP4 *.cc window/*.cc  scene/*.cc loader/*.cc /EHsc /std:c++17 /I libraries /link libraries/sdl/lib/win64/SDL2.lib libraries/sdl/lib/win64/SDL2main.lib libraries/glew/lib/win64/glew32.lib libraries/glew/lib/win64/glew32s.lib openGL32.lib /SUBSYSTEM:WINDOWS




# THINGS TO THINK ABOUT:
Matrix multiplication order is reversed in the c++ code because of my column-major implementation. That sucks.
This affects all the calculations.


# The gist of it.
The system currently uses SDL for constructing a window. I may / may not want to switch to GLFW , which at least does not hijack my logprinting. The Vec3f, Vec4f, Mat3 and Mat4 implementations strongly resemble those of Doom 3. I am unsure whether or not they are meritous, as the way they allow access to their public data members through memory addresses is (very) 
error-prone.


# TODO (in order of importance!):

Hold control to move in current plane (in negative z, this is easy. 
how does this work in arbitrary orientation?)

create a material data class -> see openGL stuff. 

refactor window with a Scene class -> refactor use light object.

Does the scene contain objects? or does the scene exists next to objects? heavy stuff.

see if we can fix the matrix multiplication. check the GLM matmul stuff.


try to figure out quaternion rotation!

wrap all SDL_Log by own print function -> create a logger! Logger.log() -> global object(?). This is a more complicated task. see the stackoverflow post.

Keep the initialization of initSDL, initGLEW, and initOpenGL. but we need some sort of alternative for the rest. The window class is getting cluttered.

Some is World Modeling stuff, some of it is not. Split!

write / finish  Vec3f.

Pull apart window into more managable classes. Maybe a LOADER class in the first place.

Pull apart window even more: Light needs a struct. Clearer matrix stuff.

Maybe a drawable(blergh) class.

learn IBOs.

learn vertex stretching?

window.addshaderfromfile should have a pointer to the current active program.

better .obj file parsing.

unify buffers. 


# DONE:

hold left mouse button to rotate.

implement rotation.

create a Light object.

parse object filepaths (objectname, texturename?).

rewrite Mat4 to be column-major instead of row-major.

fix matrices.

implement mat4.translate, mat4.rotate and mat4.scale (disallow shear)

split sendObjectTobuffer into initializeBuffer & initializeTexture.

empty main.cc and create a mainLoop in window.

I fixed the projection matrix. The problem with openGL being column major still exists though. hmm. Maybe I want to rewrite the class.

Furthermore, I don't properly understand near/far plane as of now. What we need to remember is that both of these should be positive (as the openGL perspective projection matrix is sign-flipped (as we are looking in negative Z direction for x/y alignment). sigh.

I found some problems w.r.t openGL being  column-major. it explains a lot that I had trouble simply translating the cat. I should first figure this out, and then continue from there.
I am as of now unsure whether or not the perspective projection works.

Maybe we need to switch to column major. I am not sure yet.




# LONG HAUL:
Parallelize reading in files (fread, split buffer by openMP).

unify buffers & textures.


Object now has a uint for a TBO (texture binding object, texture buffer object, whatever).
The size of GLuint is predetermined, uint is not. We need to replace variable size primitives.









# Installing a library
link against the libraries using /link in the command line, e.g. /link libraries/sdl/lib/win64/sdl2.lib.

Usually, this is not enough, as they require a DLL to operate. the compiler searches for DLLs in C:\Windows\System32 and in C:\Windows\SysWOW64. We need to copy our DLLs to here. I don't know yet how to include DLLs from another location. We do this for SDL and for glew.

FWIW, this was the correct answer, at least in my case. I had to download the SDL2 windows development libraries, then copy \SDL2\lib\x64\SDL2.dll to C:\Windows\System32 and \SDL2\lib\x86\SDL2.dll to C:\Windows\SysWOW64. Voila. 

do this not only for SDL, but for GLEW too.

Additionally, use the x64 cl thing. in CMDer, settings->tasks, create a new task with the following command:

cmd /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat" (e.g. the visual studio installer location.)
