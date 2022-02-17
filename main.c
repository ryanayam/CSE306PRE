#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool header = false;
// arguments 
// csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file

int main(int argc, char **argv) {
	// go through arguments to check which functions need to be ran
	FILE *fp = fopen(argv[argc-1], "r");
	if (fp == NULL){
		fprint("File not found. Please try again");
		exit(EXIT_FAILURE);
	};
	for (int i = 0; i < argc-1; i++) {
		argu = argv[i];
		if (argu == "-f") {
			// insert f function
		} else if (argu == "-r") {
			// insert r function
		} else if (argu == "-h") {
			header = true;
		} else if (argu == "-max") {

		} else if (argu == "-min") {
			
		} else if (argu == "-mean") {
			mean(fp, argv[i+1]);
		} else if (argu == "-records") {
			
		};
	};
	exit(EXIT_SUCCESS);
	return 0;
};

int mean(FILE *f, char field[]){
	char line[1024];
	fgets(line, 1024, f);
	int counter = 0;
	char *token = strtok(line, ",");
	while (token != NULL) { // find the index of the given field
		if (token == field) {
			break;
		};
		counter++;
		token = strtok(NULL, ",");
	};
	float total = 0;
	int totalcounter = 0;
    while (fgets(line, 1024, f)) {
        char* tmp = strdup(line);
        char x = getfield(tmp, counter); // grab field value w/ counter
		if (isdigit(x) != 0) { // check if field is numerical
			total += atof(x); // atof converts char to float
			totalcounter++;
		};
        free(tmp);
    };
	float avg = total/totalcounter;
	printf("%f", avg);
	return 0;
};

int csvF(FILE *f){
	// file comes opened already
	return 0;
};

int csvR(FILE *f){
	// file comes opened already
	return 0;
};
