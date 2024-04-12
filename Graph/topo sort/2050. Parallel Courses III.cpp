/*
    greedy won't work here think of case like here:
        https://leetcode.com/problems/parallel-courses-iii/solutions/1816306/reason-for-10th-test-case-failure-reason-for-wrong-answer/
    
    approach:
        maintain the min time req to complete all the courses and max of it is the min time req to complete all the courses
*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);
        int minTime = INT_MIN;
        vector<int> dist(n + 1, INT_MIN);

        for(auto &currRelation: relations){
            int u = currRelation[0];
            int v = currRelation[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
                dist[i] = time[i - 1];
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: adj[u]){
                dist[v] = max(dist[v], dist[u] + time[v - 1]);
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        for(int i = 1; i <= n; i++){
            minTime = max(minTime, dist[i]);
        }

        return minTime;
    }
};