#include <iostream>

using namespace std;

class neuron {
	double weight = 0.5;
	double Raznica;
	double correction = 1;
	double Lasterror = 0.0001;
;
public:
	double processInput(double input) {
		return input * weight;
	}
	double Correction() {
		return correction;
	}
	double LastError() {
		return Lasterror;
	}

	void train(double input, double expectedResult) {
		double actualResult = input * weight;
		Raznica = expectedResult - actualResult;
		correction = Raznica / actualResult;
		weight += correction * Lasterror;
		cout << "Actual correction: " << correction << "\tActual result: " << actualResult << endl;
	}
};

int main() {
	int answer;
	neuron fneu;
	while (true) {
		cout << "=====MENU=====" << endl;
		cout << "1) Training" << endl;
		cout << "2) Input" << endl;
		cout << "3) Exit" << endl;
		cout << "Enter: ";
		cin >> answer;
		switch (answer) {
		case 1: {
			double RightOutput, RightInput;
			cout << "Train param. output: " << endl;
			cin >> RightOutput;
			cout << "Train param. input: " << endl;
			cin >> RightInput;
			int i = 0;
			do {
				fneu.train(RightInput, RightOutput);
				i++;
			} while (fneu.Correction() > fneu.LastError());
			cout << "Iterations: " << i << endl;
			break;
		}
		case 2: {
			double input;
			cout << "Input: ";
			cin >> input;
			cout << fneu.processInput(input) << endl;
			break;
		}
		case 3: {
			return 0;
		}
		}
	}
}