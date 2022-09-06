/*
good problem 
here we need to think of how the time for current position to get fixed is dependnt upon the previous positions 
*/

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeros=0,seconds=0,time=0,size=s.size();
        
        for(int i=0;i<size;i++)
        {
            if(s[i]=='0')
            {
                zeros++;
            }
            
            else
            {
                if(zeros>0)
                {
                    seconds=max(seconds+1,zeros);
                    time=max(time,seconds);
                }
            }
        }
        
        return time;
    }
};