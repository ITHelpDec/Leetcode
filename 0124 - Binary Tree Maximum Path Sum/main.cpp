// DFS solution
// essentially, which is greater - our current max sum, or the sum of all the left and right branches including the current root node value

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs_sum(root);
        return mpsum_;
    }
private:
    int mpsum_ = std::numeric_limits<int>::min();

    int dfs_sum(TreeNode* root) {
        if (!root) { return 0; }

        int lsum = std::max(0, dfs_sum(root->left));
        int rsum = std::max(0, dfs_sum(root->right));

        mpsum_ = std::max(mpsum_, lsum + rsum + root->val);

        return root->val + std::max(lsum, rsum);
    }
};
