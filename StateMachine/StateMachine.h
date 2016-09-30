#pragma once
#include <string>

template <class T>
class State
{
public:
	State( std::string name )
	{
		m_name = name;
	}

	virtual ~State() {}

	inline std::string Name() const
	{
		return m_name;
	}

	virtual void Enter( T* ) = 0;
	virtual void Exec( T* ) = 0;
	virtual void Exit( T* ) = 0;

private:
	State() {}

	std::string m_name;
};

template <class T>
class StateMachine final
{
public:
	StateMachine( T* owner )
	{
		m_prevState = nullptr;
		m_currentState = nullptr;

		m_owner = owner;
	}

	virtual ~StateMachine() {}

	inline std::string CurrentStateName() const
	{
		if( m_currentState != nullptr )
		{
			return m_currentState->Name();
		}

		return "";
	}

	void ChangeState( State<T>* state )
	{
		m_prevState = m_currentState;

		if( m_prevState != nullptr )
		{
			m_prevState->Exit( m_owner );
		}

		m_currentState = state;
		m_currentState->Enter( m_owner );
	}

	void Update()
	{
		if( m_currentState != nullptr )
		{
			m_currentState->Update();
		}
	}

private:
	State<T>* m_prevState;
	State<T>* m_currentState;

	T* m_owner;

	StateMachine() {};
};