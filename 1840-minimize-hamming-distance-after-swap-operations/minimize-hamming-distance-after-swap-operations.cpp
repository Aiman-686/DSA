#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Union operations
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;

        // Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // Count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // Match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};