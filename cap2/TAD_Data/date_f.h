#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME 11

typedef struct
{
    int day, month, year;
}DATE;

enum months
{
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

DATE fill(int day, int month, int year);

bool validate(DATE date);

bool date_gen_from_days(int days, int year, DATE *date);

int qty_days_until_now(DATE date);

int qty_days_in_month(bool leap_year, int month);

bool is_leap(int year);

bool test_str_date(char *str_date, DATE *date);

void print_date(DATE date);
//
//char* formatar(int format_size);
