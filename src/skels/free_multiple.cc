/*
 * File automatically generated by
 * gengen 1.4.2 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#include "free_multiple.h"

void
free_multiple_gen_class::generate_free_multiple(ostream &stream, unsigned int indent)
{
  string indent_str (indent, ' ');
  indent = 0;

  if (has_string_type)
    {
      stream << "free_multiple_string_field (";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_given, &(";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_arg), &(";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_orig));";
      stream << "\n";
      stream << indent_str;
    }
  else
    {
      stream << "free_multiple_field (";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_given, (void *)(";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_arg), &(";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_orig));";
      stream << "\n";
      stream << indent_str;
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_arg = 0;";
      stream << "\n";
      stream << indent_str;
    }
}
