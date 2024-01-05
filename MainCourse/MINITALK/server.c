/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:01:14 by andi-gia          #+#    #+#             */
/*   Updated: 2023/07/06 18:37:50 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <signal.h>

void	signal_handle(int signum, siginfo_t *info, void *context)
{
	static int	bit_counter;
	static int	i;

	(void)context;
	if (signum == SIGUSR1)
		i += 1 << bit_counter;
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &i, 1);
		if (i == '\n')
			kill(info->si_pid, SIGUSR1);
		bit_counter = 0;
		i = 0;
	}
}

int main(void)
{
    struct sigaction    act;
    
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &signal_handle;
	sigaction(SIGUSR1, &act, (void *)0);
	sigaction(SIGUSR2, &act, (void *)0);
	sigemptyset(&act.sa_mask);
	printf("starting server...");
	printf("** PID: %d **\n", getpid());
	while (1)
		pause();
	return (0);
}