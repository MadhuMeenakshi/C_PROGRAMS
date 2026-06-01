#include "strings.h"

void reverseWords(char str[])
{
    int len = strlen(str);

    // Start from last character
    for(int i = len - 1; i >= 0; i--)
    {
        // If space found
        if(str[i] == ' ')
        {
            // Print next word
            for(int j = i + 1; str[j] != ' ' && str[j] != '\0'; j++)
            {
                printf("%c", str[j]);
            }

            printf(" ");
        }
    }

    // Print first word
    for(int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
}

void removeRepeated(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int j = i + 1; str[j] != '\0';)
        {
            // Duplicate found
            if(str[i] == str[j])
            {
                // Shift left
                for(int k = j; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                }
            }
            else
            {
                j++;
            }
        }
    }

    printf("%s", str);
}

void removeRepeated(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int j = i + 1; str[j] != '\0';)
        {
            // Duplicate found
            if(str[i] == str[j])
            {
                // Shift left
                for(int k = j; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                }
            }
            else
            {
                j++;
            }
        }
    }

    printf("%s", str);
}

void highestFreq(char str[])
{
    int max = 0, count;
    char ch;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        // Count occurrences
        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        // Store maximum
        if(count > max)
        {
            max = count;
            ch = str[i];
        }
    }

    printf("%c appears %d times", ch, max);
}

void lowestFreq(char str[])
{
    int min = 999, count;

    // Find minimum frequency
    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        if(count < min)
            min = count;
    }

    // Print characters with minimum frequency
    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        if(count == min)
            printf("%c ", str[i]);
    }
}

void reverseString(char str[])
{
    int len = strlen(str);
    char temp;

    for(int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("%s", str);
}

void removeSpaces(char str[])
{
    int i = 0, j = 0;

    // Skip leading spaces
    while(str[i] == ' ')
        i++;

    while(str[i] != '\0')
    {
        // Avoid multiple spaces
        if(!(str[i] == ' ' && str[i+1] == ' '))
        {
            str[j++] = str[i];
        }

        i++;
    }

    // Remove trailing space
    if(str[j-1] == ' ')
        j--;

    str[j] = '\0';

    printf("%s", str);
}

void replaceChar(char str[], char old, char newc)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == old)
            str[i] = newc;
    }

    printf("%s", str);
}

void charFrequency(char str[])
{
    int count, visited;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 1;
        visited = 0;

        // Check visited
        for(int k = 0; k < i; k++)
        {
            if(str[i] == str[k])
            {
                visited = 1;
                break;
            }
        }

        if(visited)
            continue;

        // Count frequency
        for(int j = i + 1; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        printf("%c = %d\n", str[i], count);
    }
}

void firstWord(char str[], char word[])
{
    int i, j;

    for(i = 0; str[i] != '\0'; i++)
    {
        j = 0;

        while(word[j] != '\0' && str[i+j] == word[j])
        {
            j++;
        }

        // Entire word matched
        if(word[j] == '\0')
        {
            printf("Found at position %d", i);
            return;
        }
    }

    printf("Not found");
}

void removeWord(char str[], char word[])
{
    int i, j, k;
    int len = strlen(word);

    for(i = 0; str[i] != '\0'; i++)
    {
        j = 0;

        while(word[j] != '\0' && str[i+j] == word[j])
        {
            j++;
        }

        // Word found
        if(word[j] == '\0')
        {
            // Shift left
            for(k = i; str[k+len] != '\0'; k++)
            {
                str[k] = str[k+len];
            }

            str[k] = '\0';
            i--;
        }
    }

    printf("%s", str);
}

void countWords(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        // End of word
        if(str[i] != ' ' &&
          (str[i+1] == ' ' || str[i+1] == '\0'))
        {
            count++;
        }
    }

    printf("Words = %d", count);
}
void toggleCase(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        // Uppercase
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }

        // Lowercase
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    printf("%s", str);
}

void removeLast(char str[], char ch)
{
    int pos = -1;

    // Find last occurrence
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
            pos = i;
    }

    // Shift left
    if(pos != -1)
    {
        for(int i = pos; str[i] != '\0'; i++)
        {
            str[i] = str[i+1];
        }
    }

    printf("%s", str);
}

void replaceFirst(char str[], char old, char newc)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == old)
        {
            str[i] = newc;
            break;
        }
    }

    printf("%s", str);
}

void countWord(char str[], char word[])
{
    int i, j, count = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        j = 0;

        while(word[j] != '\0' &&
              str[i+j] == word[j])
        {
            j++;
        }

        if(word[j] == '\0')
            count++;
    }

    printf("%d", count);
}

void palindrome(char str[])
{
    int len = strlen(str);
    int flag = 1;

    for(int i = 0; i < len/2; i++)
    {
        if(str[i] != str[len-1-i])
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not palindrome");
}

void lastOccurrence(char str[], char ch)
{
    int pos = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
            pos = i;
    }

    printf("Position = %d", pos);
}

void trim(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while(str[start] == ' ')
        start++;

    while(str[end] == ' ')
        end--;

    for(int i = start; i <= end; i++)
    {
        printf("%c", str[i]);
    }
}

void firstOccurrence(char str[], char ch)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        {
            printf("Position = %d", i);
            return;
        }
    }

    printf("Not found");
}

void allOccurrences(char str[], char word[])
{
    int i, j;

    for(i = 0; str[i] != '\0'; i++)
    {
        j = 0;

        while(word[j] != '\0' &&
              str[i+j] == word[j])
        {
            j++;
        }

        if(word[j] == '\0')
        {
            printf("%d ", i);
        }
    }
}
