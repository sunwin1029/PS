#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;
	int multiple;
	int array[15]={0}, i;
	scanf("%d %d %d", &a, &b, &c);
	multiple = a * b * c;
	while(multiple != 0){
		array[multiple%10]++;
		multiple/=10;
	}
	for(i=0;i<10;i++){
		printf("%d\n",array[i]);
	}
}
	