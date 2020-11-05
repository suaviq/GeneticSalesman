#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>								
#include<string>
#include<vector>
#include<cmath>
#include<random>
#include<algorithm>
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

//creating 2D vector for our matrix
vector<vector<string>> loadData(string input) {
	ifstream file(input);	//opening the file 
	vector<vector<string>> matrix;
	if (!file) {
		cout << "Cannot open file" << endl;
		return matrix;
	}
	string cities;
	while (getline(file, cities)) {		//reading file line by line
		vector<string> data_row = splitStringBySpaces(cities);
		matrix.push_back(data_row);			//adding lines to vector
	}
	file.close();					
	return matrix;
	
}

//transforming and putting our data into a form of matrix (ignoring first line)
vector<vector<double>> transMatrix(vector<vector<string>> data) {
	vector<vector<double>> trans_matrix;
	for (int i = 1; i < data.size(); i++) {			//we have to start from 1 because first line is the names of the cities
		vector<double> row;
		for (int j = 0; j < data[i].size(); j++)
			row.push_back((stod(data[i][j])));		//conversing string to double
		trans_matrix.push_back(row);
	}
	return trans_matrix;
}

//GENETIC ALGORITHM 
struct individual {
	vector<int> genes;				//genes=cities ex. 0 -> 1 -> 3 -> 2 -> 0
	double fitness = 0;				// distance
};

double get_distance(vector<int> genes, vector<vector<double>> data) {
	double dist = 0;				//distance starting from 0 
	/*this function has to read values from our matrix
				Warszawa Krakow Katowice Poznan 
	coordinate: 0.		1.		2.		3.
	0.			0		20		30		40 
	1.			20		0		35		60 
	2.			30		35		0		21 
	3.			40		60		21		0		*/
	for (int i = 0; i < genes.size() - 1; i++)		//last city is 0 and our salesman returns back so we have to substract 1
	{												//returning value from matrix equals to distance between to cities
		dist += data[genes[i]][genes[i+1]];	
	}
	return dist;					
}

//GENERATING GENES 
/*we randomly choose number from our set, then we are adding it to the set 
and deleting it from genes so it won't reduplicate at the next draw*/

vector<int> generate_genes(int n) {			// n - number of cities 
	vector<int> genes;		
	vector<int> set;			//tworzymy osobny zbiór aby póŸniej usuwaæ z niego dane

	for (int i = 1; i < n; i++) {		//czytanie zbioru danych w set
		set.push_back(i);			
	}
	genes.push_back(0);		// 0 bo zaczynamy od miasta zero
	for (int i = 1; i < n ; i++) {
		int index = rand() % set.size();	/*generowanie randomowych rozwi¹zañ do genes 
											indexy s¹ generowane na podstawie aktualnej d³ugoœci zbioru*/
		genes.push_back(set[index]);
		set.erase(set.begin() + index);		//zapobieganie reduplikacji
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

/*MUTATION which looks like that: example: from 1 --> 2 --> 4 --> 3 --> 1 to 1 --> 3 --> 4 --> 2 --> 1*/
vector<int> swap(vector<int> genes, int index1, int index2) {
	int gene_1 = genes[index1];
	genes[index1] = genes[index2];
	genes[index2] = gene_1;
	return genes;
}


individual generate_mutated_kid(individual parent, vector<vector<double>> data) {
	individual mutated_kid;
	/* mutated kid:
		> we take one population member (one of many solutions to solve the problem)
		and we change the order of the cities in this solution (mutation)
		> example: from 1 --> 2 --> 4 --> 3 --> 1 to 1 --> 3 --> 4 --> 2 --> 1
		> mutated kid = new solution */
	int index1 = 1 + rand() % (parent.genes.size() - 2); // 1 from beginning to ommit start city and -2 to ommit end city (Warszawa in our case)
	int index2 = 1 + rand() % (parent.genes.size() - 2);
	mutated_kid.genes = swap(parent.genes, index1, index2);
	mutated_kid.fitness = get_distance(mutated_kid.genes, data);
	return mutated_kid;
}

//w main napisac 10% wygenerowanej populacji



vector<individual> generate_population(int population_size, vector<vector<double>> data) {
	vector<individual> population;
	for (int i = 0; i < population_size; i++) {
		population.push_back(generate_individual(data));
	}
	return population;
}

bool compare_by_fitness(const individual& a, const individual& b) //porównuje individuals, aby sort wiedzia³, który jest wiêkszy
{
	return a.fitness < b.fitness;
}

vector<individual> create_new_population(vector<individual> population, vector<vector<double>> data, double n_parents = 0.1) {

	/* Math:
	1. population.size() = x
	2. sort population
	3. calculate 0.1*x = n
	4. if n is not a double, round up
	5. take first n population members
	6. mutate each member (n - 1) times (to return to original size of the population)
	! first and the last city in vector has to stay the same ! */

	int x = population.size();
	int n = n_parents * x;
	sort(population.begin(), population.end(), compare_by_fitness); //sorting values in population vector
	vector<individual> bestMembers(&population[0], &population[n]); //zwraca wektor od pocz¹tku do n czyli rodziców
	cout << "best member of current population : " << bestMembers[0].fitness << endl;
	for (int i = 0; i < n; i++) {	//parents
		for (int j = 0; j < (x - n)/n; j++) /*generating kids for each parent (x - n)/n means for example:
											population size = x = 100
											n = 10% *x = 10
											(x - n)/n = (100-10)/10 = 9 = kids*/
		{
			bestMembers.push_back(generate_mutated_kid(bestMembers[i], data)); 
		}
	}
	return bestMembers;

}


