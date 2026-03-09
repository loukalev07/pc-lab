#include <iostream>

using namespace std;

class Move {
public:
    Move(int sh, int sc, int th, int tc): sheap(sh), scoins(sc), theap(th), tcoins(tc) {}

    int getSource() const {
        return sheap;
    }

    int getSourceCoins() const {
        return scoins;
    }

    int getTarget() const {
        return theap;
    }

    int getTargetCoins() const {
        return tcoins;
    }

    friend ostream & operator << (ostream &out, const Move &move) {
        out << "takes " << move.scoins << " coins from heap " << move.sheap << " and puts ";
        if (move.tcoins == 0) out << "nothing";
        else out << move.tcoins << " coins to heap " << move.theap;
        return out;
    }

private:
    int sheap, scoins, theap, tcoins;
};

class State {
public:
    // State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n): heaps(h), players(n), playing(0) {
        coins = new int[heaps];
        for (int i = 0; i < heaps; i++) {
            coins[i] = c[i];
        }
    }
    
    ~State() {
        delete [] coins;
    }

    void next(const Move &move) throw(logic_error) {
        if (move.getSource() < 0 || move.getSource() >= heaps) {
                    throw logic_error("Invalid source heap");
        }
        if (move.getTarget() < 0 || move.getTarget() >= heaps) {
                    throw logic_error("Invalid target heap");
        }
        if (move.getSourceCoins() < 0 || move.getSourceCoins() > coins[move.getSource()]) {
                    throw logic_error("Invalid number of coins to take");

        }         
        if (move.getTargetCoins() < 0 || move.getTargetCoins() > move.getSourceCoins()) {
                    throw logic_error("Invalid number of coins to put");
        }
        coins[move.getSource()] -= move.getSourceCoins();
        coins[move.getTarget()] += move.getTargetCoins();
        if (playing == players - 1) playing = 0;
        else playing++;
    }

    bool winning() const {
        bool win = true;
        for (int i = 0; i < heaps; i++) {
            if (coins[i] > 0) win = false;
        }
        return win;
    }

    int getHeaps() const {
        return heaps;
    }

    int getCoins(int h) const throw(logic_error) {
        if (h < 0 || h >= heaps) {
            throw logic_error("Invalid heap");
        }
        return coins[h];
    }

    int getPlayers() const {
        return players;
    }

    int getPlaying() const{
        return playing;
    }

    friend ostream & operator << (ostream &out, const State &state) {
        for (int i = 0; i < state.heaps - 1; i++) {
            out << state.coins[i] << ", ";
        }
        out << state.coins[state.heaps -1] 
            << " with " << state.playing 
            << "/" << state.players << " playing next";
        return out;
    }

private:
    int heaps, players, playing;
    int *coins;
};
