#include <iostream>
using namespace std;

int main();


// declaring the function
void token(int K, int N, int numToken);

int main() {
    // variable K is for user enter for tokens to reach, variable N is the number of turns the user wants to find 
    int K, N;

    while (true) {

        /* Your program should ask the user for the goal number of tokens, and the number of turns allowed. It should
        then search and either report to the user that the total cannot be reached within the desired number of turns,
        or the exact sequence of moves for doing so, in order from the start state.*/

        cout << "How many tokens do you want to reach? :" << endl;
        cin >> K;
        cout << "How many turns are allowed?:" << endl;
        cin >> N;
        cout << "Looking for solution in " << N << " turns." << endl;

        //1. You start the game with exactly 13 tokens. 

        int numToken = 13;
        token(K, N, numToken);

        // ask the user if they want to play again

        cout << "Play again? [Y/N]" << endl;
        char answer;
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'N')
        {
            cout << "Goodbye." << endl;
            break;
        }

    }

}

/*2. On each turn, you may do one of two things:
a. You may ask for exactly 25 more tokens; or,
b. If the number of tokens you have is an even number, you may give back exactly half of the
tokens you have.
*/

void token(int K, int N, int numToken)
{
    if (N == 0)
    {
        cout << "No solutions found for the selected parameters" << endl;
    }
    else
    {

        if (numToken == K)
        {
            cout << "Solution was found, there are " << N << " turn(s) left." << endl;
        }
        else if (numToken % 2 == 0)
        {
            numToken /= 2;
            cout << "Giving back half, you have " << numToken << " tokens left." << endl;
            token(K, N - 1, numToken);
        }
        else
        {
            numToken += 25;
            cout << "By asking for 25 more tokens, you have " << numToken << " tokens." << endl;
            token(K, N - 1, numToken);

        }

    }

}