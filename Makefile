CC      = cc
CFLAGS  = -Wall -Wextra -std=c11 -g
LDFLAGS = 

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c:.0)

.PHONY: all clean

all: queue_trial stack_trial tree_trial sorting_trial list_trial dynamic_arr_trial hash_table_trial

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

bst_trial: bst_trial.o bst.o
	cc -o bst_trial bst_trial.o bst.o

queue_trial: queue_trial.o queue.o dynamic_arr.o
	cc -o queue_trial queue_trial.o queue.o dynamic_arr.o

stack_trial: stack_trial.o stack.o dynamic_arr.o
	cc -o stack_trial stack_trial.o stack.o dynamic_arr.o

tree_trial: tree_trial.o tree.o queue.o stack.o dynamic_arr.o
	cc -o tree_trial tree_trial.o tree.o queue.o \
		stack.o dynamic_arr.o

sorting_trial: sorting_trial.o sorting.o heap.o util.o
	cc -o sorting_trial sorting_trial.o sorting.o heap.o util.o

list_trial: list_trial.o list.o
	cc -o list_trial list_trial.o list.o

dynamic_arr_trial: dynamic_arr_trial.o dynamic_arr.o
	cc -o dynamic_arr_trial dynamic_arr_trial.o dynamic_arr.o

hash_table_trial: hash_table_trial.o hash_table.o
	cc -o hash_table_trial hash_table_trial.o hash_table.o

clean:
	rm *.o *_trial
