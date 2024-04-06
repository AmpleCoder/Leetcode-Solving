/*
    if str[i] == '(' push index
    str[i] == ')' and stack size is not empty them pop top element of stack, else remove current element
    at the end don't consider all those index which're there in stack

    now the task is to optimise space for that maybe we can try not to use set 
    kya kr skte ek takeItOrNot boolean array liya string ki size ke barabar iska size hoga
    aage se process kiya balance maintain rkha ')' mila to balance -= 1 kiya '(' to balance += 1
    if at any point balance < 0 ye index bad index hua 
    now reverse the string with '(' isko ')' ye krke again same process repeat kiya and bad indexes ko mark kiya 
    now all we left is with nayi string banani hei in which bad indexes excluded ho fairly simple
*/

class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int size = str.size();
        stack<int> s;
        unordered_set<int> notTake;
        string result;

        for(int i = 0; i < size; i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                continue;
            }

            if(str[i] == '('){
                s.push(i);
            }

            else{
                if(!s.empty()){
                    s.pop();
                }

                else{
                    notTake.insert(i);
                }
            }
        }

        while(!s.empty()){
            notTake.insert(s.top());
            s.pop();
        }

        for(int i = 0; i < size; i++){
            if(notTake.find(i) == notTake.end()){
                result.push_back(str[i]);
            }
        }

        return result;
    }
};