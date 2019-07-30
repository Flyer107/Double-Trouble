//Asks user for integer input.
//Counts the number of even and odd inputs.
//Finds the largest and smallest inputs.
//Created by Kwesi Owubah on 07/25/2019.

#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>
using namespace std;

//Function prototype(s)
pair<int, int> evenNodd(vector< vector<int> >);
pair<int, int> smallNlarge(vector< vector<int> >);

//Function for printing the insides of the double vector
void print(std::vector<int> v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << ' ';
		std::cout << '\n';
	}
}

int main()
{
	//Obtain size of the vector
	int n = 0;
	cout << "Enter the root of the wanted number of input: (Enter 3 for 9 elements)" << endl;
	cin >> n;

	//Declare double vector
	vector< vector<int> > doubleVect;

	//Loop to receive and store integers
	int input;
	for (int i = 0; i < n ; i++) {
		vector<int> temp;
		input = 0;
		for (int k = 1; k < n +1 ; k++) {
			cout << "Next Number: ";
			cin >> input;
			temp.push_back(input);
		}
		doubleVect.push_back(temp);
	}

	//Print contents of double vector
	for (int i = 0; i < doubleVect.size(); i++) {
		print(doubleVect[i]);
	}

	int fEven, fOdd;
	int fSmall, fLarge;
	tie(fEven, fOdd) = evenNodd(doubleVect);
	tie(fSmall, fLarge) = smallNlarge(doubleVect);

	cout << "You entered " << fEven << " even elements, and " << fOdd << " odd elements." << endl;
	cout << "The smallest number you entered was " << fSmall << " and the largest was " << fLarge << "." << endl;

	system("pause");
	return 0;
}// end of main function

//***********Function Definitions ******************
pair<int, int> evenNodd(vector< vector<int> > v) {
	int even = 0, odd = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < v[i].size(); k++) {
			if (v[i][k] & 1)
				odd++;
			else
				even++;
		}
	}
	return make_pair(even, odd);
}

pair<int, int> smallNlarge(vector< vector<int> > v) {
	int small = v[0][0], large = v[0][0];
	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < v[i].size(); k++) {
			if (small > v[i][k])
				small = v[i][k];
			if (large < v[i][k])
				large = v[i][k];
		}
	}
	return make_pair(small, large);
}