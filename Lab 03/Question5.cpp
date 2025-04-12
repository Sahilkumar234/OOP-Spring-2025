#include<iostream>
using namespace std;

class MusicPlayer {
    string playList[50];
    int songCount = 0;
    string currentPlayingSong;

    public:
    void addSongs(string song) {
        if(songCount < 50) {
            playList[songCount++] = song;
            cout<<"->Song: "<<song<<" added..."<<endl;
        }
        else {
            cout<<"Sorry Playlist is full!!!"<<endl;
        }
    }
    void removeSong(string song) {
        bool found = false;
        for(int i=0;i<songCount;i++) {
            if(playList[i] == song) {
                for(int j=0;j<songCount-1;j++) {
                    playList[j] = playList[j+1];
                }
                songCount--;
                found = true;
                cout<<"-> "<<song<<" Removed successfully..."<<endl;
                break;
            }
        }
        if(!found) {
            cout<<"There is no ->song "<<song<<" to remove..."<<endl;
        }
    }
    void playSong(string song) {
        bool found = false;
        for(int i=0;i<songCount;i++) {
            if(playList[i] == song) {
                currentPlayingSong = song;
                found = true;
                cout<<"Current song playing is: "<<currentPlayingSong<<endl;
                cout<<endl;
                break;
            }
        }
        if(!found) {
            cout<<"Your song "<<song<<" is not in playlist"<<endl;
        }
    }
    void displaySongs() {
        if(playList == 0) {
            cout<<"Play List is empty"<<endl;
        }
        else {
            cout<<endl;
            cout<<"PlayList of songs...."<<endl;
            for(int i=0;i<songCount;i++) {
                cout<<"Song "<<i+1<<": "<<playList[i]<<endl;
            }
            cout<<endl;
        }
    }
};

int main() {

    MusicPlayer M1;
    M1.addSongs("Musafir");
    M1.addSongs("Hoor");
    M1.addSongs("Faded");
    M1.displaySongs();

    M1.playSong("Hoor");

    M1.removeSong("Musafir");
    M1.displaySongs();

    return 0;
}
