#include "../SDK/SDK.h"

MAKE_SIGNATURE(CAchievementMgr_CheckAchievementsEnabled, "client.dll", "40 53 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B D9 48 8B 48 ? 48 85 C9 0F 84", 0x0);

MAKE_HOOK(CAchievementMgr_CheckAchievementsEnabled, S::CAchievementMgr_CheckAchievementsEnabled(), bool,
	void* rcx)
{
	DEBUG_RETURN(CAchievementMgr_CheckAchievementsEnabled, rcx);
#ifdef TEXTMODE
	return false;
#else
	return !I::EngineClient->IsPlayingDemo();
#endif
}
//In theory, this prevents you from unlocking achievements in TF2. But it does this for text mode, so the message that achievements have been unlocked on Steam doesn't appear.
