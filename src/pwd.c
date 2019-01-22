#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * Author : Enes USTA
 * Date : 22 / 01 / 2019
 *
 */

char *cwd(unsigned int);
int xstrcmp(char *,char *);
int main(int argc, char *argv[]) {

	char *buff = "pwd.exe";
	char *error = "Incorrect parameter input ";

	if(xstrcmp(argv[0],buff) == 0) 
		printf("\n%s",cwd(150));
	else
		printf("%s",error);	
}

char *cwd(unsigned int size) {
	
	char *buff;
	buff = (char *)malloc(size);
	
	getcwd(buff,size);

	return (char *)buff;
}

int xstrcmp(char *argv, char *param) {

	while(*argv++ == *param++)
		return 0;	

	return -1;
}
