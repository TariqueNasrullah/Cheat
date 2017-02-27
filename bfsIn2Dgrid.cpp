#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int cell[100][100];		// Cell[x][y] == -1 then it's blocked
int d[100][100], vis[100][100];  // d is destination from source
int row, col;

void bfs(int sx, int sy)
{
	memset(vis, 0, sizeof(vis));
	vis[sx][sy] = 1;
	queue<pii>q;
	
	q.push(pii(sx, sy));
	
	while(!q.empty())
	{
		pii top = q.front(); q.pop();
		
		for(int k = 0; k < 4; k++)
		{
			int tx = top.first + fx[k];
			int ty = top.second + fy[k];
			
			if(tx >= 0 && tx < row && ty >= 0 && ty < col && cell[tx][ty] != -1 && vis[tx][ty] == 0)
			{
				vis[tx][ty] = 1;
				d[tx][ty] = d[top.first][top.second] + 1;
				q.push(pii(tx, ty));
			}
		}
	}
}


int main()
{
	row = 10;
	col = 10;
	bfs(0, 0);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	return 0;
}
