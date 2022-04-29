/*
straightforward bfs but take care of some corner cases

variation
what if we add weight between transitions?
think for this (ig probably this one is djikstra's)
*/

class Solution {
public:
    
    int minMovesToReachTarget(unordered_set<string> &arr,string targetString){
      if(arr.find("0000")!=arr.end()){
          return -1;
      }
        
      queue<pair<string,int>> q;
      q.push({"0000",0});
      unordered_set<string> visited;
      char temp;
        
      visited.insert("0000");

      while(!q.empty()){
        auto topEle = q.front();
        q.pop();

        string currString = topEle.first;
        int moves = topEle.second;
        
        // cout<<currString<<" "<<moves<<endl;
 
          
        if(currString==targetString){
            return moves;
        }

        //generate all possible configuration
        for(int i=0;i<4;i++){
              string nextStateStr=currString;
              int curr=currString[i]-'0',tempVal;

              //move forward
              tempVal=(curr+1)%10;
              nextStateStr[i]=tempVal+'0';
              
              // cout<<nextStateStr<<" ";
            
              if(arr.find(nextStateStr)==arr.end() && visited.find(nextStateStr)==visited.end()){
                q.push({nextStateStr,moves+1});
                visited.insert(nextStateStr);
              }

              //move backward
              tempVal=(curr-1+10)%10;
              nextStateStr[i]=tempVal+'0';
            
              // cout<<nextStateStr<<" ";

              if(arr.find(nextStateStr)==arr.end() && visited.find(nextStateStr)==visited.end()){
                q.push({nextStateStr,moves+1});
                visited.insert(nextStateStr);
              }
            }
          
          // cout<<endl;
        }

        return -1;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(),deadends.end());
        return minMovesToReachTarget(s,target);
    }
};