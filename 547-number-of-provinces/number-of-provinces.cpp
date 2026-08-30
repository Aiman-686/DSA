class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& visited){
                //we have now reached this city
                visited[city]=true;
                int n=isConnected.size();
                //check every possible city
                for(int nextCity = 0; nextCity < n; nextCity++){
                    //Is nextCity connected AND not explored yet?
                    if(isConnected[city][nextCity]==1 && 
                    !visited[nextCity]){
                        //explore that city and everything connected to it
                        dfs(nextCity, isConnected, visited);

                    }
                }

             }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //Nobody has explored yet
        vector<bool> visited(n, false);
        int provinces = 0;
        //check every city
        for(int city = 0; city<n; city++){
            //If this city was never reached before,
            //If it belongs completely new province 
            if(!visited[city]){
                provinces++;
                //explore its ENTIRE province
                dfs(city, isConnected, visited);
            }
        }return provinces;
        
    }
};