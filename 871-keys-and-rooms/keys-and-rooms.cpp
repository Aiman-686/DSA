class Solution {
public:
    void dfs(int room, vector<vector<int>>&rooms, vector<bool>& visited){
        //we are now inside this room
        visited[room] = true;
        //check every key found inside room
        for(int key : rooms[room]){
            //If we haven't visited the room this key opens
            if(!visited[key]){
                //Go inside that room and explore it
                dfs(key, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        //visited[i] tells us whether we have entered room i
        vector<bool> visited(n, false);
        //we start with room 0, so begin exploaration there
        dfs(0, rooms, visited);
        //check whether every room has reached 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }return true;
    }
};