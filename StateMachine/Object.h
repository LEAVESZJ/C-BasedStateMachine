#pragma once

#include "StateMachine.h"
#include <vector>
#include <iostream>

/************************************************************************/
/* Object                                                               */
/************************************************************************/
class Object
{

public:

	enum STATE 
	{
		Enter = 0,
		Exec,
		Exit
	};

	Object();
	virtual ~Object();

	void Initialize();

private:

	void ChangeState( STATE state );

	StateMachine<Object, STATE>* m_pStateMachine;

	typedef typename State<Object, STATE> StateObject;
	std::vector<StateObject*> m_StateVec;

private:

	/************************************************************************/
	/* Object State Enter                                                   */
	/************************************************************************/
	class ObjectStateEnter final : public State<Object, STATE>
	{
		public:
			ObjectStateEnter( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};

	/************************************************************************/
	/* Object State Exec                                                    */
	/************************************************************************/
	class ObjectStateExec final : public State<Object, STATE>
	{
		public:
			ObjectStateExec( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};

	/************************************************************************/
	/* Object State Exit                                                    */
	/************************************************************************/
	class ObjectStateExit final : public State<Object, STATE>
	{
		public:
			ObjectStateExit( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};
};

