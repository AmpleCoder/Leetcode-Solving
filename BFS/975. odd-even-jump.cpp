/*
    approach:
        create a graph where each node will point towards the next node to jump in both cases even and odd 
        and apply bfs starting from each index 

    follow up:
        min no of jump 
            isi se nikl jayega bfs will tell har index se kitta min jump lag raha hei
*/

class Solution {
public:
    bool bfs(int index, map<pair<int, string>, int> &adj, int target){
        queue<pair<int, string>> q;
        q.push({index, "odd"});

        while(!q.empty()){
            pair<int, string> front = q.front();
            q.pop();

            int currentIndex = front.first;
            string currJump = front.second;

            if(currentIndex == target){
                return true;
            }

            int nextIndex = adj[front];
            string nextJump;

            if(currJump == "even"){
                nextJump = "odd";
            }

            else{
                nextJump = "even";
            }

            if(nextIndex != -1){
                q.push({nextIndex, nextJump});
            }
        }

        return false;
    }

    int oddEvenJumps(vector<int>& arr) {
        map<int, int> valToIdxMap;
        int size = arr.size(), goodIndexes = 0, leastSmallestValIdx, leastGreaterValIdx;
        map<pair<int, string>, int> adj;

        valToIdxMap[arr[size - 1]] = size - 1;

        for(int i = size - 2; i >= 0; i--){
            auto leastGreaterValIdxItr = valToIdxMap.lower_bound(arr[i]);
            if(leastGreaterValIdxItr == valToIdxMap.end()){
                leastGreaterValIdxItr--;
                adj[{i, "even"}] = leastGreaterValIdxItr->second;
                adj[{i, "odd"}] = -1;
            }

            else{
                if(leastGreaterValIdxItr->first == arr[i]){
                    adj[{i, "odd"}] = adj[{i, "even"}] = leastGreaterValIdxItr->second;
                }

                else{
                    adj[{i, "odd"}] = leastGreaterValIdxItr->second;
                    
                    if(leastGreaterValIdxItr != valToIdxMap.begin()){
                        leastGreaterValIdxItr--;
                        adj[{i, "even"}] = leastGreaterValIdxItr->second;
                    }

                    else{
                        adj[{i, "even"}] = -1;
                    }
                }
            }

            valToIdxMap[arr[i]] = i;
        }

        for(int i = 0; i < size; i++){
            if(bfs(i, adj, size - 1) == true){
                goodIndexes++;
            }
        }

        return goodIndexes;
    }
};