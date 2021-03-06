#pragma once
#include "NPC.h"
#include "PollTimer.h"
#include "struct.hpp"
#include "std/map"


class CNpcHomun : public CNPC
{
public:
	struct vtable_t
	{
		//TODO
	};

	/* this+0x0   */ //CNPC
	/* this+0x46C */ private: CPollTimer m_timerF;
	/* this+0x474 */ private: CPollTimer m_timerHunger;
	/* this+0x47C */ private: CPollTimer m_timerState;
	/* this+0x484 */ private: int m_homunID;
	/* this+0x488 */ private: int m_modified;
	/* this+0x48C */ private: int m_fullGrade;
	/* this+0x490 */ private: int m_fullness;
	/* this+0x494 */ private: float m_relation;
	/* this+0x498 */ private: int m_SKPoint;
	/* this+0x49C */ private: mystd::map<unsigned short,HO_SKINFO> m_skill;
	/* this+0x4A8 */ private: EXTInfo m_EXTInfo;

	//public: void CNpcHomun::CNpcHomun(void);
	//public: void CNpcHomun::~CNpcHomun(void);
	public: int CNpcHomun::GetParameterValue(unsigned short id, int& value);
	public: int CNpcHomun::UpdateParameterValue(unsigned short id, int value);
	public: int CNpcHomun::OnMsg(CCharacter* sender, CCharacter* receiver, unsigned long msgID, int par1, int par2, int par3, MSGpar::CVar par4);
	public: void CNpcHomun::OnProcess(void);
	public: int CNpcHomun::IsTarget(CCharacter* ch, unsigned long flag);
	public: void CNpcHomun::OnTimerHomun(void);
	public: void CNpcHomun::OnReqRename(char* name);
	public: void CNpcHomun::SetCharInfo(HOMUN_DBINFO* info);
	public: void CNpcHomun::InitProperty(void);
	public: void CNpcHomun::InitTimer(DWORD dwTick);
	public: void CNpcHomun::InitConditionTime(void);
	public: void CNpcHomun::IsLevelUp(void);
	public: void CNpcHomun::UpdateHomunDBInfo(HOMUN_DBINFO* info);
	public: void CNpcHomun::SetModifiedState(int state);
	public: void CNpcHomun::ResetModifiedState(int state);
	public: int CNpcHomun::EvolutionHomun(void);
	public: int CNpcHomun::IsEvolutionType(void);
	public: void CNpcHomun::StartUseSkill(void);
	public: int CNpcHomun::IsSkillUsable(unsigned short SKID);
	public: int CNpcHomun::IsSkillEnable(unsigned short SKID, int level, CCharacter* ch);
	public: short CNpcHomun::GetSKLevel(unsigned short SKID);
	public: void CNpcHomun::UpgradeSKLevel(unsigned short SKID);
	public: CPC* CNpcHomun::GetOwner(void);
	public: int CNpcHomun::GetSP(void);
	public: int CNpcHomun::GetMaxHP(void);
	public: int CNpcHomun::GetMaxSP(void);
	public: short CNpcHomun::GetStrValue(void);
	public: short CNpcHomun::GetDexValue(void);
	public: short CNpcHomun::GetVitValue(void);
	public: short CNpcHomun::GetIntValue(void);
	public: short CNpcHomun::GetAgiValue(void);
	public: int CNpcHomun::GetLukValue(void);
	public: int CNpcHomun::GetFullness(void);
	public: int CNpcHomun::GetRelation(void);
	public: void CNpcHomun::ProcessEffect_ATK(CCharacter* other, int& damage, int isMeleeATK, int isSKATK);
	public: int CNpcHomun::GetInvincibleTimeInfo(int skillID);
	public: short CNpcHomun::GetJobType(void);
	public: void CNpcHomun::NotifyStatusAmount(unsigned short type, int amount);
	public: bool CNpcHomun::ApplyStatusAmount(unsigned short type, int& amount);
	private: void CNpcHomun::InitCore(void);
	private: int CNpcHomun::IsRechargeTime(void);
	private: int CNpcHomun::GetAttackPoint(CCharacter* other, unsigned short SKID, int property);
	private: int CNpcHomun::GetMagicAttPower(void);
	private: short CNpcHomun::GetStatusDef(void);
	private: short CNpcHomun::GetStatusMagicDef(void);
	private: short CNpcHomun::GetAvoidPercent_Client(void);
	private: void CNpcHomun::CheckState(unsigned long dwTick);
	private: void CNpcHomun::SaveCharInfo(int GID);
	private: void CNpcHomun::DeleteCharInfo(int GID);
	private: int CNpcHomun::ParseSkill(unsigned char* buf, int len);
	private: int CNpcHomun::SaveSkill(void);
	private: int CNpcHomun::LoadSkill(void);
	private: int CNpcHomun::AddSkill(unsigned short SKID, HO_SKINFO* SKInfo, int SKData);
	private: HO_SKINFO* CNpcHomun::GetSkill(unsigned short SKID);
	private: void CNpcHomun::NotifyAllSKInfo(void);
	private: int CNpcHomun::IsSatisfySkill(unsigned short SKID, short job);
	private: void CNpcHomun::NotifySKInfo(unsigned short SKID, int isForce);
	private: void CNpcHomun::ChkAllEnableSkill(void);
	private: void CNpcHomun::ApplyPassiveSkill(unsigned short SKID, short level);
	private: void CNpcHomun::AddFinalSkill(void);
	private: void CNpcHomun::OnChangedHP(void);
	private: void CNpcHomun::OnChangedSP(void);
	private: void CNpcHomun::OnFeed(CPC* owner);
	private: void CNpcHomun::OnAddExp(CCharacter* sender, int exp, int par1);
	private: void CNpcHomun::OnShareExp(CCharacter* sender, int exp, int par1);
	private: void CNpcHomun::ModifyFullness(int val);
	private: void CNpcHomun::ModifyRelationship(float val);
	private: void CNpcHomun::SendStateHomun(char state, int data);
	private: void CNpcHomun::SendProperty(void);
	private: void CNpcHomun::SetInvincibleTimeInfo(unsigned long time, int skillID);
	private: void CNpcHomun::SetBodyStateTimeInfo(unsigned long firstTime, unsigned long secondTime, int state);
	private: void CNpcHomun::SetHealthStateTimeInfo(int firstTime, int secondTime, int state);
	private: short CNpcHomun::GetATKPoint_Client(void);
	private: short CNpcHomun::GetCRI_Client(void);
	private: short CNpcHomun::GetDEF_Client(void);
	private: short CNpcHomun::GetATKTime_Client(void);
	private: short CNpcHomun::GetRelationGrade(short val);
	private: int CNpcHomun::GetFullnessGrade(int fullness);
	private: int CNpcHomun::GetRecoverSPD_HP(void);
	private: int CNpcHomun::GetRecoverSPD_SP(void);
	//private: int CNpcHomun::GetEmotion_Feed(int, int);
	private: void CNpcHomun::UpdateStatusATKpower(void);
	private: void CNpcHomun::UpgradeStatus_LevelUp(void);
	private: void CNpcHomun::OPSkillToSelf(int SKID, int AID, int SKData);
	private: void CNpcHomun::ATKSkillToChar(int SKID, int AID, int SKData);
	private: int CNpcHomun::SK_LIF_Heal(CPC* owner, const MSG_TYPE4_FIVEDWORD& in_msg);
	private: int CNpcHomun::SK_LIF_Avoid(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_LIF_Change(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_AMI_Castle(CPC* owner);
	private: int CNpcHomun::SK_AMI_Defence(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_AMI_BloodLust(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_FLI_Fleet(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_FLI_Speed(MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_VAN_Chaotic(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);
	private: int CNpcHomun::SK_VAN_Explosion(CPC* owner, MSG_TYPE4_FIVEDWORD* msg);

private:
	static hook_method<int (CNpcHomun::*)(unsigned short id, int& value)> CNpcHomun::_GetParameterValue;
	static hook_method<int (CNpcHomun::*)(unsigned short id, int value)> CNpcHomun::_UpdateParameterValue;
	static hook_method<int (CNpcHomun::*)(CCharacter* sender, CCharacter* receiver, unsigned long msgID, int par1, int par2, int par3, MSGpar::CVar par4)> CNpcHomun::_OnMsg;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_OnProcess;
	static hook_method<int (CNpcHomun::*)(CCharacter* ch, unsigned long flag)> CNpcHomun::_IsTarget;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_OnTimerHomun;
	static hook_method<void (CNpcHomun::*)(char* name)> CNpcHomun::_OnReqRename;
	static hook_method<void (CNpcHomun::*)(HOMUN_DBINFO* info)> CNpcHomun::_SetCharInfo;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_InitProperty;
	static hook_method<void (CNpcHomun::*)(DWORD dwTick)> CNpcHomun::_InitTimer;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_InitConditionTime;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_IsLevelUp;
	static hook_method<void (CNpcHomun::*)(HOMUN_DBINFO* info)> CNpcHomun::_UpdateHomunDBInfo;
	static hook_method<void (CNpcHomun::*)(int state)> CNpcHomun::_SetModifiedState;
	static hook_method<void (CNpcHomun::*)(int state)> CNpcHomun::_ResetModifiedState;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_EvolutionHomun;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_IsEvolutionType;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_StartUseSkill;
	static hook_method<int (CNpcHomun::*)(unsigned short SKID)> CNpcHomun::_IsSkillUsable;
	static hook_method<int (CNpcHomun::*)(unsigned short SKID, int level, CCharacter* ch)> CNpcHomun::_IsSkillEnable;
	static hook_method<short (CNpcHomun::*)(unsigned short SKID)> CNpcHomun::_GetSKLevel;
	static hook_method<void (CNpcHomun::*)(unsigned short SKID)> CNpcHomun::_UpgradeSKLevel;
	static hook_method<CPC* (CNpcHomun::*)(void)> CNpcHomun::_GetOwner;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetSP;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetMaxHP;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetMaxSP;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetStrValue;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetDexValue;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetVitValue;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetIntValue;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetAgiValue;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetLukValue;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetFullness;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetRelation;
	static hook_method<void (CNpcHomun::*)(CCharacter* other, int& damage, int isMeleeATK, int isSKATK)> CNpcHomun::_ProcessEffect_ATK;
	static hook_method<int (CNpcHomun::*)(int skillID)> CNpcHomun::_GetInvincibleTimeInfo;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetJobType;
	static hook_method<void (CNpcHomun::*)(unsigned short type, int amount)> CNpcHomun::_NotifyStatusAmount;
	static hook_method<bool (CNpcHomun::*)(unsigned short type, int& amount)> CNpcHomun::_ApplyStatusAmount;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_InitCore;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_IsRechargeTime;
	static hook_method<int (CNpcHomun::*)(CCharacter* other, unsigned short SKID, int property)> CNpcHomun::_GetAttackPoint;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetMagicAttPower;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetStatusDef;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetStatusMagicDef;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetAvoidPercent_Client;
	static hook_method<void (CNpcHomun::*)(unsigned long dwTick)> CNpcHomun::_CheckState;
	static hook_method<void (CNpcHomun::*)(int GID)> CNpcHomun::_SaveCharInfo;
	static hook_method<void (CNpcHomun::*)(int GID)> CNpcHomun::_DeleteCharInfo;
	static hook_method<int (CNpcHomun::*)(unsigned char* buf, int len)> CNpcHomun::_ParseSkill;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_SaveSkill;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_LoadSkill;
	static hook_method<int (CNpcHomun::*)(unsigned short SKID, HO_SKINFO* SKInfo, int SKData)> CNpcHomun::_AddSkill;
	static hook_method<HO_SKINFO* (CNpcHomun::*)(unsigned short SKID)> CNpcHomun::_GetSkill;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_NotifyAllSKInfo;
	static hook_method<int (CNpcHomun::*)(unsigned short SKID, short job)> CNpcHomun::_IsSatisfySkill;
	static hook_method<void (CNpcHomun::*)(unsigned short SKID, int isForce)> CNpcHomun::_NotifySKInfo;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_ChkAllEnableSkill;
	static hook_method<void (CNpcHomun::*)(unsigned short SKID, short level)> CNpcHomun::_ApplyPassiveSkill;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_AddFinalSkill;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_OnChangedHP;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_OnChangedSP;
	static hook_method<void (CNpcHomun::*)(CPC* owner)> CNpcHomun::_OnFeed;
	static hook_method<void (CNpcHomun::*)(CCharacter* sender, int exp, int par1)> CNpcHomun::_OnAddExp;
	static hook_method<void (CNpcHomun::*)(CCharacter* sender, int exp, int par1)> CNpcHomun::_OnShareExp;
	static hook_method<void (CNpcHomun::*)(int val)> CNpcHomun::_ModifyFullness;
	static hook_method<void (CNpcHomun::*)(float val)> CNpcHomun::_ModifyRelationship;
	static hook_method<void (CNpcHomun::*)(char state, int data)> CNpcHomun::_SendStateHomun;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_SendProperty;
	static hook_method<void (CNpcHomun::*)(unsigned long time, int skillID)> CNpcHomun::_SetInvincibleTimeInfo;
	static hook_method<void (CNpcHomun::*)(unsigned long firstTime, unsigned long secondTime, int state)> CNpcHomun::_SetBodyStateTimeInfo;
	static hook_method<void (CNpcHomun::*)(int firstTime, int secondTime, int state)> CNpcHomun::_SetHealthStateTimeInfo;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetATKPoint_Client;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetCRI_Client;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetDEF_Client;
	static hook_method<short (CNpcHomun::*)(void)> CNpcHomun::_GetATKTime_Client;
	static hook_method<short (CNpcHomun::*)(short val)> CNpcHomun::_GetRelationGrade;
	static hook_method<int (CNpcHomun::*)(int fullness)> CNpcHomun::_GetFullnessGrade;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetRecoverSPD_HP;
	static hook_method<int (CNpcHomun::*)(void)> CNpcHomun::_GetRecoverSPD_SP;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_UpdateStatusATKpower;
	static hook_method<void (CNpcHomun::*)(void)> CNpcHomun::_UpgradeStatus_LevelUp;
	static hook_method<void (CNpcHomun::*)(int SKID, int AID, int SKData)> CNpcHomun::_OPSkillToSelf;
	static hook_method<void (CNpcHomun::*)(int SKID, int AID, int SKData)> CNpcHomun::_ATKSkillToChar;
	static hook_method<int (CNpcHomun::*)(CPC* owner, const MSG_TYPE4_FIVEDWORD& in_msg)> CNpcHomun::_SK_LIF_Heal;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_LIF_Avoid;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_LIF_Change;
	static hook_method<int (CNpcHomun::*)(CPC* owner)> CNpcHomun::_SK_AMI_Castle;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_AMI_Defence;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_AMI_BloodLust;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_FLI_Fleet;
	static hook_method<int (CNpcHomun::*)(MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_FLI_Speed;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_VAN_Chaotic;
	static hook_method<int (CNpcHomun::*)(CPC* owner, MSG_TYPE4_FIVEDWORD* msg)> CNpcHomun::_SK_VAN_Explosion;
};
