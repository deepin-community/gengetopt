/* test_conf_parser_ov2.c test */

/* test all kinds of options and the conf file parser */
/* differently from test_conf_parser_ov.c, first scan two conf files and
   then the command line */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>

#include "test_conf_parser_cmd.h"

static struct my_args_info args_info;

int
main (int argc, char **argv)
{
  unsigned int i;

  /* do not override command line options, initialize args_info */
  if (test_conf_parser_cmd_parser_configfile
      ("../../tests/test_conf2.conf", &args_info, 0, 1, 0) != 0)
    exit(1);

  /* do not override, do not initialize args_info */
  if (test_conf_parser_cmd_parser_configfile
      ("../../tests/test_conf3.conf", &args_info, 0, 0, 0) != 0)
    exit(1);

  if (test_conf_parser_cmd_parser2 (argc, argv, &args_info, 1, 0, 1) != 0)
    exit(1) ;

  printf ("value of required: %s\n", args_info.required_arg);
  printf ("value of string: %s\n", args_info.string_arg);
  printf ("value of no-short_given: %d\n", args_info.no_short_given);
  printf ("value of int: %d\n", args_info.int_arg);
  printf ("value of float: %f\n", args_info.float_arg);

  printf ("value of multi-string_given: %d\n", args_info.multi_string_given);
  for (i = 0; i < args_info.multi_string_given; i++)
    printf ("  value of multi-string: %s\n", args_info.multi_string_arg [i]);

  printf ("value of multi-string-def_given: %d\n",
          args_info.multi_string_def_given);
  for (i = 0; i < args_info.multi_string_def_given; i++)
    printf ("  value of multi-string-def: %s\n",
            args_info.multi_string_def_arg [i]);
  if (!args_info.multi_string_def_given && args_info.multi_string_def_arg [0])
    printf ("default value of multi-string-def: %s\n",
            args_info.multi_string_def_arg [0]);

  test_conf_parser_cmd_parser_free (&args_info);

  return 0;
}
