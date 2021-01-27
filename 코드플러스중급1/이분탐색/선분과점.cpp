#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
    cin >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Cx >> Cy >> Cz;

    double result = 100000000;

    for (int i = 0; i < 10000; i++)
    {
        double mid1X = Ax + (Bx - Ax) / 3;
        double mid1Y = Ay + (By - Ay) / 3;
        double mid1Z = Az + (Bz - Az) / 3;
        double mid2X = Bx + (Ax - Bx) / 3;
        double mid2Y = By + (Ay - By) / 3;
        double mid2Z = Bz + (Az - Bz) / 3;
        double distance1 = sqrt(pow(Cx - mid1X, 2) + pow(Cy - mid1Y, 2) + pow(Cz - mid1Z, 2));
        double distance2 = sqrt(pow(Cx - mid2X, 2) + pow(Cy - mid2Y, 2) + pow(Cz - mid2Z, 2));
        if (distance1 > distance2)
        {
            Ax = mid1X;
            Ay = mid1Y;
            Az = mid1Z;
            result = distance1;
        }
        else
        {
            result = distance2;
            Bx = mid2X;
            By = mid2Y;
            Bz = mid2Z;
        }
    }
    printf("%.9lf", result);
}