#include <iostream>
#include <cmath>
#include <string>

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define CHAR word[pos]

#define SPECIAL_CHAR ch == 'A' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 's' || ch == 'G'
#define SPECIAL_NUM ch == '4' || ch == '3' || ch == '1' || ch == '0' || ch == '5' || ch == '6'

using namespace std;

int special_chars_quantity(char*);
void switch_char(int,char*);
void switch_right_side_back_to_letters(int,char*);
bool is_special_letter(char);
bool is_special_number(char);
void make_the_swap(int,char*);
int generate_alphanum_wordlst(char*,char*);

int main(int argc, char *argv[])
{
    // test if files exist using bash
    generate_alphanum_wordlst(argv[1],argv[2]);

	return 0;
}

int generate_alphanum_wordlst(char *dicionary, char *wordlist) // switch_char all the possible combinations
{
	int n_special_chars, pos, i;
	char word[40];
	FILE *wd = fopen(wordlist,"a");
	FILE *dc = fopen(dicionary,"r");

	while (fgetc(dc) != EOF) {
		fscanf(dc,"%s",word);
		pos = strlen(word)-1;
		n_special_chars = special_chars_quantity(word);
		fprintf(wd,"%s\n",word);
		for (i=1; i<pow(2,n_special_chars); i++) {
			switch_char(pos,word);
			fprintf(wd,"%s\n",word);
		}
	}

	return 0;
}

int special_chars_quantity(char *word) // count number of characters that can be swaped
{
	int n = 0;
	for (int pos = 0; pos < (int) strlen(word); pos++) {
		if (is_special_letter(CHAR)) n++;
	}

	return n;
}

void switch_char(int pos, char *word)
{
	if (is_special_letter(CHAR)) {
		make_the_swap(pos,word);
		pos++;
		switch_right_side_back_to_letters(pos,word);
	} else {
		pos--;
		switch_char(pos,word);
	}
}

void switch_right_side_back_to_letters(int pos, char *word) // swap numbers to letters from 'pos' on the right side
{
	while (pos < (int) strlen(word)) {
		if (is_special_number(CHAR)) {
			make_the_swap(pos,word);
		}
		pos++;
	}
}

bool is_special_letter(char ch)
{
	if (SPECIAL_CHAR) {
		return true;
	} else {
		return false;
	}
}

bool is_special_number(char ch)
{
	if (SPECIAL_NUM) {
		return true;
	} else {
		return false;
	}
}

void make_the_swap(int pos, char *word) // num to letter and letter to char
{
	switch (CHAR) {
		case 'A': CHAR = '4'; break;
		case 'o': CHAR = '0'; break;
		case 'e': CHAR = '3'; break;
		case 'i': CHAR = '1'; break;
		case 'G': CHAR = '6'; break;
		case 's': CHAR = '5'; break;
		case '4': CHAR = 'a'; break;
		case '0': CHAR = 'o'; break;
		case '3': CHAR = 'e'; break;
		case '1': CHAR = 'i'; break;
		case '5': CHAR = 's'; break;
		case '6': CHAR = 'G'; break;
		default: break;
	}
}
