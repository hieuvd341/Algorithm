#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
    int n = box.size();
    int m = box[0].size();
    vector<vector<char>> res(m, vector<char>(n, '.'));
    for(int i = n-1; i >=0; i--) {
        int k = m-1;
        for(int j = m-1; j >=0; j--){ 
            if(box[i][j] == '.'){
                continue;
            }
            if(box[i][j] == '#'){
                res[k][n-i-1] = '#';
                k--;
            }
            if(box[i][j] == '*'){
                res[j][n-i-1] = '*';
                k = j-1;
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<char>> box;
    box.push_back({'#', '#', '*', '.', '*', '.'});
    box.push_back({'#', '#', '#', '*', '.', '.'});
    box.push_back({'#', '#', '#', '.', '#', '.'});
    vector<vector<char>> res = rotateTheBox(box);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}