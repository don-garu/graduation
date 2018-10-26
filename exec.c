#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc == 1)
		return 0;

	char par[1024] = "./parallel/main_3 ";
	char seq[1024] = "./sequential/main_3 ";

	char *arg = argv[1];
	printf("%s\n", arg);
	if (system(strcat(par, arg)) == 1)
		fputs("parallel error detected", stderr);
	if (system(strcat(seq, arg)) == 1)
		fputs("sequentail error detected", stderr);


	return 0;
}
