/*
two beautiful concepts to solve this problem
1) we can buil pref[i]=from {0....i}
such that pref[i]=min cost till i to get rid of all illegal goods
how to compute it 
if(a[i]=='1') {
    then either this good can be destroyed with cost 2 + min cost to get rid of all ill. goods till (i-1) 
}

else{
    no need to destroy current good so ans for this point = ans till (i-1)
}

same for right 
and we can min(left[i]+right[i+1]) over all left and right valid indices

2)in answer suppose we have 
= some left part + some middle part + some right part 
cost(some left part)=i+1;
cost(some right part)=n-i1
here cost(some middle part)=2*count of 1 in middle part 

so we can re - write this as = left + right + 2*count of 1 + count of 0 -count of 0
                             = n + count of 1 - count of 0
hence we simply need to minimise the count of 1 - count of 0 among all subarray 
which can futhur be treated as min sum sub-array in arr where we've two types of ele. one is 1 other is -1(0 can be treated as -1)
which can be solved in a similar way as we do kadane's algo
*/

class Solution {
public:
    int minimumTime(string a) {
        int n=a.size(),i,ans=INT_MAX;
        vector<int> left(n,0),right(n,0);
        left[0]=(a[0]=='0'?0:1);
        
        for(i=1;i<n;i++)
        {
            if(a[i]=='1'){
                left[i]=min(i+1,left[i-1]+2);
            }
            
            else{
                left[i]=left[i-1];
            }
        }
        
        right[n-1]=(a[n-1]=='0'?0:1);
        
        for(i=n-2;i>=0;i--){
            if(a[i]=='1'){
                right[i]=min(n-i,2+right[i+1]);
            }
            
            else{
                right[i]=right[i+1];
            }
        }
        
        for(i=0;i<n-1;i++){
            ans=min(ans,left[i]+right[i+1]);
        }
        
        ans=min({ans,left[n-1],right[0]});
        
        return ans;
    }
};