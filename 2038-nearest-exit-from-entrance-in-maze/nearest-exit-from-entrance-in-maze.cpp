class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({sr, sc});

        //mark entrance as visited 
        maze[sr][sc] = '+';

        int steps =0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();

            //process one BFS level
            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0;i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    //outside the maze
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n){
                            continue;
                        }
                        //wall or already visited 
                        if (maze[nr][nc] == '+'){
                            continue;
                        }
                        //mark visited 
                        maze[nr][nc] = '+';

                        //we reached a new cell 
                        //check whether it is an exit
                        if(nr == 0 || nr == m -1 ||
                           nc == 0 || nc == n -1){

                            return steps + 1;
                           }q.push({nr, nc});

                }
            }steps++;
        }
        return -1;
    }
};
