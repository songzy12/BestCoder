#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

const int MAX = 10240;

int nBlack, nWhite;
bool pVisited[MAX];
vector<int> pMap[MAX];

void dfs(int x, int c);

int main()
{
    ios::sync_with_stdio(false);
    int T, N, M;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        int u, v;
        nBlack = nWhite = 0;
        memset(pVisited,false, sizeof(pVisited));
        cin >> N >> M;
        for(int i = 1; i <= N; i++)
        { pMap[i].clear(); }
        for(int i = 1; i <= M; i++)
        {
            cin >> u >> v;
            pMap[u].push_back(v);
            pMap[v].push_back(u);
        }
        dfs(1, 0); //still, only one connected component?
        if(nBlack + nWhite < N)
        {
            N -= (nBlack + nWhite);
            if(nBlack < nWhite)
            {
                if(nWhite - nBlack <= N)
                {
                    N -= (nWhite - nBlack);
                    nBlack = nWhite;
                }
                else
                {
                    nBlack += N;
                    N = 0;
                }
            }
            else if(nBlack > nWhite)
            {
                if(nBlack - nWhite <= N)
                {
                    N -= (nBlack - nWhite);
                    nWhite = nBlack;
                }
                else
                {
                    nWhite += N;
                    N = 0;
                }
            }
            nBlack += N / 2; nWhite += N / 2;
            if(N & 1) { nBlack++; }
        }
        cout << nBlack * nWhite - M << endl;
    }
    return 0;
}

void dfs(int x, int c)
{
    pVisited[x] = true;
    if(c == 0) { nBlack++; }
    else { nWhite++; }
    int sz = pMap[x].size();
    for(int i = 0; i < sz; i++)
    {
        int v = pMap[x][i];
        if(!pVisited[v]) // only when not visited
        {
            if(c == 0) { dfs(v, 1); }
            else { dfs(v, 0); }
        }
    }
}