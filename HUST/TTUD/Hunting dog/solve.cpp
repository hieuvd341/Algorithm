#include <bits/stdc++.h>
using namespace std;

// Comparator for sorting the dogs
bool compareDogs(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

// Fenwick Tree functions
void update(vector<int> &fenwick, int index, int value, int size) {
    while (index <= size) {
        fenwick[index] = max(fenwick[index], value);
        index += index & -index;
    }
}

int query(const vector<int> &fenwick, int index) {
    int maxValue = 0;
    while (index > 0) {
        maxValue = max(maxValue, fenwick[index]);
        index -= index & -index;
    }
    return maxValue;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<tuple<int, int, int>> dogs(n);
    set<int> intelligenceSet;

    // Input for all dogs
    for (int i = 0; i < n; ++i) {
        int weight, intelligence, utility;
        cin >> weight >> intelligence >> utility;
        dogs[i] = make_tuple(weight, intelligence, utility);
        intelligenceSet.insert(intelligence);
    }

    // Sort the dogs by weight, then by intelligence
    sort(dogs.begin(), dogs.end(), compareDogs);

    // Coordinate compression for intelligence values
    unordered_map<int, int> compressedIntelligence;
    int rank = 1;
    for (int intelligence : intelligenceSet) {
        compressedIntelligence[intelligence] = rank++;
    }

    // Apply compression to the intelligence values
    for (int i = 0; i < n; ++i) {
        get<1>(dogs[i]) = compressedIntelligence[get<1>(dogs[i])];
    }

    // Fenwick Tree to maintain maximum utility
    vector<int> fenwick(rank, 0);

    int maxUtility = 0;

    for (const auto &dog : dogs) {
        int intelligence = get<1>(dog);  // Use only intelligence
        int utility = get<2>(dog);

        // Query the maximum utility up to the current intelligence
        int currentMax = query(fenwick, intelligence - 1);

        // Update the maximum utility for the current dog
        int newUtility = currentMax + utility;
        maxUtility = max(maxUtility, newUtility);

        // Update the Fenwick Tree with the new utility
        update(fenwick, intelligence, newUtility, rank);
    }

    // Output the maximum utility
    cout << maxUtility << endl;

    return 0;
}
