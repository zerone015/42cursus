#!bin/bash

for ((i=0; i<500; i++)); do
	./philo 4 310 200 100 | ./a.out
done