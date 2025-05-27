# graphics_prog
they made us do graphics programming gng  🥀


Graphics programming using OPENGL in Arch Linux, seting up through rendering your first image.
### graphics.h

using the graphics.h header in the file to simply render a circle
- the header file is used to render simple graphics in windows environment, you should be using C/C++ turbo
- Since i run linux, i had to try using libgraph, which is a linux implementation of the same
 so run ``yay -S libgraph``
 - But my system had other plans, it cannot install and build the the package, because i had build errors while trying to compile Guile 1.8 on Arch linux with yay
 - The error log indicates the following problem
   - functions like ``scm_char_eq_p``, ``scm_char_less_p`` are being passed to: 
   ```scm_c_define_subr(name, type, function);```
   - but the third argument ``function`` expects a function with no arguments, whereas the functions you are passing have a signature
   - hence the compiler throws the error 
   ```error: passing argument 3 of 'scm_c_define_subr' from incompatible pointer type [-Wincompatible-pointer-types]```

- This is likely due to the incompatability between the compiler ``15.1.1 20250425`` and the old Guile 1.8 codebase, its over a decade old and isnt maintained.
- So i either have to use ``Guile 2.x or 3.x``, or patch the current Guile version, modifying it such that the functions being passed it the appropriate function is of expected type, or use a docker environment

### OPENGL

what is opengl: it is an cross platform API to render 2D and 3D graphics, it is a specification, and is indepedant of the hardware that uses it, since mine has `intel integrated UHD graphics` , i can use `mesa` which is an opensource implementation of Opengl

what is mesa: On Linux systems, Mesa is the de facto standard for providing OpenGL (and other API) capabilities, especially for open-source graphics drivers.Mesa's role is to take the abstract commands from an application (written using the OpenGL API) and translate them into specific instructions that your graphics hardware (like my Intel UHD Graphics) can understand and execute.

Think of it like this:

  - OpenGL is the language that graphics applications speak to request drawing operations.
  - Mesa is the interpreter and executor that understands this language and translates it into actions for your graphics card

**step1**: system requirements and drivers

```bash
sudo pacman -Syu
sudo pacman -S mesa libglvnd vulkan-intel vulkan-tools
```

`mesa` provides OpenGL implementation.
``vulkan-intel`` provides Vulkan driver for Intel GPUs (optional but useful for future).
``vulkan-tools`` for testing Vulkan (optional).

**step2**: install dev dependencies

```bash
sudo pacman -S base-devel cmake git gcc
sudo pacman -S glfw glew glm
```
    glfw: window/context/input

    glew: OpenGL function loader

    glm: math library

    All are OpenGL helper libraries.

**step3**: setup of project

```bash
mkdir -p ~/dev/opengl-triangle/src
cd ~/dev/opengl-triangle
```

Here create a filled called `CMakeLists.txt`

```make
cmake_minimum_required(VERSION 3.10)
project(OpenGLTriangle)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(OpenGLTriangle src/main.cpp)
target_link_libraries(OpenGLTriangle GLEW::GLEW glfw OpenGL::GL)
```

**step4**: write minimal testing code

just to check whether the setup is working or not, we will first do so by checking if we can open up a black window

```cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) return -1;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
```

**step5**: build and run

```bash
cd ~/dev/opengl-triangle
cmake -S . -B build
cmake --build build
./build/OpenGLTriangle
```

if you see a black window, great it works!

here to render the triangle , follow the below steps:

- navigate to the build directory in the root directory, it not present, create one
- run `cmake ..`
- run `cmake --build .``
- then go to the `./build` and run `./triangle`, this will render the triangle

![alt text](/images/triangle.png)

boom!!
we have our first image rendered in OPENGL gng 