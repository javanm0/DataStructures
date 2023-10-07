// PalindromeR implementation file
// Javan Miller

#include "PalindromeR.hpp"

int PalindromeR::test_string(const std::string& s)
{    
    // String with one character or less is a palindrome
    if (s.length() <= 1)
    {
        return -1;
    }

    // Converts string to lowercase
    std::string lowerS = s;
    for (int i = 0; i < lowerS.length(); i++)
    {
        lowerS[i] = tolower(lowerS[i]);
    }

    // Tests if first and last character in string is equivalent
    // If true, it recursively calls the function by creating a substring
    if (lowerS[0] == lowerS[lowerS.length() - 1])
    {
        return test_string(lowerS.substr(1, lowerS.length() - 2));    
    }
    else
    {
        return 1;
    }
}