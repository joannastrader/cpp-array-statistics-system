/* Joanna Strader
 * CSCI 1010 Section 001
 * Project
 * End of semester
 * 4/28/25
*/
#include<iostream>
using namespace std;
//Step 1: Display Menu
//Step 2: Opt Menu Selection From User
//Step 3: Enter New Data/Display Largest/Display Smallest/Display Median/Display Avg/Display Ascending

const int MAX = 100;
void displayMenu();
void display(int a[], int size, int used);
void insert(int arr[], int & used);
char enterOperator();
void append(int arr[], int & used, int data);
void ascending(int arr[], int used);
int median(int arr[], int used);
int largest(int arr[], int used);
int smallest(int arr[], int used);
int average(int arr[], int used);

int main()
{
    int numbers[MAX], used = 0;
    char opt;


        //while opt does not equal 1-7
        do{
            displayMenu();
            opt = enterOperator();


            switch(opt)
            {
                case '1':
                // check if have space in array.
                insert(numbers, used);
                break;
        
                case '2':
                cout << "Largest: " << largest(numbers, used) << endl;
                break;
        
                case '3':
                cout << "Smallest: " <<  smallest(numbers, used) << endl;
                break;
        
                case '4':
                cout << "Median: " << median(numbers, used) << endl;
                break;
        
                case '5':
                cout << "Average: " << average(numbers, used) << endl;
                break;
        
                case '6':
                ascending(numbers, used);
                display(numbers, used);
                break;
        
                case '7':
                cout << "Goodbye!" << endl;
                break;
        
            }
             }
             while(opt != '7');

    return 0;
}
/*
*purpose: display array
*data needed: none
*data returned: none
*/
void display(int a[], int used)
{
    for (int i=0; i < used; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void displayMenu()
{
    cout << "Choose from the following operation: " << endl;
    
    cout << "1. Enter a number " << endl;
    cout << "2. Display the largest " << endl;
    cout << "3. Display the smallest" << endl;
    cout << "4. Display the median" << endl;
    cout << "5. Display the average" << endl;
    cout << "6. Display all the numbers in ascending order" << endl;
    cout << "7. Quit" << endl;
    
}
//enter Operator
char enterOperator()
{
    char opt;
    cout << "Enter operator";
    cin >> opt;

    return opt;

}
//insert new data at given index and shift data
//needed data: array, used size, index num, new data
//return: void , give error message if invalid index number
void insert(int arr[], int & used)
{
    if(used >= MAX)
    {
        cout << "The array is full" << endl;
    }
            else
            {
            cout << "enter a data" << endl;
            int data;
            cin >> data;


            int index = 0;
            //for loop from used - 1 (first filled element from right)
            for (int i = used -1; i >= 0; i--)
            {   //coming from right, find first index number where value is less than data to be inserted
                if(arr[i] < data)
                {
                    index = i;
                    break;
                }
            }
            //if data is larger than last element then just append (add at first empty space in array)
            if(index == used)
            {
                append(arr, used, data);
            }
            //if index # is in used, insert at index number previously found and right shift. This keeps it in ascending order.
            for (int i = used - 1; i >= index; i--)
            {
                arr[i+1]=arr[i];
            }
            arr[index] = data;
            used++;
            }
}
void append(int arr[], int & used, int data) //she may not want append in final solution. 
{
    if(used < MAX)
    {
        arr[used] = data;
        used++;
    }
    else
    {
        cout << "Err: The array is full!\n";
    }
}
void ascending(int arr[], int used)
{
    
    int temp;
    for(int i=0; i < used - 1; i++)
    {
        for(int j=0; j < used -1-i; j++)
        {
            if(arr[j] > arr[j+1])
             {
              int temp = arr[j];
              arr[j] = arr[j+1];
             arr[j+1] = temp;
             }
        }
    }
}
int median(int arr[], int used)
{
    int index = 0;
    ascending(arr, used);
    if(used %2 == 1) //odd number gets easy median value
    {
        index = used / 2;  
        return arr[index];      
    }
    else
    {
        return (arr[used/2 - 1] + arr[used/2]) / 2.0;
    }
}
int largest(int arr[], int used)
{
    ascending(arr, used);

    return arr[used-1];
}
int smallest(int arr[], int used)
{
    ascending(arr, used);
    return arr[0];
}
int average(int arr[], int used)
{
    int sum=0;
    for(int i=0; i<used; i++)
    {
        sum+=arr[i];
    }
    int avg = sum/used;
    return avg;
}
//since its already in ascending order to get largest, smallest, and median go by index number
//she wants to enter new data in array by coming from the right and compare values at each index until you reach an
//index that holds a value less than the data. Then you would insert to the right of that smaller index. 

/*
Johnny needs to memorize a set of numbers. The numbers can be entered at any time and added to the collection.

Johnny wants to know the values at any time of current collect: largest, smallest, median, average, the number list in an ascending order. 

Design a system to meet the requirement. (so display a menu).

Store it all in an array. Do a global constant for max size of 100. And also have a used variable.

After every cin, run function to put it in ascending order. 
The function should be insert func where we do for loop to find if n > a[i] & n < a[i+1]. 
Then do insert for that index number. Make sure not to go over the range of the used. 
*/