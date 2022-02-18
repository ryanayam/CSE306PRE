#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define MAXCHAR 1000
// header variable
bool header = false;

// arguments 
// csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file

int csvF(FILE *f){
        // file comes opened already
        return 0;
}

int csvR(FILE *f){
        // file comes opened already
        return 0;
}

void csvHeader(int c, char **arg) {

        for (int i = 0; i < c; i++) {
                if (arg[i] == "-h") {
                        header = true;
                        return;
                }
        }
        header = false;
        return;
}

void csvRecords(FILE *f, field, value) {
        char row[MAXCHAR];
	char **headerArr[] = {};
        while(feof(f) != true) {
                if (header == true) {
			int i = 0;
			fgets(row, MAXCHAR, f);
			char *token = strtok(row, ",");
			while (token != NULL) {
				headerArr[i] = token;
				i = i + 1;
			}
		}
		fgets(row, MAXCHAR, f);
		char *token = strtok(row, ",");
		count = 0
		while (token != NULL) {
			if (count == atoi(field))
			count = count + 1;
		}
                printf("%s", row);
        }
}

int main(int argc, char **argv) {
	// go through arguments to check which functions need to be ran
	FILE *fp = fopen(argv[argc-1], "r");
	// if we can't find the file then it is an exit failure
	if (fp == NULL){
		printf("File not found. Please try again");
		exit(EXIT_FAILURE);
	}
	
	// set the header variable
	csvHeader(argc, argv);
	// goes through all the arguments to get what we need
	for (int i = 0; i < argc-1; i++) {
		char *argu = argv[i];
		if (strcmp(argu,"-f") == 0) {
			// insert f function
		} else if (strcmp(argu,"-r") == 0) {
			// insert r function
		} else if (strcmp(argu,"-max") == 0) {

		} else if (strcmp(argu,"-min") == 0) {
			
		} else if (strcmp(argu,"-mean") == 0) {
			
		} else if (strcmp(argu, "-records") == 0) {
			csvRecords(fp, argv[i+1], argv[i+2]);
			i = i + 2;
		}
	}
	exit(EXIT_SUCCESS);
	return 0;
}
