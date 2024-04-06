/*
    idea :- https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/solutions/1646594/left-to-right-and-right-to-left/
*/

class Solution {
public:
    bool canBeValid(string str, string locked) {
        int size = str.size(), totalUnlocked = 0, balance = 0;

        if(size % 2 == 1){
            return false;
        }

        //travel from left to right
        for(int i = 0; i < size; i++){
            if(locked[i] == '0'){
                totalUnlocked++;
            }

            else{
                if(str[i] == '('){
                    balance++;
                }

                else{
                    balance--;
                }
            }

            if(balance + totalUnlocked < 0){
                return false;
            }
        }

        if(balance > totalUnlocked){
            return false;
        }

        balance = totalUnlocked = 0;

        for(int i = size - 1; i >= 0; i--){
            if(locked[i] == '0'){
                totalUnlocked++;
            }

            else{
                if(str[i] == ')'){
                    balance++;
                }

                else{
                    balance--;
                }
            }

            if(balance + totalUnlocked < 0){
                return false;
            }
        }

        if(balance > totalUnlocked){
            return false;
        }

        return true;
    }
};