#pragma once

class GameBoard
{
public:

	enum GameBoardValues
	{
		Null, Player1, Player2
	};

private:

	GameBoardValues gameBoard[3][3]{ GameBoardValues::Null };

public:

	inline void setValue(int x, int y, GameBoardValues value) { gameBoard[x][y] = value; }
	inline GameBoardValues getValue(int x, int y) const { return gameBoard[x][y]; }

	void draw();

};
