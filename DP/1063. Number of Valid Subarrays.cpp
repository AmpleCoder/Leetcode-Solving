/*
nice problem here we need to use nsei and via which we can fetch the info of number of subarray's starting from i 
which have a[i] as their smallest element
*/

class Solution {
public:
    
    vector<int> nsei(vector<int> &a)
    {
        int size=a.size(),i;
        vector<int> ans(size);
        stack<int> s;
        ans[size-1]=size;
        s.push(size-1);

        for(i=size-2;i>=0;i--)
        {
            while(s.size()>0 && a[i]<=a[s.top()])
            {
                s.pop();
            }

            if(s.size()==0)
            {
                ans[i]=size;
            }

            else
            {
                ans[i]=s.top();
            }

            s.push(i);
        }

        return ans;
    }
    
    int validSubarrays(vector<int>& nums) {
        vector<int> nsi = nsei(nums);
        int i,n=nsi.size(),ans=0;
        
        for(i=0;i<n;i++)
        {
            nsi[i]-=i;
            ans+=nsi[i];
        }
        
        return ans;
    }
};