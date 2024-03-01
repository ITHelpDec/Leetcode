// post-order traversal solution O(n)
// traverse through the nodes, keeping track of the moves
// the moves we get from the differences needed to make the val_ equal to "1" (positive if it has a surplus, negative if it is lacking this much)
// return the sum of the root value with the surplus and deficiencies minus 1 (this coin does not leave the root node)

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traverse(root, moves);
        return moves;
    }
private:
    int traverse(TreeNode *root, int &moves) {
        if (!root) { return 0; }

        int left  = traverse(root->left,  moves);
        int right = traverse(root->right, moves);

        moves += std::abs(left) + std::abs(right);

        return root->val + left + right - 1;
    }
};

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
