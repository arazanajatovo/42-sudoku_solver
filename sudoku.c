/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sudoku.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 12:33:36 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 19:55:43 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sudoku.h"

extern int g_nb_grilles;

void			lignes_vers_tab(int **grille, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i + 1][j] != '.')
				grille[i][j] = argv[i + 1][j] - '0';
			else
				grille[i][j] = -1;
			j++;
		}
		i++;
	}
}

int				test_grille_initiale(char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] != '.' && !(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			if (argv[i][9] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				**ajoute_possibilite(int **grille, int nouveau_chiffre)
{
	int				i;
	int				j;
	int				**grille_cpy;
	struct s_point	a;

	a = case_vide(grille);
	grille_cpy = (int**)malloc(sizeof(int*) * 9);
	i = -1;
	while (i++ < 9)
		grille_cpy[i] = (int*)malloc(sizeof(int) * 9);
	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			grille_cpy[i][j] = grille[i][j];
			j++;
		}
		i++;
	}
	grille_cpy[a.x][a.y] = nouveau_chiffre;
	return (grille_cpy);
}

void			sudoku(int **grille)
{
	int *tab_possibilites;
	int taille_tab_possibilites;
	int i;

	tab_possibilites = calcul_possibilites(grille, &taille_tab_possibilites);
	i = 0;
	if (taille_tab_possibilites == -1)
	{
		afficher_grille(grille);
		free(grille);
		g_nb_grilles++;
	}
	else if (taille_tab_possibilites == 0)
		free(grille);
	else
		while (i < taille_tab_possibilites)
		{
			sudoku((ajoute_possibilite(grille, tab_possibilites[i])));
			i++;
		}
}
