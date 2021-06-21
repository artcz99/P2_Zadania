#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aircraft {
public:
	virtual void getMaxCapacity() = 0;

	virtual void getMaxFuelTank() = 0;

	virtual void loadPlane() = 0;

	virtual void refuelPlane() = 0;

	virtual void readyToSetOff() = 0;
};

class Passanger : public Aircraft {
	int max_capacity = 120;
	int max_fueltank = 150;
	int cur_capacity = 0;
	int cur_fueltank = 0;
public:
	void getMaxCapacity() {
		cout << max_capacity << endl;
	}

	void getMaxFuelTank() {
		cout << max_fueltank << endl;
	}

	void loadPlane() {
		if(max_capacity != cur_capacity) {
			cout << max_capacity - cur_capacity << " passangers entered the aircraft!" << endl;
			cur_capacity = max_capacity;
		} else {
			cout << "The plane is already full!" << endl;
		}
	}

	void refuelPlane() {
		if(max_fueltank != cur_fueltank) {
			cout << max_fueltank - cur_fueltank << " liters of gasoline were pumped!" << endl;
			cur_fueltank = max_fueltank;
		} else {
			cout << "Planes fueltank is already full!" << endl;
		}
	}

	void readyToSetOff() {
		if(max_fueltank == cur_fueltank && max_capacity == cur_capacity) {
			cout << "The passanger plane is ready to fly away" << endl;
		} else {
			cout << "The passanger plane is NOT ready to fly away :(" << endl;
		}
	}

};

class Cargo : public Aircraft {
	int max_capacity = 500;
	int max_fueltank = 250;
	int cur_capacity = 100;
	int cur_fueltank = 50;
public:
	void getMaxCapacity() {
		cout << max_capacity << endl;
	}

	void getMaxFuelTank() {
		cout << max_fueltank << endl;
	}

	void loadPlane() {
		if(max_capacity != cur_capacity) {
			cout << max_capacity - cur_capacity << " kilograms of cargo loaded to the aircraft!" << endl;
			cur_capacity = max_capacity;
		} else {
			cout << "The plane is already full!" << endl;
		}
	}

	void refuelPlane() {
		if(max_fueltank != cur_fueltank) {
			cout << max_fueltank - cur_fueltank << " liters of gasoline were pumped!" << endl;
			cur_fueltank = max_fueltank;
		} else {
			cout << "Planes fueltank is already full!" << endl;
		}
	}

	void readyToSetOff() {
		if(max_fueltank == cur_fueltank && max_capacity == cur_capacity) {
			cout << "The cargo plane is ready to fly away" << endl;
		} else {
			cout << "The cargo plane is NOT ready to fly away :(" << endl;
		}
	}
};

class Tower {
public:
	vector<Aircraft *> aircrafts;

	void checkAllAircrafts() {
		for(auto a : aircrafts) {
			a->readyToSetOff();
		}
	}

	void refuelAllAircrafts() {
		for(auto a : aircrafts) {
			a->refuelPlane();
		}
	}

	void loadAllAircrafts() {
		for(auto a : aircrafts) {
			a->loadPlane();
		}
	}

	~Tower() {
		for(auto a : aircrafts) {
			delete a;
		}
	}
};


int main() {
	Tower tower;
	tower.aircrafts.push_back(new Cargo());
	tower.aircrafts.push_back(new Passanger());

	tower.checkAllAircrafts();
	tower.loadAllAircrafts();
	tower.checkAllAircrafts();
	tower.aircrafts[0]->refuelPlane();
	tower.checkAllAircrafts();
	tower.refuelAllAircrafts();
	tower.checkAllAircrafts();

	return 0;
}
