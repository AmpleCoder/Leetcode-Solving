/*
took hints from second best article very nice problem 
*/
class Solution {
public:
    int f(vector<vector<int>> &a,int r1,int c1,int r2,int c2,int n,int dp[50][50][50][50])
    {
        if(r1<0 || r2<0 || r1>=n || r2>=n || c1<0 || c2<0 || c1>=n || c2>=n || a[r1][c1]==-1 || a[r2][c2]==-1)
        {
            //invalid path
            return INT_MIN;
        }
        
        if(r1==n-1 && c1==n-1)
        {
            return a[r1][c1];
        }
        
        if(r2==n-1 && c2==n-1)
        {
            return a[r2][c2];
        }
        
        if(dp[r1][c1][r2][c2]!=-1)
        {
            return dp[r1][c1][r2][c2];
        }
        
        int cherries,valDR,valDD,valRR,valRD;
        if(r1==r2 && c1==c2)
        {
            cherries=a[r1][c1];
        }
        
        else
        {
            cherries=a[r1][c1]+a[r2][c2];
        }
        
        valDD=f(a,r1+1,c1,r2+1,c2,n,dp);
        valRR=f(a,r1,c1+1,r2,c2+1,n,dp);
        valRD=f(a,r1,c1+1,r2+1,c2,n,dp);
        valDR=f(a,r1+1,c1,r2,c2+1,n,dp);
        
        cherries+=max({valDD,valRR,valRD,valDR});
        return dp[r1][c1][r2][c2]=cherries;
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n=a.size();
        int dp[50][50][50][50];
        memset(dp,-1,sizeof(dp));
        
        return max(0,f(a,0,0,0,0,n,dp));
    }
};


/*
O(n^3) solution derived from above
*/
class Solution {
public:
    int f(vector<vector<int>> &a,int r1,int c1,int c2,int n,int dp[50][50][50])
    {
        int r2=c1+r1-c2;
        
        if(r1<0 || r2<0 || r1>=n || r2>=n || c1<0 || c2<0 || c1>=n || c2>=n || a[r1][c1]==-1 || a[r2][c2]==-1)
        {
            //invalid path
            return INT_MIN;
        }
        
        if(r1==n-1 && c1==n-1)
        {
            return a[r1][c1];
        }
        
        if(dp[r1][c1][c2]!=-1)
        {
            return dp[r1][c1][c2];
        }
        
        int cherries,valDR,valDD,valRR,valRD;
        if(r1==r2 && c1==c2)
        {
            cherries=a[r1][c1];
        }
        
        else
        {
            cherries=a[r1][c1]+a[r2][c2];
        }
        
        valDD=f(a,r1+1,c1,c2,n,dp);
        valRR=f(a,r1,c1+1,c2+1,n,dp);
        valRD=f(a,r1,c1+1,c2,n,dp);
        valDR=f(a,r1+1,c1,c2+1,n,dp);
        
        cherries+=max({valDD,valRR,valRD,valDR});
        return dp[r1][c1][c2]=cherries;
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n=a.size();
        int dp[50][50][50];
        memset(dp,-1,sizeof(dp));
        
        return max(0,f(a,0,0,0,n,dp));
    }
};