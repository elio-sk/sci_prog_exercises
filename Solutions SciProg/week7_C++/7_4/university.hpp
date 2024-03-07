// Pedro Paixão

#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class University
{
private:
	string name;
	string city;
	int num_students;

public:
	University(string name, string city, int num_students)
	{
		this->name = name;
		this->city = city;
		this->num_students = num_students;
	}

	int getNumStudents()
	{
		return num_students;
	}

	string getName()
	{
		return name;
	}

	string getCity()
	{
		return city;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setCity(string city)
	{
		this->city = city;
	}

	void setNumStudents(int num_students)
	{
		this->num_students = num_students;
	}

	void newStudent()
	{
		num_students=num_students+1;
	}

	void graduate()
	{
		assert(num_students > 0);
		num_students=num_students-1;
	}

};

int main();

#endif