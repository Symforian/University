package narzedzia;
import java.util.logging.Logger;
/**	Klasa stosu generycznego
*/
public class Stos<T>{
	private final static Logger logger = Logger.getLogger(Stos.class.getName());
	private Lista<T> list;
	private int rozmiar;

	public Stos()
	{
		list = new Lista<T>();
		rozmiar = 0;
	}
	/** Dodawanie elementu do stosu
	@param element element dodawany do stosu
	*/
	public void dodaj(T element)
	{
		logger.info("Dodawanie "+element.toString()+" na stos");
		list.wstawNaPoczątek(element);
		rozmiar++;
	}
	/**
		@return zwraca rozmiar stosu
	*/
	public int rozmiar()
	{
		return rozmiar;
	}
	/**
		Usuwa element ze stosu.
		@return element usuwany 
		@throws WyjątekONP gdy stos jest pusty
	*/
	public T usuń() throws WyjątekONP
	{
		logger.info("Usuwanie elementu ze stosu");
		if(rozmiar == 0)
			throw new ONP_PustyStos("Nie można usunąć.");
		rozmiar--;
		T elem = list.wezPierwszy();
		list.usunZPoczatku();
		return elem;
	}
}
