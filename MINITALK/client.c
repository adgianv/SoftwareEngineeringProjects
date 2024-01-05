/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:01:18 by andi-gia          #+#    #+#             */
/*   Updated: 2023/07/06 18:39:45 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void    ft_send(int pid, const char *str)
{
    static int bit_counter;
    int        i;

    while (*str)
    {
        bit_counter = 0;
        i = *str;
        while (bit_counter < 8)
        {
            if ((i & (1 << bit_counter)) != 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(1000);
            bit_counter++;
        }
        str++;
    }
}

void    recv(int signum)
{
    (void)signum;
    printf("** message received **");
}

int main(int argc, char **argv)
{
    pid_t   pid;
    
    if (argc != 3)
        printf("** wrong input data **");
    pid = ft_atoi(argv[1]);
    signal(SIGUSR1, &recv);
    ft_send(pid, argv[2]);
    ft_send(pid, "\n");
    return (0);
}