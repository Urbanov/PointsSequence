* Autor:
Dawid Urbanowicz
277352
D.Urbanowicz@stud.elka.pw.edu.pl

* Problem:
AAL-4-LS ³amana       
W uk³adzie wspó³rzêdnych XY znajduje siê n punktów. Ka¿dy punkt ma przypisan¹ wagê bêd¹c¹ liczb¹ naturaln¹. Nale¿y znaleŸæ ci¹g punktów o nastêpuj¹cych w³aœciwoœciach: (1) ka¿dy wektor pomiêdzy kolejnymi punktami z ci¹gu ma nieujemne sk³adowe, (2) ³¹czna suma wag punktów w ci¹gu jest maksymalna. Rozwa¿yæ te¿ przypadek w którym pierwszy warunek jest rozluŸniony w nastêpuj¹cy sposób: (1’) ka¿dy wektor z wyj¹tkiem co najwy¿ej jednego pomiêdzy kolejnymi punktami z ci¹gu ma nieujemne sk³adowe.

* Obs³uga programu:
Program mo¿na uruchomiæ z nastêpuj¹cymi parametrami:
--mode=nr_trybu : wybór trybu dzia³ania
--alg=nr_algorytmu(ów) : wybór algorytmów
--txt : w trybach z domyœln¹ reprezentacj¹ wizualn¹ u¿ywa reprezentacji tekstowej (aby przyk³adowo zapisaæ rozwi¹zanie w pliku)
--size=rozmiar : rozmiar problemu w trybach z generacj¹ problemów
--iter=iloœæ : liczba iteracji (z rosn¹cym rozmiarem problemu)
--inst=iloœæ : liczba instancji problemu o tym samym rozmiarze generowana w czasie jednej iteracji
--step=rozmiar : ró¿nica pomiêdzy wielkoœciami problemu w kolejnych iteracjach
--help : wyœwietlenie pomocy (po angielsku)

* Dostêpne tryby dzia³ania:
- Tryb 1 : Czytaj instancjê problemu ze standardowego wejœcia (lub przeka¿ do niego plik) i rozwi¹¿ j¹ u¿ywaj¹c algorytmów podanych w opcji --alg. Wyniki s¹ reprezentowane na wykresie, lub przy opcji --txt, wyœwietlane w konsoli jako lista punktów.

Format danych wejœciowych:
max_szerokoœæ   max_wysokoœæ
punkt_1_x       punkt_1_y         punkt_1_waga
.               .                 .
.               .                 .
.               .                 .
punkt_n_x       punkt_n_y         punkt_n_waga

Dane powinny byæ wprowadzane jako liczby ca³kowite.

- Tryb 2 : Wygeneruj instancjê problemu o rozmiarze podanym w --size i rozwi¹¿ za pomoc¹ algorytmów podanych w opcji --alg. Podobnie jak w trybie 1, wyniki s¹ reprezentowane na wykresie, lub przy opcji --txt, wyœwietlane w konsoli jako lista punktów.

- Tryb 3 : Tryb s³u¿y do obliczania wartoœci q. Testuje pojedynczy algorytm podany w opcji --alg na losowo wygenerowanym zbiorze problemów sk³adaj¹cym siê z --iter iteracji o rozmiarach zaczynaj¹cych siê od --size rosn¹cych o --step w ka¿dej iteracji. Ka¿da iteracja sk³ada siê z --inst instancji aby zapewniæ wiarygodne wyniki obliczonych wartoœci q.

- Tryb 4 : Tryb pozwala porównaæ ze sob¹ dwa algorytmy podaj¹c stosunek procentowy ich wyników. Testuje algorytmy podane w opcji --alg na losowo wygenerowanym zbiorze problemów sk³adaj¹cym siê z --iter iteracji o rozmiarach zaczynaj¹cych siê od --size rosn¹cych o --step w ka¿dej iteracji. Ka¿da iteracja sk³ada siê z --inst instancji aby zapewniæ wiarygodne wyniki.

* Konwencja prezentacji wyników:
- W trybie graficznym : wyœwietlany jest uk³ad wspó³rzêdnych, w którym narysowana jest ³amana ³¹cz¹ca punkty zgodnie z treœci¹ zadania. W konsoli wyœwietlane s¹ sumy wag poszczególnych rozwi¹zañ. Dodatkowe opcje obs³ugi trybu graficznego wypisane s¹ w konsoli.

- W trybie tekstowym : wyœwietlane s¹ wyniki w nastêpuj¹cym formacie
numer_rozwi¹zania: suma_wag
punkt_1_x       punkt_1_y         punkt_1_waga
.               .                 .
.               .                 .
.               .                 .
punkt_n_x       punkt_n_y         punkt_n_waga

* Zastosowane algorytmy i struktury danych:
Opisane w pe³nej dokumentacji

* Przewodnik po plikach Ÿród³owych:
main.cpp : parsowanie argumentów oraz uruchamianie odpowiednich trybów
literals.h : sta³e u¿ywane w programie

/plot : wykres
	plot.cpp/plot.h : rysowanie wykresu

/solvers : algorytmy
	solver.cpp/solver.h : abstrakcyjna klasa algorytmu
	brute.cpp/brute.h : brute force
	alt_brute.cpp/alt_brute.h : brute force dla drugiego przypadku
	dyn_prog.cpp/dyn_prog.h : algorytm programowania dynamicznego
	alt_dyn_prog.cpp/alt_dyn_prog.h : algorytm programowania dynamicznego dla drugiego przypadku
	seg_tree.cpp/seg_tree.h : algorytm programowania dynamicznego z u¿yciem drzewa przedzia³owego
	alt_seg_tree.cpp/alt_seg_tree.h : algorytm programowania dynamicznego z u¿yciem drzewa przedzia³owego dla drugiego przypadku

/structures : struktury danych
	matrix.h : macierz MxN
	point.cpp/point.h : punkt z wag¹ i wspó³rzêdnymi
	solution.cpp/solution.h : klasa rozwi¹zania, przetrzymuje listê punktów
	tree.h : drzewo przedzia³owe

/utils : dodatkowe klasy u¿ywane w programie
	generator.cpp/generator.h : generator losowych problemów
	test.cpp/test.h : zawiera ró¿ne tryby wykonania programu
	timer.cpp/timer.h : pomiar czasu