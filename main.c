/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 12:54:57 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 21:10:40 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sudoku.h"

int		g_nb_grilles = 0;

int		initialisation(int argc, char **argv)
{
	int test;

	test = 0;
	if (argc == 10)
	{
		test += test_grille_initiale(argv);
		if (test == 0)
		{
			test += test_grille_initiale2(argv);
			test += test_grille_initiale3(argv);
			test += test_grille_initiale4(argv);
		}
	}
	else
		test = 1;
	return (test);
}

int		main(int argc, char **argv)
{
	int **grille;
	int i;
	int test;

	test = initialisation(argc, argv);
	if (test == 0)
	{
		grille = (int**)malloc(sizeof(int*) * 9);
		i = -1;
		while (i++ < 9)
			grille[i] = (int*)malloc(sizeof(int) * 9);
		lignes_vers_tab(grille, argv);
		sudoku(grille);
		if (g_nb_grilles == 0)
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
