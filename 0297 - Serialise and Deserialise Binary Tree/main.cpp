// tricker question relying on BFS and stringstreams

// for the serialisation, if we encounter a nullptr during our bfs, we append a '#' in place of a value and a delimiter (',') to our result string
// otherwise, we append the node's value and the delimiter

// for the deserialisation, we use std::getline() to capture the value separated by the delimiter and follow a traditional bfs approach
// if the character is "#", we set the ->left/right node to nullptr, otherwise we create a new node with that value, and add it to the queue for processing

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) { return ""; }

        std::string answer;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if (!curr) {
                answer += "#,";
            } else {
                answer += std::to_string(curr->val) + ',';
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string &data) {
        if (data.empty()) { return nullptr; }

        std::istringstream values(data);
        std::string val;

        std::getline(values, val, ',');
        TreeNode *root = new TreeNode(std::stoi(val));

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            std::getline(values, val, ',');

            if (val == "#") {
                curr->left = nullptr;
            } else {
                TreeNode *left = new TreeNode(std::stoi(val));
                curr->left = left;
                q.push(left);
            }

            std::getline(values, val, ',');

            if (val == "#") {
                curr->right = nullptr;
            } else {
                TreeNode *right = new TreeNode(std::stoi(val));
                curr->right = right;
                q.push(right);
            }
        }

        return root;
    }
};
