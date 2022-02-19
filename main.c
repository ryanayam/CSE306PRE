#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool header = false;
// arguments 
// csv [-frh] [-max field] [-min field] [-mean field] [-records field value] file

// joyce
int csvF(FILE *f){
	// file comes opened already
  int cnt = 0;
  char str[61];
  
  if(f == NULL){
    printf("File not found. Please try again");
  }
  else{
    while(fgets(str, 61, f)!= NULL){
      if(str == ','){
	cnt = cnt + 1;
      }
      else{
	break;
      }
    } 
    fclose(f);
    printf("%d", cnt + 1);
  }
  return (0);
}

// terry
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

// ryan
void csvRecords(FILE *f, char *field, char *value) {
	// only works for field input "0" right now
	char row[MAXCHAR];
	while(feof(f) != true) {
		fgets(row, MAXCHAR, f);
		char *toPrint = strdup(row);
		char *token = strtok(row, ",");
		int col = atoi(field);
		
		if (col == 0 && strcmp(field, "0") == 0) {
			int count = 0;
			while (token != NULL) {
				//go to next column
				if (count == col && strcmp(token, value) == 0) {
					printf("%s", toPrint);
					token = NULL;
				} else {
					token = strtok(NULL, ",");
					count = count + 1;
				}
			}
		} else if (col > 0) {
			printf("%d", col);
			int count = 0;
			while (token != NULL) {
				print("%s", token);
				if (count == col && strcmp(token, value) == 0) {
					printf("%s", toPrint);
					token = NULL;
				} else {
					//go to next column
					token = strtok(NULL, ",");
					count = count + 1;
				}
			}
		} else {
			// anything with a string field
		}
	}
}

int main(int argc, char **argv) {
	// go through arguments to check which functions need to be ran
	FILE *fp = fopen(argv[argc-1], "r");
	if (fp == NULL){
		fprint("File not found. Please try again");
		exit(EXIT_FAILURE)
	}
	for (int i = 0; i < argc-1; i++) {
		argu = argv[i];
		if (argu == "-f") {
			// insert f function
		} else if (argu == "-r") {
			// anita
		       if (header == true){
		          row_number = 0;
			  chara = getchar(fp);
			  while (chara != EOF && chara == '\n') {
			    row_number += 1; 
			  }	 
		       }
		       printf("%d",row_number - 1);
		} else if (argu == "-h") {
			header = true;
		} else if (argu == "-max") {

		} else if (argu == "-min") {
			
		} else if (argu == "-mean") {
			
		} else if (argu == "-records") {
			
		}
	}
	exit(EXIT_SUCCESS)
	return 0
}
