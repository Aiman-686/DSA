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
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node,int maxTillNow){
        if(node==nullptr)
        return 0;

        int good=0;
        if(node->val >= maxTillNow)
        good=1;

        maxTillNow = max(maxTillNow, node->val);

        return good
         +dfs(node->left, maxTillNow)
         +dfs(node->right, maxTillNow);
    }
};