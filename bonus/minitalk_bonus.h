/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:25 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/10 15:20:26 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_sigaction
{
    void    (*sa_signaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
}   t_sigaction;

#endif
