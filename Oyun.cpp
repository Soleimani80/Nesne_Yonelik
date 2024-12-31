#include <iostream>
using namespace std;


// Nesne sınıfı****************
class Nesne {
protected:
    int x, y;

public:
    Nesne(int x, int y) : x(x), y(y) {} // Nesne oluşturucu
    virtual ~Nesne() {} // Sanal yıkıcı

    int getX() const { return x; } // X koordinatını döndür
    int getY() const { return y; } // Y koordinatını döndür

    virtual bool etkilesim(int& score) = 0; // Etkileşim fonksiyonu (sanal)
};


// Oyuncu sınıfı****************
class Player {
private:
    int x, y, score;

public:
    Player(int startX, int startY) : x(startX), y(startY), score(0) {} // Oyuncu oluşturucu

    int getX() const { return x; } // X koordinatını döndür
    int getY() const { return y; } // Y koordinatını döndür
    int getScore() const { return score; } // Skoru döndür

    void move(char direction, int mazeWidth, int mazeHeight) { // Oyuncuyu hareket ettir
        if (direction == 'w' && x > 0) x--; // Yukarı hareket
        else if (direction == 's' && x < mazeHeight - 1) x++; // Aşağı hareket
        else if (direction == 'a' && y > 0) y--; // Sola hareket
        else if (direction == 'd' && y < mazeWidth - 1) y++; // Sağa hareket
        else cout << "Gecersiz hareket!" << endl; // Geçersiz hareket uyarısı
    }

    void addScore(int points) { score += points; } // Skora puan ekle
};


// Tuzak sınıfı****************
class Trap : public Nesne {
public:
    Trap(int x, int y) : Nesne(x, y) {} // Tuzak oluşturucu

    bool etkilesim(int& score) override { // Tuzakla etkileşim
        cout << "Tuzak! Oyunu kaybettiniz." << endl;
        return false; // Oyun biter
    }
};


// Bonus sınıfı****************
class Bonus : public Nesne {
public:
    Bonus(int x, int y) : Nesne(x, y) {} // Bonus oluşturucu

    bool etkilesim(int& score) override { // Bonusla etkileşim
        score += 10; // Skoru artır
        cout << "Bonus toplandi! Skorunuz: " << score << endl;
        return true; // Oyun devam eder
    }
};


// Labirent sınıfı****************
class Maze {
private:
    int width, height, exitX, exitY;
    Nesne* objects[2]; // Sabit sayıda nesne (Tuzak ve Bonus)

public:
    Maze(int width, int height) : width(width), height(height), exitX(height - 1), exitY(width - 1) {
        objects[0] = new Trap(2, 2);   // Tuzak ekle
        objects[1] = new Bonus(3, 3); // Bonus ekle
    }

    ~Maze() { // Nesneleri temizle
        delete objects[0];
        delete objects[1];
    }

    void display(const Player& player) const { // Labirenti ekrana yazdır
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (player.getX() == i && player.getY() == j)
                    cout << "P "; // Oyuncunun pozisyonu
                else if (i == exitX && j == exitY)
                    cout << "E "; // Çıkış noktası
                else {
                    bool found = false;
                    for (int k = 0; k < 2; k++) {
                        if (objects[k] && objects[k]->getX() == i && objects[k]->getY() == j) {
                            cout << (dynamic_cast<Trap*>(objects[k]) ? "T " : "B "); // Tuzak veya Bonus
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << ". "; // Boş alan
                }
            }
            cout << endl;
        }
    }

    bool checkInteraction(Player& player) { // Oyuncunun nesneyle etkileşimini kontrol et
        for (int k = 0; k < 2; k++) {
            if (objects[k] && objects[k]->getX() == player.getX() && objects[k]->getY() == player.getY()) {
                int score = player.getScore();
                if (!objects[k]->etkilesim(score)) return false; // Oyun biter
                player.addScore(score - player.getScore()); // Skor güncelle
                delete objects[k]; // Nesneyi kaldır
                objects[k] = nullptr;
                break;
            }
        }
        return true;
    }

    bool isExit(int x, int y) const { return x == exitX && y == exitY; }
};


// Ana oyun döngüsü****************
int main() {
    Maze maze(5, 5); // Labirent oluştur
    Player player(0, 0); // Oyuncuyu başlangıç noktasına yerleştir

    while (true) {
        maze.display(player); // Labirenti göster
        cout << "Hareket (w/a/s/d): ";
        char direction;
        cin >> direction;

        player.move(direction, 5, 5); // Oyuncuyu hareket ettir

        if (!maze.checkInteraction(player)) break; // Etkileşim kontrolü

        if (maze.isExit(player.getX(), player.getY())) { // Çıkış kontrolü
            cout << "Cikisa ulastiniz! Tebrikler!" << endl;
            break;
        }
    }

    return 0;
}
