#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int checker(char letters[], string word)
{
	int a;
	for(int i = 0; i < word.size(); i++)
	{
	    if(letters[i]==word[i])
	    {
	        a++;  
	    }
	}
	if(a == word.size())return 1;
	return 0;
}
int struck(int wrongtries)
{
    if(wrongtries ==0)return 0;
    if(wrongtries == 1)
    {
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"__ __\n";
    }
     if(wrongtries == 2)
    {
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"-- --\n";
    }
     if(wrongtries == 3)
    {
        cout<<"\n";
        cout<<"\n";
        cout<<"  |\n";
        cout<<" -|-\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"__ __\n";
    }
     if(wrongtries ==4 )
    {
        cout<<"  --\n";
        cout<<"  |/\n";
        cout<<"  |\n";
        cout<<" -|-\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"__ __\n";
    }
    if(wrongtries ==5 )
    {
        cout<<"  ------\n";
        cout<<"  |   \|/\n";
        cout<<"  |    o\n";
        cout<<" -|-\n";
        cout<<"  |\n";
        cout<<"  |\n";
        cout<<"__ __\n";
    }
      if(wrongtries ==6 )
    {
        cout<<"  ------\n";
        cout<<"  |   \\|/\n";
        cout<<"  |    x\n";
        cout<<" -|-  /|\\\n";
        cout<<"  |   / \\\n";
        cout<<"  |\n";
        cout<<"__ __\n";
    }
    return 0;
}
int wordguess(string word,string guess, char letters[], int wt, int win)
{
	for(int i = 0; i<word.size();i++)
	{
		if(letters[i]==NULL)
		{
			cout<<"_ ";
		}
		else cout<<letters[i]<<" ";
	}
    cout<<"\nType a letter or a full word>>";
	cin>>guess;
	if(guess.size() == 1)
	{
		for(int i = 0; i < word.size(); i++)
	    {
	        if(guess[0]==word[i])
	        {
	            letters[i] = guess[0];  
	            wt--;
	        }
	    }
		
		wt++;
		struck(wt);
		return wt;
	}
	else
	{
		if(guess == word)
		{
			for(int i = 0; i < word.size(); i++)
		    {
		    	letters[i] = word[i];
		    	
		    }
			return wt;
		}
	wt++;
	struck(wt);
	}
	return wt;
}
int main()
{
    string word, words[6],g;
    int wt,win,n;
    wt=0;
    words[0]="car";
    words[1]="bool";
    words[2]="machine";
    words[3]="classroom";
    words[4]="computer";
    words[5]="programming";
    srand(time(0));
    LOOP:
    cout << "Pick a word - 1\nRandom word - 2\n>>";
    int lol;
    cin>>lol;
    if(lol==1)
        {
            system("cls");
            system("Color 60");
            cout<<"PICK A WORD:";
            cin>>word;

            n = word.size();
            goto GAME;
        }
    if(lol==2)
      {
          int random = rand()%5;
          word = words[random];
        n = word.size();
            goto GAME;
        goto GAME;
      }
    GAME:
        system("cls");
        system("Color 86");
		char letter[n];
		for(int i = 0 ; i<n;i++)
		{
			letter[i]= NULL;
		}
    LOOP2:
    	if(wt==6)
    	{
    		struck(wt);
    		cout<<"\nyou lost;[\n";
    		return 0;
		}
	    wt = wordguess(word,g,letter,wt, win);
	    win=checker(letter,word);
	    if(win == 1)
	    {
	    	for(int i = 0; i<word.size();i++)
			{
			 	cout<<letter[i]<<" ";
			}
	    	cout<<"\nCongrats, You WON!!!!!!!!\n";
		getch();
	    	return 0;
		}
    goto LOOP2;
    return 0;
}
