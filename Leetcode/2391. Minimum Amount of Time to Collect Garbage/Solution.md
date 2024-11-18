# Solution
## My solution
Theo đề bài,
- mỗi thời điểm chỉ được một xe đi gom rác
- có 3 loại rác là `M`, `G` và `P`
- mỗi xe cần đi lần lượt từ nhà 0 đến nhà cuối cùng có rác loại đó để gom. nếu các nhà sau không có rác loại đó thì không cần đến nữa
- bài cũng cho thời gian 1 lần gom là 1min và thời gian đi từ nhà này sang nhà kia được lưu trong mảng travel

Dựa vào những dữ kiện này ta thấy ta cần
- Tìm phần tử cuối cùng trong mảng garbage có rác loại `M`
- Tìm phần tử cuối cùng trong mảng garbage có rác loại `P`
- Tìm phần tử cuối cùng trong mảng garbage có rác loại `G`
- Thời gian đi chuyển để gom hết rác loại `M`, `P`, `G` là thời gian đi từ đầu đến vị trí cuối cùng có rác loại `M`, `P`, `G`
- Thời gian gom rác các loại là như nhau nên thời gian gom rác là `1 min * (tổng số rác)`

từ đó ta có lời giải:
```c
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int garbage_size = garbage.size();
        int glass_pos = -1;
        int metal_pos = -1;
        int paper_pos = -1;

        for (int i = garbage_size - 1; i >= 0 && (glass_pos == -1 || paper_pos == -1 || metal_pos == -1); i--) {
            if (glass_pos == -1 && garbage[i].find('G') != string::npos) {
                glass_pos = i-1;
            } 
            if (paper_pos == -1 && garbage[i].find('P') != string::npos) {
                paper_pos = i-1;
            }
            if (metal_pos == -1 && garbage[i].find('M') != string::npos) {
                metal_pos = i-1;
            }
        }

        int ans = 0;

        for (int i = 0; i <= metal_pos && i < travel.size(); i++) {
            ans += travel[i];
        }

        for (int i = 0; i <= paper_pos && i < travel.size(); i++) {
            ans += travel[i];
        }

        for (int i = 0; i <= glass_pos && i < travel.size(); i++) {
            ans += travel[i];
        }

        for (const string& str : garbage) {
            ans += str.size();
        }

        return ans;
    }
};
```