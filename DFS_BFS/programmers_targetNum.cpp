/* 문제 설명
* n개의 음이 아닌 정수가 있는데, 이 수들을 적절히 덜거나 빼서 
* 주어진 타겟 넘버를 만들려고 함.
* 예를 들어서 [1,1,1,1,1]로 숫자 3을 만든다고 하면,
* -1+1+1+1+1 = 3
* +1-1+1+1+1 = 3
* +1+1-1+1+1 = 3
* +1+1+1-1+1 = 3
* +1+1+1+1-1 = 3 
* 다섯 가지 방법이 있음.
*
* 입출력 예
*   numbers          target     return
*   [1, 1, 1, 1, 1]    3          5
*
* Created by Hyunmi on 02/08/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int index){
 
    if(index >= numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, sum+numbers.at(index), index+1);
    dfs(numbers, target, sum-numbers.at(index), index+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<int> numbers {1, 1, 1, 1, 1};
    int target = 3;
    
    auto start = system_clock::now();
    int result = solution(numbers, target);
    auto end = system_clock::now();
        
    duration<double> elapsed_time = end-start;
    cout << result << endl;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    
    return 0;
}
