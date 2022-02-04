/*
for me it's good logical problem like what kind of question one ask's from his/her recursive funtion shape's the nature of output
here what i thouught was 
say f is giving me score obtained by alice then alice must try to maximise his chance of scoring
and if it's a bob's turn bob must minimize the diffrence between alice score(upcoming calls) with his score
*/

class Solution {
public:
    
    int f(vector<int> &a,int start,int end,bool flag,int sum,int dp[][1001][2]){
        if(start>end){
            return 0;
        }
        
        if(dp[start][end][flag]!=-1){
            return dp[start][end][flag];
        }
        
        int score;
        
        if(flag==0){
            score=max(sum-a[start]+f(a,start+1,end,1,sum-a[start],dp),
                      sum-a[end]+f(a,start,end-1,1,sum-a[end],dp));
        }
        
        else{
            score=min(f(a,start+1,end,0,sum-a[start],dp)-sum+a[start],
                      f(a,start,end-1,0,sum-a[end],dp)-sum+a[end]);
        }
        
        return dp[start][end][flag]=score;
    }
    
    int stoneGameVII(vector<int>& a) {
        int n=a.size(),sum=0,ans;
        int dp[1001][1001][2];
        memset(dp,-1,sizeof(dp));
        
        for(auto &x:a){
            sum+=x;
        }
        
        ans=f(a,0,n-1,0,sum,dp);
        return ans;
    }
};