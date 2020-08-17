#pragma once
#include "CSAuth.h"
#include "Common/Packet.h"
#include "NetLib/PacketHandler.h"
class CPC;
struct PACKET_CZ_REQUEST_MOVE;
struct PACKET_CZ_USE_SKILL_TOGROUND;
struct PACKET_CZ_MER_COMMAND;
struct PACKET_CZ_REQUEST_ACTNPC;
struct PACKET_CZ_PARTY_JOIN_REQ;
struct PACKET_CZ_PARTY_CONFIG;
struct PACKET_CZ_PARTY_JOIN_REQ_ACK;
struct PACKET_CZ_MEMORIALDUNGEON_COMMAND;
struct PACKET_CZ_EQUIPWIN_MICROSCOPE;
struct PACKET_CZ_CONFIG;
struct PACKET_CZ_REQ_LEAVE_GROUP;


class CPCPacketHandler : public CPacketHandler
{
	struct vtable_t // const CPCPacketHandler::`vftable'
	{
		int (CPCPacketHandler::* OnProcess)(void);
		int (CPacketHandler::* OnRecvHook)(int byteTransferred, char* buf);
		void (CPCPacketHandler::* OnRecvOverflow)(int byteTransferred);
		void (CPCPacketHandler::* OnRecv)(int byteTransferred);
		void (CPCPacketHandler::* OnClose)(void);
		void (CPCPacketHandler::* AddSendBytes)(int len);
		void (CPacketHandler::* SetQueue)(CPacketQueue* queue);
		void* (CPCPacketHandler::* scalar_deleting_destructor)(unsigned int flags);
	};

	/* this+  0 */ public: //CPacketHandler baseclass_0;
	/* this+  8 */ private: CPC* m_pc;
	/* this+ 12 */ private: DWORD m_ReqGuildEmblemTime;
	/* this+ 16 */ private: DWORD m_ReqGuildMenuTime[4];
	/* this+ 32 */ private: DWORD m_RequestNpcTime;
	/* this+ 36 */ private: CCSAuth m_csAuth;
	/* this+156 */ private: int m_bLockCashPoint;

	public: CPCPacketHandler::CPCPacketHandler(void);
	public: virtual CPCPacketHandler::~CPCPacketHandler(void);
	public: virtual void CPCPacketHandler::OnRecvOverflow(int byteTransferred);
	public: virtual void CPCPacketHandler::OnRecv(int byteTransferred);
	public: virtual int CPCPacketHandler::OnProcess(void);
	public: HOOKED virtual void CPCPacketHandler::OnClose(void);
	public: void CPCPacketHandler::SetMyOwner(CPC* pc);
	public: virtual void CPCPacketHandler::AddSendBytes(int len);
	public: void CPCPacketHandler::Init(void);
	public: void CPCPacketHandler::OnBroadCast(int len);
	private: void CPCPacketHandler::OnMove(int packetlen);
	public: void CPCPacketHandler::OnMove(PACKET_CZ_REQUEST_MOVE* move_req);
	public: BOOL CPCPacketHandler::StartPath(PACKET_CZ_REQUEST_MOVE* p_MoveReq, DWORD startTime);
	public: void CPCPacketHandler::LockOnAttack(void);
	//public: void CPCPacketHandler::RequestSit();
	public: void CPCPacketHandler::CounterAttack(unsigned long targetID);
	//public: void CPCPacketHandler::OnSit();
	//public: void CPCPacketHandler::UseForcedSkill(char *);
	//public: void CPCPacketHandler::UnLockCashPoint();
	//private: int CPCPacketHandler::OnShandaProcess();
	private: HOOKED int CPCPacketHandler::DispatchPacket(short Header, int packetSize);
	private: void CPCPacketHandler::OnEnter(const unsigned long in_AID, const unsigned long in_GID, const int in_AuthCode, const unsigned long in_clientTime, const unsigned char in_Sex);
	private: HOOKED void CPCPacketHandler::OnChat(int len);
	private: void CPCPacketHandler::OnRequestTime(int len);
	private: void CPCPacketHandler::OnActorInit(int len);
	private: void CPCPacketHandler::OnContactNPC(int len);
	private: HOOKED void CPCPacketHandler::OnReqName(int packetSize);
	private: HOOKED void CPCPacketHandler::OnWhisper(int len);
	private: void CPCPacketHandler::OnChangeDir(int len);
	private: void CPCPacketHandler::OnDisconnectCharacter(int len);
	private: void CPCPacketHandler::OnDisconnectAllCharacter(int len);
	private: void CPCPacketHandler::OnReqAct1(int packetSize, char* buf);
	private: void CPCPacketHandler::OnReqAct2(const unsigned long in_targetGID, const unsigned char in_action, const bool in_bRequestClient);
	private: void CPCPacketHandler::OnMakeGroup(int len);
	private: void CPCPacketHandler::OnReqJoinGroup(int len);
	private: void CPCPacketHandler::OnJoinGroup(int len);
	private: void CPCPacketHandler::OnReqExpelGroupMember(int len);
	private: void CPCPacketHandler::OnReqNameByGID(int len);
	private: void CPCPacketHandler::OnPickUpItem(int len);
	private: void CPCPacketHandler::OnThrowItem(int len);
	private: void CPCPacketHandler::OnUseItem(int len);
	private: void CPCPacketHandler::OnUseItem2(const unsigned short in_index, const unsigned long in_AID);
	private: void CPCPacketHandler::OnWearEquip(int len);
	private: void CPCPacketHandler::OnTakeOffEquip(int len);
	private: void CPCPacketHandler::OnPurchaseItem(int len);
	private: void CPCPacketHandler::OnSellItem(int len);
	private: void CPCPacketHandler::OnItemExplanationByName(int len);
	private: void CPCPacketHandler::OnChooseMenu(int len);
	private: void CPCPacketHandler::OnReqNextScript(int len);
	private: void CPCPacketHandler::OnRestart(int len);
	private: void CPCPacketHandler::OnRestart_QUIT_RESTART(void);
	private: void CPCPacketHandler::OnRestart_QUIT_EXIT(void);
	private: bool CPCPacketHandler::OnRestart_QUIT_EXIT_Part1(void);
	public: void CPCPacketHandler::OnRestart_QUIT_EXIT_Part2(void);
	private: void CPCPacketHandler::OnStatusChange(int len);
	private: void CPCPacketHandler::OnReqEmotion(int len);
	private: void CPCPacketHandler::OnReqUserCount(int len);
	private: void CPCPacketHandler::OnSelectDealType(int len);
	private: void CPCPacketHandler::OnSettingWhisperPC(int len);
	private: void CPCPacketHandler::OnSettingWhisperState(int len);
	private: void CPCPacketHandler::OnReqWhisperList(int len2);
	private: void CPCPacketHandler::OnCreateChatRoom(int len);
	private: void CPCPacketHandler::OnReqEnterRoom(int len);
	private: void CPCPacketHandler::OnChangeChatRoom(int len);
	private: void CPCPacketHandler::OnReqChangeRole(int len);
	private: void CPCPacketHandler::OnReqExpelMember(int len);
	private: void CPCPacketHandler::OnExitRoom(int len);
	private: void CPCPacketHandler::OnReqExchangeItem(int len);
	private: void CPCPacketHandler::OnAckReqExchangeItem(int len);
	private: void CPCPacketHandler::OnExecExchangeItem(int len);
	private: void CPCPacketHandler::OnAddExchangeItem(int len);
	private: void CPCPacketHandler::OnConcludeExchangeItem(int len);
	private: void CPCPacketHandler::OnCancelExchangeItem(int len);
	private: void CPCPacketHandler::OnCancelLockOn(int len);
	private: void CPCPacketHandler::OnMoveItemFromBodyToStore(int len);
	private: void CPCPacketHandler::OnMoveItemFromStoreToBody(int len);
	private: void CPCPacketHandler::OnMoveItemFromBodyToCart(int len);
	private: void CPCPacketHandler::OnMoveItemFromCartToBody(int len);
	private: void CPCPacketHandler::OnMoveItemFromStoreToCart(int len);
	private: void CPCPacketHandler::OnMoveItemFromCartToStore(int len);
	private: void CPCPacketHandler::OnCloseStore(int len);
	private: HOOKED void CPCPacketHandler::OnChatParty(int len);
	private: void CPCPacketHandler::OnUpgradeSkillLevel(int len);
	private: void CPCPacketHandler::OnUseSkill(const unsigned short in_SKID, const short in_selectedLevel, unsigned long in_targetID);
	private: void CPCPacketHandler::OnUseGuildSkill(const unsigned short in_SKID, const short in_selectedLevel, const unsigned long in_targetID);
	private: void CPCPacketHandler::OnUseSkill_Merce(const unsigned short in_SKID, const short in_selectedLevel, const unsigned long in_targetID);
	private: void CPCPacketHandler::OnUseSkillToGround(const PACKET_CZ_USE_SKILL_TOGROUND& packet);
	private: void CPCPacketHandler::OnSelectWarpPoint(int len);
	private: void CPCPacketHandler::OnRememberWarpPoint(int len);
	private: void CPCPacketHandler::OnCartOff(int len);
	private: HOOKED void CPCPacketHandler::OnReqCloseMCStore(int len);
	private: void CPCPacketHandler::OnReqOpenMCStore(int len);
	private: void CPCPacketHandler::OnReqOpenMCStore2(int len);
	private: void CPCPacketHandler::PurchaseItemFromMCStore(int len);
	private: void CPCPacketHandler::OnReqItemListFromMCStore(int len);
	private: void CPCPacketHandler::OnPKModeChange(int len);
	private: void CPCPacketHandler::OnItemCreate(int len);
	private: void CPCPacketHandler::OnAdminMapMove(int len);
	private: void CPCPacketHandler::OnChangeGroupExpOption(int len);
	private: void CPCPacketHandler::OnInputEditDlg(int len);
	private: void CPCPacketHandler::OnCloseDialog(int len);
	private: void CPCPacketHandler::OnReqItemIdentify(int len);
	private: void CPCPacketHandler::OnReqItemCompositionList(int len);
	private: void CPCPacketHandler::OnReqItemComposition(int len);
	private: void CPCPacketHandler::OnReqDisconnect(int len);
	private: void CPCPacketHandler::OnSelectAutoSpell(int len);
	private: void CPCPacketHandler::OnReqGuildMenuInterface(int len);
	private: void CPCPacketHandler::OnReqGuildMenu(int len);
	private: void CPCPacketHandler::OnReqGuildEmblemImg(int len);
	private: HOOKED void CPCPacketHandler::OnRegisterGuildEmblemImg(int len);
	private: void CPCPacketHandler::OnReqChangeMemberPos(int len);
	private: void CPCPacketHandler::OnReqOpenMemberInfo(int len);
	private: void CPCPacketHandler::OnReqLeaveGuild(int len);
	private: void CPCPacketHandler::OnReqBanGuild(int len);
	private: void CPCPacketHandler::OnReqDisorganizeGuild(int len);
	private: void CPCPacketHandler::OnReqChangeGuildPositionInfo(int len);
	private: HOOKED void CPCPacketHandler::OnReqHostileGuild(int len);
	private: void CPCPacketHandler::SendAckReqAllyGuild(unsigned long AID, unsigned char answer);
	private: void CPCPacketHandler::SendAckReqHostileGuild(unsigned long AID, unsigned char answer);
	private: HOOKED void CPCPacketHandler::OnReqAllyGuild(int packetSize);
	private: void CPCPacketHandler::OnAllyGuild(int packetSize);
	private: void CPCPacketHandler::OnGuildNotice(int packetSize);
	private: HOOKED void CPCPacketHandler::OnGuildChat(int packetSize);
	private: HOOKED void CPCPacketHandler::OnReqMakeGuild(int packetLen);
	private: void CPCPacketHandler::OnReqJoinGuild(int packetSize);
	private: void CPCPacketHandler::OnJoinGuild(int packetSize);
	private: void CPCPacketHandler::OnReqDeleteRelatedGuild(int Len);
	private: void CPCPacketHandler::OnReqGuildMemberInfo(int len);
	private: void CPCPacketHandler::OnResetParameter(int len);
	private: void CPCPacketHandler::OnChangeMapType(int len);
	private: void CPCPacketHandler::OnLocalBroadCast(int len);
	private: void CPCPacketHandler::OnChangeEffectState(int len);
	public: void CPCPacketHandler::ResetReqGuildTime(void);
	private: void CPCPacketHandler::OnGuildZeny(int len);
	private: void CPCPacketHandler::OnReqMakingItem(int len);
	private: void CPCPacketHandler::OnReqUSE_SKILL_TOGROUND_WITHTALKBOX(int len);
	private: void CPCPacketHandler::OnGiveMannerPoint(int packetSize);
	private: void CPCPacketHandler::OnGiveMannerPointByName(int len);
	private: void CPCPacketHandler::OnTryCaptureMonster(int len);
	private: void CPCPacketHandler::OnCommandPet(int len);
	private: void CPCPacketHandler::OnRenamePet(int len);
	private: void CPCPacketHandler::OnRenameHomun(int len);
	private: void CPCPacketHandler::OnSelectPetEgg(int len);
	private: void CPCPacketHandler::OnPetEggInfo(int len);
	private: void CPCPacketHandler::OnPetAct(int len);
	private: void CPCPacketHandler::OnMakingItem(void);
	private: void CPCPacketHandler::OnRemoveAID(int len);
	private: void CPCPacketHandler::OnShift(int len);
	private: void CPCPacketHandler::OnRecall(int len);
	private: void CPCPacketHandler::OnRecallGID(int len);
	private: void CPCPacketHandler::OnReqEncryption(int len);
	private: void CPCPacketHandler::OnInputEditDlgStr(int len);
	private: void CPCPacketHandler::OnAddFriend(int len);
	private: void CPCPacketHandler::OnDeleteFriend(int len);
	private: void CPCPacketHandler::OnAckReqAddFriends(int len);
//	private: void CPCPacketHandler::OnReqPVPPoint(int);
	private: void CPCPacketHandler::OnReqStatus(int len);
	private: void CPCPacketHandler::OnReqMakerRanking(const short in_PacketType, const int in_PacketLength);
	private: void CPCPacketHandler::OnReqMakerRanking2(int len);
	private: void CPCPacketHandler::OnReqDeathQuestion(int len);
	private: void CPCPacketHandler::OnReqKSY(int len);
	private: void CPCPacketHandler::OnLessEffect(int len);
	private: void CPCPacketHandler::OnAckGameGuard(int len);
	private: void CPCPacketHandler::OnRequestMoveToOwner(int len);
	private: void CPCPacketHandler::OnRequestMoveNpc(int len);
	private: void CPCPacketHandler::OnRequestActNpc(int len);
	private: void CPCPacketHandler::OnCommandMercenary(int len);
	private: void CPCPacketHandler::OnAckStorePassword(int len);
	private: void CPCPacketHandler::OnMailGetList(int len);
	private: void CPCPacketHandler::OnMailOpen(int len);
	private: void CPCPacketHandler::OnMailDelete(int len);
	private: void CPCPacketHandler::OnMailGetItem(int len);
	private: void CPCPacketHandler::OnMailResetItem(int len);
	private: void CPCPacketHandler::OnMailAddItem(int len);
	private: HOOKED void CPCPacketHandler::OnMailSend(int len);
	private: void CPCPacketHandler::OnMailReturn(int len);
	private: void CPCPacketHandler::OnAuctionCreate(int len);
	private: void CPCPacketHandler::OnAuctionAddItem(int len);
	private: void CPCPacketHandler::OnAuctionAdd(int len);
	private: void CPCPacketHandler::OnAuctionAddCancel(int len);
	private: void CPCPacketHandler::OnAuctionBuy(int len);
	private: void CPCPacketHandler::OnAuctionItemSearch(int len);
	private: void CPCPacketHandler::OnAuctionReqMyInfo(int len);
	private: void CPCPacketHandler::OnAuctionMySellStop(int len);
	private: void CPCPacketHandler::OnHuntingList(int len);
	private: void CPCPacketHandler::OnPCBuyCashPointItem(int len);
	private: void CPCPacketHandler::OnPCBuyCashPointItemSimpleShop(int len);
	private: void CPCPacketHandler::OnStandingResurrection(int len);
	private: void CPCPacketHandler::OnCashPassword(int len);
	private: HOOKED void CPCPacketHandler::OnShortcutKey_Change(int len);
	private: void CPCPacketHandler::OnActiveQuest(int len);
	private: HOOKED void CPCPacketHandler::OnBattleFieldChat(int len);
	private: void CPCPacketHandler::OnProgress(int len);
	private: void CPCPacketHandler::OnCzOpenSimpleCashShopItemList(int len);
	private: void CPCPacketHandler::OnCZOnCloseWindow(int len);
	private: void CPCPacketHandler::OnCZClientVersion(int len);
	private: void CPCPacketHandler::OnCZCloseSimpleCashShop(int len);
	private: bool CPCPacketHandler::IsFixedPacket(int packetType);
	private: int CPCPacketHandler::GetPacketSize(int packetType);
	private: bool CPCPacketHandler::CheckRequestNpcTime(void);
	private: bool CPCPacketHandler::SendMsgItemScriptEvent(int senderAID, unsigned long msgID, int par1, int par2, int par3);
	private: bool CPCPacketHandler::CheckMap(unsigned long AID, unsigned long type);
	private: bool CPCPacketHandler::ForcedCloseDialog(unsigned long NPCID);
	public: void CPCPacketHandler::NotifyBattleFieldPoint(void);
	private: void CPCPacketHandler::OnGroupInfoChangeV2(int len);
//	private: void CPCPacketHandler::OnChangeGroupMaster(int);
	private: void CPCPacketHandler::OnSeekParty(int len);
//	private: void CPCPacketHandler::OnSeekPartyMember(int);
	private: void CPCPacketHandler::BroadcastNewPosition(int dx, int dy);
//	public: void CPCPacketHandler::OnCZ_REASSEMBLY_IDENTITY(const int, const bool, const bool, const bool, const bool);
	private: void CPCPacketHandler::OnMercenary_Command(const PACKET_CZ_MER_COMMAND* in_pPacket);
	private: void CPCPacketHandler::OnMercenary_RequestActNpc(const PACKET_CZ_REQUEST_ACTNPC* in_pPacket);
	private: void CPCPacketHandler::OnMercenary_UseSkill(const unsigned short in_SKID, const short in_selectedLevel, unsigned long in_targetID);
	private: void CPCPacketHandler::OnMercenary_UseSkill_ToGround(const PACKET_CZ_USE_SKILL_TOGROUND& in_Packet);
	private: void CPCPacketHandler::OnCZ_PARTY_JOIN_REQ(const PACKET_CZ_PARTY_JOIN_REQ& in_packet);
	private: void CPCPacketHandler::OnCZ_PARTY_CONFIG(const PACKET_CZ_PARTY_CONFIG& in_packet);
	private: void CPCPacketHandler::OnCZ_PARTY_JOIN_REQ_ACK(const PACKET_CZ_PARTY_JOIN_REQ_ACK& in_packet);
	private: void CPCPacketHandler::OnCZ_MEMORIALDUNGEON_COMMAND(const PACKET_CZ_MEMORIALDUNGEON_COMMAND& in_packet);
	private: void CPCPacketHandler::OnCZ_EQUIPWIN_MICROSCOPE(const PACKET_CZ_EQUIPWIN_MICROSCOPE& in_packet);
	private: void CPCPacketHandler::OnCZ_CONFIG(const PACKET_CZ_CONFIG& in_packet);
	private: void CPCPacketHandler::OnCZ_REQ_LEAVE_GROUP(const PACKET_CZ_REQ_LEAVE_GROUP& in_packet);
//	private: void CPCPacketHandler::OnCZ_SKILL_SELECT_RESPONSE(const PACKET_CZ_SKILL_SELECT_RESPONSE &);
//	private: void CPCPacketHandler::OnCZ_ITEMLISTWIN_RES(const PACKET_CZ_ITEMLISTWIN_RES *);

private:
	static hook_method<void (CPCPacketHandler::*)(int byteTransferred)> CPCPacketHandler::_OnRecvOverflow;
	static hook_method<void (CPCPacketHandler::*)(int byteTransferred)> CPCPacketHandler::_OnRecv;
	static hook_method<int  (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnProcess;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnClose;
	static hook_method<void (CPCPacketHandler::*)(CPC* pc)> CPCPacketHandler::_SetMyOwner;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_AddSendBytes;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_Init;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnBroadCast;
	static hook_method<void (CPCPacketHandler::*)(int packetlen)> CPCPacketHandler::_OnMove;
	static hook_method<void (CPCPacketHandler::*)(PACKET_CZ_REQUEST_MOVE* move_req)> CPCPacketHandler::_OnMove2;
	static hook_method<BOOL (CPCPacketHandler::*)(PACKET_CZ_REQUEST_MOVE* p_MoveReq, DWORD startTime)> CPCPacketHandler::_StartPath;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_LockOnAttack;
	static hook_method<int  (CPCPacketHandler::*)(short Header, int packetSize)> CPCPacketHandler::_DispatchPacket;
	static hook_method<void (CPCPacketHandler::*)(const unsigned long in_AID, const unsigned long in_GID, const int in_AuthCode, const unsigned long in_clientTime, const unsigned char in_Sex)> CPCPacketHandler::_OnEnter;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChat;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRequestTime;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnActorInit;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnContactNPC;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnReqName;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnWhisper;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChangeDir;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnDisconnectCharacter;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnDisconnectAllCharacter;
	static hook_method<void (CPCPacketHandler::*)(int packetSize, char* buf)> CPCPacketHandler::_OnReqAct1;
	static hook_method<void (CPCPacketHandler::*)(const unsigned long in_targetGID, const unsigned char in_action, const bool in_bRequestClient)> CPCPacketHandler::_OnReqAct2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMakeGroup;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqJoinGroup;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnJoinGroup;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqExpelGroupMember;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqNameByGID;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPickUpItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnThrowItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnUseItem;
	static hook_method<void (CPCPacketHandler::*)(const unsigned short in_index, const unsigned long in_AID)> CPCPacketHandler::_OnUseItem2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnWearEquip;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnTakeOffEquip;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPurchaseItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSellItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnItemExplanationByName;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChooseMenu;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqNextScript;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRestart;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnRestart_QUIT_RESTART;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnRestart_QUIT_EXIT;
	static hook_method<bool (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnRestart_QUIT_EXIT_Part1;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnRestart_QUIT_EXIT_Part2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnStatusChange;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqEmotion;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqUserCount;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSelectDealType;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSettingWhisperPC;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSettingWhisperState;
	static hook_method<void (CPCPacketHandler::*)(int len2)> CPCPacketHandler::_OnReqWhisperList;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCreateChatRoom;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqEnterRoom;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChangeChatRoom;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqChangeRole;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqExpelMember;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnExitRoom;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAckReqExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnExecExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAddExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnConcludeExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCancelExchangeItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCancelLockOn;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromBodyToStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromStoreToBody;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromBodyToCart;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromCartToBody;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromStoreToCart;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMoveItemFromCartToStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCloseStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChatParty;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnUpgradeSkillLevel;
	static hook_method<void (CPCPacketHandler::*)(const unsigned short in_SKID, const short in_selectedLevel, unsigned long in_targetID)> CPCPacketHandler::_OnUseSkill;
	static hook_method<void (CPCPacketHandler::*)(const unsigned short in_SKID, const short in_selectedLevel, const unsigned long in_targetID)> CPCPacketHandler::_OnUseGuildSkill;
	static hook_method<void (CPCPacketHandler::*)(const unsigned short in_SKID, const short in_selectedLevel, const unsigned long in_targetID)> CPCPacketHandler::_OnUseSkill_Merce;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_USE_SKILL_TOGROUND& packet)> CPCPacketHandler::_OnUseSkillToGround;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSelectWarpPoint;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRememberWarpPoint;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCartOff;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqCloseMCStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqOpenMCStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqOpenMCStore2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_PurchaseItemFromMCStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqItemListFromMCStore;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPKModeChange;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnItemCreate;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAdminMapMove;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChangeGroupExpOption;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnInputEditDlg;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCloseDialog;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqItemIdentify;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqItemCompositionList;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqItemComposition;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqDisconnect;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSelectAutoSpell;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqGuildMenuInterface;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqGuildMenu;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqGuildEmblemImg;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRegisterGuildEmblemImg;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqChangeMemberPos;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqOpenMemberInfo;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqLeaveGuild;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqBanGuild;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqDisorganizeGuild;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqChangeGuildPositionInfo;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqHostileGuild;
	static hook_method<void (CPCPacketHandler::*)(unsigned long AID, unsigned char answer)> CPCPacketHandler::_SendAckReqAllyGuild;
	static hook_method<void (CPCPacketHandler::*)(unsigned long AID, unsigned char answer)> CPCPacketHandler::_SendAckReqHostileGuild;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnReqAllyGuild;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnAllyGuild;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnGuildNotice;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnGuildChat;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnReqJoinGuild;
	static hook_method<void (CPCPacketHandler::*)(int packetLen)> CPCPacketHandler::_OnReqMakeGuild;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnJoinGuild;
	static hook_method<void (CPCPacketHandler::*)(int Len)> CPCPacketHandler::_OnReqDeleteRelatedGuild;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqGuildMemberInfo;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnResetParameter;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChangeMapType;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnLocalBroadCast;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnChangeEffectState;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_ResetReqGuildTime;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnGuildZeny;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqMakingItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqUSE_SKILL_TOGROUND_WITHTALKBOX;
	static hook_method<void (CPCPacketHandler::*)(int packetSize)> CPCPacketHandler::_OnGiveMannerPoint;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnGiveMannerPointByName;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnTryCaptureMonster;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCommandPet;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRenamePet;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRenameHomun;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSelectPetEgg;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPetEggInfo;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPetAct;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_OnMakingItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRemoveAID;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnShift;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRecall;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRecallGID;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqEncryption;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnInputEditDlgStr;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAddFriend;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnDeleteFriend;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAckReqAddFriends;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqStatus;
	static hook_method<void (CPCPacketHandler::*)(const short in_PacketType, const int in_PacketLength)> CPCPacketHandler::_OnReqMakerRanking;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqMakerRanking2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqDeathQuestion;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnReqKSY;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnLessEffect;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAckGameGuard;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRequestMoveToOwner;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRequestMoveNpc;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnRequestActNpc;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCommandMercenary;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAckStorePassword;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailGetList;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailOpen;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailDelete;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailGetItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailResetItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailAddItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailSend;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnMailReturn;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionCreate;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionAddItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionAdd;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionAddCancel;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionBuy;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionItemSearch;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionReqMyInfo;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnAuctionMySellStop;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnHuntingList;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPCBuyCashPointItem;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnPCBuyCashPointItemSimpleShop;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnStandingResurrection;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCashPassword;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnShortcutKey_Change;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnActiveQuest;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnBattleFieldChat;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnProgress;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCzOpenSimpleCashShopItemList;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCZOnCloseWindow;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCZClientVersion;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnCZCloseSimpleCashShop;
	static hook_method<bool (CPCPacketHandler::*)(int packetType)> CPCPacketHandler::_IsFixedPacket;
	static hook_method<int  (CPCPacketHandler::*)(int packetType)> CPCPacketHandler::_GetPacketSize;
	static hook_method<bool (CPCPacketHandler::*)(void)> CPCPacketHandler::_CheckRequestNpcTime;
	static hook_method<bool (CPCPacketHandler::*)(int senderAID, unsigned long msgID, int par1, int par2, int par3)> CPCPacketHandler::_SendMsgItemScriptEvent;
	static hook_method<bool (CPCPacketHandler::*)(unsigned long AID, unsigned long type)> CPCPacketHandler::_CheckMap;
	static hook_method<bool (CPCPacketHandler::*)(unsigned long NPCID)> CPCPacketHandler::_ForcedCloseDialog;
	static hook_method<void (CPCPacketHandler::*)(void)> CPCPacketHandler::_NotifyBattleFieldPoint;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnGroupInfoChangeV2;
	static hook_method<void (CPCPacketHandler::*)(int len)> CPCPacketHandler::_OnSeekParty;
	static hook_method<void (CPCPacketHandler::*)(int dx, int dy)> CPCPacketHandler::_BroadcastNewPosition;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_MER_COMMAND* in_pPacket)> CPCPacketHandler::_OnMercenary_Command;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_REQUEST_ACTNPC* in_pPacket)> CPCPacketHandler::_OnMercenary_RequestActNpc;
	static hook_method<void (CPCPacketHandler::*)(const unsigned short in_SKID, const short in_selectedLevel, unsigned long in_targetID)> CPCPacketHandler::_OnMercenary_UseSkill;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_USE_SKILL_TOGROUND& in_Packet)> CPCPacketHandler::_OnMercenary_UseSkill_ToGround;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_PARTY_JOIN_REQ& in_packet)> CPCPacketHandler::_OnCZ_PARTY_JOIN_REQ;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_PARTY_CONFIG& in_packet)> CPCPacketHandler::_OnCZ_PARTY_CONFIG;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_PARTY_JOIN_REQ_ACK& in_packet)> CPCPacketHandler::_OnCZ_PARTY_JOIN_REQ_ACK;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_MEMORIALDUNGEON_COMMAND& in_packet)> CPCPacketHandler::_OnCZ_MEMORIALDUNGEON_COMMAND;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_EQUIPWIN_MICROSCOPE& in_packet)> CPCPacketHandler::_OnCZ_EQUIPWIN_MICROSCOPE;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_CONFIG& in_packet)> CPCPacketHandler::_OnCZ_CONFIG;
	static hook_method<void (CPCPacketHandler::*)(const PACKET_CZ_REQ_LEAVE_GROUP& in_packet)> CPCPacketHandler::_OnCZ_REQ_LEAVE_GROUP;

	friend unsigned int RFIFOREST(const CPC*);
};


extern void __cdecl Sned_PACKET_ZC_PARTY_JOIN_REQ_ACK(CPC*const in_pToPlayer, const char* in_pTargetCharName, enum PACKET_ZC_PARTY_JOIN_REQ_ACK::enumAnswer in_Answer);