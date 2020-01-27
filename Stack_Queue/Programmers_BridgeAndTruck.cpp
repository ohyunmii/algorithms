/*
*
*
*  Created by Hyunmi on 01/27/20.
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
