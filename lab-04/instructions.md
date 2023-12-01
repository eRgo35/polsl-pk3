Zad. 1 Stwórz tablicę ‘dane’ typu int i wypełnij ją liczbami: 55, 21, 66, 11, 13, 11, 55, 24, 48, 66.
a) Następnie stwórz puste kontenery:
- vector
- set
- multiset
- unordered_set
- unordered_multiset
- map
- multimap
- unordered_map
- unordered_multimap
b) Wypełnij je wykorzystując tablicę ‘dane’. W przypadku kontenerów map jako klucze wykorzystaj
wartości z tablicy dane, natomiast jako wartości indeksy odpowiadające kolejnym wartościom z tablicy
dane.

Zad. 2 Stwórz pusty kontener map: countries, następnie:
a) Wypełnij go 3 parami klucz-wartość, gdzie kluczami będą nazwy państw, a wartościami ich stolice.
b) Wypełnij kontener map 3 parami państwo-stolica używając metody insert.
c) Dodaj kolejne 3 pary stosując tym razem operator [] i wyświetl zawartość kontenera.
d) Zmień nazwę stolicy jednego z państw oraz usuń jedno z pozostałych 5 par, następnie wyświetl
zawartość kontenera.
e) Używając konstruktora zakresowego (range constructor) stwórz nowy kontener: new_countries,
który będzie zawierał pary od początku kontenera countries do tego, dla którego zmieniono stolicę
w pkt. d. Wyświetl zawartość nowego kontenera.

Zad. 3 Stwórz dynamicznie zaalokowaną tablicę liczb typu int ‘losowe_liczby’ o rozmiarze n=1000000 i
wypełnij ją losowymi liczbami z przedziału [1,1000].
a) Stwórz pusty kontener vector, a następnie napisz funkcje, które wypełnią go liczbami z tablicy
‘losowe liczby’ stosując najpierw metodę push_back, a następnie korzystając z konstruktora
zakresowego. Dla obu przypadków zmierz czas wykonywania tych metod (** możesz wykorzystać
szablon funkcji ‘mierz_czas’ podany poniżej).
b) Stwórz pusty kontener multiset i wypełnij go liczbami z tablicy ‘losowe liczby’ używając insert, a
następnie konstruktora zakresowego. Zmierz czas wykonywania oby metod.
c) Napisz szablon funkcji liczący maksimum kontenera i za jej pomocą wyznacz maksima w obu
kontenerach vector i multiset. Wyznacz także czasy wykonywania tych funkcji.