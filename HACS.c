#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

//method to find ideal string. return char array with most frequent chars per position.
void findIdeal(int x, int y, char arr[x][y], char ideal[y]){
	printf("\nanalyzing...\t");
	int max, count;
	char biggie;
	/*
	TO DO:
		- tie resolution
	*/
	for (int j=0; j<y; j++){ //column by column
		biggie='\0';
		max=0;
		for (int i=0; i<x; i++){ //row by row //inner loop holds the current "target" letter.
			count=0;
			//loop once more through rows to compare to "target".
			for (int h=0; h<x; h++){
				if ((arr[h][j] == arr[i][j]) && (arr[h][j] != '\0')){//match
					count++;
					if (count > max){//new most common element
						max = count;
						biggie = arr[h][j];
					}
				}//end match.
			}//end letter comparison
		}//end column.
		ideal[j] = biggie;

	}//end comparisons.
	ideal[y] ='\0';
}


void cull(int x, int y, int like, char array[x][y], char best[y]){
	int count;
	for (int i=0;i<x;i++){//word by word
			count=0;
			for (int j=0;j<y;j++){//letter by letter
				if (array[i][j] == best[j]){
					count++;
				}
			}
			//after each word, cull word if count != likeness
			if (count != like){
				for (int j=0;j<y;j++){
					array[i][j]='\0';
				}
			}
		}
}


//method to find word of best fit vs. ideal. compare valid words to ideal and return winner.
void matchIdeal(bool first, int x, int y, int like, char array[x][y], char ideal[y], char best[y]){
	printf("comparing...");
	int maxindex=0, count, biggie=0;

	for (int i=0;i<x;i++){	//loop word by word
		count=0;
		for (int j=0;j<y;j++){	//compare each letter to Ideal
			if (array[i][j] == ideal[j]){
				count++;	//give score for matches
				if (count > biggie){
					biggie=count;
					maxindex=i;
				}
			}
		}
	}
	printf("\tdone! grabbing suggestion...");
	for (int i=0;i<y;i++){
		best[i] = array[maxindex][i];
	}
	best[y] = '\0';
	printf("\n\nTry entry %d : %s", maxindex+1, best); 	//winner gets printed
}


int main() {

/* TO DO:
	- prompt for # of letters in each entry, use for char array conversion. 
		done
	- ask for entries, "..." to stop collecting.
		done
	- count chars at each position, create an 'ideal string' to compare to
		done
	- find Entry of Best Fit vs. Ideal String, output as suggestion.
		done!!! MVP BABY!
	- prompt for likeness score, '999' for success
	- congratulate if success, move to exit
	- otherwise, delete entries that have a different likeness score.
	- repeat by finding a new Ideal String (looping while 'incorrect').
	*/
	int length=0, girth=0, n=0, likeness;
	bool done, first = true;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	system("cls");
	printf("\n\n\n\t\t|\tThank you for using the\t\t     |\n\t\t|Hotrod Administrative Computer Synchronizer!|\n\t\t|\t\t(HACS)\t\t\t     |\n\n\nIt seems we are unable to remotely connect to your device,\nand will require you to input data manually.\nWe apologize for any inconvenience.\n\nPlease input the password options you see on your monitor.\n\nEnter '$' when all options have been input.\n\n");
	//take array bigger than needed.
	char arr[15][15];

	//collect options
	for(int i=0; i<15; i++){ 
		printf("\n%d . \t",i+1);
		scanf("%s", &arr[i]);
		if (*arr[i] == '$')
			break; //end collection
		length++;
	}
	girth = strlen(arr[0]);//grab length of words
	//pass actual size of list into a bespoke array to do calcs.
	char work[length][girth], ideal[girth], best[girth];
	for (int i=0; i<length; i++){
		strcpy(work[i], arr[i]);
	}

	done=false;
	while (!done){
		findIdeal(length, girth, work, ideal);
		matchIdeal(first, length, girth, likeness, work, ideal, best);
		printf("\nWhat is the likeness score? \n(Enter \"999\"  if you've successfully accessed your system) :\t");
		scanf("%d", &likeness);
		cull(length, girth, likeness, work, best);
		first = false;
		if (likeness == 999)
			done = true;
	}
	printf("congratulations! Thank you for using our system.\nHave a splendiferous day!");
	
	


//exit code
	return 0;
}