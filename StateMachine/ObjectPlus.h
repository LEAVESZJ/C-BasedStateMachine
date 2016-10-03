#pragma once

#include "StateMachine.h"
#include <vector>
#include <iostream>

/************************************************************************/
/* ObjectPlus                                                           */
/************************************************************************/
class ObjectPlus
{

public:

	enum STATE 
	{
		Enter = 0,
		Exec,
		Exit
	};

	ObjectPlus();
	virtual ~ObjectPlus();

	void Initialize();

	STATE CurrentState() const
	{
		return m_pStateMachine->CurrentState();
	}

	void Update();

private:

	void ChangeState( STATE state );

	StateMachinePlus<ObjectPlus, STATE>* m_pStateMachine;

private:

	/************************************************************************/
	/* ObjectPlus State Enter                                               */
	/************************************************************************/
	class ObjectPlusStateEnter final : public State<ObjectPlus, STATE>
	{
		public:
			ObjectPlusStateEnter( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( ObjectPlus* owner ) override;
			virtual void Exec( ObjectPlus* owner ) override;
			virtual void Exit( ObjectPlus* owner ) override;
	};

	/************************************************************************/
	/* ObjectPlus State Exec                                                */
	/************************************************************************/
	class ObjectPlusStateExec final : public State<ObjectPlus, STATE>
	{
		public:
			ObjectPlusStateExec( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( ObjectPlus* owner ) override;
			virtual void Exec( ObjectPlus* owner ) override;
			virtual void Exit( ObjectPlus* owner ) override;
	};

	/************************************************************************/
	/* ObjectPlus State Exit                                                */
	/************************************************************************/
	class ObjectPlusStateExit final : public State<ObjectPlus, STATE>
	{
		public:
			ObjectPlusStateExit( STATE name, std::string nameStr = "" ) :
				State( name, nameStr )
			{
			}

			virtual void Enter( ObjectPlus* owner ) override;
			virtual void Exec( ObjectPlus* owner ) override;
			virtual void Exit( ObjectPlus* owner ) override;
	};
};

