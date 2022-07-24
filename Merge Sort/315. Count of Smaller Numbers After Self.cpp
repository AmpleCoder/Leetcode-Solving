/*
first explaination is awesome to revisit
*/

class eleToInd{
public:
    int ele;
    int ind;
    
    eleToInd(int ele,int ind)
    {
        this->ele=ele;
        this->ind=ind;
    }
};

void mergeSort(vector<eleToInd> &v,int start,int end,vector<int> &result)
{
    if(start>=end)
    {
        return;
    }
    
    int mid=start+(end-start)/2;
    
    mergeSort(v,start,mid,result);
    mergeSort(v,mid+1,end,result);
    
    /*
     we have two array [start,....,mid] and [mid+1,....,end] now we need to merge these array's
     and we need to update the inversion count of ele on left part array as well
    */
    vector<eleToInd> merged;
    int i=start,j=mid+1,eleOnRightLessThan=0;
    
    while(i<=mid && j<=end)
    {
        if(v[i].ele > v[j].ele)
        {
            merged.push_back(v[j]);
            eleOnRightLessThan++;
            j++;
        }
        
        else
        {
            result[v[i].ind]+=eleOnRightLessThan;
            merged.push_back(v[i]);
            i++;
        }
    }
    
    while(i<=mid)
    {
        merged.push_back(v[i]);
        result[v[i].ind]+=eleOnRightLessThan;
        i++;
    }
    
    while(j<=end)
    {
        merged.push_back(v[j]);
        j++;
    }
    
    int pos=start;
    
    for(eleToInd currEle:merged)
    {
        v[pos++]=currEle;
    }
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<eleToInd> v;
        int size=nums.size();
        vector<int> result(size,0);
        
        for(int i=0;i<size;i++)
        {
            eleToInd currVal(nums[i],i);
            v.push_back(currVal);
        }
        
        mergeSort(v,0,size-1,result);
        return result;
    }
};