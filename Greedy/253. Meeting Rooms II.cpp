/*
problem is to assign min no of rooms in such a way that no interval shoudl feel the deficiency of room 
so here assigning rooms with the least staring time is more sensible 
hence we're doing that 
now for a new query we need to vacate some room now the optimal strategy is to vacate the room with least end time 
to assign a room to this query asap hence for that we're keeping track of min. end time wala query in min heap

here one thing i'm having doubt is in operator the operation which we are doing at a moment will give us the pq having 
topmost ele having max finishing time then how is it working ?
*/

#define pii pair<int,int>
#define ff first 
#define ss second

class cmp{
public:
    bool operator()(pii &a,pii &b)
    {
        // if(a.ss==b.ss)
        // {
        //     return a.ff<b.ff;
        // }
        
        return a.ss>b.ss;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<pii,vector<pii>,cmp> pq;
        sort(intervals.begin(),intervals.end());
        int i,n=intervals.size();
        pq.push({intervals[0][0],intervals[0][1]});
        pii curr;
        
        for(i=1;i<n;i++)
        {
            curr=pq.top();
            // cout<<curr.ff<<" "<<curr.ss<<endl;
            if(intervals[i][0] >= curr.ss)
            {
                pq.pop();
            }
            
            pq.push({intervals[i][0],intervals[i][1]});
        }
        
        return pq.size();
    }
};