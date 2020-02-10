/* 문제 설명
* 컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열
* computers가 매개변수로 주어질 때, 네트워크의 개수를
* return 하도록 solution 함수를 작성
* 
* 컴퓨터의 개수 n은 1이상 200이하인 자연수
* i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현
* computers[i][j]는 항상 1임
*
* 입출력 예
*   n       computers                       return
*   3       [[1,1,0], [1,1,0], [0,0,1]]       2
*   3       [[1,1,0], [1,1,1], [0,1,1]]       1
*
* Created by Hyunmi on 02/10/20.
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

bool visit[200];

void dfs(int start, vector<vector<int>> &computers, int n){
    visit[start] = 1;
    for(int i=0; i<n; i++){
        if(!visit[i] && computers[start][i])
            dfs(i, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(!visit[i]){
            answer++;
            dfs(i, computers, n);
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> computers;
//    computers.push_back(vector<int> {1, 1, 0});
//    computers.push_back(vector<int> {1, 1, 0});
//    computers.push_back(vector<int> {0, 0, 1});
    computers.push_back(vector<int> {1, 1, 0});
    computers.push_back(vector<int> {1, 1, 1});
    computers.push_back(vector<int> {0, 0, 1});
   
   
//    for(int i=0; i<computers.size(); i++){
    auto start = system_clock::now();
    int result = solution(3, computers);
    auto end = system_clock::now();
    duration<double> elapsed_time = end-start;
    cout << result << endl;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
//    }
    
    return 0;
}
