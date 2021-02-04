/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 18:40:24 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 20:44:40 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sudoku.h"

int				carre(struct s_point a, char **argv)
{
	int		i;
	int		j;
	char	tab[10];

	i = -1;
	while (++i < 9)
		tab[i] = '1' + i;
	tab[i] = '\0';
	i = a.x - 3;
	while (i < a.x)
	{
		j = a.y - 3;
		while (j < a.y)
		{
			if (argv[i][j] != '.')
			{
				if (tab[argv[i][j] - '0' - 1] == '*')
					return (1);
				tab[argv[i][j] - '0' - 1] = '*';
			}
			j++;
		}
		i++;
	}
	return (0);
}

int				test_grille_initiale5(struct s_point *tab, char **argv)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (i < 3)
	{
		j = 3;
		while (j <= 9)
		{
			tab[k].y = j;
			j += 3;
			k++;
		}
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (carre(tab[i], argv) == 1)
			return (1);
		i++;
	}
	return (0);
}

int				test_grille_initiale4(char **argv)
{
	int				i;
	int				j;
	int				k;
	struct s_point	tab[9];

	i = 4;
	k = 0;
	while (i <= 10)
	{
		j = 0;
		while (j < 3)
		{
			tab[k].x = i;
			j++;
			k++;
		}
		i += 3;
	}
	return (test_grille_initiale5(tab, argv));
}

int				test_grille_initiale3(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = 0;
	while (i < 9)
	{
		k = 1;
		j = 1;
		while (k < 9)
		{
			c = argv[j][i];
			while (j < 9)
			{
				if (c == argv[j + 1][i] && c != '.' && argv[j + 1][i] != '.')
					return (1);
				j++;
			}
			k++;
			j = k;
		}
		i++;
	}
	return (0);
}

int				test_grille_initiale2(char **argv)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = 1;
	while (i < 10)
	{
		k = 0;
		j = 0;
		while (k < 8)
		{
			c = argv[i][j];
			while (j < 8)
			{
				if (c == argv[i][j + 1] && c != '.' && argv[i][j + 1] != '.')
					return (1);
				j++;
			}
			k++;
			j = k;
		}
		i++;
	}
	return (0);
}
