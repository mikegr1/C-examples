//Author: Michael Griggs
//serial #: 11
//Due: 2-19-2020
//Programming assignment 2
//Spring 2020 - CS3358 - 252
//instructor: Husain Gholoom
//description: This program takes a user size and creates a 2d vector matrix, then the program finds the magic number and compares the sums of
//the rows, columns, and diagonals to the magic number. If all sums match the magic number, the matrix is magic/perfect. All the observations
//about the matrix are outputted to the console.
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int magicNumber(int n); //calculates the perfect number
void populateVector(int n); //populates the vector and sets its size, also prints the vector
bool checkForMagic(int n, vector<vector <int> > vect); //checkts the vector to determine if it is a perfect vector

int magicNumber(int n){
    int p = (n)*((n * n) + 1)/2;
    cout<<"the magic number is: "<<p<<endl; //calculates the magic number
    return (p);
}

bool checkForMagic(int n, vector<vector <int> > vect){
    int sum = 0;
    int sum2 = 0;
    int rowSum = 0;
    int columnSum = 0;
    int mySize = vect.size();

    for(int i = 0; i<mySize; i++){
        sum = sum + vect[i][i];
        }
    cout<<"The diagonal sum 1 is: "<<sum<<endl; //calculates diagonal sums

    for(int j = mySize-1; j>=0; j--){
            sum2 = sum2 + vect[mySize-1-j][j];
        }
    cout<<"The diagonal sum 2 is: "<<sum2<<endl; //calculates diagonal sum from opposite direction


    for (int i = 0; i<mySize; i++){
        for (int j = 0; j<mySize; j++){
            if( j%n == 0 ){
                rowSum = 0; //calculates row sums
            }
            rowSum = rowSum + vect[i][j];
        }
    cout<<"The row sum "<< i <<" is: "<<rowSum<<endl;

    }

    for (int i = 0; i<mySize; i++){
        for(int j = 0; j<mySize; j++){
                if(j%n == 0){
                    columnSum = 0;  //calculates column sums
                }
            columnSum += vect[j][i];
        }
        cout<<"The column sum "<< i<< " is: "<<columnSum<<endl;
    }

    if (sum != n || columnSum != n || rowSum != n|| sum2 != n){
        return false;
    }

    else
        return true;
}

//implementation for populate vector function
void populateVector(int n){

    vector<vector <int> > vect(n, vector<int>(n,0));

    int maximum = (n * n) + 10;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<vect[i].size(); j++){
            vect[i][j] = rand() % maximum;  //populates 2d vector matrix with random numbers
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<vect[i].size(); j++){
                cout<<vect[i][j]<<" ";  //prints out the vector matrix
                int x = j + 1;
                if(x % n == 0 ){
                    cout<<endl;
                }

            }
        }

        bool magic = checkForMagic(magicNumber(n), vect);

        if(magic == true){
            cout<<"This is a perfect matrix Y_(0o0)_Y"<<endl<<endl;;
        }
        else{
            cout<<"This is not a perfect matrix >:3"<<endl;
        }
    }




int main()
{
    cout<<"The purpose of this program is to show 2d matrices generated with random input based on user size,";
    cout<<" and then preform a test comparing the sum of all rows, columns, and diagonals to eachother."<<endl;
    char input;
    cout<<"please enter Y/y to commence the magical matrix tests or N/n to terminate the program: ";
    cin>>input;
    if(input != 'y' && input != 'Y' && input != 'N' && input != 'n'){
        cout<<"This is invalid input, please enter Y/y or N/n: ";
        cin>>input;
        cout<<endl;
    }
    switch (input){
    case 'y':
        cout<<"Enter the size of the 2d vector array: ";
        int x;
        cin>>x;
        if(x<2 || x>13){
            cout<<"\ninvalid input, enter new input: ";
            cin>>x;
            cout<<endl;
        }
        populateVector(x);
        cout<<"please enter Y/y to commence the magical matrix tests or N/n to terminate the program: ";
        cin>>input;
    case 'Y':
        cout<<"Enter the size of the 2d vector array: ";
        int v;
        cin>>v;
        if(v<2 || v>13){
            cout<<"\ninvalid input, enter new input: ";
            cin>>v;
        }
        populateVector(v);
        cout<<"please enter Y/y to commence the magical matrix tests or N/n to terminate the program: ";
        cin>>input;
    case 'n':
        cout<<"Algorithim implemented by Michael Griggs \n February 19th, 2020";
        break;
    case 'N':
        cout<<"Algorithim implemented by Michael Griggs \n February 19th, 2020";
        break;
    }
    return 0;
}
