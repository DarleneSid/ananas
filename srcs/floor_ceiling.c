/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:32:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/11/09 17:10:10 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	secure_rgb(char **tab)
{
	int	cnt;
	int	n;

	cnt = 0;
	if (!tab)
		return (-1);
	if (!tab[1] || !tab[2])
		return (free_dstr(tab), -1);
	while (tab[cnt])
	{
		n = 0;
		while ((tab[cnt][n] >= 9 && tab[cnt][n] <= 13) || tab[cnt][n] == 32)
			n++;
		if (tab[cnt][n] == '\n' || tab[cnt][n] == '\0')
			return (free_dstr(tab), -1);
		else
			cnt++;
	}
	return (0);
}

int	loop_floor(t_data *data, char *s, int i)
{
	int		number;
	int		cnt;
	char	**ithink;

	number = 0;
	cnt = 0;
	ithink = ft_split(&s[i], ',');
	if (secure_rgb(ithink))
		return (-1);
	while (ithink[cnt])
	{
		number = ft_atoi(ithink[cnt]);
		if (cnt == 0 && number >= 0 && number <= 255)
			data->f_r = number;
		else if (cnt == 1 && number >= 0 && number <= 255)
			data->f_g = number;
		else if (cnt == 2 && number >= 0 && number <= 255)
			data->f_b = number;
		else
			return (free_dstr(ithink), -1);
		cnt++;
	}
	data->floor_color = data->f_r << 16 | data->f_g << 8 | data->f_b;
	free_dstr(ithink);
	return (1);
}

int	is_floor(t_data *data, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '\t' && !ft_isdigit(s[i])
			&& s[i] != 'F' && s[i] != '\n')
			return (-1);
		i++;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != 'F')
		return (-1);
	i++;
	if (s[i] != ' ')
		return (-1);
	if (loop_floor(data, s, i) == -1)
		return (-1);
	data->f_here++;
	return (1);
}

int	loop_ceiling(t_data *data, char *s, int i)
{
	int		cnt;
	int		number;
	char	**ithink;

	cnt = 0;
	number = 0;
	ithink = ft_split(&s[i], ',');
	if (secure_rgb(ithink))
		return (-1);
	while (ithink[cnt])
	{
		number = ft_atoi(ithink[cnt]);
		if (cnt == 0 && number >= 0 && number <= 255)
			data->c_r = number;
		else if (cnt == 1 && number >= 0 && number <= 255)
			data->c_g = number;
		else if (cnt == 2 && number >= 0 && number <= 255)
			data->c_b = number;
		else
			return (free_dstr(ithink), -1);
		cnt++;
	}
	data->ceiling_color = data->c_r << 16 | data->c_g << 8 | data->c_b;
	free_dstr(ithink);
	return (1);
}

int	is_ceiling(t_data *data, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '\t' && !ft_isdigit(s[i])
			&& s[i] != 'C' && s[i] != '\n')
			return (-1);
		i++;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != 'C')
		return (-1);
	i++;
	if (s[i] != ' ')
		return (-1);
	if (loop_ceiling(data, s, i) == -1)
		return (-1);
	data->c_here++;
	return (1);
}
