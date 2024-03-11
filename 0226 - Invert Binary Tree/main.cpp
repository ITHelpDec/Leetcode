// recurive O(n) solution
// check the node is valid, then swap our left and right children nodes (using temps orstd::swap)
// call our swap function recursively for the next nodes and carry on until we have done all of the nodes

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return root; }

        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

// using std::swap

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return root; }

        std::swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
