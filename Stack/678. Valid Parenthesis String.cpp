class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size(), balance = 0, stars = 0;

        for(int i = 0; i < size; i++){
            if(s[i] == '('){
                balance++;
            }

            else if(s[i] == ')'){
                balance--;
            }

            else{
                stars++;
            }

            if(balance + stars < 0){
                return false;
            }
        }

        if(balance > stars){
            return false;
        }

        balance = stars = 0;

        for(int i = size - 1; i >= 0; i--){
            if(s[i] == ')'){
                balance++;
            }

            else if(s[i] == '('){
                balance--;
            }

            else{
                stars++;
            }

            if(balance + stars < 0){
                return false;
            }
        }

        if(balance > stars){
            return false;
        }

        return true;
    }
};