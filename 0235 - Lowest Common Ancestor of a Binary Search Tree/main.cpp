// O(n) solutino
// typical early exit for nullptr's
// if our current node is less than both of the other nodes, we go right recusrively - otherwise, we go left

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return nullptr; }

        int curr = root->val;

        if (curr < p->val && curr < q->val) { return lowestCommonAncestor(root->right, p, q); }
        if (curr > p->val && curr > q->val) { return lowestCommonAncestor(root->left,  p, q); }

        return root;
    }
};
