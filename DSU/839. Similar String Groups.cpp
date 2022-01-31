/*
good problem on dsu but i've done this in kinda brute force manner with dsu optimization 
here i've updated the DSU classes where i've introduced comp_count which tells us the total number of diffrent components
*/

#define vi vector<int>

class Solution {
public:
    class union_find{
        vi parent;
        vi size;
        int comp_count;
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
            comp_count=n;
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
        
        int getCompCount()
        {
            return comp_count;
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
            comp_count--;
        }
    };
    
    bool isPossible(string &a,string &b)
    {
        int size=a.size(),i,count=0;
        char d1,d2,d3,d4;
        d1=d2=d3=d4='a';
        
        if(a==b)
        {
            return true;
        }
        
        for(i=0;i<size;i++)
        {
            if(a[i]==b[i])
            {
                count++;
            }
            
            else
            {
                if(d1==d2)
                {
                    d1=a[i];
                    d2=b[i];
                }
                
                else if(d3==d4)
                {
                    d3=a[i];
                    d4=b[i];
                }
            }
        }
        
        return (count==size-2 && (d1==d4 && d2==d3));
    }
    
    int numSimilarGroups(vector<string>& s) {
        int size=s.size(),i,j;
        union_find DSU(size);
        string s1,s2;
        
        for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
            {
                s1=s[i];
                s2=s[j];
                if(isPossible(s1,s2))
                {
                    // cout<<s1<<" "<<s2<<endl;
                    if(DSU.root(i) != DSU.root(j))
                    {
                        DSU.un(i,j);
                    }
                }
            }
        }
        
        return DSU.getCompCount();
    }
};