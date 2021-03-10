#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

// score map for printing the score
const string Score[] = {"0", "15", "30", "40", "ADV"};

class Game
{
    // see below for explanations
    public:
    Game();
    bool createPlayer(int playerId, string playerName);
    string getName(int playerId);
    bool hasADV(int playerId);
    bool setScore(int playerId, int score);
    int getIntScore(int playerId);
    string getStringScore(int playerId);

    private:
    string players[2]; // players' name
    int scores[2]; // players' score
};

Game::Game()
{
    scores[0] = 0;
    scores[1] = 0;
}

bool Game::createPlayer(int playerId, string playerName)
{
    if (playerId == 0 || playerId == 1)
    {
        players[playerId] = playerName;
        return true;
    }
    else
        return false;
}

string Game::getName(int playerId)
{
    if (playerId == 0 || playerId == 1)
        return players[playerId];
    else
        return "N/A";
}

bool Game::hasADV(int playerId)
{
    if (scores[playerId]==4)
        return true;
    else
        return false;
}

bool Game::setScore(int playerId, int score)
{
    if (score < 5)
        scores[playerId]=score;
    else
        return false;
}

int Game::getIntScore(int playerId)
{
    return scores[playerId];
}

string Game::getStringScore(int playerId)
{
    return Score[scores[playerId]];
}
//=======================================

int main()
{
    // rand init
    srand(time(NULL));

    // setting up the game
    Game myGame;
    myGame.createPlayer(0, "Petar");
    myGame.createPlayer(1, "Ivan");

    //starting game loop
    bool stop = false;
    while(!stop)
    {
        // identifying winner and looser
        int pointWinner = rand()%2;
        int pointLooser=(pointWinner+1)%2;
        cout << "The winner of the point is " << myGame.getName(pointWinner) << endl;

        // The pointWinner has advantage => win
        if (myGame.hasADV(pointWinner))
        {
            stop = true;
            cout << "Winner is " << myGame.getName(pointWinner) << endl;
        } // The opponent has advantage => tie (40-40)
        else if (myGame.hasADV(pointLooser))
            myGame.setScore(pointLooser, 3);
        // Tie (40-40) => pointWinner gets advantage
        else if (myGame.getIntScore(pointWinner)==3 && myGame.getIntScore(pointLooser) == 3)
            myGame.setScore(pointWinner, 4);
        //pointWinner is 1 point ahead of pointLooser and >=30
        else if (myGame.getIntScore(pointWinner)>myGame.getIntScore(pointLooser) && myGame.getIntScore(pointWinner)>=2)
        {
            stop = true;
            cout << "Winner is " << myGame.getName(pointWinner) << endl;
        }
        else // nothing special, pointWinner marks the point
            myGame.setScore(pointWinner, myGame.getIntScore(pointWinner)+1);

        // printing score
        if (!stop)
            cout << "Score : " << myGame.getName(0) << " " << myGame.getStringScore(0) << " - " << myGame.getStringScore(1) << " " << myGame.getName(1) << endl;
    }

    return 0;
}
