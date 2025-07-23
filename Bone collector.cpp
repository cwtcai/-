#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[1005][1005];
int ans[10005];

int main(void)
{
	int n, i, j, b[1005], V, v[1005], h;
	memset(ans, 0, sizeof(ans));
	int I = 0;
	scanf("%d", &h);
	while (h-- && h >= 0)
	{
		I++;
		scanf("%d%d", &n, &V);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= V; j++)
			{
				if (v[i] <= j)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + b[i]);
				else 
					dp[i][j] = dp[i - 1][j];
			}
		}
		ans[I] = dp[n][V];
	}
	for (i = 1; i <= I; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
