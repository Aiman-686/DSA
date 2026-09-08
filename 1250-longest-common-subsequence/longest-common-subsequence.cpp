class Solution {
public:

    int solve(
        int i,
        int j,
        string& text1,
        string& text2,
        vector<vector<int>>& dp
    ) {

        // One string finished
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        // Already solved
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (text1[i] == text2[j]) {

            return dp[i][j] =
                1 + solve(
                    i + 1,
                    j + 1,
                    text1,
                    text2,
                    dp
                );
        }

        // Characters don't match
        return dp[i][j] = max(
            solve(i + 1, j, text1, text2, dp),
            solve(i, j + 1, text1, text2, dp)
        );
    }


    int longestCommonSubsequence(
        string text1,
        string text2
    ) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(
            0,
            0,
            text1,
            text2,
            dp
        );
    }
};