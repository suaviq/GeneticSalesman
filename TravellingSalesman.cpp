#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "TravellingSalesman.h"
using namespace std;


int main() {
	vector<vector<string>> loaded_data = loadData();		
	for (int i = 0; i < loaded_data.size(); i++)
	{
		for (int j = 0; j < loaded_data[i].size(); j++)
		{
			cout <<"row " << i  << " col " << j << " val " << loaded_data[i][j] << endl;
		}
	}
	vector<string> cities = loaded_data[0];
	vector<vector<double>> data = transMatrix(loaded_data);
	cout << "-------------------- data in form of matrix ---------------------" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << "row " << i << " col " << j << " val " << data[i][j] << endl;
		}
	}
	return 0;

}

