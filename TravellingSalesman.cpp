#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "TravellingSalesman.h"
#define POPULATION_SIZE 20 
#define N_ITERARTIONS 10
using namespace std;


int main() {
	vector<vector<string>> loaded_data = loadData();
	vector<string> cities = loaded_data[0];

	for (int j = 0; j < cities.size() - 1; j++)
	{
		cout << cities[j] << " ";
	}
	cout << endl << "DO YOU KNOW DE WAE ?????!!??!" << endl;

	vector<vector<double>> data = transMatrix(loaded_data);
	vector<individual> population = generate_population(POPULATION_SIZE, data);
	for (int i = 0; i < N_ITERARTIONS; i++) {
		population = create_new_population(population, data, 0.1);
	}

	for (int j = 0; j < population[0].genes.size() - 1; j++)
	{
		cout << cities[population[0].genes[j]] << "-->";
	}
	cout << cities[population[0].genes[population[0].genes.size() - 1]] << " fitness: " << population[0].fitness << endl;

	return 0;
}
	

