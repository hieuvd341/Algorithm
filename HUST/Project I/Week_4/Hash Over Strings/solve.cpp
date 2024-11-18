#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long compute_hash(const string& s, int m) {
    long long hash_value = 0;
    int k = s.length();
    for (int i = 0; i < k; ++i) {
        hash_value = (hash_value * 256 + s[i]) % m;
    }
    return hash_value;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> hash_codes;
    hash_codes.reserve(n); 

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        hash_codes.push_back(compute_hash(s, m));
    }

    for (long long code : hash_codes) {
        cout << code << endl;
    }

    return 0;
}
