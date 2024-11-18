# Solution
Ta thấy điều kiện dừng của bài là khi tất cả các phần tử đều bằng nhau và bằng phần tử nhỏ nhất. Vậy chúng ta có thể hiểu đề bài theo hướng `cần bao nhiêu thao tác để giảm tất cả các phần tử về phần tử nhỏ nhất`. Nghe có vẻ cần duyệt các phần tử theo thứ tự từ bé đến lớn nên ta sắp xếp chúng lại.
Mà ta lại thấy một phần tử chỉ có thể giảm về tới giá trị `strictly smaller` của nó. Do vậy sau khi sắp xếp lại, giả sử phần tử bé nhất là `num1`, phần tử liền kề bên phải nó là `num2`. Ta có thể thấy nếu `num2` bằng `num1` thì chúng ta không cần thực hiện gì cả, ngược lại nếu `num2` lớn hơn `num1` thì ta cần đến 1 thao tác để giảm cho `num2` thành `num1`
Tương tự với `num3` liền kề `num2`. Nếu `num3` bằng `num2` thì chúng ta chỉ cần thực hiện một thao tác là có thể trở về `num1`, ngược lại nếu `num3` lớn hơn `num2` thì ta cần đến 2 thao tác để giảm `num3` thành `num1` (`num3` thành `num2` rồi thành `num1`).
Do vậy ta có lời giải:

```C++
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int up = 0;

        for(int i =1; i< nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                up ++;
            }
            ans += up;
        }
        return ans;
    }
};
```

```py
class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        ans =0
        up =0
        for i in range(1, len(nums)):
            if(nums[i] != nums[i-1]):
                up +=1
            ans += up

        return ans
```

**Đánh giá độ phức tạp**
Với nums có n phần tử
- Độ phức tạp là O(n.logn)
Sắp xếp tốn O(nlogn)
Sau khi sắp xếp, chúng ta lặp qua từng phần tử, mỗi lần tốn O(1). Như vậy vòng lặp tốn O(n)

- Chiếm bộ nhớ: O(nlogn) hoặc O(n)