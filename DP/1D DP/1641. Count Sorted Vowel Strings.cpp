/*
below is the most basic solution
*/
class Solution {
public:
    int countVowelStrings(int n) {
        int ans=0;
        int dp[n][5];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<=j;k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        
        for(int i=0;i<5;i++){
            ans+=dp[n-1][i];
        }
        
        return ans;
    }
};

/*
I was majorly confused with the combination solution. This article explains the concept of combinations with repetitions, and it helps tremendously.

Following the lead from the article mentioned above, the problem asks us to pick n letters with repetition from "a, e, i, o, u" without permutation (without permutation is because the pick must be in order). Let's say n = 3, it can be

a | e | i | o | u
1 | 1 | 1 |   |
or

a | e | i | o | u
  | 2 |   | 1 |
Notice the use of | as separators between letters. If we use a generic "x" to indicate the position a letter is picked, and also give all the | separators positions as well, the two options shown above can be written as:

x | x | x | |
_ _ _ _ _ _ _
and

| x x | | x |
_ _ _ _ _ _ _
Essentially, we have transformed the problem into finding how many ways we can put three "x" in seven positions. Extending this idea further, the original question is equivalent to asking how many ways we can put n "x" in n + 5 - 1 positions (think of 5 - 1 as the number of positions for separators and n is the number of positions for "x"). The solution is simple: (n + 4) choose 4.
*/

