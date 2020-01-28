/* 문제 설명
* 수평 직선에 신호를 송수힌하는 탑 N대를 세움.
* 발사한 신호는 신호를 보낸 탑보다 높은 탑에서만 수신 가능.
* 한번 수신된 신호는 다른 탑으로 송신되지 않음
*
* 예를 들어서 높이가 6,9,5,7,4인 다섯 개의 탑이 왼쪽으로 동시에 신호를 발사하면,
* 높이가 4인 다섯 번째 탑에서 발사한 신호는 높이가 7인 네 번째 탑이 수신하고,
* 높이가 7인 네 번째 탑의 신호는 높이가 9인 두번째 탑이 수신,
* 높이가 5인 세 번째 탑과 높이가 6인 첫 번째 탑이 보낸 신호는 어떤 탑에서도 수신할 수 없음.
*
*
*   송신 탑(높이)    수신 탑(높이)
*      5(4)          4(7)
*      4(7)          2(9)
*      3(5)          2(9)
*      2(9)           -
*      1(6)           - 
*
*
* 입출력 예
*   heights             return
*   [6,9,5,7,4]         [0,0,2,2,4]
*   [3,9,9,3,5,7,2]     [0,0,0,3,3,3,6]
*   [1,5,3,6,7,6,5]     [0,0,2,0,0,5,6]
*
*
* Created by Hyunmi on 1/28/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/


#include <string>
#include <vector>

using namespace std;
#define TESTCASE 3

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int top = heights[0];
    int hei = 0;
    answer.push_back(0);
    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] >= heights[i-1] && top < heights[i]) {
            top = heights[i]; answer.push_back(0);
        }
        else if (heights[i] >= heights[i-1] && top >= heights[i]) {
            answer.push_back(hei);
        }
        else if (heights[i] < heights[i-1]) {
            hei = i;
            answer.push_back(hei);
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    
    int testcase_num = TESTCASE;
    
    vector<vector<int>> heights;
    heights.push_back(vector<int> {6,9,5,7,4});
    heights.push_back(vector<int> {3,9,9,3,5,7,2});
    heights.push_back(vector<int> {1,5,3,6,7,6,5});
    
    while(testcase_num--){
        int cur_pos = abs(testcase_num - (TESTCASE-1));
        vector<int> ans = solution(heights[cur_pos]);
        cout<< "[" << cur_pos << "]";
        for(int i=0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}