#include <iostream> 
#include <string>
#include <vector>
using namespace std;

//! Class team
/*! Mendeklarasikan class team*/
class team;

//! Class player
/*! berisikan variable nama dan member initialization list dengan access modifier public*/
class player {
public: /*! access modifier public*/
    string nama; /*! variabel nama memiliki tipe data string*/
    player(string pNama) :nama(pNama) {}  /*! Member initialization list */
};

//! Class sponsor
/*! berisikan variable nama, daftar_team (pointer ke class team), member initialization list, serta methode tambahTeam(dengan pointer ke class team) dan methode cetakTeam, di mana semua variable dan methode memiliki access modifier public*/
class sponsor { 
public:  /*! access modifier public*/
    string nama;  /*! variabel nama memiliki tipe data string*/
    vector<team*> daftar_team;  /*! variabel daftar_team memakai class template vector yang merepresentasikan array yang bisa berubah ukurannya*/
    sponsor(string pNama) :nama(pNama) {} /*! member initialization list*/
    
    void tambahTeam(team*);  /*! deklarasi prosedur/methode tambahTeam (pointer ke class team)*/
    void cetakTeam(); /*! deklarasi prosedur/methode cetakTeam*/
};

//! Class team
/*! berisikan variable nama, daftar_sponsor (pointer ke class sponsor), dan daftar_player (pointer ke class player), member initialization list, serta methode/prosedur tambahSponsor, cetakSponsor, tambahPlayer, dan cetakPlayer, di mana semua variable dan methode memiliki access modifier public*/
class team {
public: /*! access modifier public*/
    string nama; /*! variabel nama memiliki tipe data string*/
    vector<sponsor*> daftar_sponsor;  /*! variabel daftar_sponsor memakai class template vector yang merepresentasikan array yang bisa berubah ukurannya*/
    vector<player*> daftar_player;  /*! variabel daftar_player memakai class template vector yang merepresentasikan array yang bisa berubah ukurannya*/

    team(string pNama) :nama(pNama) {}  /*! member initialization list*/

    void tambahSponsor(sponsor*); /*! deklarasi prosedur/methode tambahSponsor (pointer ke class sponsor)*/
    void cetakSponsor();  /*! deklarasi prosedur/methode cetakSponsor*/
    void tambahPlayer(player*); /*! deklarasi prosedur/methode tambahPlayer (pointer ke class player)*/
    void cetakPlayer(); /*! deklarasi prosedur/methode cetakPlayer*/
};

//! Prosedur tambahTeam untuk class sponsor
/*! berisikan perintah push_back */
void sponsor::tambahTeam(team* pTeam) {
    daftar_team.push_back(pTeam); /*! digunakan untuk menge-push data dari daftar_team */
}

//! Prosedur cetakTeam untuk class sponsor
/*! berisikan perintah cout, dan menggunakan perulangan for */
void sponsor::cetakTeam() {
    cout << "Nama Team dari Sponsor " << this->nama << " :\n";  /*! digunakan untuk menampilkan nama-nama team dari sponsor tertentu*/
    for (auto& a : daftar_team) {    /*! digunakan untuk perulangan data-data dari variabel daftar_team yang terdapat dalam vector*/
        cout << a->nama << "\n";  /*! digunakan untuk menampilkan nama-nama */
    }
    cout << endl; /*! digunakan untuk menampilkan dengan ganti baris*/
}

//! Prosedur tambahSponsor untuk class team
/*! berisikan perintah push.back dan pointer */
void team::tambahSponsor(sponsor* pSponsor) {
    daftar_sponsor.push_back(pSponsor); /*! digunakan untuk menge-push data dari daftar_sponsor*/
    pSponsor->tambahTeam(this); /*! digunakan untuk mengakses data dari prosedur tambahTeam*/
}

//! Prosedur cetakSponsor untuk class team
/*! berisikan perintah cout dan menggunakan perulangan for */
void team::cetakSponsor() {
    cout << "Nama Sponsor dari Team " << this->nama << " :\n"; /*! digunakan untuk menampilkan nama-nama sponsor dari team tertentu*/
    for (auto& a : daftar_sponsor) { /*! digunakan untuk perulangan data-data dari variabel daftar_sponsor yang terddapat dalam vector*/
        cout << a->nama << "\n"; /*! digunakan untuk menampilkan nama-nama*/
    }
    cout << endl; /*! digunakan untuk menampilkan dengan ganti baris*/
}

//! Prosedur tambahPlayer untuk class team
/*! berisikan perintah push.back */
void team::tambahPlayer(player* pPlayer) {
    daftar_player.push_back(pPlayer); /*! digunakan untuk menge-push data dari variabel daftar_player*/
}

//! Prosedur cetakPlayer untuk class team
/*! berisikan perintah cout dan perulangan for */
void team::cetakPlayer() {
    cout << "Nama Player dari Team " << this->nama << " :\n"; /*! digunakan untuk menampilkan nama-nama player dari team tertentu*/
    for (auto& a : daftar_player) {  /*! digunakan untuk perulangan data-data dari variabel daftar_player yang terddapat dalam vector*/
        cout << a->nama << "\n"; /*! digunakan untuk menampilkan nama-nama*/
    }
    cout << endl; /*! digunakan untuk menampilkan dengan ganti baris*/
}

//! Fungsi Main/Utama dari program untuk menjalankan semua prosedur
/*! berisikan:
 object Team1 dengan nama Onic Esport dan Team2 dengan nama Evos Esport dari class team,
 object Sponsor1 dengan nama Leica, Sponsor2 dengan nama Nike, Sponsor3 dengan nama Samsung dari class sponsor,
 object Player1a dengan nama Kirun, Player1b dengan nama Cuplis, Player1c dengan nama Sule, Player2a dengan nama Karjo, Player2b dengan nama Budi dari class player
 perintah untuk mengakses tambahSponsor pada object Team1 dan Team2 dan menambahkan sponsor dari masing-masing team,
 perintah untuk mengakses tambahPlayer pada object Team1 dan Team2 dan menambahkan player dari masing-masing team,
 perintah untuk mengakses cetakSponsor pada object Team1 dan Team2,
 perintah untuk mengakses cetakPlayer pada object Team1 dan Team2,
 perintah untuk mengakses cetakTeam pada object Sponsor1,
 dan perintah return 0 untuk mengakhiri program
 */
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

