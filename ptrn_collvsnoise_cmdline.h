/** @file ptrn_collvsnoise_cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.1
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef PTRN_COLLVSNOISE_CMDLINE_H
#define PTRN_COLLVSNOISE_CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef PTRN_COLLVSNOISE_PARSER_PACKAGE
/** @brief the program name */
#define PTRN_COLLVSNOISE_PARSER_PACKAGE "netgauge-collvsnoise"
#endif

#ifndef PTRN_COLLVSNOISE_PARSER_VERSION
/** @brief the program version */
#define PTRN_COLLVSNOISE_PARSER_VERSION "0.1"
#endif

/** @brief Where the command line options are stored */
struct ptrn_collvsnoise_cmd_struct
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * pattern_arg;	/**< @brief pattern.  */
  char * pattern_orig;	/**< @brief pattern original value given at command line.  */
  const char *pattern_help; /**< @brief pattern help description.  */
  char * datasize_arg;	/**< @brief size of the collective data transfer (default='8-8').  */
  char * datasize_orig;	/**< @brief size of the collective data transfer original value given at command line.  */
  const char *datasize_help; /**< @brief size of the collective data transfer help description.  */
  char * commsize_arg;	/**< @brief collective communicator sizes (default='2-').  */
  char * commsize_orig;	/**< @brief collective communicator sizes original value given at command line.  */
  const char *commsize_help; /**< @brief collective communicator sizes help description.  */
  int nochangecomm_flag;	/**< @brief don't change communicator during run (default=off).  */
  const char *nochangecomm_help; /**< @brief don't change communicator during run help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int pattern_given ;	/**< @brief Whether pattern was given.  */
  unsigned int datasize_given ;	/**< @brief Whether datasize was given.  */
  unsigned int commsize_given ;	/**< @brief Whether commsize was given.  */
  unsigned int nochangecomm_given ;	/**< @brief Whether nochangecomm was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct ptrn_collvsnoise_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure ptrn_collvsnoise_cmd_struct (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure ptrn_collvsnoise_cmd_struct (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *ptrn_collvsnoise_cmd_struct_purpose;
/** @brief the usage string of the program */
extern const char *ptrn_collvsnoise_cmd_struct_usage;
/** @brief all the lines making the help output */
extern const char *ptrn_collvsnoise_cmd_struct_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser (int argc, char * const *argv,
  struct ptrn_collvsnoise_cmd_struct *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use ptrn_collvsnoise_parser_ext() instead
 */
int ptrn_collvsnoise_parser2 (int argc, char * const *argv,
  struct ptrn_collvsnoise_cmd_struct *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser_ext (int argc, char * const *argv,
  struct ptrn_collvsnoise_cmd_struct *args_info,
  struct ptrn_collvsnoise_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser_dump(FILE *outfile,
  struct ptrn_collvsnoise_cmd_struct *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser_file_save(const char *filename,
  struct ptrn_collvsnoise_cmd_struct *args_info);

/**
 * Print the help
 */
void ptrn_collvsnoise_parser_print_help(void);
/**
 * Print the version
 */
void ptrn_collvsnoise_parser_print_version(void);

/**
 * Initializes all the fields a ptrn_collvsnoise_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void ptrn_collvsnoise_parser_params_init(struct ptrn_collvsnoise_parser_params *params);

/**
 * Allocates dynamically a ptrn_collvsnoise_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized ptrn_collvsnoise_parser_params structure
 */
struct ptrn_collvsnoise_parser_params *ptrn_collvsnoise_parser_params_create(void);

/**
 * Initializes the passed ptrn_collvsnoise_cmd_struct structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void ptrn_collvsnoise_parser_init (struct ptrn_collvsnoise_cmd_struct *args_info);
/**
 * Deallocates the string fields of the ptrn_collvsnoise_cmd_struct structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void ptrn_collvsnoise_parser_free (struct ptrn_collvsnoise_cmd_struct *args_info);

/**
 * The string parser (interprets the passed string as a command line)
 * @param cmdline the command line stirng
 * @param args_info the structure where option information will be stored
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser_string (const char *cmdline, struct ptrn_collvsnoise_cmd_struct *args_info,
  const char *prog_name);
/**
 * The string parser (version with additional parameters - deprecated)
 * @param cmdline the command line stirng
 * @param args_info the structure where option information will be stored
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use ptrn_collvsnoise_parser_string_ext() instead
 */
int ptrn_collvsnoise_parser_string2 (const char *cmdline, struct ptrn_collvsnoise_cmd_struct *args_info,
  const char *prog_name,
  int override, int initialize, int check_required);
/**
 * The string parser (version with additional parameters)
 * @param cmdline the command line stirng
 * @param args_info the structure where option information will be stored
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int ptrn_collvsnoise_parser_string_ext (const char *cmdline, struct ptrn_collvsnoise_cmd_struct *args_info,
  const char *prog_name,
  struct ptrn_collvsnoise_parser_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int ptrn_collvsnoise_parser_required (struct ptrn_collvsnoise_cmd_struct *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* PTRN_COLLVSNOISE_CMDLINE_H */
