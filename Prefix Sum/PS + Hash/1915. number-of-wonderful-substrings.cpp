class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long size = word.size(), result = 0, prefix;
        unordered_map<long long, long long> m;
        m[0] = 1;

        for(int i = 0; i < size; i++){
            int currIndex = word[i] - 'a';
            prefix ^= (1 << currIndex);
            
            //add all even prefix found
            result += m[prefix];

            //try to mutate indexes in prefix one by one and add all possible valide substr's --> handling atmost one odd case
            for(int j = 0; j < 10; j++){
                result += m[(prefix ^ (1 << j))];
            }

            m[prefix]++;
        }

        return result;
    }
};