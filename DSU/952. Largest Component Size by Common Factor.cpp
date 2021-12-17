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

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        union_find DSU(100001);
        int i,j,size,ans=0;
        unordered_map<int,int> m;
        
        for(auto &x:nums)
        {
            for(i=2;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    DSU.un(x,i);
                    DSU.un(x,x/i);
                }
            }
        }
        
        for(auto &x:nums)
        {
            // ++m[DSU.root(x)];
            ans=max(ans,++m[DSU.root(x)]);
        }
        
        return ans;
    }
};