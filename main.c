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
		exit(EXIT_FAILURE)
	}
	int cnt = 0;
	char ch;
	for (int i = 0; i < argc-1; i++) {
		argu = argv[i];
		if (argu == "-f") {
		} else if (argu == "-r") {
			// insert r function
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

int csvR(FILE *f){
	// file comes opened already
	return 0
}
