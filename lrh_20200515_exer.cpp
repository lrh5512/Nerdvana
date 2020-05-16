#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int sum(int x, int y);
double aver(double* a, double k)
{
   double temp = 0;
   for (int i = 0; i < k; i++)
   {
      temp += *(a + i);
   }
   return temp / k;
}

void print_aver(double* a, double k)
{
    double temp = 0;
    for (int i = 0; i < k; i++)
    {
        temp += *(a + i);
    }
    printf("평균 : %.2lf\n", temp / k);
}

void print_max(double *a,int k)
{
   double temp = INT_MIN;
   for(int i = 0;i<k;i++) 
      if (temp <= *(a+i))
      {
         temp = *(a+i);
      }
   printf("최댓값 : %.2lf\n", temp);
}
void print_min(double *a,int k)
{
   double temp = INT_MAX;
   for (int i = 0; i < k; i++)
      if (temp >= *(a + i))
      {
         temp = *(a + i);
      }
   printf("최솟값 : %.2lf\n", temp);
}
void print_stdev(double* a, int k, double aver)
{
   double temp = 0;
   for (int i = 0; i < k; i++)
   {
      temp += pow((*(a + i)) - aver,2);
   }
   temp /= k;
   printf("표준편차 : %.2lf\n", sqrt(temp));
}
int main()
{
#if 1
   int i, k;
   double* num = NULL;
   double input[11] = { 0 };
   printf("입력할 숫자의 갯수를 입력하세요 : ");
   scanf("%d", &k);
   for (i = 0; i < k; i++)
   {
      printf("%d번 값 : ", i+1);
      scanf("%lf", &input[i]);
   }
   
   num = input;
   double av = aver(num, k);
   print_max(num,k);
   print_min(num, k);
   print_aver(num, k);
   print_stdev(num, k, av);

#else

#endif
   return 0;
}
