#include "../includes/rtv1.h"

int		main()
{
	t_list *new;
	t_vector *d;

	d = (t_vector *)malloc(sizeof(t_vector));
	d->x = 5.0;
	new = ft_lstnew(d, sizeof(d));
	printf("num: %f\n", ((t_vector *)new->content)->x);

	t_list *new2;
	t_vector p;

	p.x = 6.0;
	new = ft_lstnew(&p, sizeof(p));
	printf("num: %f\n", (*(t_vector *)new->content).x);
	return (0);
}

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

typedef struct	s_queue
{
	t_list		first;
	t_list		last;
	
}				t_queue;

