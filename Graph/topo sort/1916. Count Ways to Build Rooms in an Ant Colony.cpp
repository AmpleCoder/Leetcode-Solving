/*
here we need to find the number of possible topo sort for a given tree 

approach 1) via dp 
            suppose root is having 2 childs 
            than dp[root]=dp[child1]*dp[child2]*(size1+size2Csize1)
            (still need to clarify on that combination part like how are we figuring that out)
            and for n branches we can generalize the formula 

approach 2) number of possible topo sort = n!/(size of size of each subtree)
(not having clear intuition so need to discuss more)

awesome concept learned : 
if given two array (1 2 3 4) and (5 6 7) we need to assign these elements in 7 holes then what is the number of ways to arrange them 
such that original order should be preserved

sol : 7C4 or 7C3 (how? just do one thing place one array's element in original order in (m+n) holes 
i.e we need to assign m holes in (m+n) holes and with this it's assured that rest n elements are going to retain their order itself
so ans = (m+n)Cm)

note : modulo inverse only exist if and only if gcd(num,power)==1 hence in most of the cases as we use 1e9+7 so 
modulo inverse always exists

ps : problems with so many learnings + need to revisit or try in mock dfs part consit of ans for subtree and size of subtree
*/

#define pii pair<long long,long long> 

class Solution {
public:
    
    long long power(long long a,int x,int mod)
    {
        long long ans=1;
        
        for(int i=x;i>0;i/=2){
            if(i&1)
            {
                ans=(ans*a)%mod;
            }
            
            a=(a*a)%mod;
        }
        
        return ans;
    }
    
    pii dfs(vector<vector<int>> &adj,vector<long long> &fact,vector<long long> &invFact,int root,int par,int mod)
    {
        long long l=0,comb=1,ans=1;
        
        for(auto &ngb:adj[root])
        {
            if(ngb==par)
            {
                continue;
            }
            
            pii curr = dfs(adj,fact,invFact,ngb,root,mod);
            long long currAns = curr.first;
            long long size = curr.second;
            
            comb = ((fact[size+l]*invFact[size])%mod)*(invFact[l])%mod;
            ans=((ans*currAns)%mod*comb)%mod;
            l+=size;
        }
        
        return {ans,l+1};
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        int size=prevRoom.size(),mod=(int)1e9+7,i;
        vector<vector<int>> adj(size);
        
        for(i=0;i<size;i++){
            int u,v;
            u=i;
            v=prevRoom[i];
            
            if(v!=-1)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        vector<long long> fact(size+1,1),invFact(size+1,1);
        
        for(i=2;i<=size;i++)
        {
            fact[i]=(i*fact[i-1])%mod;
            invFact[i]=power(fact[i],mod-2,mod);
        }
        
        pii ans;
        ans=dfs(adj,fact,invFact,0,-1,mod);
        return ans.first;
    }
};