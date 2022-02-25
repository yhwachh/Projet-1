
#include "libft.h"


void	*ft_calloc(size_t count, size_t size)
{
	void	*room;

	room = (void *)malloc(size * count);
	if (room != NULL)
		ft_bzero(room, size * count);
	return (room);
}
