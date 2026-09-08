class Solution {
public:
    int solve(
        int i, 
        int j,
        string& word1,
        string& word2,
        vector<vector<int>>& dp
    ){
        //word1 finished
        if(i == word1.size()){
            return word2.size() - j;
        }

        //word2 finished
        if(j == word2.size()){
            return word1.size() - i;
        }

        //already calculated
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //same charachter: no operation needed
        if(word1[i] == word2[j]){
            return dp[i][j] =
                   solve(i + 1, j + 1, word1, word2, dp);
        }
        //different characters:
        //insert, deleteor replace
        int insert =
            solve(i, j + 1, word1, word2, dp);
        int deleteChar =
            solve(i + 1, j, word1, word2, dp);
        int replace  =
            solve(i + 1, j + 1, word1, word2, dp);
        return dp[i][j] =
            1 + min({insert, deleteChar, replace});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1, -1)
        );
        return solve(0, 0, word1, word2, dp);
    }
};