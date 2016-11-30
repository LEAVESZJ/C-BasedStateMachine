#include "Object.h"
#include "ObjectPlus.h"
#include "StackableObject.h"

void main()
{
	Object* obj = new Object();
	obj->Initialize();

	ObjectPlus* objPlus = new ObjectPlus();
	objPlus->Initialize();

	StackableObject* stackableObj = new StackableObject();
	stackableObj->Initialize();

	stackableObj->PushState( StackableObject::STATE::Enter );
	stackableObj->PushState( StackableObject::STATE::Exec );
	stackableObj->PopState();
	stackableObj->ChangeState( StackableObject::STATE::Exit );


	while( true )
	{
		obj->Update();

		objPlus->Update();

		stackableObj->Update();

		if( obj->CurrentState()	    == Object::Exit &&
			objPlus->CurrentState() == ObjectPlus::Exit )
		{
			break;
		}
	}

	delete obj;
	delete objPlus;
	delete stackableObj;
}
