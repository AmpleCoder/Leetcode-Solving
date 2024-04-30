class Solution {
public:
    int longestAwesome(string s) {
        int size = s.size(), result = 1, prefix = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for(int i = 0; i < size; i++){
            int currNum = s[i] - '0';
            prefix ^= (1 << currNum);

            if(m.find(prefix) != m.end()){
                result = max(result, i - m[prefix]);
            }

            else{
                m[prefix] = i;
            }

            //iterate through all possible substr having atmost one diff
            for(int j = 0; j < 10; j++){
                if(m.find((prefix ^ (1 << j))) != m.end()){
                    result = max(result, i - m[(prefix ^ (1 << j))]);
                }
            }
        }

        return result;
    }
};