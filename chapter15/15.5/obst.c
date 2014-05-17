#include <stdio.h>
#define n 5

int main(int argc, char **argv)
{
	double p[n+1] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
	double q[n+1] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
	double e[n+2][n+1], w[n+2][n+1], root[n+1][n+1], t;
	int i;
	for (i = 1; i <= n+1; i++) {
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	int l, j, r;
	for (l = 1; l <= n; l++) {
		for (i = 1; i <= n-l+1; i++) {
			j = i+l-1;
			e[i][j] = 1000.0;
			w[i][j] = w[i][j-1]+p[j]+q[j];
			for (r = i; r <= j; r++) {
				t = e[i][r-1] + e[r+1][j] + w[i][j];
				if (t < e[i][j]) {
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	printf("the answer is e[1,5] = %f\n",e[1][5]);
}
