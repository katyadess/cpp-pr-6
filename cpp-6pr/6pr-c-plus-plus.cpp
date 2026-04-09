#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <windows.h>
#include <algorithm>
using namespace std;

void program1() {

	vector<string> cars = { "Volvo", "BMW", "Ford", "Mazda", "Peugeot", "Fiat", "Tesla"}; // 1
	for (int i = 0; i < cars.size(); i++) {
		cout << cars[i] << " ";
	} // 2

	cout << endl;

	
	cars.erase(cars.begin());
	cars.erase(cars.end() - 2); // 3

	cars[0] = "Suzuki";
	cars[cars.size() - 3] = "Audi"; // 3

	cout << "Container after changes:\n";
	vector<string>::iterator it;
	for (it = cars.begin(); it != cars.end(); it++) {
		cout << *it << " "; 
	} // 4

	cout << endl;

	vector<string> countries = { "Ukraine", "Italy", "France", "Thailand", "Japan", "Finland", "Netherlands" }; // 5

	int n = 5;
	vector<string>::iterator i = find(cars.begin(), cars.end(), "Ford");
	
	int afterI = cars.end() - (i + 1);
	if (n > afterI) {
		n = afterI;
	}

	if (i != cars.end()) {
		cars.erase(i + 1, i + 1 + n); // 6
	}

	for (it = cars.begin(); it != cars.end(); it++) {
		cout << *it << " ";
	}

	cars.insert(cars.end(), countries.begin(), countries.end()); // 6

	//for (auto i = countries.begin(); i != countries.end(); i++) {
	//	cars.push_back(*i);
	//}

	cout << endl;

	cout << "Cars container: ";

	for (it = cars.begin(); it != cars.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;

	cout << "Countries container: ";
	for (auto i = countries.begin(); i != countries.end(); i++) {
		cout << *i << " ";
	}

}

struct Student {

	string lastName;
	string faculty;

};

void displayStudents(const vector<Student> &students) {
		
	for (auto i = students.begin(); i != students.end(); i++) {
		cout << (*i).lastName << ", faculty: " << (*i).faculty << endl;
	}
}

void program2() {

	vector<Student> students = {
		{"Smith", "IT"},
		{"Johnson", "Finance"},
		{"Brown", "Law"},
		{"Williams", "Engineering"},
		{"Taylor", "Mathematics"},
		{"Anderson", "Biology"},
		{"Thomas", "Physics"},
		{"Davis", "Medicine"},
		{"Wilson", "Architecture"}

	}; // 1

	for (int i = 0; i < students.size(); i++) {
		cout << students[i].lastName << ", faculty: " << students[i].faculty << endl;
	}; // 2

	cout << endl;

	students.erase(students.end() - 1); // 3
	students.erase(students.begin() + 3); // 3
	students[students.size() - 2] = { "Taylor", "Computer Science" }; // 3
	students[1].lastName = "Clark"; // 3

	displayStudents(students); // 4

	vector<Student> newStudents = {
		{"Young", "Architecture"},
		{"Allen", "Biology"},
		{"White", "Chemistry"},
		{"Harris", "Philosophy"}
	}; // 5

	int n = 3;
	string wantedLastName = "Clark";
	auto neededIt = students.end();

	for (auto i = students.begin(); i != students.end(); i++) {
		if ((*i).lastName == wantedLastName) {
			neededIt = i;
			break;
		}
	};

	if (neededIt != students.end()) {

		int afterNeededIt = students.end() - (neededIt + 1);

		if (n > afterNeededIt) {
			n = afterNeededIt;
		}

		students.erase(neededIt + 1, neededIt + 1 + n); // 6
	}

	students.insert(students.end(), newStudents.begin(), newStudents.end()); // 6

	cout << endl;

	displayStudents(students); // 7

	cout << endl;

	displayStudents(newStudents); // 7

	//auto i = find_if(students.begin(), students.end(), 
	//	[wantedLastName] (const Student& s) {
	//		return s.lastName == "Clark";
	//	});
}


int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	program2();
}

