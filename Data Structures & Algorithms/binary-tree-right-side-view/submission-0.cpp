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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> Q;
        Q.push_back(root);
        bool added = true;
        int ind = 0;
        while(added) {
            added = false;
            int size = Q.size();
            TreeNode* rightMost = NULL;
            for(int i =ind;i<size;i++) {
                TreeNode* curr = Q[i];
                if(curr!= NULL) {
                    added = true;
                    rightMost = curr;
                    Q.push_back(curr->left);
                    Q.push_back(curr->right);
                }
            }
            if(rightMost != NULL) {
                result.push_back(rightMost->val);
            }
            ind += size - ind;
        }
        return result;
    }
};
