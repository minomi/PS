//
// Created by 오민호 on 2017. 5. 3..
//

#include <cstdio>
#include <algorithm>

const int coords[][4][2] = {
        { {0, 0}, {0, 1}, {0, 2}, {0, 3} }, // ㅡ
        { {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // ㅣ

        { {0, 0}, {0, 1}, {1, 0}, {1, 1} }, // ㅁ

        { {0, 0}, {1, 0}, {2, 0}, {2, 1} }, // ㄴ
        { {0, 0}, {0, 1}, {0, 2}, {-1, 2} }, // ㄴ
        { {0, 0}, {-1, 0}, {-2, 0}, {-2, -1} }, // ㄴ
        { {0, 0}, {0, -1}, {0, -2}, {1, -2} }, // ㄴ

        { {0, 0}, {1, 0}, {2, 0}, {2, -1} }, // ㄴ 대칭
        { {0, 0}, {0, 1}, {0, 2}, {1, 2} }, // ㄴ 대칭
        { {0, 0}, {-1, 0}, {-2, 0}, {-2, 1} }, // ㄴ 대칭
        { {0, 0}, {0, -1}, {0, -2}, {-1, -2} }, // ㄴ 대칭

        { {0, 0}, {1, 0}, {1, 1}, {2, 1} }, //
        { {0, 0}, {0, 1}, {-1, 1}, {-1, 2} }, //
        { {0, 0}, {-1, 0}, {-1, -1}, {-2, -1} }, //
        { {0, 0}, {0, -1}, {1, -1}, {1, -2} }, //

        { {0, 0}, {1, 0}, {1, -1}, {2, -1}}, //
        { {0, 0}, {0, 1}, {1, 1}, {1, 2}}, //
        { {0, 0}, {-1, 0}, {-1, -1}, {-2, -1}}, //
        { {0, 0}, {0, -1}, {1, -1}, {1, -2}}, //

        { {0, -1}, {0, 0}, {1, 0}, {0, 1} }, //
        { {1, 0}, {0, 0}, {0, 1}, {-1, 0} },//
        { {0, 1}, {0, 0}, {-1, 0}, {0, -1} }, //
        { {-1, 0}, {0, 0}, {0, -1}, {1, 0} } //
};

int map[500][500];
int n = 0, m = 0;

bool addible(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < m);
}

// 좌표 y,x 기준에서 구할수 있는 모든 합의 최대값을 구한다.
int addSum(int y, int x) {
    int ret = 0;
    //모든 타입 검사
    for(int type = 0 ; type < 23 ; ++type) {
        int sum = 0;
        int i = 0;
        for(i = 0 ; i < 4 ; ++i) {
            int dy = coords[type][i][0];
            int dx = coords[type][i][1];
            //좌표값을 더할 수 있다면
            if(addible(dy + y, dx + x))
                sum += map[dy + y][dx + x];
            else
                break;
        }
        if(i == 4) ret = std::max(sum, ret);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    int maxSum = 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            scanf("%d",&map[i][j]);

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j) {
            maxSum = std::max(addSum(i, j), maxSum);
        }

    printf("%d\n",maxSum);
    return 0;
}

