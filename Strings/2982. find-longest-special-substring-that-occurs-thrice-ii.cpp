/*
    approach:
        here first we find at each index what's the max length special string which we can form once we're done with that
        we figure out for each char with the how many sub-array's are possible such once that is done 
        we update that array with suffix sum (that's how we compute the exact number of sub-array for givenm length) bas uske bad sorted scene    
*/

class Solution {
public:
    int maximumLength(string s) {
        int size = s.size(), maxLen = -1;
        vector<int> dp1(size, 1);
        int dp2[26][size + 1];
        memset(dp2, 0, sizeof(dp2));

        for(int i = 1; i < size; i++){
            if(s[i] == s[i-1]){
                dp1[i] = dp1[i-1] + 1;
            }

            else{
                dp1[i] = 1;
            }
        }

        for(int i = 0; i < size; i++){
            dp2[s[i] - 'a'][dp1[i]]++;
        }

        for(int i = 0; i < 26; i++){
            int currMaxLen = -1;

            for(int j = size - 1; j >= 0; j--){
                dp2[i][j] += dp2[i][j + 1];

                if(dp2[i][j] >= 3 && currMaxLen == -1){
                    currMaxLen = j;
                    // break;
                }
            }

            maxLen = max(maxLen, currMaxLen);
        }

        // for(int i = 0; i < 26; i++){
        //     cout << i << " -> ";

        //     for(int j = 0; j <= size - 1; j++){
        //         cout << dp2[i][j] << " ";
        //     }

        //     cout << endl;
        // }

        return maxLen;
    }
};