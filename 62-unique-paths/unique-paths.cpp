class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //starting cell
        dp[0][0] = 1;

        //calculate number of ways for every cell
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                //already initialized 
                if(i == 0 && j == 0)
                  continue;
                //way coming from above
                if( i > 0)
                  dp[i][j] += dp[i - 1][j];
                //ways coming from left
                if(j > 0)
                  dp[i][j] += dp[i][j - 1];

            }
        }return dp[m -1][n - 1];
    }
};