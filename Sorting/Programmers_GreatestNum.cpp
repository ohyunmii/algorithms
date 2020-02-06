/* 문제 설명
* 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내시오.
*
* 예를 들어서 주어진 정수가 [6, 10, 2]라면 
* [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고
* 여기서 가장 큰 수는 6210임.
* 
*
* 입출력 예
*   numbers             return
*   [6, 10, 2]          "6210"
*   [3, 30, 34, 5, 9]   "9534330"     
*
* Created by Hyunmi on 2/02/20.
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

bool cmp(const string &a, const string &b){
    return a + b > b + a? true:false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    for(int i = 0; i< numbers.size(); i++){
        temp.push_back(to_string(numbers.at(i)));
    }
    sort(temp.begin(), temp.end(), cmp);
    
    for(string str: temp){
        answer += str;
    }
    
    if(answer[0] == '0') return 0;
    
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<string> result;
    vector<double> time;
    vector<vector<int>> numbers;
    numbers.push_back(vector<int> {6, 10, 2});
    numbers.push_back(vector<int> {3, 30, 34, 5, 9});
    
    
    for(int i=0; i<numbers.size(); i++){
        auto start = system_clock::now();
        result.push_back(solution(numbers[i]));
        auto end = system_clock::now();
        
        duration<double> elapsed_time = end-start;
        time.push_back(elapsed_time.count());
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
        cout << "Elapsed time: " << time[i] << " seconds.\n" << endl;
    }
    
    return 0;
}
