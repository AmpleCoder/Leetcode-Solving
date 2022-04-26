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
    int minCostConnectPoints(vector<vector<int>>& a) {
        int size=a.size(),i,j,wt;
        vector<pair<int,pair<int,int>>> adj;
        
        for(i=0;i<size;i++){
            for(j=i+1;j<size;j++){
                wt=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
                adj.push_back({wt,{i,j}});
            }
        }
        
        sort(adj.begin(),adj.end());
       
        union_find DSU(size);
        int edgeUsed=0,n=adj.size(),minWeight=0,currWeight,u,v;
        
        for(i=0; i<n && edgeUsed<size-1; i++){
            currWeight=adj[i].first;
            u=adj[i].second.first;
            v=adj[i].second.second;
            // cout<<currWeight<<" "<<u<<" "<<v<<endl;
            
            if(DSU.find(u,v)==false){
                DSU.un(u,v);
                minWeight+=currWeight;
                edgeUsed++;
            }
        }
        
//         cout<<endl;
        
//         for(i=0;i<size;i++){
//             cout<<DSU.root(i)<<" ";
//         }
        
        return minWeight;
    }
};