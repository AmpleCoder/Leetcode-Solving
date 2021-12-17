/*
just similar to problem number 1202 
here i've made it complicated a bit but i hope you get the idea of the problem 
and thanks for visiting my solution :)
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size=source.size(),u,v,ans=0,i,root,sum;
        union_find DSU(size);
        vector<bool> visit(size,false);
        unordered_map<int,vector<int>> m1,m2;
        string str1,str2;
        
        for(auto &p:allowedSwaps)
        {
            u=p[0],v=p[1];
            DSU.un(u,v);
        }
        
        for(i=0;i<size;i++)
        {
            root=DSU.root(i);
            m1[root].push_back(source[i]);
            m2[root].push_back(target[i]);
        }
        
        for(auto &x:m1)
        {
            root=x.first;
            vector<int> v1=x.second;
            vector<int> v2=m2[root];
            sum=0;
            unordered_map<int,int> freq1,freq2;
            
            for(i=0;i<v1.size();i++)
            {
                freq1[v1[i]]++;
                freq2[v2[i]]++;
            }
            
            for(auto &y:freq2)
            {
                u=y.first;
                if(freq1[u]<y.second)
                {
                    ans+=(y.second-freq1[u]);
                }
            }
        }
        
        return ans;
    }
};