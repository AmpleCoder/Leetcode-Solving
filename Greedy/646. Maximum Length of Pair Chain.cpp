/*

#s1**********e1      
                           #s2************************************************************************e2
                                       #s3***********e3
                                                                       #s4**********e4
If we sort by start, we can not get the correct answer for this question.
However, if we sort by end, it works.

#s1**********e1      
                                       #s3***********e3
                                                                       #s4**********e4
                           #s2************************************************************************e2
The process of the code by lefeizzz can be explained here:
initial_ending = -inf
explore s1--e1: s1> initial_ending, res++ and updating ending as e1
explore s3--e3, s3> ending(which is e1), we find a valid interval, res++ and update ending as e3.
explore s4--e4, s4>ending(e3), res++ and update ending as e4.
explore s2--e2 and it doesn't work. So we have our final res=3.

From this simple example, we can figure out the key idea is

traverse intervals.
if sorting by ending, then the first valid interval will have a smallest ending value, then it can guarantee we will generate a longest valid path.
Also, essentially, this is a greedy approach to solve problems. We can have an informal proof to show the correctness of this solution.
Claim 1: after sorting by end, the first interval must be contained in the final solution. ,Informal proof: if we don't use first part (which has the smallest end point), we must pick up one from the rest. Since the rest's ending point are greater or equal to the first pair, so those solution will achieve results<=(pick up the first pair). So the best solution should pick up the first pair.
If above claim is true, we can keep on using this claim to say: after pick up the first pair, the best strategy will pick up the first valid pair after the first interval.
Then done.

*/

class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& a) {
        int size = a.size();
        int ans=0;
        int minEnd = INT_MIN;
        int i;
        
        sort(a.begin(),a.end(),cmp);
        
        for(i=0;i<size;i++){
            if(minEnd<a[i][0]){
                ans++;
                minEnd=a[i][1];
            }
        }
        
        return ans;
    }
};