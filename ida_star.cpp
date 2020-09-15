#include "ida_star.h"

node::node(u8 c[][MAXN])
{
    for(int i = 0;i < MAXN;++i)
    {
        for(int j = 0;j < MAXN;++j)
        {
            cur[i][j] = c[i][j];
        }
    }
}

const int dx[MAXN]={0,0,1,-1};
const int dy[MAXN]={1,-1,0,0};
int s[64] = {0};

void PRINT(u8 cur[][MAXN])
{
    for(int i = 0;i < MAXN;++i)
    {
        for(int j = 0;j < MAXN;++j)
        {
            printf("%2d ",cur[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int manhattan(node& state)
{
    int ans = 0;
    for(int i = 0;i < MAXN;++i)
    {
        for(int j = 0;j < MAXN;++j)
        {
            if(state.cur[i][j] != 0)
            {
                ans += abs((state.cur[i][j]-1)/MAXN-i) + abs((state.cur[i][j]-1)%MAXN-j);
            }
            else
            {
                state.x = i;
                state.y = j;
            }
        }
    }
    return ans;
}

bool judge(u8 cur[][MAXN])
{
    int T[15][15] = {0}, e_y = 0, e_x = 0;
    int N = 0;
    bool occur[16] = {false};
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (T[y][x] == 0)
            {
                e_y = y;
                e_x = x;
            }
            else
            {
                N += count(occur + 1, occur + T[y][x], false);
                occur[T[y][x]] = true;
            }
        }
    }
    return ((N + (e_y + 1)) & 1) == 0;
}

bool ida_star(node& state,vector<node>&path)
{
    int bound = manhattan(state);
    path.push_back(state);
    while(true)
    {
        int t = dfs(path, 0, bound, 0);
        if(t == -1)
        {
            printf("Done\n");
            return true;
        }
        if(t == 0x7fffffff)
        {
            printf("failed\n");
            return false;
        }
        bound = t;
    }
}

int dfs(vector<node> &path, int g, int bound, int prev)
{
    node back = path.back();
    int f = g + manhattan(back);
    if(f > bound) return f;
    if(f == g) return -1;                    //FOUND
    if(f == 0x7fffffff) return 0;
    int min = 0x7fffffff;
    for(int i = 0;i < MAXN;++i)
    {
        if (!(!prev || i != (s[prev - 1] ^ 1)))
        {
            continue;
        }
        s[prev] = i;
        int nowx = back.x + dx[i];
        int nowy = back.y + dy[i];
        if(nowx<0||nowx>=4) continue;
        if(nowy<0||nowy>=4) continue;
        node nowstate(back.cur);
        // PRINT(nowstate.cur);
        swap(nowstate.cur[nowx][nowy], nowstate.cur[back.x][back.y]);
        // PRINT(nowstate.cur);
        nowstate.x = nowx;
        nowstate.y = nowy;
        path.push_back(nowstate);
        int t = dfs(path,g+1,bound,prev+1);
        if(t == -1)  return t;
        if(t < min) min = t;
        path.pop_back();
    }
    return min;
}