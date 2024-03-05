all: main data_stat.a build_with_static clean

main: decision.o data_io.o data_stat.o main_executable_module.o data_process.o data_sort.o
	gcc -Wall -Wextra -Werror main_executable_module.o data_io.o data_stat.o decision.o data_sort.o data_process.o -o ../../build/Quest_3

build_with_static: decision.o data_io.o data_stat.a main_executable_module.o data_process.o data_sort.o
	gcc -Wall -Wextra -Werror main_executable_module.o data_io.o decision.o data_sort.o data_process.o ../data_libs/data_stat.a -lm -o ../../build/Quest_5 

data_stat.a: data_stat.o
	ar rc ../data_libs/data_stat.a data_stat.o

main_executable_module.o: main_executable_module.c
	gcc -Wall -Wextra -Werror -c main_executable_module.c

main_executable_module_macro.o: main_executable_module.c
	gcc -Wall -Wextra -Werror -c -DMACROS main_executable_module.c

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	gcc -Wall -Wextra -Werror -c ../yet_another_decision_module/decision.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	gcc -Wall -Wextra -Werror -c ../data_module/data_process.c

data_sort.o: ../data_libs/data_sort.c ../data_libs/data_sort.h
	gcc -Wall -Wextra -Werror -c ../data_libs/data_sort.c

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc -Wall -Wextra -Werror -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc -Wall -Wextra -Werror -c ../data_libs/data_stat.c

clean:
	rm -rf *.o 
