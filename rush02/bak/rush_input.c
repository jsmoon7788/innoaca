/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string_list_from_input.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoon <jumoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:41:49 by jumoon            #+#    #+#             */
/*   Updated: 2020/11/01 16:43:31 by jumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**g_instr;

int			make_string_list_from_input(char *str)
{
	int	div;
	int	i;
	int	j;
	int	k;
	int n;
	int len;
	int flag;
	char tmpstr[100];

	len = 0;
	while (str[len] != '\0')
		len++;
	g_instr = (char **)malloc(sizeof(char *) * len * 2);
	i = 0;
	k = 0;
	len = len - 1;
	div = len / 3;
	while (div >= 0)
	{
		flag = 0;
		if (len % 3 == 2)
		{
			if (str[i] != '0')
			{
				g_instr[k] = (char *)malloc(sizeof(char) * 2);
				g_instr[k][0] = str[i];
				g_instr[k][1] = '\0';
				k++;
				g_instr[k] = (char *)malloc(sizeof(char) * 4);
				g_instr[k][0] = '1';
				g_instr[k][1] = '0';
				g_instr[k][2] = '0';
				g_instr[k][3] = '\0';
				k++;
			}
			i++;
			len--;
		}
		if (len % 3 == 1)
		{
			if (str[i] == '1')
			{
				g_instr[k] = (char *)malloc(sizeof(char) * 3);
				g_instr[k][0] = str[i];
				g_instr[k][1] = str[i + 1];
				g_instr[k][2] = '\0';
				k++;
				flag = 1;
				i = i + 2;
				len = len - 2;
			}
			else if (str[i] >= '2')
			{
				g_instr[k] = (char *)malloc(sizeof(char) * 3);
				g_instr[k][0] = str[i];
				g_instr[k][1] = '0';
				g_instr[k][2] = '\0';
				k++;
				i++;
				len--;
			}
			else
			{
				i++;
				len--;
			}
		}
		if (len % 3 == 0 && flag == 0)
		{
			if (str[i] != '0')
			{
				g_instr[k] = (char *)malloc(sizeof(char) * 2);
				g_instr[k][0] = str[i];
				g_instr[k][1] = '\0';
				k++;
			}
			i++;
			len--;
			flag = 1;
		}
		if (div != 0)
		{
			j = 0;
			tmpstr[0] = '1';
			while (j < div * 3)
			{
				j++;
				tmpstr[j] = '0';
			}
			tmpstr[++j] = '\0';
			g_instr[k] = (char *)malloc(sizeof(char) * (j + 2));
			n = 0;
			while (tmpstr[n] != '\0')
			{
				g_instr[k][n] = tmpstr[n];
				n++;
			}
			g_instr[k][n] = '\0';
			k++;
		}
		div--;
	}
	return (k);
}

int			main(void)
{
	int n;
	int ret;
	int len;
	char *tmp;

	tmp = "0";
	ret = make_string_list_from_input(tmp);
	printf("ret value: [%d], str: %s\n", ret, tmp);
	printf("=================================================\n");
	n = 0;
	while (n < ret)
	{
		printf("g_instr[%d]: %s\n", n, g_instr[n]);
		n++;
	}
	printf("=================================================\n");
	len = 0;
	while (tmp[len] != '\0')
		len++;
	n = 0;
	while (n < (len * 2 - 1))
		free(g_instr[n++]);
	free(g_instr);
	return (0);
}
