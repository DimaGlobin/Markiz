#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    double sqrt1, root1, root2, discr;
    printf("Enter the a, b, c coefficients of the quadratic equation\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a==0)
    {
        printf("The equation is not quadratic!");
    }
    else
    {
        discr=pow(b,2)-4*a*c;
        sqrt1=sqrt(discr);
        if (discr<0)
            {
                printf("No roots");
            }
        else if ((int)discr==0)
            {
                root1=(-1*(double)b)/(2*(double)a);
                printf("The root is: ");
                printf("%f", root1);
            }
        else if (discr>0)
            {
                root1=(-1*(double)b+(double)sqrt1)/(2*(double)a);
                root2=(-1*(double)b-(double)sqrt1)/(2*(double)a);
                printf("The first root: ");
                printf("%g", root1);
                printf("\n The second root is: ");
                printf("%g", root2);
            }
    }
    return 0;
}
