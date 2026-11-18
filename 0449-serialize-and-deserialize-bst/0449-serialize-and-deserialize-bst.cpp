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
    void preorder(TreeNode* root, string &s) {
        if (!root) return;

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }
    TreeNode* build(vector<int>& nums, int &i,
                    long long lower, long long upper) {

        if (i >= nums.size()) return NULL;

        int val = nums[i];

        if (val <= lower || val >= upper)
            return NULL;

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = build(nums, i, lower, val);
        root->right = build(nums, i, val, upper);

        return root;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<int> nums;
        stringstream ss(data);
        string temp;

        while (getline(ss, temp, ',')) {
            if (!temp.empty())
                nums.push_back(stoi(temp));
        }
        int i = 0;
        return build(nums, i, LLONG_MIN, LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;