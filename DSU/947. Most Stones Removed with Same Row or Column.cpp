/*
very awesome problem actually with dfs it's easy of think of the solution but with dsu one needs to think little 
*/

//dfs approach
class Solution {
public:
    
    void dfs(vector<int> &currSet,vector<vector<bool>> &visited,vector<vector<int>> &stones)
    {
        visited[currSet[0]][currSet[1]]=1;
        for(auto &x:stones)
        {
            if(visited[x[0]][x[1]]==0)
            {
                if(x[0]==currSet[0]||x[1]==currSet[1])
                {
                    dfs(x,visited,stones);
                }
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<bool>> visited(10006,vector<bool>(10006,false));
        int island=0;
        
        for(auto &x:stones)
        {
            if(visited[x[0]][x[1]]==0)
            {
                dfs(x,visited,stones);
                island++;
            }
        }
        
        return stones.size()-island;
    }
};

//dsu approach