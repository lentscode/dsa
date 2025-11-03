C_FLAGS="-I=./"

all: queue stack tree

queue: queue_trial.o queue.o dynamic_arr.o
	cc -o queue_trial queue_trial.o queue.o dynamic_arr.o

queue_trial.o: queue_trial.c
	cc -c queue_trial.c

queue.o: queue.c queue.h dynamic_arr.o
	cc -c queue.c

stack: stack_trial.o stack.o
	cc -o stack_trial stack_trial.o stack.o dynamic_arr.o

stack_trial.o: stack_trial.c
	cc -c stack_trial.c

stack.o: stack.c stack.h dynamic_arr.o
	cc -c stack.c

dynamic_arr.o: dynamic_arr.c dynamic_arr.h
	cc -c dynamic_arr.c

tree: tree.o tree_trial.o queue.o
	cc -o tree_trial tree.o tree_trial.o queue.o \
		dynamic_arr.o

tree_trial.o: tree_trial.c
	cc -c tree_trial.c

tree.o: tree.c tree.h
	cc -c tree.c

heap.o: heap.c heap.h
	cc -c heap.c

sorting: sorting_trial.o sorting.o heap.o util.o
	cc -o sorting_trial sorting_trial.o sorting.o heap.o util.o

sorting_trial.o: sorting_trial.c
	cc -c sorting_trial.c

sorting.o: sorting.c
	cc -c sorting.c

util.o: util.c util.h
	cc -c util.c

clean:
	rm *.o *_trial
