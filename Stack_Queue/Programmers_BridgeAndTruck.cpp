/*
 * 문제 설명:
 * 트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다.
 * 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다.
 * 트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딜 수 있습니다.
 *
 * 예를 들어서 길이가 2이고, 10kg 무게를 견디는 다리가 있다면...
 * 무게가 [7,4,5,6]kg인 트릭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건넘.
 *
 *
 * 경과 시간     다리를 지난 트럭       다리를 건너는 트럭      대기 트럭
 *   0          []                  []               [7,4,5,6]
 *   1-2        []                  [7]              [4,5,6]
 *   3          [7]                 [4]              [5,6]
 *   4          [7]                 [4,5]            [6]
 *   5          [7,4]               [5]              [6]
 *   6-7        [7,4,5]             [6]              []
 *   8          [7,4,5,6]           []               []
 *
 *
 * 입출력 예
 * weight        truck_weights                       return
 * 10            [7,4,5,6]                           8
 * 100           [10]                                101
 * 100           [10,10,10,10,10,10,10,10,10,10]     110
 *
 *
 *  Created by Hyunmi on 1/27/20.
 *  Copyright © 2020 Hyunmi. All rights reserved.
 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int sum, count;
    sum = count = 0;
    
    for(int i=0; i<truck_weights.size(); i++) {
        int d = truck_weights[i];
        
        while (true) {
            if (q.empty()) {
                q.push(d);
                sum += d;
                count++;
                break;
            } else if (q.size() == bridge_length) {
                sum -= q.front();
                q.pop();
            } else {
                if (sum + d > weight) {
                    q.push(0);
                    count++;
                } else {
                    q.push(d);
                    count++;
                    sum += d;
                    break;
                }
            }
            
        }
        
    }
    
    return count + bridge_length;
}


int main(int argc, const char * argv[]) {
    
    int testcase_num = 3;
    
    int bridge_length[] = {2, 100, 100};
    int weight[] = {10, 100, 100};
    vector<vector<int>> truck_weights;
    truck_weights.push_back(vector<int> {7,4,5,6});
    truck_weights.push_back(vector<int> {10});
    truck_weights.push_back(vector<int> {10,10,10,10,10,10,10,10,10,10});
    
    while(testcase_num--){
        int cur_pos = abs(testcase_num - 2);
        cout <<  solution(bridge_length[cur_pos], weight[cur_pos],truck_weights[cur_pos])<<endl;
    }
    
    return 0;
}
