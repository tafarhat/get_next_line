#include "gnl.h"
#include <fcntl.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;

	int fd = open(argv[1], O_RDONLY);
	char *str = NULL;
	int ret = 0;

	while ((ret = gnl(fd, &str)))
	{	
		ft_putendl(str);
		ft_strdel(&str);
	}
	
	ft_putendl(str);
	ft_strdel(&str);

	return 0;
}
