/*
basic idea : for a given index idx we can either adjust this into some of the current session which can have the sufficient 
capacity or we can create a new session 

trick : to memoize here we encoded {index,vector<int>} into a string and used unordered_map<string,int>

follow up 
try to understand (https://cp-algorithms.com/algebra/all-submasks.html)
and solve it in actually manner i.e dp with bitmask 
this problem is all subsets of mask kinda 

read this : https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/discuss/1432155/Easier-than-top-voted-ones-or-LegitClickbait-or-c%2B%2B
*/

class Solution {
public:
    
    string encode(int index,vector<int> sessions){
        string ans;
        ans+=to_string(index)+"#";
        
        sort(sessions.begin(),sessions.end());
        
        for(auto &x:sessions){
            ans+=to_string(x)+"#";
        }
        
        return ans;
    }
    
    int f(vector<int> &a,int idx,vector<int> &session,int limit,int size,unordered_map<string,int> &mp){
        if(idx==a.size()){
            return 0;
        }
        
        int ans=INT_MAX;
        string encodedString = encode(idx,session);
        
        if(mp.find(encodedString)!=mp.end()){
            return mp[encodedString];
        }
        
        //either adjust a[idx] in one of the existing session 
        for(int i=0;i<size;i++){
            if(session[i]+a[idx]<=limit){
                session[i]+=a[idx];
                ans = min(ans,f(a,idx+1,session,limit,size,mp));
                session[i]-=a[idx];
            }
        }
        
        //either create a new session for a[idx]
        session.push_back(a[idx]);
        ans=min(ans,1+f(a,idx+1,session,limit,size+1,mp));
        session.pop_back();
        
        return mp[encodedString]=ans;
    }
    
    int minSessions(vector<int>& a, int limit) {
        vector<int> session;
        unordered_map<string,int> mp;
        
        int ans = f(a,0,session,limit,0,mp);
        return ans;
    }
};