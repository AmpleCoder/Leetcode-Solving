/*
isme apna wala solution nhi chal raha pata nhi kyu but this one is woeking i'll look into my solutiona 
*/

class Solution {
public:
    void fillLeftAndRightCount(vector<int> &a,vector<long long> &leftCount,vector<long long> &rightCount){
        int size=a.size(),i;
        stack<int> leftMin,rightMin;
        
        for(i=0;i<size;i++){
            leftCount[i]=i+1;
            rightCount[i]=size-i;
        }
        
        for(i=0;i<size;i++){
            while(!leftMin.empty() && a[leftMin.top()]>a[i]){
                leftMin.pop();
            }
            
            leftCount[i]=(leftMin.empty()?i+1:i-leftMin.top());
            
            leftMin.push(i);
            
            while(!rightMin.empty() && a[rightMin.top()]>a[i]){
                int top=rightMin.top();
                rightCount[top]=i-top;
                rightMin.pop();
            }
            
            rightMin.push(i);
        }
        
    }
    
    int sumSubarrayMins(vector<int>& a) {
        int size=a.size(),i,mod=(int)1e9+7;
        long long ans=0;
        vector<long long> leftCount(size),rightCount(size);
        fillLeftAndRightCount(a,leftCount,rightCount);
        
        for(i=0;i<size;i++){
            // cout<<leftCount[i]<<" "<<rightCount[i]<<endl;
            ans=(ans+leftCount[i]*rightCount[i]*a[i])%mod;
        }
        
        // cout<<endl;
        
        return ans;
    }
};