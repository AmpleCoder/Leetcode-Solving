/*
OP sawal 
the things which is must is we need to min(sum_first-sum_last)
hence we'll try to make sum_first min possible of n elements
and sum_last max possible of n elements
hence we can make use of heap 
via which til any index i we can keep track of n min elem and sum of them 
same starting from back we can keep track of n max ele and sum of them 
after which we can iterate over pref and suff array and minimise the diff
here pref[i]=min_sum of n len sequence sum till ith position
suff[i]=max_sum of n len sequence from {i,n-1}
*/

class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        long long n=a.size(),i,mnSum=0,mxSum=0,ans=100000000000000000;
        vector<long long> pref_min(n);
        vector<long long> suff_max(n);
        priority_queue<long long> mxPq;
        priority_queue<long long,vector<long long>,greater<long long>> mnPq;
        
        for(i=0;i<n/3;i++){
            mnSum+=a[i];
            mxPq.push(a[i]);
        }
        
        pref_min[n/3-1]=mnSum;
        
        for(;i<n;i++){
            if(a[i]<mxPq.top()){
                mnSum-=mxPq.top();
                mnSum+=a[i];
                mxPq.pop();
                mxPq.push(a[i]);
            }
            
            pref_min[i]=mnSum;
        }
        
        for(i=n-1;i>=2*n/3;i--){
            mxSum+=a[i];
            mnPq.push(a[i]);
        }
        
        suff_max[2*n/3]=mxSum;
        
        for(;i>=0;i--){
            if(a[i]>mnPq.top()){
                mxSum-=mnPq.top();
                mxSum+=a[i];
                mnPq.pop();
                mnPq.push(a[i]);
            }
            
            suff_max[i]=mxSum;
        }
        
        for(i=n/3-1;i<2*n/3;i++){
            ans=min(ans,pref_min[i]-suff_max[i+1]);
        }
        
        return ans;
    }
};