#include "libft.h"
#include <stdio.h>

static size_t	ft_ptr_count(char const *s, char c);
static char	**make_tab(char *s, char *c);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_ptr;
	size_t	len_ptr;
	size_t	i;

	make_tab(s, c);
	i = 0;
	while (i < nb_ptr)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			len_ptr = 0;
			while (s[len_ptr] != c && s[len_ptr] != 0)
				len_ptr++;
			tab[i] = ft_substr(s, 0, len_ptr);
			if (tab[i] == NULL)
			{
				while ((int)i >= 0)
				{
					free(tab[i]);
					tab[i] = NULL;
					i--;
				}
				free(tab);
				tab = NULL;
				return (tab);
			}
			s = s + len_ptr;
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

static char	**make_tab(char *s, char *c)
{
	if (!s)
		return (NULL);
	nb_ptr = ft_ptr_count(s, c);
	tab = (char **)malloc(((sizeof(char *)) * (nb_ptr + 1)));
	if (!tab)
		return (NULL);
	return (tab);
}

static size_t	ft_ptr_count(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{	
			nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (nb);
}
