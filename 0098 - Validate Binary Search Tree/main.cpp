// recursive O(n) solution
// another challenge involving a function overload - this time we pass two pointer referring to min and max
// typical early exit for invalid node, then bounds and validity checks for min and max nodes
// finally check our left and right nodes are in the right place i.e.
// root->left is between min and root, and root->right is between root and max

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
private:
    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) { return true; }

        if (min && root->val <= min->val || max && root->val >= max->val) { return false; }

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};
