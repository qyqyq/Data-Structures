#include <string>
using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string uniqueid, string songname, string artistname, int songlength, PlaylistNode* nextnodeptr = nullptr);
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    string UniqueId;
    string SongName;
    string ArtistName;
    int SongLength;
    PlaylistNode* NextNodePtr;
};
