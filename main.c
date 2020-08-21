#include "Header.h"

/*
	Name: Koji Natsuhara

	Date: 10/21/2019

	Description: The purpose of the PA5 is to Develop and implement an interactive two-player Yahtzee game. 
	Yahtzee is a dice game that was invented by Milton Bradley and Edwin S. Lowe in 1956. The challenge 
	of the game is to outduel the other player by scoring the most points. Points are obtained by rolling 
	five 6-sided die across thirteen rounds. During each round, each player may roll the dice up to three 
	times to make one of the possible scoring combinations. Once a combination has been achieved by the player, 
	it may not be used again in future rounds, except for the Yahtzee combination may be used as many times 
	as the player makes the combination. Each scoring combination has different point totals. Some of these 
	totals are achieved through the accumulation of points across rolls and some are obtained as fixed sequences 
	of values.

	IN THIS PROGRAM I WILL HAVE TO:
	1. Use arrays
	2. Read, write to, and update files
	3. Apply standard library functions: fopen (), fclose (), fscanf (), and fprintf ()
	4. Compose decision statements ("if" conditional statements)
	5. Create and utilize compound conditions
	6. Be able to include while(), do-while(), and for() loops
*/

int main(void)
{
	srand(time(NULL));
	int player1[5] = { 0, 0, 0, 0, 0 }, player2[5] = { 0, 0, 0, 0, 0 };
	int collect1[7] = { 0, 0, 0, 0, 0, 0, 0}, collect2[7] = { 0, 0, 0, 0, 0, 0, 0};
	int combo1[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1, -1}, combo2[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1, -1};
	int scorecard1[14] = { 0 }, scorecard2[14] = { 0 };
	int score1 = 0, score2 = 0;
	int bonus1 = 0, bonus2 = 0;
	int upperscore1 = 0, upperscore2 = 0;
	int random = 0, reroll_count = 0, start = 0;
	char reroll_option = '\0', opt = '\0';
	int numberdice = 0;
	int select = 0;

	int option = 0;

	while (option != 3)
	{
		do
		{
			print_game_menu();
			option = get_option();
		} while (option < 1 || option > 3);
		system("cls");
		switch (option)
		{
		case 1:
			print_game_rules();
			break;
		case 2:
			for (int round = 0; round < 13; round++)
			{
				system("cls");
				printf("=============Player 1's Turn!=============\n");
				system("pause");
				if (start < 1)
				{
					start++;
					for (int i = 0; i < 5; i++)
					{
						random = roll_dice();
						player1[i] = random;
					}
					print_array(player1, 5);
				}
				start = 0;
				do
				{
					reroll_option = roll_prompt();
					if (reroll_option == 'Y')
					{
						reroll_count++;
						for (int i = 0; i < 5; i++)
						{
							printf("Do you want to reroll dice %d (Y/N)?: ", i + 1);
							scanf(" %c", &opt);
							if (opt == 'Y')
							{
								random = roll_dice();
								player1[i] = random;
							}
							print_array(player1, 5);
						}
					}
				} while (reroll_option == 'Y' && reroll_count < 3);
				reroll_count = 0;
				print_combination_list(scorecard1, 14, score1);
				select = select_combo_number();

				if (select == 1 && combo1[0] == -1)
				{
					//sum of 1
					combo1[0] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 1)
						{
							scorecard1[0] += 1;
						}
					}
					bonus1 += scorecard1[0];
				}
				else if (select == 2 && combo1[1] == -1)
				{
					//sum of 2
					combo1[1] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 2)
						{
							scorecard1[1] += 2;
						}
					}
					bonus1 += scorecard1[1];
				}
				else if (select == 3 && combo1[1] == -1)
				{
					//sum of 3
					combo1[2] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 3)
						{
							scorecard1[2] += 3;
						}
					}
					bonus1 += scorecard1[2];
				}
				else if (select == 4 && combo1[3] == -1)
				{
					//sum of 4
					combo1[3] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 4)
						{
							scorecard1[3] += 4;
						}
					}
					bonus1 += scorecard1[3];
				}
				else if (select == 5 && combo1[4] == -1)
				{
					//sum of 5
					combo1[4] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 5)
						{
							scorecard1[4] += 5;
						}
					}
					bonus1 += scorecard1[4];
				}
				else if (select == 6 && combo1[5] == -1)
				{
					//sum of 6
					combo1[5] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player1[i] == 6)
						{
							scorecard1[5] += 6;
						}
					}
					bonus1 += scorecard1[5];
				}
				else if (select == 7 && combo1[6] == -1)
				{
					//3 of a kind
					combo1[6] == 1;
					scorecard1[6] = check_three_kind(player1, 5);
				}
				else if (select == 8 && combo1[7] == -1)
				{
					//4 of a kind
					combo1[7] == 1;
					scorecard1[7] = check_four_kind(player1, 5);
				}
				else if (select == 9 && combo1[8] == -1)
				{
					//full house
					combo1[8] == 1;
					scorecard1[8] = check_full_house(player1, 5);
				}
				else if (select == 10 && combo1[9] == -1)
				{
					//small straight
					combo1[9] == 1;
					scorecard1[9] = check_small_straight(player1, 5);
				}
				else if (select == 11 && combo1[10] == -1)
				{
					//large straight
					combo1[10] == 1;
					scorecard1[10] = check_large_straight(player1, 5);
				}
				else if (select == 12 && combo1[11] == -1)
				{
					//yahtzee
					combo1[11] == 1;
					scorecard1[11] = check_yahtzee(player1, 5);
				}
				else if (select == 13 && combo1[12] == -1)
				{
					//chance
					combo1[12] == 1;
					for (int i = 0; i < 5; i++)
					{
						scorecard1[12] += player1[i];
					}
				}

				if (bonus1 > 63)
				{
					scorecard1[13] = 35;
				}

				score1 = calculate_total_score(scorecard1, 14);
				print_array(scorecard1, 14, score1);

				system("pause");
				system("cls");
				printf("=============Player 2's Turn!=============\n");
				system("pause");
				if (start < 1)
				{
					start++;
					for (int i = 0; i < 5; i++)
					{
						random = roll_dice();
						player2[i] = random;
					}
					print_array(player2, 5);
				}
				start = 0;
				do
				{
					reroll_option = roll_prompt();
					if (reroll_option == 'Y')
					{
						reroll_count++;
						for (int i = 0; i < 5; i++)
						{
							printf("Do you want to reroll dice %d (Y/N)?: ", i + 1);
							scanf(" %c", &opt);
							if (opt == 'Y')
							{
								random = roll_dice();
								player2[i] = random;
							}
							print_array(player2, 5);
						}
					}
				} while (reroll_option == 'Y' && reroll_count < 3);
				reroll_count = 0;
				print_combination_list(scorecard2, 14, score1);
				select = select_combo_number();

				if (select == 1 && combo2[0] == -1)
				{
					//sum of 1
					combo2[0] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 1)
						{
							scorecard2[0] += 1;
						}
					}
					bonus2 += scorecard2[0];
				}
				else if (select == 2 && combo2[1] == -1)
				{
					//sum of 2
					combo2[1] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 2)
						{
							scorecard2[1] += 2;
						}
					}
					bonus2 += scorecard2[1];
				}
				else if (select == 3 && combo2[1] == -1)
				{
					//sum of 3
					combo2[2] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 3)
						{
							scorecard2[2] += 3;
						}
					}
					bonus2 += scorecard2[2];
				}
				else if (select == 4 && combo2[3] == -1)
				{
					//sum of 4
					combo2[3] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 4)
						{
							scorecard2[3] += 4;
						}
					}
					bonus2 += scorecard2[3];
				}
				else if (select == 5 && combo2[4] == -1)
				{
					//sum of 5
					combo2[4] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 5)
						{
							scorecard2[4] += 5;
						}
					}
					bonus2 += scorecard2[4];
				}
				else if (select == 6 && combo2[5] == -1)
				{
					//sum of 6
					combo2[5] == 1;
					for (int i = 0; i < 5; i++)
					{
						if (player2[i] == 6)
						{
							scorecard2[5] += 6;
						}
					}
					bonus2 += scorecard2[5];
				}
				else if (select == 7 && combo2[6] == -1)
				{
					//3 of a kind
					combo2[6] == 1;
					scorecard2[6] = check_three_kind(player2, 5);
				}
				else if (select == 8 && combo2[7] == -1)
				{
					//4 of a kind
					combo2[7] == 1;
					scorecard2[7] = check_four_kind(player2, 5);
				}
				else if (select == 9 && combo2[8] == -1)
				{
					//full house
					combo2[8] == 1;
					scorecard2[8] = check_full_house(player2, 5);
				}
				else if (select == 10 && combo2[9] == -1)
				{
					//small straight
					combo2[9] == 1;
					scorecard2[9] = check_small_straight(player2, 5);
				}
				else if (select == 11 && combo2[10] == -1)
				{
					//large straight
					combo2[10] == 1;
					scorecard2[10] = check_large_straight(player2, 5);
				}
				else if (select == 12 && combo2[11] == -1)
				{
					//yahtzee
					combo2[11] == 1;
					scorecard2[11] = check_yahtzee(player2, 5);
				}
				else if (select == 13 && combo2[12] == -1)
				{
					//chance
					combo2[12] == 1;
					for (int i = 0; i < 5; i++)
					{
						scorecard2[12] += player2[i];
					}
				}

				if (bonus2 > 63)
				{
					scorecard2[13] = 35;
				}

				score1 = calculate_total_score(scorecard2, 14);
				print_array(scorecard2, 14, score2);
			}
			printf("===========================Player 1 Score Card===========================\n");
			print_combination_list(scorecard1, 14, score1);
			printf("=========================================================================\n");

			printf("===========================Player 2 Score Card===========================\n");
			print_combination_list(scorecard2, 14, score2);
			printf("=========================================================================\n");

			if (score1 > score2)
			{
				printf("Player 1 has one the game!\n");
			}
			else
			{
				printf("Player 2 has one the game!\n");
			}
			break;
		case 3:
			printf("Goodbye!\n");
			break;
		}
	}

	return 0;
}