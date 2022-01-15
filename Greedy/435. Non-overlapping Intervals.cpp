/*
in this problem we can figure out number max number of intervals which can be formed which are not overlapping 
which will furthur give us min number of overlapping intervals to be removed to get all remaining non overlapping inteevals

to have a upper edge
also try this problem via dp + greedy from start points
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),[&](vector<int> &a,vector<int> &b) -> bool {
            if(a[1]==b[1])
            {
                return a[0]<b[0];
            }
            
            return a[1]<b[1];
        });
        
        int maxEnd=intervals[0][1],ans=1,i,n=intervals.size();
        
        for(i=1;i<n;i++)
        {
            if(intervals[i][0]<maxEnd)
            {
                continue;
            }
            
            ans++;
            maxEnd=intervals[i][1];
        }
        
        return n-ans;
    }
};