#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function prototypes
void printCards (int cards[], int flipped[], int NUM_CARDS);
void initializeCards (int cards[], int NUM_CARDS);
void shuffle (int array[], int size);
int checkPairs (int cards[], int flipped[], int pair1, int pair2);
void clearScreen ();			// Function to clear the screen
void Inst (char x);
int main ()
{ char a,i;
  printf("Enter i to view instructions or any other character to continue game\n");
  scanf("%c",&a);
  if(a=='i'){
      Inst(i);
      scanf("%c",&a);
    }
  int NUM_CARDS;
  printf ("Enter the number of cards: ");
  scanf ("%d", &NUM_CARDS);

  if (NUM_CARDS % 2 != 0 || NUM_CARDS <= 0 || NUM_CARDS > 16)
	{
	  printf
		("Number of cards must be a positive even number and less than or equal to 16.\n");
	  return 1;
	}

  int *cards = (int *) malloc (NUM_CARDS * sizeof (int));
  int *flipped = (int *) malloc (NUM_CARDS * sizeof (int));
  int pairsRemaining = NUM_CARDS / 2;
  int MAX_ATTEMPTS = (NUM_CARDS / 2) + 1;
  int pair1, pair2;
  int attempts = 0;
  int count = MAX_ATTEMPTS;
  
  // Seed random number generator
  srand (time (NULL));

  // Initialize cards
  initializeCards (cards, NUM_CARDS);

  // Print initial state of cards
  printCards (cards, flipped, NUM_CARDS);

  // Main game loop
  
  while (pairsRemaining && attempts < MAX_ATTEMPTS && count >= 0)
	{
	  printf ("Attempts remaining: %d\n", count--);
	  printf ("Enter two card indices to flip (0 - %d): ", NUM_CARDS - 1);
	  scanf ("%d %d", &pair1, &pair2);

	  // Validate input
	  if (pair1 < 0 || pair1 >= NUM_CARDS || pair2 < 0 || pair2 >= NUM_CARDS)
		{
		  printf ("Invalid input. Please enter two valid indices.\n");
		  continue;
		}

	  // Check if the selected cards are already matched or flipped
	  if (flipped[pair1] || flipped[pair2])
		{
		  printf
			("Those cards are already matched or flipped. Please select other cards.\n");
		  continue;
		}

	  // Clear the screen
	  clearScreen ();

	  // Flip selected cards
	  flipped[pair1] = 1;
	  flipped[pair2] = 1;

	  // Print current state of cards with flipped ones visible
	  printCards (cards, flipped, NUM_CARDS);

	  // Check if the flipped cards match
	  if (checkPairs (cards, flipped, pair1, pair2))
		{
		  printf ("Match found!\n");
		  pairsRemaining--;		// Decrement pairs remaining
		}
	  else
		{
		  printf ("No match found. Flipping cards back...\n");
		  // Flip cards back after a delay
		  sleep (3);
		  flipped[pair1] = 0;
		  flipped[pair2] = 0;
		  // Clear the screen
		  clearScreen ();
		  printCards (cards, flipped, NUM_CARDS);
		}

	  attempts++;				// Increment attempts
	}

  if (pairsRemaining == 0)
	{
	  printf ("Congratulations! You've matched all the pairs!\n");
	}
  else
	{
	  printf
		("You've lost the game. All pairs were not matched within %d attempts.\n",
		 MAX_ATTEMPTS);
	}
  free (cards);
  free (flipped);
      
  
  

  return 0;
}

void Inst (char x)
{
  printf ("1.   Objective:\n");
  printf ("a)Match all pairs of cards within a limited number of attempts.\n");
  printf ("2.   Setup:\n");
  printf ("a)Enter the number of cards you want to play with (must be a positive even number and less than or equal to 16).\n");
  printf ("b)The cards will be displayed face down initially.\n");
  printf ("3.   Gameplay:\n");
  printf ("a)You have a limited number of attempts to flip and match pairs of cards.\n");
  printf ("b)Each turn, you'll input two card indices to flip.\n");
  printf ("c)If the selected cards match, they remain face up.\n");
  printf ("d)If they don't match, they flip back after a brief delay.\n");
  printf ("4.   Rules:\n");
  printf ("a)You can only flip two cards per turn.\n");
  printf ("b)You cannot flip cards that are already matched or flipped.\n");
  printf ("c)If you flipped the cards that are already flipped than your attempts will reduce by 1.\n");
  printf ("d)The game ends when all pairs are matched or when the maximum attempts are reached.\n");
  printf ("5.   Controls:\n");
  printf ("a)Press the Enter key to select a card.\n");
  printf ("6.   Winning:\n");
  printf ("a)Match all pairs of cards within the given attempts to win the game.\n");
  printf ("7.    Losing:\n");
  printf ("a)If you fail to match all pairs within the given attempts, you lose the game.\n");
  printf ("8.   Restart:\n");
  printf ("a)To play again, restart the program.\n");
  printf ("9.    Note:\n");
  printf ("a)Enjoy the challenge of testing your memory skills and have fun matching the pairs of cards!\n");
 
}

void
printCards (int cards[], int flipped[], int NUM_CARDS)
{
  printf ("\nCurrent state of cards:\n");
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  // Print the card pattern instead of "?"
		  printf (" __________");
		}
	  else
		{
		  printf (" __________");
		}
	}
  printf ("\n");

  // Print the second row of cards
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|         |");
		}
	  else
		{
		  printf ("|         |");
		}
	}
  printf ("\n");
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|         |");
		}
	  else
		{
		  printf ("|         |");
		}
	}
  printf ("\n");
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|         |");
		}
	  else
		{
		  printf ("|         |");
		}
	}
  printf ("\n");
  // Print the third row of cards with card values
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|   %2d    |", cards[i]);	// Assuming card values are two digits
		}
	  else
		{
		  printf ("|    ?    |");
		}
	}
  printf ("\n");

  // Print the fourth row of cards
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|         |");
		}
	  else
		{
		  printf ("|         |");
		}
	}
  printf ("\n");
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|         |");
		}
	  else
		{
		  printf ("|         |");
		}
	}
  printf ("\n");

  // Print the bottom row of cards
  for (int i = 0; i < NUM_CARDS; i++)
	{

	  if (flipped[i])
		{
		  printf ("|_________|");
		}
	  else
		{
		  printf ("|_________|");
		}
	}
  printf ("\n");
}

// Function to initialize cards with random numbers
void
initializeCards (int cards[], int NUM_CARDS)
{
  for (int i = 0; i < NUM_CARDS; i++)
	{
	  cards[i] = (i % (NUM_CARDS / 2)) + 1;
	}
  // Shuffle the cards
  shuffle (cards, NUM_CARDS);
}

// Function to shuffle an array
void
shuffle (int array[], int size)
{
  for (int i = 0; i < size - 1; i++)
	{
	  int j = i + rand () % (size - i);
	  int temp = array[i];
	  array[i] = array[j];
	  array[j] = temp;
	}
}

// Function to check if the flipped cards match
int
checkPairs (int cards[], int flipped[], int pair1, int pair2)
{
  return cards[pair1] == cards[pair2];
}

// Clear the screen using ANSI escape codes
void
clearScreen ()
{
  printf ("\033[2J\033[H");
}