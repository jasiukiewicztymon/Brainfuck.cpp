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
