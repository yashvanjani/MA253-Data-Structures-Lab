//Include header for string handling
#include <string>
using namespace std;

//Define the structure to store record
//Name of the structure should be 'student'
//It should have two elements
// one element should have name 'roll' and type 'int
// another element should have name 'id' and type string

// write your code here
struct student
	{
		int roll;
		string id;
	};

//Declare a function named 'sort' which takes two arguments and return nothing
//The first argument is an array of 'student' datatype
//Second argument is the length of the array
//This func should sort the array based on the 'id' of the students

// write your code here
void sort(student [], int);