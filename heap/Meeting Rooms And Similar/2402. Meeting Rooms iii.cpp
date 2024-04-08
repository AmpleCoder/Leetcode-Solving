/*
    approach
        comments me likha hei 
*/


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        unordered_map<int, int> roomToMeetingCountMap;
        priority_queue<int, vector<int>, greater<int>> unusedRoom;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRoom;
        int roomWithMaxMeetings, maximumMeetings = 0;

        for(int i = 0; i < n; i++){
            unusedRoom.push(i);
        }

        for(auto &currMeeting: meetings){
            int startTime = currMeeting[0];
            int endTime = currMeeting[1];
            //free all the rooms where meeting will get over i.e endTime of meeting in used room <= startTime of current meeting
            //doing this step so that we can assign the lowest unused room to the current meeting
            while(!usedRoom.empty() && usedRoom.top().first <= startTime){
                int currRoom = usedRoom.top().second;
                unusedRoom.push(currRoom);
                usedRoom.pop();
            }

            //if we've some unused room
            if(!unusedRoom.empty()){
                int currRoom = unusedRoom.top();
                unusedRoom.pop();
                usedRoom.push({endTime, currRoom});
                roomToMeetingCountMap[currRoom]++;
            }

            //else we've to fetch the first room which'll get free till that time this meeting has to wait
            else{
                auto [freeTime, currRoom] = usedRoom.top();
                usedRoom.pop();
                usedRoom.push({endTime + freeTime - startTime, currRoom});
                roomToMeetingCountMap[currRoom]++;
            }
        }

        for(auto [currRoom, meetingCount]: roomToMeetingCountMap){
            if(meetingCount > maximumMeetings){
                maximumMeetings = meetingCount;
                roomWithMaxMeetings = currRoom;
            }

            else if(meetingCount == maximumMeetings){
                roomWithMaxMeetings = min(roomWithMaxMeetings, currRoom);
            }
        }

        return roomWithMaxMeetings;
    }
};


/* 
    approach 
        below is the approch i thought one i've to figure out the test case for which the below code is not 
        running
*/

class Solution {
public:
    struct Meeting{
        int startTime;
        int endTime;
        int roomAlloted;
    
        Meeting(int startTime, int endTime, int roomAlloted) : startTime(startTime), endTime(endTime), roomAlloted(roomAlloted){}

        bool operator<(const Meeting& other) const {
            if (endTime != other.endTime) {
                return endTime > other.endTime; // Meeting ending earlier should come first
            } else {
                return roomAlloted > other.roomAlloted; // In case of tie, lowest roomAlloted should come first
            }
        }
    };

    // struct compare{
    //     bool operator()(const Meeting &meeting1, const Meeting &meeting2){
    //         int endTime1 = meeting1.endTime;
    //         int endTime2 = meeting2.endTime;

    //         int roomAlloted1 = meeting1.roomAlloted;
    //         int roomAlloted2 = meeting2.roomAlloted;

    //         if(endTime1 == endTime2){
    //             return roomAlloted1 < roomAlloted2;
    //         }

    //         return endTime1 < endTime2;
    //     }
    // };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        unordered_map<int, int> roomToMeetingCountMap;
        priority_queue<Meeting> meetingPq;
        priority_queue<int, vector<int>, greater<int>> freeRoomsMinPq;

        for(int i = 0; i < n; i++){
            freeRoomsMinPq.push(i);
        }
        
        int size = meetings.size();
        int currRoom;
        int maximumMeetingsAlloted = 0, roomWithMaximumMeetings;

        for(int i = 0; i < size; i++){
            int currStartTime = meetings[i][0];
            int currEndTime = meetings[i][1];

            if(meetingPq.size() == 0){
                currRoom = freeRoomsMinPq.top();
                freeRoomsMinPq.pop();
                Meeting currMeeting(currStartTime, currEndTime, currRoom);
                cout << currStartTime << " : " << currEndTime << " : " << currRoom << endl;
                meetingPq.push(currMeeting);
                roomToMeetingCountMap[currRoom]++;
            }

            else if(meetingPq.size() < n){
                Meeting earliesEndingMeeting = meetingPq.top();
                currRoom = earliesEndingMeeting.roomAlloted;

                if(earliesEndingMeeting.endTime > currStartTime){
                    //allocate meeting to current unused room
                    currRoom = freeRoomsMinPq.top();
                    freeRoomsMinPq.pop();
                    Meeting currMeeting(currStartTime, currEndTime, currRoom);
                    meetingPq.push(currMeeting);
                    roomToMeetingCountMap[currRoom]++;
                }

                else{
                    //free all possible alloted meeting who's scheduledMeetingEndTime <= currStartTime
                    while(!meetingPq.empty() && meetingPq.top().endTime <= currStartTime){
                        //add this alloted room to freeRoomsMinPq coz it's about to get free
                        currRoom = meetingPq.top().roomAlloted;
                        freeRoomsMinPq.push(currRoom);
                        meetingPq.pop();
                    }

                    currRoom = freeRoomsMinPq.top();
                    freeRoomsMinPq.pop();
                    Meeting currMeeting(currStartTime, currEndTime, currRoom);
                    meetingPq.push(currMeeting);
                    roomToMeetingCountMap[currRoom]++;
                }
            }

            else{
                Meeting earliesEndingMeeting = meetingPq.top();
                currRoom = earliesEndingMeeting.roomAlloted;

                if(earliesEndingMeeting.endTime > currStartTime){
                    int delay = earliesEndingMeeting.endTime - currStartTime;
                    currStartTime += delay;
                    currEndTime += delay;
                }

                //free all possible alloted meeting who's scheduledMeetingEndTime <= currStartTime
                while(!meetingPq.empty() && meetingPq.top().endTime <= currStartTime){
                    //add this alloted room to freeRoomsMinPq coz it's about to get free
                    currRoom = meetingPq.top().roomAlloted;
                    freeRoomsMinPq.push(currRoom);
                    meetingPq.pop();
                }

                currRoom = freeRoomsMinPq.top();
                freeRoomsMinPq.pop();

                Meeting currMeeting(currStartTime, currEndTime, currRoom);
                // cout << currStartTime << " : " << currEndTime << " : " << currRoom << endl;
                meetingPq.push(currMeeting);
                roomToMeetingCountMap[currRoom]++;
            }
        }

        for(auto [room, meetingCount]: roomToMeetingCountMap){
            if(maximumMeetingsAlloted < meetingCount){
                maximumMeetingsAlloted = meetingCount;
                roomWithMaximumMeetings = room;
            }

            else if(maximumMeetingsAlloted == meetingCount){
                roomWithMaximumMeetings = min(roomWithMaximumMeetings, room);
            }
        }

        return roomWithMaximumMeetings;
    }
};