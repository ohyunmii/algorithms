/* 문제 설명
* 중요도가 높은 문서를 먼저 출력하는 프린터를 개발함.
* 개발한 프린터는 아래와 같은 방식으로 인쇄작업을 수행
*
* 1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냄
* 2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣음
* 3. 그렇지 않으면 J를 인쇄 함.
*
* 예를 들어서 4개의 문서(A,B,C,D)가 순서대로 인쇄대기 목록에 있고
* 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됨
*
* 현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와
* 내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return하도록 하는 solution 함수를 작성
*
* 입출력 예
*   priorities          location        return
*   [2,1,3,2]             2              1         
*   [1,1,9,1,1,1]         0              5
*
*
* Created by Hyunmi on 2/02/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/



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
