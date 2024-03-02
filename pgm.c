/*
    Name: Voting Mechine
    Author: Navaneeth P P
    Date of Creation: October 26, 2023
    Last Modified on: October 29, 2023
    Requirments: None
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct candidate
{
    char candidate_name[20];
    int votes;
};


void main()
{
    int number_of_candidates, i, vote, voter, j, minimum, temp, winner = 0, invalid_vote = 0;

    // Clear the screen
    system("clear");

    // Reading total number of candidates
    printf("Enter total number of candidates: ");
    scanf("%d", &number_of_candidates);

    if (number_of_candidates <= 0 || number_of_candidates >= 100)
    {
        printf("Invalid number of candidtaes\n");
    }
    else
    {
        struct candidate candidates[number_of_candidates];

        // Reading candidate details
        printf("Enter candidate names:\n");
        getchar();
        for ( i = 0; i < number_of_candidates; i++)
        {
            printf("%d ", i + 1);
            fgets(candidates[i].candidate_name, 20, stdin);
            printf("Stored successfully.\n\n");
        }
        

        // Clear the screen
        system("clear");

        // Printing total candidates and intializing votes to zero.
        printf("  Candidates\n");
        for ( i = 0; i < number_of_candidates; i++)
        {
            printf("%d %s\n", i + 1, candidates[i].candidate_name);
            candidates[i].votes = 0;
        }

        // Reading total voters.
        printf("Enter the total number of voters: ");
        scanf("%d", &voter);

        // Reading permision to start the election
        printf("Please press 'enter' key to start the election...");
        getchar();
        system("clear");

        // Counting the votes for each candidates
        // When user enter the serial no. of candidate, it will be calculated as a vote.
        for ( i = 0; i < voter; i++)
        {
            printf("  Candidates\n");
            for ( j = 0; j < number_of_candidates; j++)
                printf("%d %s\n", j + 1, candidates[j].candidate_name);

            printf("\nEnter Candidate's Serial No. to cast votes.\nOnly after 2 seconds the next voter can cast his or her vote.\n");

            printf("Voter %d: ", i + 1);
            scanf("%d", &vote);
            
            if (vote > number_of_candidates || vote <= 0)
            {
                printf("Invalid vote.\n");
                invalid_vote++;
            }
            else
                candidates[vote - 1].votes += 1;
            
            sleep(1);
            system("clear");
            sleep(2);
        }

        printf("All votes are correctly recorded. Votes will be published within 5 seconds.\n");
        sleep(5);

        // Total votes printing
        printf("Votes\tCandidate Name");
        for ( i = 0; i < number_of_candidates; i++)
            printf("\n%d\t%s", candidates[i].votes, candidates[i].candidate_name);
        printf("\nInvalid Votes\t%d\n", invalid_vote);

        // Winner desiding segment
        for ( i = 0; i < number_of_candidates - 1; i++)
        {
            if (candidates[i].votes > candidates[winner].votes)
                winner = i;
        }

        printf("\n\n");
        printf("The winner is %s", candidates[winner].candidate_name);
        printf("And he is won by %d votes. ", candidates[winner].votes);
        printf("Congragulations %s", candidates[winner].candidate_name);
    }
}