/* 문제 설명
* 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인
* 전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사임.
* 구조대: 119
* 박준영: 97 674 223 
* 지영석: 11 9552 4421 
*
* 전화번호부에 적힌 전화번호를 담은 배열 phone_book이 함수의 매개변수로 주어질 때,
* 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를, 그렇지 않으면 true를
* return 하도록 solution 함수를 작성
*
* 입출력 예
*   phone_book                              return
*   ["119", "97674223", "1195524421"]       false
*   ["123", "456", "789"]                   true
*   ["12", "123", "1235", "567", "88"]      false
*
*
*   TODO:
*   hash로 풀어보기, 효율성 높이기
*
* Created by Hyunmi on 02/13/20.
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

bool solution(vector<string> phonebook) {
    bool answer = true;
    
    sort(phonebook.begin(), phonebook.end());
    for(int i=1; i<phonebook.size(); i++){
        if(phonebook[i-1]==phonebook[i].substr(0,phonebook[i-1].size())){
            return false;
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<vector<string>> phonebook;
    phonebook.push_back(vector<string> {"119", "97674223", "1195524421"});
    phonebook.push_back(vector<string> {"123", "456", "789"});
    phonebook.push_back(vector<string> {"12", "123", "1235", "567", "88"});
   
    bool result[3];
    
    for(int i=0; i<phonebook.size(); i++){
    auto start = system_clock::now();
    result[i] = solution(phonebook[i]);
    auto end = system_clock::now();

    duration<double> elapsed_time = end-start;
    cout << result[i] << endl;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    }
    
    return 0;
}
