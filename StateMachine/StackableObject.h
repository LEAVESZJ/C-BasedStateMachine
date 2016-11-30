#pragma once

#include "StateMachine.h"

class StackableObject
{

public:

	enum STATE
	{
		None = -1,
		Enter,
		Exec,
		Exit
	};

	StackableObject();
	virtual ~StackableObject();

	void Initialize();

	STATE PrevState() const
	{
		if( m_pStateMachine->PrevState() == nullptr )
		{
			return STATE::None;
		}

		return m_pStateMachine->PrevState()->Name();
	}

	STATE CurrentState() const
	{
		if( m_pStateMachine->CurrentState() == nullptr )
		{
			return STATE::None;
		}

		return m_pStateMachine->CurrentState()->Name();
	}

	void Update();

	void PushState( STATE state );
	void PopState();
	void ChangeState( STATE state );

private:

	StackableStateMachine<StackableObject, STATE>* m_pStateMachine;

private:

	/************************************************************************/
	/* StackableObject State Enter                                          */
	/************************************************************************/
	class StackableObjectStateEnter final : public State<StackableObject, STATE>
	{
	public:
		StackableObjectStateEnter( STATE name, std::string nameStr = "" ) :
			State( name, nameStr )
		{
		}

		virtual void Enter( StackableObject* owner ) override;
		virtual void Exec( StackableObject* owner ) override;
		virtual void Exit( StackableObject* owner ) override;
	};

	/************************************************************************/
	/* StackableObject State Exec                                           */
	/************************************************************************/
	class StackableObjectStateExec final : public State<StackableObject, STATE>
	{
	public:
		StackableObjectStateExec( STATE name, std::string nameStr = "" ) :
			State( name, nameStr )
		{
		}

		virtual void Enter( StackableObject* owner ) override;
		virtual void Exec( StackableObject* owner ) override;
		virtual void Exit( StackableObject* owner ) override;
	};

	/************************************************************************/
	/* StackableObject State Exit                                           */
	/************************************************************************/
	class StackableObjectStateExit final : public State<StackableObject, STATE>
	{
	public:
		StackableObjectStateExit( STATE name, std::string nameStr = "" ) :
			State( name, nameStr )
		{
		}

		virtual void Enter( StackableObject* owner ) override;
		virtual void Exec( StackableObject* owner ) override;
		virtual void Exit( StackableObject* owner ) override;
	};
};