class Solution {
public:
    int minInsertions(string str) {
        int size = str.size(), res = 0;
        stack<int> s;

        for(int i = 0; i < size; i++){
            if(str[i] == '('){
                //stack is empty or already contain '(' at the top simply push 2
                if(s.empty() || s.top() == 2){
                    s.push(2);
                }

                //stack top = 1
                else{
                    //balance it before adding this current '(' on stack
                    res++;
                    s.pop();
                    s.push(2);
                }
            }

            else {
                //if stack is empty
                if(s.empty()){
                    //add a 1 i.e we're adding half matched opening parenthesis and add 1 into our result
                    res++;  
                    s.push(1);
                }

                else{
                    //pretty simle
                    if(s.top() == 2){
                        s.pop();
                        s.push(1);
                    }

                    else{
                        s.pop();
                    }
                }
            }
        }

        while(!s.empty()){
            res += s.top();
            s.pop();
        }

        return res;
    }
};