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

struct Book {

	string title;
	int price;

};
bool operator<(const Book& lhs, const Book& rhs) {
	return tie(lhs.price, lhs.title) < tie(rhs.price, rhs.title);
}


void displayBooks(const vector<Book>& books) {

	for (auto i = books.begin(); i != books.end(); i++) {
		cout << (*i).title << ", price: " << (*i).price << "$" << endl;
	}
}

void program3() {
	vector<Book> books = {
		{"Harry Potter", 250},
		{"The Hobbit", 330},
		{"1984", 70},
		{"Clean Code", 140},
		{"Dune", 400},
		{"War and Peace", 115},
		{"The Alchemist", 150},
		{"Sherlock Holmes", 200},
		{"The Catcher in the Rye", 130},
		{"To Kill a Mockingbird", 160},
		{"Brave New World", 210},
		{"The Lord of the Rings", 400},
		{"Fahrenheit 451", 110}
	}; // 1
	displayBooks(books);
	cout << endl;

	for (int i = 0; i < books.size() - 1; i++) {
		for (int j = 0; j < books.size() - i - 1; j++) {
			if (books[j+1].price > books[j].price) {
				swap(books[j+1], books[j]);
			}
		}
	} // 2

	displayBooks(books); // 3
	cout << endl;

	set<Book> expensiveBooks;
	int expensivePrice = 200;

	for (int i = 0; i < books.size(); i++) {
		if (books[i].price > expensivePrice) {
			expensiveBooks.insert(books[i]);
		}
	} // 4, 5

	for (auto i = expensiveBooks.begin(); i != expensiveBooks.end(); i++) {
		cout << (*i).title << ", price: " << (*i).price << "$" << endl;
	} // 6

	cout << endl;
	
	for (int i = 0; i < books.size() - 1; i++) {
		for (int j = 0; j < books.size() - i - 1; j++) {
			if (books[j].price > books[j+1].price) {
				swap(books[j], books[j+1]);
			}
		}
	} // 7, сет і так відсортований у порядку зростання

	displayBooks(books);
	cout << endl;

	vector<Book> unionContainer;
	unionContainer.insert(unionContainer.end(), books.begin(), books.end());
	unionContainer.insert(unionContainer.end(), expensiveBooks.begin(), expensiveBooks.end()); // 9

	displayBooks(unionContainer); // 10
	cout << endl; 

	int countEl = 0;
	int requirement = 399;
	for (int i = 0; i < unionContainer.size(); i++) {
		if (unionContainer[i].price > requirement) {
			countEl += 1;
		}
	} // 11

	cout << "Count of books, that meet the requirements: " << countEl << endl;

	if (countEl > 0) { // 12
		cout << "в третьому контейнері є елемент, що задовільняє заданій умові (ціна більша за " << requirement << ")" << endl;
	}
	else {
		cout << "в третьому контейнері немає елемента, що задовільняє заданій умові (ціна більша за " << requirement << ")" << endl;
	}
}


int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

}

