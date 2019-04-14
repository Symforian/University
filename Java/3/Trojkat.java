package geometria;

	public class Trojkat implements Przeksztalcenia
	{
		private Punkt a, b ,c;
		public Trojkat( double Ax, double Ay, double Bx, double By, double Cx, double Cy) throws IllegalArgumentException, PunktPrzecieciaRownoleglych
		{
			this(new Punkt(Ax,Ay),new Punkt(Bx,By),new Punkt(Cx,Cy));

		}
		public Trojkat( Punkt A, Punkt B, Punkt C) throws IllegalArgumentException, PunktPrzecieciaRownoleglych
		{
			
			if((A.odleglosc(B)+A.odleglosc(C)>C.odleglosc(B)) 
			&& (A.odleglosc(C)+C.odleglosc(B)>B.odleglosc(A))
			 && (B.odleglosc(C)+A.odleglosc(B)>A.odleglosc(C)))
				{
					a = A;
					b = B;
					c = C;
				}
			else
				{
					IllegalArgumentException e = new IllegalArgumentException();
					throw e;
				}

		}
		public void przesun( Wektor v)
		{
			a.przesun(v);
			b.przesun(v);
			c.przesun(v);
									
		}
		public void odbij(Prosta p) throws PunktPrzecieciaRownoleglych
		{
			a.odbij(p);
			b.odbij(p);
			c.odbij(p);
		}
		public void obroc(Punkt p, double kat)
		{
			a.obroc(p,kat);
			b.obroc(p,kat);
			c.obroc(p,kat);
		}
		public String toString()
		{
			return "a =("+a.toString()+") b =("+b.toString()+") c =("+c.toString()+")";
		}
	}



