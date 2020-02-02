#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> input;
    priority_queue<int> priority;
    
    for(int i=0; i<priorities.size(); i++){
        input.push(make_pair(i, priorities[i]));
        priority.push(priorities[i]);
    }

    while(!input.empty()){
        if(input.front().second == priority.top()){
            if(input.front().first == location){
                return answer + 1;
            } else{ // same priority
                input.pop();
                priority.pop();
                answer++;
            }
        } else{
            input.push(input.front());
            input.pop();
        }
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    int testcase_num = 2;
    vector<vector<int>> priorities;
    priorities.push_back(vector<int> {2,1,3,2});
    priorities.push_back(vector<int> {1,1,9,1,1,1});
    vector<int> location {2,0};
    
    while(testcase_num--){
        int cur_pos = abs(testcase_num - 1);
        cout << solution(priorities[cur_pos], location[cur_pos]) <<endl;
    }
    
    return 0;
}
