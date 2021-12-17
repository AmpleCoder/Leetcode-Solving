/*
similar to problem number 1998

the alternative good way to solve this is to iterate over all the factors of number x and do union of (factor,x) and (x/factor,x)
then we can keep track of count of root for all the numbers in a map and we can simply figure out the maximum among all
*/
#define vi vector<int>

class union_find{
    vi parent;
    vi size;
public:
    union_find(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int root(int i)
    {
        if(i == parent[i])
            return i;

        return parent[i] = root(parent[parent[i]]);//to do some small optimization
    }

    int find(int i,int j)
    {
        return root(i) == root(j);
    }    

    void un(int i,int j)
    {
        int u=root(i);
        int v=root(j);

        if(u==v)    return;

        if(size[u]>size[v]) 
            swap(u,v);

        parent[u]=v;
        size[v]+=size[u];
    }
    
    vi getSize(){
        return this->size;
    }
};

class primeFactorization{
    vi spf;
public:
    primeFactorization(int n)
    {
        int i;
        spf.resize(n);
        
        for(i=0;i<n;i++)
        {
            spf[i]=0;
        }
    }
    
    void sieve()
    {
        spf[1] = 1;

        for (int i=2; i<100001; i++)
            spf[i] = i;

        for (int i=4; i<100001; i+=2)
            spf[i] = 2;

        for (int i=3; i*i<100001; i++)
        {
            if (spf[i] == i)
            {
                for (int j=i*i; j<100001; j+=i)
                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
    }

    vector<int> getFactorization(int x)
    {
        vector<int> ret;

        while (x != 1)
        {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }

        return ret;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        union_find DSU(100001);
        primeFactorization pf(100001);
        pf.sieve();
        vector<int> adj[100001];
        int i,j,size;
        
        for(auto &x:nums)
        {
            vector<int> factors=pf.getFactorization(x);
            for(auto &y:factors)
            {
                adj[y].push_back(x);
            }
        }
        
        for(i=1;i<=100000;i++)
        {
            vi temp=adj[i];
            size=temp.size();
            
            for(j=0;j<size-1;j++)
            {
                DSU.un(temp[j],temp[j+1]);
            }
        }
        
        int ans=0;
        vi sizes = DSU.getSize();
        
        for(i=1;i<=100000;i++)
        {
            ans=max(ans,sizes[i]);
        }
        
        return ans;
    }
};