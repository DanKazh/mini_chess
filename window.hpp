#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "board.hpp"

struct chessPiece
{
    sf::Sprite Sprite;
    int pieceID, x, y;
    bool draw = 0;
};

class chessWin
{
private:
    sf::RenderWindow win;
    sf::RectangleShape Squares[8][8];
    sf::IntRect Holder;
    sf::Texture pieceTex[12];
    chessPiece pieces[64];
    chessBoard cBoard;
    int selected[2];
    bool cSelect = 0;
    int sX, sY;

    void FitToHolder();
    void DrawSquares();
    void DrawPieces();
    void MapPieces();
    void MapPieces(move curr);

public:
    chessWin(int width, int height, const char* name, const char* imgPath[12], int* colours, bool mode);
    sf::Color sColors[2];
    void ChangeColors(int red, int green, int blue, int side);
    bool Update();
};
#endif
