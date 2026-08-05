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
    int maxDepth(TreeNode* root) {
        //Empty tree has depth 0
        if(root ==NULL)
        return 0;

        //Ask left subtree
        int left=maxDepth(root->left);
        //Ask right subtree
        int right=maxDepth(root->right);
        //I count myself also
        return 1+max(left,right);
    }
};