#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "window.hpp"

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

int main()
{
    chessWind window(800, 800, "chess", defaultTheme);
    while (window.Update())
    {
    }
    return 0;
}
