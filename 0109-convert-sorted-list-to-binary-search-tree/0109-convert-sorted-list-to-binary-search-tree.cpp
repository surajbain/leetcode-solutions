/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

TreeNode* build(ListNode* head, ListNode* tail) {

    if (head == tail) {
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;


    while (fast != tail && fast->next != tail) {   //  Find Middle
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode* root = new TreeNode(slow->val);  // Middle becomes root

    root->left = build(head, slow);

    root->right = build(slow->next, tail);

    return root;
}

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
        
    }
};