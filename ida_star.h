#ifndef __IDA_STAR__
#define __IDA_STAR__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <climits>
#include <sys/time.h>
using namespace std;

typedef unsigned char u8;
#define MAXN 4

typedef struct node
{
    u8 cur[MAXN][MAXN];
    int x;
    int y;
    node();
    node(u8 c[][MAXN]);
}node;

int manhattan(node& state);
bool judge(u8 cur[][MAXN]);
bool ida_star(node& state,vector<node>&path);
int dfs(vector<node> &path, int g, int bound, int prev);
void PRINT(u8 cur[][MAXN]);

#endif