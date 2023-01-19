#include <iostream>
#include <cstdlib>

#include "TicTacToe.h"

int main()
{
	TicTacToe ticTacToe;

	while (ticTacToe.isRunning())
	{
		ticTacToe.update();
		ticTacToe.clear();
		ticTacToe.draw();
	}

	return 0;
}
