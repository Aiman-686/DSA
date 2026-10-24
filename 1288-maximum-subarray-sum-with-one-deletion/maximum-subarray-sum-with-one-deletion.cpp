
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];
        int oneDelete = 0;

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int oldNoDelete = noDelete;

            // Case 1: Don't delete anything
            noDelete = max(arr[i],
                           noDelete + arr[i]);

            // Case 2: Use exactly one deletion
            oneDelete = max(oldNoDelete,
                            oneDelete + arr[i]);

            // Best answer so far
            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};
