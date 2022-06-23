class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int size=courses.size(),time=0;
        priority_queue<int> pq;
        
        for(int i=0;i<size;i++)
        {
            if(courses[i][0]+time<=courses[i][1])
            {
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }
            
            else if(!pq.empty() && pq.top()>courses[i][0])
            {
                time-=pq.top();
                pq.pop();
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }
        }
        
        return pq.size();
    }
};


class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        
        return a[1]<b[1];
    }
    
    int f(vector<vector<int>>& courses,int idx,int time,int size,vector<vector<int>> &dp)
    {
        if(idx==size)
        {
            return 0;
        }
        
        if(dp[idx][time]!=-1)
        {
            return dp[idx][time];
        }
        
        int taken=0,notTaken,localMax;
        notTaken=f(courses,idx+1,time,size,dp);
        
        if(courses[idx][0]+time<=courses[idx][1])
        {
            taken=1+f(courses,idx+1,courses[idx][0]+time,size,dp);
        }
        
        localMax=max(taken,notTaken);
        return dp[idx][time]=localMax;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int size=courses.size(),ans=0,maxTime=courses[size-1][1];
        vector<vector<int>> dp(size+1,vector<int>(maxTime+1,-1));
        
        return f(courses,0,0,size,dp);
    }
};