/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:19:19 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/27 17:54:22 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int      count_word(char const *s, char c)
{
        int     count;
        int     i;

        i = 0;
        count = 0;
        while (s[i])
        {
                while (s[i] && s[i] == c)
                        i++;
                if (s[i] && s[i] != c)
                        count++;
                while (s[i] && s[i] != c)
                        i++;
        }
        return (count);
}

static char     *count_and_fill(char const *s, char c)
{
        char    *str;
        int             i;
        int             length;

        length = 0;
        while (s[length] && s[length] != c)
                length++;
        str = (char *) malloc(sizeof(char) * (length + 1));
        if (!str)
                return (NULL);
        i = 0;
        while (i < length)
        {
                str[i] = s[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

static char     **clr_all(char **str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                free(str[i]);
                i++;
        }
        free(str);
        return (NULL);
}

char    **ft_split(char const *s, char c)
{
        char    **str;
        int             i;
        int             length;

        if (!s)
                return (NULL);
        length = count_word(s, c);
        str = (char **) malloc(sizeof(char *) * (length + 1));
        if (!str)
                return (NULL);
        str[length] = NULL;
        i = 0;
        while (i < length)
        {
                while (*s && *s == c)
                        s++;
                str[i] = count_and_fill(s, c);
                if (!str[i])
                        return (clr_all(str));
                while (*s && *s != c)
                        s++;
                i++;
        }
        return (str);
}

// int	count_my_string(char const *s, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == c && s[i])
// 			i++;
// 		if (s[i] && s[i] != c)
// 			count++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	return (count);
// }

// int	count_my_word(char const *s, char c, int *i)
// {
// 	int	count;

// 	count = 0;
// 	while (s[*i] && s[*i] == c)
// 		(*i)++;
// 	while (s[*i] && s[*i] != c)
// 	{
// 		count++;
// 		(*i)++;
// 	}
// 	return (count);
// }

// void	clr_all(char **str, int index)
// {
// 	int	i;

// 	i = 0;
// 	while (i < index)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// void	fill_my_word(char const *s, char *str, int i, int x)
// {
// 	str[x] = '\0';
// 	x--;
// 	while (x >= 0)
// 	{
// 		i--;
// 		str[x] = s[i];
// 		x--;
// 	}
// }

// char	**ft_split(char const *s, char c)
// {
// 	int	x;
// 	int	y;
// 	int	index;
// 	char	**str;
// 	int	i;

// 	y = count_my_string(s, c);
// 	if (!s)
// 		return (0);
// 	str = (char **) malloc(sizeof(char *) * (y + 1));
// 	if (!str)
// 		return (0);
// 	index = 0;
// 	i = 0;
// 	while (index < y)
// 	{
// 		x = count_my_word(s, c, &i);
// 		str[index] = (char *) malloc(sizeof(char) * (x + 1));
// 		if (!str[index])
// 		{
// 			clr_all(str, index);
// 			return (0);
// 		}
// 		fill_my_word(s, str[index], i, x);
// 		index++;
// 	}
// 	str[index] = NULL;
// 	return (str);
// }
