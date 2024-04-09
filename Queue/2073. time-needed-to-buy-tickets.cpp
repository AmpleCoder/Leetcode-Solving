/*
    approach:
        simulation
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        unordered_map<int, int> indexToTimeMap;
        queue<pair<int, int>> q;
        int size = tickets.size(), time = 0;

        for(int i = 0; i < size; i++){
            q.push({tickets[i], i});
        }

        while(!q.empty()){
            time++;
            pair<int, int> front = q.front();
            q.pop();
            int frontTicket, frontIndex;
            frontTicket = front.first;
            frontIndex = front.second;

            frontTicket--;
            if(frontTicket == 0){
                indexToTimeMap[frontIndex] = time;
                continue;
            }

            q.push({frontTicket, frontIndex});
        }

        return indexToTimeMap[k];
    }
};

/*
    approach:
        considering when index k completes the ticket collection how many time elements before and after 
        appear it 
        if(i <= k)  min(tickets[i], tickets[k])
        else    min(tickets[i], tickets[k] - 1)
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0, size = tickets.size();

        for(int i = 0; i < size; i++){
            if(i <= k){
                time += min(tickets[i], tickets[k]);
            }

            else{
                time += min(tickets[i], tickets[k] - 1);
            }
        }

        return time;
    }
};