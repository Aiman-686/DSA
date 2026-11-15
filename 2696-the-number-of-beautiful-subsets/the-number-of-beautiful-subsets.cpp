class Solution {
public:
    unordered_map<int, int> freq;
    int ans = 0;

    void dfs(vector<int>& nums, int idx, int k) {

        // All elements have been processed
        if (idx == nums.size()) {
            ans++;
            return;
        }

        // Choice 1: Don't include nums[idx]
        dfs(nums, idx + 1, k);

        // Choice 2: Include nums[idx]
        int x = nums[idx];

        // Check whether x-k or x+k is selected
        if (freq[x - k] == 0 && freq[x + k] == 0) {

            freq[x]++;

            dfs(nums, idx + 1, k);

            // Backtracking: undo our selection
            freq[x]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        dfs(nums, 0, k);

        // Remove the empty subset
        return ans - 1;
    }
};