package narzedzia;
import java.util.logging.Logger;
/**	Kolejka generyczna
*/
public class Kolejka<T>{
	private final static Logger logger = Logger.getLogger(Kolejka.class.getName());
	private Lista<T> list;
	private int rozmiar;

	public Kolejka()
	{
		list = new Lista<T>();
		rozmiar = 0;
	}
	/** Dodawanie elementu do kolejki
	@param element element dodawany do kolejki
	*/
	public void dodaj(T element)
	{
		
		logger.info("Dodawanie "+element.toString()+" do kolejki");
		list.wstawNaPoczątek(element);
		rozmiar++;
	}
	/**
		@return zwraca rozmiar kolejki
	*/
	public int rozmiar()
	{
		return rozmiar;
	}
	/**
		Usuwa element ze kolejki.
		@return element usuwany 
		@throws WyjątekONP gdy kolejka jest pusta
	*/
	public T usuń() throws WyjątekONP
	{
		logger.info("Usuwanie elementu z kolejki");
		if(rozmiar == 0)
			throw new ONP_PustaKolejka("Nie można usunąć.");
		rozmiar--;
		T elem = list.wezOstatni();
		list.usunZKonca();
		return elem;
	}
}
