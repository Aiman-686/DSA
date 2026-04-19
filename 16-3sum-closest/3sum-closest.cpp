#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());   // sort array
        int n = nums.size();

        int diff = INT_MAX;               // store minimum difference
        int res_sum = 0;                  // store closest sum

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                int d = abs(target - total);

                // update closest sum
                if (d < diff) {
                    diff = d;
                    res_sum = total;
                }

                // exact match
                if (total == target) {
                    return res_sum;
                }

                // move pointers
                if (total < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res_sum;
    }
};