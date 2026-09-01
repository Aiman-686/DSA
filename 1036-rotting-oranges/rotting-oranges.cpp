class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        //step 1: find all rotten oranges
        //and count all fresh oranges.
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        //step 2:BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();

            //process one complete minute
            while(size--){
                auto [r, c] = q.front();
                q.pop();

                //try 4 directions
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    //outside grid
                    if(nr < 0 || nr >= m ||
                       nc < 0 || nc >= n){
                        continue;
                       }
                       //only fresh oranges can rot
                       if(grid[nr][nc] != 1){
                        continue;
                       }//make it rotten 
                       grid[nr][nc] = 2;

                       //one less fresh orange
                       fresh--;

                       //this orange will spread
                       //during the next minute
                       q.push({nr, nc});
                }
            }minutes++;
        }
        //step 3: Did some fresh orange remain?
        if(fresh>0){
            return -1;
        }return minutes;
    }
};