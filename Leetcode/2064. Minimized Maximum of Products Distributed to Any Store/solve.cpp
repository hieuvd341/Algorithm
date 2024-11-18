#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int n, vector<int> quantities, int mid){
    int s = quantities.size();
    int count = 0;
    int remainder;
    for(int i = 0; i < s; i++){
        remainder = quantities[i] % mid;
        count += quantities[i] / mid;
        if(remainder != 0){
            count++;
        }
    }
    if(count <= n){
        return true;
    }
    return false;
}
int minimizedMaximum(int n, vector<int> &quantities)
{
    int left = 1;
    int right = *max_element(quantities.begin(), quantities.end());
    int mid;
    while(left < right) {
        mid = left + (right - left) /2;
        if(check(n, quantities, mid)){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;

}
int main()
{
    int n = 7;
    vector<int> quantities = {15,10,10};
    cout << minimizedMaximum(n, quantities) << endl;
    return 0;
}