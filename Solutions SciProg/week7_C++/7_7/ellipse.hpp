#ifndef _ELLIPSE_
#define _ELLIPSE_
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class Ellipse
{
private:
    double center[2];
    double a;
    double b;

public:
    Ellipse(double center[2], double a, double b)
    {
        this->center[0] = center[0];
        this->center[1] = center[1];
        this->a = a;
        this->b = b;
    }


    // return the pointer to the center
    double* getCenter()
    {
        return center; // note that we cannot return center directly, because it is a pointer
    }


    double getXCenter()
    {
        return center[0];
    }

    double getYCenter()
    {
        return center[1];
    }


    double getA()
    {
        return this->a;
    }

    double getB()
    {
        return this->b;
    }


    bool setCenter(double center[2])
    {
        this->center[0] = center[0];
        this->center[1] = center[1];
        return true;
    }

    bool setA(double a)
    {
        this->a = a;
        return true;
    }

    bool setB(double b)
    {
        this->b = b;
        return true;
    }

    bool isInside(double x, double y)
    {
        if (pow((x - center[0]) / a, 2) + pow((y - center[1]) / b, 2) <= 1)
        {
            cout << "The point is inside the ellipse." << endl;
            if (pow((x - center[0]) / a, 2) + pow((y - center[1]) / b, 2) == 1)
            {
                cout << "The point lies on the ellipse." << endl;
            }
            return true;
        }
        else
        {
            cout << "The point is not inside the ellipse." << endl;
            return false;
        }
    }

    bool isCircle()
    {
        if (a == b)
        {
            cout << "The ellipse is a circle." << endl;
            return true;
        }
        else
        {
            cout << "The ellipse isn't a circle." << endl;
            return false;
        }
    }

    void printFocalPoints()
    {

        if (abs(a) > abs(b))
        {
        double focalPoint1[2] = {center[0] + sqrt(a * a - b * b), center[1]};
        double focalPoint2[2] = {center[0] - sqrt(a * a - b * b), center[1]};
        cout << "Focal points of the ellipse:" << endl;
        cout << "Focal point 1: (" << focalPoint1[0] << ", " << focalPoint1[1] << ")" << endl;
        cout << "Focal point 2: (" << focalPoint2[0] << ", " << focalPoint2[1] << ")" << endl;
        }

        else if (abs(a) < abs(b))
        {
        double focalPoint1[2] = {center[0], center[1] + sqrt(b * b - a * a)};
        double focalPoint2[2] = {center[0], center[1] - sqrt(b * b - a * a)};
        cout << "Focal points of the ellipse:" << endl;
        cout << "Focal point 1: (" << focalPoint1[0] << ", " << focalPoint1[1] << ")" << endl;
        cout << "Focal point 2: (" << focalPoint2[0] << ", " << focalPoint2[1] << ")" << endl;
        }

        else
        {
        cout << "Ellipse is a circle and both focal points correspond to the center with coordinates: (" << center[0] << ", " << center[1] << ")." << endl;
        }

    }

    double getEccentricity()
    {
        return sqrt(1 - pow(min(a,b) / max(a,b), 2));
    }
};

#endif



