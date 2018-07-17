/*
Andrew Koontz
CSC 389
High Low Game
*/

#include <stdio.h>
#include <time.h>

// Creating Variables
int currPlayer;
int guess;
int p1pass = 3;
int p2pass = 3;
int p1passed = 0;
int p2passed = 0;
int win = 0;

main ()
{	
	srand(time(NULL));
	int randPlayer;
	randPlayer = rand() % 2;//Randomly choose starting player
	randPlayer++;
	int randNum;
	randNum = rand() % 100;//Randomly choose number
	randNum++;
	
	//Main Program Playing Game
	while (win != 1)
	{
		printf("Player Number?\n");
		scanf("%d", &currPlayer);
		
		//Deciding if it is the current players turn
		if (currPlayer == randPlayer)
		{	
			if (currPlayer == 1)
			{
				randPlayer = playerTurn(1, randNum);
			}
			else
			{
				randPlayer = playerTurn(2, randNum);
			}
		}
		else
		{
			printf("You have to wait your turn.\n");
		}

	}
}
	
	int playerTurn(int playerNum, int randNum)
	{
		int currPlayer;
		printf("Enter Your Guess Between 1 and 100 or Enter '0' to Pass:\n");//Player enters guess
		scanf("%d", &guess);
		
		if (guess == 0)//Check to see if they passed
		{
			currPlayer = pass(playerNum, randNum);
			return currPlayer;
		}
		else
		{
			if (guess > randNum)//Check if number is too high
			{
				printf("Too High.\n");
				if (playerNum == 1)
				{
					playerNum = 2;
				}
				else
				{
					playerNum = 1;
				}
			}
			else if(guess < randNum)//Check if number it too low
			{
				printf("Too Low.\n");
				if (playerNum == 1)
				{
					playerNum = 2;
				}
				else
				{
					playerNum = 1;
				}
			}
			else
			{
				printf("Correct!\n");//If not too high or low, it is correct
				win = 1;
			}
			return playerNum;
		}
	}
	
	int pass(int playerNum, int randNum)
	{
		if(playerNum == 1)
		{
			if (p1pass != 0)
			{
				p1pass--;
				p1passed++;
				printf("You have passed ");
				printf("%d", p1passed);
				printf(" number of times, you have ");
				printf("%d", p1pass);
				printf(" more times left.\n");
				playerNum = 2;
				return playerNum;
			}
			else
			{
				printf("You are all out of passes.\n");
				playerTurn(1, randNum);
			}
		}
		else if(playerNum == 2)
		{
			if (p2pass != 0)
			{
				p2pass--;
				p2passed++;
				printf("You have passed ");
				printf("%d", p2passed);
				printf(" number of times, you have ");
				printf("%d", p2pass);
				printf(" more times left.\n");
				playerNum = 1;
				return playerNum;
			}
			else
			{
				printf("You are all out of passes.\n");
				playerTurn(2, randNum);
			}
		}
	}