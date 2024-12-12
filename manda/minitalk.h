/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:25 by ygorget           #+#    #+#             */
/*   Updated: 2024/12/12 17:07:19 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define ERR_MALLOC "allocation memory failed"
# define ERR_KILL "error sending signal"
# define ERR_SIG "Signal management failed"
# define ERR_ARGC "there are not 3 arguments"
# define ERR_PID "PID is not good"

#endif
