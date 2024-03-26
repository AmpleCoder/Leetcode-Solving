class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size(), remainingA = 0, currB = 0, currA = 0, minDeletion = size;

        for(int i = 0; i < size; i++){
            remainingA += (s[i] == 'a' ? 1 : 0);
        }

        for(int i = 0; i < size; i++){
            if(s[i] == 'a'){
                remainingA--;		
            }
                
            minDeletion = min(minDeletion, remainingA + currB);

            if(s[i] == 'b'){
                currB++;
            }
        }

        return minDeletion;
    }
};