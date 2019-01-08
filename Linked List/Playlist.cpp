#include <iostream>
#include <string>
#include "Playlist.h"

PlaylistNode::PlaylistNode(string uniqueid, string songname, string artistname, int songlength, PlaylistNode* nextnodeptr)
{
    this->UniqueId = uniqueid;
    this->SongName = songname;
    this->ArtistName = artistname;
    this->SongLength = songlength;
    this->NextNodePtr = nextnodeptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* temp = this->NextNodePtr;
    this->NextNodePtr = nodePtr;
    nodePtr->NextNodePtr = temp;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this -> NextNodePtr = nodePtr;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this -> NextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->UniqueId << endl;
    cout << "Song Name: " << this->SongName << endl;
    cout << "Artist Name: " << this->ArtistName << endl;
    cout << "Song Length (in seconds): " << this->SongLength << endl;
}
