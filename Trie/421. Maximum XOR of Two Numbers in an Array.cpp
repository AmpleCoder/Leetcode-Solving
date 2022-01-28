/*
here we're using trie insertion in which we're assuming each numbers consists of size 32 bits and inserting numbers one by one 
and for a current iteration i , the trie which is formed till this point we're fetching the maxXor from trie of num[i]
which is logical like if nums[i] ki current bit is 1 then we check do we have a trie node with child[0] present or not 
if yes than we can turn ith bit on in our answer else no 

there are so many similar problem around this binary trie do try to solve them 
1)given an array find out the maximum xor subarray
*/

class Trie{
 public:
    bool isEnd;
    Trie *child[2];

    Trie(){
        this->isEnd=false;
        for(int i=0;i<2;i++)
        {
            this->child[i]=NULL;
        }
    }

    void insert(int num){
        Trie *curr=this;

        for(int i=31;i>=0;i--)
        {
            int currBit=((num>>i) & (1));
            if(curr->child[currBit]==NULL)
            {
                curr->child[currBit]=new Trie();
            }

            curr=curr->child[currBit];
        }

        curr->isEnd=true;
    }
};

class Solution {
public:
    int maxXorWithCurrTrieVal(Trie *trie,int &val)
    {
        int ans=0,i;
        Trie *curr=trie;
        
        for(i=31;i>=0;i--)
        {
            int currBit=((val>>i) & (1));
            if(curr->child[currBit ^ 1]!=NULL)
            {
                curr=curr->child[currBit ^ 1];
                ans |= (1<<i);
            }
            
            else
            {
                curr=curr->child[currBit];
            }
        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie=new Trie();
        int size=nums.size(),i,ans=0,currMaxVal;
        
        trie->insert(nums[0]);
        
        for(i=1;i<size;i++){
            currMaxVal=maxXorWithCurrTrieVal(trie,nums[i]);
            ans=max(ans,currMaxVal);
            trie->insert(nums[i]);
        }
        
        return ans;
    }
};