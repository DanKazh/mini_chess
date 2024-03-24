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

void chessWindow::MapPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (squares[i].draw == 1)
        {
            squares[i].Sprite.setPosition(sf::Vector2f(holder.left + (squares[i].x * holder.width / 8), holder.top + (squares[i].y * holder.height / 8)));
            squares[i].Sprite.setScale(holder.width / 1600.0, holder.height / 1600.0);
        }
    }
}

chessWindow::chessWindow(int width, int height, const char* name, const char* imgPath[12])
{
    bool colour = 1;
    colours[0].r = 150;
    colours[0].g = 75;
    colours[0].b = 0;
    colours[1].r = 238;
    colours[1].g = 238;
    colours[1].b = 210;
    sX = width;
    sY = height;
    holder.left = 0;
    holder.top = 0;
    holder.width = width;
    holder.height = height;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j].setFillColor(colours[colour]);
            colour = !colour;
        }
        colour = !colour;
    }
    FitToHolder();
    sf::IntRect blank;
    for (int i = 0; i < 12; ++i)
    {
        pieceTexture[i].loadFromFile(imgPath[i], blank);
    }
    int index = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            squares[index].placeID = newBoard.mini_board[i][j];
            squares[index].x = i;
            squares[index].y = j;
            if (squares[index].placeID != -1)
            {
                squares[index].Sprite.setTexture(pieceTexture[squares[index].placeID], true);
                squares[index].draw = 1;
            }
            ++index;
        }
    }
    MapPieces();
    window.create(sf::VideoMode(width, height), name);
}

bool chessWindow::Update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Resized:
            sX = window.getSize().x;
            sY = window.getSize().y;
            window.setView(sf::View(sf::FloatRect(0, 0, sX, sY)));
            if (sX > sY)
            {
                holder.width = sY;
                holder.height = sY;
                holder.left = sX / 2 - holder.width / 2;
                holder.top = 0;
            }
            else
            {
                holder.width = sX;
                holder.height = sX;
                holder.top = sY / 2 - holder.height / 2;
                holder.left = 0;
            }
            MapPieces();
            FitToHolder();
            break;
        case sf::Event::Closed:
            window.close();
            return false;
            break;
        }
    }
    window.clear();
    DrawSquares();
    DrawPieces();
    window.display();
    return true;
}
