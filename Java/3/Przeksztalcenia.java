package geometria;

	public interface Przeksztalcenia
	{
		public void przesun( Wektor v);
		public void odbij(Prosta p) throws PunktPrzecieciaRownoleglych;
		public void obroc(Punkt p, double kat);
		
	}

