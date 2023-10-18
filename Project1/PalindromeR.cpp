// PalindromeR implementation file
// Javan Miller

#include "PalindromeR.hpp"

int PalindromeR::test_string(const std::string& s)
{
    // Converts string to lowercase
    std::string lowerS = s;
    for (int i = 0; i < lowerS.length(); i++)
    {
        lowerS[i] = tolower(lowerS[i]);
    }

    // String with one character or less is a palindrome
    if (s.length() <= 1)
    {
        return -1;
    }

    // Find the index of the first alphabetical character
    int first = 0;
    while (isalpha(s[first]) == 0)
    {
        first++;
    }

    // Find the index of the last alphabetical character
    int last = s.length() - 1;
    while (isalpha(s[last]) == 0)
    {
        last--;
    }

    // Is palindrome if first is greater than or equal to last char
    if (first >= last)
    {
        return -1;
    }

    // Tests if first and last character in string is equivalent
    // If true, it recursively calls the function by creating a substring
    if (lowerS[first] == lowerS[last])
    //if (lowerS[0] == lowerS[lowerS.length() - 1])
    {
        return test_string(lowerS.substr(first + 1, last - first - 1));    
    }
    else
    {
        return 1;
    }
}