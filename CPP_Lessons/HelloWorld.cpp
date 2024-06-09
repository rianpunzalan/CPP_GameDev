#include <iostream>
#include <vector>


class Student							//class declaration
{
	std::string m_firstname = "First";	//these are private
	std::string m_lastname = "Name";
	int			m_id	= 0;
	float		m_avg	= 0;
public:
	Student()	{}						//default constructor

	Student(std::string firstname, std::string lastname, int id, float avg) //parameterized constructor
		: m_firstname	(firstname)
		, m_lastname	(lastname)
		, m_id			(id)
		, m_avg			(avg)
	{
	}
										//getters and setters
	float getAvg()						
	{
		return m_avg;
	}

	int getID()
	{
		return m_id;
	}

	std::string getFirst()
	{
		return m_firstname;
	}

	std::string getLast()
	{
		return m_firstname;
	}

	void setAvg(float avg)
	{
		m_avg = avg;
	}

	void setID(int id)
	{
		m_id = id;
	}

	void setFirst(std::string firstname)
	{
		m_firstname = firstname;
	}

	void setLast(std::string lastname)
	{
		m_lastname = lastname;
	}

	void print() const
	{
		std::cout << m_firstname << " " << m_lastname << " ";
		std::cout << m_id << " " << m_avg << "\n";
	}
};
/*
void doMachineLearning(const Data& d) //declared as const to ensure that it will not change
{
	d.getValue()
}
*/

class Course
{
	std::string m_name = "Course";
	std::vector<Student> m_students;
public:
	Course(){}
	Course(const std::string& name)		//string& passes a reference to a string, instead of copying it
		:m_name(name)					// const so the name doesnt change
	{
	}

	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}

	const std::vector<Student>& getStudents() const		//the first const = means what we are returning cannot change
	{													//second const means getStudents will not change the class
		return m_students;
	}

	void pring() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}
};

int main(int argc, char* argv[])
{
	
	/*
	 std::cout << "Hello World!" << std::endl;
	int a = 42;
	int b = 10;

	std::cout << a << b << "\n";		//concatenated
	std::cout << a + b << std::endl;	//added

	std::vector<int> vec;				//vector declaration
	vec.push_back((a));					//putting value inside a vector
	vec.push_back(b);
	vec.push_back(99);

										//go through vector manually.
	std::cout << vec[0] << "\n";		//prints 42
	std::cout << vec[1] << "\n";		//prints 10
	std::cout << vec[2] << "\n";		//prints 99
	std::cout << vec[3] << "\n";		//prints whatever was in the memory at that location
										//unlike arrays, vectors don't check if you gave it a new value


	for(size_t i = 0; i<vec.size(); i++) //"size_t" instead of just "int" is used because vec.size() gives unsigned int
	{									 //logical error might occur when comparing signed to unsigned					
		std::cout << vec[i] << "\n";
	}


	for(int i : vec)					//iterates through vector (for every integer in vector)
	{
		std::cout << i << "\n";
	}

	float c = 1.1f;						//float declaration

	std::vector<float> vec_float;		
	vec_float.push_back((c));
	vec_float.push_back(9.9f);

	for (int i : vec_float)				//converts float into into before printing
	{
		std::cout << i << "\n";			//prints 1, 9
	}

	for (auto a : vec_float)		//does type inference for you.
	{
		std::cout << a << "\n";			//prints 1.1, 9.9
	}

	*/

	Student s1;
	Student s2("Rian", "Punzalan", 1, 95.1f);
	const Student s3("Celine", "Ang", 2, 100.0f);	//notice the const, meaning you dont want this object to change

	Course comp4300("Comp 4300");

	s1.print();

	s2.print();
	s2.setFirst("Rian Karlo");
	s2.print();

	s3.print();							//calling a non-const function on a const object will give a compiler error.
										//solution: put a const on the function

	std::vector<Student> vec_students;	//create a vector of type Student and populate it.
	vec_students.push_back(s1);
	vec_students.push_back(s2);
	vec_students.push_back(s3);
	vec_students.push_back(Student("Cameron", "Bucasas", 1, 99.9f));

	for(Student s : vec_students)		//iterate through the vector and use print function
	{
		s.print();
	}
	return 0;
}
