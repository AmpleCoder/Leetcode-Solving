/*
just simple djikstra here i need to explore it further all trade off's and solve variations
*/

class Solution {
public:
    void djikstra(unordered_map<int,unordered_map<int,int>> &graph,vector<int> &distance,int n,int k){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,k});
        distance[k]=0;
        
        while(!pq.empty()){
            vector<int> topEle=pq.top();
            pq.pop();
            
            int currWeight=topEle[0];
            int currNode=topEle[1];
            
            for(auto &ngb:graph[currNode]){
                int ngbNode=ngb.first;
                int ngbWeight=ngb.second;
                
                if(distance[ngbNode] > distance[currNode] + ngbWeight){
                    distance[ngbNode] = distance[currNode] + ngbWeight;
                    pq.push({distance[ngbNode],ngbNode});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,unordered_map<int,int>> graph;
        vector<int> distance(n+1,INT_MAX);
        int result=INT_MIN;
        
        for(auto &currEdge:times){
            int u=currEdge[0];
            int v=currEdge[1];
            int w=currEdge[2];
            
            graph[u][v]=w;
        }
        
        djikstra(graph,distance,n,k);
        
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            
            result=max(result,distance[i]);
        }
        
        return result;
    }
};