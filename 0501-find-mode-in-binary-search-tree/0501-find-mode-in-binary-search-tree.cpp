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
class Solution {
public:
    vector<int> ans;
    TreeNode* prev = nullptr;
    int count = 0;
    int maxCount = 0;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);
        if (prev != nullptr && prev->val == root->val)
            count++;
        else
            count = 1;
        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (count == maxCount) {
            ans.push_back(root->val);
        }
        prev = root;
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};