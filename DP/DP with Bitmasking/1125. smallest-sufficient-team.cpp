/*
    approach:
        very nice problem memoization is trick part here mere liye
*/

class Solution {
public:
    void dfs(vector<vector<int>> &dp, vector<int> &peopleSkill, int &totalReqSkills, int currSkill, int currIdx, int size, vector<int> currPossibleTeam, vector<int> &smallestTeam){
        if(currIdx == size){
            if(currSkill == totalReqSkills){
                if(smallestTeam.size() == 0 || smallestTeam.size() > currPossibleTeam.size()){
                    smallestTeam = currPossibleTeam;
                }
            }

            return;
        }

        if(dp[currIdx][currSkill] != -1){
            if(dp[currIdx][currSkill] <= currPossibleTeam.size()){
                return;
            }
        }

        if(smallestTeam.size() > 0 && smallestTeam.size() < currPossibleTeam.size()){
            return;
        }

        //ignore the current idx person skill in currSkill
         dfs(dp, peopleSkill, totalReqSkills, currSkill, currIdx + 1, size, currPossibleTeam, smallestTeam);

        //include the current idx person skill in currSkill
        currPossibleTeam.push_back(currIdx);

        dfs(dp, peopleSkill, totalReqSkills, (currSkill | peopleSkill[currIdx]), currIdx + 1, size, currPossibleTeam, smallestTeam);

        currPossibleTeam.pop_back();

        if(currPossibleTeam.size() > 0){
            dp[currIdx][currSkill] = currPossibleTeam.size();
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillmap;
        vector<int> peopleSkillHash;
        int reqSkillSize = req_skills.size(), peopleSkillSize = people.size();
        int totalReqSkills = 0;
        vector<int> smallestTeam;
        vector<int> currPossibleTeam;

        for(int i = 0; i < reqSkillSize; i++){
            skillmap[req_skills[i]] = i;
            totalReqSkills |= (1 << i);
        }

        for(auto &currSkills: people){
            int currHash = 0;
            
            for(auto &skill: currSkills){
                currHash |= (1 << skillmap[skill]);
            }

            peopleSkillHash.push_back(currHash);
        }

        vector<vector<int>> dp(peopleSkillSize + 1, vector<int>(totalReqSkills + 1, -1));

        dfs(dp, peopleSkillHash, totalReqSkills, 0, 0, peopleSkillSize, currPossibleTeam, smallestTeam);
        return smallestTeam;
    }
};