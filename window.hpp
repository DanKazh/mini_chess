#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

struct chessPiece {
	sf::Sprite Sprite;
	int placeID, x, y;
	bool draw = 0;
};

class chessWin {
private:
	sf::RenderWindow win;
	sf::RectangleShape Squares[8][8];
	sf::IntRect Holder;
	sf::Color $Color$[2];
	sf::Texture pieceTex[12];
	chessPiece pieces[64];
	chessBoard cBoard;
	int $X, $Y;

	void FitToHolder();
	void DrawSquares();
	void DrawPieces();
	void MapPieces();

public:
	chessWin(int width, int height, const char* name, const char* imgPath[12]);
	bool Update();
};

#endif
