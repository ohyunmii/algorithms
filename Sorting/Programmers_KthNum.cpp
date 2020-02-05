/* 문제 설명
* 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k 번째에 있는 수를 구하려 함
*
* 예를 들어서 array가 [1,5,2,6,3,7,4], i=1, j=5, k=3이라면
* 1. array의 2번째부터 5번째까지 자르면 [5,2,6,3]임
* 2. 1에서 나온 배열을 정렬하면 [2,3,5,6]임
* 3. 2에서 나온 배열의 3번째 숫자는 5임
*
* 입출력 예
*   array               commands                        return
*   [1,5,2,6,3,7,4]     [[2,5,3], [4,4,1], [1,7,3]]     [5,6,3]       
*
* Created by Hyunmi on 2/02/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/


#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using namespace chrono;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i<commands.size(); i++){
        vector<int> temp;
        temp.assign(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    
    
    vector<int> array{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands;
    commands.push_back(vector<int> {2, 5, 3});
    commands.push_back(vector<int> {4, 4, 1});
    commands.push_back(vector<int> {1, 7, 3});
    
    auto start = system_clock::now();
    vector<int> result = solution(array, commands);
    auto end = system_clock::now();
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    
    duration<double> elapsed_time = end-start;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    
    return 0;
}
