package narzedzia;
import java.util.logging.Logger;
/**	Lista generyczna
*/
public class Lista<T>{
	private final static Logger logger = Logger.getLogger(Lista.class.getName());
	private class Węzeł<T> {
	private T Zawartość;
	 Węzeł<T> Następny;
	 Węzeł<T> Poprzedni;
	 
		public Węzeł() 
		{
			Następny = null;
			Poprzedni = null;
		}
	 
		public Węzeł(T e, Węzeł<T> nast, Węzeł<T> popr) 
		{
			this.Zawartość = e;
			this.Następny = nast;
			this.Poprzedni = popr;
		}
	 
		public T pobierzElement() 
		{
			return Zawartość;
		}
	 
		public Węzeł<T> pobierzNastępny() 
		{
			return Następny;
		}
	 
		public void ustawNastępny(Węzeł<T> nast) 
		{
			this.Następny = nast;
		}
	 
		public Węzeł<T> pobierzPoprzedni() 
		{
			return Poprzedni;
		}
	 
		public void ustawPoprzedni(Węzeł<T> popr) 
		{
			this.Poprzedni = popr;
		}
	}
	private Węzeł<T> Pierwszy;
	private Węzeł<T> Ostatni;
	private int rozmiar;
	public Lista()
	{
		Pierwszy = null;
		Ostatni = null;
		rozmiar = 0;
	}
	/** Wstawia element na koniec listy
		@param elem element wstawiany do listy
	*/
	public void wstawNaKoniec(T elem) 
	{
		logger.info("Wstawianie "+elem.toString()+" na koniec listy");
		Węzeł<T> wez = new Węzeł<T>(elem, null, null);
		if (isEmpty()) 
		{
			Pierwszy = wez;
			Ostatni = wez;
		}
		else 
		{
			Ostatni.ustawNastępny(wez);
			wez.ustawPoprzedni(Ostatni);
			Ostatni = wez;
			
		}

 		rozmiar++;
	}
	/** Wstawia element na początek listy
		@param elem element wstawiany do listy
	*/
	public void wstawNaPoczątek(T elem) 
	{
		logger.info("Wstawianie "+elem.toString()+" na początek listy");
		Węzeł<T> wez = new Węzeł<T>(elem, null, null);
		if (isEmpty()) 
		{
			Pierwszy = wez;
			Ostatni = wez;
		}
		else 
		{
			Pierwszy.ustawPoprzedni(wez);
			wez.ustawNastępny(Pierwszy);
			Pierwszy = wez;
			
		}
 		rozmiar++;
	}
	/** Usuwa element z końca listy
		@throws WyjątekONP gdy lista jest pusta
	*/
	public void usunZKonca() throws WyjątekONP
	{
		logger.info("Usuwanie elementu  z końca listy");
		if(isEmpty())
		{
			throw new ONP_PustaLista("Nie można usunąć elementu.");	
		}
		else if(Pierwszy == Ostatni)
		{
			Pierwszy = null;
			Ostatni = null;
		}
		else
		{
			Węzeł<T> pom = Ostatni.pobierzPoprzedni();
			Ostatni.ustawPoprzedni(null);
			pom.ustawNastępny(null);
			Ostatni = pom;
		}
		rozmiar--;
	}
	/** Usuwa element z początku listy
		@throws WyjątekONP gdy lista jest pusta
	*/
	public void usunZPoczatku() throws WyjątekONP
	{
		logger.info("Usuwanie elementu z początku listy");
		if(isEmpty())
		{
			throw new ONP_PustaLista("Nie można usunąć elementu.");	
		}
		else if(Pierwszy == Ostatni)
		{
			Pierwszy = null;
			Ostatni = null;
		}
		else
		{
			Węzeł<T> pom = Pierwszy.pobierzNastępny();
			Pierwszy.ustawNastępny(null);
			pom.ustawPoprzedni(null);
			Pierwszy = pom;
		}
		rozmiar--;
	}
	/** Sprawdza czy lista jest pusta
		@return True gdy jest pusta False w przeciwnym przypadku
	*/
	public boolean isEmpty() 
	{
		return (rozmiar == 0);
	}
	/** 
		@return Rozmiar listy
	*/
	public int rozmiar()
	{
		return rozmiar;
	}
	/** Pobiera element z początku listy
		@return Pierwszy element z listy
		@throws WyjątekONP gdy lista jest pusta
	*/
	public T wezPierwszy() throws WyjątekONP
	{
		if(Pierwszy == null)
	    		throw new ONP_PustaLista("Nie można pobrać elementu.");
		return Pierwszy.Zawartość;
	}
	/** Pobiera element z końca listy
		@return Ostatni element z listy
		@throws WyjątekONP gdy lista jest pusta
	*/
	public T wezOstatni() throws WyjątekONP
	{
		if(Ostatni == null)
	    		throw new ONP_PustaLista("Nie można pobrać elementu.");
		return Ostatni.Zawartość;
	}
	/** Pobiera element z listy
		@param elem element szukany
		@return Ostatni element z listy
		@throws WyjątekONP gdy lista jest pusta lub nie ma takiego elementu
	*/
	public T znajdź(T elem) throws WyjątekONP
  {
	if(Pierwszy == null)
		throw new ONP_BrakZmiennej();
	if(Pierwszy.pobierzNastępny() == null)
	{
		if(elem.equals(Pierwszy.Zawartość))
			return Pierwszy.Zawartość;
		else
			throw new ONP_BrakZmiennej();
	}
	Węzeł<T> pom = Pierwszy;
	while(pom != null)
	{
		if(elem.equals(pom.Zawartość))
			return pom.Zawartość;
		pom = pom.pobierzNastępny();
	}
	throw new ONP_BrakZmiennej();
  }
	/** Usuwa element z listy
		@param elem element usuwany
		@throws WyjątekONP gdy lista jest pusta lub nie ma takiego elementu
	*/
public void usun(T elem) throws WyjątekONP
  	{
		logger.info("Usuwanie "+elem.toString()+" z listy");
		if(Pierwszy == null)
			throw new ONP_BrakZmiennej();
   		 if(Pierwszy.pobierzNastępny() == null)
   		{
    		  if(elem.equals(Pierwszy.Zawartość))
	   		{
	       		usunZPoczatku();
			return;
	     		}
      		else
        	throw new ONP_BrakZmiennej();
    		}
    Węzeł<T> pom = Pierwszy;
    while(Pierwszy != null)
    {
      Węzeł<T> p = Pierwszy.pobierzPoprzedni();
      Węzeł<T> n = Pierwszy.pobierzNastępny();
      if(elem.equals(Pierwszy.Zawartość))
      {
		if(p == null)
		{
			  if(n == null)
			  {
			    Pierwszy = null;
			    return;
			  }
			  else
			  {
			    n.ustawPoprzedni(null);
			    Pierwszy = n;
			    return;
			  }
		}
		if(n == null)
		{
		  p.ustawNastępny(null);
		  Pierwszy = pom;
		  return;
		}
		else
		{
		  n.ustawNastępny(p);
		  p.ustawPoprzedni(n);
		  Pierwszy = null;
		  Pierwszy = pom;
		  return;
		}
      }
      Pierwszy = Pierwszy.pobierzNastępny();
    }
    throw new ONP_BrakZmiennej();
  }
}
