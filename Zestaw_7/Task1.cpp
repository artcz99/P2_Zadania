#include <iostream>

using namespace std;

class Shape {
public:
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	void draw() {
		cout << "  _  " << "\n" << " / \\ " << "\n" << "|   |" << "\n" << " \\ / " << "\n" << "  -  " << endl;
	}
};

class Square : public Shape {
public:
	void draw() {
		cout << " ----" << "\n|    |" <<"\n|    |" << "\n ----" << endl;
	}
};

class Triangle : public Shape {
public:
	void draw() {
		cout << " /\\ " << "\n/  \\" << "\n----" << endl;
	}
};



int main() {
	Circle x2;
	x2.draw();
	Square x3;
	x3.draw();
	Triangle x4;
	x4.draw();
}
