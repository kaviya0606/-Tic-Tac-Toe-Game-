#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize board
void initializeBoard()
{
    char position = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = position++;
        }
    }

    currentPlayer = 'X';
}

// Function to display board
void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << endl;

        if(i < 2)
            cout << "-----------" << endl;
    }

    cout << "\n";
}

// Function to make move
bool makeMove(int position)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if(position < 1 || position > 9)
        return false;

    if(board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;

    return true;
}

// Function to check winner
bool checkWinner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonal
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    // Anti-Diagonal
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// Function to switch player
void switchPlayer()
{
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    char playAgain;

    do
    {
        initializeBoard();

        int position;
        bool gameOver = false;

        cout << "\n================================";
        cout << "\n       TIC TAC TOE GAME";
        cout << "\n================================\n";

        while(!gameOver)
        {
            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";

            cin >> position;

            if(!makeMove(position))
            {
                cout << "Invalid Move! Try Again.\n";
                continue;
            }

            if(checkWinner())
            {
                displayBoard();

                cout << "🎉 Player "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if(checkDraw())
            {
                displayBoard();

                cout << "🤝 Game Draw!\n";

                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}
