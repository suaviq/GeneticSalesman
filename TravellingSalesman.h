#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>								
#include<string>
#include<vector>
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

vector<vector<double>> transMatrix(vector<vector<string>> data) {
	vector<vector<double>> trans_matrix;
	for (int i = 1; i < data.size(); i++) {
		vector<double> row;
		for (int j = 0; j < data[i].size(); j++)
			row.push_back((stod(data[i][j])));
		trans_matrix.push_back(row);
	}
	return trans_matrix;
}

struct individual {
	vector<int> genes; //genes=cities ex. 0 -> 1 -> 3 -> 2 -> 0
	float fitness; // distance
};

float get_distance(vector<int> genes, vector<vector<double>> data) {
	float distance;
	/*
	NAPISAÆ FUNKCJE DYSTANSU MIEDZY MIASTAMI
	*/
	return distance;
}

individual generate_individual(vector<vector<double>> data) {
	individual population_member;
	/*NAPISAÆ GENEROWANIE TYPKA*/
	return population_member;
}

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