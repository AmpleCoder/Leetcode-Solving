class Solution {
public:
    string makeGood(string str) {
        int size = str.size();
        stack<char> s;
        string goodString;

        for(int i = 0; i < size; i++){
            if(islower(str[i])){
                if(!s.empty() && isupper(s.top()) &&  tolower(s.top()) == str[i]){
                    s.pop();
                }

                else{
                    s.push(str[i]);
                }
            }

            else{
                if(!s.empty() && islower(s.top()) &&  toupper(s.top()) == str[i]){
                    s.pop();
                }

                else{
                    s.push(str[i]);
                }
            }
        }

        while(!s.empty()){
            goodString.push_back(s.top());
            s.pop();
        }

        reverse(goodString.begin(), goodString.end());
        return goodString;
    }
};