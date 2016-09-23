#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include<ctime>


/**
* author Ash Smith
* version 09/18/16
* HW4.cpp
* g++ -g -c -o hw4.o hw4.cpp
*
*/
using namespace std;
const double AARONACC = 1.0/3;
const double BOBACC = 0.5;
const double CHARACC = 1.0;
const double numDuels = 10000;
bool aaronAlive = true, bobAlive = true, charlieAlive = true;

/* Member function prototypes */
bool at_least_two_alive(bool aaronAlive, bool bobAlive, bool charlieAlive);
void Aaron_shoots1(bool& bobAlive, bool& charlieAlive);
void Bob_shoots(bool& aaronAlive, bool& charlieAlive);
void Charlie_shoots(bool& aaronAlive, bool& bobAlive);
void Aaron_shoots2(bool& bobAlive, bool& charlieAlive);

/* Test function prototypes */
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);


void shoot(bool& targetAlive, double accuracy)
{
   double attack;
   if (targetAlive == true)
   {
      attack = rand() % 100;
      if (attack < (accuracy * 100))
      {
         targetAlive = false;
      }
   }
}

bool at_least_two_alive (bool aaronAlive, bool bobAlive,  bool charlieAlive)
{
   if ((aaronAlive && bobAlive) || 
              (aaronAlive && charlieAlive) ||
                         (bobAlive && charlieAlive))
      return true;
   
   else
      return false;
}

void Aaron_Shoots1(bool& bobAlive, bool& charlieAlive)
{
   if (charlieAlive)
   {
      shoot(charlieAlive, AARONACC);
      if (!(charlieAlive))
      {
         cout << "Charlie is dead.\n";
      }
         
      else
      {
         cout << "Aaron misses.\n";
      }
   }
   
   else if (bobAlive)
   {
      shoot(bobAlive, AARONACC);
      if (!(bobAlive))
      {
         cout << "Bob is dead.\n";
      }
         
      else
      {
         cout << "Aaron misses.\n";
      }
   
   }
}

void Bob_Shoots(bool& aaronAlive, bool& charlieAlive)
{
   if (charlieAlive)
   {
      shoot(charlieAlive, BOBACC);
      if (!(charlieAlive))
      {
         cout << "Charlie is dead.\n";
      }
         
      else
      {
         cout << "Bob misses.\n";
      }
   
   }   
   
   else if(aaronAlive)
   {
      shoot(aaronAlive, BOBACC);
      if (!(aaronAlive))
      {
         cout << "Aaron is dead.\n";
      }
         
      else
      {
         cout << "Bob misses.\n";
      }
   }
}

void Charlie_Shoots(bool& aaronAlive, bool& bobAlive)
{
   if (bobAlive)
   {
      shoot(bobAlive, CHARACC);
      if (!(bobAlive))
      {
         cout << "Bob is dead.\n";
      }
         
      else
      {
         cout << "Charlie somehow misses.\n";
      }
   }
      
   else if (aaronAlive)
   {
      shoot(aaronAlive, CHARACC);
      if (!(aaronAlive))
      {
         cout << "Aaron is dead.\n";
      }
         
      else
      {
         cout << "Charlie somehow magically misses.\n";
      }
   }
}

void Aaron_Shoots2(bool& bobAlive, bool& charlieAlive)
{
   if (bobAlive && charlieAlive)
   {
      return;
   }
      
   else
   {
      if (charlieAlive)
      {
         shoot(charlieAlive, AARONACC);
         if (!(charlieAlive))
         {
            cout << "Charlie is dead.\n";
         }
         
         else
         {
            cout << "Aaron misses.\n";
         }
      
      }
      
      else if (bobAlive)
      {
         shoot(bobAlive, AARONACC);
         if (!(bobAlive))
         {
            cout << "Bob is dead.\n";
         }
         
         else
         {
            cout << "Aaron misses.\n";
         }
      
      }
   }
}

void test_at_least_two_alive(void) 
{
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
	
   cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "Case passed ...\n";

   cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "Case passed ...\n";
   
   cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "Case passed ...\n";
   
   cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "Case passed ...\n";
   
   cout << "Case 5: Aaron alive, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "Case passed ...\n";
   
   cout << "Case 6: Aaron alive, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "Case passed ...\n";
   
   cout << "Case 7: Aaron alive, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "Case passed ...\n";
   
   cout << "Case 8: Aaron alive, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "Case passed ...\n";
}

void test_Aaron_Shoots1(void)
{
   cout << "Unit Testing 2: Function – Aaron_Shoots1()\n";
   cout << "Case 1: Bob alive, Charlie alive\nAaron is shooting at Charlie\n";
   bobAlive = true;
   charlieAlive = true;
   Aaron_Shoots1(bobAlive, charlieAlive);
   cout << "Case 2: Bob dead, Charlie alive\nAaron is shooting at Charlie\n";
   bobAlive = false;
   charlieAlive = true;
   Aaron_Shoots1(bobAlive, charlieAlive);
   cout << "Case 3: Bob alive, Charlie dead\nAaron is shooting at Bob\n";
   charlieAlive = false;   
   bobAlive = true;
   Aaron_Shoots1(bobAlive, charlieAlive);

}

void test_Bob_Shoots(void)
{
   cout << "Unit Testing 3: Function – Bob_Shoots()\n";
   cout << "Case 1: Aaron alive, Charlie alive\nBob is shooting at Charlie\n";
   aaronAlive = true;
   charlieAlive = true;
   Bob_Shoots(aaronAlive, charlieAlive);      
   cout << "Case 2: Aaron dead, Charlie alive\nBob is shooting at Charlie\n";
   aaronAlive = false;
   charlieAlive = true;
   Bob_Shoots(aaronAlive, charlieAlive);
   cout << "Case 3: Aaron alive, Charlie dead\nBob is shooting at Aaron\n";
   charlieAlive = false;
   aaronAlive = true;  
   Bob_Shoots(aaronAlive, charlieAlive);
}

void test_Charlie_Shoots(void)
{
   cout << "Unit Testing 4: Function – Charlie_Shoots()\n";
   cout << "Case 1: Aaron alive, Bob alive\nCharlie is shooting at Bob\n";
   aaronAlive = true;  
   bobAlive = true;
   Charlie_Shoots(aaronAlive, bobAlive);
   cout << "Case 2: Aaron dead, Bob alive\nCharlie is shooting at Bob\n";
   aaronAlive = false;  
   bobAlive = true;
   Charlie_Shoots(aaronAlive, bobAlive);    
   cout << "Case 3: Aaron alive, Bob dead\nCharlie is shooting at Aaron\n";
   bobAlive = false;
   aaronAlive = true;
   Charlie_Shoots(aaronAlive, bobAlive);
}

void test_Aaron_Shoots2(void)
{
   cout << "Unit Testing 5: Function – Aaron_Shoots2()\n";
   cout << "Case 1: Bob alive, Charlie alive\nAaron intentionally misses his first shot\n";
   bobAlive = true;
   charlieAlive = true;
   Aaron_Shoots2(bobAlive, charlieAlive);
   cout << "Case 2: Bob dead, Charlie alive\nAaron is shooting at Charlie\n";
   bobAlive = false;
   charlieAlive = true;
   Aaron_Shoots2(bobAlive, charlieAlive);
   cout << "Case 3: Bob alive, Charlie dead\nAaron is shooting at Bob\n";
   charlieAlive = false;  
   bobAlive = true;
   Aaron_Shoots2(bobAlive, charlieAlive); 
}

int main()
{
   int aaronWin = 0, bobWin = 0, charlieWin = 0;
   int aaronWin2 = 0, bobWin2 = 0, charlieWin2 = 0;
   
   cout << "*** Welcome to Ash Smith's amazing Duel Simulator, pitting idiot men against each other since 2007 ***\n";
   test_at_least_two_alive();
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   test_Aaron_Shoots1();
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   test_Bob_Shoots();
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   test_Charlie_Shoots();
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   test_Aaron_Shoots2();
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   cout << "Ready to test strategy 1 (run " << numDuels << " times):\n";
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   
   for (int i = 0; i <= numDuels; i++)
   {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive))
      {
         if(aaronAlive)
         {
            Aaron_Shoots1(bobAlive, charlieAlive);
         }
         if(bobAlive)
         {
            Bob_Shoots(aaronAlive, charlieAlive);
         }
         
         if(charlieAlive)
         {
            Charlie_Shoots(aaronAlive, bobAlive);
         }
      }
      if(!(bobAlive || charlieAlive))
      {
         aaronWin++;
      }
         
      if (!(aaronAlive || charlieAlive))
      {
         bobWin++;
      }
      
      if (!(aaronAlive || bobAlive))
      {
         charlieWin++;
      }
   
   }
   double aaronPercent = aaronWin/numDuels * 100;
   double bobPercent = bobWin/numDuels * 100;
   double charliePercent = charlieWin/numDuels * 100;
   
   cout << "Aaron won " << aaronWin << "/" << numDuels << " duels or " << aaronPercent << "%\n";
   cout << "Bob won " << bobWin << "/" << numDuels << " duels or " << bobPercent << "%\n";
   cout << "Charlie won " << charlieWin << "/" << numDuels << " duels or " << charliePercent << "%\n";
   
   cout << "Ready to test strategy 2 (run " << numDuels << " times.)\n";
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   
   for (int i = 0; i < numDuels; i++)
   {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive))
      {
         if(aaronAlive)
         {
            Aaron_Shoots2(bobAlive, charlieAlive);
         }
            
         if(bobAlive)
         {
            Bob_Shoots(aaronAlive, charlieAlive);
         }
         
         if(charlieAlive)
         {
            Charlie_Shoots(aaronAlive, bobAlive);
         }
               
      }
      if(!(bobAlive || charlieAlive))
         aaronWin2++;
      if(!(aaronAlive|| charlieAlive))
         bobWin2++;
      if(!(aaronAlive || bobAlive))
         charlieWin2++;
   
   }
   double aaronPercent2 = aaronWin2/numDuels * 100;
   double bobPercent2 = bobWin2/numDuels * 100;
   double charliePercent2 = charlieWin2/numDuels * 100;

   cout << "Aaron won " << aaronWin2 << "/" << numDuels << " duels or " << aaronPercent2 << "%\n";
   cout << "Bob won " << bobWin2 << "/" << numDuels << " duels or " << bobPercent2 << "%\n";
   cout << "Charlie won " << charlieWin2 << "/" << numDuels << " duels or " << charliePercent2 << "%\n";
   
   if (aaronWin2 > aaronWin)
      cout << "Strategy 2 is better than strategy 1.";
   
   else
      cout << "Strategy 1 is better than strategy 2."; 
}