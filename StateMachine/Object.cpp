
#include <stdio.h>
#include "Object.h"

/************************************************************************/
/* Object                                                               */
/************************************************************************/
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
	m_pStateMachine = new StateMachine<Object, STATE>( this );

	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateEnter( STATE::Enter, "STATE::Enter" ) ) );
	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateExec(  STATE::Exec,  "STATE::Exec"  ) ) );
	m_StateVec.push_back( dynamic_cast<StateObject*>( new ObjectStateExit(  STATE::Exit,  "STATE::Exit"  ) ) );

	this->ChangeState( STATE::Enter );
}

void Object::Update()
{
	if( m_pStateMachine != nullptr )
	{
		m_pStateMachine->Update();
	}
}

void Object::ChangeState( STATE state )
{
	if( this->m_pStateMachine == nullptr ) return;

	m_pStateMachine->ChangeState( m_StateVec[ state ] );

	/* For Debug **/
	std::cout << "[Current State] " + m_StateVec[ state ]->NameStr() << std::endl;
}

/************************************************************************/
/* Object State Enter                                                   */
/************************************************************************/
void Object::ObjectStateEnter::Enter( Object* owner )
{
	owner->ChangeState( STATE::Exec );
}

void Object::ObjectStateEnter::Exec( Object* owner )
{
}

void Object::ObjectStateEnter::Exit( Object* owner )
{
}

/************************************************************************/
/* Object State Exec                                                    */
/************************************************************************/
void Object::ObjectStateExec::Enter( Object* owner )
{
}

void Object::ObjectStateExec::Exec( Object* owner )
{
	owner->ChangeState( STATE::Exit );
}

void Object::ObjectStateExec::Exit( Object* owner )
{
}

/************************************************************************/
/* Object State Exit                                                    */
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