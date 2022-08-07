/*
number of paths in directed graph(may contain cycle) having length = n
*/

class Solution {
public:
    //a->0 , e->1 , i->2 , o->3 , u->4
    unordered_map<int,vector<int>> mapping;
    const int mod=(int)1e9+7;
    
    void buildMap()
    {
        mapping[0]={1};
        mapping[1]={0,2};
        mapping[2]={0,1,3,4};
        mapping[3]={2,4};
        mapping[4]={0};
        mapping[5]={0,1,2,3,4};
    }
    
    long long dfs(int idx,int n,long long dp[20001][6],int prev=5)
    {
        if(idx==n)
        {
            return 1;
        }
        
        if(dp[idx][prev]!=-1)
        {
            return dp[idx][prev];
        }
        
        long long ans=0;
        
        for(auto &x:mapping[prev])
        {
            ans=(ans+dfs(idx+1,n,dp,x))%mod;
        }
        
        return dp[idx][prev]=ans;
    }
    
    int countVowelPermutation(int n) {
        long long dp[20001][6];
        memset(dp,-1,sizeof(dp));
        buildMap();
        return dfs(0,n,dp);
    }
};