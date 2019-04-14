
package narzedzia;
class ONP_DzieleniePrzez0 extends WyjątekONP {/*...*/

    public ONP_DzieleniePrzez0(String message) {
        super("Dzielenie przez 0. "+ message);
    }
   public ONP_DzieleniePrzez0()
	{
		super("Dzielenie przez 0.");
	}
}
