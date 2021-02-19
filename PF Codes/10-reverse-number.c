# include <stdio.h>

int main(void)
{
    int n;

    printf("Enter first number :");
    scanf("%d", &n);

    int num=0;
    while(n>0)
    {   int ans=n%10;
        num=num+ans;
        if(n/10==0)

        {
            n=n/10;


            printf("%d",num);


        } else
        {
            num=num*10;
            n=n/10;
        }


    }
    return 0;
}