/*
    here carefully observe that target array vals are distinct hope you got the idea
*/

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int targetSize = target.size();
        int arrSize = arr.size();
        unordered_map<int, int> order;
        vector<int> LISList;

        //fetch the order        
        for(int i = 0; i < targetSize; i++){
            order[target[i]] = i;
        }

        for(int i = 0; i < arrSize; i++){
            if(order.find(arr[i]) == order.end()){
                continue;
            }

            //if list is empty add current order value into list and continue
            if(LISList.empty()){
                LISList.push_back(order[arr[i]]);
                continue;
            }

            //find the first value in the LISList which is > arr[i] and then replace that value with arr[i]
            int low, high, mid, index = -1;
            low = 0;
            high = LISList.size() - 1;

            while(low <= high){
                mid = low + (high - low)/2;
                if(LISList[mid] < order[arr[i]]){
                    low = mid + 1;
                }

                else{
                    index = mid;
                    high = mid -1;
                }
            }

            if(index != -1){
                LISList[index] = order[arr[i]];
            }

            else{
                LISList.push_back(order[arr[i]]);
            }
        }

        return targetSize - LISList.size();
    }
};