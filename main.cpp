#include <iostream>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
};

void showBoard();

int getInput(char player);

int getRow(int choice);
int getCol(int choice);

bool isOccupied(int row, int col);

void placeMove(int choice, char player);
bool handleMove(int choice, char player);

bool checkPlayerWon(char player);
bool checkDraw();

int main()
{
    char player = 'x';
    showBoard();
    std::cout << '\n'
              << "Enter " << "'Ctrl + c' " << "to quit." << "\n\n";

    while (true)
    {
        int choice = getInput(player);

        if (!handleMove(choice, player))
        {
            continue;
        }

        showBoard();

        if (checkPlayerWon(player))
        {
            std::cout << "PLayer " << player << "Won\n";
            break;
        }

        if (checkDraw())
        {
            std::cout << "\nIt is a Draw!\n";
            break;
        }

        player = (player == 'x') ? 'o' : 'x'; // switching
    }

    return 0;
}

void showBoard()
{

    std::cout << '\n';
    for (int i = 0; i < 3; i++)
    { // this is a row loop
        for (int j = 0; j < 3; j++)
        { // this is a column loop
            std::cout << " " << board[i][j] << " ";
            if (j < 2)
            {
                std::cout << "|";
            }
        }
        std::cout << '\n';
        if (i < 2)
        {
            std::cout << "---|---|---" << '\n';
        }
    }
}

int getInput(char player)
{
    int choice;
    while (true)
    {
        std::cout << '\n'
                  << "Enter " << player << ": ";
        if (std::cin >> choice && choice >= 1 && choice <= 9)
            return choice;

        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid Input\n";
    }
}

int getRow(int choice)
{
    return (choice - 1) / 3;
}

int getCol(int choice)
{
    return (choice - 1) % 3;
}

bool isOccupied(int row, int col)
{
    return board[row][col] == 'x' ||
           board[row][col] == 'o';
}

void placeMove(int choice, char player)
{
    int row = getRow(choice);
    int col = getCol(choice);

    board[row][col] = player;
}

bool handleMove(int choice, char player)
{
    int row = getRow(choice);
    int col = getCol(choice);

    if (isOccupied(row, col))
    {
        std::cout << "This block already occupied." << '\n';
        return false;
    }
    else
    {
        placeMove(choice, player);
        return true;
    }
}

bool checkPlayerWon(char player)
{
    // Check if Player X wins

    if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x')
        return true;

    if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x')
        return true;

    if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x')
        return true;

    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
        return true;

    if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
        return true;

    if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x')
        return true;

    if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x')
        return true;

    if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x')
        return true;

    // Check if Player O wins

    if (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o')
        return true;

    if (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o')
        return true;

    if (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o')
        return true;

    if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o')
        return true;

    if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o')
        return true;

    if (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o')
        return true;

    if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o')
        return true;

    if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o')
        return true;

    return false;
}
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '8')
            {
                // this means games have still blocks and func ends here
                return false;
            }
        }
    }
    // game out of the blocks Draw function becomes true
    return true;
}
