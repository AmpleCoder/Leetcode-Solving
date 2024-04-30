class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int findTheLongestSubstring(string s) {
        int size = s.size(), prefix = 0, result = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for(int i = 0; i < size; i++){
            char currChar = s[i];
            
            if(isVowel(currChar)){
                prefix ^= (1 << (currChar - 'a'));
            }

            if(m.find(prefix) != m.end()){
                result = max(result, i - m[prefix]);
            }

            else{
                m[prefix] = i;
            }
            
        }

        return result;
    }
};