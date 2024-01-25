// Wrong but has sort map example
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>
#include<Windows.h>
using namespace std;

// bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.second < b.second;
// }

// std::vector<int> wrongSongPopularity(std::vector<std::vector<int>> song_preference, int n, int m) {
//     std::map<int, int> point;
//     for (int i = 0; i < n; i++) {
//         for (int ii = 0; ii < m; ii++) {
//             point[song_preference[i][ii]] += ii;
//         }
//     }

//     vector<pair<int, int>> pointVector(point.begin(), point.end());

//     sort(pointVector.begin(), pointVector.end(), cmp);

//     std::vector<int> res;
//     for (const auto& entry : pointVector) {
//         res.push_back(entry.first);
//     }

//     return res;
// }

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
vector<int> songPopularity(vector<vector<int>> song_preference, int n, int m) {
    vector<int> v (m, 0);
    vector<vector<int>> beats(m, v);
    int song1;
    int song2;
    for(int i =0; i<n; i++) {
        for(int j =0; j<m; j++) {
            for(int k =j+1; k <m; k++ ) {
                song1 = song_preference[i][j];
                song2 = song_preference[i][k];
                beats[song1][song2]++;
            }
        }
    }
    // for(int i =0; i<m; i++) {
    //     for(int j =0; j<m; j++) {
    //         cout << beats[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int,int>>song_ranks;
    for(int i =0; i< m; i++) {
        int popularity_score = 0;
        for(int j= 0; j <m; j++) {
            if(beats[i][j] >= (n/2)) {
                popularity_score-=1;
            }
            else if(n % 2 == 0 && beats[i][j] == (n / 2) && i < j) {
                popularity_score-=1;
            }
        }
        song_ranks.push_back(pair(popularity_score, i));
    }
    
    sort(song_ranks.begin(), song_ranks.end(), cmp);
    vector<int> res;
    for(auto song_rank : song_ranks) {
        res.push_back(song_rank.second);
    }
    return res;
}

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }

    int n, m;
    inputFile >> n;
    inputFile >> m;
    vector<vector<int>> song_preference;
    for(int i =0; i < n; i++){
        vector<int> v;
        for(int ii =0; ii <m; ii++){
            int n;
            inputFile >> n;
            v.push_back(n);
        }
        song_preference.push_back(v);
    }
    vector<int> res;
    res = songPopularity(song_preference, n, m);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}