#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
//# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
//# include "../libft/libft.h"

enum state
{
	EAT = 0,
	SLEEP = 1,
	THINK = 2,
	FORK = 3,
	DIED = 4
};

enum error
{
	ERR_MALLOC = -1,
	ERR_THREAD = -2,
	ERR_MUTEX = -3
};
typedef struct			s_dlist
{
    void				*content;
    struct s_dlist		*next;
    struct s_dlist		*prev;
}						t_dlist;

typedef	struct	s_prm
{
	int				num;
	int				die;
	int				eat;
	int				sleep;
	int				meals;
	int				delay;
	int	            start;
	pthread_mutex_t	lock_die;
	pthread_mutex_t	lock_write;
	//t_dlist         lst[200];
	int				fed;
}				t_prm;

typedef	struct		s_ph
{
	int				id;
    long long      	last_meal;
    //struct timeval	death;
	struct s_frk	*f1;
	struct s_frk	*f2;
	int				meals;
	struct s_prm	*prm;

}					t_ph;

typedef struct		s_frk
{
	pthread_mutex_t	lock;
	int				last_user;
	int             id;
}					t_frk;

typedef struct		s_ctrl
{
	struct s_ph		*ph;
	struct s_frk	*frk;
	struct s_prm	*prm;
}					t_ctrl;


int					prm_setup(int ac, char **av, t_prm *prm, t_ctrl *ctrl);
int					frk_init(t_ctrl *ctrl);
int					ph_init(t_ctrl *ctrl);
int					run_threads(t_ctrl *ctrl);
void				free_data(t_ctrl *ctrl);
void	            print_state(t_ph *ph, int status);
long long           get_time();
//void	ft_dlstadd_back(t_dlist *lst, t_dlist *new);

#endif
