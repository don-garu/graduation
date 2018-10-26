#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc == 1)
		return 0;

	FILE* fp = fopen("/home/jjun/graduation/result/result.txt", "w");
	fclose(fp);
	// file delete

	char par[1024] = "/home/jjun/graduation/parallel/main_3 ";
	char seq[1024] = "/home/jjun/graduation/sequential/main_3 ";

	char *arg = argv[1];
//	printf("%s\n", arg);
	if (system(strcat(par, arg)) == 1)
		fputs("parallel error detected", stderr);
	else
		fputs("parallel execution completed\n", stdout);
	if (system(strcat(seq, arg)) == 1)
		fputs("sequentail error detected", stderr);
	else
		fputs("sequential execution completed\n", stdout);
	if (system("python3 chart.py") == 1)
		fputs("charting error detected", stderr);
	else
		fputs("charting completed\n", stdout);

	return 0;
}
