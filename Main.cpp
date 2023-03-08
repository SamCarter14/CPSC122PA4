/*
Sam Carter
CPSC 122 spring 2023
Date: 3/7/23
Programming Assignment: PA4
Description: This program accepts a list from the user via command line arguments. It then processes the data, figuring out the number of packages and driver name. It then outputs information about the file to the user.
Notes: NA
*/
#include "PA4.h"

// TODO: add parameters to main() for command line args
int main(int argc, char * argv[]) {
	// TODO: your code here
  ifstream inFile;
  string word, truckerName;
  int numPackages = 0, heaviestId;
  double avgWeight, heaviestWeight = 0;

  Package * packages = NULL;
  inFile.open(argv[1], ios::in);
  packages = loadPackages(inFile, &truckerName, &numPackages);
  computePackageStats(packages, numPackages, &heaviestId, &heaviestWeight, &avgWeight);
  delete [] packages;
  packages = NULL;
  displayInformation(inFile, &truckerName, &numPackages, &heaviestId, &heaviestWeight, &avgWeight);

  inFile.close();
	return 0;
}
