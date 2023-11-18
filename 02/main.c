#include <stdio.h>
#include <stdlib.h>

const int RockScore = 1;
const int PaperScore = 2;
const int ScissorsScore = 3;
const int WinScore = 6;
const int DrawScore = 3;

int calculateScoreProb1(char opponent, char player);
int calculateScoreProb2(char opponent, char result);

int main(int argc, char** argv)
{
    FILE* file = fopen(argv[1], "r");
 
    if(file == NULL)
    {
        printf("Error opening file named \"%s\"\n", argv[1]);
    }

    int problemNo = atoi(argv[2]);
    printf("Solving problem no %d\n", problemNo);

    if(problemNo != 1 && problemNo != 2)
    {
        fprintf(stderr, "Incorrect problem no. input.\n");
        return -1;
    }

    char line[256];
    int score = 0;

    while(fgets(line, sizeof(line), file))
    {
        if(problemNo == 1)
        {
            score += calculateScoreProb1(line[0], line[2]);
        }
        else
        {
            score += calculateScoreProb2(line[0], line[2]);
        }
        
    }

    printf("Total score: %d\n", score);

    fclose(file);
    return 0;
}

int calculateScoreProb1(char opponent, char player)
{
    /*
    Opponent:
    A = Rock        
    B = Paper       
    C = Scissors    
        
    Player: 
    X = Rock        = 1
    Y = Paper       = 2
    Z = Scissor     = 3
    */
    int score = 0;

    if(player == 'X')
    {
        // Player = rock, wins against scissors
        score += RockScore;
        if(opponent == 'A')
        {
            score += DrawScore;
        }
        else if (opponent == 'C')
        {
            score += WinScore;
        }
    }
    else if (player == 'Y')
    {   
        // Player = Paper, wins against rock
        score += PaperScore;
        if(opponent == 'B')
        {
            score += DrawScore;
        }
        else if (opponent == 'A')
        {
            score += WinScore;
        }
    }
    else if (player == 'Z')
    {
        // Player = Scissors, wins against paper
        score += ScissorsScore;
        if(opponent == 'C')
        {
            score += DrawScore;
        }
        else if (opponent == 'B')
        {
            score += WinScore;
        }
        
    }
    
    return score;    
}

int calculateScoreProb2(char opponent, char result)
{
    /*
        X = loss
        Y = draw
        Z = win
    */
   int score = 0;

   if(opponent == 'A')
   {
       // rock
       if(result == 'X')
       {
           // loss, scissors
           score += ScissorsScore;
       }
       else if (result == 'Y')
       {
           // draw, rock
           score += DrawScore;
           score += RockScore;
       }
       else
       {
           // win, paper
           score += WinScore;
           score += PaperScore;
       }
   }
   else if (opponent == 'B')
   {
        // paper
        if(result == 'X')
        {
            // loss, rock
            score += RockScore;
        }
        else if (result == 'Y')
        {
            //draw, paper
            score += DrawScore;
            score += PaperScore;
        }
        else
        {
            // win, scissors
            score += WinScore;
            score += ScissorsScore;
        }
    }
    else
    {
        // scissors
        if(result == 'X')
        {
            // loss, paper
            score += PaperScore;
        }
        else if (result == 'Y')
        {
            // draw, scissors
            score += DrawScore;
            score += ScissorsScore;
        }
        else
        {
            // win, rock
            score += WinScore;
            score += RockScore;
        }
    }

    return score;
}