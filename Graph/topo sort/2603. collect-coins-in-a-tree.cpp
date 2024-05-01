/*
    approach:
        In the remaining tree(tree where we first trim starting from leafs having 0 coins and going up jab tk 0 coins hein), remove each leaf node and its parent from the tree. 
        The remaining nodes in the tree are the ones that must be visited. 
        Hence, the answer is equal to (# remaining nodes -1) * 2
*/

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int size = coins.size(), result = 0;
        unordered_map<int, unordered_set<int>> adj;

        for(auto &currEdge: edges){
            int u = currEdge[0];
            int v = currEdge[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<int> leafs;

        //trim tree from leaves jab tk coins nhi hein
        for(int i = 0; i < size; i++){
            int u = i;

            while(adj[u].size() == 1 && coins[u] == 0){
                int ngbNode = *(adj[u].begin());
                adj[ngbNode].erase(u);
                adj[u].erase(ngbNode);
                u = ngbNode;
            }

            if(adj[u].size() == 1){
                leafs.push_back(u);
            }
        }

        for(int i = 0; i < 2; i++){
            vector<int> temp;

            for(auto currLeaf: leafs){
                if(adj[currLeaf].size() != 0){
                    int ngbNode = *(adj[currLeaf].begin());
                    adj[ngbNode].erase(currLeaf);
                    adj[currLeaf].erase(ngbNode);

                    if(adj[ngbNode].size() == 1){
                        temp.push_back(ngbNode);
                    }
                }
            }   

            leafs = temp;
        }

        for(int i = 0; i < size; i++){
            result += adj[i].size();
        }
        
        return result;
    }
};