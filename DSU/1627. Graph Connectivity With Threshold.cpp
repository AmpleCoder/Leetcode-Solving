/*
here first we need to understand that 
for a given number a it'll form component with 2*a,3*a,4*a... 
so we'll start with the number threshold+1 and go till n 
and form the component with there multiples later on we can simply do 
DSU.find(u,v) to figure out whether (u,v) forms the same comp. or not 
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

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        union_find DSU(n+1);
        int i,j,u,v;
        
        for(i=threshold+1;i<=n;i++)
        {
            for(j=2*i;j<=n;j+=i)
            {
                DSU.un(i,j);
            }
        }
        
        vector<bool> ans;
        
        for(auto &q:queries)
        {
            u=q[0],v=q[1];
            ans.push_back(DSU.find(u,v));
        }
        
        return ans;
    }
};