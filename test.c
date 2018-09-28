#include "libft/includes/libft.h"
#include <stdio.h>

int		main(void)
{
	char	*line;

	ft_putstr("enter the number: ");
	get_next_line(0, &line);
	printf("%s\n", line);
	return (0);
}