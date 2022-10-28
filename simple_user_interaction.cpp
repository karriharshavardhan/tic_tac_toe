#include <bits/stdc++.h>
using namespace std;

void display_game(vector<string> game_list);
void replacement_choice(vector<string> &game_list,int position);
int position_choice(vector<string> game_list);
void choice(vector<string> &game_list);

void display_game(vector<string> game_list)
{
    cout<<"[";
    for(int i=0;i<game_list.size();i++){
        cout<<game_list[i];
        if(i!=game_list.size()-1) cout<<",";
    }
    cout<<"]"<<endl;
}

void choice(vector<string> &game_list)
{
    cout<<"do you wish to play the game again?(y/n): ";
    char c;
    cin>>c;
    if(c=='y' || c=='Y') replacement_choice(game_list,position_choice(game_list));
    else if(c=='n' || c=='N'){
        cout<<"Thankyou for playing the game\n";
        return;
    }
    else{
        cout<<"invalid response\n";
        choice(game_list);
    }
}
void replacement_choice(vector<string> &game_list,int position)
{
    string h;
    cout<<"place a string to replace at position "<<position<<": ";
    cin>>h;
    game_list[position]=h;
    cout<<"the altered game list: ";
    display_game(game_list);
    choice(game_list);
}

int position_choice(vector<string> game_list)
{
    cout<<"the current game_list: ";
    display_game(game_list);
    int position;
    cout<<"pick a position, which you want to alter(0,1,2): ";
    cin>>position;
    if(position!=0 && position!=1 && position!=2){
        cout<<"sorry! invalid index\n";
        position=position_choice(game_list);
    }
    return position;
}

int main()
{
    vector<string> game_list;
    game_list={"0","1","2"};
    cout<<"intial game list: ";
    display_game(game_list);
    replacement_choice(game_list,position_choice(game_list));
    cout<<"final game list: ";
    display_game(game_list);
    return 0;
}