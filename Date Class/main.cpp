#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;

   bool isValidName(const string &mn) const;

   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date() {
   this->day = 1;
   this->month = 1;
   this->year = 2000;
   this->monthName = "January";
}
 /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
       */
Date::Date(unsigned m, unsigned d, unsigned y) {
   bool invalid = false;
   if (0 < m && m <= 12) {
      this->month = m;
   }
   else if (m < 1) {
      this->month = 1;
      invalid = true;
   }
   else {
      this->month = 12;
      invalid = true;
   }
   this->year = y;
   this->monthName = name(month);
   
   if (d > daysPerMonth(this->month, this->year)) {
      invalid = true;
      this->day = daysPerMonth(this->month, this->year);
   }
   else if (d < 1) {
      invalid = true;
      this->day = 1;
   }
   else {
      this->day = d;
   }

   if (invalid) {
      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl;
   }
}
 
   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
Date::Date(const string &mn, unsigned d, unsigned y) {
   if(isValidName(mn)) {
      bool invalid = false;

      this->monthName = mn;
      monthName[0] = toupper(monthName[0]);
      this->year = y;
      this->month = number(monthName);
      if (d > daysPerMonth(this->month, this->year)) {
         invalid = true;
         this->day = daysPerMonth(this->month, this->year);
      }
      else if (d < 1) {
         invalid = true;
         this->day = 1;
      }
      else {
         this->day = d;
      }
      if (invalid) {
         cout << "Invalid date values: Date corrected to ";
         printNumeric();
         cout << "." << endl;
      }
   }
   else {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      this->monthName = "January";
      this->month = number(monthName);
      this->year = 2000;
      this->day = 1;
   }
}

void Date::printNumeric() const {
   cout << this->month << "/" << this->day << "/" << this->year;
}

void Date::printAlpha() const {
   cout << this->monthName << " " << this->day << ", " << this->year;
}
/*
(year % 4 == 0) implies leap year
except (year % 100 == 0) implies NOT leap year
except (year % 400 == 0) implies leap year
*/
bool Date::isLeap(unsigned y) const {
   bool leap = false;
   if (y % 4 == 0) {
      if (y % 100 == 0 && y % 400 == 0) {
         leap = true;
      }
      else if (y % 100 != 0) {
         leap = true;
      }
      
   }
   return leap;
}

/* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   int days = 30;
   if(isLeap(y) && m == 2) {
      days = 29;
   }
   else if (m == 2) {
      days = 28;
   }
   else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
   {
      days = 31;
   }
   return days;
}

bool Date::isValidName(const string &mn) const {
   bool valid = false;
 
   if(mn == "January" || mn == "january" || mn == "February" || mn == "february" || mn == "March" || mn == "march" || mn == "April" || mn == "april" || mn == "May" || mn == "may" || mn == "June" || mn == "june" || mn == "July" || mn == "july" || mn == "August" || mn == "august" || mn == "September" || mn == "september" || mn == "October" || mn == "october" || mn == "November" || mn == "november" || mn == "December" || mn == "december")
   valid = true;
   return valid;
}

string Date::name(unsigned m) const {
   string month;
   switch (m) {
      case 1:
         month = "January";
         break;
      case 2:
         month = "February";
         break;
      case 3:
         month = "March";
         break;
      case 4:
         month = "April";
         break;
      case 5:
         month = "May";
         break;
      case 6:
         month = "June";
         break;
      case 7:
         month = "July";
         break;
      case 8:
         month = "August";
         break;
      case 9:
         month = "September";
         break;
      case 10:
         month = "October";
         break;
      case 11:
         month = "November";
         break;
      default:
         month = "December";
         break;
   }
   return month;
}
/*
mn == "January" || mn == "january" 
mn == "Febuary" || mn == "febuary" 
mn == "March" || mn == "march" 
mn == "April" || mn == "april" 
mn == "May" || mn == "may" 
mn == "June" || mn == "june" 
mn == "July" || mn == "july" 
mn == "August" || mn == "august" 
mn == "September" || mn == "september" 
mn == "October" || mn == "october" 
mn == "November" || mn == "november" 
mn == "December" || mn == "december"
*/
unsigned Date::number(const string &mn) const {
   unsigned month = 12;
   if(mn == "January" || mn == "january" ) {
      month = 1;
   }
   else if (mn == "February" || mn == "february" ) {
      month = 2;
   }
   else if(mn == "March" || mn == "march" ) {
      month = 3;
   }
   else if ( mn == "April" || mn == "april" ) {
      month = 4;
   }
   else if (mn == "May" || mn == "may") {
      month = 5;
   }
   else if (mn == "June" || mn == "june") {
      month = 6;
   }
   else if (mn == "July" || mn == "july" ) {
      month = 7;
   }
   else if(mn == "August" || mn == "august") {
      month = 8;
   }
   else if(mn == "September" || mn == "september") {
      month = 9;
   }
    else if(mn == "October" || mn == "october" ) {
      month = 10;
   }
   else if (mn == "November" || mn == "november") {
      month = 11;
   }
   return month;
}



// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
