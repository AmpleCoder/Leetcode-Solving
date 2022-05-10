/*
super awesome intuitve problem need to get a feel of some number of things 
isme stack ka top apne right side wale elements ko layoff krta chla jayega 
jisse apne ko ek sabse right mei candidate c3 milega agar wo current a[i] se 
bda hei iska matlab 132 pattern mil gya kyu kyuki a[i] to stack ke top element 
se chota tha hi aur wo top jinko lay kiya usme se ek a[i] se bda nikl gya sexy af

follow up 
1)find number of 132 triplets in given array
2)find the most closing greater in the right side of every a[i] using stack
3)find if 123 and 321 pattern exist or not and find there total numbers 
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int s3=INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<s3){
                return true;
            }
            
            else{
                while(!s.empty() && nums[i]>s.top()){
                    s3=s.top();
                    s.pop();
                }
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
};