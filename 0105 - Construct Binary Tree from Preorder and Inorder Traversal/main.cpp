//  recursive O(n) solution using an overload of the original function
// we use two variables to keep a track of where we are in the preorder and inorder traversals
// we also need a variable to signifiy when to stop
//
// if we go beyond the size of our preorder container we can return a nullptr
// if we encounter our stop variable as part of our inorder traversal, increment our index and return a nullptr
// beyond the early exit checks, create a new node from our preorder traversal and increment its index
//
// from there, recursively call the overloaded function on our node's left and right children nodes
// for our left node, we know we're finished when we reach root's val
// for our right node, we know we're finished when we reach "stop"
//
// one thing to bear in mind is that our pre-/in-order indices must be passed by reference

class Solution {
public:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        int p = 0, i = 0;
        return buildTree(preorder, inorder, INT_MAX, p, i);
    }
private:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder, int stop, int &p, int &i) {
        if (p >= preorder.size()) { return nullptr; }

        if (inorder[i] == stop) {
            ++i;
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[p++]);

        root->left  = buildTree(preorder, inorder, root->val, p, i);
        root->right = buildTree(preorder, inorder, stop,      p, i);

        return root;
    }
};
