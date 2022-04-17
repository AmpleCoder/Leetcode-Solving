/*
similar to sub-array's minimum
*/

class Solution {
public:
    void fillMinCounts(vector<int> &a,vector<long long> &leftMinCount,vector<long long> &rightMinCount){
        stack<int> left,right;
        int size=a.size(),i;
        
        for(i=0;i<size;i++){
            leftMinCount[i]=i+1;
            rightMinCount[i]=size-i;
        }
        
        for(i=0;i<size;i++){
            while(!left.empty() && a[i]<a[left.top()]){
                left.pop();
            }
            
            leftMinCount[i]=(left.empty()?i+1:i-left.top());
            left.push(i);
            
            while(!right.empty() && a[i]<a[right.top()]){
                int currIndex=right.top();
                right.pop();
                rightMinCount[currIndex]=i-currIndex;
            }
            
            right.push(i);
        }
    }
    
    void fillMaxCounts(vector<int> &a,vector<long long> &leftMaxCount,vector<long long> &rightMaxCount){
        stack<int> left,right;
        int size=a.size(),i;
        
        for(i=0;i<size;i++){
            leftMaxCount[i]=i+1;
            rightMaxCount[i]=size-i;
        }
        
        for(i=0;i<size;i++){
            while(!left.empty() && a[i]>a[left.top()]){
                left.pop();
            }
            
            leftMaxCount[i]=(left.empty()?i+1:i-left.top());
            left.push(i);
            
            while(!right.empty() && a[i]>a[right.top()]){
                int currIndex=right.top();
                right.pop();
                rightMaxCount[currIndex]=i-currIndex;
            }
            
            right.push(i);
        }
    }
    
    long long subArrayRanges(vector<int>& a) {
        long long ans=0,currContribution;
        int size=a.size(),i;
        vector<long long> lMaxCount(size),rMaxCount(size),lMinCount(size),rMinCount(size);
        fillMinCounts(a,lMinCount,rMinCount);
        fillMaxCounts(a,lMaxCount,rMaxCount);
        
        for(i=0;i<size;i++){
            currContribution=(lMaxCount[i]*rMaxCount[i] - lMinCount[i]*rMinCount[i])*a[i];
            ans+=currContribution;
        }
        
        return ans;
    }
};