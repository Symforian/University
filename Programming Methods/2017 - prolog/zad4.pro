sibling(A,B):-
	parent(C,A),
	parent(C,B).

sister(A,B):-
	sibling(A,B),
	female(A).

grandson(A,B):-
	parent(C,A),
	parent(B,C),
	male(A).

cousin(A,B):-
	parent(C,A),
	parent(D,B),
	sibling(C,D).

descendant(A,B):-
	parent(B,A).

descendant(A,B):-
	parent(B,Z),
	descendant(A,Z).
	

is_mother(A):-
	female(A),
	parent(A,B).

is_father(A):-
	male(A);
	parent(A,B).


male(adam).
male(mark).
male(joshua).
male(david).
male(john).
female(eve).
female(helen).
female(ivonne).
female(anna).

parent(adam,helen).
parent(adam,ivonne).
parent(adam,anna).
parent(eve,helen).
parent(eve,ivonne).
parent(eve,anna).
parent(john,joshua).
parent(helen,joshua).
parent(ivonne,david).
parent(mark,david).
