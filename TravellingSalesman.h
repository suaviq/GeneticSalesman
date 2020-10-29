#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream> //including library which allows us to read files 
#include<string>
#include<vector>
using namespace std;

vector<string> dataLoad() { //creating a vector which will hold our data
	ifstream file("data.txt"); //read data from file "data.txt"
	vector<string>dcities; //
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

struct individual {
	vector<int> genes; //genes=cities ex. 0 -> 1 -> 3 -> 2 -> 0
	float fitness; // distance
};


