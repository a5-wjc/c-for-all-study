/*A struct (structure) is a user-defined composite data type 
that allows you to group variables of different types 
under a single name.*/

#include<iostream>

using namespace std;

//Method 1: Define the struct first, then create variables (most common)
struct Student
{
	char name[20];
	int age;
	float score;
	
};

//Method 2: Create variables while defining the struct
struct Student1
{
	string name;
	int age;
	float score;
} s1, s2;// Variables s1 and s2 created right at the struct definition

//Method 3: Anonymous struct (no struct name)
struct 
{
	string name;
	int age;
	float score;
} s3;   // Variables can only be created here; the type cannot be reused later*/

//5. Struct Arrays
struct Student3
{
	string name;
	int age;
	float score;
};

// Create and initialize a struct array
Student cls[3] = 
{
	{"Zhang San3", 20, 95.5},
	{"Li Si",     21, 88.0},
	{"Wang Wu",   19, 76.5}
};

//6. Structs as Function Parameters

//Method 1: Pass by value (copies the entire struct)
void printStudent(Student s) 
{
	cout << s.name << ", " << s.age << " ";
	s.age = 99; // Modifies the copy only; the original is unchanged
	cout << s.age << endl; 
	/*
	The age is only changed now, 
	and it gets destroyed as soon as the function ends
	*/
}
/*
Pros: Safe, original data is untouched
Cons: Expensive for large structs due to copying
*/

//Method 2: Pass by address (pass a pointer)
void printStudent1(Student* p) 
{
	cout << p->name << ", " << p->age << " ";
	p->age = 999;  // Modifies the original variable
	cout << p->age << endl;
}
/*
Pros: Efficient, no copy
Cons: Risk of accidentally modifying the original
*/

//Method 3: Pass by reference (recommended in C++)
void printStudent2(const Student& s)//put the s1 and then s is an alias of s1
{
	cout << s.name << ", " << s.age << endl;
	// s.age = 99;  Compile error — const forbids modification
}
/*
The recommended approach in C++: Clean syntax (uses .), efficient (no copy), 
and const prevents accidental modification.
*/

//---s *p &s these three comparisons---------
/*
1.Passing by value will copy everything, which uses memory and takes time
2.Points to a different address, but passing a null pointer (nullptr) can be risky and cause crashes
3.A reference just gives an alias; the memory points to the same block.
   s can only be changed internally by itself
*/

//------------there is an important thing-----------
struct Date 
{
	int year;
	int month;
	int day;
};

struct Student4 {
	string name;
	int age;
	Date birthday;   // A member that is another struct
};

void print_4 {
	Student s = {"张三", 20, {2005, 6, 15}};
	
	cout << s.birthday.year << "年"
	<< s.birthday.month << "月"
	<< s.birthday.day << "日" << endl;
    // Output: 2005-6-15
}

int main(void)
{
	Student s1 = {"Zhang San1", 20, 95.5};
	/*Using the . operator (for regular variables)*/
	cout << s1.name << endl;   // Access a member
	s1.age = 21;               // Modify a member
	cout << s1.age << endl;    // Output: 21
	
	/*Using the -> operator (for pointer variables)*/
	Student s2 = {"Zhang San2", 20, 95.5};
	Student* p = &s2;	       // p is a pointer to s2
	
	cout << "for s2" << endl; 
	cout << p->name << endl;   // Access with ->
	(*p).score = 56; 		   // Modify with ->
	p->age = 22;               // Modify with ->
	
	// Equivalent form: (*p).name
	cout << (*p).name << " " << p->score << ' ' << p->age << endl;  // Exactly the same as p->name
	
	// Iterate and access
	for (int i = 0; i < 3; i++) {
		cout << "Name: " << cls[i].name
		<< ", Age: " << cls[i].age
		<< ", Score: " << cls[i].score << endl;
	}
	
	// Range-based for loop (C++11)
	for (const auto& s : cls) {
		cout << s.name << endl;
	}
	cout << "-----" << endl;
	printStudent(s1);	
	cout << "-----" << endl;	
	printStudent1(&s1);//remeber to getna the address (using &) 
}
