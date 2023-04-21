# Brainfuck.cpp

A simple Brainfuck interpreter written in C++! First of all, start by including the `Brainfuck.h` file:

```cpp
#include "Brainfuck.h"
```

To start by creating the `Interpreter` class:

```cpp
// Interpreter initialization
Interpreter i = Interpreter();
```

Now, you're ready to use the interpreter. You can load the code from a string, or an ifstream:

```cpp
// Running from string
i.run(">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++ .------------. > ++++++[<++++++++ + >-]<+.<.++ + .------.--------.>> > ++++[<++++++++>-] < +.");

// Running from file
std::ifstream e("../../../../Brainfuck/Fib.bf");
i.run(e);
```
