
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        q_.push(root);
        bfs();
        return convertToString();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        convertToVector(data);
        return build();
    }

private:
    vector<string> data_;
    queue<TreeNode *> q_;
    const string kNull = "X";
    const char delimiter = '\n';

    void bfs() {
        while (!q_.empty()) {
            TreeNode *node = q_.front();
            q_.pop();
            if (!node) {
                data_.push_back(kNull);
            } else {
                data_.push_back(to_string(node->val));
                q_.push(node->left);
                q_.push(node->right);
            }
        }
    }

    string convertToString() {
        string result;
        for (auto &s : data_) {
            result += s + delimiter;
        }
        return result;
    }

    void convertToVector(string &data) {
        stringstream ss(data);
        data_.clear();
        string tmp;
        while (getline(ss, tmp, delimiter)) {
            data_.push_back(tmp);
        }
    }

    TreeNode *build() {
        TreeNode *root = nullptr;
        if (data_[0] != kNull)
            root = new TreeNode(stoi(data_[0]));
        queue<TreeNode *> nodes;
        nodes.push(root);
        int i = 0;
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            i++;
            if (i < data_.size() && data_[i] != kNull) {
                node->left = new TreeNode(stoi(data_[i]));
                nodes.push(node->left);
            }
            i++;
            if (i < data_.size() && data_[i] != kNull) {
                node->right = new TreeNode(stoi(data_[i]));
                nodes.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

