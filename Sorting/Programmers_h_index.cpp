/* 문제 설명
* H-Index는 과학자의 생산성과 영향력을 나타내는 지표임.
* 어느 과학자의 H-Index를 나타내는 값인 h를 구하려 한다면:
* 어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편이상이고,
* 나머지 논문이 h번 이하 인용되었다면 h가 이 과학자의 H-index가 됨.
*
* 입출력 예
*   citations           return
*   [63, 0, 6, 1, 5]      3
*
* Created by Hyunmi on 02/07/20.
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

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i=0; i<citations.size(); i++){
        if(citations[i]<=answer) break;
        answer++;
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    
    vector<int> citations {3, 0, 6, 1, 5};
    
    auto start = system_clock::now();
    int result = solution(citations);
    auto end = system_clock::now();
        
    duration<double> elapsed_time = end-start;
    cout << result << endl;
    cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    
    return 0;
}
