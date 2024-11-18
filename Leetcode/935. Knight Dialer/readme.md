<<<<<<< HEAD
# 935. Knight Dialer

## Approach 1: Top-Down Dynamic Programming

![Alt text](/img/image-2.png)

Theo hình ta thấy

| From | Can jump to |
| ---- | ----------- |
| 0    | 4,6         |
| 1    | 6,8         |
| 2    | 7,9         |
| 3    | 4,8         |
| 4    | 3,9,0       |
| 5    |             |
| 6    | 1,7,0       |
| 7    | 2,6         |
| 8    | 1,3         |
| 9    | 2,4         |

Ta thấy mặt điện thoại như một graph. Từ ô số 0 ta có thể nhảy đến 4,6, ..
Ví dụ ta đang ở ô thứ 7, và chúng ta muốn nhảy thêm 5 lần nữa. Chúng ta có thể:
- Nhảy đến ô 2 sau, sau đó nhảy tiếp 4 lần nữa
- Nhảy đến ô 6, sau đó nhảy tiếp 4 lần nữa.

Cả 2 trường hợp trên đều là các bài toán con tương tự. 
Do vậy ý tưởng của chúng ta là tạo ra một hàm `dp(remain, square)`. Nó sẽ trả về số cách mà ta hoàn thành các bước nhảy còn lại, nếu chúng ta đang ở một ô bất kì. 
trường hợp cơ sở của hàm này là: Khi `remain = 0`, chúng ra return 1
Nếu không, chúng ta tính toán giá trị `dp(remain, sqaure)`. Chúng ta phải kiểm tra mỗi khả năng mà ta có thể nhảy tới từ ô vuông đang đứng. Mỗi khi nhảy tới ô vuông mới, ta gọi hàm `dp(remain-1, nextSquare)` để tiếp tục tìm số khả năng có thể nhảy. 
Vậy câu trả lời cho vấn đề ban đầu của chúng ta là gì? Phần mô tả bài toán nói rằng chúng ta có thể đặt quân mã vào bất kỳ ô bắt đầu nào. Vì vậy, chúng ta phải coi tất cả các hình vuông là hình vuông bắt đầu. Cho một ô bắt đầu, chúng ta phải thực hiện n - 1 lần nhảy. (Vì ô đầu tiên đã tính rồi.)
Nhìn chung, câu trả lời cho bài toán là tổng dp(n - 1, bình phương) cho tất cả các giá trị của bình phương trong phạm vi [0, 9].
1 lưu ý không nhỏ lắm là trong bài này khối lượng cần tính toán lặp đi lặp lại là rất nhiều. Để giải quyết vấn đề này, ta sẽ lưu trữ kết quả cho từng trạng thái. Ở trong lời giải bên dưới là memo. Ta sẽ thấy việc này giảm khối lượng tính toán đi rất nhiều lần.

Algorithm:
1. Define an array jumps where jumps[square] contains a list of all squares that you can jump to from square
2. Define a memoized function dp(remain, square):
- If remain == 0, return 1.
- Initialize ans = 0.
- Iterate nextSquare over jumps[square]:
    - Add dp(remain - 1, nextSquare) to ans.
- Return ans.
3. Initialize ans = 0.
4. Iterate square from 0 to 9:
- Add dp(n - 1, square) to ans.
5. Return ans.

Code:
```c
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
        }
        
        return ans;
    }
};
```
![Alt text](/img/image-3.png)

## Approach 2: Bottom-Up Dynamic Programming
Cách tiếp cận này tương tự như cách tiếp cận trong bài trước. Chỉ khác là thay vì xuất phát từ `remain-1` và giảm dần tới khi về `0` thì lần này chúng ta xuất phát từ `0` và tăng dần tới `remain-1`.
Lần này, tại mỗi trạng thái `remain`, ta sẽ lưu lại số cách để đi dến trạng thái `remain` đấy. 
Algorithm:
1. Define an array jumps where jumps[square] contains a list of all squares that you can jump to from square.
2. Initialize a 2d array dp of size n * 10.
3. Set the base case: dp[0][square] = 1 for all square from 0 to 9.
4. Iterate remain from 1 until n:
- Iterate square from 1 to 9:
    - Initialize ans = 0.
    - Iterate nextSquare over jumps[square]:
        - Add dp[remain - 1][nextSquare] to ans.
    - Set dp[remain][square] = ans.
5. Initialize ans = 0.
6. Iterate square from 0 to 9:
- Add dp[n - 1][square] to ans.
7. Return ans.

Implementation:
```c
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector(10, 0));
        for (int square = 0; square < 10; square++) {
            dp[0][square] = 1;
        }

        for (int remain = 1; remain < n; remain++) {
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + dp[remain - 1][nextSquare]) % MOD;
                }

                dp[remain][square] = ans;
            }
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp[n - 1][square]) % MOD;
        }

        return ans;
    }
};
```

![Alt text](/img/image-4.png)

## Approach 3: Space-Optimized Dynamic Programming
Bạn có thể nhận thấy rằng trong quan hệ truy hồi của chúng ta theo cách tiếp cận trước đó, khi tính các giá trị trong dp[remain], chúng ta chỉ quan tâm đến các giá trị trong dp[remain - 1].
Ví dụ: giả sử chúng ta đang cố tính dp[17][2]. Các giá trị chúng tôi yêu cầu là dp[16][7] và dp[16][9]. Các giá trị trong dp[15], dp[14], dp[13], v.v. không còn cần thiết nữa.
Chúng ta có thể tận dụng nhận xét này để tiết kiệm một số không gian. Thay vì giữ n hàng có độ dài 10, chúng ta sẽ chỉ giữ hai hàng.
1. `dp` sẽ đại diện cho hàng `remain`
2. `prevDp` sẽ đại diện cho hàng `remain - 1`.

Để tính dp[square], chúng tôi lấy tổng của `prevDp[nextSquare]` cho tất cả `nextSquare` trong jumps[square].

Nhớ là bài này phải hiểu theo cách ngược lại, tức là bình thường từ 0 mới đến đc 4 và 6 thì cũng đồng nghĩa với việc từ 4 và 6 mới có thể đến được 0.
```c++
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<int> dp(10, 0);
        vector<int> prevDp(10, 1);

        for (int remain = 1; remain < n; remain++) {
            dp = vector(10, 0);
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + prevDp[nextSquare]) % MOD;
                }

                dp[square] = ans;
            }
            
            prevDp = dp;
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + prevDp[square]) % MOD;
        }

        return ans;
    }
};
```
=======
# 935. Knight Dialer

## Approach 1: Top-Down Dynamic Programming

![Alt text](/img/image-2.png)

Theo hình ta thấy

| From | Can jump to |
| ---- | ----------- |
| 0    | 4,6         |
| 1    | 6,8         |
| 2    | 7,9         |
| 3    | 4,8         |
| 4    | 3,9,0       |
| 5    |             |
| 6    | 1,7,0       |
| 7    | 2,6         |
| 8    | 1,3         |
| 9    | 2,4         |

Ta thấy mặt điện thoại như một graph. Từ ô số 0 ta có thể nhảy đến 4,6, ..
Ví dụ ta đang ở ô thứ 7, và chúng ta muốn nhảy thêm 5 lần nữa. Chúng ta có thể:
- Nhảy đến ô 2 sau, sau đó nhảy tiếp 4 lần nữa
- Nhảy đến ô 6, sau đó nhảy tiếp 4 lần nữa.

Cả 2 trường hợp trên đều là các bài toán con tương tự. 
Do vậy ý tưởng của chúng ta là tạo ra một hàm `dp(remain, square)`. Nó sẽ trả về số cách mà ta hoàn thành các bước nhảy còn lại, nếu chúng ta đang ở một ô bất kì. 
trường hợp cơ sở của hàm này là: Khi `remain = 0`, chúng ra return 1
Nếu không, chúng ta tính toán giá trị `dp(remain, sqaure)`. Chúng ta phải kiểm tra mỗi khả năng mà ta có thể nhảy tới từ ô vuông đang đứng. Mỗi khi nhảy tới ô vuông mới, ta gọi hàm `dp(remain-1, nextSquare)` để tiếp tục tìm số khả năng có thể nhảy. 
Vậy câu trả lời cho vấn đề ban đầu của chúng ta là gì? Phần mô tả bài toán nói rằng chúng ta có thể đặt quân mã vào bất kỳ ô bắt đầu nào. Vì vậy, chúng ta phải coi tất cả các hình vuông là hình vuông bắt đầu. Cho một ô bắt đầu, chúng ta phải thực hiện n - 1 lần nhảy. (Vì ô đầu tiên đã tính rồi.)
Nhìn chung, câu trả lời cho bài toán là tổng dp(n - 1, bình phương) cho tất cả các giá trị của bình phương trong phạm vi [0, 9].
1 lưu ý không nhỏ lắm là trong bài này khối lượng cần tính toán lặp đi lặp lại là rất nhiều. Để giải quyết vấn đề này, ta sẽ lưu trữ kết quả cho từng trạng thái. Ở trong lời giải bên dưới là memo. Ta sẽ thấy việc này giảm khối lượng tính toán đi rất nhiều lần.

Algorithm:
1. Define an array jumps where jumps[square] contains a list of all squares that you can jump to from square
2. Define a memoized function dp(remain, square):
- If remain == 0, return 1.
- Initialize ans = 0.
- Iterate nextSquare over jumps[square]:
    - Add dp(remain - 1, nextSquare) to ans.
- Return ans.
3. Initialize ans = 0.
4. Iterate square from 0 to 9:
- Add dp(n - 1, square) to ans.
5. Return ans.

Code:
```c
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
        }
        
        return ans;
    }
};
```
![Alt text](/img/image-3.png)

## Approach 2: Bottom-Up Dynamic Programming
Cách tiếp cận này tương tự như cách tiếp cận trong bài trước. Chỉ khác là thay vì xuất phát từ `remain-1` và giảm dần tới khi về `0` thì lần này chúng ta xuất phát từ `0` và tăng dần tới `remain-1`.
Lần này, tại mỗi trạng thái `remain`, ta sẽ lưu lại số cách để đi dến trạng thái `remain` đấy. 
Algorithm:
1. Define an array jumps where jumps[square] contains a list of all squares that you can jump to from square.
2. Initialize a 2d array dp of size n * 10.
3. Set the base case: dp[0][square] = 1 for all square from 0 to 9.
4. Iterate remain from 1 until n:
- Iterate square from 1 to 9:
    - Initialize ans = 0.
    - Iterate nextSquare over jumps[square]:
        - Add dp[remain - 1][nextSquare] to ans.
    - Set dp[remain][square] = ans.
5. Initialize ans = 0.
6. Iterate square from 0 to 9:
- Add dp[n - 1][square] to ans.
7. Return ans.

Implementation:
```c
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector(10, 0));
        for (int square = 0; square < 10; square++) {
            dp[0][square] = 1;
        }

        for (int remain = 1; remain < n; remain++) {
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + dp[remain - 1][nextSquare]) % MOD;
                }

                dp[remain][square] = ans;
            }
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp[n - 1][square]) % MOD;
        }

        return ans;
    }
};
```

![Alt text](/img/image-4.png)

## Approach 3: Space-Optimized Dynamic Programming
Bạn có thể nhận thấy rằng trong quan hệ truy hồi của chúng ta theo cách tiếp cận trước đó, khi tính các giá trị trong dp[remain], chúng ta chỉ quan tâm đến các giá trị trong dp[remain - 1].
Ví dụ: giả sử chúng ta đang cố tính dp[17][2]. Các giá trị chúng tôi yêu cầu là dp[16][7] và dp[16][9]. Các giá trị trong dp[15], dp[14], dp[13], v.v. không còn cần thiết nữa.
Chúng ta có thể tận dụng nhận xét này để tiết kiệm một số không gian. Thay vì giữ n hàng có độ dài 10, chúng ta sẽ chỉ giữ hai hàng.
1. `dp` sẽ đại diện cho hàng `remain`
2. `prevDp` sẽ đại diện cho hàng `remain - 1`.

Để tính dp[square], chúng tôi lấy tổng của `prevDp[nextSquare]` cho tất cả `nextSquare` trong jumps[square].

Nhớ là bài này phải hiểu theo cách ngược lại, tức là bình thường từ 0 mới đến đc 4 và 6 thì cũng đồng nghĩa với việc từ 4 và 6 mới có thể đến được 0.
```c++
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<int> dp(10, 0);
        vector<int> prevDp(10, 1);

        for (int remain = 1; remain < n; remain++) {
            dp = vector(10, 0);
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + prevDp[nextSquare]) % MOD;
                }

                dp[square] = ans;
            }
            
            prevDp = dp;
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + prevDp[square]) % MOD;
        }

        return ans;
    }
};
```
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
![Alt text](/img/image-5.png)