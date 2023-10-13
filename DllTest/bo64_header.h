#pragma once

int AuthorisePass = 0;

int EncryptKey[] = { 7, 4, 1, 8, 2 };
int SpecialEncryptKey[] = { 4, 5, 7, 8, 1 };

const char* PluginVer = "1.0.72";
int IsDumpSo = 1;

#define ENABLE_DEBUG 1

#ifdef ENABLE_DEBUG 
//#define DEBUG_PRINT(x) OutputDebugString(x)
//#define DEBUG_PRINT(...) {char cad[512]; snprintf(cad,512, __VA_ARGS__);  OutputDebugStringA(cad);}
#define DEBUG_PRINT(...) 
#else 
#define DEBUG_PRINT(...) 
#endif

//#define GENERAL_PRINT(...) {char cad[512]; snprintf(cad,512, __VA_ARGS__);  OutputDebugStringA(cad);}
#define GENERAL_PRINT(...) 

//From大文 
//lm_getMapAreaID = (int* (*)(int*))(ADDR);
//lm_getMapAreaID 就係一個
//int* (int*)
//既function指針

#define KEYEVENTF_KEYDOWN  0x0


#define LODWORD(_qw)    ((DWORD)(_qw))
#define HIDWORD(l) ((DWORD)(((DWORDLONG)(l) >> 32) & 0xFFFFFFFF))

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;
typedef __int64 int64;
using uint = unsigned int;

__uint64_t* LHGameInstanceAddr;
__uint64_t* GameThreadIdPtr;
__uint64_t* EnginePtr ;
__uint64_t* UWolrldPtr;
__uint64_t* ClosePanelStartAddr;
__uint64_t* GameObject2_ClientConfigPtr;


__uint64_t* GameThreadTid = 0;
__uint64_t* FB2ScalabilityControllerPtr;
__uint64_t(*UEngine_GetWorldFromContextObject)  (__uint64_t, __uint64_t, int);


__uint64_t(*GetFNameString)(__uint64_t, __uint64_t);


__uint64_t(*FMemory_Free_Real) (__uint64_t);
__uint64_t(*FTextToString)  (__uint64_t);
__uint64_t(*TextBlock_GetDisplayText)  (__uint64_t, __uint64_t);
__uint64_t(*GetUObjectFullPathName)  (__uint64_t, __uint64_t, __uint64_t, char);
//__uint64_t(*UWidget_GetParent)  (__uint64_t);
unsigned int (*UWidget_GetVisibility)  (__uint64_t);



__uint64_t(*UWidget_GetIsEnabled)  (__uint64_t);

__uint64_t(*UCheckBox_GetCheckedState)  (__uint64_t);
__uint64_t(*old_GetAllChildWidgets)  (__uint64_t, __uint64_t);
//__uint64_t(*UWidgetSwitcher_GetActiveWidgetIndex)  (__uint64_t);
__uint64_t(*UWidget_GetCachedGeometry)  (__uint64_t);

__uint64_t(*USlateBlueprintLibrary_LocalToViewport)  (__uint64_t, __uint64_t, __uint64_t, __uint64_t, __uint64_t);
__uint64_t(*old_GameViewportClient_GetViewportSize) (__uint64_t, __uint64_t);
//__uint64_t(*GameInstance_GetGameViewportClient) (__uint64_t);


__uint64_t(*ULHMapMgr_SetAutoMove) (__uint64_t, int, char, __uint64_t);





__uint64_t(*UButton_SlateHandleClicked)(__uint64_t, __uint64_t);
__uint64_t(*UButton_SlateHandlePressed)(__uint64_t);
__uint64_t(*UButton_SlateHandleReleased)(__uint64_t);


__uint64_t(*UEngine_SetMaxFPS) (__uint64_t, float);

__uint64_t(*old_UNkUiManager_Tick) (__uint64_t);

__uint64_t Testing_Fun2(__uint64_t a, __uint64_t a2);
__uint64_t(*old_Testing_Fun2) (__uint64_t, __uint64_t);

__uint64_t(*UserWidget_GetPrivateStaticClass) ();
__uint64_t(*AB2HUD_GetPrivateStaticClass) ();
__uint64_t(*AB2PlayerController_GetPrivateStaticClass) ();




__uint64_t(*GetObjectsOfClass) (__uint64_t, __uint64_t, char, int, int);


char (*Item2_GetItemGrade) (__uint64_t);
__uint64_t(*Item2_GetItemName) (__uint64_t);
__uint64_t(*Bag2_RequestConsumeItem) (__uint64_t, __uint64_t,int,int);
__uint64_t(*Bag2_RequestDestroyItem) (__uint64_t, __uint64_t, __int16, int);
__uint64_t(*Game_AutoPlayMapMove) (__uint64_t, __uint64_t, __uint64_t,  float, __uint64_t,  char);
char(*ICharacter_HasMoveCommand) (__uint64_t);

__uint64_t(*WeakObjectPtr_Get) (__uint64_t);

__uint64_t(*UISleepModePanel_OnClose) (__uint64_t, __uint64_t);
__uint64_t(*UISleepModePanel_Open) (__uint64_t);

__uint64_t(*UISleepModePanel_SetSleepState) (__uint64_t, char, char);

__uint64_t(*UIPanelManager_OpenPanel) (__uint64_t, int, char);

__uint64_t(*UScrollBox_SetScrollOffset) (__uint64_t, float);
__uint64_t(*STableViewBase_SetScrollOffset) (__uint64_t, float);


__uint64_t(*Map3DPanel_HandleSwipeDeltaEvent) (__uint64_t, __uint64_t, float);

__uint64_t(*Game_FindAgent) (__uint64_t, __uint64_t, __uint64_t);


char (*EquipSet_IsEquipped) (__uint64_t, __uint64_t);

__uint64_t(*Bag2_RequestDisassembleItem) (__uint64_t, __uint64_t,int);

__uint64_t(*Quest_GetQuestMissionProgressMax) (__uint64_t);
__uint64_t(*UITradeBag_OnClickSlotButton) (__uint64_t, __uint64_t);

__uint64_t(*UIInventoryPanel_OnClickItemSlotButton) (__uint64_t, __uint64_t,int);

__uint64_t(*Tutorial_End) ( __uint64_t,char, int);



__uint64_t(*Game_checkAvailableAutoMoveWhatHyperRun) (__uint64_t);
__uint64_t(*PlayerHeroDisplay_StopMoveOnPath) (__uint64_t);
__uint64_t(*PlayerHeroDisplay_StopDestGimmick) (__uint64_t);
__uint64_t(*AgentDisplay_ClearActionTimer) (__uint64_t);

__uint64_t(*AutoPlay2_Finish) (__uint64_t);
__uint64_t(*AutoPlay2_setCommonParam) (__uint64_t, __uint64_t, char);
__uint64_t(*AutoPlay2_setMoveParam) (__uint64_t, __uint64_t, __uint64_t, float);
__uint64_t(*AutoPlay2_setMoveParamDungeon) (__uint64_t, __uint64_t, __uint64_t, float);
__uint64_t(*AutoPlay2_changePlayState) (__uint64_t, char, char);
__uint64_t(*AutoMovePath_FindPath) (__uint64_t, __uint64_t, char);
__uint64_t(*UpdateAutoBattleUIAndMessage) ();//Fused


__uint64_t(*Grocery_ProcessUseGroceryItem) (__uint64_t, __uint64_t, __uint64_t, __uint64_t, __uint64_t, __uint64_t, char);


char (*PlayerHero_GetWeaponGroupType) (__uint64_t);
__uint64_t(*QuickSetBook_SetUseAuto) (__uint64_t, __uint64_t, char, char);
__uint64_t(*PlayerHero_SetUseAuto) (__uint64_t, char, char, char);



__uint64_t(*EquipSet_GetEquipSlot) (__uint64_t, char, unsigned __int16 );
__uint64_t(*Bag2_RequestEquipItem) (__uint64_t, char, unsigned __int16 , __uint64_t, char, char);

__uint64_t(*Party_RequestInvitePartyByHeroName) (__uint64_t, char *, __uint64_t);

__uint64_t(*Npc_GetRecordName) (__uint64_t, __uint64_t);

__uint64_t(*Game_SetAttackTargetId) (__uint64_t, __uint64_t,char, char);
__uint64_t(*Game_AutoPlayAttack) (__uint64_t);
__uint64_t(*Game_PickTarget) (__uint64_t, __uint64_t, char);

__uint64_t(*FB2ScalabilityController_SetMaxFPS) (__uint64_t, float);
__uint64_t(*AutoPlay_Combat) (__uint64_t, __uint64_t,char);

__uint64_t(*ChatMain_sendMessageEscape) (__uint64_t);

__uint64_t(*HyperRunController_SetImpossibleAutoMoveEb) (__uint64_t, char);
__uint64_t(*HyperRunController_PlayHyperRunEh) (__uint64_t, char);

__uint64_t(*GetFB2ScalabilityController) ();

__uint64_t(*Game_UnlockTarget) (__uint64_t);


__uint64_t(*SkillContext6_CheckCanHitTargetByAutoEy) (__uint64_t, __uint64_t);
__uint64_t(*Game_AutoPlayAttackTarget) (__uint64_t, __uint64_t, char, char);
__uint64_t(*Game_SetPickedAgentId) (__uint64_t, char, char);
__uint64_t(*AutoPlay2_SingleCombat) (__uint64_t);

__uint64_t(*AutoPlay2_SingleSkill) (__uint64_t, __uint64_t);


__uint64_t(*UI3DWorldMap_getUI3DMapObjectMapIconObject) (__uint64_t, __uint64_t,int);
__uint64_t(*UI3DMapPanel_OnWorldMapIconTouched) (__uint64_t, unsigned  int, float);

__uint64_t(*DataManager_GetEquipCollectionDictEv) ();
__uint64_t(*DataManager3_GetEffectManualDictEv) ();

__uint64_t(*EffectManualDict_GetEffectByIdEv) (__uint64_t, __uint64_t);


__uint64_t(*B2ClientTextFormat_GetText) (__uint64_t, __uint64_t);

__uint64_t(*CircularViewWrapper_ScrollToIndexIntoView) (__uint64_t, unsigned int , unsigned __int8 , unsigned __int8 );

__uint64_t(*UIItemCircularView_GetGridDataIndex) (__uint64_t, int);


__uint64_t(*Stash2_RequestMoveToInventory) (__uint64_t, __uint64_t, unsigned __int16, int);
__uint64_t(*Bag2_RequestMoveToStash) (__uint64_t, __uint64_t, unsigned __int16, int);
__uint64_t(*UIStashPanel_refreshItem) (__uint64_t);
__uint64_t(*Bag2_RequestSellItem2) (__uint64_t, __uint64_t, __uint64_t, unsigned __int16, int);

__uint64_t(*UICitizenShopPanel_OnClickBagSlotButtonERK5FName) (__uint64_t, __uint64_t, __uint64_t);


static int (*fake_SendMessagew)(HWND, UINT, WPARAM, LPARAM);
__uint64_t(*FScreenshotRequest_RequestScreenshot)  (__uint64_t, char, char);
__uint64_t(*DefaultAllocator_ResizeForCopy)  (__uint64_t, signed int, signed int);

char(*B2Client_GetContentsOptionSkipEnchantResultPopup)  (__uint64_t);

__uint64_t(*UEngine_GetFirstLocalPlayerController) (__uint64_t, __uint64_t);
__uint64_t(*AController_SetControlRotation) (__uint64_t, __uint64_t);

__uint64_t(*B2Client_GetAccountLoginHistroy_LastConnectedWorldName) ();

char(*Agent_IsAttackPlayerHero) (__uint64_t);



std::string GetUIElementByTree(char* TreeStr, char* TmpResult, int SizeOfTmpResult, int IsIgnoreHide);
void GetFNameStr(char* output, __uint64_t TmpAddress);
__uint64_t FMemory_Free(__uint64_t a);
__uint64_t GetChildElementByName(__uint64_t ParentElement, char* ChildElementName, int IsIgnoreHide, int IsLastTreeNode);
void SetGameFunAddr();
void GetPlayerLVExp();
void GetPlayerHP();
void GetIsMoving();
void ReadBagItem();
int GetEmptyBagItemSlot(__uint64_t ItemID, __int64 Count);
uint64_t GetBaseAddress();
__uint64_t GetItemFNameIDBPos(__uint64_t UIItemGridWidget, int Pos);
int GetTradeBagFNameID(__uint64_t InstanceId);
int GetBagItemFNameID(__uint64_t InstanceId);
int GetSellBagItemFNameID(__uint64_t InstanceId);
void usleep(int microsec);
__uint64_t HookFloat(__uint64_t a);
void FakeCallGameFunction();
__uint64_t GetHyperRunController();
void AutoRunToPos(__uint64_t MapID, float X, float Y, float Z);
void AutoRunToPosByNoTeleport(__uint64_t MapID,  float X, float Y, float Z);


void ReadAllUI();
__uint64_t UWidget_IsVisible(__uint64_t a);
__uint64_t UWidget_GetParent(__uint64_t a);
__int64 UWidgetSwitcher_GetActiveWidgetIndex(__int64 a1);
__uint64_t GameInstance_GetGameViewportClient(__uint64_t a);
bool UUserWidget_GetIsVisible(__uint64_t a1);
int IsUUserWidget(__uint64_t a);
__uint64_t FoundUIByTree(char* TreeStr, int IsIgnoreHide);
int __fastcall B2Client__IsShowLoadingScreen(__int64_t Tmpthis);
int SetAndCheckGameVerion();

void WaitGetUIDone();
Json::Value  DumpAllUI(Json::Value Root);
Json::Value DumpChildElementByName(Json::Value Root, __uint64_t ParentElement, int IsWidgetTree);
struct UISizeCoorType GetUISizeCoorInfo(__uint64_t TmpUObject);
void GetChildUIList(__uint64_t ParentElement, char* buf, int bufsize, char* Largebuf, int Largebufsize, char* Resultbuf, int Resultbufsize, int IsGetAllChild);
__uint64_t GetUIManager();
int GetUIPanelList(__uint64_t UIMangerPtr);
__uint64_t GetBag2();
HWND GetProcessMainWindow();
LRESULT CALLBACK WndProcHook(int nCode, WPARAM wParam, LPARAM lParam);
std::string GetMissionList();
__uint64_t GetGameUI();
void GetTeamList();
void ReadStorageItem();
void SetStopMove();
void SetQuickSlotAuto(char Switch, char Pos);
__int64_t GetEquipSetPtr();
__uint64_t GetParty();
void SetAuto(char State);
__int64_t GetSkillContext6();
void SetNoAttackList();
void ResetBlackNoAttackList();
void GetBlackNoAttackList();


std::string ReadActorList();


extern "C"//防止函数被name mangling
{

    void print1(void);
    void print2(void);
    __int64 g_iValue = 100;

    __int64_t RealSlateHandleClickedPtr = 0x00276D600;
    __int64_t RealSlateHandlePressedPtr = 0x00276D600;
    __int64_t RealSlateHandleReleasePtr = 0x00276D600;
    __int64_t Game_AutoPlayMapMovePtr = 0x00276D600;
    __int64_t UISleepModePanel_OnClosePtr = 0x00276D600;
    __int64_t AutoPlay2_changePlayStatePtr = 0x00276D600;
    __int64_t AutoPlay2_FinishPtr = 0x00276D600;
    __int64_t HyperRunController_SetImpossibleAutoMoveEbPtr = 0x00276D600;
    __int64_t HyperRunController_PlayHyperRunEhPtr = 0x00276D600;
    __int64_t AutoPlay2_SingleCombatPtr = 0x00276D600;
    __int64_t Game_PickTargetPtr = 0x00276D600;
    
}






struct CoorType GetCurrentCoor();
int GetCurrentMap();

int IsLastWidgetVisible = 0;

int mmemcmp(const void* ptr1, const void* ptr2, size_t num);
int (*old_memcmp) (const void*, const void*, size_t);
void hookall();


struct UICheckListType { //名稱為student的結構
    char IsUsed;
    char Text[500];
    int IsShow;
};

struct UIElementType{ //名稱為student的結構
    char IsUsed;
    __uint64_t Pointer;
    __uint64_t ParentPtr;
    int index;
    int X; 
    int Y;
    int Show;
    char name[100];
    char Text[100];
    char NameInArray[200];
};
/*
struct UIChildType { //名稱為student的結構
    __int64_t Pointer;
    int Type;
    int x;
    int y;
    int w;
    int h;
    int IsShow;
    std::string link;
    std::string name;
    std::string Text;
    std::vector<UIChildType> son;
};

std::vector<UIChildType> UITreeList;
*/



struct UISizeCoorType { //名稱為student的結構
    int width;
    int height;
    int X;
    int Y;
};



struct PanelListType { //名稱為student的結構
    char IsUsed;
    int UObjectAddress;
};


struct TradeBagType { //名稱為student的結構
    char IsUsed;
    __int64_t Pointer;
    int id;
};

struct BagItemType { //名稱為student的結構
    char IsUsed;
    char* Pointer;
    int id;
    char NameID[100];
    char name[80];
    char NameInHex[160];
    int Count;
    int InfoId;
    int ItemGrade;
    float ItemWeight;
    int ItemBindType;
    int ItemType;
    int EquipItemType;
    int EquipItemSubType;
    __uint64_t ItemID;
    __uint64_t item2Ptr;
    __uint64_t InstanceId;
    int isEnchantable;
    int EnhanceLv;
    int ItemDataPtr;
    int isLock;
    int isTrade;
    int isDeCompsable;

    __uint64_t MaxStackCount;
    int BagType;
    int isEquipItem;
    int isEquiped;
};

struct FGeometry {
    float width;
    float height;
    float scale;
    float X;
    float Y;
    float a5;
    float a6;
    float a7;
    float a8;
    float a9;
    float a10;
    float a11;
    float a12;
};


struct CoorType {
    float XCoor;
    float YCoor;
    float ZCoor;
};


struct FMemeryType {
    __uint64_t A;
    __uint64_t B;
    __uint64_t C;
    __uint64_t D;
    __uint64_t E;
    __uint64_t F;
};

struct GMemeryType {
    __uint64_t A;
    __uint64_t B;
    __uint64_t C;
    __uint64_t D;
    __uint64_t E;
    __uint64_t F;
    __uint64_t G;
    __uint64_t H;
    __uint64_t I;

};


struct TeamType { //名稱為student的結構
    char IsUsed;
    char* Pointer;
    __int64_t id;
    __int64_t PlayerID;
    char PlayerName[200];
    int IsLeader;
    int Pos;
    __int64_t NowHP;
    __int64_t MaxHP;
    int MapID;
    
    char PlayerMap[200];
    float PosX;
    float PosY;
    float PosZ;
};

struct EffectDataType { //名稱為student的結?
    char IsUsed;
    __int64_t Pointer;
    int id;
    int Type;
    char name[500];
};

struct UIElementType UiElement[1001];
struct UIElementType UiPanel[1001];
struct PanelListType PanelList[1001];
struct UICheckListType UICheckList[501];
char UICheckStr[500];
char UICheckStr2[500];
int UICheckListCount = 0;

struct FMemeryType FixedFNameMem;
struct FMemeryType FixedAllChildWidgetMem;
struct FMemeryType FixedAllChildWidgetMemB;
struct FMemeryType FixedAllChildWidgetMemC;

struct BagItemType EquipItem[51];
struct BagItemType BagItem[1001];
struct BagItemType StorageItem[501];

struct TeamType TeamList[51];



struct PriortyAttackListType { //名稱為student的結構
    char IsUsed;
    std::string name;
};

struct ChangedDontAttackListType { //嘿student挡篶
    char IsUsed;
    std::string name;
    char OriginVal;
    __uint64_t FXNpcGroupDataID;
    __uint64_t GameRecord2_Npc2;
    
};

struct ActorProxyType { //
    char IsUsed;
    __uint64_t ActorProxyPointer;
    __uint64_t ActorPtr;
    char Type;   // 0 = player 1=monster 2=NPC 4=Pet
    int Lv;
    int NowHP;
    int MaxHP;

    int IsStaticNPC;
    int IsAttackMe;
    int IsPlayer;
    __uint64_t ObjectID;
    __uint64_t QuestNPCID;
    int ObjectSerial;
    int IsBoss;
    int IsNpc;
    int NpcType;
    int MonsterGrade;

    __uint64_t TargetPtr;
    float XCoor;
    float YCoor;
    float ZCoor;
    char Targetname[100];
    char name[300];
    char Guildname[500];
    char NameInArray[301];
};

struct EffectDataType EffectData[1001];
struct PriortyAttackListType PriortyAttackList[1001];
struct PriortyAttackListType DontAttackList[1001];
struct PriortyAttackListType ReactDontAttackList[1001];
struct PriortyAttackListType DontPickItemList[1001];
struct PriortyAttackListType OnlyPickItemList[1001];
struct ChangedDontAttackListType ChangedDontAttackList[3001];
struct ActorProxyType ActorList[1501];

struct FMemeryType PriortyAttackFMem;

//int PriortyAttackBuff[1501];

__int64_t PriortyAttackBuffAddr = 0;
__int64_t PriortyAddAttackBuffAddr = 0;
int PriortyAttackBuffCount = 0;


int DontAttackListCount = 0;
int ReactDontAttackListCount = 0;
int PriortyAttackListCount = 0;
int DontPickItemListCount = 0;
int OnlyPickItemListCount = 0;


int ReactDontAttackSwitch = 0;
int DontAttackSwitch = 0;
int PriorityAttackSwitch = 0;
int DontPickItemSwitch = 0;
int OnlyPickItemSwitch = 0;


char buf[3000];
char Largebuf[160000];
char Resultbuf[160000];
char SavedClickUI[10000];
char GlobalResult[3000];
int LargebufSize = 159999;
int ResultbufSize = 159999;
int SavedClickUISize = 10000;


float ScreenX = 0;
float ScreenY = 0;
int IsBotEnded = 0;
int CheckPatchSystemBox = 0;

int NeedGetUI = 1;
int GettingUI = 0;
int IsDoingmemcmp = 0;

int EverClosedHook = 0;
int UiPanelCount = 0;
int PanelListCount = 0;
bool end_Healing = false;
int IsPK = 0;
int EffectMaxCount = 0;

Json::Value GlobalSendRoot;

float RandomVal = 60;
__uint64_t GlobalTmpVal;
__uint64_t LastCallingFunTime;
__uint64_t AttackerPlayerID = 0;
std::string AttackerPlayerIDStr = "";

//PlayerInfo
double CurrentExp = 0;
double MaximumExp = 0;
int CurrentLv = 0;
char CurrentMapName[300];
char CurrentPlayerName[300];
char CurrentServerName[300];
char CurrentTargetName[300];
char PKTargetName[300];

__int64_t MapIndex = 0;
char MapName[100];
char MyMapName[401];
char MyZoneName[401];



int MyHp = 0;
int MyMaxHp = 0;
int MyMp = 0;
int MyMaxMp = 0;

int AttackerHp = 0;
int AttackerMaxHp = 0;
int AttackerMp = 0;
int AttackerMaxMp = 0;

int PKAttackerHp = 0;
int PKAttackerMaxHp = 0;
int PKAttackerMp = 0;
int PKAttackerMaxMp = 0;

int MaxItemCount = 0;
int NowItemCount = 0;

int CallResult = 0;
int RealIndexReturn = -1;
int IsFollowPartyLeader = 0;


__int64_t MyMoney = 0;
__int64_t MyDiamond = 0;

__int64_t MyOtherMoney2 = 0;
__int64_t MyOtherMoney3 = 0;
__int64_t MyOtherMoney4 = 0;
__int64_t MyOtherMoney5 = 0;
__int64_t MyOtherMoney6 = 0;
__int64_t MyOtherMoney7 = 0;
__int64_t MyOtherMoney8 = 0;
__int64_t MyOtherMoney9 = 0;
__int64_t MyOtherMoney10 = 0;
__int64_t MyOtherMoney11 = 0;
__int64_t MyOtherMoney12 = 0;
__int64_t MyOtherMoney13 = 0;
__int64_t MyOtherMoney14 = 0;
__int64_t MyOtherMoney15 = 0;
__int64_t MyOtherMoney16 = 0;
__int64_t MyOtherMoney17 = 0;
__int64_t MyOtherMoney18 = 0;
__int64_t MyOtherMoney19 = 0;
__int64_t MyOtherMoney20 = 0;
__int64_t MyOtherMoney21 = 0;
__int64_t MyOtherMoney22 = 0;
__int64_t MyOtherMoney23 = 0;

int RecordCursorX = 0;
int RecordCursorY = 0;

int IsMoving = 0;
int isAutoBattle = 0;
int AutoPlayState = 0;

__int64_t NowTargetID = 0;
int IsFighting = 0;
int IsShowActionButton = 0;

int BagItemCount = 0;
int StorageItemCount = 0;

unsigned int MainThreadTid = 0;
__int64_t LastHelperThreadTime = 0;
__uint64_t LastCallingFunTime2 = 0;

int IsCallingFunStarted = 0;
int IsCallingFun = 0;
int IsStopGetUi = 0;
int IsGameHooked = 0;
int IsPassGameHooked = 0;

int IsGameVersionPass = 0;
int StartCallFunction = 0;
int NeedHelperSelect = 0;


__uint64_t LastConnectTime;

int IsHelperFunctioning = 0;
int IsHandlingCommand = 0;

int IsNeedHyperRun = 0;

__int64_t FakePara1 = 0;
__int64_t FakePara2 = 0;
__int64_t FakePara3 = 0;
__int64_t FakePara4 = 0;
std::string FakeObject = "";

struct CoorType DestCoor;
time_t Globaltimestamp_sec;

std::string GlobalResultStr;

std::string InviteMemberName = "";

float MyXCoor = 0;
float MyYCoor = 0;
float MyZCoor = 0;
int MyMapID = -1;
__int64_t MyZoneID = -1;
int MyZoneType = -1;

std::vector<uint64> GlobalAddressBegin;
std::vector<uint64> GlobalAddressSize;
std::vector<int> GlobalAddressCanRead;


void WaitMainThreadDone();
void WaitMainThreadDone2();

void InitFMem(struct FMemeryType* TmpMem) {
    TmpMem->A = 0;
    TmpMem->B = 0;
    TmpMem->C = 0;
    TmpMem->D = 0;
    TmpMem->E = 0;
    TmpMem->F = 0;
}

void InitFMem2(struct FMemeryType* TmpMem) {
    TmpMem->A = 0;
    TmpMem->B = 0;
    TmpMem->C = 0;
    TmpMem->D = 0;
    TmpMem->E = 0;
    TmpMem->F = 0;
}


void InitFMem3(struct FMemeryType* TmpMem) {
    TmpMem->A = 0;
    TmpMem->B = 0;
    TmpMem->C = 0;
    TmpMem->D = 0;
    TmpMem->E = 0;
    TmpMem->F = 0;
}



void InitGMem(struct GMemeryType* TmpMem) {
    TmpMem->A = 0;
    TmpMem->B = 0;
    TmpMem->C = 0;
    TmpMem->D = 0;
    TmpMem->E = 0;
    TmpMem->F = 0;
    TmpMem->G = 0;
    TmpMem->H = 0;
    TmpMem->I = 0;
}



#ifdef _WIN64
#define WRAP uint64_t
#else
#define WRAP uint32_t
#endif

void* addr(void* address, WRAP offset)
{
    return (void*)((WRAP)address + offset);
}

uint32_t rU32(void* address, WRAP offset)
{
    if (address)
    {
        if (IsBadReadPtr(addr(address, offset), 4) == false)
        {
            return *(uint32_t*)(addr(address, offset));
        }
    }

    return 0;
}


uint32_t rU32(uint64_t address, WRAP offset)
{
    if (address)
    {
        if (IsBadReadPtr(addr((void*)address, offset), 4) == false)
        {
            return *(uint32_t*)(addr((uint64_t*)address, offset));
        }
    }

    return 0;
}

uint64_t rU64(uint64_t address, WRAP offset)
{
    if (address)
    {
        if (IsBadReadPtr(addr((void*)address, offset), 8) == false)
        {
            return *(uint64_t*)(addr((uint64_t*)address, offset));
        }
    }

    return 0;
}

uint8_t rU8(void* address, WRAP offset)
{
    if (address)
    {
        if (IsBadReadPtr(addr(address, offset), 1) == false)
        {
            return *(uint8_t*)(addr(address, offset));
        }
    }

    return 0;
}

int utf8_strlen(const std::string str)
{
    int c, i, ix, q;
    for (q = 0, i = 0, ix = str.length(); i < ix; i++, q++)
    {
        c = (unsigned char)str[i];
        if (c >= 0 && c <= 127) i += 0;
        else if ((c & 0xE0) == 0xC0) i += 1;
        else if ((c & 0xF0) == 0xE0) i += 2;
        else if ((c & 0xF8) == 0xF0) i += 3;
        //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
        //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
        else return 0;//invalid utf8
    }
    return q;
}
static uint oem_code(uint key) {
    short code[256] = { 0 };
    code['q'] = 0x10; code['a'] = 0x1e;
    code['w'] = 0x11; code['s'] = 0x1f;
    code['e'] = 0x12; code['d'] = 0x20;
    code['r'] = 0x13; code['f'] = 0x21;
    code['t'] = 0x14; code['g'] = 0x22;
    code['y'] = 0x15; code['h'] = 0x23;
    code['u'] = 0x16; code['j'] = 0x24;
    code['i'] = 0x17; code['k'] = 0x25;
    code['o'] = 0x18; code['l'] = 0x26;
    code['p'] = 0x19; code[':'] = 0x27; code[';'] = 0x27;

    code['z'] = 0x2c;
    code['x'] = 0x2d;
    code['c'] = 0x2e;
    code['v'] = 0x2f;
    code['b'] = 0x30;
    code['n'] = 0x31;
    code['m'] = 0x32;
    return code[key & 0xffu];

}
int  My_SendMessagew(HWND a1, UINT a2, WPARAM a3, LPARAM a4)
{
    //   MEMORY[0x7FFF80EC27C0](0i64, L"Window Registration Failed!", L"Error!", 48i64);  奻醱    v64[1] = (__int64)sub_7FF7A06F9B80;
    //ULONG64 ProcessDeferredMessage = 0x7FF6F35CAE00 ;
    return fake_SendMessagew(a1, a2, a3, a4);

}

void* rP(void* address, WRAP offset)
{
    if (address)
    {
        if (IsBadReadPtr(addr(address, offset), 8) == false)
        {
            return *(void**)addr(address, offset);
        }

    }
    return 0;
}

void ToLowerCase(char* s)
{
    while (*s)
    {
        *s = tolower(*s);
        s++;
    }
}