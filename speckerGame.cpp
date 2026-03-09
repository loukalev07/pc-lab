#include <iostream>
#include "speckerMoveState.cpp"
#include "speckerPlayer.cpp"

class Game {
public:
    Game(int heaps, int players): playersno(players), heapsno(heaps), heapscount(0), playerscount(0) {
        Players = new Player *[players];
        Heaps = new int [heaps];
    }
    ~Game() {
        delete [] Players;
        delete [] Heaps;
    }

    void addHeap(int coins) {
        try {
            if (heapscount < heapsno) {
                Heaps[heapscount] = coins;
                heapscount++;
            }
            else {
                throw logic_error("Too many heaps");
            }
        }
        catch (logic_error exc) {
            cout << exc.what() << endl;
        }
    }

    void addPlayer(Player *player) {
        try {
            if (playerscount < playersno) {
                Players[playerscount++] = player;
            }
            else {
                throw logic_error("Too many players");
            }
        }
        catch (logic_error exc) {
            cout << exc.what() << endl;
        }    
    }

    void play(ostream &out){
        try {
            if (playerscount < playersno) {
                throw logic_error("Too little players");
            }
            State state(heapsno, Heaps, playersno);
            int count = 0;
            while (!state.winning()) {
                cout << "State: " << state << endl;
                cout << Players[count] << " " << Players[count]->play;
                state.next(Players[count++]->play);
                if (count == playersno) {
                    count = 0;
                }
            }
            cout << "State: " << state << endl;
            cout << Players[--count] << " wins";
        }
        catch (logic_error exc) {
            cout << exc.what() << endl;
        }
    }

    int getPlayers() const {
        return playersno;
    }

    const Player *getPlayer(int p) const  {

    }

private:
    int *Heaps; 
    Player **Players;
    int playersno, heapsno, playerscount, heapscount;

};