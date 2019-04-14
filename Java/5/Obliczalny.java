package narzedzia;
/** Interfejs obliczalności wyrażeń w ONP
 
 */
public interface Obliczalny
{
/** Oblicza wartość
   @return Wartość
   @throws WyjątekONP wyjątek powstały przy obliczaniu wartości danej funkcji
 */
double obliczWartość () throws WyjątekONP;

}
