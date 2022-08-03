#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string txt = get_string("Text: ");
    int n = strlen(txt);

    //count of letters
    int lt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(txt[i]))
        {
            lt++;
        }
    }

    //count of words
    int wo = 1;
    for (int i = 0; i < n; i++)
    {
        if (isspace(txt[i]))
        {
            wo++;
        }
    }

    //count of sentences
    int se = 0;
    for (int i = 0; i < n; i++)
    {
        if ((txt[i]) == 46 || (txt[i]) == 33 || (txt[i]) == 63)
        {
            se++;
        }
    }

    //calculation for grades
    float L = (100 * (float)lt) / (float)wo;
    float S = (100 * (float)se) / (float)wo;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    //printf grades
    if (index >= 1 && index <= 15)
    {
        printf("Grade %.f\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

//Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
//102 letters
//19 words