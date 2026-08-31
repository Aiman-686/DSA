class Solution {
public:
double dfs(
        string current,
        string target,
        unordered_map<string, vector<pair<string, double>>>& graph,
        unordered_set<string>& visited
    ){
        if(current == target){
            return 1.0;
        }
        visited.insert(current);
        for (auto& [neighbour, weight] : graph[current]){
            if(visited.count(neighbour))
             continue;
             double result = dfs(
                neighbour,
                target,
                graph,
                visited
             );
             if (result != -1.0)
              return weight * result;
        }return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        //build graph
        for (int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];

            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0/value});
        }
        vector<double> answer;
        //answer every query
        for(auto& query : queries){
            string start = query[0];
            string target = query[1];
            if (!graph.count(start) || !graph.count(target)){
                answer.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double result = dfs(
                start,
                target,
                graph,
                visited
            );
            answer.push_back(result);
        }return answer;
    }
};