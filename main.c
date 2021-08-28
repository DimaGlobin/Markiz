#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int isEqual(double val1, double val2)
{
    if (val1==NAN && val2==NAN)
        {
            return 1;
        }
    else if (val1==val2)
        {
            return 1;
        }
    else
        {
            return 0;
        }

}
int isZero(double val)
{
    return (fabs(val)<0,001);
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(std::isfinite (a));
    assert(std::isfinite (b));
    assert(std::isfinite (c));

    assert(x1!=NULL);
    assert(x2!=NULL);
    assert(x1!=x2);

    if (isZero(a)==1)
        {
            if (isZero(b))
            {
                return 0;
            }
            else
            {
                *x1=-1*c/b;
                return 1;
            }
        }
    else
        {
            double d=b*b-4*a*c;
            if (d<0)
                {
                    return 0;
                }
            else if (isZero(d)==1)
                {
                    *x1=*x2=-1*b/(2*a);
                    return 1;
                }
            else
                {
                    *x1=(-1*b+sqrt(d))/(2*a);
                    *x2=(-1*b-sqrt(d))/(2*a);
                    return 2;
                }
        }
}

int UnitTest(int nTest, double a, double b, double c, int nRootsref, double x1ref, double x2ref)
{
    double x1=NAN, x2=NAN;
    int nRoots=SolveSquare(a, b, c, &x1, &x2);
    if (!isEqual(x1, x1ref) || !isEqual(x2, x2ref) || !isEqual(nRoots, nRootsref))
        {
            printf("Test %d FAILED\n"
                    "nRoots=%d should be: %d,\n"
                    "x1=%lg should be %lg\n"
                    "x2=%lg Should be: %lg\n",
                    nTest, nRoots, nRootsref, x1, x1ref, x2, x2ref);
            return 0;
        }
    else
        {
            return 1;
        }
}

int RunUnitTest()
{
    int failed=0;
    if(UnitTest(1, 1, 5, -6, 2, 1, -6)==0)
        {
            failed++;
        }
    if(UnitTest(2, 1, 0, -4, 2, 2, -2)==0)
        {
            failed++;
        }
    return failed;
}

int main()
{
    RunUnitTest();
    printf("Enter the a, b, c coefficients: ");
    double a=NAN, b=NAN, c=NAN;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1=NAN, x2=NAN;
    int nRoots=SolveSquare(a, b, c, &x1, &x2);

    if (nRoots==0)
        {
            printf("No roots =/");
        }
    else if (nRoots==1)
        {
            printf("x = %lg", x1);
        }
    else if (nRoots==2)
        {
            printf("x1 = %lg, x2 = %lg", x1, x2);
        }
    return 0;
}
