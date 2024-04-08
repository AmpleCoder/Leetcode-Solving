/*
    approach 1:
        simulation
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        int size = students.size(), i = 0, count = 0; 
        bool isPossible = true;

        for(int i = 0; i < size; i++){
            studentQueue.push(students[i]);
        }

        while(i < size && isPossible){
            int currSandwich = sandwiches[i];
            int currStudent = studentQueue.front();

            if(currSandwich == currStudent){
                i++;
                studentQueue.pop();
            }

            else{
                studentQueue.pop();
                studentQueue.push(currStudent);

                //check if any upcoming student in the queue can eat or not
                queue<int> copyStudentQueue = studentQueue;

                while(!copyStudentQueue.empty()){
                    int newStudent = copyStudentQueue.front();
                    copyStudentQueue.pop();

                    if(newStudent == currSandwich){
                        break;
                    }
                }

                if(copyStudentQueue.size() == 0){
                    isPossible = false;
                }
            }
        }

        return studentQueue.size();
    }
};


/*
    approach 2:
        counting 
            for a given sandwich i'll check if there are any student who can consume this type of sandwich rn or
            later on if yes let if consume else return the remaining students
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros = 0, ones = 0, size = students.size();

        for(int i = 0; i < size; i++){
            if(students[i] == 0){
                zeros++;
            }

            else{
                ones++;
            }
        }

        for(int i = 0; i < size; i++){
            if(sandwiches[i] == 0){
                if(zeros == 0){
                    return ones;
                }

                zeros--;
            }

            else{
                if(ones == 0){
                    return zeros;
                }

                ones--;
            }
        }

        return 0;
    }
};