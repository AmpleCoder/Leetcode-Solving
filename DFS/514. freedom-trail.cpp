/*
    approach:
        the main part here where i got stuck is to figure out the which dir to choose for current index to pick
        here the simplest way to think about that is to keep track of the prev index which we've included in 
        our solution and relative to it we can figure out the solution for the current index 
        i think that's how we solve most of dfs + dp problem where current solution depends on the prev included 
        solution configuration

    follow up:
        try to solve it via dijkstra 
*/

class Solution {
public:
    int dfs(string &key, unordered_map<char, vector<int>> &adj, map<pair<int, int>, int> &dp, int idx, int prevIdx, int &ringSize, int &keySize){
        if(idx == keySize){
            return 0;
        }

        if(dp.find({idx, prevIdx}) != dp.end()){
            return dp[{idx, prevIdx}];
        }

        int currCostClock, currCostAntiClock, minCost = INT_MAX, currCost;
        char currChar = key[idx];
        vector<int> currVec = adj[currChar];

        for(int &currIdx: currVec){
            currCostClock = abs(currIdx - prevIdx);
            currCostAntiClock = ringSize - currCostClock;
            currCost = min(currCostClock, currCostAntiClock) + dfs(key, adj, dp, idx + 1, currIdx, ringSize, keySize);
            minCost = min(minCost, currCost + 1);
        }

        return dp[{idx, prevIdx}] = minCost;
    }

    int findRotateSteps(string ring, string key) {
        map<pair<int, int>, int> dp;
        unordered_map<char, vector<int>> adj;
        int ringSize = ring.size();
        int keySize = key.size();

        for(int i = 0; i < ringSize; i++){
            adj[ring[i]].push_back(i);
        }

        return dfs(key, adj, dp, 0, 0, ringSize, keySize);
    }
};