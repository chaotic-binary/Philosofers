# Philosofers
Solving philosophers problem with mutexes, semaphores and threads

1. philo_one: threads and mutexes
2. philo_two: threads and semaphores 
3. philo_three: processes and semaphores 

### Build and run
1. ```make``` (in ```philo_*``` directory)
2. ```./philo_{} [philos_count] [ms_to_die] [ms_to_eat] [ms_to_sleep] [optional: meals_provided]```

> Example: ```./philo_one 5 800 200 200```

Simulation ends on any philosopher death or then meals number (the last argument) ends

