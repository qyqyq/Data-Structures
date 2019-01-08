#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void rmv(int cnt, PlaylistNode* head, PlaylistNode* temp)
{
    if(cnt == 1){
        head = temp->GetNext();
        return;
    }
    PlaylistNode* iter = head;
    while(--cnt)
        iter->GetNext();
    iter = iter -> GetNext();
    iter = temp->GetNext();
}

int main()
{
    PlaylistNode* head;
    PlaylistNode* tail = head;
    PlaylistNode* iter;
    PlaylistNode* nodebef;
    PlaylistNode* nodeaft;

    string uniqueid;
    string songname;
    string artistname;
    int songlength;
    int cnt,bef,aft,n;

    cout << "Enter playlist's title:\n" << endl;
    string title;
    getline(cin, title);

    string option = "";
    while(option.compare("q")){
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << "" << endl;
        cout << "Choose an option:" << endl;

        cin >> option;
        if(option[0]=='a'){
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> iter->UniqueId;
            cout << "Enter song's name:" << endl;
            cin >> iter->SongName;
            cout << "Enter artist's name:" << endl;
            cin >> iter->ArtistName;
            cout << "Enter song's length (in seconds):" << endl;
            cin >> iter->SongLength;
            tail->InsertAfter(iter);
        }
        else if(option[0]=='d'){
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueid;

            cnt=0;
            iter = head;
            while(iter->GetNext()){
                cnt++;
                iter = iter->GetNext();
                if(iter->UniqueId == uniqueid) break;
            }

            cout << "\"" << iter->SongName << "\" removed" << endl;
            rmv(cnt, head, iter);
        }
        else if(option[0]=='c'){
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> bef;
            cout << "Enter new position for song:" << endl;
            cin >> aft;

            for(n=0, iter = head; iter != tail; iter = iter->GetNext())
                n++;
            if(bef < 1)
                bef = 1;
            if(bef > n)
                bef = n;
            if(aft < 1)
                aft = 1;
            if(aft >n)
                aft = n;

            for(cnt = 0, iter = head; iter != tail; iter->GetNext(), cnt++){
                if(cnt == bef)
                    break;
            }
            nodebef = iter;
            songname = iter->SongName;
            for(cnt = 0, iter = head; iter != tail; iter = iter->GetNext(), cnt++){
                if(cnt == aft-1)
                    break;
            }
            nodeaft = iter;

            rmv(bef,head,iter);
            nodeaft->InsertAfter(nodebef);
            cout << "\"" << songname << "\" moved to position " << aft << endl;
        }
        else if(option[0]=='t'){
            for(cnt=0, iter = head; iter != tail; iter->GetNext())
                cnt+=iter->SongLength;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << cnt << " seconds" << endl;
        }
        else if(option[0]=='s'){
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
                cout << "Enter artist's name:" << endl;
                cin >> artistname;
                for(cnt=0, iter = head; iter != tail; iter->GetNext(), cnt++){
                    if(artistname.compare(iter->ArtistName) == 0){
                        cout << endl;
                        cout << cnt << '.' << endl;
                        iter->PrintPlaylistNode();
                    }
                }
        }
        else if(option[0]=='o'){
            if(head == nullptr)
                    cout << "Playlist is empty" << endl;
                else{
                    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
                    cnt = 0;
                    iter = head;
                    while(iter != tail){
                        cout << ++cnt << '.' << endl;
                        iter=iter->NextNodePtr;
                        iter->PrintPlaylistNode();
                        cout << endl;
                    }
                }
                break;
        }
    }
    return 0;
}
