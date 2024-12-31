Labirent Oyunu (Maze Game):

Bu proje, temel nesne tabanlı programlama (NTP) prensiplerini kullanarak geliştirilmiş bir konsol tabanlı labirent oyunudur.
Oyuncu, labirentte hareket ederek bonusları toplar ve tuzaklardan kaçarak çıkış noktasına ulaşmaya çalışır.


Özellikler:

Oyuncu Hareketi: Oyuncu 'w', 'a', 's', 'd' tuşlarıyla yukarı, sol, aşağı ve sağ yönlerde hareket edebilir.
Etkileşim Mekanizması: Oyuncu bir bonus (B) topladığında skor artar. Tuzak (T) ile karşılaşırsa oyun sona erer.
Çıkış Noktası: Oyuncu çıkışa (E) ulaştığında oyun kazanılır.
Nesne Tabanlı Programlama: Kod, sınıf yapıları ve polimorfizm gibi NTP prensiplerine dayanır.


Kullanılan Yapılar ve Kodlar:

Sınıflar ve Kalıtım: Player, Trap, Bonus, ve Maze sınıfları kullanıldı. Trap ve Bonus, Nesne sınıfından türetilmiştir.
Dinamik Bellek Yönetimi: Labirentteki nesneler dinamik olarak oluşturulmuş ve oyun sırasında yönetilmiştir.
Sanallık (Polimorfizm): Nesne sınıfındaki etkilesim fonksiyonu, türetilmiş sınıflar tarafından ezilmiştir.
Kontrol Mekanizması: Oyuncunun labirentteki hareketi ve nesnelerle etkileşimi, koordinatlar üzerinden kontrol edilmiştir.


Nasıl Çalıştırılır?

Kodunuzu derleyin:
g++ maze_game.cpp -o maze_game

Oyunu çalıştırın:
./maze_game


Oyunu oynayın:

Oyuncuyu hareket ettirmek için 'w', 'a', 's', 'd' tuşlarını kullanın.
Bonusları toplayın, tuzaklardan kaçının ve çıkışa ulaşmaya çalışın.


Proje Yapısı:

Nesne sınıfı: Bonus ve Tuzak gibi nesnelerin temel sınıfıdır.
Player sınıfı: Oyuncunun pozisyonunu ve skorunu yönetir.
Maze sınıfı: Labirentin yapısını, nesneleri ve oyun mekaniklerini kontrol eder.
Trap ve Bonus sınıfları: Labirentteki özel nesneler için davranışları tanımlar.


Ekran Görüntüsü:
P . . . .
. . . . .
. . T . .
. . . B .
. . . . E
Hareket (w/a/s/d): 
