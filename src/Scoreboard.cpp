#include <iostream>

#include "Scoreboard.h"
#include "Player.h"

void Scoreboard::draw()
{
	std::cout << "-----------------------------     ---------------------" << std::endl;
	std::cout << "| Player 1: " << playerScore[int(Player::Player1)] << " | ";
	std::cout << "Player 2: " << playerScore[int(Player::Player2)] << " |     ";
	std::cout << "| Current Player: " << int(currentPlayer) << " |" << std::endl;
	std::cout << "-----------------------------     ---------------------" << std::endl << std::endl;
}
