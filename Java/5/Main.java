package narzedzia;
import java.lang.*;
import java.util.regex.*;
import java.util.Scanner;
import java.util.logging.*;
import java.io.IOException;

class Main
{
	private final static Logger logger = Logger.getLogger(Main.class.getName());
 private static FileHandler fh = null;
 public static void init(){
 try {
 fh=new FileHandler("calc.log", false);
 } catch (SecurityException | IOException e) {
 e.printStackTrace();
 }
 Logger l = Logger.getLogger("");
 fh.setFormatter(new SimpleFormatter());
 l.addHandler(fh);
 l.setLevel(Level.CONFIG);
 }
  public static void main(String[] args) throws WyjątekONP
  {
 	Main.init();

    Lista<Zmienna> zmienne = new Lista<Zmienna>();
    Scanner sc = new Scanner(System.in);
	logger.info("Kalkulator rozpoczyna pracę");
    while(true)
    {
      String st = "";
      String s = sc.nextLine();
      s = s.replace(" =", "=");
      String[] str = s.trim().split("\\s+");
	logger.info("Sprawdzanie komendy");
      assert(str[0].equals("calc") || str[0].equals("clear") || str[0].equals("exit")):"Nieznana komenda";
	logger.log(Level.INFO, "Komenda: "+str[0]);
      if(str[0].equals("exit"))
        {
	
	break;
	}
      else if(str[0].equals("clear"))
      {
        if(str.length > 1)
        {
          for(int i = 1; i < str.length; i++)
          {
            try
            {
            Zmienna z = new Zmienna(str[i]);
            zmienne.usun(z);
            }
            catch(WyjątekONP e)
            {
              System.out.println(e.getClass().getCanonicalName() + ": " +  e.getMessage());
		logger.log(Level.INFO, e.getClass().getCanonicalName() + ": " +  e.getMessage());
            }
          }
        }
        else
        {
          for(int i = 0; i < zmienne.rozmiar(); i++)
            zmienne.usunZPoczatku();
        }
      }
      else if(str[0].equals("calc"))
      {
      try
      {
      for(int i = 0; i < str.length; i++)
      {
        if(str[i].matches("\\p{Alpha}\\p{Alnum}*="))
        {
          String[] k = str[i].split("=");
          Zmienna z = new Zmienna(k[0]);
          Wyrażenie w = new Wyrażenie(st, zmienne);
          z.ustalWartość(w.oblicz());
          zmienne.wstawNaPoczątek(z);
        }
        else
          st += str[i] + " ";
      }
      Wyrażenie o = new Wyrażenie(st, zmienne);
      System.out.println(o.oblicz());

      }
      catch(WyjątekONP e)
      {
	logger.log(Level.WARNING, e.getClass().getCanonicalName() + ": " +  e.getMessage());
        System.out.println(e.getClass().getCanonicalName() + ": " +  e.getMessage());
      }
    }

  }
	logger.info("Kalkulator kończy pracę");
}
}
