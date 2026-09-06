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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> Q;
        vector<vector<int>> result;
        Q.push_back(root);
        bool added = true;
        int ind = 0;
        while(added) {
            added = false;
            int size = Q.size();
            vector<int> res;
            for(int i =ind;i<size;i++) {
                TreeNode* curr = Q[i];
                if(curr != NULL) {
                    res.push_back(curr->val);
                    Q.push_back(curr->left);
                    Q.push_back(curr->right);
                    added = true;
                }
            }
            if(added) {
                result.push_back(res);
            }
            ind += size-ind;
        } 
        return result;  
    }
};
