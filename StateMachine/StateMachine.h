#pragma once

#include <string>

/************************************************************************/
/* State                                                                */
/************************************************************************/
template <class T, typename TEnum, typename std::enable_if<std::is_enum<TEnum>::value>::type* = nullptr >
class State
{
public:
	State( TEnum name, std::string nameStr = "" )
	{
		m_Name = name;
		m_NameStr = nameStr;
	}

	virtual ~State() {}

	inline TEnum Name() const
	{
		return m_Name;
	}

	inline std::string NameStr() const
	{
		return m_NameStr;
	}

	virtual void Enter( T* ) = 0;
	virtual void Exec( T* ) = 0;
	virtual void Exit( T* ) = 0;

private:
	State() {}

	TEnum m_Name;
	std::string m_NameStr;
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

	inline TEnum CurrentState() const
	{
		return m_pCurrentState->Name();
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
			m_pCurrentState->Exec( m_pOwner );
		}
	}

private:
	State<T, TEnum>* m_pPrevState;
	State<T, TEnum>* m_pCurrentState;

	T* m_pOwner;

	StateMachine() {};
};