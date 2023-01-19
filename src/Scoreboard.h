#pragma once
#include "Player.h"

class Scoreboard
{
private:
	int playerScore[3]{ 0 };
	Player currentPlayer{Player::Player1};
public:

	inline void setCurrentPlayer(Player player) { currentPlayer = player; }
	inline void increaseScore(Player player) { playerScore[int(player)]++; }
	inline void decreaseScore(Player player) { playerScore[int(player)]--; }
	inline void resetScore() { playerScore[1] = 0; playerScore[2] = 0; }
	inline void setScore(Player player, int value) { playerScore[int(player)] = value; }

	void draw();
};
