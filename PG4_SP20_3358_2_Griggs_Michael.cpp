//serial number: 11
//Author: Michael Griggs
//Due Date: April 6th, 2020
//Spring 2020 - CS3358 - 252
//instructor: Husain Gholoom
//Description: this program generates an array and preforms recursive functions that display the function in various ways to demonstrate
//understanding of recursive functions in c++


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

/*this function generates random numbers to put into the array*/
int randomNum(){
	int max, min, range;
  max = 375;
  min = 10;
	range = max-min + 1;
	return rand()%range + min;
}


/*this function gets the square of a number*/
int square(int p){
  return p * p;
}

/*this recursive function displys the table of squares*/
void squareDisplay(int c, int d[], int g){

  if(c < g){
    int n = square(d[c]);
    cout<<d[c]<<setw(10)<<n<<endl;
    c++;
    squareDisplay(c, d, g);
  }
  else if(c >= g){
    cout<<endl;
  }
}

/* recursive function to display the array in reverse */
void reverseDisplay(int c, int d[]){

  if(c > 0 || c == 0 ){
    c--;
    cout<<d[c]<<" ";
    reverseDisplay( c, d);
  }
  else if(c < 0){
    cout<<endl;
  }
}

/* this function adds digits of a number */
int sumDigits(int x){
  int sum = 0;
  while(x != 0){
    sum = sum + x % 10;
    x = x / 10;
  }
  return sum;
}

/* recursive function or calculating and displaying sum of digits */
void displaySum(int c, int d[], int g){
  if(c < g){
    cout<<"position "<< c <<" equals "<<setw(3);
    cout<<d[c]<<setw(3)<<" and has a sum of digits of: ";
    int v = sumDigits(d[c]);
    cout<<setw(3)<<v<<endl;
    c++;
    displaySum(c, d, g);
  }
  else if(c >= g){
    cout<<endl;
  }
}


/* function to determine prime or not prime */
bool isPrime(int x){
  if (x % 2 == 0 || x % 3 == 0 || x % 11 == 0 || x % 13 == 0){
    return false;
  }
  else{
    return true;
  }
}

/* recursive function to determine prime status of each number in array and display it*/
void displayPrime(int c, int d[], int g){
  string f = " is not prime";
  string t = " is prime";

  if(c < g){
    cout<<d[c];
    bool p = isPrime(d[c]);
    if(p == true){
      cout<<setw(5)<<t<<endl;
    }
    else if(p == false){
      cout<<setw(5)<<f<<endl;
    }
    c++;
    displayPrime(c, d, g);
  }
  else if(c >= g){
    cout<<endl;
  }
}

/*this function displays the array in the requested ways*/
void displayArray(int b[], int g){
  string dsply1 = "The generated array is: ";
  string dsply2 = "The reverse is: ";
  string dsply3 = "Table of square values \n-n-     -n^2-";
  string dsply4 = "sum of its digits is: ";
  string dsply5 = "Is it prime? ";

  cout<<dsply1;
  for(int l = 0; l < g; l++){
    cout<<b[l]<<" ";
  }
  cout<<endl;

  cout<<dsply2;
  reverseDisplay(g, b);

  cout<<dsply3<<endl;
  squareDisplay(0, b, g);

  cout<<dsply4<<endl;
  displaySum(0, b, g);

  cout<<dsply5<<endl;
  displayPrime(0, b, g);

  cout<<"Implemented by Michael Griggs"<<endl;

}

/*this function creates the array the program will use later*/
void makeArray(int x [], int i){

    for(int n = 0; n < i; n++){
        int randnum = randomNum();
        x[n] = randnum;
    }

}

int main() {
  cout<<"???Welcome to Michael Griggs's recursion app???"<<endl;
  cout<<endl;
  cout<<"Enter the size of the array you wish to create (input must be >=5): ";
  int g;
  while(!(cin>>g)){
    cout<<"\n invalid input, exiting the program";
    return 0;
  }
  while(g < 5){
    cout<<"\n invald input, exiting the program";
    return 0;
  }
  cout<<endl;
  int arr[g];
  makeArray(arr, g);
  displayArray(arr, g);
  return 0;
}
