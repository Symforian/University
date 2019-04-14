mily(X):-
	czlowiek(X),
	odwiedza_zoo(X).
szczesliwe(Z):-
	zwierze(Z),
	styka(Z,X),
	mily(X).
styka(Z,X):-
	zwierze(Z),
	czlowiek(X),
	mieszka_zoo(Z),
	odwiedza_zoo(X).
styka(Z,X):-
	zwierze(X),
	czlowiek(Z),
	mieszka_zoo(X),
	odwiedza_zoo(Z).
niesmok(X):-
	mieszka_zoo(X),
	szczesliwe(X).

zwierze(S):-
	smok(S).

odwiedza_zoo(przykladowyCzlowiek).
czlowiek(przykladowyCzlowiek).
smok(random_smok).
%to mamy^^^^^ 
%tego szukamy\/\/\/\/
%szczesliwe(S):-
%	zwierze(S),??
%	styka(S,X):-
%		zwierze(S),??
%		czlowiek(X),??
%		mieszka_zoo(S).-to ma byc falsz
%		odwiedza_zoo(X).
%	mily(X):-
%		czlowiek(X).??
%		odwiedza_zoo(X).??
%brakuje 
% człowieka, który odwiedza zoo, czyli

% wiadomosci ze smok jest zwierzęciem 

	

	
