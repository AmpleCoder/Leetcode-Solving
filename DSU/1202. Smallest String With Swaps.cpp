/*
one of the best problems in DSU 
here it is simple to figure out that we need to form comp. through the input pairs 
but the most trickiest part is to figure out that how to sort each individual comp. 
and then rearrange charecters among them 
that i've done using unordered_map<int,string> where i'll be storing all the charecters which are in same component and 
first identifier is root for the comp. then sort it assign newly decreasing sorted string then what we need to do is 
fetch the last charecter and put it under right root through this at the end we'll be having lex. smallest string
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size=s.size(),u,v,i,root;
        union_find DSU(size);
        unordered_map<int,string> m;
        string str;
        
        for(auto &p:pairs)
        {
            u=p[0],v=p[1];
            DSU.un(u,v);
        }
        
        for(i=0;i<size;i++)
        {
            root=DSU.root(i);
            m[root].push_back(s[i]);
        }
        
        for(auto &x:m)
        {
            root=x.first;
            str=x.second;
            sort(str.begin(),str.end(),greater<char>());
            m[root]=str;
        }
        
        for(i=0;i<size;i++)
        {
            root=DSU.root(i);
            s[i]=m[root].back();
            m[root].pop_back();
        }
        
        return s;
    }
};