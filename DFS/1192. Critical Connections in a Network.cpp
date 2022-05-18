class Solution {
public:
    int dfs(unordered_map<int,vector<int>> &graph,int node,int par,int currentRank,unordered_map<int,int> &rank,map<pair<int,int>,bool> &isPartOfCriticalConn){
        //if node is already explored
        if(rank.find(node)!=rank.end()){
            return rank[node];
        }
        
        //if not explored assign rank
        rank[node]=currentRank;
        
        int minRank=currentRank+1;
        
        //explore all the adjacents
        for(auto &ngb:graph[node]){
            //if ngb is parent ignore it else explore it
            if(ngb!=par){
                //fetch recursive rank
                int recursiveRank=dfs(graph,ngb,node,currentRank+1,rank,isPartOfCriticalConn);
                
                //now comes the most important observation if this recursive rank is <= currentRank it means this edge between ngb and node is part of cycle
                if(recursiveRank<=currentRank){
                    int u=min(ngb,node);
                    int v=max(ngb,node);
                    isPartOfCriticalConn[{min(u,v),max(u,v)}]=false;
                }
                
                //update minRank here
                minRank=min(minRank,recursiveRank);
            }
        }
        
        //return minRank
        return minRank;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ansList;
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> rank;
        map<pair<int,int>,bool> isPartOfCriticalConn;
        
        for(auto &x:connections){
            int u=x[0];
            int v=x[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            isPartOfCriticalConn[{min(u,v),max(u,v)}]=true;
        }
        
        dfs(graph,0,-1,0,rank,isPartOfCriticalConn);
        
        for(auto &x:isPartOfCriticalConn){
            int u=x.first.first;
            int v=x.first.second;
            bool canBeConn=x.second;
            
            if(canBeConn){
                ansList.push_back({u,v});
            }
            
            // cout<<u<<" "<<v<<" "<<canBeConn<<endl;
        }
        
        return ansList;
    }
};