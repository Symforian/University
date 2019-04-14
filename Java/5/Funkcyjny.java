package narzedzia;
/**	interfejs funkcji
*/
public interface Funkcyjny extends Obliczalny
{

int arność ();
int brakująceArgumenty ();
void dodajArgument (double a) throws WyjątekONP;

}
