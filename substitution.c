#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool check_repeat(string s);
char make_ciphertext(char a, string cipher);

int main(int argc, string argv[])
{
    // check whether the command line argument has a valid length
    if (argc == 2)
    {
        // check whether the command line argument contains 26 characters
        if (strlen(argv[1]) == 26)
        {
            string cla = argv[1];
            printf("%s\n", cla);
            // loop through command line argument (= cla)
            for (int i = 0; i < strlen(cla); i++)
            {
                // check whether the cla contains only letters
                // if ((cla[i] >= 'A' && cla[i] <= 'Z') || (cla[i] >= 'a' && cla[i] <= 'z'))
                if (isalpha(cla[i]))
                {
                    //check if there are any repeating characters within cla
                    if (check_repeat(cla))
                    {
                        // prompt user for plaintext input
                        string s = get_string("plaintext: ");
                        //print ciphertext
                        printf("ciphertext: ");

                        for (int g = 0; g < strlen(s); g++)
                        {
                            // find out whether s[g] is alphabetical
                            if (isalpha(s[g]))
                            {
                                // check whether s[g] is uppercase or lowercase
                                if (isupper(s[g]))
                                {
                                    // do this if s[g] is uppercase
                                    char lower_char = tolower(s[g]);
                                    char upper_char = make_ciphertext(lower_char, cla);
                                    char answer = toupper(upper_char);
                                    printf("%c", answer);
                                }
                                else
                                {
                                    // do this if s[g] is lowercase
                                    char answer = make_ciphertext(s[g], cla);
                                    printf("%c", answer);
                                }
                            }
                            else
                            {
                                printf("%c", s[g]);
                            }
                        }
                        printf("\n");
                        return 0;
                    }
                    else
                    {
                        printf("characters should not repeat themselves.\n");
                        return 1;
                    }
                }
                else
                {
                    printf("Key must contain 26 alphabetic characters.\n");
                    return 1;
                }
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}



//function to check whether cla includes any repeating characters
bool check_repeat(string s)
{
    // declare integer array 'count' with 26 positions
    int count[26];
    // loop through 'count' and set each position to 0
    for (int a = 0; a < 26; a++)
    {
        count[a] = 0;
    }

    // loop through ASCII 'a-z' & compare to the value of the string[i]
    for (int j = 'a', d = 0; j <= 'z'; j++, d++)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            // make sure s[i] is case insensitive
            s[i] = tolower(s[i]);
            // if s[i] is equal to j --> add 1 to count[d]
            if (s[i] == (char) j)
            {
                count[d]++;
            }
            else
            {
                count[d] += 0;
            }
        }
    }
    // loop through count in order to find out whether there is any repetition
    for (int b = 0; b < 26; b++)
    {
        if (count[b] != 1)
        {
            return false;
        }
    }
    return true;
}

// function to turn plaintext into ciphertext

char make_ciphertext(char a, string cipher)
{
    int alpha_arr[26];

    //loop through alpha_arr to assign each position with the correct letter from the alphabet
    for (int i = 'a', d = 0; i <= 'z'; i++, d++)
 
    {
        alpha_arr[d] = i;
    }

    // loop through alpha_arr and find/return matching char at cipher with same index
    for (int b = 0; b < 26; b++)
    {
        if (alpha_arr[b] == a)
        {
            return cipher[b];
        }
    }
    return 'x';
}