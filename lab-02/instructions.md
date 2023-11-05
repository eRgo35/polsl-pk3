Zad 1. (1 pkt)
a) Zdefiniuj listę (std::list) typu int i wypełnij ją 20 cyframi z zakresu 0-9 oraz drugą listę typu
double i wypełnij ją liczbami z zakresu 1.5-5.0. Korzystając z algorytmów STL policz ilość
wystąpień cyfry 7 w pierwszej liście.
b) Napisz szablon funkcji, która wyświetla podany jej argument. Następnie wyświetl obie listy
(typu int i double) korzystając z algorytmu ‘for_each’ oraz napisanej wcześniej funkcji
wyświetlającej zawartość.

Zad 2. (1.5 pkt)
a) Zdefiniuj wektor typu int i wypełnij go 10 dowolnymi liczbami.
b) Zdefiniuj obiekt funkcyjny, który będzie zwracał wartość przeciwną do podanej. Następnie
korzystając z tego obiektu i algorytmu ‘transform’ zamień każdy element wektora na wartość
przeciwną.
c) Zrób to samo co w pkt. b jednak tym razem korzystając z wyrażenia lambda.

Zad 3. (1.5 pkt)
a) Zdefiniuj dwa wektory v1 i v2 typu int i wypełnij je 6 dowolnymi liczbami, zdefiniuj trzeci pusty
wektor v3 typu int.
b) Korzystając z transform, back_inserter i wyrażenia lambda oblicz iloczyn kolejnych elementów
wektorów v1 i v2, wyniki wstawiaj do wektora v3.
c) Zdefiniuj sparametryzowany obiekt funkcyjny przyjmujący argument ‘t’, zainicjalizuj go
dowolną wartością. Zdefiniuj wektor v4 i wstaw do niego sumę wektorów kolejnych
elementów wektorów v1 i v2 powiększoną dodatkowo o wartość ‘t’.