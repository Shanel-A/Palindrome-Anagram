/*
* Programmer: ALCARAZ, Shanel Pauline G.
* Date Created: 01/25/2021
* Program: BSMIT
* Course / Section: CS127-8L/BM1
*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#include<conio.h>
#include<windows.h>
string sort(string str);						//reaaranging the orders of string to test if its anagram
bool areAnagrams(string str1,string str2);		//process the strgin if anagram anf returns the value 1 or 0


string RemSpacePunct(string str);				//function that removes space and punctation in aa string
////////////////////////////////
void palindrome(char sal[120]);					//testing whether the c-string value is palindrome or not
void password();								//asking the user to enter the password
char menu();									//displaying choices a,b, and c then returns the answer
void quit();									//asking the user if he/she wants to quit
string EnterPassword();							//processing if the password is correct and diplaying it with "*" sign


int main()
{
	char let,ans;
    
do{
	system("cls");
    password();
    
 do{
  ans=menu();


   switch(ans)
   {
   		case 'a':	
   			{char sal[120];
			cin.ignore();
   		   	cout<<"Input the word: ";
		   	cin.getline(sal, 120);
		   	palindrome(sal);	
		   	break;
   			}
   			
   		case 'b':
   			{string str1, str2;
   			cin.ignore();
   			cout<<"Enter the First String: ";
    		getline(cin, str1);
    		cout<<"Enter the Second String: ";
    		getline(cin, str2);
   			areAnagrams(str1, str2);
   			if (areAnagrams(str1, str2))
        		cout << "They are anagrams.";
    		else
        		cout << "They are not anagrams.";
   			break;
   			}
   		
   	
   			
   		case 'c':
   			quit();
   		
		   	
   }

   do{
		cout<<"\n\nDo you want to try again [y/n]"<<endl
			<<"Choice: ";
		cin>>let;
		let=tolower(let);
		}while(let!='n'&&let!='y');
	
 }while(let=='y');

}while(let=='n');

		system("pause");
        return 0;

}//end main
//////////////////////////////////////////////////////
void quit()
{
	char qchoice;
	
	do{
		cout<<"\nDo you want to quit now? [y/n]"<<endl
			<<"Choice: ";
		cin>>qchoice;
		qchoice=tolower(qchoice);
		}
	while(qchoice!='n'&&qchoice!='y');
	

	if (qchoice=='n')
		main();	
	else if (qchoice=='y')
		cout<<"\nThank you! ";
		exit(0);
	
}

///////////////////////
string EnterPassword()
{
   string password="";
   char ch=getch();
   while (ch!='\r')
   {	   
	   if(ch == '\b')   
            {
            if(password.size() != 0) 
               {
            		cout << "\b \b";
               		password.erase(password.size() - 1, 1);
               }
            ch=getch();
            }
       else
	   {
	   		cout<<'*';
	   		password+=ch;
	   		ch=getch();
       }
   }

   return password;
}

////////////////////////////////////////////////////
char menu()
{
	char choice;

do{
 system ("cls");
 
	cout<<"[a] Check the palindrome"<<endl
		<<"[b] Testing if strings are Anagrams"<<endl
		<<"[c] Quit"<<endl
		<<"Your choice: ";
	cin>>choice;
	    return choice;
	}while(choice!='a' && choice!='b' && choice!='c');
			

}


//////////////////////////////////
void password()
{
 	cout<<"enter password: ";
   	string password=EnterPassword();
   	
   	 if(password=="123456" || password=="12245")
	 {   
	 	cout<<"\nprocessing your password";
       
		for(int i=1;i<=5;i++)
		{	
			Sleep(100);
			cout<<".";
		}	
	  } 
	  
	 else
   	 {   
		cout<<"\nprocessing your password";
       		for(int i=1;i<=5;i++)
			{	
				Sleep(100);
				cout<<".";
			}

	   	system("cls");
	   	cout<<"sorry incorrect password....."<<endl
		   	<<"\n\nyou have reached the maximum attempt for password.";
		cout<<endl;
		
		exit(0);
	 }

}

////////////////////////////////////////////////////////////////
string sort(string str)
{
    sort(str.begin(), str.end());
		return str; 
    
}
//////////////////////////////
bool areAnagrams(string str1,string str2)
{
	int n1 = str1.length();
    int n2 = str2.length();
    string str3, str4;
    
	str3=sort(str1);
	str4=sort(str2);	
	
		
	if (str3 == str4)
        return true;
    else
	    return false;
	

}
//////////////////////////////
string RemSpacePunct(string str)
{
	
    for (int i=0, len=str.size(); i<len; i++) 
    { 
        
        if (ispunct(str[i])) 
        { 
            str.erase(i--, 1); 
            len = str.size(); 
        } 
    } 
}
///////////////////////////////
void palindrome(char sal[120])
{
	char x[120];
	
	strcpy(x,sal);
	cout<<"\nIn reverse order: "<<strrev(x)<<endl;

    
        if(strcmpi(x,sal)==0)
			cout<<"\nThe word is a palindrome."<<endl;
		else
			cout<<"\nThe word is not a palindrome."<<endl;
	
}


