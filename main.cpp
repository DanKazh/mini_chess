#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "menu.hpp"
#include <time.h>

using namespace sf;

const char* defaultTheme[12] = { "D:/chesss/chesss-project/chesss-project/pieces/wp.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/wr.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/wn.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/wb.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/wk.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/wq.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/bp.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/br.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/bn.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/bb.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/bk.png",
                                "D:/chesss/chesss-project/chesss-project/pieces/bq.png" };
bool mode = 0;

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

int colours[6] = { 118, 150, 86, 238, 238, 210 };

void GamеStart(int* colours)
{
    chessWin window(800, 800, "chess", defaultTheme, colours, mode);
    while (window.Update())
    {
    }
}
void CustomGamеStart(int* colours)
{
    mode = 1;
    chessWin window(800, 800, "chess", defaultTheme, colours, mode);
    while (window.Update())
    {
    }
}

void Options()
{
    colours[0] = rand() % 256;
    colours[1] = rand() % 256;
    colours[2] = rand() % 256;
    colours[3] = rand() % 256;
    colours[4] = rand() % 256;
    colours[5] = rand() % 256;

}


int main()
{
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), L"chess", Style::Fullscreen);
    window.setMouseCursorVisible(false);
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    RectangleShape background(Vector2f(width, height));
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu1.jpg")) return 4;
    background.setTexture(&texture_window);
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 830, 50, L"chess", 150, Color(237, 147, 0), 3);
    String name_menu[]{ L"start a normal game",L"start a random game", L"change board colours",L"i had enough" };
    game::GameMenu mymenu(window, 950, 350, 4, name_menu, 100, 120);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black); 
    mymenu.AlignMenu(2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); }
                if (event.key.code == Keyboard::Return)
                {
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:GamеStart(colours); 
                        break;
                    case 1:CustomGamеStart(colours);  
                        break;
                    case 2:Options(); 
                        break;
                    case 3:window.close();
                        break;

                    }

                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
    }

    return 0;
}

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font,
    Color menu_text_color, int bord, Color border_color)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}
