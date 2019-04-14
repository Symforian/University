package geometria;

	public class Odcinek implements Przeksztalcenia
	{
		private Punkt A, B;
		public Odcinek( double Ax, double Ay, double Bx, double By) throws IllegalArgumentException
		{
			if(Ax!=Bx || Ay!=By)
				{
					A = new Punkt(Ax,Ay);
					B = new Punkt(Bx,By);
				}
			else
				{
					IllegalArgumentException e = new IllegalArgumentException();
					throw e;
				}

		}
		public Odcinek(Punkt A1, Punkt B1) throws IllegalArgumentException
		{
			if(Punkt.czyRozne(A1,B1))
				{
					A = A1;
					B = B1;
				}
			else
				{
					IllegalArgumentException e = new IllegalArgumentException();
					throw e;
				}

		}

		public void przesun( Wektor v)
		{
			A.przesun(v);
			B.przesun(v);
		}
		public void odbij(Prosta p) throws PunktPrzecieciaRownoleglych
		{
			A.odbij(p);
			B.odbij(p);
		}
		public void obroc(Punkt p, double kat)
		{
			A.obroc(p,kat);
			B.obroc(p,kat);
		}
		public String toString()
		{
			return "A=("+A.toString()+") B =("+B.toString()+")";
		}
		
	}


