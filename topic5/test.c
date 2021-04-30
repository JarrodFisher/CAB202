#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool date_read(int *d, int *m, int *y) {
    //INSERT CODE HERE

    if(scanf("%d-%d-%d", d, m, y) == 3) {
        printf("date read into array correctly \n");
        return true;
    } else {
        printf("date not read into array correctly\n");
        return false;
    }
}

int date_write(int d, int m, int y) {
    //INSERT CODE HERE
    printf("%d-%d-%d", d, m, y);
    return 0;
}

int date_compare(int d1, int m1, int y1, int d2, int m2, int y2) {
    //INSERT CODE HERE
    if (d1 == d2 && m1 == m2 && y1 == y2) {
        return 0;
    } else {
        if (y1 < y2) {
            return -1;
        } else if (y1 == y2 && m1 < m2) {
            return -1;
        } else if (y1 == y2 && m1 == m2 && d1 < d2) {
            return -1;
        } else {
            return 1;
        }
    }
}

bool date_valid(int d, int m, int y) {
    //INSERT CODE HERE
    int a;
	int b;
	int c;
	
	a = y%4; //divides by 4
	b = y%100; //divides by 100
	c = y%400; //divides by 400

    if (y >= 1 && m >= 1 && m <= 12 && d >= 1 && d <= 31) { 
        if (b == 0 && c == 0) { // case 1 //checks  divisible by 100 rule AND divisible by 400 rule
            // leap year
            if (m == 2) {
                if (d <= 29) {
                    //printf(" 1date_valid: true\n");
                    return true;
                } else {
                    //printf(" 2date_valid: false\n");
                    return false;
                }
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d <= 30) {
                    //printf(" 3date_valid: true\n");
                    return true;
                } else {
                    //printf(" 4date_valid: false\n");
                    return false;
                }
            } else if (m == 1 || m == 3 || m == 5 || m== 7 || m == 8 || m == 10 || m == 12) {
                if (d <= 31) {
                    //printf(" 5date_valid: true\n");
                    return true;
                } else {
                    //printf(" 6date_valid: false\n");
                    return false;
                }
            } else {
                //printf(" 7date_valid: false\n");
                return false;
            }

        } else if (a == 0 && b == 0) { // case 2 //checks divisible by 4 rule AND divisible by 100 rule
            // not a leap year
            if (m == 2) {
                if (d <= 28) {
                    //printf(" 8date_valid: true\n");
                    return true;
                } else {
                    //printf(" 9date_valid: false\n");
                    return false;
                }
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d <= 30) {
                    //printf(" 10date_valid: true\n");
                    return true;
                } else {
                    //printf(" 11date_valid: false\n");
                    return false;
                }
            } else if (m == 1 || m == 3 || m == 5 || m== 7 || m == 8 || m == 10 || m == 12) {
                if (d <= 31) {
                    //printf(" 12ate_valid: true\n");
                    return true;
                } else {
                    //printf(" 13date_valid: false\n");
                    return false;
                }
            } else {
                //printf(" 14date_valid: false\n");
                return false;
            }

        } else if (a == 0) { //case 3 //checks divisible by 4 rule
            // leap year
            if (m == 2) {
                if (d <= 29) {
                    //printf(" 15date_valid: true\n");
                    return true;
                } else {
                    //printf(" 16date_valid: false\n");
                    return false;
                }
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d <= 30) {
                    //printf(" 17date_valid: true\n");
                    return true;
                } else {
                    //printf(" 18date_valid: false\n");
                    return false;
                }
            } else if (m == 1 || m == 3 || m == 5 || m== 7 || m == 8 || m == 10 || m == 12) {
                if (d <= 31) {
                    //printf(" 19date_valid: true\n");
                    return true;
                } else {
                    //printf(" 20date_valid: false\n");
                    return false;
                }
            } else {
                //printf(" 21date_valid: false\n");
                return false;
            }

        } else { // case 4
            if (m == 2) {
                if (d <= 28) {
                    //printf(" 22date_valid: true\n");
                    return true;
                } else {
                    //printf(" 23date_valid: false\n");
                    return false;
                }
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                if (d <= 30) {
                    //printf(" 24date_valid: true\n");
                    return true;
                } else {
                    //printf(" 25date_valid: false\n");
                    return false;
                }
            } else if (m == 1 || m == 3 || m == 5 || m== 7 || m == 8 || m == 10 || m == 12) {
                if (d <= 31) {
                    //printf(" 26date_valid: true\n");
                    return true;
                } else {
                    //printf(" 27date_valid: false\n");
                    return false;
                }
            } else {
                //printf(" 28date_valid: false\n");
                return false;
            }
        }
    } else {
        return false;
    }
}

int date_match(int qd, int qm, int qy, int d[], int m[], int y[], int num_items, int criteria) {
    //INSERT CODE HERE
    if (num_items <= 0) {
        return -1;
    }

    printf("\n\nQuery Date: %d-%d-%d\n", qd, qm, qy);
    for (int j = 0; j < num_items; j++) {
        printf("Array date %d: %d-%d-%d\n", (j+1), d[j], m[j], y[j]);

        if (date_valid(d[j], m[j], y[j]) && date_compare(d[j], m[j], y[j], qd, qm, qy) == criteria) {
            return j;
        } else if (!date_valid(d[j], m[j], y[j])) {
            printf("\n",date_valid(d[j], m[j], y[j]));
            return -1;
        }
    }
    return -1;
}
// ----------------------------------------------------------------------------------------------------------------

#define MAX_ITEMS (100)

int main(void) {
    int query_day, query_month, query_year;
    printf("Input query date using format %s: ", "%d-%d-%d");
    date_read(&query_day, &query_month, &query_year);

    int dd[MAX_ITEMS], mm[MAX_ITEMS], yy[MAX_ITEMS];
    int num_items;

    // Get number of ref_dates.
    printf("Please enter number of items (up to %d) that will be processed: ", MAX_ITEMS);
    scanf("%d", &num_items);

    // if number of ref_dates exceeds array size, restrict it to that value.
    if (num_items > MAX_ITEMS)
    {
        num_items = MAX_ITEMS;
    }

    for (int i = 0; i < num_items; i++)
    {
        printf("Please enter item %d of %d using format %s, with day first and year last: ", (i + 1), num_items, "%d-%d-%d");
        bool ok = date_read(&dd[i], &mm[i], &yy[i]);

        if ( ! ok ) {
            num_items = i;
            break;
        }
    }

    for (int i = 0; i < num_items; i++)
    {
        date_write(dd[i], mm[i], yy[i]);

        if (!date_valid(dd[i], mm[i], yy[i]))
        {
            printf(" is not valid.\n");
            continue;
        }

        int cmp = date_compare(dd[i], mm[i], yy[i], query_day, query_month, query_year);

        if (cmp < -1 || cmp > 1)
        {
            printf("Error!!! date_compare is broken.\n");
            exit(1);
        }

        char * labels[] = { 
            "less than", 
            "equal to", 
            "greater than" 
        };

        printf(" is %s ", labels[cmp + 1]);
        date_write(query_day, query_month, query_year);
        printf("\n");
    }

    const int criterion = -1;

    int match_idx = date_match(
        query_day, query_month, query_year, 
        dd, mm, yy, 
        num_items, criterion
    );

    if (match_idx >= 0)
    {
        printf("The first valid date matching the search criterion is ");
        date_write(dd[match_idx], mm[match_idx], yy[match_idx]);
    }
    else
    {
        printf("There is no valid date matching the search criterion.\n");
    }

    return 0;
}
