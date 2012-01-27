#include"Service.h"


bool Contient(int x1, int y1, int x2, int y2, int x3, int y3)
//Algorithme : vérifie que x1 est dans l'inetrvale [x2,x3] et que y1 est dans l'intervalle [y2,y3]
{
	if(((x1()<=x2 && x1>= x3)||(x1()>=x2 && x1<= x3)) && ((y1()<=y2 && y1>= y3)||(y1()>=y2 && y1<= y3)))
	{
		return true;
	}
	return false;
}






