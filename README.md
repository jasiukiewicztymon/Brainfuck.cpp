# Brainfuck.cpp

A Brainfuck interpreter written with C++!

## Example

```cpp
/*
Brainfuck.cpp :
 
Unit test
*/

#include "Brainfuck.h"

int main()
{
	// Interpreter initialization
	Interpreter i = Interpreter();

	// Running from string
	i.run(">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++ .------------. > ++++++[<++++++++ + >-]<+.<.++ + .------.--------.>> > ++++[<++++++++>-] < +.");

	// Running from file
	std::ifstream e("../../../../Brainfuck/Fib.bf");
	i.run(e);

	return 0;
}
```

### Output

```
Hello, World!0
1
1
2
3
5
8
13
21
34
...
```
