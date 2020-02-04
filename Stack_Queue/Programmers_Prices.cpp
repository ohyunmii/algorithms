/* 문제 설명
* 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
* 가격이 떨어지지 않은 기간은 몇 초인지 return하는 solution 함수를 작성
* 
* 입출력 예
*   prices         return
*   [1,2,3,2,3]    [4,3,1,1,0]        
* 
* 입출력 예 설명
* 1초 시점의 1은 끝까지 가격이 떨어지지 않음.
* 2초 시점의 2는 끝까지 가격이 떨어지지 않음.
* 3초 시점의 3은 1초 뒤에 가격이 떨어짐. 따라서 1초간 가격이 떨어지지 않은 것으로 봄.
* 4초 시점의 2는 1초간 가격이 떨어지지 않음.
* 5초 시점의 3은 0초간 가격이 떨어지지 않음.    
*
* Created by Hyunmi on 04/02/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/


#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int index = 0;
    int count = 0;
    
    while(index < prices.size()){
        count = 0;
        for(int i=index+1; i<prices.size(); i++){
            if(prices[index] <= prices[i]) count++;
            else{ count++; break;}
        }
        answer.push_back(count);
        index++;
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<int> prices{1,2,3,2,3};
    
    auto start = system_clock::now();
    vector<int> result = solution(prices);
    auto end = system_clock::now();
    
    for(int i=0; i<result.size(); i++){
    cout << result[i] <<endl;
    }
    
    duration<double> elapsed_time = end-start;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    
    return 0;
}
