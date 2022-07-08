class Solution {
public:
    int f(int val,unordered_map<int,int> &valToCountMap)
    {
        if(val==1)
        {
            return 0;
        }
        
        if(valToCountMap.find(val)!=valToCountMap.end())
        {
            return valToCountMap[val];
        }
        
        int steps=0;
        
        if((val&1))
        {
            steps=1+f(3*val+1,valToCountMap);
        }
        
        else
        {
            steps=1+f(val/2,valToCountMap);
        }
        
        return valToCountMap[val]=steps;
    }
    
    bool static cmp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        
        return a.first<b.first;
    }
    
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> valToCountMap;
        valToCountMap[1]=0;
        
        vector<pair<int,int>> v;
        
        for(int i=1;i<=1000;i++)
        {
            f(i,valToCountMap);
        }
        
        for(int i=lo;i<=hi;i++)
        {
            v.push_back({valToCountMap[i],i});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        return v[k-1].second;
    }
};