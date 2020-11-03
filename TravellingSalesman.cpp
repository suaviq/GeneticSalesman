#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "TravellingSalesman.h"
#define POPULATION_SIZE 50 
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
	vector<individual> population = generate_population(POPULATION_SIZE, data);
	cout << "--------------------        population       ---------------------" << endl;
	for (int i = 0; i < POPULATION_SIZE; i++) 
	{
		cout << "genes: ";
		for (int j = 0; j < population[i].genes.size() - 1; j++)
		{
			cout << population[i].genes[j] << "-->";
		}
		cout << population[i].genes[population[i].genes.size() - 1] << " fitness: " << population[i].fitness << endl;
	}
	return 0;

}

