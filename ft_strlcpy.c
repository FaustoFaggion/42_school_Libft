#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	
	if(!src && !dest)
		return(0);
	i = 0;
	if(dstsize == 0)
		return(ft_strlen(src));
	while(dstsize > 1)
	{
		if(dest[i] != '\0' && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dstsize--;
	}
		dest[i] = '\0';
	
	return(ft_strlen(src));
}