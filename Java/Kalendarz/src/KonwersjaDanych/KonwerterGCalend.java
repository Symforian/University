package KonwersjaDanych;

public class KonwerterGCalend {

    public static String NumbToMonth(int numb) {
        if (numb == 0)
            return "Styczeń";
        if (numb == 1)
            return "Luty";
        if (numb == 2)
            return "Marzec";
        if (numb == 3)
            return "Kwiecień";
        if (numb == 4)
            return "Maj";
        if (numb == 5)
            return "Czerwiec";
        if (numb == 6)
            return "Lipiec";
        if (numb == 7)
            return "Sierpień";
        if (numb == 8)
            return "Wrzesień";
        if (numb == 9)
            return "Październik";
        if (numb == 10)
            return "Listopad";
        if (numb == 11)
            return "Grudzień";
        return "Błąd";
    }
    public static int MonthToNumb(String Month) {
        if (Month.equals("Styczeń"))
            return 0;
        if (Month.equals("Luty"))
            return 1;
        if (Month.equals("Marzec"))
            return 2;
        if (Month.equals("Kwiecień"))
            return 3;
        if (Month.equals("Maj"))
            return 4;
        if (Month.equals("Czerwiec"))
            return 5;
        if (Month.equals("Lipiec"))
            return 6;
        if (Month.equals("Sierpień"))
            return 7;
        if (Month.equals("Wrzesień"))
            return 8;
        if (Month.equals("Październik"))
            return 9;
        if (Month.equals("Listopad"))
            return 10;
        if (Month.equals("Grudzień"))
            return 11;
        return -1;
    }

    public static String NumbToDayOfWeek(int numb) {

        if (numb == 1)
            return "Niedziela";
        if (numb == 2)
            return "Poniedziałek";
        if (numb == 3)
            return "Wtorek";
        if (numb == 4)
            return "Środa";
        if (numb == 5)
            return "Czwartek";
        if (numb == 6)
            return "Piątek";
        if (numb == 7)
            return "Sobota";
        return "Błąd";
    }

}
