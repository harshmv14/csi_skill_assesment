#include <iostream>
#include <vector>
#include <string>
#define max 1000
using namespace std;

class player
{
    static int N;
    int ID;
    string name;
    string country;
    int matches;
    string type;
    int runs;
    float bat_avg;
    float strike_rate;
    int bowls_faced;
    int wickets;
    float economy;
    int bowls_delivered;
    int runs_leaked;

public:
    player()
    {
        ID = N++;
        string temp;
        cout << "Enter Name of the player: ";
        cin >> name;
        cout << "Enter the country: ";
        cin >> country;
        cout << "Enter number of Matches: ";
        cin >> matches;
        cout << "Is the player a batsman(Bat) or a bowler(Bowl) or an allrounder(All): ";
        cin >> temp;
        if (temp == "Bat" || "bat")
        {
            type = "Batsman";
        }
        else if (temp == "Bowl" || "bowl")
        {
            type = "Bowler";
        }
        else if (temp == "all" || "All")
        {
            type = "All Rounder";
        }
        cout << "Enter the runs scored by the player: ";
        cin >> runs;
        bat_avg = float(runs) / matches;
        cout << "Enter the bowls faced by the player: ";
        cin >> bowls_faced;
        strike_rate = (float(runs) / bowls_faced) * 100;
        cout << "Enter wickets taken by the player: ";
        cin >> wickets;
        cout << "Enter bowls delivered by the player: ";
        cin >> bowls_delivered;
        cout << "Enter runs leaked by the player: ";
        cin >> runs_leaked;
        economy = (float(runs_leaked) / bowls_delivered) * 6;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Country: " << country << endl;
        cout << "Type: " << type << endl;
        cout << "Number of matches: " << matches << endl;
        cout << "Runs scored: " << runs << endl;
        cout << "Batting Average: " << bat_avg << endl;
        cout << "Strike Rate: " << strike_rate << endl;
        cout << "Wickets taken: " << wickets << endl;
        cout << "Economy: " << economy << endl;
    }

    string get_name(){
        return name;
    }

    void modify(){
         string temp;
        cout << "Enter Name of the player: ";
        cin >> name;
        cout << "Enter the country: ";
        cin >> country;
        cout << "Enter number of Matches: ";
        cin >> matches;
        cout << "Is the player a batsman(Bat) or a bowler(Bowl) or an allrounder(All): ";
        cin >> temp;
        if (temp == "Bat" || "bat")
        {
            type = "Batsman";
        }
        else if (temp == "Bowl" || "bowl")
        {
            type = "Bowler";
        }
        else if (temp == "all" || "All")
        {
            type = "All Rounder";
        }
        cout << "Enter the runs scored by the player: ";
        cin >> runs;
        bat_avg = float(runs) / matches;
        cout << "Enter the bowls faced by the player: ";
        cin >> bowls_faced;
        strike_rate = (float(runs) / bowls_faced) * 100;
        cout << "Enter wickets taken by the player: ";
        cin >> wickets;
        cout << "Enter bowls delivered by the player: ";
        cin >> bowls_delivered;
        cout << "Enter runs leaked by the player: ";
        cin >> runs_leaked;
        economy = (float(runs_leaked) / bowls_delivered) * 6;
    }

    friend void highestruns(vector<player *> &Player);
    friend void highestwickets(vector<player *> &Player);
};

int player::N = 1;

void highestruns(vector<player *> &Player){
    int maxruns=0;
    int n;
    for(int i=0;i<player::N;i++){
            if(Player[i]->runs > max){
                maxruns = Player[i]->runs;
                n = i;
            }
        
    }

    Player[n]->print();
}

void highestwickets(vector<player *> &Player){
    int maxwickets=0;
    int n;
    for(int i=0;i<player::N;i++){
            if(Player[i]->wickets > max){
                maxwickets = Player[i]->wickets;
                n = i;
            }
        
    }

    Player[n]->print();
}

int main()
{
    vector<player *> Player(max);
    int i = 0;
    Player[i++] = (new player);
    Player[i++] = (new player);
    for (int j = 0; j < i; j++)
    {
        Player[j]->print();
    }
    while(true){
        cout << "1. Enter new player" << endl;
        cout << "2. Modify PLayer Details" << endl;
        cout << "3. View All players" << endl;
        cout << "4. Search a player" << endl;
        cout << "5. View Rankings" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
            Player[i++] = new player;
            break;
            case 2:
            {
            string temp;
            cout << "Enter name: ";
            cin >> temp;
            for(int j=0; j<i;j++){
                if(temp == Player[j]->get_name()){
                    Player[j]->modify();
                    break;
                }
            }
            }
            break;
            case 3:
            for(int j=0;j<i;j++){

                Player[j]->print();
                cout << endl;

            }
            break;

            case 4:
            {
            string temp;
            cout << "Enter name of player to search :";
            cin >> temp;
            for(int j=0; j<i; j++){
                if(temp == Player[j]->get_name()){
                    Player[j]->print();
                }
            }
            }
            break;

            case 5:
            cout << "Highest Runs: " << endl;
            highestruns(Player);
            cout << "Highest Wickets: " << endl;
            highestwickets(Player);
            break;

            case 6:
            exit(0);
        }
    }
    return 0;
}