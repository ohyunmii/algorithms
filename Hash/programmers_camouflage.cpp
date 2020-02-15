/* 문제 설명
* 스파이들은 매일 다른 옷을 조합하여 입어서 자신을 위장함.
* 예를 들어서 스파이가 가진 옷이 아래와 같고, 
* 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면, 
* 다음날은 처바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용해야 함
* 
* 종류 	이름
* 얼굴	동그란 안경, 검정 선글라스
* 상의	파란색 티셔츠
* 하의	청바지
* 겉옷 	긴 코트
* 
* 스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 
* 서로 다른 옷의 조합 수를 return하도록 solution 함수를 작성
*
* 입출력 예
* clothes 									return
* ------------------------------------------------
* [["yellow_hat", "headgear"], 					5
* ["blue_sunglasses", "eyewear"], 
* ["green_turban", "headgear"]]
* ------------------------------------------------
* [["crow_mask", "face"], 						3
* ["blue_sunglasses", "face"]
* ["smoky_makeup", "face"]]
*
* Created by Hyunmi on 02/14/20.
* Copyright © 2020 Hyunmi. All rights reserved.
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <map>

using namespace std;
using namespace chrono;


int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    map<string, int> types;
    
    for(vector<string> idx: clothes){
        types[idx[1]]++;
    }
    
    for (map<string, int>::iterator iter = types.begin(); iter != types.end(); ++iter) {
        answer *= ((*iter).second + 1);
    }
    
    return answer - 1;
    
}


int main(int argc, const char * argv[]) {
    
    int result[2];
    vector<vector<string>> first_case = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string>> second_case = {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}};
    vector<vector<vector<string>>> clothes= {{first_case}, {second_case}};

    for(int i=0; i<clothes.size(); i++){
        auto start = system_clock::now();
        result[i] = solution(clothes[i]);
        auto end = system_clock::now();

        duration<double> elapsed_time = end-start;
        cout << result[i] << endl;
        cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n" << endl;
    }
    
    return 0;
}