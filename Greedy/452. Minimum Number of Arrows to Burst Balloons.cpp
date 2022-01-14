/*
good questions opens up many follow 
here we need to release min number of arrows to burst all the ballons
so here we need to think greedily like if we sort each ballon on the basis of their end point 
and we target the end point of one ballon and cover all the other ballon which will get burst while bursting this ballon 
and continuing doing this till we get all ballons burst

follow up : 1) given array sorted on the basis of end point we need to modify the array such that it'll contain minimum points 
                with all required points being merged
                eg : {(1,4),(3,4),(5,8),(7,10)}
                o/p :- {(3,4),(7,8)}

            2) 435. Non-overlapping Intervals 
            3) 56. Merge Intervals
            4) 252. Meeting Rooms
            5) 253. Meeting Rooms II

try to explore more cases of this problem and other way sorting solution as well 
*/

#define pii pair<int,int>
#define ff first
#define ss second

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> &a,vector<int> &b)-> bool{
            if(a[1]==b[1])  return a[0]<b[0];
            return  a[1]<b[1];
        });
        
        int minCount=1,currEnd=points[0][1],i,n=points.size();
        
        for(i=1;i<n;i++)
        {
            if(points[i][0]<=currEnd)
            {
                continue;
            }
            
            minCount++;
            currEnd=points[i][1];
        }
        
        return minCount;
    }
};