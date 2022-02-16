#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./rpn <input file>\n");		
		return EXIT_FAILURE;
	}

	float result; //stores the result of the calculation.
	bool cond;

	stack *s = malloc(sizeof(stack));

    s->top = NULL;

    FILE *fp = fopen(argv[1], "r");

	cond = processVal(s, fp, &result); //checks to see if expression in valid (example of invalid expression "1 2 3 -")

    if(cond == false){
		fclose(fp);
        printf("Expression is malformed! \n");
        return EXIT_FAILURE;
    }

	printf("%f\n", result);

	fclose(fp);
	freeStack(s);
	
	return EXIT_SUCCESS;
}
