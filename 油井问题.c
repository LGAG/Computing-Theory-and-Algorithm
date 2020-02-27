#include <stdio.h>

int wells[200001];
int min[200001];
int max[200001];

int find(int start, int end, int rank, int target, int a[]);

int main(void) {
	int x,y;
	int count=1;
	while(scanf("%d,%d",&x,&y) != EOF) {
		wells[count] = y;
		count++;
	}
	x = find(1,count-1,0,count/2,wells);
	if(count%2==1) {
		y=find(1,count-1,0,count/2+1,wells);
		if(x%2 == 1 && y%2 == 1) printf("%d\n",x/2+y/2+1);
		else if(x%2 == 0 && y%2 == 0) printf("%d\n",x/2+y/2);
		else printf("%d.5\n",x/2+y/2);
	} 
	printf("%d\n",x);
	system ("pause");
}

int find(int start, int end, int rank, int target, int a[]) {
	int count1=1,count2=1,count3=1;
	int b= a[(start + end)/2];
	for(int i=start; i<=end; i++) {
		if(a[i]<b) min[count1++]=a[i];
		else if(a[i]>b) max[count2++]=a[i];
		else count3++;
	}
	if(rank + count1-1 >= target) find(1, count1-1, rank, target, min);
	else if(rank + count1-1 + count3-1 < target) find(1, count2-1, rank + count1-1 + count3-1, target, max);
	else return b;
}
