class Solution {
public:

    void dfs(TreeNode* node, vector<int>& leaves)
    {
        // Empty subtree
        if(node==NULL)
            return;

        // Found a leaf
        if(node->left==NULL && node->right==NULL)
            leaves.push_back(node->val);

        // Explore left subtree
        dfs(node->left,leaves);

        // Explore right subtree
        dfs(node->right,leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> first;
        vector<int> second;

        dfs(root1,first);
        dfs(root2,second);

        return first==second;
    }
};