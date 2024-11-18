# Solutions
## Aproach 1: Sliding window

Trước tiên chúng ta phải tìm một phần tử `target` ở bên trong mảng `nums` và làm sao tạo ra càng nhiều phần tử target này càng tốt. (dĩ nhiên là từ các phần tử nhỏ hơn target vì chúng ta chỉ có thể cộng mà thôi)
Vậy tại sao `target` lại nằm trong `nums` rồi. Có thể giải thích thế này:
- Giả sử như `target` đã ở bên trong `nums` rồi, nhưng `target - 1` và `target +1` không ở trong `nums`. Thì chắc chắn với k lần tăng ta có thể tạo ra `target` nhiều hơn so với `target + 1`
- Nếu chúng ta cố tạo ra `target +1` thì chỉ đơn giản là tăng phần tử có thể xuất hiện nhiều nhất lên 1 phần tử nữa thôi. Điều này chỉ tốn số lần tăng k chứ chả có tác dụng gì cả.


Để làm bài này ta cần đọc lí thuyết về Window Sliding technique.
Ý tưởng của chúng ta bây giờ là:
- Sắp xếp lại mảng nums. Sau khi mảng đã được sắp xếp lại, đặt phần tử đầu tiên bên trái `target` là `smaller`(phần từ lớn nhất trong `nums` nhưng còn nhỏ hơn smaller). Do `smaller` là phần tử gần nhất với `target` nên mục tiêu của chúng ta bây giờ là tăng nó bằng với `target`. Điều này sẽ tốn của chúng ta `target - smaller` lần tăng. Tiếp theo chúng ta xem xét đến `smaller2` là phần tử ở bên trái `smaller`. Phần tử này sẽ tốn của chúng ta `target - smaller2`,... Tiếp tục như vậy đến khi chúng ta hoàn thành hết k lần tính toán.
- Theo window sliding technique thì số lượng thao tác cần yêu cầu có thể được tính đơn giản theo công thức `target * (left - right) - curr`  với `curr` là tổng các phần tử từ `left` tới `right`
- Nếu như số lượng thao tác yêu cầu lớn hơn k, chúng ta phải chia nhỏ window ra. 
**Algorithm**
1. Sort `nums`
2. Initialize the following integers:
- left = 0, the left pointer.
- ans = 0, the best answer we have seen so far.
- curr = 0, the sum of the elements currently in our window.

3. Iterate right over the indices of nums:
- Consider `target = nums[right]`.
- Add `target` to `curr`.
- While the size of the window `target * (left - right) - curr` is greater than `k`:
    - Subtract `nums[left]` from `curr`.
    - Increment `left`.
- Update `ans` with the current window size if it is larger.

4. Return `ans`.

Solution:
```C++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
```

**Complexity Analysis**
Given `n` as the length of nums,
- Time complexity: `O(n.log(n))`
Despite the while loop, each iteration of the for loop is amortized `O(1)`. The while loop only runs `O(n)` times across all iterations. This is because each iteration of the while loop increments left. As left can only increase and cannot exceed n, the while loop never performs more than n iterations total. This means the sliding window process runs in `O(n)`.
- Space complexity: O(log(n)) or O(n)
We only use a few integer variables, but some space is used to sort.
The space complexity of the sorting algorithm depends on the implementation of each programming language:
  - In Java, Arrays.sort() for primitives is implemented using a variant of the Quick Sort algorithm, which has a space complexity of `O(log⁡n)`
  - In C++, the sort() function provided by STL uses a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of `O(log⁡n)`
  - In Python, the `sort()` function is implemented using the Timsort algorithm, which has a worst-case space complexity of `O(n)`

## Aproach 2: Advanced Sliding Window
Để cải thiện cách tiếp cận trên. Ta thấy ta chỉ quan tâm đến độ dài của window nhất mà không quan tâm đến window đấy là gì. Vậy ý tưởng cải tiến của chúng ta là, giả sử chúng ta tìm được một window phù hợp có độ dài len, chúng ta cần tìm cách để không cần quan tâm đến các cửa sổ có độ dài nhỏ hơn len nữa.

Mục đích của vòng lặp while trong cách tiếp cận trước là thu nhỏ cửa sổ cho đến khi nó hợp lệ trở lại. Theo cách tiếp cận này, chúng tôi sẽ không thu nhỏ cửa sổ - chúng tôi sẽ chỉ cố gắng tăng kích thước cửa sổ lên mức có thể.

Chúng ta sẽ giữ điều kiện tương tự trong vòng lặp while để kiểm tra xem window hiện tại `[left, right]` có hợp lệ hay không, nhưng thay vì sử dụng vòng lặp while, chúng ta sẽ chỉ sử dụng câu lệnh if. Điều này có nghĩa là `left` không bao giờ tăng nhiều hơn 1 mỗi lần lặp. Bởi vì `right` cũng tăng thêm 1 mỗi lần lặp, nên nếu không thể tìm thấy cửa sổ hợp lệ, chúng ta sẽ chỉ trượt một cửa sổ có kích thước tĩnh trên mảng.

Tuy nhiên, nếu chúng ta thêm phần tử `nums[right]` vào cửa sổ và cửa sổ đó hợp lệ thì câu lệnh `if` sẽ không được kích hoạt và `left` sẽ không được tăng lên. Do đó, chúng tôi sẽ tăng kích thước cửa sổ lên 1. Trong trường hợp này, điều đó có nghĩa là cửa sổ hiện tại `[left, right]` là cửa sổ tốt nhất mà chúng ta thấy cho đến nay.
Như vậy ta có thể thấy kích thước của window không thể giảm vì mỗi lần lặp sẽ tăng sang phải 1 hoặc tăng sang trái 0 hoặc 1.

Bởi vì kích thước cửa sổ của chúng tôi không thể giảm, điều đó cũng có nghĩa là kích thước của cửa sổ luôn biểu thị độ dài của cửa sổ tốt nhất mà chúng tôi đã tìm thấy cho đến nay - tương tự như ans trong cách tiếp cận trước đó.
Sau khi lặp xong thì kích thước của window là `n-left`. Và đó cũng là kết quả của chúng ta

**Algorithm**

1. Sort nums.
2. Initialize the following integers:
- left = 0, the left pointer.
- curr = 0, the sum of the elements currently in our window.
3. Iterate right over the indices of nums:
- Consider target = nums[right].
- Add target to curr.
- If the size of the window `target * (left - right) - curr` is greater than k:
    - Subtract nums[left] from curr.
    - Increment left.
4. Return nums.length - left.


**Solution**
```C++
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        
        return nums.size() - left;
    }
};
```

```py
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        curr = 0
        
        for right in range(len(nums)):
            target = nums[right]
            curr += target
            
            if (right - left + 1) * target - curr > k:
                curr -= nums[left]
                left += 1

        return len(nums) - left
```

