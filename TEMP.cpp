//Scales
//Allow user to choose a scale, play the scale back to the user using beep command
//Mariah Houston
//December 9, 2019

#include <iostream>
#include <AppKit/AppKit.h>
#include <cmath>
using namespace std;

int main()
{
    //establish variables
    double scaleFrequency[118];
    int scaleTones[9];
    int wholeStep, halfStep, scaleKey, choice, fundamental, i;
    int aScale, BbScale, bScale, cScale, DbScale, dScale, EbScale, eScale, fScale, GbScale, gScale, AbScale;
    double mult; //12th root of 2(1sq2 = 1.05946)
    string tonality, key;

    //initializing scale variables
    aScale=56;
    BbScale=57;
    bScale=58;
    cScale=59;
    DbScale=60;
    dScale=61;
    EbScale=62;
    eScale=63;
    fScale=64;
    GbScale=65;
    gScale=66;
    AbScale=67;

    //initialize steps
    wholeStep=2;
    halfStep=1;

    //intialize fundamental
    fundamental=440;

    scaleFrequency[56]=fundamental;
    mult = pow(2, 0.08333333333);

    //find hertz values using for loop
    for (i=0; i<60; i++)
    {
        scaleFrequency[57+i]=mult*scaleFrequency[56+i];
    }
    for(i=0; i<55; i++)
    {
        scaleFrequency[55-i]=scaleFrequency[56-i]/mult;
    }

    //prompt menu

cout << "Welcome to my program!" << endl;
cout << "Would you like to practice a scale?" << endl;
cin >> choice;
cout << "What key?" << endl;
cin >> key;
cout << "Would you like it to be Major or minor?" << endl;
cin >> tonality;

//if else statements
if((key == "A") || (key == "a"))
{
    scaleKey = aScale;
    scaleTones[0]=scaleFrequency[scaleKey];
}
    else if ((key == "Bb") || (key == "bb") || (key == "A#") || (key == "a#"))
    {
        scaleKey = BbScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "B") || (key == "b"))
    {
        scaleKey = bScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "C") || (key == "c"))
    {
        scaleKey = cScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "C#") || (key == "C#") || (key == "Db") || (key == "db"))
    {
        scaleKey = DbScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "D") || (key == "d"))
    {
        scaleKey = dScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "Eb") || (key == "eb") || (key == "D#") || (key == "d#"))
    {
        scaleKey = EbScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "E") || (key == "e"))
    {
        scaleKey = eScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "F") || (key == "f"))
    {
        scaleKey = fScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "F#") || (key == "f#") || (key == "Gb") || (key == "gb"))
    {
        scaleKey = GbScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "G") || (key == "g"))
    {
        scaleKey = gScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
    else if ((key == "G#") || (key == "g#") || (key == "Ab") || (key == "ab"))
    {
        scaleKey = AbScale;
        scaleTones[0]==scaleFrequency[scaleKey];
    }
        else //else statement if the input isn't recognized
        { 
            cout << "Error! Restart the program, and enter a corret key from a-g\n";
            return 0;
        }

    //if for tonality
    if((tonality == "Major") || (tonality == "major"))
    {
        for(i=0; i<2; i++) //scale degree 1
        {
            scaleTones[1+i]=scaleFrequency[scaleKey+=wholeStep]; //intervals 2 and 3
        }
        scaleTones[3]=scaleFrequency[scaleKey+=halfStep]; //intervals 4
        for (i=0; i<2; i++)
        {
            scaleTones[4+i]=scaleFrequency[scaleKey+=wholeStep]; //intervals 5 6 7
        }
        scaleTones[7]=scaleFrequency[scaleKey+halfStep]; //interval 8
    }
    else if ((tonality == "Minor") || (tonality == "minor"))
    {
        scaleTones[1]=scaleFrequency[scaleKey+=wholeStep]; // 2
        scaleTones[2]=scaleFrequency[scaleKey+=halfStep]; // 3
        for(i=0; i<2; i++)
        {
            scaleTones[3+i]=scaleFrequency[scaleKey+=wholeStep];//4 5
        }
        scaleTones[5]=scaleFrequency[scaleKey+=halfStep];//6
            for(i=0; i<2; i++)
            {
                scaleTones[6+i]=scaleFrequency[scaleKey+=wholeStep]; //7 8
            }
    }
    else //else for incorrect input
    {
        cout << "Error! Please restart the program, and enter either minor or major\n";
        return 0;
    }

    //for loops to play the scale
    for (i=0; i<8; i++) //ascending scale
    {
        Beep(scaleTones[0+i], 500);
    }
    for (i=0; i<7; i++)
    {
        Beep(scaleTones[6-i, 500]);
    }
    cout << "All done! Thank you for using my scales program\n";
    return 0;
}