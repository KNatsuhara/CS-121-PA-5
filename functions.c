#include "Header.h"

/*
Function: get_option
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: Asks user for an integer as an option.
Input Parameters: void
Returns: integer
Preconditions: Initialized integer variable for the function
Postconditions: An integer variable inputted by the user
*/

int get_option(void)
{
	int option = 0;
	printf("Input a valid option: ");
	scanf("%d", &option);
	return option;
}

/*
Function: print_game_menu
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: Prints out the game menu
Input Parameters: void
Returns: prints out the game menu to the screen
Preconditions: none
Postconditions: none
*/

void print_game_menu(void)
{
	printf("=========Yahtzee!=========\n");
	printf("1. Print game rules\n");
	printf("2. Start a game of Yahtzee\n");
	printf("3. Exit\n");
	printf("==========================\n");
}

/*
Function: print_game_rules
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: Prints out the game rules
Input Parameters: void
Returns: Prints out the game rules
Preconditions: none
Postconditions: none
*/

void print_game_rules(void)
{
	printf("1. The winner of this game is the one with the most points.\n");
	printf("2. Each player will play 13 rounds rolling 5 dice.\n");
	printf("3. Your goal is to match with all of the 13 different dice combinations given.\n");
	printf("4. If you roll all 5 dice you will be given the option to re-roll any of the dice.\n");
	printf("5. You can only roll the dice 3 times and after that you must select an option you have not already selected.\n");
	printf("6. If the upper section of your score card is above 63, you will be granted a bonus of 35 points.\n");
	printf("7. At the end of the 13 rounds the player with the most points wins.\!\n");
}

/*
Function: print_array
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will print out all the elements of the array
Input Parameters: int arr[], int size
Returns: void
Preconditions: The size of the array must be known in order for this function to work.
Postconditions: none
*/

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

/*
Function: print_array
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will print out all the elements of the array
Input Parameters: int arr[], int size
Returns: void
Preconditions: The size of the array must be known in order for this function to work.
Postconditions: none
*/

int roll_dice(void)
{
	int random = 0;

	random = rand() % 6 + 1;

	return random;
}

/*
Function: roll_prompt
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function asks the user for a char
Input Parameters: void
Returns: Char inputted by the user
Preconditions: An initalized character
Postconditions: A variable with the character inputted by the user
*/

char roll_prompt(void)
{
	char c = '\0';
	printf("Would you like to re-roll? (Y/N): ");
	scanf(" %c", &c);
	return c;
}

/*
Function: check_three_kind
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return the sum of the array
if there are 3 or more of the same numbers in the array.
Input Parameters: int arr[], int size
Returns: The sum of the array
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_three_kind(int arr[], int size)
{
	int collect1[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, sum = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect1[index]++;
		sum += arr[i];
	}
	for (int i = 0; i < 7; i++)
	{
		if (collect1[i] >= 3)
		{
			return sum;
		}
	}
	return 0;
}

/*
Function: check_four_kind
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return the sum of the array
if there are 4 or more of the same numbers in the array.
Input Parameters: int arr[], int size
Returns: The sum of the array
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_four_kind(int arr[], int size)
{
	int collect1[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, sum = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect1[index]++;
		sum += arr[i];
	}
	for (int i = 0; i < 7; i++)
	{
		if (collect1[i] >= 4)
		{
			return sum;
		}
	}
	return 0;
}

/*
Function: check_yahtzee
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return 50
if there are 5 identical integers in the array
Input Parameters: int arr[], int size
Returns: 50 or 0
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_yahtzee(int arr[], int size)
{
	int collect1[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect1[index]++;
	}
	for (int i = 0; i < 7; i++)
	{
		if (collect1[i] == 5)
		{
			return 50;
		}
	}
	return 0;
}

/*
Function: check_full_house
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return 25
if there are 3 identical integers and a pair of a different integer in the array
Input Parameters: int arr[], int size
Returns: 25 or 0
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_full_house(int arr[], int size)
{
	int collect1[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, triple = 0, pair = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect1[index]++;
	}
	for (int i = 0; i < 7; i++)
	{
		if (collect1[i] == 3)
		{
			triple++;
		}
		if (collect1[i] == 2)
		{
			pair++;
		}
	}
	if (triple == 1 && pair == 1)
	{
		return 25;
	}
	return 0;
}

/*
Function: check_small_straight
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return 30
if there is a run of at least 4 dice in the array
Input Parameters: int arr[], int size
Returns: 30 or 0
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_small_straight(int arr[], int size)
{
	int collect[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect[index]++;
	}
	if (collect[1] >= 1 && collect[2] >= 1 && collect[3] >= 1 && collect[4] >= 1)
	{
		return 30;
	}
	else if (collect[2] >= 1 && collect[3] >= 1 && collect[4] >= 1 && collect[5] >= 1)
	{
		return 30;
	}
	else if(collect[3] >= 1 && collect[4] >= 1 && collect[5] >= 1 && collect[6] >= 1)
	{
		return 30;
	}
	else
	{
		return 0;
	}
}

/*
Function: check_large_straight
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: This function will sort through an array and return 40
if there is a run of at 5 dice in the array
Input Parameters: int arr[], int size
Returns: 40 or 0
Preconditions: Must have an array the size of 5 between the values 1-6.
Postconditions: This function must be set to an index in an array
*/

int check_large_straight(int arr[], int size)
{
	int collect[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		index = arr[i];
		collect[index]++;
	}
	if (collect[1] >= 1 && collect[2] >= 1 && collect[3] >= 1 && collect[4] >= 1 && collect[5] >= 1)
	{
		return 40;
	}
	else if(collect[6] >= 1 && collect[2] >= 1 && collect[3] >= 1 && collect[4] >= 1 && collect[5] >= 1)
	{
		return 40;
	}
	else
	{
		return 0;
	}
}

/*
Function: select_combo_number
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: A function which repeatedly asks the user for an integer between 1 and 3
Input Parameters: void
Returns: Integer between 1 and 3
Preconditions: Initialized integer variable for the function
Postconditions: An integer variable inputted by the user
*/

int select_combo_number(void)
{
	int select = 0;
	do
	{
		printf("What game combination do you want to select?: ");
		scanf("%d", &select);
	} while (select < 1 || select > 13);

	return select;
}

/*
Function: print_comboination_list
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: A function which prints out the score of a player and the combinations used
Input Parameters: int arr[], int size, int score
Returns: void
Preconditions: The array inputed must be 14 elements long and the size must be inputted correctly
Postconditions: A printed scorecard of a player
*/

void print_combination_list(int arr[], int size, int score)
{
	printf("1. Sum of 1's: %d -------------------- 8. Four-of-a-kind: %d\n", arr[0], arr[7]);
	printf("2. Sum of 2's: %d -------------------- 9. Full House: %d\n", arr[1], arr[8]);
	printf("3. Sum of 3's: %d -------------------- 10. Small Straight: %d\n", arr[2], arr[9]);
	printf("4. Sum of 4's: %d -------------------- 11. Large Straight: %d\n", arr[3], arr[10]);
	printf("5. Sum of 5's: %d -------------------- 12. Yahtzee: %d\n", arr[4], arr[11]);
	printf("6. Sum of 6's: %d -------------------- 13. Chance: %d\n", arr[5], arr[12]);
	printf("7. Three-of-a-kind: %d --------------- 14. Bonus: %d\n", arr[6], arr[13]);
	printf("=============== Total Score: %d ============\n", score);
}

/*
Function: calculate_total_score
Date Created: 10/21/2019
Date Modified: 10/21/2019
Description: A function which calculates the total sum of an array and returns it as the total score
Input Parameters: int arr[], int size
Returns: An integer containing the sum of the entire array
Preconditions: The array inputed must be 14 elements long and the size must be inputted correctly
Postconditions: A variable with the total sum of the array
*/

int calculate_total_score(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < 14; i++)
	{
		sum += arr[i];
	}
	return sum;
}