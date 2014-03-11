using namespace std;

class LocCounter
{
public:
	int loc_count();

private:
	string trim(char *string);
	char *get_first_word(string line);
	bool same_word(string a_word, char *other);
	bool is_allowed(char first_char, char *first_word);
	void print_report(string file_name, int globals, int functions,
			int function_lines, int classes, int class_lines);
};
