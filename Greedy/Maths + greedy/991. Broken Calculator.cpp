/*
greedy ye tha isme ki 
reach source from target 
how ?
if target is even make it target/2 think why it can't be made target+1
if it's odd then no choice make it target + 1
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startValue){
            if(target%2==0){
                target/=2;
            }
            
            else{
                target+=1;
            }
            
            ans++;
        }
        
        return ans+startValue-target;
    }
};