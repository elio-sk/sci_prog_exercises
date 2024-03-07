
#include "university.hpp"

int main()
{
    //Adding a new university
	University u1("TU Wien", "Wien", 200);
	cout << "Name " << u1.getName() << ", location: " << u1.getCity() << ", nr. of students " << u1.getNumStudents() << endl << endl;

	u1.graduate();
	u1.graduate();
	cout << "2 students graduate" << endl;

	cout << "Name " << u1.getName() << ", location: " << u1.getCity() << ", nr. of students " << u1.getNumStudents() << endl << endl;


	cout << "27 new students have been added" << endl;
	for (int i = 0; i < 27; i++)
	{
		u1.newStudent();
	}

	cout << "Name " << u1.getName() << ", location: " << u1.getCity() << ", nr. of students " << u1.getNumStudents() << endl << endl;



    //Add another university to the class University and correction example
	University u2("TU Berlin", "Berlin", 100);
	cout << "Name " << u2.getName() << ", location: " << u2.getCity() << ", nr. of students " << u2.getNumStudents() << endl << endl;


	cout << "67 new students have been added" << endl;
	for (int i = 0; i < 67; i++)
	{
		u2.newStudent();
	}

	cout << "Name " << u2.getName() << ", location: " << u2.getCity() << ", nr. of students " << u2.getNumStudents() << endl << endl;

    cout<<"Oooops previous data was wrong, let's change it"<<endl;
    u2.setNumStudents(200);

    cout << "Name " << u2.getName() << ", location: " << u2.getCity() << ", nr. of students " << u2.getNumStudents() << endl << endl;

	return 0;
}