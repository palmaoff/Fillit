#include <stdio.h>
#include "fillit.h"
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	line = NULL;
	fd = open("input", O_RDONLY);
	if (!check_input(fd))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("OK\n");
//	close(fd);
//	fd = open("input", O_RDONLY);
//	make_list(fd);
	
	return (0);
}
