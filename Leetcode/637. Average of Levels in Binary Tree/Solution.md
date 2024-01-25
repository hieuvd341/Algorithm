# Solution

Bài này tag Easy nên chỉ ôn lại thuật toán BFS chứ không có kĩ thuật gì đặc biệt cả.Thứ tự giải bài toán như sau:
- Xuất phát từ root. Đầu tiên ta kiểm tra xem root có tồn tại không. Nếu không thì kết thúc hàm. Nếu có thì đẩy root vào queue để thực hiện BFS
- Hàng đợi q dùng để lưu các node tại mỗi level. Sau khi lặp xong root sẽ push vào các node ở level1... và cứ như vậy tiếp tục.
- Sau khi lặp xong mỗi level sẽ tính giá trị trung bình của level này.
- Kết quả lưu vào ans.

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int levelsize=q.size();
            double sum =0;
            for(int i =0; i<levelsize; i++) {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)  {q.push(temp->left);}
                if(temp->right) {q.push(temp->right);}
                sum+=temp->val;
            }
            double avg=sum/levelsize;
            ans.push_back(avg);
        }
        return ans;
    }
};
```