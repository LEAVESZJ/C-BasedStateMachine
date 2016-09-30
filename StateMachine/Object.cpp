
#include <stdio.h>
#include "Object.h"

Object::Object() :
	m_pStateMachine( nullptr )
{
}

Object::~Object()
{
	delete m_pStateMachine;
}

void Object::Initialize()
{
	m_pStateMachine = new StateMachine<Object>( this );

	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateEnter( "STATE::Enter" ) ) );
	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateExec( "STATE::Exec" ) ) );
	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateExit( "STATE::Exit" ) ) );

	m_pStateMachine->ChangeState( m_StateVec[ STATE::Enter ] );
	m_pStateMachine->ChangeState( m_StateVec[ STATE::Exec ] );
	m_pStateMachine->ChangeState( m_StateVec[ STATE::Exit ] );
	m_pStateMachine->ChangeState( m_StateVec[ STATE::Enter ] );
}

/************************************************************************/
/* Object State Enter													*/
/************************************************************************/
void Object::ObjectStateEnter::Enter( Object* owner )
{
}

void Object::ObjectStateEnter::Exec( Object* owner )
{
}

void Object::ObjectStateEnter::Exit( Object* owner )
{
}

/************************************************************************/
/* Object State Exec													*/
/************************************************************************/
void Object::ObjectStateExec::Enter( Object* owner )
{
}

void Object::ObjectStateExec::Exec( Object* owner )
{
}

void Object::ObjectStateExec::Exit( Object* owner )
{
}

/************************************************************************/
/* Object State Exit													*/
/************************************************************************/
void Object::ObjectStateExit::Enter( Object* owner )
{
}

void Object::ObjectStateExit::Exec( Object* owner )
{
}

void Object::ObjectStateExit::Exit( Object* owner )
{
}