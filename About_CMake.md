1)To compile a c file into a binary

``gcc -o output_file input.c``
or you can even control the level of optimisations that gcc provides
``gcc -O3 -o output_file input.c``

you can compile with 2 source files, if we had included on in the header of another file

``gcc -o main main.c random.c -lm`` the last `-lm` links with `math.h`the math library that is not included in the standard c runtime library.

or another way to do the same is to compile both source files inddividdually and then use the combiled binaries to create the final one

``gcc -c main.c`` , creates a `main.o`
``gcc -c random.c``, creates a `random.o`
``gcc -o main main.o random.o -lm``

Now onto the purpose and the motivation of `make`

A few code bases can potentially be managed an be compiled by hand, but at some point you are going to need some automation
- A popular tool `htop` has about 128 .c files plus all the .h files
- There are more than 20,000 .c files in the Linux Kernel plus all the .h files

### Make 

- its one of the earliest and still popular automation tools for building software.
- It uses a configuration file called `Makefile` to define what .c files are needed and which dependencies exist between them
- Learn about the makefile syntax and the contents inside them
//
//
//
etc
example:
```make
#default rule to build the target
all: hellow

#link the object files to create the executable
hellow: hellow.c
  gcc -o hellow hellow.c

#clean up build files
clean:
  rm -f hellow
```
you now just type `make` to compile the program
now run `make clean` rebuilds the binaries
running `make all` rebuilds all the binaries, although i am not sure about the proper difference between them

- The makefile can become comlpex as we work on bigger projects, the linux kerel makefile has around 2k(this is only in the top level) lines, we can specify what compiler to use, what are the source files, variables can be used inside and all the cool shii

### CMake
- So we need to automate the creation of makefiles as well, thats where `cmake` comes in c for `cross platform`
- Cmake uses a configuration file called `CMakeLists.txt`
    - you define a project in `CMakeLists.txt`
    - run cmake to create the makefile
    - build your project using make
    - Add code, fix things, then to step3, use make again
    - If you add a new .c file or alter the dependencies then jump to step1

- Traditionally makefile are placed in the same directory as the source code, you go to the source directory and then run make
- But Cmake is different, the makefile is generated in a different directory , usually `./build` 
- This is called `Out-of-source` builds Sandwich/c_prog/src
say we are in `/home/kavithesh/CarbamideSandwich/c_prog/src/graphics_prog/`


