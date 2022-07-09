# CS 154 Resources

This is a collection of lab problems that were given to me when I took the CS 154 (Programming Paradigms Laboratory) course, along with my solutions to them.

Hopefully, this will prove useful to you!

Some resources I find useful in this course were:
- [learncpp.com](https://www.learncpp.com/) to learn about Object Oriented Programming in C++
- [realpython.com](https://realpython.com/) to learn about Python (Disclaimer: I have tried only the free part)
- [The FLTK Manual](https://www.fltk.org/doc-1.3/index.html) to learn about FLTK
- The book "An Introduction to Prolog Programming" by Ulle Endriss for Prolog

During the CS 152 and 154 courses, you will need to use Linux/a Linux VM (if you are using WSL, make sure to use WSL 2 with Graphics (this is available only on Windows 11)), with the following software installed:
- The gcc and g++ compilers for C and C++ respectively
- A Python interpreter (preferable python3.8 or above)
- The FLTK compiler to use the FLTK graphics library for C++
- The ghc compiler for Haskell
- The gprolog interpreter for Prolog

## To install gcc and g++, run:
    sudo apt install build-essential
## To install a Python interpreter, run:
    sudo apt install python3.8
## To install the FLTK compiler, run the following commands
    sudo apt install libxft-dev

    sudo apt install xorg

    wget https://www.fltk.org/pub/fltk/1.3.8/fltk-1.3.8-source.tar.bz2

    tar -xvf fltk-1.3.8-source.tar.bz2

    cd fltk-1.3.8

    ./configure


To compile a file (named ```file.cpp``` for example), run
    fltk-config --compile file.cpp
This will create and executable named ```file```

Note that if you are using an IDE (such as VSCode), then you may also find it helpful to add the directory ```FL``` to your include path by running:
    cp -r FL /usr/local/include
## To install the ghc compiler, run:
    sudo apt install ghc
## To install the latest version of gprolog:
    wget http://www.gprolog.org/gprolog-1.5.0.tar.gz

    tar -xvf gprolog-1.5.0.tar.gz

    cd gprolog-1.5.0/src

    ./configure

    make

    sudo make install
