package geometria;

	public class Wektor
	{
		public final double dx, dy;
		public Wektor(double x, double y)
		{
			dx=x;
			dy=y;
		}
		public static Wektor zlozDwaWektory(Wektor v, Wektor u)
		{
			return new Wektor(v.dx+u.dx,v.dy+u.dy);
		}
		public String toString()
		{
			return "dx = "+dx+" , dy = "+dy;
		}
	}



