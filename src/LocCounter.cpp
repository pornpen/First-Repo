/******************************************************************/
/* Program Assignment: 2                                          */
/* Name: Pornpen Wonganusorn                                      */
/* Date: 8 Feb, 2014                                              */
/* Description: This is a program to count LOC.                   */
/******************************************************************/

/******************************************************************/
/* Listing Contents:                                              */
/*   Reuse instructions                                           */
/*   Includes                                                     */
/*   Source code                                                  */
/*     trim()                                                     */
/*     get_first_word()                                           */
/*     same_word()                                                */
/*     is_allowed()                                               */
/*     print_report()                                             */
/*     loc_count()                                                */
/*     main()                                                     */
/******************************************************************/

/******************************************************************/
/* Reuse instructions                                             */
/*   string trim(char *string)                                    */
/*     Purpose: to trim whitespace from a string                  */
/*     Limitations: trims only ' ' and '\t'                       */
/*   char *get_first_word(string line)                            */
/*     Purpose: get first word of a string a string               */
/*     Limitations: doesn't trim leading whitespace               */
/*   bool same_word(char *a_word, char *other)                    */
/*     Purpose: compare 2 strings                                 */
/******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "LocCounter.hpp"

using namespace std;

string LocCounter::trim(char *string)
{
	char *ptr = string;
	for (unsigned i = 0; i < strlen(string); i++, ptr++)
	{
		if (*ptr != ' ' && *ptr != '\t')
		{
			break;
		}
	}
	if (*ptr != '\0')
	{
		return ptr;
	}
	return "";
}

char *LocCounter::get_first_word(string line)
{
	char* line_copy = strdup(line.c_str());
	trim(line_copy);
	return strtok(line_copy, " ");
}

bool LocCounter::same_word(string a_word, char *other)
{
	return !a_word.empty() && strcmp(a_word.c_str(), other) == 0;
}

bool LocCounter::is_allowed(char first_char, char *first_word)
{
	if (first_char == '/')
		return false;
	if (first_char == '*')
		return false;
	if (first_char == '#')
		return false;
	if (same_word("using", first_word))
		return false;
	if (same_word("public:", first_word))
		return false;
	if (same_word("private:", first_word))
		return false;
	return true;
}

void LocCounter::print_report(string file_name, int globals, int functions,
		int function_lines, int classes, int class_lines)
{
	cout << "Report for " << file_name << endl;
	cout << "Numbers of global variables: " << globals << endl;
	cout << "Global variables part size: " << globals << endl;
	cout << "Numbers of functions: " << functions << endl;
	cout << "Function part size: " << function_lines << endl;
	cout << "Numbers of classes: " << classes << endl;
	cout << "Class part size: " << class_lines << endl;
	cout << "Total size: " << globals + function_lines + class_lines;
}

int LocCounter::loc_count()
{
	string file_name;
	cin >> file_name;
	ifstream file(file_name.c_str());

	if (!file.is_open())
	{
		cout << "Could not open the file.";
		return -1;
	}

	string line;
	int globals = 0;
	int functions = 0;
	int function_lines = 0;
	int classes = 0;
	int class_lines = 0;
	bool is_counting_function = false;
	bool is_counting_class = false;

	while (getline(file, line))
	{
		string trimmed = trim(strdup(line.c_str()));
		char *first_word = get_first_word(trimmed);
		char first_char = line[0];

		if (trimmed.empty() || !is_allowed(first_char, first_word))
			continue;

		if (is_counting_function)
		{
			if (first_char == '}')
			{
				is_counting_function = false;
			}
			else
			{
				function_lines++;
			}
		}
		else if (is_counting_class)
		{
			if (same_word("};", first_word))
			{
				is_counting_class = false;
			}
			else
			{
				class_lines++;
			}
		}
		else // not counting
		{
			if (same_word("class", first_word))
			{
				classes++;
				is_counting_class = true;
			}
			else if (first_char == '{')
			{
				functions++;
				function_lines++;
				is_counting_function = true;
			}
			else if (*line.rbegin() == ';')
			{
				globals++;
			}
		}
	}
	file.close();
	print_report(file_name, globals, functions, function_lines, classes,
			class_lines);
	return globals + function_lines + class_lines;
}
