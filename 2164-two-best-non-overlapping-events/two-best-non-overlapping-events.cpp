class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        //1. sort events by starting time
        sort(events.begin(), events.end());
        //store all starting times
        vector<int> starts(n);
        for(int i=0;i<n;i++){
            starts[i] = events[i][0];
        }
        //2. build suffix maximum array
        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(
                events[i][2],
                suffixMax[i+1]
            );
        }
        int ans=0;
        //3. try every event as first event
        for(int i=0;i<n;i++){
                int end=events[i][1];
                int value=events[i][2];
                //4. find first event starting after current end
                int idx = upper_bound(
                    starts.begin(),
                    starts.end(),
                    end
                ) - starts.begin();
                //attend only th ecurrent event
                ans = max(ans, value);
                //if a valid second event exists
                if(idx < n){
                    int total = value + suffixMax[idx];
                    ans = max(ans, total);
                }
        }
        return ans;
        
    }
};