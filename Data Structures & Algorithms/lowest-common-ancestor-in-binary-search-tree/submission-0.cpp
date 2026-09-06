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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* curr = root;
        while(true) {
            int val = curr->val;
            if(pVal > val && qVal > val) {
                curr = curr->right;
            }
            if(pVal < val && qVal < val) {
                curr = curr->left;
            }
            else {
                return curr;
            }
        }
        return NULL;
    }
};
