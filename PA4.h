/*
Sam Carter
CPSC 122 spring 2023
Date: 3/7/23
Programming Assignment: PA4
Description: This program accepts a list from the user via command line arguments. It then processes the data, figuring out the number of packages and driver name. It then outputs information about the file to the user.
Notes: NA
*/
#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

Package * loadPackages(ifstream&, string *, int *);

void displayInformation(ifstream&, string *, int *, int *, double *, double *);

void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
// TODO: add your additional function prototypes here


#endif
