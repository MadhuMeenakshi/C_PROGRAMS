
#include "file_handling.h"


/* =========================================
   1. Create File And Write Text
   ========================================= */

void createFile(void)
{
    char filename[100];
    char text[500];

    printf("Enter File Name: ");
    scanf("%s",filename);

    getchar();

    printf("Enter Text: ");
    fgets(text,sizeof(text),stdin);

    FILE *fp = fopen(filename,"w");

    if(fp == NULL)
    {
        printf("File Creation Failed\n");
        return;
    }

    fputs(text,fp);

    fclose(fp);

    printf("File Created Successfully\n");
}


/* =========================================
   2. Display File Contents
   ========================================= */

void displayFile(void)
{
    char filename[100];
    char ch;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}


/* =========================================
   3. Write Multiple Lines
   ========================================= */

void writeMultipleLines(void)
{
    char filename[100];
    char line[200];

    int n;

    printf("Enter File Name: ");
    scanf("%s",filename);

    printf("Number Of Lines: ");
    scanf("%d",&n);

    getchar();

    FILE *fp = fopen(filename,"w");

    if(fp == NULL)
    {
        return;
    }

    for(int i=0;i<n;i++)
    {
        printf("Line %d : ",i+1);

        fgets(line,sizeof(line),stdin);

        fputs(line,fp);
    }

    fclose(fp);

    printf("All Lines Saved\n");
}


/* =========================================
   4. Read Lines Into Array
   ========================================= */

void readLinesToArray(void)
{
    char filename[100];

    char lines[100][200];

    int count = 0;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(lines[count],
                sizeof(lines[count]),
                fp))
    {
        count++;
    }

    fclose(fp);

    printf("Stored Lines:\n");

    for(int i=0;i<count;i++)
    {
        printf("%s",lines[i]);
    }
}


/* =========================================
   5. Append Lines
   ========================================= */

void appendLines(void)
{
    char filename[100];
    char line[200];

    int n;

    printf("Enter File Name: ");
    scanf("%s",filename);

    printf("Number Of New Lines: ");
    scanf("%d",&n);

    getchar();

    FILE *fp = fopen(filename,"a");

    if(fp == NULL)
    {
        return;
    }

    for(int i=0;i<n;i++)
    {
        printf("Line %d : ",i+1);

        fgets(line,sizeof(line),stdin);

        fputs(line,fp);
    }

    fclose(fp);

    printf("Lines Appended Successfully\n");
}


/* =========================================
   6. Copy File
   ========================================= */

void copyFile(void)
{
    char source[100];
    char destination[100];

    char ch;

    printf("Source File: ");
    scanf("%s",source);

    printf("Destination File: ");
    scanf("%s",destination);

    FILE *src = fopen(source,"r");

    FILE *dst = fopen(destination,"w");

    if(src == NULL || dst == NULL)
    {
        printf("Error Opening File\n");
        return;
    }

    while((ch = fgetc(src)) != EOF)
    {
        fputc(ch,dst);
    }

    fclose(src);
    fclose(dst);

    printf("File Copied Successfully\n");
}


/* =========================================
   7. Delete File
   ========================================= */

void deleteFileDemo(void)
{
    char filename[100];

    printf("Enter File Name: ");
    scanf("%s",filename);

    if(remove(filename) == 0)
    {
        printf("File Deleted Successfully\n");
    }
    else
    {
        printf("Unable To Delete File\n");
    }
}


/* =========================================
   8. Read Variable From File
      And Write Variable To File
   ========================================= */

void readWriteVariable(void)
{
    char filename[100];

    int value;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("File Not Found\n");
        return;
    }

    fscanf(fp,"%d",&value);

    fclose(fp);

    printf("Read Value = %d\n",value);

    fp = fopen(filename,"w");

    value = 100;

    fprintf(fp,"%d",value);

    fclose(fp);

    printf("100 Written To File\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* =========================================
   9. Count Number Of Lines
   ========================================= */

void countLines(void)
{
    char filename[100];
    char ch;

    int count = 0;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            count++;
        }
    }

    fclose(fp);

    printf("Total Lines = %d\n",
           count + 1);
}


/* =========================================
   10. Count Words And Characters
   ========================================= */

void countWordsCharacters(void)
{
    char filename[100];
    char ch;

    int words = 0;
    int chars = 0;
    int inWord = 0;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        chars++;

        if(ch==' ' ||
           ch=='\n' ||
           ch=='\t')
        {
            inWord = 0;
        }
        else if(inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    printf("Words = %d\n",words);

    printf("Characters = %d\n",
           chars);
}


/* =========================================
   11. Display Contents And Line Count
   ========================================= */

void displayAndCountLines(void)
{
    char filename[100];
    char line[200];

    int count = 0;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(line,sizeof(line),fp))
    {
        printf("%s",line);

        count++;
    }

    fclose(fp);

    printf("\nTotal Lines = %d\n",
           count);
}


/* =========================================
   12. Remove Specific Line
   ========================================= */

void removeLine(void)
{
    char filename[100];

    int removeLineNo;
    int currentLine = 1;

    char buffer[500];

    printf("Enter File Name: ");
    scanf("%s",filename);

    printf("Line To Remove: ");
    scanf("%d",&removeLineNo);

    FILE *fp = fopen(filename,"r");

    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(buffer,sizeof(buffer),fp))
    {
        if(currentLine != removeLineNo)
        {
            fputs(buffer,temp);
        }

        currentLine++;
    }

    fclose(fp);
    fclose(temp);

    remove(filename);

    rename("temp.txt",
           filename);

    printf("Line Removed\n");
}


/* =========================================
   13. Modify Particular Line
   ========================================= */

void modifyLine(void)
{
    char filename[100];

    int targetLine;
    int currentLine = 1;

    char buffer[500];
    char newText[500];

    printf("Enter File Name: ");
    scanf("%s",filename);

    printf("Line Number: ");
    scanf("%d",&targetLine);

    getchar();

    printf("New Text: ");

    fgets(newText,
          sizeof(newText),
          stdin);

    FILE *fp = fopen(filename,"r");

    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(buffer,sizeof(buffer),fp))
    {
        if(currentLine == targetLine)
        {
            fputs(newText,temp);
        }
        else
        {
            fputs(buffer,temp);
        }

        currentLine++;
    }

    fclose(fp);
    fclose(temp);

    remove(filename);

    rename("temp.txt",
           filename);

    printf("Line Modified\n");
}


/* =========================================
   14. Replace Word In File
   ========================================= */

void replaceWord(void)
{
    char filename[100];

    char oldWord[50];
    char newWord[50];

    char line[1000];

    printf("Enter File Name: ");
    scanf("%s",filename);

    printf("Word To Replace: ");
    scanf("%s",oldWord);

    printf("Replacement Word: ");
    scanf("%s",newWord);

    FILE *fp = fopen(filename,"r");

    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(line,sizeof(line),fp))
    {
        char *pos;

        while((pos = strstr(line,
                            oldWord))
                            != NULL)
        {
            char buffer[1000];

            int index =
            pos - line;

            line[index] = '\0';

            strcpy(buffer,line);

            strcat(buffer,newWord);

            strcat(buffer,
                   pos +
                   strlen(oldWord));

            strcpy(line,buffer);
        }

        fputs(line,temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);

    rename("temp.txt",
           filename);

    printf("Word Replaced\n");
}


/* =========================================
   15. Convert To Uppercase
   ========================================= */

void toUpperFile(void)
{
    char filename[100];

    int ch;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(toupper(ch),
              temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);

    rename("temp.txt",
           filename);

    printf("Converted To Uppercase\n");
}


/* =========================================
   16. Convert To Lowercase
   ========================================= */

void toLowerFile(void)
{
    char filename[100];

    int ch;

    printf("Enter File Name: ");
    scanf("%s",filename);

    FILE *fp = fopen(filename,"r");

    FILE *temp = fopen("temp.txt","w");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(tolower(ch),
              temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);

    rename("temp.txt",
           filename);

    printf("Converted To Lowercase\n");
}



/* =========================================
   17. Capitalize First Letter Of Each Word
   ========================================= */

void capitalizeWords(void)
{
    char filename[100];
    int ch;
    int newWord = 1;

    printf("Enter File Name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(newWord && isalpha(ch))
        {
            ch = toupper(ch);
            newWord = 0;
        }

        if(ch == ' ' ||
           ch == '\n' ||
           ch == '\t')
        {
            newWord = 1;
        }

        fputc(ch, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Capitalized Successfully\n");
}


/* =========================================
   18. Display Lines In Reverse Order
   ========================================= */

void reverseLines(void)
{
    char filename[100];
    char lines[100][200];

    int count = 0;

    printf("Enter File Name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(lines[count],
                sizeof(lines[count]),
                fp))
    {
        count++;
    }

    fclose(fp);

    printf("Reverse Order:\n");

    for(int i=count-1;i>=0;i--)
    {
        printf("%s", lines[i]);
    }
}


/* =========================================
   19. Encrypt File
   Caesar Shift +3
   ========================================= */

void encryptFile(void)
{
    char filename[100];

    int ch;

    printf("Enter File Name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch + 3, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("File Encrypted\n");
}


/* =========================================
   20. Decrypt File
   Caesar Shift -3
   ========================================= */

void decryptFile(void)
{
    char filename[100];

    int ch;

    printf("Enter File Name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch - 3, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("File Decrypted\n");
}


/* =========================================
   21. Join Two Files Into Third File
   ========================================= */

void joinFiles(void)
{
    char file1[100];
    char file2[100];
    char output[100];

    int ch;

    printf("File 1: ");
    scanf("%s", file1);

    printf("File 2: ");
    scanf("%s", file2);

    printf("Output File: ");
    scanf("%s", output);

    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    FILE *out = fopen(output, "w");

    if(fp1 == NULL ||
       fp2 == NULL)
    {
        return;
    }

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, out);
    }

    fputc('\n', out);

    while((ch = fgetc(fp2)) != EOF)
    {
        fputc(ch, out);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(out);

    printf("Files Joined\n");
}


/* =========================================
   22. Merge Alternate Lines
   ========================================= */

void mergeAlternateLines(void)
{
    char file1[100];
    char file2[100];
    char output[100];

    char line1[200];
    char line2[200];

    printf("File 1: ");
    scanf("%s", file1);

    printf("File 2: ");
    scanf("%s", file2);

    printf("Output File: ");
    scanf("%s", output);

    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    FILE *out = fopen(output, "w");

    if(fp1 == NULL ||
       fp2 == NULL)
    {
        return;
    }

    while(1)
    {
        char *r1 =
        fgets(line1,sizeof(line1),fp1);

        char *r2 =
        fgets(line2,sizeof(line2),fp2);

        if(r1 == NULL &&
           r2 == NULL)
        {
            break;
        }

        if(r1)
        {
            fputs(line1,out);
        }

        if(r2)
        {
            fputs(line2,out);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(out);

    printf("Alternate Merge Done\n");
}


/* =========================================
   23. Append One File To Another
   ========================================= */

void appendFileToAnother(void)
{
    char file1[100];
    char file2[100];

    int ch;

    printf("Main File: ");
    scanf("%s", file1);

    printf("File To Append: ");
    scanf("%s", file2);

    FILE *mainFile =
    fopen(file1,"a");

    FILE *extraFile =
    fopen(file2,"r");

    if(mainFile == NULL ||
       extraFile == NULL)
    {
        return;
    }

    while((ch = fgetc(extraFile))
            != EOF)
    {
        fputc(ch, mainFile);
    }

    fclose(mainFile);
    fclose(extraFile);

    printf("Append Successful\n");
}


/* =========================================
   24. Compare Two Files
   ========================================= */

int compareFiles(const char *file1,
                 const char *file2)
{
    FILE *fp1 = fopen(file1,"r");
    FILE *fp2 = fopen(file2,"r");

    int ch1;
    int ch2;

    if(fp1 == NULL ||
       fp2 == NULL)
    {
        return -1;
    }

    do
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if(ch1 != ch2)
        {
            fclose(fp1);
            fclose(fp2);

            return 0;
        }

    }while(ch1 != EOF &&
           ch2 != EOF);

    fclose(fp1);
    fclose(fp2);

    return 1;
}

/* =========================================
   25. List Files In Directory
   ========================================= */

void listDirectoryFiles(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);

    if(dir == NULL)
    {
        printf("Unable to open directory\n");
        return;
    }

    printf("Files:\n");

    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}


/* =========================================
   26. Find File Size
   ========================================= */

long fileSize(const char *filename)
{
    FILE *fp;

    long size;

    fp = fopen(filename,"rb");

    if(fp == NULL)
    {
        return -1;
    }

    fseek(fp,0,SEEK_END);

    size = ftell(fp);

    fclose(fp);

    return size;
}


/* =========================================
   27. Last Modification Time
   ========================================= */

void lastModifiedTime(const char *filename)
{
    struct stat info;

    if(stat(filename,&info) != 0)
    {
        printf("Cannot access file\n");
        return;
    }

    printf("Last Modified: %s",
           ctime(&info.st_mtime));
}


/* =========================================
   28. Common Directory Path
   ========================================= */

void commonDirectoryPath(void)
{
    char paths[3][200] =
    {
        "/home/user/docs/a.txt",
        "/home/user/docs/b.txt",
        "/home/user/docs/old/c.txt"
    };

    char common[200];

    int i = 0;

    while(paths[0][i] &&
          paths[1][i] &&
          paths[2][i] &&
          paths[0][i] == paths[1][i] &&
          paths[1][i] == paths[2][i])
    {
        common[i] = paths[0][i];
        i++;
    }

    common[i] = '\0';

    char *lastSlash =
    strrchr(common,'/');

    if(lastSlash)
    {
        *lastSlash = '\0';
    }

    printf("Common Path = %s\n",
           common);
}


/* =========================================
   29. Employee Database
   ========================================= */

void employeeDatabase(void)
{
    FILE *fp;

    char name[50];

    int age;

    fp = fopen("employees.txt","a");

    if(fp == NULL)
    {
        return;
    }

    printf("Name : ");
    scanf("%s",name);

    printf("Age : ");
    scanf("%d",&age);

    fprintf(fp,"%s %d\n",
            name,
            age);

    fclose(fp);

    printf("Employee Added\n");
}


/* =========================================
   30. Grocery Inventory
   ========================================= */

void groceryInventory(void)
{
    FILE *fp;

    char item[50];

    int qty;

    float price;

    fp = fopen("inventory.txt","a");

    if(fp == NULL)
    {
        return;
    }

    printf("Item : ");
    scanf("%s",item);

    printf("Quantity : ");
    scanf("%d",&qty);

    printf("Price : ");
    scanf("%f",&price);

    fprintf(fp,
            "%s %d %.2f\n",
            item,
            qty,
            price);

    fclose(fp);

    printf("Inventory Updated\n");
}


/* =========================================
   31. Command Line Sum To File
   ========================================= */

void commandLineSumToFile(int argc,
                          char *argv[])
{
    int sum = 0;

    for(int i=1;i<argc-1;i++)
    {
        sum += atoi(argv[i]);
    }

    FILE *fp =
    fopen(argv[argc-1],"w");

    if(fp == NULL)
    {
        return;
    }

    fprintf(fp,"%d",sum);

    fclose(fp);

    printf("Sum Written To File\n");
}


/* =========================================
   32. Count Lines Ending
       With Semicolon
   ========================================= */

void countSemicolonLines(void)
{
    char filename[100];

    char line[500];

    int count = 0;

    printf("File Name : ");
    scanf("%s",filename);

    FILE *fp =
    fopen(filename,"r");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(line,
                sizeof(line),
                fp))
    {
        int len = strlen(line);

        while(len > 0 &&
             (line[len-1]=='\n' ||
              line[len-1]=='\r'))
        {
            len--;
        }

        if(len > 0 &&
           line[len-1] == ';')
        {
            count++;
        }
    }

    fclose(fp);

    printf("Lines ending with ';' = %d\n",
           count);
}


/* =========================================
   33. Count Blank Lines
   ========================================= */

void countBlankLines(void)
{
    char filename[100];

    char line[500];

    int count = 0;

    printf("File Name : ");
    scanf("%s",filename);

    FILE *fp =
    fopen(filename,"r");

    if(fp == NULL)
    {
        return;
    }

    while(fgets(line,
                sizeof(line),
                fp))
    {
        int blank = 1;

        for(int i=0; line[i]; i++)
        {
            if(line[i] != ' ' &&
               line[i] != '\t' &&
               line[i] != '\n' &&
               line[i] != '\r')
            {
                blank = 0;
                break;
            }
        }

        if(blank)
        {
            count++;
        }
    }

    fclose(fp);

    printf("Blank Lines = %d\n",
           count);
}