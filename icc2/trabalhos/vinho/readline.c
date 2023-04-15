#include <stdlib.h>
#include <stdio.h>


#define READLINE_BUFFER 4096

char *readline(FILE *stream){
	char *string = 0; 	
	int pos = 0; 		

	do {
		if (pos % READLINE_BUFFER == 0) {
			string = (char *) realloc(string, 
				(pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
		}
		string[pos] = (char) fgetc(stream);	
	}
	while (string[pos++] != '\n' && !feof(stream));
	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	return string;
}


int main (int argc, char *argv[]){
	FILE *file_pointer; //Stack 8 bytes
	char *string;		

	if(argc != 2){
		printf("usage: %s filename\n", argv[0]);
		exit(0);
	}

	// fopen -> Comando que vem da stdio
	file_pointer = fopen(argv[1], "r"); 	// "r" read/leitura
						// "w" write/escrita
						// "r+" read-and-write
						// "w+" se o arquivo existir, truncate
	//string = readline(stdin);
	while(!feof(file_pointer)) {  		//feof => function end of file
		string = readline(file_pointer);
		printf("%s\n", string);
		free(string);
	}
		
	fclose(file_pointer);                   // fechar o arquivo que foi aberto

	return 0;
}
