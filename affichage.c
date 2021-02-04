/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   affichage.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aniervas <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 13:02:00 by aniervas     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 15:15:19 by aniervas    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sudoku.h"

extern int g_nb_grilles;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	afficher_grille(int **grille)
{
	int i;
	int j;

	i = 0;
	if (g_nb_grilles > 0)
		ft_putchar('\n');
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putnbr(grille[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
