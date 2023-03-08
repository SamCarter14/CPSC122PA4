/*
Sam Carter
CPSC 122 spring 2023
Date: 3/7/23
Programming Assignment: PA4
Description: This program accepts a list from the user via command line arguments. It then processes the data, figuring out the number of packages and driver name. It then outputs information about the file to the user.
Notes: NA
*/
#include "PA4.h"

// TODO: finish the functions and define/call additional functions
/*
Function: loadPackages()
Date Created: 3/4/23
Date last modified: 3/4/23
Description: This function figures out the number of packages, driverName and returns a filled dynamically allocated array of packages
Input parameters:ifstream& inFile
Returns:string * driverName, int * numPackages, packages (dynamically allocated)
Pre: Must have file from user
Post: Returns number of packages, driverName and filled array.
*/
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
  int num;
  string word, trashbin;
  double numDec;
  *numPackages = 0;
  getline(inFile, *driverName);
  getline(inFile, trashbin);
 while(!inFile.eof()){
   getline(inFile, word);
    *numPackages += 1;
  }
  *numPackages /= 6;

  inFile.clear();
  inFile.seekg(0);
  getline(inFile, word);
  getline(inFile, word);
  
  Package * packages = new Package[*numPackages];

  for(int i = 0; i < *numPackages; i++){
  inFile >> num;
  packages[i].id = num;
  inFile >> numDec;
  packages[i].weight = numDec;
  inFile >> num;
  packages[i].width = num;
  inFile >> num;
  packages[i].length = num;
  inFile >> num;
  packages[i].height = num;
//
  }

	return packages;
}
/*
Function: computePackageStats()
Date Created: 3/5/23
Date last modified: 3/5/23
Description: This function calculates the average weight, heaviest weight and heaviest id.
Input parameters: const Package packages[], const int numPackages, 
Returns: int * heaviestId, double * heaviestWeight, double * avgWeight
Pre: Must have processed file information to find numPackages
Post: Returns package stats
*/
void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
  double total = 0;
	for(int i = 0; i < numPackages; i++){
    total += packages[i].weight;
    if(*heaviestWeight < packages[i].weight){
      *heaviestWeight = packages[i].weight;
      *heaviestId = packages[i].id;
    }
  }
  *avgWeight = total / numPackages;
}

/*
Function: displayInformation
Date Created: 3/5/23
Date last modified: 3/5/23
Description: This function displays information about the packages to the user
Input parameters: ifstream& inFile, string * driverName, int * numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight
Returns: Information to the user through console
Pre: Must have processed information to get averages
Post: Returns info to user
*/
void displayInformation(ifstream& inFile, string * driverName, int * numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
  inFile.clear();
  inFile.seekg(0);
  string word;
  getline(inFile, word);
  cout << "Number of packages in " << word << "'s truck: " << *numPackages << endl << endl;
  cout << "Package Information" << endl << "-------------------" << endl << endl;
  for(int i = 0; i < *numPackages; i++){
    getline(inFile, word);
    getline(inFile, word);
    cout << "Package ID: " << word << endl;
    getline(inFile, word);
    cout << "Package Weight: " << word << endl;
    getline(inFile, word);
    cout << "Package Width: " << word << endl;
    getline(inFile, word);
    cout << "Package Length: " << word << endl;
    getline(inFile, word);
    cout << "Package Height: " << word << endl << endl;

  }
    cout << "Package Stats" << endl;
    cout << "-------------" << endl << endl;
    cout << "ID of heaviest package: " << *heaviestId << endl;
    cout << "Heaviest weight on truck: " << *heaviestWeight << endl;
    cout << "Average weight of packages on truck: " << *avgWeight << endl;
}



