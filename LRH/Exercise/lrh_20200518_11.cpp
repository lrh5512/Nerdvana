#include<stdio.h>
#define exernum 2

void my_gets(char* str, int size);
int main()
{
#if exernum == 1
	char small, cap = 'G';
	if ((cap >= 'A') && (cap <= 'Z'))
	{
		small = cap + ('a' - 'A');
	}
	printf("대문자 : %c %c", cap, '\n');
	printf("소문자 : %c", small);
#elif exernum == 2
	char ch1, ch2;
	scanf("%c%c", &ch1, &ch2);
	printf("[%c%c]", ch1, ch2);
#elif exernum == 3
	int ch;
	ch = getchar();
	printf("입력한 문자 : ");
	putchar(ch);
	putchar('\n');
#elif exernum == 4
	char ch;
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf("%c", &ch);
		printf("%c", ch);
	}
#elif exernum == 5
	int res;
	char ch;
	while (1)
	{
		res = scanf("%c", &ch);
		if (res == -1) break;
		printf("%d ", ch);
	}
#elif exernum == 6
	char str[7];
	my_gets(str, sizeof(str));
	printf("입력한 문자열 : %s\n", str);
#elif exernum == 7
	int num, grade;
	printf("학번 입력 : ");
	scanf("%d", &num);
	getchar();
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c", num, grade);
#endif
	return 0;
}
void my_gets(char* str, int size)
{
	int ch;
	int i = 0;
	ch = getchar();
	while ((ch != '\n') && (i < size - 1))
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}
