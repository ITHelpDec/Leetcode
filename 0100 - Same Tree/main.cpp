// recursive O(n) solution
// if either of the nodes are null, make sure they're both null
// check the left movements and right movements are identical, ...
// ...and not only are the movements identical, the values at each node pair are identical, too

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) { return p == q; }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};
