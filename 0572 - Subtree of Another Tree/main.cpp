// recursive O(n) solution
// early checks to see if one (or both) of the pointers are null
// we will need a helper function to check whether the trees are the same
// this involves checking whether the node values are the same and recursively checking each left and right node
// finally we recursively check the left and right nodes to see if they are subtree

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) { return true;  }
        if (!root || !subRoot) { return false; }

        if (root->val == subRoot->val && isSametree(root, subRoot)) { return true; }

        return isSubtree(root->left, subRoot) || isSametree(root->right, subRoot);
    }
private:
    bool isSametree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) { return true; }
        if (!root || !subRoot) { return false; }

        return root->val == subRoot->val &&
               isSametree(root->left,  subRoot->left) &&
               isSametree(root->right, subRoot->right);
    }
};
