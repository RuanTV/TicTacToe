#include <iostream>
#include <cstdlib>

#include "GameBoard.h"

void GameBoard::draw()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "                  ";
		for (int j = 0; j < 3; j++)
		{
			
			switch (gameBoard[i][j])
			{
			case Null:
				std::cout << ' ';
				break;
			case Player1:
				std::cout << 'x';
				break;
			case Player2:
				std::cout << 'o';
				break;
			default:
				break;
			}
			if (j < 2)
				std::cout << " | ";
		}
		if (i < 2)
			std::cout << std::endl << "                  ---------" << std::endl;
	}
}
