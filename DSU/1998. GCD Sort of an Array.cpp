/*
beautiful problem 
here the main part to observe is gcd(a[i],a[j])>1 means we can swap any two ele which will lie in the same component
eg : {2 , 4 , 6 } and {3 ,9} will form the same component so these can be swappable in any possible permutation(think try dry running one 
or two examples) so what we can do is we can mainatin a copy of same array sort it then the most imp thing is we can do prime 
factorization of each ele (prob in O(logn) with some O(nloglogn) pre computation) and with each ele in the prime fac. we can 
do union of the current ele with its prime factor ex: we can take union of 6 with 2,3. after that for each ele we can check whether the 
ele at same index in the sorted array lie in the same comp. or not ex: a[i] and sorted[i] should be part of same comp. then and only 
they are swappable(think)
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
    bool gcdSort(vector<int>& nums) {
        union_find DSU(100001);
        primeFactorization pf(100001);
        long long i,j,n=nums.size();
        vector<int> sorted;
        
        for(auto &x:nums){
            sorted.push_back(x);
        }
        
        sort(sorted.begin(),sorted.end());
        
        pf.sieve();
        
        for(auto &x:nums)
        {
            vector<int> v=pf.getFactorization(x);
            for(auto &y:v)
            {
                DSU.un(y,x);
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(!DSU.find(sorted[i],nums[i]))
            {
                return false;
            }
        }
        
        return true;
    }
};