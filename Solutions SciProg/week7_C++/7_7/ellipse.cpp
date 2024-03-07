#include "ellipse.hpp"

int main()
{
    // add an ellipse to the class Ellipse
    Ellipse e1(0, 0, 2, 1);
    cout << "The ellipse's center has coordinates (" << e1.getXCenter() << ", " << e1.getYCenter() << ")." << endl;
    cout << "The ellipse's semiaxis a is " << e1.getA() << "." << endl;
    cout << "The ellipse's semiaxis b is " << e1.getB() << "." << endl;
    cout << "The ellipse's eccentricity is " << e1.getEccentricity() << "." << endl;
    e1.printFocalPoints();
    e1.isInside(1, 2);
    e1.isCircle();
    cout << endl << endl;


    
    return 0;    
}

