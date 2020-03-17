#include <stdio.h> 
#include <iostream>
int m[102][102] = { 0 };
int s[102][102] = { 0 };
int Right[102] = { 0 };
int Left[102] = { 0 };
int p[102] = { 0 };
int ANS=0;
using namespace std;
void MatrixChain(int *p, int n) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int Traceback(int i, int j) {
	if (i == j) {
		return 0;
	}

	//cout << "Multiply A " << i << ", " << s[i][j] << " and A " << (s[i][j] + 1) << ", " << j << endl;
	
	if (s[i][j] != i) {
		Left[i]++;
		Right[s[i][j]]++;
	}
	if (s[i][j] + 1 != j) {
		Left[s[i][j] + 1]++;
		Right[j]++;
	}
	return Traceback(i, s[i][j])+Traceback(s[i][j] + 1, j)+p[i-1]*p[s[i][j]]*p[j];
}
int main(void) {
	int N;
	scanf("%d", &N);
	getchar();
	
	for (int i = 0; i <= N; i++) {
		scanf("%d", &p[i]);
		getchar();
	}
	MatrixChain(p, N);
	printf("%d\n(",Traceback(1, N));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= Left[i]; j++) {
			printf("(");
		}
		printf("A%d", i);
		for (int j = 1; j <= Right[i]; j++) {
			printf(")");
		}
	}
	cout << ")" << endl;
}
