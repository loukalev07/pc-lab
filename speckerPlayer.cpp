#include <iostream>

class Player {
public:
    Player(const string &n): name(n) {}
    virtual ~Player();

    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player) {
        out << player.getType() << " player " << player.name; 
    }
private:
    string name;
};

class GreedyPlayer: public Player {
public:
    GreedyPlayer(const string &n): Player(n) {}
    ~GreedyPlayer() override {}

    const string & getType() const override {
        static string type = "Greedy";
        return type;
    }

    Move play(const State &s) override {
        int max = s.getCoins(0), source = 0;
        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max) {
                max = s.getCoins(i);
                source = i;
            }
        }
        return Move(source, max, 0, 0);
    }
};

class SpartanPlayer: public Player {
public:
    SpartanPlayer(const string &n): Player(n) {}
    ~SpartanPlayer() override {}

    const string & getType() const override {
        static string type = "Spartan";
        return type;
    }

    Move play(const State &s) override {
        int max = s.getCoins(0), source = 0;
        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max) {
                max = s.getCoins(i);
                source = i;
            }
        }
        return Move(source, 1, 0, 0);
    }
};

class SneakyPlayer: public Player {
public:
    SneakyPlayer(const string &n): Player(n) {}
    ~SneakyPlayer() override {}

    const string & getType() const override {
        static string type = "Sneaky";
        return type;
    }

    Move play(const State &s) override {
        int min = s.getCoins(0), source = 0;
        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) < min) {
                min = s.getCoins(i);
                source = i;
            }
        }
        return Move(source, min, 0, 0);
    }
};

class RighteousPlayer: public Player {
public:
    RighteousPlayer(const string &n): Player(n) {}
    ~RighteousPlayer() override {}

    const string & getType() const override {
        static string type = "Righteous";
        return type;
    }

    Move play(const State &s) override {
        int max = s.getCoins(0), min = s.getCoins(0), sourcemax = 0, sourcemin = 0;
        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > max) {
                max = s.getCoins(i);
                sourcemax = i;
            }
            if (s.getCoins(i) < min) {
                min = s.getCoins(i);
                sourcemin = i;
            }
        }
        return Move(sourcemax, (max / 2), sourcemin, (max / 2) - 1);
    }
};
