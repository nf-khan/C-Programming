#include <stdio.h>

int main(void)
{
  int n;
  printf("insert a number:");
  scanf("%d", &n);

  if (n == 0)
  {
    printf("1");
  }
  else
  {
    int i = 1;
    int ans = n * i;

    for (i = 1; i < n; i++)
    {
      ans = ans * i;
    }

    printf("%d", ans);
  }
}