class Solution{
public:
     unordered_map<long long, int> prefix;
     int ans=0;
     void dfs(TreeNode* node, long long sum, int targetSum){
        //Nothing here 
        if(node == nullptr)
        return;

        //Add current node to our running sum
        sum += node->val;

        //check how many previous prefixes can make targetSum
        ans += prefix[sum - targetSum];

        //Remember this sum of our children 
        prefix[sum]++;

        //Go down 
        dfs(node->left, sum, targetSum);
        dfs(node->right, sum, targetSum);

        //we are leaving this node.
        //remove its sum so another branch cannot use it.
        prefix[sum]--;

     }
     int pathSum(TreeNode* root, int targetSum){
        //Important:
        //imaginary sum befor ethe root
        prefix[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
     }

};