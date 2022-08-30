#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open("./get_next_line.h", O_RDONLY);
	while (get_next_line(fd, &line) > 0) {
		printf("%s\n", line);
	}
	close(fd);
	return 0;
}
