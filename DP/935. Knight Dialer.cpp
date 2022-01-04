/*
simple casework
time complexity :- O(n) and O(n) space 
using iterative space can be reduced to O(1)

to reduce time complexity we can use matrix exponentiation 
how?we can create a 10*10 matrix with M[i][j]=1 (if i and j are connected) and ans=[1,1,1,1,1,1,1,1,1,1]*(M^(n-1))
think more and try to imlement 

https://medium.com/hackernoon/google-interview-questions-deconstructed-the-knights-dialer-f780d516f029
*/

#define ll long long
class Solution {
public:
    int mod=(int)1e9+7;
    
    ll dfs(vector<vector<ll>> &dp,int i,int n)
    {
        if(n==1)    return 1;
        ll ans=0;
        
        if(dp[i][n]!=-1)    
        {
            return dp[i][n];
        }
        
        switch(i)
        {
                //1-2,2-2,3-2,4-3,6-3,7-2,8-2,9-2,0-2
            case 0:
                ans=dfs(dp,4,n-1)+dfs(dp,6,n-1);
                break;
                
            case 1:
                ans=dfs(dp,8,n-1)+dfs(dp,6,n-1);
                break;
                
            case 2:
                ans=dfs(dp,7,n-1)+dfs(dp,9,n-1);
                break;
             
            case 3:
                ans=dfs(dp,8,n-1)+dfs(dp,4,n-1);
                break;
            
            case 4:
                ans=dfs(dp,3,n-1)+dfs(dp,9,n-1)+dfs(dp,0,n-1);
                break;
                
            case 5:
                ans=0;
                break;
                
            case 6:
                ans=dfs(dp,1,n-1)+dfs(dp,7,n-1)+dfs(dp,0,n-1);
                break;
            
            case 7:
                ans=dfs(dp,2,n-1)+dfs(dp,6,n-1);
                break;
                
            case 8:
                ans=dfs(dp,1,n-1)+dfs(dp,3,n-1);
                break;
                
            case 9:
                ans=dfs(dp,4,n-1)+dfs(dp,2,n-1);
                ;
        }
        
        return dp[i][n]=ans%mod;
    }
    
    int knightDialer(int n) {
        ll ans=0,i;
        vector<vector<ll>> dp(10,vector<ll>(n+1,-1));
        
        for(i=0;i<=9;i++)
        {
            ans=(ans+dfs(dp,i,n))%mod;
        }
        
        return ans;
    }
};