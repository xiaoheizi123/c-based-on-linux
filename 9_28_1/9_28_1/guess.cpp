#include <iostream>
#include <iomanip>

#include "random.h"
#include "guess.h"

using namespace std;

const int lowest_price=100;
const int highest_price = 200;
const int guess_count = 6;

static int InitializeBout();

static bool	PlayBout(int actual_price,int lowest_price,int highest_price,int chances_left);

static bool Again();

static int GetPrice(int lowest_price, int highest_price, int  chances_left);

static int CheckPrice(int lowest_price, int highest_price, int  guess_price);

static int JudgePrice(int actual_price, int guess_price);

void PrintWelcomeInfo()
{
	cout << "if you guess the right price between the already known ranges,you are win,you have " << count << "chances" << endl;

}


void InitializeGame()
{
	int i, n;
	Randomize();
}

double PlayGame()
{
	int actual_price, lower_price = lowest_price, higher_price = highest_price;
	int chances_left = guess_count;
	int bout_count = 0, prevailed_bout_cout = 0;
	while (true)
	{
		cout << endl;
		actual_price = InitializeBout();
		if (PlayBout(actual_price, lower_price, higher_price, chances_left))
			prevailed_bout_cout++;
		bout_count++;
		if (!Again())
			break;
	}
	return (double)prevailed_bout_cout / (double)bout_count;
}

void PrintGameOverInfo(double prevailed_ratio)
{
	cout << "prevailed retio" << setw(3) << prevailed_ratio * 100 << "%.\n";
	if (prevailed_ratio >= 0.75)
		cout << "you are luckyyyyyy!\n\n";
	else if (prevailed_ratio >= 0.5)
		cout << "you can do better.\n\n";

}

static int InitializeBout()
{
	return GenerateRandomNumber(lowest_price, highest_price);

}