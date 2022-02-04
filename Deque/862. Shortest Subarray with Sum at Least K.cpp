/*
most important thing to figure out here is if at any index i sum till i = s 
then we only need to consider those index's who's sum is <= s - k 
now here s - sum >= k => that we can store prefix sum's and some data structure in which i can maintain some prefix sum's 
which can be used to tell whether there exist a sub-array {j+1,i} such that it's sum >=k or not 
if yes then my ds should contain some more prefix sum values which furthur can be candidate for my final asnwer 
and ds should be conatinaing prefix sums in increasing values otherwise ds will not be optimal to answer in linear time 
this ds is deque (monotonic)

ps : try solving more problems on deque
*/

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int size=a.size(),i,ans=INT_MAX;
        deque<int> dq;
        vector<long> prefix(size);
        
        prefix[0]=a[0];
        if(prefix[0]>=k){
            ans=1;
        }
        
        for(i=1;i<size;i++)
        {
            prefix[i]=prefix[i-1]+a[i];
            if(prefix[i]>=k){
                ans=min(ans,i+1);
            }
        }
        
        
        for(i=0;i<size;i++)
        {
            while(!dq.empty() && prefix[i]<=prefix[dq.back()]){
                dq.pop_back();
            }
            
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                // cout<<i<<" "<<dq.front()<<endl;
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            
            dq.push_back(i);
        }
        
        return ans==INT_MAX?-1:ans;
    }
};