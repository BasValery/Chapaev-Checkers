#include "Computer.h"



float ComputerPlayer::GetKnock(int & ComputerCheker, int & HumanCheker)
{

	 ComputerCheker = rand() % ComputerCheker;
	 HumanCheker = rand() % HumanCheker;
	return rand()%16 + 145;
}
