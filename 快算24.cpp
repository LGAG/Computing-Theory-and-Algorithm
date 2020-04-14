#include <stdio.h>
typedef struct number{
	int Numerator;   //·Ö×Ó 
	int Denominator; //·ÖÄ¸ 
} NUMBER;
NUMBER num[4],temp_num[4];
char oper[3],OP[4]={'+','-','*','/'};
NUMBER exe(NUMBER n1, NUMBER n2, char op){
	NUMBER temp;
	switch (op){
		case '+' :{
			if(n1.Denominator==n2.Denominator){
				temp.Denominator=n1.Denominator;
				temp.Numerator=n1.Numerator+n2.Numerator;
			}
			else{
				temp.Numerator=n1.Numerator*n2.Denominator+n1.Denominator*n2.Numerator;
				temp.Denominator=n1.Denominator*n2.Denominator;
			}
			return temp;
		}
		case '-' :{
			if(n1.Denominator==n2.Denominator){
				temp.Denominator=n1.Denominator;
				temp.Numerator=n1.Numerator-n2.Numerator;
			}
			else{
				temp.Numerator=n1.Numerator*n2.Denominator-n1.Denominator*n2.Numerator;
				temp.Denominator=n1.Denominator*n2.Denominator;
			}
			return temp;
		}
		case '*':{
			temp.Denominator=n1.Denominator*n2.Denominator;
			temp.Numerator=n1.Numerator*n2.Numerator;
			return temp;
		}
		case '/' :{
			if(n2.Numerator*n1.Denominator==0){
				temp.Numerator=28562;
				temp.Denominator=1;
				return temp;
			}
			temp.Denominator=n2.Numerator*n1.Denominator;
			temp.Numerator=n1.Numerator*n2.Denominator;
			return temp;
		}
	}
}
int main(void){
	while(scanf("%d %d %d %d",&num[0].Numerator,&num[1].Numerator,&num[2].Numerator,&num[3].Numerator)!=EOF){
		getchar();
		for(int i=0;i<4;i++){
			num[i].Denominator=1;
		}
		for(int i1=0;i1<4;i1++){
			for(int i2=0;i2<4;i2++){
				for(int i3=0;i3<4;i3++){
					oper[0]=OP[i1];
					oper[1]=OP[i2];
					oper[2]=OP[i3];
					for(int j1=0;j1<4;j1++){
						for(int j2=0;j2<4;j2++){
							if(j1==j2) continue;
							for(int j3=0;j3<4;j3++){
								if(j3==j1||j3==j2)continue;
								for(int j4=0;j4<4;j4++){
									if(j4==j1||j4==j2||j4==j3) continue;
									NUMBER tep[3];
									temp_num[0]=num[j1];
									temp_num[1]=num[j2];
									temp_num[2]=num[j3];
									temp_num[3]=num[j4];
									tep[0]=exe(temp_num[0],temp_num[1],oper[0]);
									if(tep[0].Numerator==28562) goto k1;
									tep[1]=exe(tep[0],temp_num[2],oper[1]);
									if(tep[1].Numerator==28562) goto k1;
									tep[2]=exe(tep[1],temp_num[3],oper[2]);
									if(tep[2].Numerator%tep[2].Denominator==0 && tep[2].Numerator/tep[2].Denominator==24) {
										printf("(%d %c %d) %c %d) %c %d)\n",temp_num[0].Numerator,oper[0],temp_num[1].Numerator,oper[1],temp_num[2].Numerator,oper[2],temp_num[3].Numerator);
										goto l;
									}
									k1:tep[0]=exe(temp_num[0],temp_num[1],oper[0]);
									if(tep[0].Numerator==28562) goto k2;
									tep[1]=exe(temp_num[2],temp_num[3],oper[2]);
									if(tep[1].Numerator==28562) goto k2;
									tep[2]=exe(tep[0],tep[1],oper[1]);
									if(tep[2].Numerator%tep[2].Denominator==0 && tep[2].Numerator/tep[2].Denominator==24){
										printf("(%d %c %d) %c (%d %c %d)\n",temp_num[0].Numerator,oper[0],temp_num[1].Numerator,oper[1],temp_num[2].Numerator,oper[2],temp_num[3].Numerator);
										goto l;
									}
									k2:tep[0]=exe(temp_num[1],temp_num[2],oper[1]);
									if(tep[0].Numerator==28562) goto k3;
									tep[1]=exe(temp_num[0],tep[0],oper[0]);
									if(tep[1].Numerator==28562) goto k3;
									tep[2]=exe(tep[1],temp_num[3],oper[2]);
									if(tep[2].Numerator%tep[2].Denominator==0 && tep[2].Numerator/tep[2].Denominator==24) {
										printf("(%d %c ( %d %c %d ) %c %d)\n",temp_num[0].Numerator,oper[0],temp_num[1].Numerator,oper[1],temp_num[2].Numerator,oper[2],temp_num[3].Numerator);
										goto l;
									}
									k3:tep[0]=exe(temp_num[2],temp_num[3],oper[2]);
									if(tep[0].Numerator==28562) goto k4;
									tep[1]=exe(temp_num[1],tep[0],oper[1]);
									if(tep[1].Numerator==28562) goto k4;
									tep[2]=exe(temp_num[0],tep[1],oper[2]);
									if(tep[2].Numerator%tep[2].Denominator==0 && tep[2].Numerator/tep[2].Denominator==24) {
										printf("(%d %c %d) %c %d) %c %d)\n",temp_num[0].Numerator,oper[0],temp_num[1].Numerator,oper[1],temp_num[2].Numerator,oper[2],temp_num[3].Numerator);
										goto l;
									}
									k4:tep[0]=exe(temp_num[1],temp_num[2],oper[1]);
									if(tep[0].Numerator==28562) goto k5;
									tep[1]=exe(tep[0],temp_num[3],oper[2]);
									if(tep[1].Numerator==28562) goto k5;
									tep[2]=exe(temp_num[0],tep[1],oper[0]);
									if(tep[2].Numerator%tep[2].Denominator==0 && tep[2].Numerator/tep[2].Denominator==24) {
										printf("(%d %c %d) %c %d) %c %d)\n",temp_num[0].Numerator,oper[0],temp_num[1].Numerator,oper[1],temp_num[2].Numerator,oper[2],temp_num[3].Numerator);
										goto l;
									}
									k5:continue;
								}
							}
						}
					}
				}
			}
		}
		printf("no\n");
		continue;
		l:printf("yes\n");
	}
}
