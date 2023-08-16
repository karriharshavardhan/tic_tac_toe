#include <bits/stdc++.h>
using namespace std;

void main1();
char choice();
void display_board(vector<char> board);
void filling(vector<char> &board, int count, char player1, char player2);
bool decide(vector<char> board);
bool occupied(vector<char> board);
bool check_vacancy(vector<char> board, int i);
bool check_row(vector<char> board);
bool check_column(vector<char> board);
bool check_diagonal(vector<char> board);
void rematch();

void main1()
{
    int count{};
    vector<char> board;
    board = {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1, player2;
    player1 = choice();
    if (player1 == 'X' || player1 == 'x')
    {
        player1 = 'X';
        player2 = 'O';
    }
    else
    {
        player2 = 'X';
        player1 = 'O';
    }
    filling(board, count, player1, player2);
    cout << endl;
    rematch();
}

char choice()
{
    cout << "which symbol do you want to choose(player 1)(X/O): "; // case sensitve
    char player1;
    cin >> player1;
    if (player1 == 'X' || player1 == 'O' || player1 == 'x' || player1 == 'o')
        return player1;
    else
    {
        cout << "invalid!\n";
        player1 = choice();
    }
    return ' ';
}

void display_board(vector<char> board)
{
    cout << " " << board[7] << " | " << board[8] << " | " << board[9] << endl;
    cout << "-----------" << endl;
    cout << " " << board[4] << " | " << board[5] << " | " << board[6] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1] << " | " << board[2] << " | " << board[3];
}

void filling(vector<char> &board, int count, char player1, char player2)
{
    while (!decide(board) && !occupied(board))
    {
        cout << "current board: \n";
        display_board(board);
        cout << endl;
        if (count % 2 == 0)
        {
            int num;
            cout << "player1 enter a number from 1 to 9: ";
            cin >> num;
            if (check_vacancy(board, num))
            {
                board[num] = player1;
            }
            else
            {
                cout << "position " << num << " is occupied, choose someother position\n";
                filling(board, count, player1, player2);
            }
            count++;
        }
        else
        {
            int num;
            cout << "player2 enter a number from 1 to 9: ";
            cin >> num;
            if (check_vacancy(board, num))
            {
                board[num] = player2;
            }
            else
            {
                cout << "position " << num << " is occupied, choose someother position\n";
                filling(board, count, player1, player2);
            }
            count++;
        }
    }
    cout << "final board: \n";
    display_board(board);
    cout << endl;
    if (occupied(board))
        cout << "the game is drawn!!\n";
    else
    {
        if (count % 2 == 0)
            cout << "player2 is the winner!!\n";
        else
            cout << "player1 is the winnner!!\n";
    }
}

bool decide(vector<char> board)
{
    vector<char> b = board;
    if (check_row(board) || check_column(board) || check_diagonal(board))
        return true;
    else
        return false;
}

bool occupied(vector<char> board)
{
    for (int i = 1; i < 10; i++)
    {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

bool check_vacancy(vector<char> board, int i)
{
    if (board[i] == ' ')
        return true;
    else
        return false;
}

bool check_row(vector<char> board)
{
    vector<char> b = board;
    if ((b[1] == b[2] && b[2] == b[3] && b[1] != ' ') || (b[4] == b[5] && b[5] == b[6] && b[4] != ' ') || (b[7] == b[8] && b[8] == b[9] && b[7] != ' '))
        return true;
    else
        return false;
}

bool check_column(vector<char> board)
{
    vector<char> b = board;
    if ((b[1] == b[4] && b[4] == b[7] && b[1] != ' ') || (b[2] == b[5] && b[5] == b[8] && b[2] != ' ') || (b[3] == b[6] && b[6] == b[9] && b[3] != ' '))
        return true;
    else
        return false;
}

bool check_diagonal(vector<char> board)
{
    vector<char> b = board;
    if ((b[1] == b[5] && b[5] == b[9] && b[1] != ' ') || (b[3] == b[5] && b[5] == b[7]) && b[5] != ' ')
        return true;
    else
        return false;
}

void rematch()
{
    cout << "do you wish to play the game again?(Y/N): ";
    char c;
    cin >> c;
    if (c == 'Y' || c == 'y')
        main1();
    else if (c == 'N' || c == 'n')
        cout << "thankyou for playing the game!!\n";
    else
    {
        cout << "invalid response!!\n";
        rematch();
    }
}

int main()
{
    main1();
    return 0;
}
