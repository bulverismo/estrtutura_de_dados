//gcc -o executavel principal.c implementacao.c
//or
//make
#include <stdlib.h>
#include <stdio.h>
#include "date_f.h"
#include <argp.h>

#define QTY_ARGS 1

const char *argp_program_version =
  "Data_f 1.0";

const char *argp_program_bug_address =
  "<joseamericolf@gmail.com>";

/* Program documentation. */
static char doc[] =
  "Data_f -- um programa para testar validade das datas e retornar datas formatadas";

/* A description of the arguments we accept. */
static char args_doc[] = "DD/MM/YYYY";

/* The options we understand. */
static struct argp_option options[] = {
  {"verbose",  'v', 0,      0,  "Produz saída ver verbose output" },
  {"quiet",    'q', 0,      0,  "Don't produce any output" },
  {"silent",   's', 0,      OPTION_ALIAS },
  {"output",   'o', "FILE", 0, 
   "Output to FILE instead of standard output" },
  { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
  char *args[QTY_ARGS];             
  int silent, verbose;
  char *output_file;
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'q': case 's':
      arguments->silent = 1;
      break;
    case 'v':
      arguments->verbose = 1;
      break;
    case 'o':
      arguments->output_file = arg;
      break;

    case ARGP_KEY_ARG:
      if (state->arg_num >= QTY_ARGS)
        /* Too many arguments. */
        argp_usage (state);

      arguments->args[state->arg_num] = arg;

      break;

    case ARGP_KEY_END:
      if (state->arg_num < QTY_ARGS)
        /* Not enough arguments. */
        argp_usage (state);
      break;

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };


int main(int argc,char **argv) {

  	struct arguments arguments;

    DATE data = { 1, 1, 2021 };
    
  	/* Default values. */
	arguments.silent = 0;
	arguments.verbose = 0;
	arguments.output_file = "-";

	argp_parse (&argp, argc, argv, 0, 0, &arguments);

	printf("Main genérica\n");

	// DEBUG
	printf ("ARG1 = %s\nARG2 = %s\nARG3 = %s\nOUTPUT_FILE = %s\n"
		"VERBOSE = %s\nSILENT = %s\n",
	arguments.args[0], arguments.args[1], arguments.args[2],
	arguments.output_file,
	arguments.verbose ? "yes" : "no",
	arguments.silent ? "yes" : "no");
    
    printf("data 01/01/2021: ");
    print_date(data);

    //data = fill( atoi(arguments.args[0]), atoi(arguments.args[1]), atoi(arguments.args[2]) );

    //printf("data %d %d %d\n", data.day, data.month, data.year);
    
    if (test_str_date(arguments.args[0], &data))
    {
        printf("data recebida: ");
        print_date(data);
        printf("Qty days %d\n", qty_days_until_now(data));
        printf("valida\n");

        DATE data2;
        int x=0;
        printf("\n");
        while(x<366) 
        {
          if (date_gen_from_days(x, data.year, &data2)) {
              printf("%d > ",x);
              print_date(data2);
              printf(" > ");
              printf("%d", qty_days_until_now(data2));

          }
          else
          {
              printf("impossivel");
          }
          printf("\n");
          x++;
        }
    }
    else
    {
        printf("data invalida\n");
    }

	if (arguments.verbose) {
		printf("Saida verbossssssssssssssaaa!\n");
	}

	return 0;
}
