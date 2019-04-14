
connectionB(wroclaw,warszawa).
connectionB(wroclaw,krakow).
connectionB(wroclaw,szczecin).
connectionB(szczecin,lublin).
connectionB(szczecin,gniezno).
connectionB(warszawa,katowice).
connectionB(gniezno,gliwice).
connectionB(lublin,gliwice).

connection(A,B):-
	connectionB(A,B).
connection(A,B):-
	connectionB(A,C), connection(C,B).

