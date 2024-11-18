<<<<<<< HEAD
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void find_start_pos(vector<string> &matrix, int &row, int &col) {
    int i, j;

	for (i = 0; i < matrix.size(); i++)
		for (j = 0; j < matrix[i].length(); j++)
			if (matrix[i][j] == 'M') {
				row = i;
				col = j;
			}
}
void find(int row, int col, vector<string>&matrix, int &count) {
    if(matrix[row][col] == '*') {
        cout << count;
        return ;
    }
    matrix[row][col] = 'X';
    if(row > 0 && matrix[row-1][col] != 'X') {
        count++;
        find(row -1, col, matrix, count);
        count --;
    }
    if(row < matrix.size()-1 && matrix[row+1][col] != 'X') {
        count ++;
        find(row+1, col, matrix, count);
        count--;
    }
    if(col > 0 && matrix[row][col - 1] != 'X') {
        count ++;
        find(row, col-1, matrix, count);
        count --;
    }
    if(col < matrix[0].length()-1 && matrix[row][col + 1] != 'X') {
        count ++;
        find(row, col+1, matrix, count);
        count --;
    }
}

void countLuck(vector<string>& matrix, int k) {
    int row, col;
    int count = 0;
    find_start_pos(matrix, row, col);
    find(row, col, matrix, count);
    // cout << count;
    // return "aaaaa";
}

int main() {
    vector<string> matrix;
    int k;
    int row, col;
    ifstream inputFile ("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    inputFile >> row >> col;
    string a;
    for(int i =0; i<row; i++) {
        inputFile >> a;
        matrix.push_back(a);
    }
    inputFile >> k;
    inputFile.close();
    // for(int i =0; i < row; i++) {
    //     cout << matrix[i] << endl;
    // }
    // int start_row;
    // int start_col;
    // find_start_pos(matrix, start_row, start_col);
    // cout << start_row << " " << start_col;

    countLuck(matrix, k);
    
=======
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void find_start_pos(vector<string> &matrix, int &row, int &col) {
    int i, j;

	for (i = 0; i < matrix.size(); i++)
		for (j = 0; j < matrix[i].length(); j++)
			if (matrix[i][j] == 'M') {
				row = i;
				col = j;
			}
}
void find(int row, int col, vector<string>&matrix, int &count) {
    if(matrix[row][col] == '*') {
        cout << count;
        return ;
    }
    matrix[row][col] = 'X';
    if(row > 0 && matrix[row-1][col] != 'X') {
        count++;
        find(row -1, col, matrix, count);
        count --;
    }
    if(row < matrix.size()-1 && matrix[row+1][col] != 'X') {
        count ++;
        find(row+1, col, matrix, count);
        count--;
    }
    if(col > 0 && matrix[row][col - 1] != 'X') {
        count ++;
        find(row, col-1, matrix, count);
        count --;
    }
    if(col < matrix[0].length()-1 && matrix[row][col + 1] != 'X') {
        count ++;
        find(row, col+1, matrix, count);
        count --;
    }
}

void countLuck(vector<string>& matrix, int k) {
    int row, col;
    int count = 0;
    find_start_pos(matrix, row, col);
    find(row, col, matrix, count);
    // cout << count;
    // return "aaaaa";
}

int main() {
    vector<string> matrix;
    int k;
    int row, col;
    ifstream inputFile ("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    inputFile >> row >> col;
    string a;
    for(int i =0; i<row; i++) {
        inputFile >> a;
        matrix.push_back(a);
    }
    inputFile >> k;
    inputFile.close();
    // for(int i =0; i < row; i++) {
    //     cout << matrix[i] << endl;
    // }
    // int start_row;
    // int start_col;
    // find_start_pos(matrix, start_row, start_col);
    // cout << start_row << " " << start_col;

    countLuck(matrix, k);
    
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}