/*
this one can be solved using bfs , dfs , union find 
it's a good task
below is the dfs solution
*/
class Solution {
public:
    double dfs(unordered_map<string,unordered_map<string,double>> graph,string &src,string &dest,unordered_set<string> &visited,double currProduct){
        if(src==dest){
            return currProduct;
        }
        
        double ans=-1;
        visited.insert(src);
        
        for(auto &ngb:graph[src]){
            string ngbStr=ngb.first;
            double weight=ngb.second;
            
            if(!visited.count(ngbStr)){
                ans =  dfs(graph,ngbStr,dest,visited,currProduct*weight);
                if(ans!=-1.0){
                    return ans;
                }
            }
        }
        
        visited.erase(src);
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        int size=values.size();
        vector<double> result;
        
        for(int i=0;i<size;i++){
            string num=equations[i][0];
            string den=equations[i][1];
            double weight=values[i];
            
            graph[num][den]=weight;
            graph[den][num]=1.0/weight;
            graph[num][num]=graph[den][den]=1.0;
        }
        
        for(auto &q:queries){
            string s1=q[0];
            string s2=q[1];
            unordered_set<string> visited;
            
            if(graph.find(s1)==graph.end() || graph.find(s2)==graph.end()){
                result.push_back(-1.0);
            }
            
            else{
                result.push_back(dfs(graph,s1,s2,visited,1.0));
            }
        }
        
        return result;
        
    }
};

/*
bfs approach
*/

class Solution {
public:
    
    double bfs(unordered_map<string,unordered_map<string,double>> &graph,string &src,string &dest,unordered_set<string> &visited,double currProduct){
        queue<pair<string,double>> q;
        q.push({src,currProduct});
        visited.insert(src);
        
        while(!q.empty()){
            auto front = q.front();
            string currStr = front.first;
            double currProd = front.second;
            q.pop();
            
            if(currStr == dest){
                return currProd;
            }
            
            for(auto &ngb:graph[currStr]){
                string ngbStr = ngb.first;
                double prod = ngb.second;
                
                if(visited.count(ngbStr)){
                    continue;
                }
                
                visited.insert(ngbStr);
                q.push({ngbStr,prod*currProd});
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        int size=values.size();
        vector<double> result;
        
        for(int i=0;i<size;i++){
            string num=equations[i][0];
            string den=equations[i][1];
            double weight=values[i];
            
            graph[num][den]=weight;
            graph[den][num]=1.0/weight;
            graph[num][num]=graph[den][den]=1.0;
        }
        
        for(auto &q:queries){
            string s1=q[0];
            string s2=q[1];
            unordered_set<string> visited;
            
            if(graph.find(s1)==graph.end() || graph.find(s2)==graph.end()){
                result.push_back(-1.0);
            }
            
            else{
                result.push_back(bfs(graph,s1,s2,visited,1.0));
            }
        }
        
        return result;
        
    }
};

/*
DSU approach
do it 
*/