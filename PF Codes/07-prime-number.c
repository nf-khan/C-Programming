#include <stdio.h>

void main()
{
  int n;
  printf("insert a number:");
  scanf("%d", &n);

  if (n == 1)
  {
    printf("no its not prime number\n");
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      if (n % i == 0)
        if (i == n)
        {
          printf("yes its prime number\n");
        }
        else
        {
          printf("no its not prime number\n");
          break;
        }
    }
  }
}