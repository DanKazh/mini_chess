#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

struct chessSquare {
	sf::Sprite Sprite;
	int placeID, x, y;
	bool draw = 0;
};

class chessWindow {
private:
	sf::RenderWindow window;
	sf::RectangleShape board[8][8];
	sf::Color colours[2];
        sf::IntRect holder;
	sf::Texture pieceTexture[12];
	chessSquare squares[64];
	chessBoard newBoard;
	int sX, sY;

	void FitToHolder();
        void DrawSquares();
	void DrawPieces();
	void MapPieces();

public:
	chessWindow(int width, int height, const char* name, const char* imgPath[12]);
	bool Update();
};

#endif
