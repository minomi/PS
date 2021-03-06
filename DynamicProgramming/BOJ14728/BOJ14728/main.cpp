//
//  main.cpp
//  BOJ14728
//
//  Created by 오민호 on 2017. 9. 27..
//  Copyright © 2017년 Minomi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

int N, T;


std::vector<std::pair<int, int>> subjects;
int cache[101][10001];
const int NINF = -987654321;

int dp(int n, int time) {
    
    if (time > T)
        return NINF;
    
    if (n > N)
        return 0;
    
    int& ret = cache[n][time];
    
    if (ret != -1) {
        return ret;
    }
    
    ret = std::max(dp(n + 1, time + subjects[n].first) + subjects[n].second,
                   dp(n + 1, time));
    
    return ret;
    
}

int main(int argc, const char * argv[]) {

    memset(cache, -1, sizeof(cache));
    std::cin >> N >> T;

    subjects.resize(N + 1);
    
    for (int i = 1 ; i <= N ; ++i)
        std::cin >> subjects[i].first >> subjects[i].second;
    
    std::cout << std::max(dp(2, subjects[1].first) + subjects[1].second ,
                          dp(2 , 0)) << "\n";
    
    return 0;
    
}
