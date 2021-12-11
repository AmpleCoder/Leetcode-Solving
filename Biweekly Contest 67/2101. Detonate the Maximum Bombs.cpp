/*
good problem 
how i solved first i figured out all the circles for a given circle whose centre's lies on this circle 
and then formed a  directed graph with edge going from bigger circle to circles who's centre lies in this circle
after that i applied dfs(trick is using bitset(to boost up processing) and returning the size of bitset basically as 
number of bombs are less
follow up 
:- instead of bitset how would've thing were changed if we havee 10**5 bombs)
*/

class Solution {
public:
    vector<int> adj[101];
    typedef long long ll;
    
    int dfs(int node,bitset<100> &detonated)
    {
        if(detonated[node]==0)
        {
            detonated[node]=1;
            
            for(auto &ngb:adj[node])
            {
                if(detonated[ngb]==0)
                {
                    dfs(ngb,detonated);
                }
            }
        }
        
        return detonated.count();
    }
    
    int maximumDetonation(vector<vector<int>>& a) {
        long long n=a.size(),i,j,x,y,r2,dist;
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            x=a[i][0],y=a[i][1],r2=(long long)a[i][2]*a[i][2];
            
            for(j=0;j<n;j++)
            {
                dist=(a[j][0] - x)*(a[j][0] - x) + (a[j][1] - y)*(a[j][1] - y);
                if(r2 >= dist)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        for(i=0;i<n;i++)
        {
            ans=max(ans,dfs(i,bitset<100>()={}));
        }
        
        return ans;
    }
};