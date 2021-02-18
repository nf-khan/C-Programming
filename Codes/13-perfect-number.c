#include <stdio.h>

int main(void)
{
  int n;
  printf("insert a number:");
  scanf("%d", &n);

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (n % i == 0)
    {
      sum = sum + i;
    }
  }
  if (sum == n)
  {
    printf("perfect number");
  }
  else
  {
    printf("no");
  }
}