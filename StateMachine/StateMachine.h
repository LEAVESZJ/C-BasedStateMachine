#pragma once

#include <string>
#include <vector>

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
/* State Machine                                                        */
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

	inline void ChangeState( State<T, TEnum>* state )
	{
		m_pPrevState = m_pCurrentState;

		if( m_pPrevState != nullptr )
		{
			m_pPrevState->Exit( m_pOwner );
		}

		m_pCurrentState = state;
		m_pCurrentState->Enter( m_pOwner );
	}

	inline void Update()
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

/************************************************************************/
/* State Machine Plus                                                   */
/************************************************************************/
template <class T, typename TEnum, typename std::enable_if<std::is_enum<TEnum>::value>::type* = nullptr >
class StateMachinePlus final
{
public:
	StateMachinePlus( T* owner )
	{
		m_pPrevState = nullptr;
		m_pCurrentState = nullptr;

		m_pOwner = owner;
	}

	virtual ~StateMachinePlus()
	{
		this->ClearState();
	}

	inline TEnum CurrentState() const
	{
		return m_pCurrentState->Name();
	}

	inline void AddState( State<T, TEnum>* state )
	{
		this->m_StateVec.push_back( state );
	}

	inline State<T, TEnum>* GetState( TEnum state ) const
	{
		return this->m_StateVec[ state ];
	}

	inline void ChangeState( TEnum state )
	{
		m_pPrevState = m_pCurrentState;

		if( m_pPrevState != nullptr )
		{
			m_pPrevState->Exit( m_pOwner );
		}

		m_pCurrentState = this->GetState( state );
		m_pCurrentState->Enter( m_pOwner );
	}

	inline void ClearState()
	{
		for( const auto& state : m_StateVec )
		{
			if( state != nullptr )
			{
				delete state;
			}
		}

		m_StateVec.clear();
	}

	inline void Update()
	{
		if( m_pCurrentState != nullptr )
		{
			m_pCurrentState->Exec( m_pOwner );
		}
	}

private:
	std::vector <State<T, TEnum>*> m_StateVec;

	State<T, TEnum>* m_pPrevState;
	State<T, TEnum>* m_pCurrentState;

	T* m_pOwner;

	StateMachinePlus() {};
};