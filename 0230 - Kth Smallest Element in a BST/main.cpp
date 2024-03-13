// O(n) solution
// easiest way to find the kth smallest is by following a preorder traversal (dfs)
// decrement our counter (k_) for each node we pass through and return its value

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        preorder(root);
        return ksmallest_;
    }
private:
    int ksmallest_;
    int k_;

    void preorder(TreeNode *root) {
        if (root->left) { preorder(root->left); }
        
        if (k_) {
            ksmallest_ = root->val;
            --k_;
        }

        if (root->right) { preorder(root->right); }
    }
};

// i reckon there's an opportunity for an earlier exit in this implementation when k_ reaches 0 to avoid making unnecessary passes

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        preorder(root);
        return ksmallest_;
    }
private:
    int ksmallest_;
    int k_;

    void preorder(TreeNode *root) {
        if (root->left) { preorder(root->left); }

        if (!k_) { return; } 
        ksmallest_ = root->val;
        --k_;

        if (root->right) { preorder(root->right); }
    }
};

// ...or even...

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        preorder(root);
        return ksmallest_;
    }
private:
    int ksmallest_;
    int k_;

    void preorder(TreeNode *root) {
        if (root->left) { preorder(root->left); }
        
        if (k_-- == 1) {
            ksmallest_ = root->val;
            return;
        }

        if (root->right) { preorder(root->right); }
    }
};
