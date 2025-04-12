#include <iostream>
using namespace std;

class GameLevel
{
    string level;
    int difficulty;

public:
    GameLevel(string level, int difficulty) : level(level), difficulty(difficulty) {}

    void displayLevel() const
    {
        cout << "Level: " << level << endl;
        cout << "Difficulty: " << difficulty << endl;
        cout << "<----------------------------------->" << endl;
    }
};

class VideoGame
{
    string name;
    int capacity;
    int levelCount;
    GameLevel **levels;
    string genre;

public:
    VideoGame(string name, string genre, int capacity) : name(name), genre(genre), capacity(capacity), levelCount(0)
    {
        levels = new GameLevel *[capacity];
    }

    ~VideoGame()
    {
        for (int i = 0; i < levelCount; i++)
        {
            delete levels[i];
        }
        delete[] levels;
    }

    void addLevel(string level, int difficulty)
    {
        if (levelCount < capacity)
        {
            levels[levelCount++] = new GameLevel(level, difficulty);
            cout << "" << level << " added To Game " << name << endl;
        }
        else
        {
            cout << "There is no enough space to add game..." << endl;
        }
        cout << "<----------------------------------->" << endl;
    }

    void displayGame() const
    {
        cout << "Title: " << name << endl;
        cout << "Genre: " << genre << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i]->displayLevel();
        }
    }
};

int main()
{
    VideoGame G("Space Invaders", "Arcade/Shooter", 4);

    G.addLevel("Earth Orbit", 2);
    G.addLevel("Aestroid belt", 4);
    G.addLevel("Alien Planet", 6);
    G.addLevel("Mothership Assault", 8);

    G.displayGame();
}
