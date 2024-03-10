// recursive O(n) solution, O(log(n)) space
// check the node's valid, go as far left as you can, and go as far right as you can
// (+1 to include the root node)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) { return 0; }

        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
