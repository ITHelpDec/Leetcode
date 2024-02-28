// O(log(n)) solution, due to it being a BST
// classic binary search
// if what we're looking for is more than or equal to our current position, keep traversing right
// otherwise, move left - the successor must be current node in this case
// return the successor

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *successor = nullptr;

        while (root) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
