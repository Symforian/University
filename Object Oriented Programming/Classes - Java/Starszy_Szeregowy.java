

public class Starszy_Szeregowy extends Stopnie_wojskowe{
	public Starszy_Szeregowy(String Tozsamosc)
		{
			this.Imie_nazwisko = Tozsamosc;
			this.stopien = "Starszy szeregowy";
		}
	public int Wartosc_stopnia()
		{
			return 2;
		}

}
