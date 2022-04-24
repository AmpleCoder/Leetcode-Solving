/*
hint : route bana ke karo 

follow up : reachable stations not direct
*/

class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap;
    unordered_map<string,pair<int,double>> routeMap;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> checkInEle=checkInMap[id];
        checkInMap.erase(id);
        
        string checkInStation=checkInEle.first;
        int checkInTime=checkInEle.second;
        
        string route=checkInStation+"_"+stationName;
        routeMap[route].first+=(t-checkInTime);
        routeMap[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"_"+endStation;
        double average=routeMap[route].first/routeMap[route].second;
        return average;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/*
checkout this awesome solution using proper OOPS
https://leetcode.com/problems/design-underground-system/discuss/672744/Java-solution-for-easy-understanding-using-OOPS
*/