/*
similar to 421 just we need to process queries offline just because of limit constraint and rest is pretty simple 
here time complexity :- O(nlogn)+O(mlogm)+O(m+n)
follow up :
1)how to solve for online query here 
*/

class node{
public:
    int ind;
    int val;
    int m;
};

class Trie{
public:
    Trie *child[2];
    Trie(){
        for(int i=0;i<2;i++){
            this->child[i]=NULL;
        }
    }
    
    void insert(int num){
        Trie *curr=this;
        
        for(int i=31;i>=0;i--){
            int currBit=(num>>i) & 1;
            if(curr->child[currBit]==NULL){
                curr->child[currBit]=new Trie();
            }
            
            curr=curr->child[currBit];
        }
    }
    
    int maxXor(int num){
        Trie *curr=this;
        int ans=0,i;
        
        for(i=31;i>=0;i--){
            int currBit = (num>>i) & 1;
            if(curr->child[currBit ^ 1]!=NULL){
                ans |= (1<<i);
                curr=curr->child[currBit ^ 1];
            }
            
            else{
                curr=curr->child[currBit];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    bool static cmp(node &a,node &b){
        if(a.m==b.m)
        {
            return a.val<b.val;
        }
        
        return a.m<b.m;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int size=queries.size(),i,ptr=0,currM,currVal,currInd,currAns,n=nums.size();
        vector<node> nodes;
        node currNode;
        Trie *trie = new Trie();
        vector<int> maximizeXorResult(size);
        
        for(i=0;i<size;i++)
        {
            currNode.ind=i;
            currNode.val=queries[i][0];
            currNode.m=queries[i][1];
            
            nodes.push_back(currNode);
        }
        
        sort(nums.begin(),nums.end());
        sort(nodes.begin(),nodes.end(),cmp);
        
        for(i=0;i<size;i++)
        {
            currInd=nodes[i].ind;
            currM=nodes[i].m;
            currVal=nodes[i].val;
            while(ptr<n && nums[ptr] <= currM){
                trie->insert(nums[ptr]);
                ptr++;
            }
            currAns=-1;
            if(ptr>0)
                currAns=trie->maxXor(currVal);
            maximizeXorResult[currInd]=currAns;
        }
        
        return maximizeXorResult;
    }
};