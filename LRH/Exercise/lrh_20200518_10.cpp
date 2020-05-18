#include<stdio.h>
#define exernum 1

void print_ary(int* pa);
void print_ary(int* pa,int size);
void input_ary(double* pa, int size);
double find_max(double* pa, int size);
int main()
{
#if exernum==1
	int ary[3];
	int i;
	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;
	printf("세 번째 배열 요소에 키보드 입력 : ");
	scanf("%d", ary + 2);
	for (i = 0; i < 3; i++)
	{
		printf("%5d", *(ary + i));
	}
#elif exernum == 2
	int ary[3];
	int* pa = ary;
	int i;
	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];
	for (i = 0; i < 3; i++)
	{
		printf("%5d", pa[i]);
	}
#elif exernum==3
	int ary[3] = { 10,20,30 };
	int* pa = ary;
	int i;
	printf("배열의 값 : ");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", *pa);
		pa++;
	}
#elif exernum == 4
	int ary[5] = { 10,20,30,40,50 };
	int* pa = ary;
	int* pb = pa + 3;
	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;
	printf("pb - pa : %u\n", pb - pa);
	printf("앞에 있는 배열 요소의 값 출력 : ");
	if (pa < pb)
	{
		printf("%d\n", pa);
	}
	else
		printf("%d\n", *pb);
#elif exernum == 5
	int ary[5] = { 10,20,30,40,50 };
	print_ary(ary);
#elif exernum == 6
	int ary1[5] = { 10,20,30,40,50 };
	int ary2[7] = { 10,20,30,40,50,60,70 };
	print_ary(ary1, 5);
	printf("\n");
	print_ary(ary2, 7);
#elif exernum == 7
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);
	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최댓값 : %.1lf\n", max);

#endif
	return 0;
}
void print_ary(int* pa)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d", pa[i]);
	}
}
void print_ary(int* pa, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}
void input_ary(double* pa, int size)
{
	int i;
	printf("%d개의 실수값 입력 : ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%lf", pa + i);
	}

}
double find_max(double* pa, int size)
{
	double max;
	int i;
	max = pa[0];
	for (i = 0; i < size; i++)
	{
		if (pa[i] > max) max = pa[i];
	}
	return max;
}
