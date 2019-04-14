#include <SDL2/SDL.h>

enum CurrentScreen
{
	Starting_Screen,
	Character_Selection_Screen_Player_1,
	Character_Selection_Screen_Player_2,
	Before_Player_1_Turn,
	Player_1_Turn,
	Before_Player_2_Turn,
	Player_2_Turn,
	Action_Screen,
	Ending_Screen,
	THERE_IS_NO_MOAR_SCREEN
};
void ScreenControl();
void Start();
void Selection(int Player);
void Before(int Player);
void Turn(int Player);
void Action();
void Result(int player);
