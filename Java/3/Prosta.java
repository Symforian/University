package geometria;

	public class Prosta
	{
		public final double A, B, C;
		public Prosta( double a, double b, double c)
		{
			A = a;
			B = b;
			C = c;
		}
		public static Prosta przesun(Prosta p,Wektor v)
		{
			double newC = p.C;
			newC -= p.A * v.dx;
			newC += v.dy;
			return new Prosta(p.A,p.B,newC);
		}
		public static boolean czyRownolegle(Prosta p, Prosta l)
		{
			if(p.A*l.B==l.A*p.B)
				return true;
			else
				return false;
		}
		public static boolean czyProstopadle(Prosta p, Prosta l)
		{
			if(p.A*l.A==-1*p.B*l.B)
				return true;
			else
				return false;
		}
		public static Punkt punktPrzeciecia(Prosta p, Prosta l)  throws PunktPrzecieciaRownoleglych
		{
			if(czyRownolegle(p,l))
				{
					PunktPrzecieciaRownoleglych e = new PunktPrzecieciaRownoleglych("Brak punktu przeciecia prostych rownoleglych");
					throw e;
				}
			else
				{
					double x,y;

					x = (-p.C*l.B+l.C*p.B)/(p.A*l.B-l.A*p.B);
					y = (-p.A*l.C+l.A*p.C)/(p.A*l.B-l.A*p.B);
					return new Punkt(x,y);

					
				}
				
		}
		public String toString()
		{		
			return "("+A+")x+("+B+")y+("+C+")";
		}
	}



