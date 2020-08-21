#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

void print_game_menu(void);
void print_game_rules(void);
void print_array(int arr[], int size);
int roll_dice(void);
char roll_prompt(void);
int check_three_kind(int arr[], int size);
int check_four_kind(int arr[], int size);
int check_yahtzee(int arr[], int size);
int check_full_house(int arr[], int size);
int check_small_straight(int arr[], int size);
int check_large_straight(int arr[], int size);
int select_combo_number(void);
void print_combination_list(int arr[], int size, int score);
int calculate_total_score(int arr[], int size);
