
#include <stdio.h>
#include <iostream>
#include "StackableObject.h"

StackableObject::StackableObject() :
	m_pStateMachine( nullptr )
{
}

StackableObject::~StackableObject()
{
	delete m_pStateMachine;
}

void StackableObject::Initialize()
{
	m_pStateMachine = new StackableStateMachine<StackableObject, STATE>( this );

	m_pStateMachine->AddState( new StackableObjectStateEnter( STATE::Enter, "StackableObject::STATE::Enter" ) );
	m_pStateMachine->AddState( new StackableObjectStateExec(  STATE::Exec,  "StackableObject::STATE::Exec"  ) );
	m_pStateMachine->AddState( new StackableObjectStateExit(  STATE::Exit,  "StackableObject::STATE::Exit"  ) );
}

void StackableObject::Update()
{
	if( m_pStateMachine != nullptr )
	{
		m_pStateMachine->Update();
	}
}

void StackableObject::PushState( STATE state )
{
	m_pStateMachine->PushState( state );
}

void StackableObject::PopState()
{
	m_pStateMachine->PopState();
}

void StackableObject::ChangeState( STATE state )
{
	m_pStateMachine->ChangeState( state );
}


/************************************************************************/
/* StackableObject State Enter                                          */
/************************************************************************/
void StackableObject::StackableObjectStateEnter::Enter( StackableObject* owner )
{
}

void StackableObject::StackableObjectStateEnter::Exec( StackableObject* owner )
{

}

void StackableObject::StackableObjectStateEnter::Exit( StackableObject* owner )
{

}


/************************************************************************/
/* StackableObject State Exec                                           */
/************************************************************************/
void StackableObject::StackableObjectStateExec::Enter( StackableObject* owner )
{
}

void StackableObject::StackableObjectStateExec::Exec( StackableObject* owner )
{

}

void StackableObject::StackableObjectStateExec::Exit( StackableObject* owner )
{

}


/************************************************************************/
/* StackableObject State Exit                                           */
/************************************************************************/
void StackableObject::StackableObjectStateExit::Enter( StackableObject* owner )
{

}

void StackableObject::StackableObjectStateExit::Exec( StackableObject* owner )
{

}

void StackableObject::StackableObjectStateExit::Exit( StackableObject* owner )
{

}
