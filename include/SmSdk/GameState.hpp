#pragma once

#include "SmSdk/Network/SteamNetworkServer.hpp"
#include "SmSdk/Network/SteamNetworkClient.hpp"
#include "SmSdk/Network/NetworkServer.hpp"
#include "SmSdk/Network/ListenServer.hpp"
#include "SmSdk/Base/InputTarget.hpp"

#include "SmSdk/unreferenced_params.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

enum EGameStateType : uint32_t
{
	GameState_Null = 0,
	GameState_LoadState = 1,
	GameState_PlayState = 2,
	GameState_MenuState = 3,
	GameState_TileEditorState = 4,
	GameState_WorldBuilderState = 5
};

struct GameState : public InputTarget
{
public:
	virtual ~GameState() = default;
private:
	virtual void func8() { /* implemented by the game */ }
	virtual void func9() { /* implemented by the game */ }
public:
	virtual void update(float delta_time) { SMSDK_UNREF(delta_time); /* implemented by the game */ }
private:
	virtual void func11() { /* implemented by the game */ }
	virtual void func12() { /* implemented by the game */ }
	virtual void func13() { /* implemented by the game */ }
	virtual void func14() { /* implemented by the game */ }
	virtual void func15() { /* implemented by the game */ }
	virtual void func16() { /* implemented by the game */ }
	virtual void func17() { /* implemented by the game */ }
	virtual void func18() { /* implemented by the game */ }
	virtual void func19() { /* implemented by the game */ }
	virtual void func20() { /* implemented by the game */ }
	virtual void func21() { /* implemented by the game */ }
	virtual void func22() { /* implemented by the game */ }
	virtual void func23() { /* implemented by the game */ }
	virtual void func24() { /* implemented by the game */ }
	virtual void func25() { /* implemented by the game */ }
public:
	virtual EGameStateType getGameStateType() { /* implemented by the game */ }
	virtual EGameStateType getNextGameStateType() { /* implemented by the game */ }
private:
	virtual void func28() { /* implemented by the game */ }
public:
	static GameState* GetCurrentState();
	static bool IsCurrentGameState(EGameStateType gsType);
	static bool IsCurrentOrNextGameState(EGameStateType gsType);
	static SteamNetworkClient* GetSteamNetworkClient();
private:
	/* 0x0008 */ char pad_0x8[0x110];
}; // Size: 0x118

static_assert(sizeof(GameState) == 0x118, "GameState: Incorrect Size");

struct SimpleTimer
{
private:
	virtual void func1() { /* implemented by the game */ }
	virtual void func2() { /* implemented by the game */ }
	virtual void func3() { /* implemented by the game */ }
	virtual void func4() { /* implemented by the game */ }

	/* 0x0008 */ char pad_0x8[0xC];
public:
	/* 0x0014 */ float m_fElapsedTime;
}; // Size: 0x18
static_assert(sizeof(SimpleTimer) == 0x18, "SimpleTimer: Incorrect Size");

struct PlayState : public GameState
{
private:
	/* 0x0118 */ char pad_0x118[0x8];
public:
	/* 0x0120 */ std::shared_ptr<ListenServer> m_pListenServer;
	/* 0x0130 */ std::shared_ptr<SteamNetworkClient> m_pSteamNetworkClient;
private:
	/* 0x0140 */ char pad_0x140[0x8];
public:
	/* 0x0148 */ std::shared_ptr<class GameInstance> m_pGameInstance;
	/* 0x0158 */ SimpleTimer m_someTimer;
public:
	/* 0x0170 */ std::int32_t m_iConnectionTimeoutIdx;
private:
	/* 0x0174 */ char pad_0x174[0x1C];
}; // Size: 0x190
static_assert(sizeof(PlayState) == 0x190, "PlayState: Incorrect Size");

struct LoadState : public GameState
{
private:
	/* 0x0118 */ char pad_0x118[0x8];
public:
	/* 0x0120 */ std::shared_ptr<GameState> m_pNextState;
	/* 0x0130 */ std::shared_ptr<GameState> m_pPrevState;
	/* 0x0140 */ struct LoadingScreen* m_pLoadingScreen;
private:
	/* 0x0148 */ char pad_0x148[0x10];
}; // Size: 0x158

static_assert(offsetof(LoadState, LoadState::m_pNextState) == 0x120, "LoadState::m_pNextState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pPrevState) == 0x130, "LoadState::m_pPrevState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pLoadingScreen) == 0x140, "LoadState::m_pLoadingScreen: Incorrect offset");

static_assert(sizeof(LoadState) == 0x158, "LoadState: Incorrect Size");

SMSDK_END_NAMESPACE