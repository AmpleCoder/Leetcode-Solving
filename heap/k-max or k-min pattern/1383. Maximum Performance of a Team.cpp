/*
given two array a and b 
find max(bi*(ai+a1+a2+...ax)) such that number of ele in (a1+a2+..+ai+..+ax) is k
*/

class Solution {
public:
    const int mod=(int)1e9+7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int size=speed.size();
        priority_queue<int,vector<int>,greater<int>> minPq;
        vector<vector<int>> mapping;
        long long maxSumTillNow=0,currEff,maxEff=0;
        
        for(int i=0;i<size;i++)
        {
            mapping.push_back({efficiency[i],speed[i]});
        }
        
        sort(mapping.begin(),mapping.end());
        
        for(int i=size-1;i>=0;i--)
        {
            currEff = (mapping[i][1]+maxSumTillNow)*mapping[i][0];
            maxEff = max(maxEff,currEff);
            
            // cout<<maxSumTillNow<<" ";
            
            if(k>1 && minPq.size()<k-1)
            {
                maxSumTillNow+=mapping[i][1];
                minPq.push(mapping[i][1]);
            }
            
            else if(k>1 && minPq.size()==k-1)
            {
                if(minPq.top()<mapping[i][1])
                {
                    maxSumTillNow-=minPq.top();
                    minPq.pop();
                    maxSumTillNow+=mapping[i][1];
                    minPq.push(mapping[i][1]);
                }
            }
        }
        
        return maxEff%mod;
    }
};