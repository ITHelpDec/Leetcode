// it's better to opt for a BFS solution when working through level order
// typical "create a queue, while the queue has elements - process"
// the only added complexity is extracting the values from the current nodes in the queue and adding them to our answer
// we do this by creating two temporaries - a vector to hold the values, and an integer to know when to stop processing before moving to the next level

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return answer_; }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> level;

            int n = q.size();

            for (int i = 0; i != n; ++i) {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)  { q.push(curr->left);  }
                if (curr->right) { q.push(curr->right); }

                level.emplace_back(curr->val);
            }
            
            answer_.emplace_back(level);
        }

        return answer_;
    }
private:
    std::vector<std::vector<int>> answer_;
};
