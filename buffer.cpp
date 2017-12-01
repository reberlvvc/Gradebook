#include<iostream>
#include<vector>
#include<fstream>
class Student
{
public:
	Student(std::string,double);
	void setName(std::string);
	void setGrade(double);
	std::string getName();
	double getGrade();
	char getMark();
private:
	std::string name;
	double grade;
	static const int A = 90;
	static const int B = 80;
	static const int C = 70;
	static const int D = 60;
};
Student::Student(std::string n,double g)
{
	name = n;
	grade = g;
}
void Student::setName(std::string n)
{
	name = n;
}
void Student::setGrade(double g)
{
	grade = g;
}
std::string Student::getName()
{
	return name;
}
double Student::getGrade()
{
	return grade;
}
char Student::getMark()
{
	if(grade >= A)
	{
		return 'A';
	}
	else if(grade >= B)
	{
		return 'B';
	}
	else if(grade >= C)
	{
		return 'C';
	}
	else if(grade >= D)
	{
		return 'D';
	}
	else
	{
		return 'F';
	}
}
class Gradebook
{
public:
	Gradebook(std::string);
	void setName(std::string);
	void addStudent(Student);
	void rmStudent(std::string);
	void rmStudent(int);
	std::string getName();
	int getClassSize();
	Student* getStudent(std::string);
	Student* getStudent(int);
private:
	std::vector<Student> students;
	std::string className;
};
Gradebook::Gradebook(std::string n)
{
	className = n;
}
void Gradebook::setName(std::string n)
{
	className = n;
}
void Gradebook::addStudent(Student s)
{
	students.push_back(s);
}
void Gradebook::rmStudent(std::string n)
{
	for(int i = 0;i < students.size();i++)
	{
		if(n == students[i].getName())
		{
			students.erase(students.begin() + i);
			break;
		}
	}
}
void Gradebook::rmStudent(int i)
{
	students.erase(students.begin() + i);
}
std::string Gradebook::getName()
{
	return className;
}
int Gradebook::getClassSize()
{
	return students.size();
}
Student* Gradebook::getStudent(std::string n)
{
	for(int i = 0;i < students.size();i++)
	{
		if(n == students[i].getName())
		{
			return &students[i];
		}
	}
}
Student* Gradebook::getStudent(int i)
{
	return &students[i];
}
int main(int argc,char ** argv)
{
	Gradebook cppClass("CIS201");
	//./buffer grades.dat
	//^argv[0] ^argv[1]
	if(argc != 2)
	{
		std::cerr << "Error 1: Incorrect Usage" << std::endl;
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		return 1;
	}
	std::ifstream input;
	input.open(argv[1]);
	if(input.fail())
	{
		
		std::cerr << "Error 2: File Access Error" << std::endl;
		std::cerr << "Could not open file: " << argv[1] << std::endl;
		return 2;
	}
	while(!input.eof())
	{
		std::string fname = " ";
		std::string lname = " ";
		double tmpGrd = -1.0;
		input >> fname >> lname >> tmpGrd;
		if(tmpGrd == -1.0)
		{
			std::string wipe;
			std::getline(input,wipe);
			break;
		}
		fname += " ";
		fname += lname;
		Student temp(fname,tmpGrd);
		cppClass.addStudent(temp);
	}
	for(int i = 0;i < cppClass.getClassSize();i++)
	{
		std::cout.width(21);
		std::cout << cppClass.getStudent(i)->getName();
		std::cout.width(6);
		std::cout << cppClass.getStudent(i)->getGrade();
		std::cout.width(2);
		std::cout << cppClass.getStudent(i)->getMark() << std::endl;
		
	}
//	Gradebook cppClass("Cis201");
//	Student logan("Logan Reber",95.0);
//	cppClass.addStudent(logan);
//	std::cout << cppClass.getStudent(0)->getName() << std::endl;
//	Student* logan2 = &logan;
//	double newGrade;
//	std::cout << "Enter new grade: ";
//	std::cin >> newGrade;
//	logan2->setGrade(newGrade);
//	std::cout << logan.getGrade() << " " << logan2->getGrade() << std::endl;
	return 0;
}
