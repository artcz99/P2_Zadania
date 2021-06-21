#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rodent {
public:
	virtual void getName() = 0;

	virtual void getSound() = 0;

	virtual ~Rodent() = default;
};

class Mouse : public Rodent {
	string name = "mouse";
public:
	void getName() override {
		cout << name << "!" << endl;
	}

	void getSound() override {
		cout << "Squeeeeeaak" << endl;
	}

	~Mouse() {
		cout << "Bye bye " << name << "!" << endl;
	}
};

class Gerbil : public Rodent {
	string name = "gerbil";
public:
	void getName() override {
		cout << name << "!" << endl;
	}

	void getSound() override {
		cout << "Purpuprupur" << endl;
	}

	~Gerbil() override {
		cout << "Bye bye " << name << "!" << endl;
	}
};

class Hamster : public Rodent {
	string name = "hamster";
public:
	void getName() override {
		cout << name << "!" << endl;
	}

	void getSound() override {
		cout << "Mrmrmrmmr" << endl;
	}

	~Hamster() override {
		cout << "Bye bye " << name << "!" << endl;
	}
};

class BlueHamster : public Hamster {
	string name = "Blue hamster";
public:
	void getName() override {
		cout << name << "!" << endl;
	}

	void getSound() override {
		cout << "blublublublu" << endl;
	}

	~BlueHamster() override {
		cout << "Bye bye " << name << "!" << endl;
	}
};

int main() {
	auto** arr = new Rodent*[3];
	*(arr + 0) = new Mouse();
	*(arr + 1) = new Gerbil();
	*(arr + 2) = new Hamster();

	for(int i = 0; i < 3; i++) {
		(*(arr + i))->getSound();
	}

	for(int i =0; i < 3; i++) {
		delete (*(arr + i));
	}
	delete[] arr;

	vector<Rodent *> vec;

	vec.push_back(new Mouse());
	vec.push_back(new Gerbil());
	vec.push_back(new Hamster());

	for(auto a : vec) {
		a->getSound();
	}

	for(auto a : vec) {
		delete a;
	}

	auto* blue = new BlueHamster();
	blue->getName();
	blue->getSound();
	delete blue;

	return 0;
}
