#include <iostream>
#include <random>
#include <conio.h>

#include "TicTacToe.h"
#include "Player.h"

TicTacToe::TicTacToe()
	: running(true)
{
	gameBoard = new GameBoard();
	scoreboard = new Scoreboard();
	currentPlayer = raffleFirstPlayer();
	scoreboard->setCurrentPlayer(currentPlayer);
	draw();
}

TicTacToe::~TicTacToe()
{
	delete gameBoard;
	delete scoreboard;
}

Player TicTacToe::raffleFirstPlayer()
{
	std::random_device randDevice;
	std::mt19937 mt(randDevice());
	std::uniform_int_distribution<int> dist(1, 2);
	
	return (Player)dist(mt);
}

void TicTacToe::draw()
{
	scoreboard->draw();
	gameBoard->draw();
	std::cout << std::endl;
}

void TicTacToe::update()
{
	input();
	checkWinner();
}

void TicTacToe::input()
{
	int position{ 0 };
	
	while (true)
	{
		clear();
		draw();

		std::cin >> position;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (position < 1 || position > 9)
			continue;

		if (!checkGameBoardPosition(position))
			continue;

		break;
	}
	int raw{ 0 }, column{ 0 };
	intToPosition(position, raw, column);

	gameBoard->setValue(raw, column, GameBoard::GameBoardValues(currentPlayer));

	currentPlayer = (currentPlayer == Player::Player1) ? Player::Player2 : Player::Player1;

	scoreboard->setCurrentPlayer(currentPlayer);

	clear();
	draw();
}

bool TicTacToe::checkGameBoardPosition(int position)
{
	int row{ 0 }, column{ 0 };
	intToPosition(position, row, column);

	if (gameBoard->getValue(row, column) == GameBoard::Null)
		return true;
	
	return false;
}

Player TicTacToe::getWinner()
{
	// check row
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard->getValue(0, i) == gameBoard->getValue(1, i) && gameBoard->getValue(0, i) == gameBoard->getValue(2, i))
		{
			if(gameBoard->getValue(0, i) != GameBoard::Null)
				return Player(gameBoard->getValue(0, i));
		}
	}
	// check column
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard->getValue(i, 0) == gameBoard->getValue(i, 1) && gameBoard->getValue(i, 0) == gameBoard->getValue(i, 2))
		{
			if (gameBoard->getValue(i, 0) != GameBoard::Null)
				return Player(gameBoard->getValue(i, 0));
		}
	}
	// check diagonal
	if (gameBoard->getValue(0, 0) == gameBoard->getValue(1, 1) && gameBoard->getValue(0, 0) == gameBoard->getValue(2, 2))
	{
		if (gameBoard->getValue(0, 0) != GameBoard::Null)
			return Player(gameBoard->getValue(0, 0));
	}
	// check diagonal
	if ((gameBoard->getValue(0, 2) == gameBoard->getValue(1, 1) && gameBoard->getValue(0, 2) == gameBoard->getValue(2, 0)))
	{
		if (gameBoard->getValue(0, 2) != GameBoard::Null)
			return Player(gameBoard->getValue(0, 2));
	}

	return Player::Null;
}

void TicTacToe::intToPosition(int position, int& x, int& y)
{
	position--;
	x = position / 3;
	y = position % 3;
}

bool TicTacToe::checkTie()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->getValue(i, j) == GameBoard::Null)
				return false;
		}
	}

	return true;
}

void TicTacToe::reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard->setValue(i, j, GameBoard::Null);
		}
	}
}

void TicTacToe::checkWinner()
{
	Player player = getWinner();
	if (player != Player::Null)
	{
		clear();
		draw();
		std::cout << "Player " << int(player) << " wins\n";
		scoreboard->increaseScore(player);
		playAgain();
	}
	if (checkTie())
	{
		std::cout << "Tie" << std::endl;
		playAgain();
	}
}

void TicTacToe::playAgain()
{
	std::cout << "Press enter to play again..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (_getch() == 13)
		reset();
	else
		running = false;
}
