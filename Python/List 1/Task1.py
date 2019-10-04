import math
def vat_faktura(lista):
	suma = 0
	for e in lista:
		suma+=e
	return suma*23/100

def vat_paragon(lista):
	suma = 0
	for e in lista:
		suma+=e*23/100
	return suma

zakupy = [0.2, 0.5, 4.59, 6]
print(vat_faktura(zakupy))
print(vat_paragon(zakupy))
print(vat_faktura(zakupy) == vat_paragon(zakupy))


def change(amount):
	coins = [20, 10, 5, 2, 1]
	returnList = [0,0,0,0,0]
	pointer = 0
	while amount >0:
		noCoins = amount // coins[pointer]
		if noCoins > 0:
			amount -= coins[pointer] * noCoins
		returnList[pointer] = (str(coins[pointer])+" zl ",noCoins)
		pointer+=1
	return returnList
 


print(change(123))

def isPrime(n):
	if n == 2: return True
	for i in range (2, math.floor(math.sqrt(n))):
		if n%i == 0:
			return False
	return True

def rozklad(n):
	returnValue = []
	i = 2
	while n > 1:
		if isPrime(i):
			liczba =  0 
			while n%i == 0:
				if n % i == 0:
					liczba+=1
					n /= i
			if liczba>0:	returnValue.append((i,liczba))
		i +=1
		print( i)
	return returnValue
	

print(rozklad(756))

