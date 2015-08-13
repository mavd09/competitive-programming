 #include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>

#define MP make_pair
#define PB push_back

using namespace std;

const int MAX=100;

int n, m;
vector<int> graph[MAX];
vector<int> graphr[MAX];
set<int> new_graph[MAX];
int fathers[MAX];
int cnt=1;
bool visited[MAX];
stack<int> nodes;

void dfs(int node)
{
    if(visited[node])
        return ;
    visited[node]=true;
    for(int i = 0; i < graph[node].size(); i++)
        dfs(graph[node][i]);
    nodes.push(node);
}

void bfs(int node)
{
    int father=cnt++;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int hq=q.front();
        q.pop();
        if(fathers[hq] != 0)
            continue;
        fathers[hq]=father;
        for(int i = 0; i < graphr[hq].size(); i++)
            q.push(graphr[hq][i]);
    }
}

set<int> s;

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from].PB(to);
        graphr[to].PB(from);
    }
    
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);
    while(!nodes.empty())
    {
        if(fathers[nodes.top()])
        {
            nodes.pop();
            continue;
        }
        bfs(nodes.top());
        nodes.pop();
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < graph[i].size(); j++)
            if(fathers[graph[i][j]] != fathers[i])
                new_graph[fathers[i]].insert(fathers[graph[i][j]]);
     
    return 0;
}