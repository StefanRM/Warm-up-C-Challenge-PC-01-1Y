.___________. _______ .___  ___.      ___          __ 
|           ||   ____||   \/   |     /   \        /_ |
`---|  |----`|  |__   |  \  /  |    /  ^  \        | |
    |  |     |   __|  |  |\/|  |   /  /_\  \       | |
    |  |     |  |____ |  |  |  |  /  _____  \      | |
    |__|     |_______||__|  |__| /__/     \__\     |_|


===Task 1===

		Functia SumDiv() are ca parametru un numar natural x. Aceasta
	calculeaza suma tuturor divizorilor lui x in afara de el insusi. In
	functie avem urmatoarele variabile:
		-- s --> variabila in care se face suma divizorilor 
			 initializata cu 1 pentru ca 1 divide orice numar,
			 functia returneaza aceasta variabila;
		-- d --> variabila care retine valorile de la 2 pana la
			 x % 2 (deoarece x nu se ia in calcul) si verifica
			 daca este divizor sau nu al lui x; daca este divizor
			 atunci se aduna sumei;

		In programul principal se citeste valoarea k (numarul mai mare
	decat numerele din perechi). Apoi se incearca toate numerele de la 1 
	pana la k (contorul fiind variabila i). Din enuntul problemei se stie 
	ca SumDiv(a) = b si SumDiv(b) = a (a < b), iar de aici rezulta ca 
	a = SumDiv(SumDiv(a)). Astfel daca SumDiv(SumDiv(i)) = i si 
	i < SumDiv(i) < k, conditie echivalenta cu a < b < k,
	atunci se va afisa perechea (i, SumDiv(i)), adica perechea (a, b), cu
	a < b, ceruta in enuntul problemei.

===Task 2===

		Functia isPalindrome() are ca parametru un numar natural x.
	Aceasta verifica daca x este palindrom prin calcularea oglinditului
	sau (valoare salvata in variabila y), valoarea lui x se pastreaza
	in variabila z. Daca z = y atunci definitia palindromului este
	verificata si functia returneaza 1 (adevarat), iar in caz contrar 
	returneaza 0 (fals).

		Functia power() are ca parametri un numar natural x, si un
	numar natural y. Aceasta returneaza x^y.

		In programul principal se citesc valorile p (numarul de cifre)
	si x (numarul mai mare decat palindroamele obtinute). Numerele din
	perechi se cauta intre min = 10^(p-1) si max = 10^p (trebuie sa aiba
	p cifre). Tinand cont ca 0 este palindrom se va initializa nr (numarul
	de perechi) cu 1 daca min < 10 (echivalent cu p = 1) si cu 0 daca 
	min >= 10 (echivalent cu p > 1). Cautarea palindroamelor incepe de la 1 
	pana la x ( contorul fiind i). Daca i este palindrom atunci incepe o 
	cautare de la min pana la max (contorul fiind j). Daca j divide i 
	atunci se initializeaza o variabila k = i / j. Stiind ca i e palindrom 
	si ca j * k = i, atunci e suficient ca j sa fie diferit de k si 
	min <= k <= max. Daca e indeplinita aceasta conditie atunci se 
	incrementeaza nr cu 1 si se cauta o alta pereche pentru un alt
	palindrom i. In final se afiseaza numarul de perechi nr.

===Task 3===

		Functia coordinateConfig() are ca parametru nr intreg a,
	reprezentand configuratia urmatoarei mutari in baza 10 (a in baza 2 are
	12 cifre). In functie se initializeaza o variabila config = 1 care va
	reprezenta configuratia pozitiei soldatului. Se afla coordonatele
	y si x, din ultimele doua cifre ale numarului scrise in baza 2, ale 
	soldatului si se construieste configuratia pozitiei astfel:
	se shift-eaza la stanga cu 8 variabila config pentru fiecare rand
	(numarul de randuri este 7 - x, deoarece configuratia tine de cont de
	coltul din dreapta jos al tablei), apoi se shift-eaza cu 7 - y la 
	stanga, deoarece configuratia merge de la dreapta la stanga. La urma se
	returneaza configuratia pozitiei formata, adica variabila config.
	De mentionat faptul ca variabila config are, in baza 2 un singur 1, iar
 	in rest 0.
	
		Functia soldierExists() are ca parametri configuratia pozitiei 
	soldatului din variabila mask si configuratia tablei in momentul
	respectiv. Aceasta returneaza 1 (adevarat) daca soldatul exista in
	configuratia tablei prin pozitia obtinuta, in caz contrar returneaza
	0 (fals).

		In programul principal se citeste configuratia tablei in
	variabila mapConfig si numarul de mutari N. Apoi se citesc cele N
	mutari in variabila move si se construiesc configuratiile celor doua 
	pozitii din mutare, move se shifteaza la stanga cu 6 pentru a putea
	obtine configuratia starii finale (config 1 este starea initiala, iar 
	config2 este starea finala). Daca cele doua configuratii config1 si 
	config2 sunt diferite (soldatul nu se muta pe locul pe care se afla
	initial) si exista pe harta din coordonatele obtinute din mutare
	atunci mutarea este valida si se obtine configuratia mutarii in 
	variabila config (config = config1 + config2), care va avea, in baza 2,
	doua valori 1 si restul 0. Apoi se foloseste operatorul XOR (^) pentru a 
	obtine configuratia tablei dupa mutare (daca soldatul se muta pe pozitia 
	altui soldat acestia dispar, iar daca pozitia este neocupata aceasta va 
	fi luata de soldat, pozitiile initiale devenind 0).
	Dupa ce se efectueaza cele N mutari se afiseaza configuratia finala a
	hartii.
