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

void swapStrings(char str1[], char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    strcat(str1, str2);

    strcpy(str2, str1);

    str2[len1] = '\0';

    strcpy(str1, str1 + len1);

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
}

void sortStrings(char str[][20], int n)
{
    char temp[20];

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(strcmp(str[j], str[j+1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%s\n", str[i]);
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

void highestFreq(char str[])
{
    int max = 0, count;
    char ch;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        if(count > max)
        {
            max = count;
            ch = str[i];
        }
    }

    printf("%c", ch);
}

void removeDuplicate(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int j = i+1; str[j] != '\0';)
        {
            if(str[i] == str[j])
            {
                for(int k = j; str[k] != '\0'; k++)
                    str[k] = str[k+1];
            }
            else
            {
                j++;
            }
        }
    }

    printf("%s", str);
}

void duplicateChars(char str[])
{
    int count;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        if(count > 1)
        {
            printf("%c ", str[i]);

            for(int k = i+1; str[k] != '\0'; k++)
            {
                if(str[k] == str[i])
                    str[k] = '*';
            }
        }
    }
}

void rotation(char str1[], char str2[])
{
    char temp[100];

    strcpy(temp, str1);
    strcat(temp, str1);

    if(strstr(temp, str2))
        printf("Yes");
    else
        printf("No");
}

void divideString(char str[], int n)
{
    int len = strlen(str);

    int part = len / n;

    for(int i = 0; i < len; i++)
    {
        printf("%c", str[i]);

        if((i+1)%part == 0)
            printf("\n");
    }
}

void firstNonRepeat(char str[])
{
    int count;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 0;

        for(int j = 0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
                count++;
        }

        if(count == 1)
        {
            printf("%c", str[i]);
            return;
        }
    }
}

void reverseWords(char str[])
{
    int len = strlen(str);

    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            for(int j = i+1; str[j] != ' ' && str[j] != '\0'; j++)
                printf("%c", str[j]);

            printf(" ");
        }
    }

    for(int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
        printf("%c", str[i]);
}

void compress(char str[])
{
    int count;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count = 1;

        while(str[i] == str[i+1])
        {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
    }
}

void naiveSearch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    for(int i = 0; i <= n-m; i++)
    {
        int j;

        for(j = 0; j < m; j++)
        {
            if(text[i+j] != pattern[j])
                break;
        }

        if(j == m)
            printf("Found at %d\n", i);
    }
}

void naiveSearch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    for(int i = 0; i <= n-m; i++)
    {
        int j;

        for(j = 0; j < m; j++)
        {
            if(text[i+j] != pattern[j])
                break;
        }

        if(j == m)
            printf("Found at %d\n", i);
    }
}

void longestUnique(char str[])
{
    int max = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        int visited[256] = {0};
        int count = 0;

        for(int j = i; str[j] != '\0'; j++)
        {
            if(visited[str[j]])
                break;

            visited[str[j]] = 1;
            count++;
        }

        if(count > max)
            max = count;
    }

    printf("%d", max);
}

void anagram(char str1[], char str2[])
{
    int freq[256] = {0};

    for(int i = 0; str1[i] != '\0'; i++)
        freq[str1[i]]++;

    for(int i = 0; str2[i] != '\0'; i++)
        freq[str2[i]]--;

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            printf("False");
            return;
        }
    }

    printf("True");
}

void countWords(char str[])
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' &&
          (str[i+1] == ' ' || str[i+1] == '\0'))
        {
            count++;
        }
    }

    printf("%d", count);
}

void stringToInt(char str[])
{
    int num = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        num = num*10 + (str[i]-48);
    }

    printf("%d", num);
}

void interleavings(char str1[], char str2[],
                   char result[],
                   int i, int j,
                   int m, int n)
{
    // Both strings finished
    if(i == m && j == n)
    {
        result[i+j] = '\0';
        printf("%s\n", result);
        return;
    }

    // Take character from first string
    if(i < m)
    {
        result[i+j] = str1[i];

        interleavings(str1, str2,
                      result,
                      i+1, j,
                      m, n);
    }

    // Take character from second string
    if(j < n)
    {
        result[i+j] = str2[j];

        interleavings(str1, str2,
                      result,
                      i, j+1,
                      m, n);
    }
}
void boyerMoore(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int i = 0;

    while(i <= n-m)
    {
        int j = m-1;

        while(j >= 0 &&
              pattern[j] == text[i+j])
        {
            j--;
        }

        if(j < 0)
        {
            printf("Found at %d\n", i);
            i += m;
        }
        else
        {
            i++;
        }
    }
}

void longestPalindrome(char str[])
{
    int len = strlen(str);

    int start = 0;
    int max = 1;

    for(int i = 0; i < len; i++)
    {
        // Odd length
        int l = i;
        int r = i;

        while(l >= 0 &&
              r < len &&
              str[l] == str[r])
        {
            if(r-l+1 > max)
            {
                start = l;
                max = r-l+1;
            }

            l--;
            r++;
        }

        // Even length
        l = i;
        r = i+1;

        while(l >= 0 &&
              r < len &&
              str[l] == str[r])
        {
            if(r-l+1 > max)
            {
                start = l;
                max = r-l+1;
            }

            l--;
            r++;
        }
    }

    for(int i = start;
        i < start+max;
        i++)
    {
        printf("%c", str[i]);
    }
}

void sortWord(char str[])
{
    int len = strlen(str);

    for(int i = 0; i < len-1; i++)
    {
        for(int j = 0; j < len-1-i; j++)
        {
            if(str[j] > str[j+1])
            {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

void groupAnagrams(char arr[][20], int n)
{
    char temp[20][20];

    for(int i = 0; i < n; i++)
    {
        strcpy(temp[i], arr[i]);
        sortWord(temp[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%s : ", arr[i]);

        for(int j = i+1; j < n; j++)
        {
            if(strcmp(temp[i], temp[j]) == 0)
            {
                printf("%s ", arr[j]);
            }
        }

        printf("\n");
    }
}

int wildcard(char pattern[], char str[])
{
    int i = 0, j = 0;

    while(pattern[i] != '\0' &&
          str[j] != '\0')
    {
        // Exact match or '?'
        if(pattern[i] == str[j] ||
           pattern[i] == '?')
        {
            i++;
            j++;
        }

        // '*' matches everything
        else if(pattern[i] == '*')
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    return 1;
}

void longestCommon(char str1[],
                   char str2[])
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int max = 0;
    int end = 0;

    int dp[100][100] = {0};

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] =
                dp[i-1][j-1] + 1;

                if(dp[i][j] > max)
                {
                    max = dp[i][j];
                    end = i;
                }
            }
        }
    }

    for(int i = end-max;
        i < end;
        i++)
    {
        printf("%c", str1[i]);
    }
}

void removeBandAC(char str[])
{
    int i, j = 0;

    char temp[100];

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'b')
            continue;

        if(str[i] == 'a' &&
           str[i+1] == 'c')
        {
            i++;
            continue;
        }

        temp[j++] = str[i];
    }

    temp[j] = '\0';

    printf("%s", temp);
}

void streamNonRepeat(char str[])
{
    int freq[256] = {0};

    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;

        int found = 0;

        for(int j = 0; j <= i; j++)
        {
            if(freq[str[j]] == 1)
            {
                printf("%c ", str[j]);
                found = 1;
                break;
            }
        }

        if(!found)
            printf("-1 ");
    }
}

void removeAdjacent(char str[])
{
    int len = strlen(str);

    for(int i = 0; i < len-1; i++)
    {
        if(str[i] == str[i+1])
        {
            int j = i;

            while(str[j+2] != '\0')
            {
                str[j] = str[j+2];
                j++;
            }

            str[j] = '\0';

            removeAdjacent(str);

            return;
        }
    }

    printf("%s", str);
}

void secondHighestFreq(char str[])
{
    int freq[256] = {0};

    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }

    int first = 0;
    int second = 0;

    char ch;

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > first)
        {
            second = first;
            first = freq[i];
        }

        else if(freq[i] > second &&
                freq[i] != first)
        {
            second = freq[i];
            ch = i;
        }
    }

    printf("%c", ch);
}

int isPalindrome(char str[], int start, int end)
{
    while(start < end)
    {
        if(str[start] != str[end])
            return 0;

        start++;
        end--;
    }

    return 1;
}

int minPartition(char str[], int start, int end)
{
    // Entire substring already palindrome
    if(isPalindrome(str, start, end))
        return 0;

    int min = 9999;

    for(int i = start; i < end; i++)
    {
        int left =
        minPartition(str, start, i);

        int right =
        minPartition(str, i+1, end);

        int total = left + right + 1;

        if(total < min)
            min = total;
    }

    return min;
}

int dpInterleave(char s1[],
                 char s2[],
                 char s3[])
{
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[100][100] = {0};

    dp[0][0] = 1;

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i > 0 &&
               s1[i-1] == s3[i+j-1])
            {
                dp[i][j] |= dp[i-1][j];
            }

            if(j > 0 &&
               s2[j-1] == s3[i+j-1])
            {
                dp[i][j] |= dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}

void smallestWindow(char str[],
                    char pat[])
{
    int freq[256] = {0};

    for(int i = 0; pat[i] != '\0'; i++)
        freq[pat[i]]++;

    int start = 0;
    int minLen = 9999;
    int startIndex = -1;

    int count = 0;

    for(int end = 0; str[end] != '\0'; end++)
    {
        if(freq[str[end]] > 0)
            count--;

        freq[str[end]]--;

        while(count == 0)
        {
            if(end-start+1 < minLen)
            {
                minLen = end-start+1;
                startIndex = start;
            }

            freq[str[start]]++;

            if(freq[str[start]] > 0)
                count++;

            start++;
        }
    }

    for(int i = startIndex;
        i < startIndex+minLen;
        i++)
    {
        printf("%c", str[i]);
    }
}

void containingWord(char arr[][20],
                    int n,
                    char word[])
{
    int found;

    for(int i = 0; i < n; i++)
    {
        found = 1;

        for(int j = 0; word[j] != '\0'; j++)
        {
            if(strchr(arr[i], word[j]) == NULL)
            {
                found = 0;
                break;
            }
        }

        if(found)
            printf("%s\n", arr[i]);
    }
}

void reverseSentence(char str[])
{
    int len = strlen(str);

    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            for(int j = i+1;
                str[j] != ' ' &&
                str[j] != '\0';
                j++)
            {
                printf("%c", str[j]);
            }

            printf(" ");
        }
    }

    for(int i = 0;
        str[i] != ' ' &&
        str[i] != '\0';
        i++)
    {
        printf("%c", str[i]);
    }
}

void longestPalindromeDP(char str[])
{
    int len = strlen(str);

    int dp[100][100] = {0};

    int start = 0;
    int max = 1;

    for(int i = 0; i < len; i++)
        dp[i][i] = 1;

    for(int l = 2; l <= len; l++)
    {
        for(int i = 0; i < len-l+1; i++)
        {
            int j = i+l-1;

            if(str[i] == str[j])
            {
                if(l == 2 ||
                   dp[i+1][j-1])
                {
                    dp[i][j] = 1;

                    if(l > max)
                    {
                        max = l;
                        start = i;
                    }
                }
            }
        }
    }

    for(int i = start;
        i < start+max;
        i++)
    {
        printf("%c", str[i]);
    }
}