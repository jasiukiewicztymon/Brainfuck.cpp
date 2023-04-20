/*
Brainfuck.cpp :
 
Unit test
*/

#include <thread>

#include "Brainfuck.h"



#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

int main()
{
	Interpreter i1 = Interpreter();

	std::ifstream e1("../../../../Brainfuck/HelloWorld.bf");
	i1.run(e1);

	std::cout << "\n";

	Interpreter i2 = Interpreter();

	std::ifstream e2("../../../../Brainfuck/Input.bf");
	i2.run(e2);

	std::cout << "\n";

	Interpreter i3 = Interpreter();

	std::ifstream e3("../../../../Brainfuck/Fib.bf");
	i3.run(e3);

	return 0;
}
