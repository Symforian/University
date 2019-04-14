czlowiek(anglik).
czlowiek(hiszpan).
czlowiek(ukrainiec).
czlowiek(norweg).
czlowiek(japonczyk).

kolor_d(czerwony).
kolor_d(zielony).
kolor_d(bialy).
kolor_d(zolty).
kolor_d(niebieski).

zwierze(psa).
zwierze(weza).
zwierze(lisa).
zwierze(konia).
zwierze(slonia).

napoj(kawe).
napoj(herbate).
napoj(mleko).
napoj(sok).
napoj(wodke).

papierosy(winstony).
papierosy(koole).
papierosy(chesterfieldy).
papierosy(lucky_stricky).
papierosy(kenty).

poz(skrajnie_lewy).
poz(lewy).
poz(srodkowy).
poz(prawy).
poz(skrajnie_prawy).


%dom(czlowiek(X),kolor_d(Y),poz(Z))
%
skrajnie_lewy:-
	sasiad(lewy).
srodkowy:-
	sasiad(lewy).
lewy:-
	sasiad(skrajnie_lewy).
lewy:-
	sasiad(srodkowy).
srodkowy:-
	sasiad(lewy).
srodkowy:-
	sasiad(prawy).
prawy:-
	sasiad(srodkowy).
prawy:-
	sasiad(skrajnie_prawy).
skrajnie_prawy:-
	sasiad(prawy).

% 2
mieszka(anglik, czerwony).
mieszka(X, niebieski):-
	adres(X,AX),
	adres(norweg,sasiad(AX)),
	mieszka(norweg,adres(sasiad(AX)).
mieszka(X, zielony):-
  adres(X,AX),
  adres(Y,sasiad(AX)),
  mieszka(Y, bialy).

% 3
ma_zwierze(hiszpan, pies).

% 4
pije(X, kawa):-
  mieszka(X, zielony).

% 5
pije(ukrainiec, herbata).
pije(X, mleko):-
  dzialka(X, 3).
% 6 ???


% 7
pali(X, winstony):-
  ma_zwierze(X, waz).

% 8
pali(X, koole):-
  mieszka(X, zolty).

% 9




% 11
pali(X, chesterfieldy):-
  sasiad(X, Y),
  ma_zwierze(Y, lis).

% 12
pali(X, koole):-
  sasiad(X, Y),
  ma_zwierze(Y, kon).

% 13
pali(X, luckystrike):-
  pije(X, sok).

% 14
pali(japonczyk,kenty).

% 15
% 10
dzialka(norweg, 1).



