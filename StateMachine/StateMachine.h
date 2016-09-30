#pragma once

#include <string>

template <class T>
class State
{
public:
	State( std::string name )
	{
		m_Name = name;
	}

	virtual ~State() {}

	inline std::string Name() const
	{
		return m_Name;
	}

	virtual void Enter( T* ) = 0;
	virtual void Exec( T* ) = 0;
	virtual void Exit( T* ) = 0;

private:
	State() {}

	std::string m_Name;
};

template <class T>
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

	inline std::string CurrentStateName() const
	{
		if( m_pCurrentState != nullptr )
		{
			return m_pCurrentState->Name();
		}

		return "";
	}

	void ChangeState( State<T>* state )
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
	State<T>* m_pPrevState;
	State<T>* m_pCurrentState;

	T* m_pOwner;

	StateMachine() {};
};