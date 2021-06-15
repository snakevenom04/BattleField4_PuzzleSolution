
/* what you wanna do
1) give all the lamps a number(clockwise from door is easiest i think) and remember it.

2) note down what lamps are on at the start

3) now go to each button press it once and check which lamps CHANGED (on -> off or off -> on)

4) write the numbers of those lamps into the corresponding button list below.

5) do it for all of them

6) after you switch off the last button the default lamp state which will be set so write that down into the default_lamps below

7) once its ready run the program

*/

#include <bits/stdc++.h>

using namespace std;

// edit these, i have filled some random values as an example

int default_lamps[] = {5, 6};// edit this.

//You want to put in the lamp numbers that were CHANGED on pressing one of these switches. So if lamp 2 was on and was turned off then you put in 2 down there.

/* Also remember that when you press the 7th button(last one any order) and then press it again to bring the 
lamps back to inital state THE GAME WILL CHANGE THE INITIAL STATE. So if you had lamps 2 3 4 on at the start, after 
turning 7th button on and off you might have a different set up. Just input that setup into "default_lamps" list above and you ll be fine.*/

int tree[] = {1, 3, 4, 5}; // edit these.
int pier[] = {1, 2};
int rock[] = {3, 4};
int water[] = {5, 6};
int stove[] = {7, 8};
int temple[] = {9, 10};
int shrine[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};


// CODE STARTS HERE IGNORE FROM HERE ON OUT

void reset(int arr[])
{
    for(int i =0; i<7; i++)
    {
        arr[i] = 0;
    }
}

int convert(int arr[], int len)
{
    int sum = 0;
    
    for(int i=0; i< len; i++)
    {
            sum = sum + pow(2,(arr[i] - 1));
        
    }
    
    return sum;
    
}

void checkSum(int a[], int n, int k, int track[], int deci_lamps)
{
    // Calculate number of bits
    int range = (1 << n) - 1;
    
    //cout << range << endl;
 
    // Generate combinations using bits
    for (int i = 0; i <= range; i++) {
 
        int x = 0, y = i, sum = deci_lamps;
        int index = 0;
        
        //cout << sum << endl;
 
        while (y > 0) {
 
            if (y & 1 == 1) {
 
                // Calculate sum
                track[x] = 1;
                sum = sum ^ a[x];
                
                //cout << range << endl;
            }
            x++;
            y = y >> 1;
        }
 
        // If sum is found, set flag to 1
        // and terminate the loop
        if (sum == k)
           return;
           
        reset(track);
        
        //cout << "reset" << endl;
    }
 
    return;
}


int main()
{
    //int final_state[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; //20
    
    int deci_lamps = convert(default_lamps, (sizeof(default_lamps)/sizeof(default_lamps[0])));
    
    int deci_tree = convert(tree, (sizeof(tree)/sizeof(tree[0])));
    
    int deci_pier = convert(pier, (sizeof(pier)/sizeof(pier[0])));
    
    int deci_rock = convert(rock, (sizeof(rock)/sizeof(rock[0])));
    
    int deci_water = convert(water, (sizeof(water)/sizeof(water[0])));
    
    int deci_stove = convert(stove, (sizeof(stove)/sizeof(stove[0])));
    
    int deci_temple = convert(temple, (sizeof(temple)/sizeof(temple[0])));
    
    int deci_shrine = convert(shrine, (sizeof(shrine)/sizeof(shrine[0])));
    
    int deci_final = 1048575;
    
    //cout << "deci =" << deci_lamps << endl;
    
    int a[7] = {deci_tree, deci_shrine, deci_temple, deci_stove, deci_water, deci_rock, deci_pier};
    
    int track[7] = {0, 0, 0, 0, 0, 0, 0};
    
    checkSum(a, 7, deci_final, track, deci_lamps);
    
    for(int i=0; i<7;i++)
    {
        if(track[i] == 1)
        {
            switch(i)
            {
                case 0:
                    cout << "TREE \t";
                    break;
                    
                case 1:
                    cout <<"SHRINE \t";
                    break;
                    
                case 2:
                    cout <<"TEMPLE \t";
                    break;
                    
                case 3:
                    cout <<"STOVE \t";
                    break;
                    
                case 4:
                    cout <<"WATER \t";
                    break;
                    
                case 5:
                    cout <<"ROCK \t";
                    break;
                    
                case 6:
                    cout <<"PIER \t";
                    break;
                    
                default:
                    cout << "NOT WORKING";
            }   
            
        }
        
        
    }
    
    
    return 0;
}
