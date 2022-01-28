/*
here we're using trie insertion in which we're assuming each numbers consists of size 32 bits and inserting numbers one by one 
and for a current iteration i , the trie which is formed till this point we're fetching the maxXor from trie of num[i]
which is logical like if nums[i] ki current bit is 1 then we check do we have a trie node with child[0] present or not 
if yes than we can turn ith bit on in our answer else no 

there are so many similar problem around this binary trie do try to solve them 
1)given an array find out the maximum xor subarray

note : try to think of map soltion as well (this once is little less intuitive but good to have a practice over it)
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

//using map (java solution) i'll try coding once in cpp

  public int findMaximumXOR(int[] nums) {
        int maxResult = 0; 
        int mask = 0;
        /*The maxResult is a record of the largest XOR we got so far. if it's 11100 at i = 2, it means 
        before we reach the last two bits, 11100 is the biggest XOR we have, and we're going to explore
        whether we can get another two '1's and put them into maxResult
        
        This is a greedy part, since we're looking for the largest XOR, we start 
        from the very begining, aka, the 31st postition of bits. */
        for (int i = 31; i >= 0; i--) {
            
            //The mask will grow like  100..000 , 110..000, 111..000,  then 1111...111
            //for each iteration, we only care about the left parts
            mask = mask | (1 << i);
            
            Set<Integer> set = new HashSet<>();
            for (int num : nums) {
                
/*                we only care about the left parts, for example, if i = 2, then we have
                {1100, 1000, 0100, 0000} from {1110, 1011, 0111, 0010}*/
                int leftPartOfNum = num & mask;
                set.add(leftPartOfNum);
            }
            
            // if i = 1 and before this iteration, the maxResult we have now is 1100, 
            // my wish is the maxResult will grow to 1110, so I will try to find a candidate
            // which can give me the greedyTry;
            int greedyTry = maxResult | (1 << i);
            
            for (int leftPartOfNum : set) {
                //This is the most tricky part, coming from a fact that if a ^ b = c, then a ^ c = b;
                // now we have the 'c', which is greedyTry, and we have the 'a', which is leftPartOfNum
                // If we hope the formula a ^ b = c to be valid, then we need the b, 
                // and to get b, we need a ^ c, if a ^ c exisited in our set, then we're good to go
                int anotherNum = leftPartOfNum ^ greedyTry;
                if (set.contains(anotherNum)) {
                    maxResult= greedyTry;
                    break;
                }
            }
            
            // If unfortunately, we didn't get the greedyTry, we still have our max, 
            // So after this iteration, the max will stay at 1100.
        }
        
        return maxResult;
    }