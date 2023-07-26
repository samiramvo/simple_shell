#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


/* where you call the environement*/
extern char **environ;

/**
 * struct data - that contains all relevant data
 * @av : argument
 * @args : tokens in the command
 * @inp : command line that user write
 * @stat: last status of the sh
 * @count: counter line
 * @_environ: variable environnement
 * @pid: process ID
 */
typedef struct data
{
	char **av;
	char **args;
	char *input;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s -Builtin struct
 * @separator: The name of the command(cd, exit...)
 * @next: data type pointer function
 * Description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* LIST.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* LIST2.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* aux_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* aux_str3.c */
void rev_string(char *s);

/* check_syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(datash *data, char *input, int i, int bool);
int check_syntax_error(datash *data, char *input);

/* loop_sh.c */
char *delete_com(char *in);
void loop_sh(datash *data);

/* read_lines.c */
char *read_lines(int *value);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* rep_var.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* getLine.c */
void attr_line(char **lineptr, size_t *n, char *buffer, size_t len);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* execute_line.c */
int execute_line(datash *data);

/* command_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(datash *data);
int check_error_cmd(char *dir, datash *data);
int command_exec(datash *data);

/* env.c */
int comp_env(const char *name_env, const char *name)
char *_getenv(const char *name, char **_environ);
int _printenv(datash *data);

/* env_builtin.c */
char *copy_inf(char *name, char *val);
void set_env(char *name, char *value, datash *data);
int _setenv(datash *data);
int _unsetenv(datash *data);

/* cmd_cd.c */
void cd_dot(datash *data);
void cd_to(datash *data);
void cd_previous(datash *data);
void cd_to_home(datash *datash);

/* cd_shell.c */
int cd_shell(datash *data);

/* get_builtins.c */
int (*get_builtins(char *command))(datash *);

/* exit_sh.c */
int exit_sh(datash *data);

/* stdlib.c */
int get_len(int n);
char *itoa(int n);
int _atoi(char *s);

/* error1.c */
char *strcat_cd(datash *data, char *msg, char *error, char *ver_str);
char *error_get_cd(datash *data);
char *error_not_found(datash *data);
char *error_exit_shell(datash *data);

/* error2.c */
char *error_get_alias(char **args);
char *error_env(datash *data);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


/* get_error.c */
int get_error(datash *data, int error_val);

/* get_signal.c */
void get_signal(int signal);

/* HELP.c */
void env_help(void);
void setenv_help(void);
void unsetenv_help(void);
void general_help(void);
void exit_help(void);

/* help2.c */
void help_help(void);
void help_alias(void);
void cd_help(void);

/* getHELP.c */
int get_HELP(datash *data);

#endif
