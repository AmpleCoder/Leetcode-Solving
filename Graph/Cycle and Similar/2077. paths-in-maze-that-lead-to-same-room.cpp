/*
    approach:
        if three nodes are part of cycle of length 3 then all three connected to each other i.e har edge ke liye figure 
        out kar liya if set of nodes jo adj hein dono ke unme kitte common ele hein that's it aur har in order to avoid 
        counting repetated cycles we've ensured here ki direction jo edge ki hum rakh rhe hein i.e from small value to 
        larger value
*/

class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        unordered_map<int, unordered_set<int>> graph;
        int numOfPaths = 0;
        
        for(auto &currEdge: corridors){
            int u = currEdge[0];
            int v = currEdge[1];

            if(u < v){
                graph[u].insert(v);
            }

            else{
                graph[v].insert(u);
            }
        }

        for(auto &currEdge: corridors){
            int u = currEdge[0];
            int v = currEdge[1];

            unordered_set<int> set1 = graph[u];
            unordered_set<int> set2 = graph[v];

            for(auto &currNgb : set1){
                if(set2.find(currNgb) != set2.end()){
                    numOfPaths++;
                }
            }
        }

        return numOfPaths;
    }
};

/*
    approach:
        using dfs(prettiest approach it can be scaled to cycle of any size and we can print all the cycles via this approach as well)
*/

class Solution {
public:
    void dfs(unordered_map<int, unordered_set<int>> &graph, int currNode, int startNode, int currLength, int &numOfPaths){
        if(currLength == 3){
            if(graph[currNode].find(startNode) != graph[currNode].end()){
                numOfPaths++;
            }

            return;
        }

        for(int ngbNode: graph[currNode]){
            if(ngbNode < currNode){
                continue;
            }

            dfs(graph, ngbNode, startNode, currLength + 1, numOfPaths);
        }
    }

    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        unordered_map<int, unordered_set<int>> graph;
        int numOfPaths = 0;
        
        for(auto &currEdge: corridors){
            int u = currEdge[0];
            int v = currEdge[1];

            graph[u].insert(v);
            graph[v].insert(u);
            
        }

        for(int i = 1; i <= n; i++){
            dfs(graph, i, i, 1, numOfPaths);
        }

        return numOfPaths;
    }
};