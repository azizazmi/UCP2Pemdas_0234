#include <iostream>
#include <string>
#include <vector>
using namespace std;

class team;

class player {
public:
    string nama;
    player(string pNama) :nama(pNama) {}
};

class sponsor {
public:
    string nama;
    vector<team*> daftar_team;
    sponsor(string pNama) :nama(pNama) {}
   
    void tambahTeam(team*);
    void cetakTeam();
};

class team {
public:
    string nama;
    vector<sponsor*> daftar_sponsor;
    vector<player*> daftar_player;


    team(string pNama) :nama(pNama) {}


    void tambahSponsor(sponsor*);
    void cetakSponsor();
    void tambahPlayer(player*);
    void cetakPlayer();
};

void sponsor::tambahTeam(team* pTeam) {
    daftar_team.push_back(pTeam);
}

void sponsor::cetakTeam() {
    cout << "Nama Team dari Sponsor " << this->nama << " :\n";
    for (auto& a : daftar_team) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void team::tambahSponsor(sponsor* pSponsor) {
    daftar_sponsor.push_back(pSponsor);
    pSponsor->tambahTeam(this);
}

void team::cetakSponsor() {
    cout << "Nama Sponsor dari Team " << this->nama << " :\n";
    for (auto& a : daftar_sponsor) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void team::tambahPlayer(player* pPlayer) {
    daftar_player.push_back(pPlayer);
}

void team::cetakPlayer() {
    cout << "Nama Player dari Team " << this->nama << " :\n";
    for (auto& a : daftar_player) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    team* Team1 = new team("Onic Esport");
    team* Team2 = new team("Evos Esport");
    sponsor* Sponsor1 = new sponsor("Leica");
    sponsor* Sponsor2 = new sponsor("Nike");
    sponsor* Sponsor3 = new sponsor("Samsung");

    Team1->tambahSponsor(Sponsor1);
    Team1->tambahSponsor(Sponsor2);
    Team1->tambahSponsor(Sponsor3);
    Team2->tambahSponsor(Sponsor3);
    Team2->tambahSponsor(Sponsor1);

    player* Player1a = new player("Kirun");
    player* Player1b = new player("Cuplis");
    player* Player1c = new player("Sule");
    player* Player2a = new player("Karjo");
    player* Player2b = new player("Budi");
   
    Team1->tambahPlayer(Player1a);
    Team1->tambahPlayer(Player1b);
    Team1->tambahPlayer(Player1c);
    Team2->tambahPlayer(Player2a);
    Team2->tambahPlayer(Player2b);

    Team1->cetakSponsor();
    Team2->cetakSponsor();
    Team1->cetakPlayer();
    Team2->cetakPlayer();
    Sponsor1->cetakTeam();
    
    return 0;
}