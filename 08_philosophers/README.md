## 식사하는 철학자 문제를 멀티 스레드, 멀티 프로세스로 구현하는 과제입니다.
mandatory part에서는 철학자를 스레드로 구현하여 동기화를 위해 뮤텍스를 사용합니다.  
bonus part에서는 철학자를 프로세스로 구현하여 동기화를 위해 세마포어를 사용합니다.  
모든 철학자들이 제때 밥을 먹어 굶어 죽지 않도록 해야 하며, 과제를 하면서 많은 OS 지식을 학습을 하게 됩니다.  
[관련 지식을 정리한 블로그](https://velog.io/@zerone015/series/philosophers)  
### 인원
- 1인
### 사용 언어
- C언어
### 실행
```shell
# Download
$ git clone https://github.com/zerone015/42seoul.git philosophers
$ cd philosophers/08_philosophers

# build
$ cd philo
$ make            # mandatory

$ cd philo_bonus
$ make bonus      # bonus

# execute
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional argument)]        # mandatory
./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional argument)]  # bonus

# example
./philo 10 410 200 200        # mandatory
./philo_bonus 11 610 200 200  # bonus
```
### 구현 내용
- 멀티 스레드
- 멀티 프로세스
### 학습 내용
- 프로세스, 스레드
- process management
- PCB
- context switch
- race condition
- critical section
- deadlock
- process synchronization
- CPU scheduling
- busy waiting, block/wakeup
