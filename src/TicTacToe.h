#pragma once
#include <cstdlib>

#include "GameBoard.h"
#include "Player.h"
#include "Scoreboard.h"

class TicTacToe
{
private:
	GameBoard* gameBoard{ nullptr };
	Scoreboard* scoreboard{ nullptr };
	bool running{ false };
	Player currentPlayer {Player::Player1};

	Player raffleFirstPlayer();
	void input();
	Player getWinner();
	void checkWinner();
	bool checkTie();
	bool checkGameBoardPosition(int position);

	void intToPosition(int position, int& x, int& y);
	void reset();
	void playAgain();

public:
	
	TicTacToe();
	~TicTacToe();

	void draw();
	void update();
	inline void clear() { system("cls"); }

	inline bool isRunning() const { return running; }
	inline Player getCurrentPlayer() const { return currentPlayer; }

};
