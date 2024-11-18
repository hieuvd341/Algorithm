#include <iostream>
#include<cmath>
using namespace std;
int rangeBitwiseAnd(int left, int right)
{
    int high = log2(right);
    if(left < pow(2, high)) return 0;
    int res = left;
    for(int i = left+1; i <= right; i++) {
        res = res & i;
    }
    return res;
}
int main()
{
    int left = 5;
    int right = 7;
    cout << rangeBitwiseAnd(left, right);

}