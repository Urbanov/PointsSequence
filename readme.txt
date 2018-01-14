* Autor:
Dawid Urbanowicz
277352
D.Urbanowicz@stud.elka.pw.edu.pl

* Problem:
AAL-4-LS �amana       
W uk�adzie wsp�rz�dnych XY znajduje si� n punkt�w. Ka�dy punkt ma przypisan� wag� b�d�c� liczb� naturaln�. Nale�y znale�� ci�g punkt�w o nast�puj�cych w�a�ciwo�ciach: (1) ka�dy wektor pomi�dzy kolejnymi punktami z ci�gu ma nieujemne sk�adowe, (2) ��czna suma wag punkt�w w ci�gu jest maksymalna. Rozwa�y� te� przypadek w kt�rym pierwszy warunek jest rozlu�niony w nast�puj�cy spos�b: (1�) ka�dy wektor z wyj�tkiem co najwy�ej jednego pomi�dzy kolejnymi punktami z ci�gu ma nieujemne sk�adowe.

* Obs�uga programu:
Program mo�na uruchomi� z nast�puj�cymi parametrami:
--mode=nr_trybu : wyb�r trybu dzia�ania
--alg=nr_algorytmu(�w) : wyb�r algorytm�w
--txt : w trybach z domy�ln� reprezentacj� wizualn� u�ywa reprezentacji tekstowej (aby przyk�adowo zapisa� rozwi�zanie w pliku)
--size=rozmiar : rozmiar problemu w trybach z generacj� problem�w
--iter=ilo�� : liczba iteracji (z rosn�cym rozmiarem problemu)
--inst=ilo�� : liczba instancji problemu o tym samym rozmiarze generowana w czasie jednej iteracji
--step=rozmiar : r�nica pomi�dzy wielko�ciami problemu w kolejnych iteracjach
--help : wy�wietlenie pomocy (po angielsku)

* Dost�pne tryby dzia�ania:
- Tryb 1 : Czytaj instancj� problemu ze standardowego wej�cia (lub przeka� do niego plik) i rozwi�� j� u�ywaj�c algorytm�w podanych w opcji --alg. Wyniki s� reprezentowane na wykresie, lub przy opcji --txt, wy�wietlane w konsoli jako lista punkt�w.

Format danych wej�ciowych:
max_szeroko��   max_wysoko��
punkt_1_x       punkt_1_y         punkt_1_waga
.               .                 .
.               .                 .
.               .                 .
punkt_n_x       punkt_n_y         punkt_n_waga

Dane powinny by� wprowadzane jako liczby ca�kowite.

- Tryb 2 : Wygeneruj instancj� problemu o rozmiarze podanym w --size i rozwi�� za pomoc� algorytm�w podanych w opcji --alg. Podobnie jak w trybie 1, wyniki s� reprezentowane na wykresie, lub przy opcji --txt, wy�wietlane w konsoli jako lista punkt�w.

- Tryb 3 : Tryb s�u�y do obliczania warto�ci q. Testuje pojedynczy algorytm podany w opcji --alg na losowo wygenerowanym zbiorze problem�w sk�adaj�cym si� z --iter iteracji o rozmiarach zaczynaj�cych si� od --size rosn�cych o --step w ka�dej iteracji. Ka�da iteracja sk�ada si� z --inst instancji aby zapewni� wiarygodne wyniki obliczonych warto�ci q.

- Tryb 4 : Tryb pozwala por�wna� ze sob� dwa algorytmy podaj�c stosunek procentowy ich wynik�w. Testuje algorytmy podane w opcji --alg na losowo wygenerowanym zbiorze problem�w sk�adaj�cym si� z --iter iteracji o rozmiarach zaczynaj�cych si� od --size rosn�cych o --step w ka�dej iteracji. Ka�da iteracja sk�ada si� z --inst instancji aby zapewni� wiarygodne wyniki.

* Konwencja prezentacji wynik�w:
- W trybie graficznym : wy�wietlany jest uk�ad wsp�rz�dnych, w kt�rym narysowana jest �amana ��cz�ca punkty zgodnie z tre�ci� zadania. W konsoli wy�wietlane s� sumy wag poszczeg�lnych rozwi�za�. Dodatkowe opcje obs�ugi trybu graficznego wypisane s� w konsoli.

- W trybie tekstowym : wy�wietlane s� wyniki w nast�puj�cym formacie
numer_rozwi�zania: suma_wag
punkt_1_x       punkt_1_y         punkt_1_waga
.               .                 .
.               .                 .
.               .                 .
punkt_n_x       punkt_n_y         punkt_n_waga

* Zastosowane algorytmy i struktury danych:
Opisane w pe�nej dokumentacji

* Przewodnik po plikach �r�d�owych:
main.cpp : parsowanie argument�w oraz uruchamianie odpowiednich tryb�w
literals.h : sta�e u�ywane w programie

/plot : wykres
	plot.cpp/plot.h : rysowanie wykresu

/solvers : algorytmy
	solver.cpp/solver.h : abstrakcyjna klasa algorytmu
	brute.cpp/brute.h : brute force
	alt_brute.cpp/alt_brute.h : brute force dla drugiego przypadku
	dyn_prog.cpp/dyn_prog.h : algorytm programowania dynamicznego
	alt_dyn_prog.cpp/alt_dyn_prog.h : algorytm programowania dynamicznego dla drugiego przypadku
	seg_tree.cpp/seg_tree.h : algorytm programowania dynamicznego z u�yciem drzewa przedzia�owego
	alt_seg_tree.cpp/alt_seg_tree.h : algorytm programowania dynamicznego z u�yciem drzewa przedzia�owego dla drugiego przypadku

/structures : struktury danych
	matrix.h : macierz MxN
	point.cpp/point.h : punkt z wag� i wsp�rz�dnymi
	solution.cpp/solution.h : klasa rozwi�zania, przetrzymuje list� punkt�w
	tree.h : drzewo przedzia�owe

/utils : dodatkowe klasy u�ywane w programie
	generator.cpp/generator.h : generator losowych problem�w
	test.cpp/test.h : zawiera r�ne tryby wykonania programu
	timer.cpp/timer.h : pomiar czasu