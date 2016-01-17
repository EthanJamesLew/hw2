#include "main.h"
#include <fstream>
using namespace std;

bool fileExists(const string& name) {
  ifstream f(name.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }   
}


int main(int argc, char *argv[])
{
	ifstream inData;
	ofstream outData;
	string filename = "";
	string outfile = "";

	double varX;
	double varY;
	double varZ;
	double varW;

	int int1;
	char char1;
	float float1;
	char char2;

	string word1;
	string word2;
	string word3;
	string word4;
	string string1;
	string string2;

	double answer;


	while (true)
	{
		cout << "Enter an input file: ";
		cin >> filename;
		if(fileExists(filename) == false)
		{
			cout << "\nWhoops! That file doesn't exist. ";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter an output file: ";
		cin >> outfile;
		if(fileExists(outfile) == true)
		{
			cout << "\nWhoops! That file exists. ";
		}
		else
		{
			break;
		}
	}
	streamsize ss = cout.precision();

	outData.precision(10);

	inData.open(filename.c_str());
	inData >> varW >> varX >> varY >> varZ >> int1 >> char1 >> float1 >> char2>>word1>>word2>>word3>>word4>>string1>>string2;

	string1 = string1 + " " + string2;

	outData.open(outfile.c_str());

	answer = (4/3)*(M_PI*varX*varY*varZ);
	outData <<"Volume of a sphere: \n" <<answer <<endl; 
	answer = sqrt(pow(varW-varX,2) + pow(varY - varZ, 2));
	outData << "Distance between points (" << varX <<", " << varZ << 
				") and point (" << varW << ", " << varY << "):" << endl << answer <<endl;

	answer = (varY-varZ)/(varW-varX);
	outData << "Slope between points (" << varX <<", " << varZ << 
				") and point (" << varW << ", " << varY << "):" << endl << answer <<endl;

	answer = pow(varX, varY) + pow(varW, varZ) - ((3 + varZ)/(3.45 * varW));
	outData << "Random equation answer: \n";
	outData << answer << endl;

	outData.precision(ss);
	outData << float1 <<" " <<char2<<" "<<int1<<" "<<char1<<endl<<word4<<" "<<word1<<" "<<word3 <<" "<<word2<<" "<<string1<< endl;
	outData << "Ethan Lew hw2"<<endl;

	inData.close();
	outData.close();

	//std::cout.precision(100);

	//cout<<varA<<endl;
	return 0;
}
