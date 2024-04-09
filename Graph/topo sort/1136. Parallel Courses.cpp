class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        int minSemRequired = 0;
        vector<int> topoSort;

        for(auto &currRelation: relations){
            int u, v;
            u = currRelation[0];
            v = currRelation[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int currQueueSize = q.size();

            for(int i = 0; i < currQueueSize; i++){
                int currNode = q.front();
                q.pop();
                topoSort.push_back(currNode);

                for(auto &next: adj[currNode]){
                    indegree[next]--;
                    if(indegree[next] == 0){
                        q.push(next);
                    }
                }
            }

            minSemRequired++;
        }

        return (topoSort.size() == n ? minSemRequired : -1);
    }
};