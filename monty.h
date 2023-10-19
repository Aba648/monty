#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*all functions*/
/*execute.c*/
void _function(op_func func, char *p, char *val, int ln, int format);
void _execute(char *opcode, char *val, int line, int format);
/*file_operations.c*/
stack_t *_node(int n);
void op_file(char *path_name);
void read_from_file(FILE *fd);
int tokenize_line(char *buffer, int line_num, int format);
/*handle_err.c*/
void handles_error(int error, ...);
void string_err(int error, ...);
void _err(int error, ...);
void f_queue(stack_t **new_n, unsigned int line);
/*free_strack*/
void bfree(void);
/*func_stacks*/
void add_2stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void display_stack(stack_t **stack, unsigned int line_number);
void discard_top(stack_t **stack, unsigned int line_number);
void display_top_node(stack_t **stack, unsigned int line_number);
/*monty_stack_operations*/
void do_nothing(stack_t **stack, unsigned int line_number);
void interchange_top(stack_t **stack, unsigned int line_number);
void add_top_2(stack_t **stack, unsigned int line_number);
void subtract_top_2(stack_t **stack, unsigned int line_number);
void divise_top_2(stack_t **stack, unsigned int line_number);
/*arithmetic_operations*/
void multiply_top_2(stack_t **stack, unsigned int line_number);
void calc_modulo(stack_t **stack, unsigned int line_number);
/*output_operations*/
void print_ch_ascii(stack_t **stack, unsigned int line_number);
void print_ascii_string(stack_t **stack, __attribute__((unused))unsigned int ln);
void rot_stack_left(stack_t **stack, __attribute__((unused))unsigned int ln);
void rot_stack_right(stack_t **stack, __attribute__((unused))unsigned int ln);

#endif
