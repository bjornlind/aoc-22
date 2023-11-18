#include <stdio.h>
#include <stdlib.h>

// col1 = elfNbr, col2 = calories
int calories[3][2];

int currentCal;
int currentElf = 1;

void updateElfs(int newElf, int newCalories);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "No input file supplied.\n");
        return -1;
    }  
    
    char const* fileName = argv[1];
    FILE *file = fopen(fileName, "r");

    if(file == NULL)
    {
        fprintf(stderr, "Failed opening file named \"%s\".\n", fileName);
        return -1;
    }

    char line[256];
    
    while(fgets(line, sizeof(line), file))
    {
        if(line[0] == '\n' || feof(file))
        {
            if(feof)
            {
                currentCal += atoi(line);
            }

            updateElfs(currentElf, currentCal);

            // Reset current values
            currentCal = 0;
            currentElf++;
        }
        else
        {
            // Parse calorie value
            currentCal += atoi(line);
        }    
    }

    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        printf("Elf %d has %d calories\n", calories[i][0], calories[i][1]);
        sum += calories[i][1];
    }

    printf("These top three elves are carrying %d calories.\n", sum);
    fclose(file);

    return 0;
}

void updateElfs(int currentElf, int currentCal)
{
// Evaluate elfs properties, update max
    if(currentCal > calories[0][1])
    {
        // Move second elf to third
        calories[2][0] = calories[1][0];
        calories[2][1] = calories[1][1];

    // Move first elf to second
        calories[1][0] = calories[0][0];
        calories[1][1] = calories[0][1];

    // Move new elf to first
        calories[0][0] = currentElf;
        calories[0][1] = currentCal;
    }
    else if(currentCal > calories[1][1])
    {
        // Move second elf to third
        calories[1][0] = calories[2][0];
        calories[1][1] = calories[2][1];

    // Move new elf to second
        calories[1][0] = currentElf;
        calories[1][1] = currentCal;
    }
    else if(currentCal > calories[2][1])
    {
        // Move new elf to second
        calories[2][0] = currentElf;
        calories[2][1] = currentCal;
    }
}