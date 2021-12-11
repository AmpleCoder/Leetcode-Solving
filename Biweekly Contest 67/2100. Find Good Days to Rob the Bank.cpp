/*
here we need to keep an eye on every index
we need to check whether ending at that index do we get a prefix of type a(i-x),a(i-x+1),....a(i) such that a(i-x)>=a(i-x+1)>=....>=a(i)
how to check it can be done using stack 
(edge case a[i]=2 and ele at stack :- 6 5 try thinking from here i thought of keeping prev poped ele)
we need to do similar thing in suffix as well 
and if for i pre[i]=suff[i]=1 then this is our target ele
*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int time) {
        int n=a.size(),i,prev;
        vector<bool> pre(n,false),suff(n,false);
        stack<int> s1;
        
        for(i=0;i<min(time,n);i++)
        {
            s1.push(i);
        }
        
        for(;i<n;i++)
        {
            prev=-1;
            
            while(!s1.empty() && a[i]<=a[s1.top()])
            {
                if(a[s1.top()] >= prev)
                {
                    prev=a[s1.top()];
                    s1.pop();
                }
                
                else
                {
                    break;
                }
            }
            
            if(s1.size()==0)
            {
                pre[i]=true;
            }
            
            else
            {
                if(i-s1.top()>time)
                {
                    pre[i]=true;
                }
            }
            
            s1.push(i);
        }
        
        stack<int> s2;
        
        for(i=n-1;i>max(n-time-1,0);i--)
        {
            s2.push(i);
        }
        
        for(;i>=0;i--)
        {
            prev=-1;
            
            while(!s2.empty() && a[i]<=a[s2.top()])
            {
                if(a[s2.top()] >= prev)
                {
                    prev=a[s2.top()];
                    s2.pop();
                }
                
                else
                {
                    break;
                }
            }
            
            if(s2.size()==0)
            {
                suff[i]=true;
            }
            
            else
            {
                if(s2.top()-i>time)
                {
                    suff[i]=true;
                }
            }
            
            s2.push(i);
        }
        
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(pre[i] && suff[i])
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};