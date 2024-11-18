#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
using namespace std;
void build(vector<int> &st, vector<int> a, int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(st, a, id * 2 + 1, l, mid);
    build(st, a, id * 2 + 2, mid + 1, r);

    st[id] = min(st[id * 2 + 1], st[id * 2 + 2]);
}
int query(vector<int> st, int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return INT_MAX;
    }
    if (u <= l && r <= v) {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return st[id];
    }
    int mid = (l + r) / 2;
    return min(query(st, id*2+1, l, mid, u, v), query(st, id*2 + 2, mid+1, r, u, v));
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        return 1;
    }
    int n;
    inputFile >> n;
    int tmp1;
    int tmp2;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        inputFile >> tmp1;
        a.push_back(tmp1);
    }
    vector<int> st(n * 4, 0);
    int m;
    inputFile >> m;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < m; i++)
    {
        inputFile >> tmp1;
        inputFile >> tmp2;
        pairs.push_back({tmp1, tmp2});
    }
    build(st, a, 0, 0, n - 1);
    for (int i = 0; i < 4 * n; i++)
    {
        if (st[i] == 0)
            break;
        cout << st[i] << " ";
    }
    cout << endl;
    cout << query(st, 0, 0, n-1, 1, 5);
    cout << query(st, 0, 0, n-1, 0, 9);
    cout << query(st, 0, 0, n-1, 1, 15);
    cout << query(st, 0, 0, n-1, 6, 10);
}