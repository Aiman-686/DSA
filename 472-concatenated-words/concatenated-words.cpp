
class Solution {
public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<string> dict(words.begin(), words.end());

        vector<string> ans;

        for (string &word : words) {

            // Remove current word so it cannot use itself.
            dict.erase(word);

            int n = word.size();

            // dp[i] = can we construct word[i...n-1]?
            vector<bool> dp(n + 1, false);

            // Empty suffix is always possible.
            dp[n] = true;

            // Work backwards.
            for (int i = n - 1; i >= 0; i--) {

                // Try every possible ending position.
                for (int j = i; j < n; j++) {

                    string part = word.substr(i, j - i + 1);

                    // If this part exists and remaining suffix works.
                    if (dict.count(part) && dp[j + 1]) {

                        dp[i] = true;
                        break;
                    }
                }
            }

            if (dp[0]) {
                ans.push_back(word);
            }

            // Restore word for future targets.
            dict.insert(word);
        }

        return ans;
    }
};
