#pragma once

#include <string>

/************************************************************************/
/* State                                                                */
/************************************************************************/
template <class T, typename TEnum, typename std::enable_if<std::is_enum<TEnum>::value>::type* = nullptr >
class State
{
public:
	State( TEnum name )
	{
		m_Name = name;
	}

	virtual ~State() {}

	inline TEnum Name() const
	{
		return m_Name;
	}

	virtual void Enter( T* ) = 0;
	virtual void Exec( T* ) = 0;
	virtual void Exit( T* ) = 0;

private:
	State() {}

	TEnum m_Name;
};

/************************************************************************/
/* StateMachine                                                         */
/************************************************************************/
template <class T, typename TEnum, typename std::enable_if<std::is_enum<TEnum>::value>::type* = nullptr >
class StateMachine final
{
public:
	StateMachine( T* owner )
	{
		m_pPrevState = nullptr;
		m_pCurrentState = nullptr;

		m_pOwner = owner;
	}

	virtual ~StateMachine() {}

	inline TEnum CurrentStateName() const
	{
		if( m_pCurrentState != nullptr )
		{
			return m_pCurrentState->Name();
		}

		return "";
	}

	void ChangeState( State<T, TEnum>* state )
	{
		m_pPrevState = m_pCurrentState;

		if( m_pPrevState != nullptr )
		{
			m_pPrevState->Exit( m_pOwner );
		}

		m_pCurrentState = state;
		m_pCurrentState->Enter( m_pOwner );
	}

	void Update()
	{
		if( m_pCurrentState != nullptr )
		{
			m_pCurrentState->Update();
		}
	}

private:
	State<T, TEnum>* m_pPrevState;
	State<T, TEnum>* m_pCurrentState;

	T* m_pOwner;

	StateMachine() {};
};