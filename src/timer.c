#include <stdio.h>
#include <stdlib.h>
#define DELAY 128000


struct time {
	int hours;
	int minutes;
	int seconds;
};


void display(struct time *);
void update(struct time *t);
void delay(void);

void main(int argc,char *argv[]) {

	struct time systime;

	systime.hours=0;
	systime.minutes=0;
	systime.seconds=0;

	for(;;) {
		update(&systime);
		display(&systime);
		if(systime.hours==atoi(argv[1])
				&& systime.minutes==atoi(argv[2])) {
			system("cmd.exe /c \"C:\\AIMP\\AIMP.exe C:\\Users\\Enes\\Desktop\\file.mp3\"");
			break;
		}
	}	


}

void update(struct time *t) {
	
	t->seconds++;
	if(t->seconds==60) {
		t->seconds = 0;
		t->minutes++;
	}
	if(t->minutes==60) {
		t->minutes =0;
		t->hours++;
	}
	if(t->hours==24) t->hours=0;
	delay();
}
void display(struct time *t) {

	printf("%02d:",t->hours);
	printf("%02d:",t->minutes);
	printf("%02d\n",t->seconds);
}
void delay(void) {
	long int t;
	for(t =1 ; t < DELAY; t++);
}
