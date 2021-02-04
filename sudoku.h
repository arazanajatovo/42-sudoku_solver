/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sudoku.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: krambono <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 16:30:55 by krambono     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 19:57:10 by krambono    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <stdlib.h>
# include <unistd.h>

struct			s_point
{
	int x;
	int y;
};

struct s_point	case_vide(int **grille);

int				*calcul_possibilites(int **grille,
				int *taille_tab_possibilite);

int				test_grille_initiale(char **argv);

int				test_grille_initiale2(char **argv);

int				test_grille_initiale3(char **argv);

int				test_grille_initiale4(char **argv);

void			lignes_vers_tab(int **grille, char **argv);

void			sudoku(int **grille);

void			ft_putstr(char *str);

void			afficher_grille(int **grille);

#endif
