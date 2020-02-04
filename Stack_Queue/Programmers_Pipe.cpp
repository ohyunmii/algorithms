/* 문제 설명
* 여러 개의 쇠막대기를 레이저로 절단하려고 할 때,
* 효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고,
* 레이저를 위에서 수직으로 발사하여 쇠막대기들을 자름.
*
* 쇠막대기와 레이저의 배치는 다음 조건을 만족함:
* - 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있음
* - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓음
* - 각 쇠막대기를 자르는 레이저는 적어도 하나 존재
* - 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않음.
* 그림은 프로그래머스에서 확인: https://programmers.co.kr/learn/courses/30/lessons/42585 
* 
* 레이저와 막대기의 표현
* (a) 레이저는 여는 괄호와 다든 괄호의 인접한 쌍 '()'으로 표현.
* (b) 쇠막대기의 왼쪽 끝은 여는 괄호 '(', 오른쪽 끝은 닫힌 괄호 ')'로 표현
* 
* 입출력 예
*   arrangement       			return
*   "()(((()())(())()))(())"      17            
*
* Created by Hyunmi on 04/02/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/


#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <stack>


using namespace std;
using namespace chrono;

int solution(string arrangement){
	int answer = 0;
	stack<char> pipe;

	for(int i=0; i<arrangement.length(); i++){
		if(arrangement[i]=='(') pipe.push(1);
		else{
			pipe.pop();
			if(arrangement[i-1]=='('){
				answer += pipe.size();
			} else{
				answer++;
			}
		}
	}

	return answer;
}


int main(int argc, const char * argv[]) {
    
    string arrangement = "()(((()())(())()))(())";
    
    auto start = system_clock::now();
       
    cout << solution(arrangement) <<endl;
    auto end = system_clock::now();
        
    duration<double> elapsed_time = end-start;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    
    return 0;
}