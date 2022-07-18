#include <cs50.h>
#include <stdio.h>
#include <strings.h>

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//set the maximum of candidates and voters
#define MAX_CANDIDATES 9
#define MAX_VOTERS 50

//global variables
int preferences[MAX_VOTERS][MAX_CANDIDATES];
candidate candidates[MAX_CANDIDATES];
int candidate_count;
int voter_count;

//calling functions
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    //verifies if the arguments are valids
    candidate_count = argc - 1;
    if (candidate_count < 2)
    {
        printf("Invalid arguments. Usage: more than 1 candidate.\n");
        return 1;
    }
    else if (candidate_count > MAX_CANDIDATES)
    {
        printf("Invalida arguments. Usage: less than %i candidates.\n", MAX_CANDIDATES);
        return 1;
    }

    //filling in the typedef struct for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[(i + 1)];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }


    do
    {
        //get and verifies if the number of voters is valid
        voter_count = get_int("Number of voters: ");
        if (voter_count > MAX_VOTERS)
        {
            printf("Maximum number of voters is %i, please type a valid number\n", MAX_VOTERS);
        }
        else if (voter_count <= 0)
        {
            printf("The minimun number of voters is 1, please type a valid number\n");
        }
    }
    while (voter_count > MAX_VOTERS || voter_count <= 0);

    for (int i = 0; i < voter_count; i++)
    {
        //getting and ranking the votes
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("RANK %i OF VOTER %i\n %i# pick of voter %i: ", j + 1, i + 1, j + 1, i + 1);
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
            }
        }
        printf("\n");

    }

    while (true)
    {
        //second turn
        tabulate();

        //verifies is the election has a winner
        bool has_awinner = print_winner();
        if (has_awinner == true)
        {
            break;
        }

        //find the minimun number of votes
        int min = find_min();

        bool tie = is_tie(min);

        //if everyone has the same amount of votes, is a tie and everyone wins
        if (tie == true)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (candidates[i].eliminated == false)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
        }

        //eliminating candidates with the smallest number of votes
        eliminate(min);
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

//function to compare whether the votes are valid and rank the votes
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i].name) == 0) //case insensitive function that compares if the user typed a valid vote
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

//second turn of the election to non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int voted_candidate = preferences[i][j];
            if (!candidates[voted_candidate].eliminated)
            {
                candidates[voted_candidate].votes++;
                break;
            }
        }
    }
    return;
}

//funtion to print the winner if is not a tie
bool print_winner(void)
{
    int half_of_votes = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > half_of_votes)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

//funtiont to return the minimun number o votes of a candidate that was not eliminated
int find_min(void)
{
    int min = MAX_VOTERS;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

//funtion to determinate if the candidates are tied
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes > min)
        {
            return false;
        }
    }
    return true;
}

//function to eliminate one, or all, candidates that have the minimum number of votes
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
