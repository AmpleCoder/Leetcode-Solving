/*
sexiest problem here the only thing to think of is we have to utilize ladders very optimally 
so if k ladders than use k ladders for k maximum diffrence jumps(damn)
and hence upto some index i if we've utilized all the ladders than all we need to think is whether it's possible to 
reach upto index i without any ladder or not 

ps:very beautiful interview problem + lots of edge cases 
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i,size=heights.size(),currSum=0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(i=1;i<size;i++){
            int currDiff = heights[i]-heights[i-1];
            if(currDiff<=0) continue;
            if(ladders!=0 && (pq.empty() || pq.size()<ladders)){
                pq.push(currDiff);
            }
            
            else if(ladders!=0 && pq.size()==ladders){
                int remVal=0;
                if(currDiff > pq.top()){
                    remVal=pq.top();
                    pq.pop();
                    pq.push(currDiff);
                    currSum+=remVal;
                }
                
                else{
                    currSum+=currDiff;
                }
            }
            
            else{
                currSum+=currDiff;
            }

            // cout<<currDiff<<" "<<bricks<<" "<<i<<endl;
            if(currSum>bricks){
                break;
            }
        }
        
        return i-1;
    }
};