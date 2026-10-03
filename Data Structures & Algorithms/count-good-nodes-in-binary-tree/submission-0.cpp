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
    int goodNodes(TreeNode* root) {
        return gNodes(root, -200);
    }

    int gNodes(TreeNode* root, int currMax) {
        int gN = 0;
        if(root == NULL) {
            return 0;
        }
        if(root->val >= currMax) {
            gN++;
            currMax = root->val;
        }
        gN += gNodes(root->left, currMax) + gNodes(root->right, currMax);
        return gN;
    }
};
