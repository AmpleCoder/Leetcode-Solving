/*
method-1) counting when we at index i we can figure out how many pairs starting from 0....(i-1) actually forming sum = target - a[i]
*/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int freq[301],i,size=arr.size(),lo,hi,mod=(int)1e9+7;
        long long ans=0;
        memset(freq,0,sizeof(freq));
        
        for(i=0;i<size;i++){
            int newTarget=target-arr[i];
            lo=0;
            hi=newTarget;
            
            while(lo<hi)
            {
                ans=(ans+freq[lo]*freq[hi]);
                ans%=mod;
                lo++;
                hi--;
            }
            
            if(lo==hi)
            {
                ans=(ans+(freq[lo]*(freq[lo]-1))/2);
                ans%=mod;
            }
            
            freq[arr[i]]++;
        }
        
        return ans;
    }
};

/*
method-2) we can store the freq of each ele of the array after that we'll iterate over the freq array 2 and check for new target 
= target-i-j and we'll  be having 3 cases (i)i==j==k (ii)i==j && j!=k (iii)i<j and j<k
try to think more with this
*/

/*
method-3) sorting wali isme aapn wahi ele a[k] ke liye figure out karenge ki how many ele are there such that a[i]+a[j]=target-a[k]
as duplicate numbers ho skte to apne ko width kobhi dhyan mei rkhna pdega
*/