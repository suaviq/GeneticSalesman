#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>								
#include<string>
#include<vector>
#include<cmath>
#include<random>
using namespace std; 


//splitting a sentence into words 
vector<string> splitStringBySpaces(string dataLoad)
{
	string word = "";
	vector<string> words;
	for (int i = 0; i < (int)(dataLoad.length()); i++) {
		if (dataLoad[i] == ' ') {
			words.push_back(word);
			word = "";
		}
		else {
			word = word + dataLoad[i];
		}
	}
	return words;
}

//creating 2D vector for our matrix and creating matrix
vector<vector<string>> loadData() {
	ifstream file("data.txt");
	vector<vector<string>> matrix;
	if (!file) {
		cout << "Cannot open file" << endl;
		return matrix;
	}
	string cities;
	while (getline(file, cities)) {
		vector<string> data_row = splitStringBySpaces(cities);
		matrix.push_back(data_row);
	}
	file.close();
	return matrix;
	
}

//transforming and putting our data into a matrix
vector<vector<double>> transMatrix(vector<vector<string>> data) {
	vector<vector<double>> trans_matrix;
	for (int i = 1; i < data.size(); i++) {
		vector<double> row;
		for (int j = 0; j < data[i].size(); j++)
			row.push_back((stod(data[i][j])));		//conversing string to double
		trans_matrix.push_back(row);
	}
	return trans_matrix;
}

//GENETIC ALGORITHM 
struct individual {
	vector<int> genes; //genes=cities ex. 0 -> 1 -> 3 -> 2 -> 0
	double fitness = 0; // distance
};

double get_distance(vector<int> genes, vector<vector<double>> data) {
	double dist = 0;				//distance
	/*this function has to read values from our matrix
				Warszawa Krakow Katowice Poznan 
	coordinate: 0.		1.		2.		3.
	0.			0		20		30		40 
	1.			20		0		35		60 
	2.			30		35		0		21 
	3.			40		60		21		0		*/
	/*wzi¹æ to z wektora genes?*/
					//row
					//col
	for (int i = 0; i < genes.size() - 1; i++)
	{
		dist += data[genes[i]][genes[i+1]];			//returning value from matrix equals to distance between to cities
	}
	return dist;					
}

//losujemy liczbê ze zbioru genes, dodajemy j¹ do setu i usuwamy j¹ z genes aby siê nie powtarza³a przy nastêpnym losowaniu
vector<int> generate_genes(int n) {
	vector<int> genes;
	vector<int> set;

	for (int i = 1; i < n; i++) {
		set.push_back(i);
	}
	genes.push_back(0);
	for (int i = 1; i < n ; i++) {
		int index = rand() % set.size();
		genes.push_back(set[index]);
		set.erase(set.begin() + index);
	}
	genes.push_back(0);
	return genes;
}


individual generate_individual(vector<vector<double>> data) {
	individual population_member;
	population_member.genes = generate_genes((int)data.size());
	population_member.fitness = get_distance(population_member.genes, data);
	return population_member;
}

//w main napisac 10% wygenerowanej populacji

vector<individual> generate_population(int population_size, vector<vector<double>> data) {
	vector<individual> population;
	for (int i = 0; i < population_size; i++) {
		population.push_back(generate_individual(data));
	}
	return population;
}

individual generate_mutated_kid(individual parent) {
	individual mutated_kid;

	/*NAPISAÆ DZIECKO*/


	return mutated_kid;
}