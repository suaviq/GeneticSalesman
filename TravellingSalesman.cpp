#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "TravellingSalesman.h"
#define POPULATION_SIZE 100
#define N_ITERARTIONS 10
using namespace std;

/**                     mister Dudzik's code                    */
static void show_usage(std::string name)
{
	std::cerr << "Usage: " << name << "<option(s)> SOURCES"
		<< "Options:\n"
		<< "\t-h,--help\t\tShow this help message\n"
		<< "\t-o,--output FILE_PATH\tSpecify the output path\n"
		<< "\t-i,--input FILE_PATH\tSpecify the input path\n"
		<< std::endl;
}

void printArgs(int argc, char** argv)
{
	std::cout << "You have entered " << argc
		<< " arguments:" << "\n";

	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << "\n";

	std::cout << "\n\n\n";
}

int main(int argc, char* argv[])
{

	printArgs(argc, argv);

	if (argc < 5) {
		show_usage(argv[0]);
		return 1;
	}

	std::string input, output;
	for (int i = 1; i < argc; i++)
	{
		auto argument = std::string(argv[i]);
		if (argument == "-i" || argument == "--input")
		{
			input = argv[i + 1];
			std::cout << "Input: " << input << "\n";
		}
		else if (argument == "-o" || argument == "--output")
		{
			output = argv[i + 1];
			std::cout << "Output: " << output << "\n";
		}
	}
	
	std::cout << "Done\n";


	/**Loading data from txt file to vector**/
	vector<vector<string>> loaded_data = loadData(input);
	vector<string> cities = loaded_data[0];

	/**Writing out cities*/
	for (int j = 0; j < cities.size(); j++)
	{
		cout << cities[j] << " ";
	}
	cout << endl << "Do you know the route?" << endl;
	/**Transforming and putting our data into a form of matrix.*/
	vector<vector<double>> data = transMatrix(loaded_data);
	/**Generating first population*/
	vector<individual> population = generate_population(POPULATION_SIZE, data);
	for (int i = 0; i < N_ITERARTIONS; i++)
	{
		/**next - creating new popuation of our solutions*/
		population = create_new_population(population, data, 0.1);
	}
	/**Algorithm will optimize the route and tell us how we should go*/
	for (int j = 0; j < population[0].genes.size() - 1; j++)
	{
		cout << cities[population[0].genes[j]] << "-->";
	}
	cout << cities[population[0].genes[population[0].genes.size() - 1]] << " fitness: " << population[0].fitness << endl;
	/**reading our output to txt file*/
	ofstream out(output); 
	/**almost the same "for" as above-mentioned for but reading output to txt*/
	for (int j = 0; j < population[0].genes.size() - 1; j++) 
	{
		out << cities[population[0].genes[j]] << "-->";
	}
	out << cities[population[0].genes[population[0].genes.size() - 1]] << " fitness: " << population[0].fitness << endl;

	out.close();

	return 0;
}
	

