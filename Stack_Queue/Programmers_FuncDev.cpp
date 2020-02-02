/* 
 * 문제 출처: 프로그래머스 https://programmers.co.kr/learn/courses/30/lessons/42586
 * 문제 설명:
 * 프로그래머스 팀에서 기능 개선 작업을 수행 중.
 * 각 기능은 진도가 100%일 때 서비스에 반영 가능.
 * 각 기능의 개발 속도는 달라서 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있음.
 * 하지만, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됨.
 *
 * 예를 들어서 진행상황이 93%, 30%, 55%인 기능들이 있고,
 * 각 기능의 개발속도가 하루에 1%, 30%, 5%라고 할때...
 *
 * 입출력 예
 * progresses    	speeds         return
 * [93,30,55]       [1,30,5]       [2,1]
 * 
 * 첫 번째 기능은 93% 완료되어 있고, 하루에 1%씩 작업이 가능하므로 7일간 작업 후 배포
 * 두 번째 기능은 30% 완료되어 있고, 하루에 30%씩 작업이 가능하므로 3일간 작업 후 배포
 * 하지만, 첫 번째 기능이 완성되지 않았기 때문에 두 번째 기능은 7일째 배포 가능
 * 세 번째 기능은 55% 완료되어 있고, 하루에 5%씩 작업이 가능하므로 9일간 작업후 배포
 *
 * 따라서 7일째에 2개의 기능, 9일째에 1개의 기능이 배포됨
 *
 *  Created by Hyunmi on 1/27/20.
 *  Copyright © 2020 Hyunmi. All rights reserved.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define FULL 100

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 1;
    int temp = ceil((FULL-progresses[0])/speeds[0]);
    
    for(int i=1; i<progresses.size(); i++){
       
        int current = ceil((FULL-progresses[i])/speeds[i]);
       
        if(temp >= current){
            count++;
        } else{
            answer.push_back(count);
            count = 1;
            temp = current;
        }
    }
    answer.push_back(count);
    
    return answer;
}



int main(int argc, const char * argv[]) {
    
    vector<int> progresses{93,30,55} ;
    vector<int> speeds{1,30,5};
    vector<int> result = solution(progresses, speeds);
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    
    return 0;
}