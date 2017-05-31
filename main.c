#ifdef __unix__         

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32) 

#define OS_Windows

#include <stdio.h>
#include <stdlib.h>

#endif

int fd;

void game_loop()
{
	char key = 0;
	char buff[1024] = {0};
	
	printf("Starting game loop...\n\n");
	
	/* use system call to make terminal send all keystrokes directly to stdin */
	system ("/bin/stty raw");

		write(fd, "abcdefg", 7);
	/*while ((key = getchar()) != '.') {

		if (write(fd, &key, 1) > 0) {
			printf(" <- Sent !\n", key);
			if (read(fd, &buff, 1024))
				printf("%s", buff);
		} else {
			printf("Error sending %c \n", key);
		}

		sleep(3000);
	}*/
}

int main(int argc, char* argv[])
{
	ssize_t ret_in, ret_out;
	char buffer[1024];

	fd = open("/dev/ttyUSB0", O_RDWR);

	if (fd == -1) {
		perror("open");

		return 2;
	}

	game_loop();
	
	close(fd);

	return 0;
}
