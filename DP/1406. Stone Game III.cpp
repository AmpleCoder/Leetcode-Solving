/*
here think like let f returns the optimal score which alice can score 
then bob's score = sum - f
and in f while it's bob's turn he'll try to minimize alice score as much as possible 
counterly alice will try to increase herscore as max as possible 

ps: do checkout lee's solution he solved in O(1) space crazy af
*/

class Solution {
public:
    
    int f(vector<int> &a,int idx,bool flag,int size,int dp[][2]){
        if(idx==size){
            return 0;
        }
        
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        
        int ans=0;
        
        if(flag==0){
            ans=f(a,idx+1,1,size,dp)+a[idx];
            
            if(idx+1<size){
                ans=max(ans,a[idx]+a[idx+1]+f(a,idx+2,1,size,dp));
            }
            
            if(idx+2<size){
                ans=max(ans,a[idx]+a[idx+1]+a[idx+2]+f(a,idx+3,1,size,dp));
            }
        }
        
        else{
            ans=f(a,idx+1,0,size,dp);
            
            if(idx+1<size){
                ans=min(ans,f(a,idx+2,0,size,dp));
            }
            
            if(idx+2<size){
                ans=min(ans,f(a,idx+3,0,size,dp));
            }
        }
        
        return dp[idx][flag]=ans;
    }
    
    string stoneGameIII(vector<int>& a) {
        int size=a.size(),ans,sum=0;
        int dp[50001][2];
        memset(dp,-1,sizeof(dp));
        ans=f(a,0,0,size,dp);
        
        for(auto &x:a){
            sum+=x;
        }
        
        // cout<<ans;
        
        if(ans==sum-ans){
            return "Tie";
        }
        
        else if(ans>sum-ans){
            return "Alice";
        }
        
        return "Bob";
    }
};