/*
    approach:
        get the available tasks 
        pick up the task having with shortest processing time 
        process it update the time 

    follow up:
        how about multi threaded cpu?
*/

class Solution {
public:
    struct Task{
        int arrivalTime;
        int processTime;
        int index; 
    };

    bool static cmp1(Task &a, Task &b){
        if(a.arrivalTime == b.arrivalTime){
            return a.processTime < b.processTime;
        }

        return a.arrivalTime < b.arrivalTime;
    }

    struct cmp2{
        bool operator()(Task &a, Task &b){
            if(a.processTime == b.processTime){
                return a.index > b.index;
            }

            return a.processTime > b.processTime;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> v;
        int size = tasks.size(), nextTaskIdx = 0;
        long long currTime = 0;
        priority_queue<Task, vector<Task>, cmp2> availableTasks;
        vector<int> processedTaskIndexes;

        for(int i = 0; i < size; i++){
            Task currTask;
            int arrivalTime = tasks[i][0];
            int processTime = tasks[i][1];
            currTask.arrivalTime = arrivalTime;
            currTask.processTime = processTime;
            currTask.index = i;

            v.push_back(currTask);
        }

        sort(v.begin(), v.end(), cmp1);

        while((nextTaskIdx < size) || (!availableTasks.empty())){
            //if heap is empty update the timer crucial step
            if((availableTasks.empty())){
                currTime = max(currTime, 1ll * v[nextTaskIdx].arrivalTime);
            }

            //add all the tasks who's enqueue time <= time
            while(nextTaskIdx < size && v[nextTaskIdx].arrivalTime <= currTime){
                availableTasks.push(v[nextTaskIdx++]);
            }

            // cout << currTime << " " << nextTaskIdx << endl;

            //enqueue the top task and update the current time
            Task topTask =  availableTasks.top();
            availableTasks.pop();

            //process this task i.e add the index into our result 
            processedTaskIndexes.push_back(topTask.index);

            //update time
            currTime += topTask.processTime;
        }

        return processedTaskIndexes;
    }
};