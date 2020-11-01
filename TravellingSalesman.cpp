#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "TravellingSalesman.h"
using namespace std;
using namespace std;


int main() {
	vector<string> data = dataLoad();		//reading data from txt file
	split(data);							//splitting sentence into words by " "
	vector<string> firstLine();				//ignoring first line since they're names of the cities
	transMatrix(data);								//transforming data into a matrix SOMETHING IS WRONG WIOENCOWNCWNVOCDS


	return 0;

}

