#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>									//including library which allows us to read files 
#include<string>
#include<vector>
using namespace std; 

vector<string> dataLoad() {							//creating a vector which will hold our data
	ifstream file("data.txt");						//read data from file "data.txt"
	vector<string>dcities;			
	string input;
	while (getline(file, input))
	{
		dcities.push_back(input);
	}
	for (string dcity : dcities)
	{
		cout << dcity << endl;
	}
	file.close();
	return dcities;
}

//splitting a sentence into words 
void split(vector<string> dataLoad) 
{
	string word = " ";
	for (auto x : dataLoad) {
		if (x == " ") {
			cout << word << endl;

		}
		else {
			word = word + x;
		}
	}
	cout << word << endl;
}
//                       IS IT WORKING???????                      
//??????????????????????????????????????????????????????????????????????????????????????????????
//ignoring the first line because these are the names of the cities   
vector<string> firstLine() {
	ifstream file("data.txt");						//open file	
	vector<string>dcities;							//setting up a place to store our data read from the file
	string cities;					
	/*Read and throw away the first line simply by doing
	nothing with it and reading again*/
	while (getline(file, cities)) {
		dcities.push_back(cities);
	}
	while (!file.eof()) {							//let's begin 	
		getline(file, cities);						//over write the first line read
		cout << cities << endl;
	}
	file.close();
	return dcities;

}
//???????????????????????????????????????????????????????????????????????????????????????????????

//transforming data from txt into a matrix
void transMatrix(double, double) {
	ifstream file("data.txt");		//open input file
	vector<vector<double>> matrix;	//create matrix as vector of vectors
	int flag;
	string line;					//read file
	while (getline(file, line)) {
		if (!file)						// (but it was IF!) if something went wrong (probably EOF), exit the loop
			break;
		if (line.empty()) {		// IF the line is empty, read row contents into vectorand append flag 1
			flag == 1;
			continue;
			vector<double>row;
			copy(istream_iterator<double>(file),
				istream_iterator<double>(),
				back_inserter(row));
			row.push_back(flag);
		if (flag ==0)				//E L S E 	// else read row contents into vector and append flag 0
			vector<double>row;
		copy(std::istream_iterator<double>(file),
			std::istream_iterator<double>(),
			std::back_inserter(row));
		row.push_back(flag);
		}
	return matrix;					//i     d o n ' t     k n o w    W   T   H

}

struct individual {
	vector<int> genes; //genes=cities ex. 0 -> 1 -> 3 -> 2 -> 0
	float fitness; // distance

};


