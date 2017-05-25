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


int main(int argc, char* argv[])
{
	int fd;
	ssize_t ret_in, ret_out;
	char buffer[1024];

	fd = open("/dev/ttyUSB0", O_RDWR);

	if (fd == -1) {
		perror("open");

		return 2;
	}

	while ((ret_in = read(fd, &buffer, 1024)) > 0) {
		printf("%s", buffer);
	}

	close(fd);

	return 0;
}
