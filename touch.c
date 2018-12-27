#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/*
 * Date : 27 / 12 / 2018
 * Author : Enes USTA
*/

char *current_path(size_t);
char *create_path(char *, char *);
int strcmp_param(char *, char *);
FILE create_file(char *);

typedef struct Path {

	char *location;
} Path;



void main(int argc, char *argv[]) {

	char *buff = "touch";
	

	if(strcmp_param(argv[0],buff) == 0) {

		struct Path *path;
	
		path = (struct Path *)malloc(sizeof(struct Path));
		path->location = create_path(current_path(40),argv[1]);
		create_file(path->location);
	
		free(path);
	
	} else {
		char *buffer = "Incorrect parameter input,\n\t correct usage touch <file-name.file-extension>";
		printf("%s",buffer);
	
	}		
	
		

}

int strcmp_param(char *argv, char *param) {
	
	char *buffer = "Incorrect parameter input,\n\t correct usage touch <file.name>";

	while( *argv++ == *param++ )  
		return 0;	

	return -1;
}

char *current_path(size_t size) {

	char cwd[(int)size];
	char *buff;

	buff = (char *)malloc(sizeof(cwd));

	if(getcwd(buff, sizeof(cwd))!=NULL) {
		//printf("\nCurrent working dir :%s\n",cwd);
		
	} else {
		perror("getcwd() error");
	}
	return (char *)buff;
}

FILE create_file(char *current_path) {


	FILE *file_ptr = fopen(current_path, "w");
	unsigned char kr;
	unsigned long flen,i;
	
	fseek(file_ptr, 0L, 1L);
	flen = ftell(file_ptr);

	for(i=0;i<flen;i++)
		fputc(kr,file_ptr);


	fclose(file_ptr);	

	return *file_ptr;
}

char *create_path(char *cwd,char *append) {

	char *path;


	if((path = malloc(strlen(cwd)+strlen(append)+1)) != NULL ) {
		path[0] = '\0';
		strcat(path,cwd);
		strcat(path,"\\");
		strcat(path,append);
	}else {
	}
	
	return (char *)path;
}












