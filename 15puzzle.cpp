#include "ida_star.h"
using namespace std;

#define GET_TIME(now) { \
    struct timeval t; \
    gettimeofday(&t, NULL); \
    now = t.tv_sec + t.tv_usec/1000000.0; \
}

// u8 start[MAXN][MAXN]={
//     {2,1,3,4},
//     {5,6,7,8},
//     {9,10,11,12},
//     {13,14,0,15}
// };

// u8 start[MAXN][MAXN]={
//     {2,3,4,0},
//     {1,5,7,8},
//     {9,6,10,12},
//     {13,14,11,15}
// };

// u8 start[MAXN][MAXN]={
//     {5,1,2,4},
//     {9,6,3,8},
//     {13,15,10,11},
//     {14,0,7,12}
// };

// u8 start[MAXN][MAXN]={
//     {14,10,6,0},
//     {4,9,1,8},
//     {2,3,5,11},
//     {12,13,7,15}
// };

// u8 start[MAXN][MAXN]={
//     {0,5,15,14},
//     {7,9,6,13},
//     {1,2,12,10},
//     {8,11,4,3}
// };

int main()
{
    u8 start[MAXN][MAXN] = {0};
    for(int i = 0;i < MAXN;++i)
    {
        for(int j = 0;j < MAXN;++j)
        {
            int tmp;
            scanf("%d", &tmp);
            start[i][j] = (u8)tmp;
        }
    }
    if(!judge(start))
    {
        printf("There is no solution to this problem.\n");
        return 0;
    }
    node startstate(start);
    vector<node> path;
    double b,e;
    GET_TIME(b);
    ida_star(startstate, path);
    GET_TIME(e);
    for(int i = 0;i < path.size();++i)
    {
        PRINT((path[i].cur));
    }
    printf("Step: %ld\nRun time: %f s\n", path.size()-1, e-b);
    return 0;
}