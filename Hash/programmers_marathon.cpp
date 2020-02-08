/* 문제 설명
* 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와
* 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때,
* 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성
* 단 한명의 선수만 완주를 하지 못함. 
*
* Created by Hyunmi on 02/08/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace chrono;


string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> participants;
    
    for(string name: participant){
        ++participants[name];
    }
    for(string name:completion){
        --participants[name];
    }
    for(auto pair: participants){
        if(pair.second > 0){
            return pair.first;
        }
    }
    return "";
}


int main(int argc, const char * argv[]) {
    
    vector<vector<string>> participant;
    participant.push_back(vector<string> {"leo", "kiki", "eden"});
    participant.push_back(vector<string> {"josipa", "filipa", "marina", "nikola", "vinko"});
    participant.push_back(vector<string> {"milsav", "stanko", "mislav", "ana"});
    vector<vector<string>> completion;
    completion.push_back(vector<string> {"eden", "kiki"});
    completion.push_back(vector<string> {"marina", "josipa", "filipa", "nikola"});
    completion.push_back(vector<string> {"stanko", "ana", "mislav"});
    
    for(int i=0; i<participant.size(); i++){
    auto start = system_clock::now();
    string result = solution(participant[i], completion[i]);
    auto end = system_clock::now();
    duration<double> elapsed_time = end-start;
    cout << result << endl;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    }
    
    return 0;
}
