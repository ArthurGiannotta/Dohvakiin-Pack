#include "Console.h"
#include "Global.h"
#include <conio.h>
#include <iostream>
using namespace std;

Console::Console(void)
{
	resetInput();
}

Console::~Console(void)
{
	if(input) delete input;
}

void Console::resetInput(void)
{
	if(input) delete input;

	input = new char[MAX_COMMAND_SIZE];
	inputN = 0;

	while(inputN < MAX_COMMAND_SIZE) {
		input[inputN++] = '\0';
	}

	inputN = 0;
}

void Console::tick(void)
{
	// Handle Input
	if(_kbhit()) {
		char c = (inputN == MAX_COMMAND_SIZE - 1) ? '\r' : static_cast<char>(_getch());
		switch(c) {
			case '\b': if(inputN > 0) {inputN--; util::backspace();} break;
			case '\r': input[inputN++] = '\0'; cout << '\n'; onCommand(); resetInput(); break;
			default: input[inputN++] = c; cout << c; break; // support for changing cursor position and delete button and insert button
		}
	}
	// Shows current container
	//cout <<currentContainer.name
	// Handle Input
	//cin.getline(command, MAX_COMMAND_SIZE);
	// Calls function that manage commands
	//onCommand(command);
}

void Console::onCommand(void)
{
	// command return bool tyo see error or not // error list List<errors> to make erros maybe erros of each function as well
}