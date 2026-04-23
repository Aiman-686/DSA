#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto &p : mp) {
            vector<int>& idx = p.second;
            int m = idx.size();

            vector<long long> prefix(m + 1, 0);

            // build prefix sum
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + idx[i];
            }

            // compute answer
            for (int k = 0; k < m; k++) {
                long long i = idx[k];

                long long left = i * k - prefix[k];
                long long right = (prefix[m] - prefix[k + 1]) - i * (m - k - 1);

                ans[i] = left + right;
            }
        }

        return ans;
    }
};