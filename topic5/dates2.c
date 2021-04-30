#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//  (Task 1) Define a function called date_read which uses scanf to get the 
//  data for a date. Fields are to be entered as three separate int values
//  in the format "%d-%d-%d". Dates will be entered with day first, followed by
//  month, followed by year.
// 
//  Parameters:
//      d - the address of an integer which will represent the day.
//      m - the address of an integer which will represent the month.
//      y - the address of an integer which will represent the year.
//
//  Returns:
//      The function must return a boolean value indicating the status of the 
//      I/O operation. The result is true if and only if three integer values 
//      have been successfully parsed using the designated format string.
//
//      Do not try to perform other data validation in this function.

bool date_read(int *d, int *m, int *y) {
    //INSERT CODE HERE
    // int date = scanf("%d", d);
    // int month = scanf("%d", m);
    // int year = scanf("%d", y);

    if(scanf("%d-%d-%d", d, m, y) == 3) {
        // printf("true");
        return true;
    } else {
        // printf("false");
        return false;
    }
}

//  (Task 2) Define a function called date_write which uses printf to 
//  display the value of a date in format "%d-%d-%d", with day followed by month
//  followed by year.
// 
//  Parameters:
//      d - an integer which will represent the day.
//      m - an integer which will represent the month.
//      y - an integer which will represent the year.
//
//  Returns:
//      Nothing.

int date_write(int d, int m, int y) {
    //INSERT CODE HERE
    printf("%d-%d-%d", d, m, y);
    return 0;
}

//  (Task 3) Define a function called date_compare which compares two
//  dates. Your implementation may assume that these values are valid dates.
// 
//  Parameters:
//      d1, m1, y1 - Three integers representing the first date. 
//      d2, m2, y2 - Three integers representing the second date. 
//
//  Returns:
//      An int which is:
//      -1  if the date represented by (d1, m1, y1) is before that 
//          represented by (d2, m2, y2);
//      0   if the two values represent the same date;
//      +1  otherwise.

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

//  (Task 4) Implement the date_valid function which determines if the 
//  supplied date is valid:
//  *   Year must be greater than or equal to 1.
//  *   Month must between 1 and 12 inclusive.
//  *   Day must be at least 1, with upper limits given below:
//      30 days: September (9), April (4), June (6), and November (11).
//      31 days: January (1), March (3), May (5), July (7), August (8), October (10), December (12).
//      28 or 29: February (2) (usually 28, but 29 in a leap year).
//  
//  A year is a leap year if it is divisible by 400, or if it is
//  divisible by 4 but not divisible by 100.
//  
//  Parameters:
//     d, m, y - three integers representing a date.
//
//  Returns:
//      Returns true if and only if the supplied date is valid according to 
//      the definition listed above.

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

//  (Task 5) Define a function called date_match which compares a query date to
//  a list of dates. The function returns the position of the first object in 
//  the list which satisfies a designated criterion.
//
//  If criterion is -1, then the function returns the position of 
//  the first date in the list that comes before the query date. If criterion is
//  +1, then the function returns the position of the first date in the list 
//  that comes after the query date. If criterion is 0, then the function returns 
//  the position of the first date in the list that is equal to the query.
// 
//  Parameters:
//      d, m, y    - Three integers which represents a query date.
//
//      dd, mm, yy - Three integer arrays, holding respective days, months and 
//                   years of a list of dates.
//
//      num_dates  - an int which tells the function how many elements there 
//                   are in the array.
//
//      criterion  - an int (guaranteed to be -1, 0, or 1) which defines the 
//                   matching criterion. 
//
//  Returns:
//      The integer position of the first item in the list which satisfies the 
//      matching criterion.
//
//      If num_dates is equal to or less than 0, the function returns -1.
//
//      If the query is not a valid date, the function returns -1.
//
//      If there is integer i for which 
//          0 <= i < num_dates,  
//      and
//          date_valid( dd[i], mm[i], yy[i] )
//      and
//          date_compare( dd[i], mm[i], yy[i], d, m, y ) == criterion
//      then 
//          the function returns i.
//
//      Otherwise the function returns -1.

int date_match(int qd, int qm, int qy, int *d, int *m, int *y, int num_items, int criteria) {
    //INSERT CODE HERE
    return -1;
}

