#include "SmSdk/GameState.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

bool GameState::IsCurrentGameState(const EGameStateType gsType)
{
	GameState* pCurrentState = GameState::GetCurrentState();
	if (!pCurrentState)
		return false;

	return pCurrentState->getGameStateType() == gsType;
}

bool GameState::IsCurrentOrNextGameState(const EGameStateType gsType)
{
	GameState* v_pCurState = GameState::GetCurrentState();
	if (v_pCurState)
	{
		const auto v_pCurStateType = v_pCurState->getGameStateType();

		if (v_pCurStateType == gsType)
			return true;

		if (v_pCurStateType == EGameStateType::LoadState)
		{
			LoadState* v_pLoadState = reinterpret_cast<LoadState*>(v_pCurState);
			if (v_pLoadState->m_pNextState && v_pLoadState->m_pNextState->getGameStateType() == gsType)
				return true;
		}
	}

	return false;
}

SteamNetworkClient* GameState::GetSteamNetworkClient()
{
	GameState* v_pCurState = GameState::GetCurrentState();
	if (v_pCurState && v_pCurState->getGameStateType() == EGameStateType::PlayState)
		return reinterpret_cast<PlayState*>(v_pCurState)->m_pSteamNetworkClient.get();

	return nullptr;
}