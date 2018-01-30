#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int createProfile(char* inFile, char* plotTitle, int nbins, int xlow, int xhigh){

	//Instantiate a TProfile object
	testProfile = new TProfile(plotTitle, "Cross-section", nbins, xlow, xhigh);

	//Open the relevant .dat file
	FILE *fp_in;
	fp_in = fopen(inFile,"r");

	//Create a buffer for the first 100 characters of each line
	const int bufferLength = 100;
	char buf[bufferLength];

	//Begin reading lines
	fgets(buf, bufferLength, fp_in);

	//Loop iff a line was successfully read.
	while((fgets(buf,bufferLength,fp_in)) != NULL){

		//Ignore lines that start with comments
		if (buf[0] == '#') continue;

		//Create placeholders for the variables of interest
		double xvar, crossSection, error;

		//Get values from buf
		sscanf(buf, "%lf %lf %lf\n", &xvar,&crossSection,&error);
		
		//Fill the TProfile with the above data
		testProfile->Fill(xvar, crossSection);
	}
}
