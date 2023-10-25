#pragma once

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;


//20231025


__int64_t _ZN8B2Client8instanceE = 0x5D6C458; //OK
__uint64_t _GameThreadTid = 0x5E322A8;
__int64_t _EnginePtr = 0x5FC7300; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x38C8600; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1D61380;

__int64_t _ZN7FMemory4FreeEPv = 0x1C6DC70;
__int64_t _ZNK5FText8ToStringEv = 0x1CC0650;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E42070;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E46DF0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1F239E0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1F3EDD0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2E4B940;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2E483F0;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2DF64F0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2EAA910; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2E45FB0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E88960;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x34B7B60;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2E1F070;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2E1F330;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2E1F530;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x38DCC50;

__int64_t _ZN5Item212GetItemGradeEy = 0xC0D820;

__int64_t _ZN5Item211GetItemNameEy = 0xC0DE10;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA4B080;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA4B4B0;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2E45550;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1F3E830;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC0B006;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13FBBC0;

__int64_t _ClosePanelStartAddr = 0x5D94000; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x14005D0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x1410AF0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x15B8890;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E61000;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x21B6100;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB09880;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x32A0F70;

__int64_t _ZN4Game9FindAgentEy = 0xB14FF0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB276A0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA4B9A0;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xDEAD70;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x1503490;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x119A370;
__int64_t _ZN8Tutorial3EndEbb = 0xE88940;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB4E470;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD4DEA0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD4DCB0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9E8B40;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA301C0;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA5F400;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA5F680;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA59A00;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA2F390;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCC9790;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBC16B0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB1A6C0;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA4C490;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC9F920;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x32A0A90;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCBE610;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB45350;
__int64_t _ZN4Game10PickTargetEyb = 0xB2D140;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x32B2D80;
__int64_t __GetFB2ScalabilityController = 0x313B450;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA2C6C0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFBACC0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE2F410;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE22B90;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE0E6F0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x128B430;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x1270B90;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x99B8C0;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xADCFD0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE67AC0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA4D6A0;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x1145110; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x1621C10;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x11D1A80;

__int64_t OFF_ProcessDeferredMessage = 0x1F78890;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x68DFB0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x38DB270; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA71530;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x99B770;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB29BC0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA6FC80;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9FD110;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2ED41E0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3989390;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x398C0F0;




/*


//20231018


__int64_t _ZN8B2Client8instanceE = 0x5D5AA78; //OK
__uint64_t _GameThreadTid = 0x5E20768;
__int64_t _EnginePtr = 0x5FB5838; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x38B4890; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1D4C990;

__int64_t _ZN7FMemory4FreeEPv = 0x1C59280;
__int64_t _ZNK5FText8ToStringEv = 0x1CABC60;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E2E010;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E32D90;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1F0EF40;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1F2A330;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2E378E0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2E34390;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2DE2490;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E968B0; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2E31F50;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E74900;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x34A3E20;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2E0B010;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2E0B2D0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2E0B4D0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x38C8EE0;

__int64_t _ZN5Item212GetItemGradeEy = 0xC05450;

__int64_t _ZN5Item211GetItemNameEy = 0xC05A40;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA43720;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA43B50;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2E314F0;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1F29D90;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC02C36;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13EB440;

__int64_t _ClosePanelStartAddr = 0x5D82550; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13EFE00;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x14001F0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x15A6570;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E4CFA0;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x21A1630;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB01D30;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x328D2A0;

__int64_t _ZN4Game9FindAgentEy = 0xB0D120;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB1F6C0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA44040;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xDE2700;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14F1240;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x1189310;
__int64_t _ZN8Tutorial3EndEbb = 0xE7F610;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB46420;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD45960;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD45770;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9E1990;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA28860;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA57AA0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA57D20;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA520A0;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA27A30;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCC1260;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBB9360;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB12880;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA44B30;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC973F0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x328CDC0;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCB60E0;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB3D300;
__int64_t _ZN4Game10PickTargetEyb = 0xB25160;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x329F0B0;
__int64_t __GetFB2ScalabilityController = 0x3127160;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA24D60;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFAF8F0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE26A70;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE1A1F0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE05F90;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x127A3D0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x125FB30;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x994930;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAD53B0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE5E940;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA45D40;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x11340B0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x160F800;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x11C0A20;

__int64_t OFF_ProcessDeferredMessage = 0x1F63DF0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x6892D0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x38C7500; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA699F0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9947E0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB21BE0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA68140;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9F5F60;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2EC0180;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3975420;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3979460;







*/




char FMemoryFreeArray[] = { 0x48 ,0x85 ,0xC9 ,0x74, 0x2E, 0x53, 0x48, 0x83 };



__uint64_t _ZN9AutoPlay214setCommonParamEPKch = 0x0891D90;//無用
__uint64_t __UpdateAutoBattleUIAndMessage = 0x008924B0; //無用


__uint64_t _ZN4Game14AutoPlayAttackEv = 0x0923CD0;//ICharacter::SetNameText
__uint64_t _ZN9AutoPlay212SingleCombatEv = 0x0085B470;
__uint64_t _ZN4Game12UnlockTargetEv = 0x000947990;//
__uint64_t _ZN4Game20AutoPlayAttackTargetEybb = 0x00923D60;//
__uint64_t _ZN4Game16SetPickedAgentIdEyb = 0x00923D60;//
__uint64_t _ZN9AutoPlay211SingleSkillEyh = 0x0088DFA0;//





//-------------------偏移--------------------------------------------
int IsDungeonOffset = 368;//AutoPlay2::MinimapMove      if ( v7[372] )

int GameUIOffset = 1424;// PlayerHero::SetShowVirtualJoystick  下面那個   Guild::OnRecvCancelGuildApplicationOk
int Game_Offset = 1376;// UI3DWorldMap::refreshMyPosIcon  下面那個
int IsPanel2OpenOffset = 2229;// 2225;// UIPanel2::IsOpen(__int64 a1)
int LoadingScreen_Offset = 1440;// B2Client::IsShowLoadingScreen


//int ICharacterNameOffSet = 4328;//ICharacter::SetNameText   //TArray<char16_t,TSizedDefaultAllocator<32>>::ResizeForCopy(v64 + 4328, (unsigned int)v66, v67);
int PKTargetOffset = 4344;// 4336;// 4312;// 4288;// 4272;// PlayerHero::SetCounterAttackableTargetId  425*8
int MaxHpOffset = 188;// 172;//AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
int NowHpOffset = 124;// 124;// 112;
int NowMpOffset = 128;// 124;// PlayerHeroDisplay::UpdateFocusBar
int MaxMpOffset = 2296 + 8;// 2240;// 2248;// 2248;// 1864;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
int MaxMpOffset2 = 248;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)

int AgentMaxMpOffset = 304;// 292;//AgentDisplay::UpdateFocusBar

int ICharacterOffset = 880;// 864;// 1040;//115 * 8 //AgentDisplay::UpdateFocusBar

int AgentOffset = 72;// 64;// 56;// 104;//UI3DWorldMap::refreshMyPosIcon
int PlayerHeroDisplayOffset = 368;// PlayerHero::GetPlayerHeroDisplay

int MoneyOffSet = 174 + 1;//PlayerHero::getMoney(PlayerHero *this, int a2)


int Game_IsAutoPlay_Offset1 = 1544;// 1464;// 1384;// 1376;// 171 * 8;// 1336; //Game::IsAutoPlay(__int64 a1)
int Game_IsAutoPlay_Offset2 = 433;// 425;



int MapID_Offset = 40;// 4 * 8;// AutoPlay2::SingleCombat(AutoPlay2 *this) AutoPlay2::setMoveParam(v11, v44[17],
int ZoneID_Offset = 5416;// 675 * 8;// 535 * 8;//UIMiniMapPanel::RefreshDistrictName;  
int ZoneName_Offset = 3088;// 3072;// 1952;//UIMiniMapPanel::setPlaceText     utf8_copy((char *)(v4 + 800), 256, v3);
int ZoneTypeOffset = 252;// 236; // Agent::IsInSafetyArea  Game::IsAvailablePk(Game *this) 

int GetAttackTargetId_Offset = 1640;// 1560;// 1480;// 1472;// 183 * 8;// 1432;//Game::GetAttackTargetId(__int64 a1)

int EquipSet_Offset = 1912;// 1888;// 1864;// 1848;//ItemHelper::FindItemFuncType    v39 = *(EquipSet **)(v34 + 1856);

int ShowActionButtonOffset = 3992;// 3976;// 2496; //UIActionMenuPanel6::IsShowActionButton(UIActionMenuPanel6 *this)
int QuestJournalOffset = 1784;// 1760;// 1736;// 1720;// 1728;// 1344; //UIQuestHudPanel::makeBulletinQuestDataIdList
int QuestSize =  120;// 120;// 14 * 8;  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)


int Bag2Offset = 1880;// 1856;// 1832;// 1816;// 1824;// 182 * 8; //UIItemDetailBasePanel::checkAttachableBead    v16 = *(_QWORD *)(v11 + 1824);
int Stash2Offset = 1896;// 1872;// 1848;// 1832;// 230 * 8;//PlayerHero::ReqChangeItemSlot

int TradeBagOffset = 4080;// 4064;// 2816; //UITradePanel::OnClickSlotButton  //_ZN10UITradeBag17OnClickSlotButtonEi向上一層
int UITradeBagItemCircularViewOffset = 152;// UITradeBag::OnClickSlotButton

int UIInventoryPanelTabIndexOffset = 2833;// 2817;//UIInventoryPanel2::OnClickItemSlotButton 下  //v46 = *((char *)this + 2817);    v46 = *((char *)this + 2817);    //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
int UIInventoryPanelStartAddressOffset = 2856;// 2840;//UIInventoryPanel2::OnClickItemSlotButton 下 //v47   v47 = *((_QWORD *)this + 355);    //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
int UIItemCircularViewOffset = 3088;// 3072;// 2056; //UIInventoryPanel2::ScrollToSpcificItemGridIndex   UIInventoryPanel2::OnClickItemSlotButton 下 UIItemCircularView::GetGridDataIndex((UIInventoryPanel2 *)((char *)v5 + 3072), v4);

int UISellItemCircularViewOffset = 4000; //  UICitizenShopPanel2::OnClickBagSlotButton 下 v25 = UIItemCircularView::GetGridDataIndex(v3 + 4000, v49);
int UISellInventoryPanelTabIndexOffset = 2860;//UICitizenShopPanel2::OnClickBagSlotButton 下    v24 = *(_BYTE *)(v3 + 2860);     if ( v24 >= 0 && *(_BYTE *)(v3 + 4240) > v24 )
int UISellInventoryPanelTabMaxOffset = 4240; //UICitizenShopPanel2::OnClickBagSlotButton 下    v24 = *(_BYTE *)(v3 + 2860);     if ( v24 >= 0 && *(_BYTE *)(v3 + 4240) > v24 )
int UISellInventoryPanelStartAddressOffset = 3016;//UICitizenShopPanel2::OnClickBagSlotButton 下     v26 = *(_QWORD *)(v3 + 3016);  v28 = Bag2::GetItemByInstanceId(v19, *(_QWORD *)(*(_QWORD *)(v27 + v26) + 8i64 * v25));


int ItemForgeUIOffset = 112;// 128; //GameUI::Initialize(GameUI *this)    v6 = (ItemForgeUI *)*((_QWORD *)v2 + 14);   UIItemForgePanel::OnClickedSkipUnsafeResultButton  

int EnterSleepModeOffSet = 3520;// 3504;// 3488;// 2272; //UISleepModePanel::Open  UISleepModePanel::SetSleepState(   *(_BYTE *)(v7 + 2264) = 1; 


int AutoMovePathOffset = 368;// 360; // AutoPlay2::MinimapMove(       if ( AutoMovePath::FindPath(v7 + 360, v7 + 36, 1LL) & 1 )
int PartyOffset = 1976;// 1952;// 1928;// 1912;// 1920;// 194 * 8;//UIPartyManagementPanel::onClickedSearcOkButton(__int64 result, const FName *a2)  1544

int TeamListSize = 1232;// Party::GetPartyMemberByHeroName


int Map3DPanelWrapperOffset = 10936;// 1327 * 8;//10616 1223 * 8; //UI3DWorldMap::removeImageIcon  9704
int UI3DWorldMapOffset = 2896;// 2880;// 1776; //UI3DMapPanel::ResetMapCenterToPlayer(UI3DMapPanel *this, unsigned __int16 a2)
int QuickSetBookOffset = 2104;// 2080;// 2056;// 2040;// //PlayerHero::SetUseAuto    UISignatureSkillPadPanel6::OnSwipeQuickSkillSlotButton  v32 = *(QuickSetBook **)(v39 + 1688);  QuickSetBook::SetUseAuto(v32, v33, v16, 0);





int NPCListMaxCountOffSet = 352;// 176;// 272; //  Game::snapshotHeroList     240;  Game::UpdateNpcAll

//int SkillOffset = 452; //AutoPlay2::arrived(AutoPlay2 *this, char a2)  result = AutoPlay2::SingleSkill(v5, *((_QWORD *)v5 + 51), *((_BYTE *)v5 + 452));
//int IsAttackFxOffset = 1040;//GameUI::StopAttackBtnFx(GameUI *this)      v3 = *(unsigned int **)(*(_QWORD *)this + 1040LL);

int Npc2nameOffset = 1064;// 1056;// 744;// Npc::GetRecordName@<GameRecord2::Npc2::name((GameRecord2::Npc2 *)(result + 744));
int NpcGetRecordNameOffset = 4296;// 4288;// 880; // Npc::GetRecordName
int NpcGradeOffset = 252;// 236; //GameRecord2::Npc2::grade(GameRecord2::Npc2 *this)


int NpcIsVisibleOffset = 1058;// 1042;// 1330;// 1178;//Npc::IsVisible
int IsPlayerOffset = 1328;// 1320;// 968; // UIPartyManagementPanel::makeInviteHeroListByFilteringZone    if ( v23 && *(_BYTE *)(v23 + 960) != 1 )      if ( v23 && *(_BYTE *)(v23 + 960) != 1 )


int UI3DWorldMapIconMaxOffSet = 9840;// 9520;// 288; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)    v21 = *(_DWORD *)(v19 + 288);
int UI3DWorldMapIconStartOffSet = UI3DWorldMapIconMaxOffSet - 72;// 216; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)   v18 = *(_QWORD *)(v15 + 216);

int UIChatMainOffset = 2856;// 2840;// 1720;  //UIChatPanel3::OnModifiedWriteBox(UIChatPanel3 *this, const FName *a2)

int SkillContext6Offset = 4328;// 4320;// 4296;// 4272;// 4256;// 4248;// 4240;// 4008;// 3416; //Game::GetSkillContext6 v3 = *(_QWORD *)(v2 + 4176);
int HyperRunController_Offset = 4312;// 4304;// 4280;// 4256;// 4240;// 4232;// 4224;// 3992;// 3384; //Game::GetHyperRunController@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)

int EquipCollectionBookOffset = 1848;// 1824;// 1800;// 1784;// 224 * 8;//UIEquipCollectionPanel::RefreshAll(__int64 result, char a2)  v19 = (int *)v11[177];
int StorageShopUnknownOffset = 2832;// 354 * 8;//2832 UIStashPanel::OnClickMoveToStashButton     Bag2::RequestMoveToStash(v162, *((_QWORD *)v6 + 352), (__int64)&v171, &v176);
//int SellShopUnknownOffset = 3912;//UIBuySellItemPopupPanel::onClickedOkButton     Bag2::RequestSellItem2(v17, v30, v31, *(signed __int16 *)(v5 + 3840), 1);


int MsgObj_HeroGuildOffset = 1232;  //Hero::SetGuild(Hero *this, const MsgObj::GuildBroadcast *a2)      v7 = (char *)this + 1192;  v8 = (_QWORD*)(v6 & 0xFFFFFFFFFFFFFFFELL);
//int GuildTextOffset = 4696;  //ICharacter::SetGuildText
int GuildTextOffset1 = 1200; //ICharacter::SetGuildText 之上  HeroDisplay::UpdateNamePlate
int GuildTextOffset2 = 1256; //ICharacter::SetGuildText 之上  HeroDisplay::UpdateNamePlate




int GameCameraOffset = 1144;// Game::CameraReset
int SetCameraOffset = 256;// Game::CameraReset

int EffectBoardOffset = 672; //UIHudPlayerInfoPanel::RefreshEffectList  v49 = *(EffectBoard **)(result + 672);

int IsFollowPartyLeaderOffset = 3608;// 3584;// 3560;// 3544;// 3536; //PlayerHero::IsFollowPartyLeader   //Game::SetAttackTargetId
int GameRecord2_Npc2_CannotBeTargetedOffSet = 504; //GameRecord2::Npc2::CannotBeTargeted



//int SkipUnsafeOffset = 2328; //未找到ItemForgeUI::ToggleSkipUnsafeResult(__int64 a1, UIItemForgePanel **a2)   UIItemForgePanel::OnClickedSkipUnsafeResultButton
int UIPanelMax = 0x7E + 6 + 1;  //+1是DimPanel  //Tutorial::getPanelTypeByUIPanel   ////UIPanelManager::ClosePanel 中 考慮改UIPanelManager::ClosePanel  的做法



int CoorOffset = 28 * 4;// 24 * 4; //Agent::GetPos(Agent *this, float *a2, float *a3, float *a4)
int ImageNamePathOffset = 368;// 360; //UImage::SetBrushFromTextureDynamic // if ( *(UTexture2DDynamic **)(result + 360) != a2 )
int SRichTextBlockOffSet = 223 * 8;// 222 * 8; //URichTextBlock::SetText(URichTextBlock *this, const FText *a2) result = (SRichTextBlock *)*((_QWORD *)v2 + 223);
int SRichTextBlockTextOffSet = 680; //SRichTextBlock::SetText     FText::operator=((_QWORD *)(a1 + 680), a2);
int ButtonIconNameOffset = 368; //參考UTSWidgetSlot_Skill::SetButtonIcon 46*8  // /    v17[72] != v12 ) 4 72
int STableViewBaseOffset = 52 * 8;// 51 * 8; //UListViewBase::SetScrollOffset

//int LoopListViewOffSet = 536;// ITypedUMGListView<UObject *>::GetEntryWidgetFromItem<ULHWidget>((__int64)v10 + 536, &v19); ULHWidget::ActivateTouchMaskRecursive(ULHWidget *this, const UQuestTouchMaskRecord *a2)
int UCircularView_GetCustomDisplayedEntryWidgetsOffset = 872 - 8;// UCircularView::GetDisplayedWidgetsNum - 8





std::string UIInventoryPanelName = "bpBagPanel2";
std::string TradePanelName = "bpTrade";
std::string UIMiniMapPanelName = "bpRadarMobile";
std::string UI3DWorldMapName = "bp3DMap";
std::string UIActionMenuPanel6Name = "bpActionMenuMobile";
std::string UIChatPanel3PanelName = "UIChatPanel3";
std::string SleepModeTypePanelName = "UISleepModePanel";
std::string SleepModeTypePanel2Name = "bpSleepModePlayerInfoMobile";

std::string ShopPanel2Name = "bpShopPanel2";


//int UIInventoryPanelID = 9;// 13; //Bag2::notifyUIRemoveItem(Bag2 *this, __int16 a2)
int UIMiniMapPanelType = 23;// 29;  //UIMiniMapPanel::GetPanelType()
int IsGetUIMiniMapPanelType = 0;
//int UI3DWorldMapType = 24;// 30; //  UI3DMapPanel::GetPanelType(#1243 *this)
//int UIActionMenuPanel6Type = 26;// 32;  //UIActionMenuPanel6::GetPanelType()
int UIChatPanel3PanelType = 40;// 46; //UIChatPanel3::GetPanelType(UIChatPanel3 *this)
int IsGetUIChatPanel3PanelType = 0;
//int TradePanelID = 111;// 117;  //UITradeItemList::OnClickSlotForFavarites(UITvradeItemList * this, const FName * a2)
//int SleepModeType = 120;// 125; //UISleepModePanel::GetPanelType(UISleepModePanel *this)  UISleepModePanel::OnClosePanel()
//int SleepModeType2 = 121;// 126;  //UISleepModePanel::OnClosePanel()
//int UIStashPanelType = 13; //UIStashPanel::GetPanelType




//int TradeBagItemStartOffset = 95 * 4; //UIItemGridWidget::ReceiveTabEventItemSlot2
//int TradeBagItemCountOffset = 400; // UIItemGridWidget::ReceiveTabEventItemSlot2(UIItemGridWidget *this, const FName *a2, UIItemSlot **a3, UIItemGridInterface *a4)
//int TradeBagItemGridSize = 848;// UIItemGridWidget::ReceiveTabEventItemSlot2 v7 = 824

//int UIInventoryViewBagCanvasOffset = 1808; //UIInventoryPanel2::OnClickItemSlotButton  ??
//int UIItemGridWidgetOffset = 168; //UIInventoryViewBagCanvas::OnClickItemSlotButton(__int64 a1, __int64 *a2, const FName *a3)  ??




//-------------------GameFuntion--------------------------------------------


__uint64_t UWidgetTree_FindWidgetParent(__uint64_t thisa, __uint64_t a2, __uint64_t a3) {

    __uint64_t* v3; // x8
    __int64 v4; // x9
    __int64 result; // x0
    __int64 v6; // x10
    __int64 v7; // x9
    __uint64_t* v8; // x12

    v3 = (__uint64_t*)thisa;
    v4 = *((__uint64_t*)thisa + 5);
    if (v4)
    {
        result = *(__uint64_t*)(v4 + 40);
        if (result)
        {
            v6 = *(signed int*)(result + 272);
            if ((signed int)v6 < 1)
            {
            LABEL_9:
                v7 = -1;
            }
            else
            {
                v7 = 0LL;
                while (1)
                {
                    v8 = *(__uint64_t**)(*(__uint64_t*)(result + 264) + 8 * v7);
                    if (v8)
                        v8 = (__uint64_t*)*((__uint64_t*)v8 + 6);
                    if (v8 == v3)
                        break;
                    if (++v7 >= v6)
                        goto LABEL_9;
                }
            }
            *(int*)a2 = v7;
        }
        else
        {
            *(int*)a2 = 0;
        }
    }
    else
    {
        result = 0LL;
        *(int*)a2 = 0;
    }
    return result;

}

__int64 __fastcall Item2__GetItemTypeInner(__int64_t Tmpthis)
{
    __int64_t v2; // x19
    __int64 v3; // x0
    __int64_t result; // x0
    if (!Tmpthis)
        return 0LL;
    v2 = Tmpthis;
    v3 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Tmpthis + 56))(Tmpthis);

    return v3;
}

int __fastcall Item2__GetItemType(__int64_t Tmpthis)
{
    __int64 v1; // x0
    unsigned int v3; // w8
    unsigned int v4; // w8

    v1 = Item2__GetItemTypeInner(Tmpthis);
    if ((unsigned __int64)(v1 - 1000000) < 0xF4240)
        return 1LL;
    v3 = 2;
    if ((unsigned __int64)(v1 - 2000000) < 0xF4240 || (unsigned __int64)(v1 - 3000000) < 0xF4240)
        return v3;
    if ((unsigned __int64)(v1 - 4000000) < 0xF4240)
        return 4;
    if ((unsigned __int64)(v1 - 5000000) < 0xF4240)
        return 3LL;
    if ((unsigned __int64)(v1 - 6000000) < 0xF4240)
        return 7LL;
    if ((unsigned __int64)(v1 - 7000000) < 0xF4240)
        return 6LL;
    if ((unsigned __int64)(v1 - 9000000) >= 0xF4240)
        v4 = 0;
    else
        v4 = 5;
    return v4;
}


__int64_t __fastcall Item2__CastGroceryItem(__int64_t Tmpthis, const __int64_t a2)
{
    __int64_t v2; // x19
    __int64 v3; // x0
    __int64_t result; // x0
    bool v5; // cf
    bool v6; // cf
    bool v7; // cf
    bool v8; // cf
    bool v9; // cf
    bool v10; // cf

    if (!Tmpthis)
        return 0LL;
    v2 = Tmpthis;
    v3 = Item2__GetItemTypeInner(Tmpthis);
    if ((unsigned __int64)(v3 - 1000000) < 0xF4240)
        return 0LL;
    if ((unsigned __int64)(v3 - 3000000) >= 0xF4240)
        v5 = (unsigned __int64)(v3 - 2000000) >= 0xF4240;
    else
        v5 = 0;
    if (v5)
        v6 = (unsigned __int64)(v3 - 4000000) >= 0xF4240;
    else
        v6 = 0;
    if (v6)
        v7 = (unsigned __int64)(v3 - 5000000) >= 0xF4240;
    else
        v7 = 0;
    if (v7)
        v8 = (unsigned __int64)(v3 - 6000000) >= 0xF4240;
    else
        v8 = 0;
    if (v8)
        v9 = (unsigned __int64)(v3 - 7000000) >= 0xF4240;
    else
        v9 = 0;
    if (v9)
        v10 = (unsigned __int64)(v3 - 9000000) >= 0xF4240;
    else
        v10 = 1;
    if (v10)
        result = 0LL;
    else
        result = v2;
    return result;

}


__int64_t __fastcall Item2__CastEquipItem(__int64_t Tmpthis, const __int64_t a2)
{
    __int64_t v2; // x19
    __int64 v3; // x0
    __int64_t result; // x0
    bool v5; // cf
    bool v6; // cf
    bool v7; // cf
    bool v8; // cf

    if (!Tmpthis)
        return 0LL;
    v2 = Tmpthis;
    v3 = Item2__GetItemTypeInner(Tmpthis);
    if ((unsigned __int64)(v3 - 1000000) < 0xF4240)
        return 0LL;
    if ((unsigned __int64)(v3 - 3000000) >= 0xF4240)
        v5 = (unsigned __int64)(v3 - 2000000) >= 0xF4240;
    else
        v5 = 0;
    if (v5)
        v6 = (unsigned __int64)(v3 - 4000000) >= 0xF4240;
    else
        v6 = 0;
    if (v6)
        v7 = (unsigned __int64)(v3 - 5000000) >= 0xF4240;
    else
        v7 = 0;
    if (v7)
        v8 = (unsigned __int64)(v3 - 6000000) >= 0xF4240;
    else
        v8 = 0;
    if (v8)
        result = 0LL;
    else
        result = v2;
    return result;
}



__int64_t __fastcall Item2__CastDressItem(__int64_t Tmpthis, const __int64_t a2)
{
    __int64 v2; // x19
    __int64 v3; 
    __int64_t result = Tmpthis;
    if (result)
    {
        v2 = result;
        v3 = Item2__GetItemTypeInner(Tmpthis);
        if ((v3 - 1000000) >= 0xF4240)
            result = 0LL;
        else
            result = v2;
    }
    return result;
}

__int64_t __fastcall Item2__CastBeadItem(__int64_t Tmpthis, const __int64_t a2)
{
    __int64_t v2; // x19
    __int64 v3; // x0
    __int64_t result; // x0
    bool v5; // cf
    bool v6; // cf
    bool v7; // cf
    bool v8; // cf
    bool v9; // cf

    if (!Tmpthis)
        return 0LL;
    v2 = Tmpthis;
    v3 = Item2__GetItemTypeInner(Tmpthis);
    if ((unsigned __int64)(v3 - 1000000) < 0xF4240)
        return 0LL;
    if ((unsigned __int64)(v3 - 3000000) >= 0xF4240)
        v5 = (unsigned __int64)(v3 - 2000000) >= 0xF4240;
    else
        v5 = 0;
    if (v5)
        v6 = (unsigned __int64)(v3 - 4000000) >= 0xF4240;
    else
        v6 = 0;
    if (v6)
        v7 = (unsigned __int64)(v3 - 5000000) >= 0xF4240;
    else
        v7 = 0;
    if (v7)
        v8 = (unsigned __int64)(v3 - 6000000) >= 0xF4240;
    else
        v8 = 0;
    if (v8)
        v9 = (unsigned __int64)(v3 - 7000000) >= 0xF4240;
    else
        v9 = 1;
    if (v9)
        result = 0LL;
    else
        result = v2;
    return result;
}


__int64 __fastcall GameRecord2_Reward2Data_id(__int64* Tmpthis)
{
    __int64 result; // x0

    if (*(__int64*)Tmpthis)
        result = **(__int64**)Tmpthis;
    else
        result = 0LL;
    return result;
}

unsigned int __fastcall GameRecord2_EquipCollection_id(__uint64_t* Tmpthis)
{
    unsigned int result; // x0

    if (*(__uint64_t*)Tmpthis)
        result = **(unsigned int**)Tmpthis;
    else
        result = 0LL;
    return result;
}


__int64* __fastcall GameRecord2_EquipmentData2_discomposedReward(__int64_t* Tmpthis)
{
    if (!*(__int64_t*)Tmpthis)
        return 0;
    if (*(__int64_t*)(*(__int64_t*)Tmpthis + 56LL))
        return *(__int64_t**)(*(__int64_t*)Tmpthis + 56LL);
    return 0;
}

__int64_t* EquipItem__GetGameRecord2_EquipmentData2(__int64_t Tmpthis)
{
    __int64_t* v1; // x0
    __int64 v2; // t1
    __int64* v3; // x0

    v2 = *((__int64_t*)Tmpthis + 31);
    v1 = (__int64_t*)((char*)Tmpthis + 248);
    if (!v2) {
        return 0LL;
    }
    return v1;
}


bool __fastcall EquipItem__IsDisassemble(__int64_t Tmpthis)
{
    __int64_t* v1; // x0
    __int64 v2; // t1
    __int64* v3; // x0

    v1 = EquipItem__GetGameRecord2_EquipmentData2(Tmpthis);
    if (!v1)
        return 0LL;
    v3 = GameRecord2_EquipmentData2_discomposedReward(v1);
    return (bool)(GameRecord2_Reward2Data_id((__int64*)v3) != 0);
}


__int64_t GameRecord2__EquipmentData2__equipSlot(__int64_t Tmpthis)
{
    __int64 result; // x0

    if (*(__int64_t*)Tmpthis)
        result = *(unsigned __int8*)(*(__int64_t*)Tmpthis + 64LL);
    else
        result = 0LL;
    return result;

}


__int64_t GameRecord2_EquipmentData2_itemSubType(__int64_t Tmpthis)
{
    __int64 result; // x0

    if (*(__int64_t*)Tmpthis)
        result = *(unsigned __int8*)(*(__int64_t*)Tmpthis + 49LL);
    else
        result = 0LL;
    return result;

}



bool __fastcall EquipItem__GetEquipSlotType(__int64_t Tmpthis)
{
    __int64_t* v1; // x0
    __int64 v2; // t1
    __int64_t v3; // x0

    v1 = EquipItem__GetGameRecord2_EquipmentData2(Tmpthis);
    if (!v1)
        return 0LL;
    v3 = GameRecord2__EquipmentData2__equipSlot((__int64_t)v1);
    return v3;
}

__int64_t __fastcall EquipItem__GetWeaponType(__int64_t Tmpthis)
{
    __int64_t* v1; // x0
    __int64 v2; // t1
    __int64_t v3; // x0

    v1 = EquipItem__GetGameRecord2_EquipmentData2(Tmpthis);
    if (!v1)
        return 0LL;
    v3 = GameRecord2_EquipmentData2_itemSubType((__int64_t)v1);
    return v3;
}








__int64* __fastcall GameRecord2_DressData2_discomposedReward(__int64_t* Tmpthis)
{
    if (!*(__int64_t*)Tmpthis)
        return 0;
    if (*(__int64_t*)(*(__int64_t*)Tmpthis + 64LL))
        return *(__int64_t**)(*(__int64_t*)Tmpthis + 64LL);
    return 0;
}

__int64* __fastcall GameRecord2_GroceryData_discomposedReward(__int64_t* Tmpthis) //GameRecord2::GroceryData::discomposedReward(GameRecord2::GroceryData *this)
{
    if (!*(__int64_t*)Tmpthis)
        return 0;
    if (*(__int64_t*)(*(__int64_t*)Tmpthis + 296LL))
        return *(__int64_t**)(*(__int64_t*)Tmpthis + 296LL);
    return 0;
}


__int64* __fastcall GameRecord2_BeadData_discomposedReward(__int64_t* Tmpthis)
{
    if (!*(__int64_t*)Tmpthis)
        return 0;
    if (*(__int64_t*)(*(__int64_t*)Tmpthis + 88LL))
        return *(__int64_t**)(*(__int64_t*)Tmpthis + 88LL);
    return 0;
}


bool __fastcall Dress2_IsDisassemble(__int64_t Tmpthis)
{
    __int64* v1; // x0

    v1 = GameRecord2_DressData2_discomposedReward((__int64*)((char*)Tmpthis + 96));


    return GameRecord2_Reward2Data_id((__int64*)v1) != 0;
}

bool __fastcall Bead2_IsDisassemble(__int64_t Tmpthis)
{
    __int64* v1; // x0
    __int64 v2; // t1
    bool result; // x0

    v2 = *((__int64_t*)Tmpthis + 9);
    v1 = (__int64_t*)((char*)Tmpthis + 72);
    if (v2)
        result = GameRecord2_BeadData_discomposedReward(v1) != 0LL;
    else
        result = 0LL;
    return result;
}


__int64 __fastcall GameRecord2_GroceryData_subKey(__int64_t Tmpthis) {
    __int64 result; // x0

    if (*(__int64_t*)Tmpthis)
        result = *(__int64_t*)(*(__int64_t*)Tmpthis + 24LL);
    else
        result = 0LL;
    return result;
}

__int64 __fastcall GameRecord2_GroceryData_subValue(__int64_t Tmpthis) {
    __int64 result; // x0

    if (*(__int64_t*)Tmpthis)
        result = *(__int64_t*)(*(__int64_t*)Tmpthis + 32LL);
    else
        result = 0LL;
    return result;
}


__int64_t __fastcall Grocery2_GetGameRecord2_GroceryData(__int64_t Tmpthis) {
    return (__int64_t)(Tmpthis + 88); // Grocery2::GetSubValue(Grocery2 *this)
}


__int64_t __fastcall Grocery2_GetSubKey(__int64_t Tmpthis) {

    __int64_t v1; // x0
    __int64 v2; // t1
    __int64 result; // x0

    v2 = *(__int64_t*)(Grocery2_GetGameRecord2_GroceryData(Tmpthis));
    v1 = Grocery2_GetGameRecord2_GroceryData(Tmpthis);
    if (v2)
        result = GameRecord2_GroceryData_subKey(v1);
    else
        result = 0LL;
    return result;
}

__int64_t __fastcall Grocery2_GetSubValue(__int64_t Tmpthis) {

    __int64_t v1; // x0
    __int64 v2; // t1
    __int64 result; // x0

    v2 = *(__int64_t*)(Grocery2_GetGameRecord2_GroceryData(Tmpthis));
    v1 = Grocery2_GetGameRecord2_GroceryData(Tmpthis);
    if (v2)
        result = GameRecord2_GroceryData_subValue(v1);
    else
        result = 0LL;
    return result;
}

bool __fastcall Grocery2_IsDisassemble(__int64_t Tmpthis)
{
    __int64* v1; // x0
    __int64 v2; // t1
    __int64* v3; // t1
    bool result; // x0

    v2 = *(__int64_t*)(Grocery2_GetGameRecord2_GroceryData(Tmpthis));
    v1 = (__int64*)Grocery2_GetGameRecord2_GroceryData(Tmpthis);
    if (v2) {
        v3 = (__int64*)GameRecord2_GroceryData_discomposedReward(v1);
        result =(GameRecord2_Reward2Data_id(v3) != 0);
    }
    else {
        result = 0LL;
    }
   
    return result;
}


bool __fastcall Tutorial_IsPlayingTutorial(__int64_t Tmpthis)
{
    bool result; // x0

    if (*((__int64_t*)Tmpthis + 2))
        result = 1LL;
    else
        result = *((__int64_t*)Tmpthis + 2) != 0;
    return result;
}




signed __int64 EquipCollectionBook_GetEquipCollection(__int64* Tmpthis, __int64 a2)//EquipCollectionBook::GetEquipCollection
{
    char* v2; // r10
    int v3; // eax
    __int64 v4; // r8
    signed __int64 v5; // rcx
    signed __int64 result; // rax

    DEBUG_PRINT("[+] EquipCollectionBook_GetEquipCollection Count =%lx   \n", *((signed int*)Tmpthis + 18) );

    if (*((int*)Tmpthis + 2) == *((int*)Tmpthis + 13))
        goto LABEL_15;
    v2 = (char*)Tmpthis + 56;
    if (*((__int64*)Tmpthis + 8))
        v2 = (char*)*((__int64*)Tmpthis + 8);
    v3 = *(int*)&v2[4 * ((*((signed int*)Tmpthis + 18) - 1i64) & ((signed int)a2 + 23 * HIDWORD(a2)))];
    if (v3 == -1)
        goto LABEL_15;
    v4 = *(__int64*)Tmpthis;
    while (1)
    {
        v5 = v4 + 56i64 * v3;
        if (*(__int64*)v5 == a2)
            break;
        v3 = *(int*)(v5 + 48);
        if (v3 == -1)
            return 0i64;
    }
    if (v3 == -1)
        LABEL_15:
    v5 = 0i64;
    result = v5 + 8;
    if (!v5)
        result = 0i64;
    return result;
}
