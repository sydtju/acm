//拓扑排序是对于有向无环图的遍历 
//图的存储可以使用的是邻接表 邻接矩阵 邻接多重表  
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 110;
const int MAXM = 10010;

int head[MAXN],indegree[MAXM],N,M,T;
struct EdgeNode
{
	int to;
	int w;
	int next;
};
EdgeNode Edges[MAXM];


int toposort()
{
	queue<int> Q;
	int u;
	int Count = 0;
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
			Q.push(i);
		else
			Count++;
	}
	int id = 0;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i = head[u]; i != -1; i = Edges[i].next)
		{
			indegree[Edges[i].to]--;
			if(indegree[Edges[i].to]==0)
			{
				id++;
				Q.push(Edges[i].to);
			}
		}
	}
	if(id < Count)
		return false;
	else
		return true;
}
int main()
{
	int x,y;
	while(cin >> N >> M)
	{
		memset(head,-1,sizeof(head));
		memset(indegree,0,sizeof(indegree));
		for(int i = 0; i < M; i++)
		{
			cin >> x >> y;
			Edges[i].to = y;
			Edges[i].w = 1;
			Edges[i].next = head[x];
			head[x] = i;
			indegree[y]++;
		}
		if(toposort())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
