/*
    approach:
        one of the prettiest topo sort problem here we've to trim level by level and the last left nodes either 
        one or two(how? we can see by drawing some examples) is our answer
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }

        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> adj;
        vector<int> result;

        for(auto &currEdge: edges){
            int u = currEdge[0];
            int v = currEdge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            result.clear();

            int currSize = q.size();

            for(int i = 0; i < currSize; i++){
                int front = q.front();
                result.push_back(front);
                q.pop();

                for(auto &ngb: adj[front]){
                    indegree[ngb]--;
                    if(indegree[ngb] == 1){
                        q.push(ngb);
                    }
                }
            }
        }
        
        return result;
    }
};