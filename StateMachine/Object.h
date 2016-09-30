#pragma once

#include "StateMachine.h"
#include <vector>
#include <iostream>

/************************************************************************/
/* Object                                                               */
/************************************************************************/
class Object
{
	typedef typename State<Object> StateObject;

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

	StateMachine<Object>*	  m_pStateMachine;
	std::vector<StateObject*> m_StateVec;

private:

	/************************************************************************/
	/* Object State Enter                                                   */
	/************************************************************************/
	class ObjectStateEnter final : public State<Object>
	{
		public:
			ObjectStateEnter( std::string name ) :
				State( name )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};

	/************************************************************************/
	/* Object State Exec                                                    */
	/************************************************************************/
	class ObjectStateExec final : public State<Object>
	{
		public:
			ObjectStateExec( std::string name ) :
				State( name )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};

	/************************************************************************/
	/* Object State Exit                                                    */
	/************************************************************************/
	class ObjectStateExit final : public State<Object>
	{
		public:
			ObjectStateExit( std::string name ) :
				State( name )
			{
			}

			virtual void Enter( Object* owner ) override;
			virtual void Exec( Object* owner ) override;
			virtual void Exit( Object* owner ) override;
	};
};

