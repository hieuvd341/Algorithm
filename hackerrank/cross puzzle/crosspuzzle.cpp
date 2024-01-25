#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

void printBoard(vector<vector<char>> puzzle)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << puzzle[i][j];
        }
        cout << endl;
    }
}

bool canPlaceVertical(vector<vector<char>> puzzle, int row, int col, string word)
{
    int i = 0;
    int c = 0;

    int len = word.length();

    if (row - 1 >= 0)
    {
        if (puzzle[row - 1][col] != '+')
        {
            if (puzzle[row - 1][col] == word[0])
            {
                i = 1;
                c = 1;
            }
            if (puzzle[row - 1][col] != word[0])
            {
                return false;
            }
        }
    }
    for (; row < 10 && i < len; row++ && i++)
    {
        if (puzzle[row][col] == '-')
        {
            c += 1;
        }
        else if (puzzle[row][col] == word[i])
        {
            c += 1;
        }
        else
        {
            break;
        }
    }

    if (c == len)
    {
        return true;
    }
    return false;
}

bool canPlaceHorizontal(vector<vector<char>> puzzle, int row, int col, string word)
{
    int i = 0;
    int c = 0;
    int len = word.length();
    if (col - 1 >= 0)
    {
        if (puzzle[row][col - 1] != '+')
        {
            if (puzzle[row][col - 1] == word[0])
            {
                i = 1;
                c = 1;
            }
            else if (puzzle[row][col - 1] != word[0])
            {
                return false;
            }
        }
    }
    for (; col < 10 && i < len; col++ && i++)
    {
        if (puzzle[row][col] == '-')
        {
            c += 1;
        }
        else if (puzzle[row][col] == word[i])
        {
            c += 1;
        }
        else
        {
            break;
        }
    }
    if (c == len)
    {
        return true;
    }
    return false;
}

void fillTheWordVertical(vector<vector<char>> &puzzle, int row, int col, string word)
{
    int i = 0;
    int len = word.length();
    if (row - 1 >= 0)
    {
        if (puzzle[row - 1][col] == word[0])
        {
            i = 1;
        }
    }
    for (; i < len; i++)
    {
        puzzle[row][col] = word[i];
        row += 1;
    }
}

// void fillTheWordVertical(vector<vector<char>> &puzzle, int row, int col, const string &word) {
//     int i =0;
//     int len = word.length();
//     if(row -1 >= 0) {
//         if(puzzle[row-1][col] == word[0]) {
//             i = 1;
//         }
//     }
//     for(; i < len; i++) {
//         puzzle[row][col] = word[i];
//         row +=1;
//     }
// }

void fillTheWordHorizontal(vector<vector<char>> &puzzle, int row, int col, string word)
{
    int i = 0;
    int len = word.length();
    if (col - 1 >= 0)
    {
        if (puzzle[row][col - 1] == word[0])
        {
            i = 1;
        }
    }
    for (; i < len; i++)
    {
        puzzle[row][col] = word[i];
        col += 1;
    }
}

void removeTheWordVertical(vector<vector<char>> &puzzle, int row, int col, string word)
{
    int i = 0;
    int len = word.length();
    if (row - 1 >= 0)
    {
        if (puzzle[row - 1][col] == word[0])
        {
            i = 1;
        }
    }
    for (; i < len; i++)
    {
        puzzle[row][col] = '-';
        row += 1;
    }
}

void removeTheWordHorizontal(vector<vector<char>> &puzzle, int row, int col, string word)
{
    int i = 0;
    int len = word.length();
    if (col - 1 >= 0)
    {
        if (puzzle[row][col - 1] == word[0])
        {
            i = 1;
        }
    }
    for (; i < len; i++)
    {
        puzzle[row][col] = '-';
        col += 1;
    }
}

bool solveCrossPuzzle(vector<vector<char>> &puzzle, vector<string> puzzleWords)
{
    int col = -1;
    int row = -1;
    bool isEmpty = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (puzzle[i][j] == '-')
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
            if (isEmpty)
            {
                break;
            }
        }
    }
    if (!isEmpty)
    {
        return true;
    }
    int count = 0;
    for (auto s : puzzleWords)
    {
        if (canPlaceVertical(puzzle, row, col, s))
        {
            fillTheWordVertical(puzzle, row, col, s);
            if (solveCrossPuzzle(puzzle, puzzleWords))
            {
                return true;
            }
            removeTheWordVertical(puzzle, row, col, s);
        }
        if (canPlaceHorizontal(puzzle, row, col, s))
        {
            fillTheWordHorizontal(puzzle, row, col, s);
            if (solveCrossPuzzle(puzzle, puzzleWords))
            {
                return true;
            }
            removeTheWordHorizontal(puzzle, row, col, s);
        }
    }
    return false;
}

int main()
{
    int row = 10;
    int col = 10;
    vector<vector<char>> puzzle(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> puzzle[i][j];
        }
    }
    string words;
    cin >> words;
    vector<string> puzzleWords;
    string w = "";
    for (auto i : words)
    {
        if (i == ';')
        {
            puzzleWords.push_back(w);
            w = "";
        }
        else
        {
            w += i;
        }
    }
    puzzleWords.push_back(w);
    bool success;
    success = solveCrossPuzzle(puzzle, puzzleWords);

    if (success)
    {
        printBoard(puzzle);
    }
    else
    {
        cout << "failed";
    }
    return 0;
}