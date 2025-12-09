Miłosz Sobczak
203969 
WEIA ARISS sem. 3 
Projekt "Arkanoid"

OPIS:

Kod gry jest zaprojektowany w taki sposób, aby każdy element gry był zarządzany przez osobną klasę, co zapewnia łatwość modyfikacji i rozbudowy. Klasa Platforma odpowiada za ruch i rysowanie platformy, którą steruje gracz. Gracz porusza platformą za pomocą klawiszy strzałek, a jej ruch jest ograniczony do obszaru okna gry, co zapobiega wyjściu poza ekran.
Klasa Pilka1 reprezentuje piłkę, która porusza się po planszy, odbijając się od ścian, platformy i cegieł. Piłka jest rysowana jako okrąg, a jej pozycja i prędkość są aktualizowane w każdej klatce gry. Piłka zmienia kierunek odbicia w zależności od obiektu, z którym się zderzy. Jeśli piłka spadnie poniżej ekranu, zostaje zresetowana do początkowej pozycji.
Klasa Cegla odpowiada za cegły, które gracz ma zniszczyć. Każda cegła ma przypisaną liczbę punktów życia (HP), co wpływa na jej kolor – od zielonego (pełne HP) do czerwonego (minimalna ilość życia). Po trafieniu przez piłkę, cegła traci życie i zmienia kolor. Gdy cegła straci wszystkie punkty życia, znika z planszy.
W klasie Game znajdują się wszystkie mechanizmy zarządzające grą. Przechowuje ona instancje platformy, piłki oraz cegieł, a także logikę aktualizowania stanu gry. Sprawdza, czy piłka zderzyła się z platformą lub cegłami, oraz rozstrzyga, czy gra została wygrana, czy przegrana. Gra kończy się przegraną, gdy piłka spadnie poniżej platformy, lub wygraną, gdy wszystkie cegły zostaną zniszczone. Klasa ta obsługuje także zapis i wczytywanie stanu gry, co pozwala na kontynuowanie rozgrywki po jej przerwaniu.
W pliku main.cpp odbywa się główna pętla gry, gdzie obsługiwane są zdarzenia takie jak naciśnięcie klawiszy. Gra działa w trzech stanach: menu, gra i pauza. Menu pozwala na rozpoczęcie nowej gry, wczytanie zapisanej gry lub wyjście z gry. W trakcie gry można wcisnąć pauzę, zapisać stan gry lub wznowić grę.
