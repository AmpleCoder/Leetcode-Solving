/*
it's very simialr to what we did in min ele from all subarray sum
*/

class Solution {
public:
    void fillMinCounts(vector<int> &a,vector<int> &leftMinCount,vector<int> &rightMinCount){
        stack<int> left,right;
        int size=a.size(),i;
        
        for(i=0;i<size;i++){
            leftMinCount[i]=-1;
            rightMinCount[i]=size;
        }
        
        for(i=0;i<size;i++){
            while(!left.empty() && a[i]<=a[left.top()]){
                left.pop();
            }
            
            leftMinCount[i]=(left.empty()?-1:left.top());
            left.push(i);
            
            while(!right.empty() && a[i]<=a[right.top()]){
                int currIndex=right.top();
                right.pop();
                rightMinCount[currIndex]=i;
            }
            
            right.push(i);
        }
    }
    
    int maxSumMinProduct(vector<int>& a) {
        long long size=a.size(),i,currVal,maxResult=0,mod=(int)1e9+7;
        vector<long long> prefixSum(size,0);
        vector<int> leftMinIndex(size),rightMinIndex(size);
        fillMinCounts(a,leftMinIndex,rightMinIndex);
        
        prefixSum[0]=a[0];
        
        for(i=1;i<size;i++){
            prefixSum[i]=prefixSum[i-1]+a[i];
        }
        
        for(i=0;i<size;i++){
            long long leftIndex,rightIndex,sum,mod=(int)1e9+7;
            leftIndex=leftMinIndex[i];
            rightIndex=rightMinIndex[i];
            
            
            if(leftIndex!=-1 && rightIndex!=size){
                sum=prefixSum[max(rightIndex-1,0ll)]-prefixSum[leftIndex];
            }
            
            else if(leftIndex==-1 && rightIndex!=size){
                sum=prefixSum[max(rightIndex-1,0ll)];
            }
            
            else if(leftIndex!=-1 && rightIndex==size){
                sum=prefixSum[size-1]-prefixSum[leftIndex];
            }
            
            else{
                sum=prefixSum[size-1];
            }
            
            // cout<<leftIndex<<" "<<rightIndex<<" "<<sum<<endl;
            
            currVal=(a[i]*sum);
            maxResult=max(maxResult,currVal);
        }
        
        return maxResult%mod;
    }
};