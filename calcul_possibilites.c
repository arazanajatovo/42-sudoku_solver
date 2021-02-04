/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_possibilites.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 12:53:11 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 15:38:03 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sudoku.h"

extern int g_nb_grilles;

struct s_point	case_vide(int **grille)
{
	int				i;
	int				j;
	struct s_point	a;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grille[i][j] == -1)
			{
				a.x = i;
				a.y = j;
				return (a);
			}
			j++;
		}
		i++;
	}
	a.x = -1;
	return (a);
}

int				*fill_t(int **grille, int *tab_possibilites,
		int *taille_tab_possibilites, int i)
{
	int				j;
	struct s_point	a;

	a = case_vide(grille);
	i = -1;
	while (i++ < 9)
		tab_possibilites[i] = i + 1;
	if (a.x == -1)
	{
		*taille_tab_possibilites = -1;
		return (0);
	}
	i = a.x / 3 * 3;
	while (i < (a.x / 3 * 3) + 3)
	{
		j = a.y / 3 * 3;
		while (j < (a.y / 3 * 3) + 3)
		{
			if (grille[i][j] != -1)
				tab_possibilites[grille[i][j] - 1] = -1;
			j++;
		}
		i++;
	}
	return (tab_possibilites);
}

int				*fill_t2(int **grille, int *tab_possibilites)
{
	int				i;
	struct s_point	a;

	i = 0;
	a = case_vide(grille);
	while (i < 9)
	{
		if (grille[i][a.y] != -1)
			tab_possibilites[grille[i][a.y] - 1] = -1;
		if (grille[a.x][i] != -1)
			tab_possibilites[grille[a.x][i] - 1] = -1;
		i++;
	}
	return (tab_possibilites);
}

int				length(int *tab_possibilites)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (i < 9)
	{
		if (tab_possibilites[i] != -1)
			length++;
		i++;
	}
	return (length);
}

int				*calcul_possibilites(int **grille, int *taille_tab_possibilites)
{
	int				i;
	int				j;
	int				*tab_possibilites;
	int				*tab_possibilites2;

	i = 0;
	j = 0;
	tab_possibilites = (int*)malloc(sizeof(int) * 9);
	tab_possibilites = fill_t(grille, tab_possibilites,
			taille_tab_possibilites, i);
	if (*taille_tab_possibilites == -1)
		return (0);
	tab_possibilites = fill_t2(grille, tab_possibilites);
	tab_possibilites2 = (int*)malloc(sizeof(int) * length(tab_possibilites));
	while (i < 9)
	{
		if (tab_possibilites[i] != -1)
		{
			tab_possibilites2[j] = tab_possibilites[i];
			j++;
		}
		i++;
	}
	*taille_tab_possibilites = j;
	return (tab_possibilites2);
}
