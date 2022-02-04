/*
good problem
first think greedily 
then think why it fails when we try greedily
(in this case take ex: a={1 2 3 4 5 677 -7}  m= 4 mul={1,1,1,1}) 
1*1+1*2+1*3+1*4 = exp
1*-7+1*677+1*6+1*4 = act

ps: here check constraints and adjust size and index acco.
*/

class Solution {
public:
    
    int f(vector<int> &a,vector<int> &mul,int i,int j,int idx,int m,int n,vector<vector<int>> &dp){
        if(idx==m)
        {
            return 0;
        }
        
        if(dp[i][n-1-j]!=-1){
            return dp[i][n-1-j];
        }
        
        int val1,val2,ans;
        val1=a[i]*mul[idx]+f(a,mul,i+1,j,idx+1,m,n,dp);
        val2=a[j]*mul[idx]+f(a,mul,i,j-1,idx+1,m,n,dp);
        ans=max(val1,val2);
        return dp[i][n-1-j]=ans;
    }
    
    int maximumScore(vector<int>& a, vector<int>& mul) {
        int n=a.size(),m=mul.size(),ans;
        vector<vector<int>> dp(m,vector<int>(m,-1));
        ans=f(a,mul,0,n-1,0,m,n,dp);
        return ans;
    }
};



