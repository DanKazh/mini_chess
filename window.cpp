
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

void chessWindow::FitToHolder()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j].setPosition(sf::Vector2f(holder.left + (i * holder.width / 8), holder.top + (j * holder.height / 8)));
            board[i][j].setSize(sf::Vector2f(holder.width / 8, holder.height / 8));
        }
    }
}


void chessWindow::DrawSquares()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            window.draw(board[i][j]);
        }
    }
}
void chessWindow::DrawPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (squares[i].draw == 1)
        {
            window.draw(squares[i].Sprite);
        }
    }
}
