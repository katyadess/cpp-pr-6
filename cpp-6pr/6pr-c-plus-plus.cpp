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


int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	program1();
}

