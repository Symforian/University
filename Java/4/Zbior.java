package Wyrazenia;
/**
 * Zbiór par.
 */
public class Zbior {

	private Para[] tablica;
	private int pojemność;
	public Zbior()
	{
		tablica = new Para[16];
		pojemność = 16;
	}
	public Zbior(int wielkosc)
	{
		tablica = new Para[wielkosc];
		pojemność = wielkosc;
	}
	/** metoda zapobiegająca braku miejsca w tablicy
	*/
	public void sprawdzPojemnosc()
	{
		if(ile() == pojemność)
			{
				pojemność *= 2;
				Para[] tymczasowa = new Para[pojemność];
				for(int i = 0; i<pojemność/2; i++)
					tymczasowa[i] = tablica[i];
				tablica = tymczasowa;  
			}
	}
	/** metoda szuka pary z określonym kluczem 
	 * @param kl	Klucz pary szukanej.
	 * @return Para szukana.
	 */
	public Para szukaj (String kl) throws IllegalArgumentException {
		for(int i=0; i<tablica.length; i++)
			{
				if(kl == tablica[i].klucz)
					return tablica[i];
			}
		throw new IllegalArgumentException("Brak pary w zbiorze\n");
	}
	/** metoda wstawia do zbioru nową parę
	 * @param p	Para do wstawienia.
	 */
	public void wstaw (Para p) throws IllegalArgumentException {
			boolean wstawiono = false;
			for(int i=0; i<tablica.length; i++)
			{
				if(tablica[i]==null)
					{
						tablica[i] = p;
						wstawiono = true;
						break;
					}
			}
			if(!wstawiono)
				throw new IllegalArgumentException("Brak miejsca na parę w zbiorze\n");
	 }
	/** metoda odszukuje parę i zwraca wartość związaną z kluczem 
	* @param kl	Para do odszukania.
	* @return Wartość związana z kluczem.
	*/
	public double czytaj (String kl) throws IllegalArgumentException {
			for(int i=0; i<tablica.length; i++)
			{
				if(kl == tablica[i].klucz)
					return tablica[i].getWartość();
			}
		throw new IllegalArgumentException();
	}

	/** metoda wstawia do zbioru nową albo aktualizuje istniejącą parę 
	 * @param p 	Para wstawiana lub wartość dla istniejącej pary do zaktualizowania.
	*/
	public void ustal (Para p) throws IllegalArgumentException {
			boolean done = false;
			for(int i=0; i<tablica.length; i++)
			{
				if(p.klucz == tablica[i].klucz)
					{
					tablica[i].setWartość(p.getWartość());
					done = true;
					break;
					}
			}
			if(!done)
				wstaw(p);
	/* ... */ }
	/** metoda podaje ile par jest przechowywanych w zbiorze 
	* @return Zwraca ilość przechowywanych par w zbiorze.
	*/
	public int ile () {
			int licznik = 0;
			for(int i=0; i<tablica.length; i++)
			{
				if(tablica[i]!=null)
					{
						licznik++;
					}
			}
			return licznik;
	/* ... */ }

	/** metoda usuwa wszystkie pary ze zbioru */
	public void czysc () {
				for(int i=0; i<tablica.length; i++)
			{
				tablica[i]=null;
			}
		}

	
}
