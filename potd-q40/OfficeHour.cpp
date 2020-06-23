#include <iostream>
#include "OfficeHour.h"

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student
@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
    if(onDutyStaff.size() <= 0 || nthStudent < 1 || nthStudent > (int)queue.size()) return -1;
    vector<int> hasTime;
    for(auto i: onDutyStaff){
        hasTime.push_back(0);
    }
    
    int n = 0;//the number of students that has been answered
    for(int t = 0; t < 1000; t++){
        for(int i = 0; i < (int)onDutyStaff.size(); i++){
            if(hasTime[i] == 0 && onDutyStaff[i].getEnergyLevel() > 0){
                Student cur = queue.front();
                queue.pop();
                n = n + 1;
                hasTime[i] = onDutyStaff[i].answerQuestion(cur.getQuestionType(), cur.getTimeNeeded());
                if(n == nthStudent){
                    return t;
                }
            }
            hasTime[i] -= 1;
        }
    }
    return -1;
}