#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Author : Enes Usta
* Date : 21 / 01 / 2019
*/

char * increment_pointer(char *);
void reverse_string(char *);
void main(int argc, char *argv[]) {

	char *p = argv[1];
	printf(p);
	printf("\n");
	reverse_string(p);



}

void reverse_string(char *arr) {

	arr = increment_pointer(arr);

	printf("\n final addres is : %d\n",arr);
	
	*arr--;

	while(*arr) 
		printf("%c",*arr--);


}

char * increment_pointer(char *p) {
	
	printf("Start address is : %d", p);


	while(*p)
		p++;


	return (char *)p;
}
