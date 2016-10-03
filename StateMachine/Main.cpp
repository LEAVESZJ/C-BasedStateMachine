#include "Object.h"
#include "ObjectPlus.h"

void main()
{
	Object* obj = new Object();
	obj->Initialize();

	ObjectPlus* objPlus = new ObjectPlus();
	objPlus->Initialize();

	while( true )
	{
		obj->Update();

		objPlus->Update();

		if( obj->CurrentState() == Object::Exit &&
			objPlus->CurrentState() == Object::Exit )
		{
			break;
		}
	}

	delete obj;
	delete objPlus;
}
