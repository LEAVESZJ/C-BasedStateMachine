#include "Object.h"

void main()
{
	Object* obj = new Object();
	obj->Initialize();

	while( true )
	{
		obj->Update();

		if( obj->CurrentState() == Object::Exit )
		{
			break;
		}
	}
}
