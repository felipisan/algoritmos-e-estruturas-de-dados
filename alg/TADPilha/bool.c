#include <stdio.h>
#include <stdlib.h>

enum b {
	true = 1:, false = 0
};

typedef enum b bool;

int main() {
	bool var;
	
	var = true;
	if(var) {
		printf("aaa\n");
	}
	
	return EXIT_SUCCESS;
}