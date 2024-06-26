#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "window.hpp"

void chessWin::FitToHolder()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Squares[i][j].setPosition(sf::Vector2f(Holder.left + (i * Holder.width / 8), Holder.top + (j * Holder.height / 8)));
            Squares[i][j].setSize(sf::Vector2f(Holder.width / 8, Holder.height / 8));
        }
    }
}
void chessWin::DrawSquares()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            win.draw(Squares[i][j]);
        }
    }
}
void chessWin::DrawPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            win.draw(pieces[i].Sprite);
        }
    }
}
void chessWin::MapPieces()
{
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
}
void chessWin::MapPieces(move curr)
{
    chessPiece* current = nullptr;
    bool capture = false;
    for (int i = 0; i < 64; ++i)
    {
        if (pieces[i].draw == 1)
        {
            if (pieces[i].x == curr.oX && pieces[i].y == curr.oY)
            {
                current = &pieces[i];
            }
            if (pieces[i].x == curr.X && pieces[i].y == curr.Y)
            {
                pieces[i].draw = 0;
                capture = true;
            }
            pieces[i].Sprite.setPosition(sf::Vector2f(Holder.left + (pieces[i].x * Holder.width / 8), Holder.top + (pieces[i].y * Holder.height / 8)));
            pieces[i].Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
        }
    }
    current->x = curr.X;
    current->y = curr.Y;
    current->Sprite.setPosition(sf::Vector2f(Holder.left + (current->x * Holder.width / 8), Holder.top + (current->y * Holder.height / 8)));
    current->Sprite.setScale(Holder.width / 1600.f, Holder.height / 1600.f);
}
void MShuff(int m[], int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i)
        std::swap(m[i], m[std::rand() % size]);
}
void FillSecondRow(int arr[8][8], bool& mode) {
    if (mode)
    {
        int m[6] = { 1, 1, 2, 3, 4, 5 };
        MShuff(m, 6);
        for (int i = 1; i < 7; i++)
        {
            arr[i][6] = m[i - 1];
            arr[i][1] = m[i - 1] + 6;
        }
    }
}
void chessWin::ChangeColors(int red, int green, int blue, int side)
{
    sColors[side].r = red;
    sColors[side].g = green;
    sColors[side].b = blue;
}
chessWin::chessWin(int width, int height, const char* name, const char* imgPath[12], int* colours, bool mode)
{
    bool sColor = 1;
    sColors[0].r = colours[0];
    sColors[0].g = colours[1];
    sColors[0].b = colours[2];
    sColors[1].r = colours[3];
    sColors[1].g = colours[4];
    sColors[1].b = colours[5];
    sX = width;
    sY = height;
    Holder.left = 0;
    Holder.top = 0;
    Holder.width = width;
    Holder.height = height;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Squares[i][j].setFillColor(sColors[sColor]);
            sColor = !sColor;
        }
        sColor = !sColor;
    }
    FitToHolder();
    sf::IntRect blank;
    for (int i = 0; i < 12; ++i)
    {
        pieceTex[i].loadFromFile(imgPath[i], blank);
    }
    int index = 0;
    FillSecondRow(cBoard.mBoard.arr, mode);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            pieces[index].pieceID = cBoard.mBoard.arr[i][j];
            pieces[index].x = i;
            pieces[index].y = j;
            if (pieces[index].pieceID != -1)
            {
                pieces[index].Sprite.setTexture(pieceTex[pieces[index].pieceID], true);
                pieces[index].draw = 1;
            }
            ++index;
        }
    }
    MapPieces();
    win.create(sf::VideoMode(width, height), name);
}


bool chessWin::Update()
{
    sf::Event event;
    while (win.pollEvent(event))
    {
        if (event.type == sf::Event::Resized) {
            sX = win.getSize().x;
            sY = win.getSize().y;
            win.setView(sf::View(sf::FloatRect(0, 0, sX, sY)));
            if (sX > sY)
            {
                Holder.width = sY;
                Holder.height = sY;
                Holder.left = sX / 2 - Holder.width / 2;
                Holder.top = 0;
            }
            else
            {
                Holder.width = sX;
                Holder.height = sX;
                Holder.top = sY / 2 - Holder.height / 2;
                Holder.left = 0;
            }
            MapPieces();
            FitToHolder();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                int pX, pY;
                pX = event.mouseButton.x;
                pY = event.mouseButton.y;
                int projX, projY;
                projX = ((pX - Holder.left) - ((pX - Holder.left) % (Holder.width / 8))) / (Holder.width / 8);
                projY = ((pY - Holder.top) - ((pY - Holder.top) % (Holder.height / 8))) / (Holder.height / 8);
                if (cSelect == 0)
                {
                    if (pX >= Holder.left && pX <= Holder.left + Holder.width && pY > Holder.top && pY < Holder.top + Holder.height)
                    {
                        selected[0] = projX;
                        selected[1] = projY;
                        Squares[selected[0]][selected[1]].setFillColor(sf::Color(186, 202, 68));
                        cSelect = 1;
                    }
                }
                else
                {
                    if (selected[0] == projX && selected[1] == projY)
                    {
                        Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                        cSelect = 0;
                    }
                    else
                    {
                        move m(selected[0], selected[1], projX, projY);
                        if (cBoard.playMove(m))
                        {
                            MapPieces(m);
                            cBoard.nextTurn();
                        }
                        Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                        cSelect = 0;
                    }
                }
            }
            else if (event.mouseButton.button == sf::Mouse::Button::Right)
            {
                Squares[selected[0]][selected[1]].setFillColor(sColors[1 - ((selected[0] + selected[1]) % 2)]);
                cSelect = 0;
            }
        }
        if (event.type == sf::Event::Closed) {
            win.close();
            return false;
        }
    }
    win.clear();
    DrawSquares();
    DrawPieces();
    win.display();
    return true;
}
