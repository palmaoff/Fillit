

#include "../includes/fillit.h"

int main()
{
	t_cell		**head;
//	t_cell		*c1;
	t_cell		*cell;
	char		*filename;
	int fd;

//	head = create_header(5);
//	c1 = ft_cellnew(3, 2, 3, 4);
//	c1->pos = 1;
//	test = ft_findhead(c1, head, 25);
//	print_map(head, 5);
//	printf("x: %d y: %d pos: %d\n", c1->x, c1->y, c1->pos);
	filename = "/Users/eflorean/CLionProjects/fillit/input";
	fd = open(filename, O_RDONLY);
	if (!check_input(fd))
	{
		printf("error\n");
		return (0);
	}
	printf("OK\n");
	fd = open(filename, O_RDONLY);
	cell = make_list(fd);
	close(fd);
	head = ft_create_header(4);
	input(head, cell, 4, 4);
    print_map(head, 4);
    ft_print(head, 4);
//  print_cell(cell);
//  ft_alg(head[0], 0, 4, head);
//	print_map(head, 4);
	return (0);
}
