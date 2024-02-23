#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// int maximumWhiteTiles(vector<vector<int>> &tiles, int l)
// {
//     int s = tiles.size();
//     sort(tiles.begin(), tiles.end());
//     int ans = 0;
//     int covered = 0;
//     int j = 0;
//     int i = 0;
//     while(j < s && i < s){
//         if(l+tiles[i][0] -1>= tiles[j][1] && j < s-1) {
//             covered += tiles[j][1] - tiles[j][0] +1;
//             j++;
//         } else {
//             if(l+tiles[i][0]-1 >= tiles[j][0] && i!= s-1) {
//                 covered += l+tiles[i][0] - tiles[j][0];
//                 ans = (ans < covered ? covered : ans);
//                 covered -= tiles[i][1] - tiles[i][0] +1;
//                 covered -= l+tiles[i][0] - tiles[j][0] ;
//                 i++;
//             } else {
//                 if(i == j && i == s-1) {
//                     covered += tiles[j][1] - tiles[j][0] +1;
//                 }
//                 ans = (ans < covered ? covered : ans);
//                 covered -= tiles[i][1] - tiles[i][0] +1;
//                 i++;
//             }
//         }
//     }
//     return ans;
// }

int maximumWhiteTiles(vector<vector<int>> &tiles, int l)
{
    int i = 0, j = 0, ans = 0, cover = 0, n = tiles.size(), p;
    sort(tiles.begin(), tiles.end());
    for (i = 0; i < n && ans < l;)
    {
        if (tiles[j][0] + l > tiles[i][1])
        {
            cover += tiles[i][1] - tiles[i][0] + 1;
            ans = max(ans, cover);
            i++;
        }
        else
        {
            p = max(tiles[j][0] + l - tiles[i][0], 0);
            ans = max(ans, cover + p);
            cover -= (tiles[j][1] - tiles[j][0] + 1);
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> tiles;
    int carpetLen = 10;
    tiles.push_back({1, 5});
    tiles.push_back({10, 11});
    tiles.push_back({12, 18});
    tiles.push_back({20, 25});
    tiles.push_back({30, 32});
    // tiles.push_back({10, 11});
    // tiles.push_back({1, 1});
    cout << maximumWhiteTiles(tiles, carpetLen);
}