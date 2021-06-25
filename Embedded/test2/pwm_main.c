#include <stdio.h>
#include "pwm.h"
#include <unistd.h>
#include "pwm_music.h"

int main(int argc, char const *argv[])
{
	int fd, i;

	fd = pwm_init();

	for(i = 0; i < sizeof(MumIsTheBestInTheWorld) / sizeof(Note); i ++){
		beep_setfre(fd, MumIsTheBestInTheWorld[i].pitch);
		usleep(MumIsTheBestInTheWorld[i].pitch * 50);
		beep_off(fd);
	}


	close(fd);




	return 0;
}