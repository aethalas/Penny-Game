// Title  :  Assignment 1
// Purpose:  Penny Game
// Author :  anonymous
// Date   :  21/10/2015

// Using the standard IO library and time library for randomised numbers.
#include <iostream>
#include <time.h>

// Using the standard namespace as it is a single programmer project.
using namespace std;

int action(int &playerMove, int &currentAmount, int &computerWins,
int maxInput)
{ // The 'action' subprogram is directly responsible for handling the
  // players' actions throughout the course of the game. It's here they'll
  // enter the amount they wish to take away from the pile from a value
  // between [1] and [5]. These values will be controlled by the amount of
  // remaining pennies, however, with the values changing to [1] – [?]
  // where [?] is the remaining pennies minus one.

 if (currentAmount == 1)
 { // This if statement will run a quick check on the pennies remaining in
   // the pile that is determined by the 'main' subprogram. In the event
   // there is a single penny remaining, and thus the player has lost the
   // round, it will add to the computer's win tally and announce that the
   // player has lost the round. This statement will also reduce the pile
   // of pennies to '0.' This is important as it lets the game know that
   // the round has ended.
 ++computerWins; // Adds a win for the computer.
 cout << "YOU WERE LEFT WITH THE FINAL PENNY! YOU LOSE!" << endl ;
 --currentAmount ; // Reduces the penny pile to zero.
 }
 do
 { // This loop is used to marshal the players' decisions by demanding a
   // valid input. If the player enters something the game is not
   // expecting then it'll notify them of the incorrect value and prompt
   // them to correct their decision. 

  if (currentAmount > 1)
  { // Speaks for itself – if the penny pile is greater than one, then
    // allow the user to make a choice for their turn.
  cout << "Enter between [1] and [";
   if(currentAmount > 5) 
   { // This if statement is used to check how many pennies are
     // remaining in the pile, and if the conditions are met, limit the
     // players' input. For example, if there were only [3] pennies
     // remaining, the game will request that the player chooses between
     // [1] and [2] rather than [1] and [5], for obvious reasons.
   cout << "5";
   } else {
   maxInput = currentAmount - 1 ; // Limits the 'maxInput' value.                      
   cout << currentAmount - 1 ; // Prints the players' limited option.
   }
  cout << "] to take away from the pile: ";
  cin >> playerMove ;
  }

  if(!cin || playerMove <= 0 || playerMove > maxInput)
  { // If the player somehow enters an input value that the game is not
    // expecting, then the game will let the player know they need to make
    // a different choice. 
  cin.clear();             // Clear whatever was entered into the input.
  cin.ignore(999, '\n');   // Ignore anything in the stream.
  } else {
  currentAmount = currentAmount - playerMove ;
  } 
 }
 // The first condition for the loop is simple enough – if the user enters
 // a value less than or equal to zero, they’ll be given an error message
 // and looped back to make another choice. The second condition is
 // slightly trickier as it’ll change depending on the amount of pennies
 // remaining in the pile. 
 while (playerMove <= 0 || playerMove > maxInput);

return 0;
} // action

int cpuAction(int &currentAmount, int &playerWins, bool &firstMove,
int &pennyAmount)
{ // The 'cpuAction' subprogram is responsible for controlling the
  // computer's moves. It's not exactly intelligent, but it does its job
  // well enough to make the game slightly challenging because of
  // randomisation. The computer will select a random value between [1]
  // and [5] each turn until there are less than 6 pennies remaining in
  // the pile. In this instance, the computer will always leave the player
  // with the final penny and therefore win the round. This statement will
  // also reduce the pile of pennies to '0.' This is important as it lets
  // the game know that the round has ended.

if (currentAmount == 1)
{ // If there's a single penny remaining on the computer's turn, then
  // it'll add a win to the players' count. 
 ++playerWins; // Adds a win for the player.
 cout << "THE COMPUTER HAS THE FINAL PENNY! YOU WIN!" << endl ;
 --currentAmount ; // Reduces the penny pile to zero.
}

if (firstMove == true && currentAmount < pennyAmount)
{ // Controls when the computer can have their turn! If the player has
  // the initial move, and only if the player has had their turn, can
  // the computer make their move. Otherwise, it can't do anything.

if (currentAmount > 1)
{ // Speaks for itself – if the penny pile is greater than one, then
  // allow the computer to make a choice for their turn.
srand((unsigned)time(NULL)) ; // Select a randomised number.
int randomNumber = rand() % 5 + 1; // +1 so the result can't be 0.

cout << "~-~-~-~-~-~-~ COMPUTER'S ACTION ~-~-~-~-~-~-~" << endl ;

 if(currentAmount == 6)
 { // If there are 6 or fewer pennies remaining, the computer will always
   // leave the player with the final penny, and therefore win the round.
 cout << "The computer has taken 5 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 5 ;
 }
 else if(currentAmount == 5)
 {
 cout << "The computer has taken 4 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 4 ;
 }
 else if(currentAmount == 4)
 {
 cout << "The computer has taken 3 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 3 ;
 }
 else if(currentAmount == 3)
 {
 cout << "The computer has taken 2 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 2 ;
 }
 else if(currentAmount == 2)
 {
 cout << "The computer has taken 1 penny." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 1 ;
 } else {
  if(randomNumber == 1)
  { // This isn't totally necessary, but for the sake of grammar I thought
    // it would be a nice addition. In the event the computer only selects
    // [1] penny, the game will reflect this by stating 'penny' rather
    // than 'pennies.'
  cout << "The computer has taken " << randomNumber << " penny." << endl ;
  currentAmount = currentAmount - randomNumber ;
  } else {
  cout << "The computer has taken " << randomNumber;
  cout << " pennies." << endl ;
  currentAmount = currentAmount - randomNumber ;
  }
cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 }
}

}
return 0;
} // cpuAction

int cpuActionFirst(int &currentAmount, int &playerWins, bool &firstMove,
int &pennyAmount)
{ // The 'cpuActionFirst' subprogram is identical to the 'cpuAction'
  // subprogram but with a very slight difference. This subprogram is
  // setup in the instance the computer has the initial turn rather than
  // the player. 

if (currentAmount == 1)
{ // If there's a single penny remaining on the computer's turn, then
  // it'll add a win to the players' count. 
 ++playerWins; // Adds a win for the player.
 cout << "THE COMPUTER HAS THE FINAL PENNY! YOU WIN!" << endl ;
 --currentAmount ; // Reduces the penny pile to zero.
}

if (currentAmount > 1)
{ // Speaks for itself – if the penny pile is greater than one, then
  // allow the computer to make a choice for their turn.
srand((unsigned)time(NULL)) ; // Select a randomised number.
int randomNumber = rand() % 5 + 1; // +1 so the result can't be 0.

cout << "~-~-~-~-~-~-~ COMPUTER'S ACTION ~-~-~-~-~-~-~" << endl ;

 if(currentAmount == 6)
 { // If there are 6 or fewer pennies remaining, the computer will always
   // leave the player with the final penny, and therefore win the round.
 cout << "The computer has taken 5 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 5 ;
 }
 else if(currentAmount == 5)
 {
 cout << "The computer has taken 4 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 4 ;
 }
 else if(currentAmount == 4)
 {
 cout << "The computer has taken 3 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 3 ;
 }
 else if(currentAmount == 3)
 {
 cout << "The computer has taken 2 pennies." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 2 ;
 }
 else if(currentAmount == 2)
 {
 cout << "The computer has taken 1 penny." << endl ;
 cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 currentAmount = currentAmount - 1 ;
 } else {
  if(randomNumber == 1)
  { // This isn't totally necessary, but for the sake of grammar I thought
    // it would be a nice addition. In the event the computer only selects
    // [1] penny, the game will reflect this by stating 'penny' rather
    // than 'pennies.'
  cout << "The computer has taken " << randomNumber << " penny." << endl ;
  currentAmount = currentAmount - randomNumber ;
  } else {
  cout << "The computer has taken " << randomNumber;
  cout << " pennies." << endl ;
  currentAmount = currentAmount - randomNumber ;
  }
cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~" << endl ;
 }
}

return 0;
} // cpuActionFirst

int remaining(int &currentAmount, int &pennyAmount, int &playerWins,
int &computerWins, int &gameAmount, int &playerMove, int &maxInput,
bool firstMove)
{ // The 'remaining' subprogram is used to show the player how many coins
  // there are to play for, but it's also used to announce a new round is
  // beginning once the condition is met.
if(playerWins + computerWins != gameAmount)
{ // The remaining subprogram will only work as long as there are rounds
  // left to play for. Otherwise, it'll return nothing to the main
  // subprogram.
 if(currentAmount <= 0)
 { // If there is a final penny remaining for either the player or the CPU
   // then it'll be inherently deleted so the amount will equal a flat
   // zero. If this is the case, then we'll top the coins back up to full.
   // Once this happens, the subprogram will alert the user that a new
   // round has begun.
 currentAmount = pennyAmount ;
  if(currentAmount > 1)
  { // Once the count has been restored back to full a new round will be
    // announced to the player.
   cout << "You have won [" << playerWins << "] round(s)." << endl ;
   cout << "The computer has won [" << computerWins << "] ";
   cout << "round(s)." << endl ;
   cout << endl ;
   cout << "+---+---+---+---+---+---+---+---+---+---+---+" << endl ;
   cout << "Round [" << playerWins + computerWins + 1 << "] ";
   cout << "Starting!" << endl ;
   cout << "+---+---+---+---+---+---+---+---+---+---+---+" << endl ;
    if(firstMove == false)
    { // We only want to print this if the player does not have the first
      // move. Otherwise, we want to keep it hidden. This is because this
      // information is already displayed if the player has the first go.
    cout << endl ;
    cout << "Number of pennies remaining:" << endl ;
     for(int loop = 0; loop < currentAmount; loop++)
     { // How many coins are left in the pile? Let's show the user how many
       // coins they are playing for. We'll represent them with the letter
       // 'O' rather than a flat number. Immersion!
       cout << "O" ;
     }
   cout << endl ;
   cout << endl ;
    }
  } 
 } else {
 cout << endl ;
 cout << "Number of pennies remaining:" << endl ;
  for(int loop = 0; loop < currentAmount; loop++)
  { // How many coins are left in the pile? Let's show the user how many
    // coins they are playing for. We'll represent them with the letter
    // 'O' rather than a flat number. Immersion!
  cout << "O" ;
  } 
cout << endl ;
cout << endl ;
  }
}

return 0;
} // remaining

int main()
{ // The 'main' subprogram is the core of the penny game, and it is here
  // that we’ll initialise our variables to use throughout the game. If
  // you wish to alter the amount of pennies available in the pile, who
  // will have the first turn, or if you wish to alter how many rounds
  // there are to play for, you can alter the 'pennyAmount', 'firstMove'
  // and 'gameAmount' variables accordingly.
bool firstMove = true ; // Allows the user to have the first turn.
int pennyAmount = 30 ; // Change this number to edit amount of pennies.
int currentAmount = pennyAmount ; // The difference in pennies.
int gameAmount = 5 ; // Change this number to the maximum amount of games.
int maxInput = 5; // The maximum amount you can take away from the pile.
int playerMove; // The players action.
int playerWins = 0 ; // Store the amount of times the player has won.
int computerWins = 0 ; // Store the amount of times the CPU has won.

// There's just something about a dos window that makes me want to gouge
// my eyes out with a spoon. It might have something to do with the
// mundane black & white console box that just makes it terribly hard to
// concentrate on. For that reason, I tried to spruce up the title screen
// a little to very limited effect. It looks decent for approximately one
// action before it spirals off to the top of the screen, never to be
// heard from or seen again.
cout << R"(
 ____                           ____                      
|  _ \ ___ _ __  _ __  _   _   / ___| __ _ _ __ ___   ___ 
| |_) / _ \ '_ \| '_ \| | | | | |  _ / _` | '_ ` _ \ / _ \
|  __/  __/ | | | | | | |_| | | |_| | (_| | | | | | |  __/
|_|   \___|_| |_|_| |_|\__, |  \____|\__,_|_| |_| |_|\___|
                       |___/                                            )"
<< endl ;
cout << endl ;

// This section is a basic explanation of the rules of the game and will
// give a visual view on the amount of coins the player is working with,
// as well as how many rounds there are to play for. Both of these amounts
// can be changed in the variables at the top of this subprogram and will
// be reflected in this introduction section for the players' convenience.
cout << "In this game, you'll be playing against the computer. The ";
cout << "rules are simple." << endl ;
cout << endl ;
cout << "Each turn, you'll enter a number between [1] and [5]." << endl ;
cout << endl ;
cout << "This number will subtract from the pile of [" << pennyAmount;
cout << "] pennies." << endl ;
cout << endl ;
cout << "Whoever gets left with [1] penny will lose the round." << endl ;
cout << endl ;
 if(gameAmount > 1)
 { // Nothing important, or impressive, but I wanted this section to be
   // grammatically correct. If the variable for the rounds were set to 1,
   // then the game will print 'round' as opposed to 'rounds.'
 cout << "The winner will be determined over [" << gameAmount << "] ";
 cout << "rounds." ;
 } else {
 cout << "The winner will be determined over [" << gameAmount << "] ";
 cout << "round." ;
 }
cout << endl ;
cout << endl ;
cout << "Pennies you're playing for:" << endl ;
  for(int loop = 0; loop < currentAmount; loop++)
  { // How many coins are left in the pile? Let's show the user how many
    // coins they are playing for. We'll represent them with the letter
    // 'O' rather than a flat number. Immersion!
  cout << "O" ;
  } 
cout << endl ;
cout << endl ;

while(playerWins + computerWins != gameAmount)
{ // This section of the game will be looped until the rounds are over. By
  // default, this means the game will end when the player has played [5]
  // rounds collectively. This value can be changed in the variables
  // declared at the top of the subprogram.

// This section is the core structure of the game and is where our 
// subprograms will be called into action. The game will rotate between
// the four subprograms in a very regimental order. The player will be
// given the first move, always, in every round of the game. After the
// players' move, the game will display the remaining pennies before
// allowing the computer to have their move and once again displaying the
// remaining pennies. These actions are looped until the game is over.
 if (firstMove == true)
 { // The subprograms will be called in this specific order if the player
   // has the first move. Otherwise, it'll call them in reverse order.
 action(playerMove, currentAmount, computerWins, maxInput) ;
 remaining(currentAmount, pennyAmount, playerWins, computerWins, gameAmount,
 playerMove, maxInput, firstMove) ;
 cpuAction(currentAmount, playerWins, firstMove, pennyAmount) ;
 remaining(currentAmount, currentAmount, playerWins, computerWins,
 gameAmount, playerMove, maxInput, firstMove) ;
 } else {
 cpuActionFirst(currentAmount, playerWins, firstMove, pennyAmount) ;
 remaining(currentAmount, currentAmount, playerWins, computerWins,
 gameAmount, playerMove, maxInput, firstMove) ;
 action(playerMove, currentAmount, computerWins, maxInput) ;
 remaining(currentAmount, pennyAmount, playerWins, computerWins, gameAmount,
 playerMove, maxInput, firstMove) ;
 }
}

if(playerWins + computerWins == gameAmount)
{ // Once the rounds have totalled the amount specified by our variable,
  // which at default is [5], then the overall winner will be announced by
  // checking whether the player has more wins than the computer. This is
  // the final task performed by the game before it prints the winner's
  // message and quits.
cout << endl ;
cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
cout << endl ;
cout << "The numbers are in..." << endl ;
cout << endl ;
cout << "Player wins: [" << playerWins << "] | Computer wins: [";
cout << computerWins << "]" << endl ;
cout << endl ;
cout << "...and we can officially announce..." << endl ;
 if(playerWins > computerWins)
 { // If the player has won more rounds than the computer then announce
   // that the player has won the overall game.
 cout << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 cout << "CONGRATULATIONS -- YOU WON THE GAME!" << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 } else if(playerWins < computerWins)
 { // If the player has lost more rounds than the computer then announce
   // that the player has lost the overall game.
 cout << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 cout << "OUCH -- THE COMPUTER WON THE GAME!" << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 } else if (playerWins == computerWins)
 { // If both the player and computer has won equal amount of rounds then
   // announce that there has been a draw. This is only possible if the
   // number of rounds has been set to an even amount, and therefore, will
   // not be shown by default.
 cout << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 cout << "OH NO -- IT'S A DRAW!" << endl ;
 cout << "<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>" << endl ;
 }
}
return 0;
} // main