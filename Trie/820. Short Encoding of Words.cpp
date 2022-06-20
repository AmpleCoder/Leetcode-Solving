/*
quite intuitive solution we can insert all strings in the set later on for each and every string's substring from
i=1....sizeofStr-1 we find all the substring occuring in set and removing them that'it 
TC -> O(N*K^2) 
SC -> O(NK)

approach 2 -> we'll solve this particular problem using trie
*/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        int ans=0;
        
        for(auto &currWord:words)
        {
            for(int i=1;i<currWord.size();i++)
            {
                s.erase(currWord.substr(i));
            }
        }
        
        for(auto &x:s)
        {
            ans+=x.size()+1;
        }
        
        return ans;
    }
};