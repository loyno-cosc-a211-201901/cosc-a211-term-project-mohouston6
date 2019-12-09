//Scales
//Allow user to choose a scale, specify the tonality, and have the program play the scale back to the user using beep command
//Mariah Houston
//December 9, 2019

#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	//establishing variables
	double scaleFreqs[118];
	int scaleTones[9];
	int i, fundamental, wholeStep, halfStep, keyOfScale;
	int aScale, BbScale, bScale, cScale, DbScale, dScale, EbScale, eScale, fScale, GbScale, gScale, AbScale;
	double mult;
	string tuning, repeat, tonality, key;
	
	
	//initiallize scale variables
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
	
	//initialize other variables
	wholeStep=2;
	halfStep=1;
	fundamental=440.0;
	scaleFreqs[56]=fundamental;
	
	//calculations for the hertz of each note. scaleFreqs[56] is A4=440 aka the fundamental
	mult = pow(2, 0.08333333333);
	for (i=0; i<60; i++)
	{
		scaleFreqs[57+i]=mult*scaleFreqs[56+i];
		
	}
	for (i=0; i<55; i++)
	{
		scaleFreqs[55-i]=scaleFreqs[56-i]/mult;
	}

	cout << "Scale Practice Helper\n"; //Print the name of the program
	cout << "\nWhat is the key of the scale you would like to practice? (A - G#)"; //Ask the user what key they would like to practice in
	cin >> key; //allow user to enter string of key
	cout << "\nWould you like it to be major or minor? "; //Ask the user what tonality they want to practice, major or minor
	cin >> tonality; //allow user to enter string of tonality
		
		//this decides what key the scale will be in based on the "key" string
		if ((key == "A") || (key == "a"))
	{
		keyOfScale=aScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
				if ((key == "Bb") || (key == "bb") || (key == "A#") || (key == "a#"))
	{
		keyOfScale=BbScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "B") || (key == "b") || (key == "Cb") || (key == "cb"))
	{
		keyOfScale=bScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "C") || (key == "c") || (key == "B#") || (key == "b#"))
	{
		keyOfScale=cScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "Db") || (key == "db") || (key == "C#") || (key == "c#"))
	{
		keyOfScale=DbScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "D") || (key == "d"))
	{
		keyOfScale=dScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "Eb") || (key == "eb") || (key == "D#") || (key == "d#"))
	{
		keyOfScale=EbScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "E") || (key == "e") || (key == "Fb") || (key == "fb"))
	{
		keyOfScale=eScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "F") || (key == "f") || (key == "E#") || (key == "e#"))
	{
		keyOfScale=fScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "Gb") || (key == "gb") || (key == "F#") || (key == "f#"))
	{
		keyOfScale=GbScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "G") || (key == "g"))
	{
		keyOfScale=gScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
			if ((key == "Ab") || (key == "ab") || (key == "G#") || (key == "g#"))
	{
		keyOfScale=AbScale;
		scaleTones[0]=scaleFreqs[keyOfScale];
	}
	
		//This decides what tonality
		if ((tonality == "Major") || (tonality == "major"))
		{
			for (i=0; i<2; i++) // scale degree 1
			{
				scaleTones[1+i]=scaleFreqs[keyOfScale+=wholeStep]; // 2	3
			}
			scaleTones[3]=scaleFreqs[keyOfScale+=halfStep]; // 4
			for (i=0; i<3; i++)
			{
				scaleTones[4+i]=scaleFreqs[keyOfScale+=wholeStep]; // 5	6	7
			}
			scaleTones[7]=scaleFreqs[keyOfScale+halfStep]; // 8
		}
		if ((tonality == "Minor") || (tonality == "minor"))
		{
			scaleTones[1]=scaleFreqs[keyOfScale+=wholeStep]; // 2
			scaleTones[2]=scaleFreqs[keyOfScale+=halfStep]; // 3
			for
				(i=0; i<2; i++)
				{
					scaleTones[3+i]=scaleFreqs[keyOfScale+=wholeStep]; // 4	5
				}
			scaleTones[5]=scaleFreqs[keyOfScale+=halfStep]; // 6
				for
					(i=0; i<2; i++)
					{
					scaleTones[6+i]=scaleFreqs[keyOfScale+=wholeStep]; // 7	8
					}
		}
	
	//for loops that play the scale
	for (i=0; i<8; i++) //ascending the scale
	{
		Beep(scaleTones[0+i], 500);
	}
	for (i=0; i<7; i++) //descending the scale
	{
		Beep(scaleTones[6-i], 500);
	}
	return 0;
}

