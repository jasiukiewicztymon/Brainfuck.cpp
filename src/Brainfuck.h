#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>

#include <conio.h>
#include <stdio.h>

class Interpreter {
	std::vector<int> checkPoints, memory = { 0 };

	int index = 0, ptr = 0;
	std::string source;

	void exec() {
		this->index = 0; 
		this->ptr = 0;
		this->memory = { 0 };
		this->checkPoints = {};

		std::vector<int> Stack;

		/* Creating a check points vector with relative positions to manage 
		loops while running the program */

		for (int i = 0; i < this->source.size(); i++) {
			this->checkPoints.push_back(i);

			if (this->source[i] == '[')
				Stack.push_back(i);
			else if (this->source[i] == ']') {
				int t = Stack[Stack.size() - 1];
				Stack.pop_back();
				this->checkPoints[t] = i;
				this->checkPoints[i] = t;
			}
		}

		Stack = {};

		/* Brainfuck runtime */

		while (this->index != this->source.size()) {
			char ch = this->source[this->index];

			switch (ch) {
			case '>':
				this->ptr++;
				if (this->ptr == this->memory.size())
					this->memory.push_back(0);
				break;
			case '<':
				if (this->ptr > 0)
					this->ptr--;
				break;
			case '+':
				this->memory[this->ptr]++;
				break;
			case '-':
				this->memory[this->ptr]--;
				break;
			case ',':
				this->memory[this->ptr] = getch();
				std::cout << (char)this->memory[this->ptr];
				break;
			case '.':
				std::cout << (char)this->memory[this->ptr];
				break;
			case '[':
				if (this->memory[this->ptr] == 0)
					this->index = this->checkPoints[this->index];
				break;
			case ']':
				if (this->memory[this->ptr] != 0)
					this->index = this->checkPoints[this->index];
				break;
			}

			this->index++;
		}
	}
public:
	// Those functions enable running the BrainFuck script from string or file

	void run(std::string source) {
		this->source = source;
		this->exec();
	}
	void run(std::ifstream & source) {
		if (source.is_open()) {
			std::string txt;
			this->source = "";

			while (std::getline(source, txt)) {
				this->source += txt;
			}

			this->exec();
		}
	}
};