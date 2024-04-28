class Solution {
public:
    class DSU{
        vector<int> parent;
    public:
        DSU(int size){
            parent.resize(size);
            for(int i = 0; i < size; i++){
                parent[i] = i;
            }
        }

        int find(int currNode){
            return (currNode == parent[currNode] ? currNode : parent[currNode] = find(parent[currNode]));
        }

        void connect(int node1, int node2){
            parent[find(node1)] = parent[find(node2)];
        }
    };

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU friendsDsu(n);
        vector<bool> result;

        for(auto &currReq: requests){
            int u = currReq[0];
            int v = currReq[1];

            int parU = friendsDsu.find(u);
            int parV = friendsDsu.find(v);

            if(parU == parV){
                result.push_back(true);
            }

            else{
                bool canBeFrinds = true;
                //we'll check if any pair is there in the restriction which is restricting us to make this pair friend
                for(auto &currRest: restrictions){
                    int resU = currRest[0];
                    int resV = currRest[1];
                    int parResU = friendsDsu.find(resU);
                    int parResV = friendsDsu.find(resV);

                    if((parResU == parU && parResV == parV) || (parResU == parV && parResV == parU)){
                        canBeFrinds = false;
                        break;
                    }
                }

                if(canBeFrinds){
                    result.push_back(true);
                    friendsDsu.connect(u, v);
                }

                else{
                    result.push_back(false);
                }
            }
        }

        return result;
    }
};