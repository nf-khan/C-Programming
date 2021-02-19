# include <stdio.h>

//To calculate power
int power(void)
{   int b;
    int c;
    int m;

  printf("Enter first number :");
    scanf("%d", &b);
    printf("Enter second number:");
    scanf("%d",&c);

    m=1;

    for(int i=1; i<=c; i++)
    {
        m=b*m;
        

    }
    return m;
}

void main()
{   
    int p= power();

   printf("%d",p);

}