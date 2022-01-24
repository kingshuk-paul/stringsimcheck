#include <string>

std::string lcs(const std::string* src, const std::string* dest);
int lcs_len(const std::string* src, const std::string* dest);
float lcs_score(const std::string* src, const std::string* dest);

int levenshtein(const std::string* src, const std::string* dest);

int damerau_levenshtein(const std::string* src, const std::string* dest);