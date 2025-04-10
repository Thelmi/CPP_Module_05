#include <iostream>
#include <sstream>

class Person
{
	public:
		int age;
		std:: string name;
		int *p;
		Person(int Age, std:: string Name, int value)
			: age(Age), name(Name)
			{
				p = new int(value);
			}
		void display()
		{
			std:: cout << age << " " << name << " " << *p << std:: endl;
		}

		Person(Person &other)
		{
			age = other.age;
			name = other.name;
			p = new int(*other.p);
		}

		Person &operator=(const Person& other)
		{
			if (this != &other)
			{
				delete p;
				age = other.age;
				name = other.name;
				p = new int(*other.p);
			}
			return *this;
		}
		std:: ostream &operator<<(std:: ostream& os)
		{
			os << "name: "<< name << " Age: " << age << "Fav number: " << *p << std::endl; 
			return os;
		}
		Person *create_person(int Age, std:: string Name, int Value)
		{
			Person *bro = new Person(Age , Name, Value);
			return bro;
		}

		~Person()
		{
			std:: cout << "destructor is called " << std:: endl;
			delete p;
		}
		void cleanup()
		{
			delete p;
			p = nullptr;
		}
};

//std:: ostream &operator<<(std:: ostream& os, const Person& other)
//{
//	os << "name: " << other.name << " Age: " << other.age << " Fav number: " << *other.p << std::endl; 
//	return os;
//}

int main()
{
	Person CEO(22, "Taha", 10);
	Person CTO(23, "Maaz", 11);
	Person *CPO = CEO.create_person(23, "Maaz", 11);

	//std:: ostringstream out_string;
	//out_string << CEO;
	//std:: cout << CEO;
	
	//CEO.display();
	//std:: string result = out_string.str();
	//std:: cout << result;
	//CPO->display();
	//delete CPO;
	//CTO.display();
}