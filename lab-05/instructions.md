Zad. 1 Stwórz klasę ErrorLog (stosując wzorzec projektowy singleton, który zapewnia możliwość
utworzenia tylko jednej instancji tej klasy). Klasa powinna pozwalać na zapis do pliku „log.txt”. Plik
powinien być otwierany w konstruktorze i zamykany w destruktorze. Następnie przeciąż operator<<
(wykorzystując szablon), aby zapisać zadane dane do pliku oraz przetestuj jego działanie.

Zad. 2 Stwórz szablon klasy, który będzie przechowywał tablicę dynamiczną dowolnego typu (o
pojemności typu long long int). W konstruktorze jednoargumentowym zadeklaruj tablicę dynamiczną o
zadanej pojemności (uwaga: Należy sprawdzić, czy możliwa jest alokacja pamięci, w przeciwnym razie
wyrzucić wyjątek: do tego celu można można użyć stałej std::nothrow i sprawdzić, czy operator new
zwrócił nullptr. Jeśli tak: wyrzucić wyjątek). Konstruktory i destruktor powinny wyświetlać komunikat o ich
uruchomieniu. Klasa powinna posiadać ponadto metody insert i get, które pozwalają odpowiednio na
wstawienie i zwrócenie elementu na daną pozycję. W przypadku obu tych metod w przypadku wyjścia
poza zakres powinny być zwrócone wyjątki