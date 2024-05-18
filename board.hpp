#include <vector>
struct move
{
    int oX, oY, X, Y;
    move() {}
    move(int oldX, int oldY, int newX, int newY);
};
struct board
{
    int arr[8][8] = { {-1, -1, -1, -1, -1, -1, -1, -1},
                     {-1, 7, 6, -1, -1, 0, 1, -1},
                     {-1, 8, 6, -1, -1, 0, 2, -1},
                     {-1, 9, 6, -1, -1, 0, 3, -1},
                     {-1, 11, 6, -1, -1, 0, 5, -1},
                     {-1, 10, 6, -1, -1, 0, 4, -1},
                     {-1, 7, 6, -1, -1, 0, 1, -1},
                     {-1, -1, -1, -1, -1, -1, -1, -1} };
};
class chessBoard
{
private:
    bool turn = 1;
    const char* notation(int x, int y);
    std::vector<board> history;

    void wPawn(std::vector<move>& moves, int x, int y);
    void bPawn(std::vector<move>& moves, int x, int y);
    void King(std::vector<move>& moves, int x, int y);
    void Queen(std::vector<move>& moves, int x, int y);
    void Rook(std::vector<move>& moves, int x, int y);
    void Bishop(std::vector<move>& moves, int x, int y);
    void Knight(std::vector<move>& moves, int x, int y);
    std::vector<move> getLegalMoves(board b, bool color);

public:
    board mBoard;
    bool playMove(move req);
    bool nextTurn();
};
