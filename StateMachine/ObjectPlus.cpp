
#include <stdio.h>
#include "ObjectPlus.h"

/************************************************************************/
/* ObjectPlus                                                           */
/************************************************************************/
ObjectPlus::ObjectPlus() :
	m_pStateMachine( nullptr )
{
}

ObjectPlus::~ObjectPlus()
{
	delete m_pStateMachine;
}

void ObjectPlus::Initialize()
{
	m_pStateMachine = new StateMachinePlus<ObjectPlus, STATE>( this );

	m_pStateMachine->AddState( new ObjectPlusStateEnter( STATE::Enter, "ObjectPlus::STATE::Enter" ) );
	m_pStateMachine->AddState( new ObjectPlusStateExec(  STATE::Exec,  "ObjectPlus::STATE::Exec"  ) );
	m_pStateMachine->AddState( new ObjectPlusStateExit(  STATE::Exit,  "ObjectPlus::STATE::Exit"  ) );

	this->ChangeState( STATE::Enter );
}

void ObjectPlus::Update()
{
	if( m_pStateMachine != nullptr )
	{
		m_pStateMachine->Update();
	}
}

void ObjectPlus::ChangeState( STATE state )
{
	if( this->m_pStateMachine == nullptr ) return;

	/* For Debug **/
	std::cout << "[Current State] " + m_pStateMachine->GetState( state )->NameStr() << std::endl;

	m_pStateMachine->ChangeState( state );
}

/************************************************************************/
/* ObjectPlus State Enter                                               */
/************************************************************************/
void ObjectPlus::ObjectPlusStateEnter::Enter( ObjectPlus* owner )
{
	owner->ChangeState( STATE::Exec );
}

void ObjectPlus::ObjectPlusStateEnter::Exec( ObjectPlus* owner )
{
}

void ObjectPlus::ObjectPlusStateEnter::Exit( ObjectPlus* owner )
{
}

/************************************************************************/
/* ObjectPlus State Exec                                                */
/************************************************************************/
void ObjectPlus::ObjectPlusStateExec::Enter( ObjectPlus* owner )
{
}

void ObjectPlus::ObjectPlusStateExec::Exec( ObjectPlus* owner )
{
	owner->ChangeState( STATE::Exit );
}

void ObjectPlus::ObjectPlusStateExec::Exit( ObjectPlus* owner )
{
}

/************************************************************************/
/* ObjectPlus State Exit                                                */
/************************************************************************/
void ObjectPlus::ObjectPlusStateExit::Enter( ObjectPlus* owner )
{
}

void ObjectPlus::ObjectPlusStateExit::Exec( ObjectPlus* owner )
{
}

void ObjectPlus::ObjectPlusStateExit::Exit( ObjectPlus* owner )
{
}