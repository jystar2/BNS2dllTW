#pragma once

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;

//20230823


__int64_t _ZN8B2Client8instanceE = 0x5CFD208; //OK
__uint64_t _GameThreadTid = 0x5DC0A68;
__int64_t _EnginePtr = 0x5F55A18; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x3865F60; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1CF9B10;

__int64_t _ZN7FMemory4FreeEPv = 0x1C06400;
__int64_t _ZNK5FText8ToStringEv = 0x1C58DE0;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DE1050;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DE5EC0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1EBBFB0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1ED73A0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2DEAA40;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2DE7460;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2D92090;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E47090; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2DE5080;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E28F70;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x34548F0;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2DBBA00;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2DBBCC0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2DBBEC0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x387A6F0;

__int64_t _ZN5Item212GetItemGradeEy = 0xBEB090;

__int64_t _ZN5Item211GetItemNameEy = 0xBEB670;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA33850;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA33C80;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2DE4530;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1ED6E00;

__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13A7420;

__int64_t _ClosePanelStartAddr = 0x5D22EA0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13ABDE0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x13BC1D0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1563420;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E03980;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x214E220;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAEC3E0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x323BF70;

__int64_t _ZN4Game9FindAgentEy = 0xAF76C0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB097F0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA34170;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD851A0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14ACD70;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x1128090;
__int64_t _ZN8Tutorial3EndEbb = 0xE5F470;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB303A0;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD23590;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD233A0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9D68B0;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA1BA80;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA46F30;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA471B0;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA41D00;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA1AC50;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCA3B20;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA3BC0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xAFCD10;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA34C60;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC7A100;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x323BA90;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xC98AA0;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB27370;
__int64_t _ZN4Game10PickTargetEyb = 0xB0F240;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x324DE60;
__int64_t __GetFB2ScalabilityController = 0x30D8190;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA188C0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF875B0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE06C00;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xDFCA20;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDEAD80;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1230FB0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x1210DE0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x98BA10;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAC0180;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE3F580;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA35E70;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10DC4D0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15CC870;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x115CB30;

__int64_t OFF_ProcessDeferredMessage = 0x1F10D80;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x67F900;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x3878D10; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA57CF0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x98B8F0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB0BDF0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA56810;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9EAF90;


__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E70960;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3927630;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x392AA50;











/*



//20230816


__int64_t _ZN8B2Client8instanceE = 0x5CFD188; //OK
__uint64_t _GameThreadTid = 0x5DC09A8;
__int64_t _EnginePtr = 0x5F55958; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x3866750; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1CF8B40;

__int64_t _ZN7FMemory4FreeEPv = 0x1C05420;
__int64_t _ZNK5FText8ToStringEv = 0x1C57E00;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DE0080;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DE4EF0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1EBAFE0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1ED63D0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2DE9A70;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2DE6490;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2D910C0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E460C0; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2DE40B0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E27FA0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x3453820;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2DBAA30;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2DBACF0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2DBAEF0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x387AEC0;

__int64_t _ZN5Item212GetItemGradeEy = 0xBEB900;

__int64_t _ZN5Item211GetItemNameEy = 0xBEBEE0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA33740;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA33B70;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2DE3560;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1ED5E30;

__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13A6710;

__int64_t _ClosePanelStartAddr = 0x5D22DE0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13AB0D0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x13BB4C0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x15626D0;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E029B0;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x214D250;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAEC5C0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x323AF30;

__int64_t _ZN4Game9FindAgentEy = 0xAF78A0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB099D0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA34060;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD85920;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14AC030;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x1127B50;
__int64_t _ZN8Tutorial3EndEbb = 0xE5FA50;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB30600;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD23D60;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD23B70;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9D6870;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA1B970;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA46DF0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA47070;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA41BC0;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA1AB40;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCA3B70;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA3E20;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xAFCEF0;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA34B50;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC7A150;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x323AA50;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xC98AF0;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB27550;
__int64_t _ZN4Game10PickTargetEyb = 0xB0F420;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x324CE20;
__int64_t __GetFB2ScalabilityController = 0x30D71C0;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA187B0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF87890;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE071E0;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xDFD000;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDEB360;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1230910;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x1210840;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x98BA50;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAC0120;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE3FB60;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA35D60;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10DBF90; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15CB8C0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x115C5F0;

__int64_t OFF_ProcessDeferredMessage = 0x1F0FDB0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x67F940;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x38794E0; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA57BB0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x98B930;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB0BFD0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA566D0;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E6F990;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3927E40;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x392B210;




//20230802


__int64_t _ZN8B2Client8instanceE = 0x5C92888; //OK
__uint64_t _GameThreadTid = 0x5D54B28;
__int64_t _EnginePtr = 0x5EE9AE8; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x380C5D0; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1CA1040;

__int64_t _ZN7FMemory4FreeEPv = 0x1BAD930;
__int64_t _ZNK5FText8ToStringEv = 0x1C00310;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2D88560;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2D8D3D0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1E634F0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1E7E8E0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2D91F50;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2D8E970;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2D395B0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2DEE6D0; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2D8C590;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2DD0480;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x33F9EF0;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2D62F10;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2D631D0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2D633D0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x3820D40;

__int64_t _ZN5Item212GetItemGradeEy = 0xBC9C60;

__int64_t _ZN5Item211GetItemNameEy = 0xBCA250;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA32920;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA32D50;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2D8BA40;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1E7E340;

__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13683F0;

__int64_t _ClosePanelStartAddr = 0x5CB7650; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x136CDB0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x137D110;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x151CC70;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2DAAE90;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x20F58B0;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAE4350;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x31E20E0;

__int64_t _ZN4Game9FindAgentEy = 0xAEF430;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB01470;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA33240;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD70720;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x146AE00;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x110F3A0;
__int64_t _ZN8Tutorial3EndEbb = 0xE45670;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB28150;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD10FE0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD10DF0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9D2010;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA18E70;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA46310;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA46590;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA41010;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA18040;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xC90F50;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA1910;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xAF4A90;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA33D30;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC65FF0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x31E1C00;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xC85610;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB1F180;
__int64_t _ZN4Game10PickTargetEyb = 0xB06FD0;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x31F3C80;
__int64_t __GetFB2ScalabilityController = 0x307F430;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA15CB0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF2ECD0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xDEF990;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xDE57B0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDD3B80;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x11FF060;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x11E4700;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x987BC0;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAB89E0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE25FF0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA34F40;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10BCA00;



__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15857E0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x1145EC0;

__int64_t OFF_ProcessDeferredMessage = 0x1EB82C0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x67C400;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x381F360; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA55170;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x987AA0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB03B80;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA53C90;


__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E17F00;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x38CDD90;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x38D11E0;



__int64_t _UWolrldPtr = 0x5EEE328;
__int64_t _ZN7UEngine29GetFirstLocalPlayerControllerEPK6UWorld = 0x380AF20;
__int64_t _ZN11AController18SetControlRotationERK8FRotator = 0x33489D0;



__int64_t _GameObject2_ClientConfig = 0x05C94E98;

__int64_t _ZN12DataManager319GetEffectManualDictEv = 0x987AA0;
__int64_t _EffectManualDict_GetEffectByIdEv = 0x0B03B80;




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
int IsPanel2OpenOffset = 2225;// UIPanel2::IsOpen(__int64 a1)
int LoadingScreen_Offset = 1440;// B2Client::IsShowLoadingScreen


int ICharacterNameOffSet = 4328;//ICharacter::SetNameText   //TArray<char16_t,TSizedDefaultAllocator<32>>::ResizeForCopy(v64 + 4328, (unsigned int)v66, v67);
int PKTargetOffset = 4272;// 4264;// 4256;// 4024;// PlayerHero::SetCounterAttackableTargetId  425*8
int MaxHpOffset = 188;// 172;//AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
int NowHpOffset = 124;// 124;// 112;
int NowMpOffset = 128;// 124;// PlayerHeroDisplay::UpdateFocusBar
int MaxMpOffset = 2240;// 2248;// 2248;// 1864;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
int MaxMpOffset2 = 248;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)

int AgentMaxMpOffset = 304;// 292;//AgentDisplay::UpdateFocusBar

int ICharacterOffset = 864;// 1040;//115 * 8 //AgentDisplay::UpdateFocusBar

int AgentOffset = 64;// 56;// 104;//UI3DWorldMap::refreshMyPosIcon
int PlayerHeroDisplayOffset = 368;// PlayerHero::GetPlayerHeroDisplay

int MoneyOffSet = 174;//PlayerHero::getMoney(PlayerHero *this, int a2)


int Game_IsAutoPlay_Offset1 = 1376;// 171 * 8;// 1336; //Game::IsAutoPlay(__int64 a1)
int Game_IsAutoPlay_Offset2 = 433;// 425;



int MapID_Offset = 40;// 4 * 8;// AutoPlay2::SingleCombat(AutoPlay2 *this) AutoPlay2::setMoveParam(v11, v44[17],
int ZoneID_Offset = 5416;// 675 * 8;// 535 * 8;//UIMiniMapPanel::RefreshDistrictName;  
int ZoneName_Offset = 3088;// 3072;// 1952;//UIMiniMapPanel::setPlaceText     utf8_copy((char *)(v4 + 800), 256, v3);
int ZoneTypeOffset = 252;// 236; // Agent::IsInSafetyArea  Game::IsAvailablePk(Game *this) 

int GetAttackTargetId_Offset = 1472;// 183 * 8;// 1432;//Game::GetAttackTargetId(__int64 a1)

int EquipSet_Offset = 1848;// 232 * 8;// 186 * 8;//ItemHelper::FindItemFuncType    v39 = *(EquipSet **)(v34 + 1856);

int ShowActionButtonOffset = 3992;// 3976;// 2496; //UIActionMenuPanel6::IsShowActionButton(UIActionMenuPanel6 *this)






int QuestJournalOffset = 1720;// 1728;// 1344; //UIQuestHudPanel::makeBulletinQuestDataIdList
int QuestSize =  120;// 120;// 14 * 8;  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)

int Bag2Offset = 1816;// 1824;// 182 * 8; //UIItemDetailBasePanel::checkAttachableBead    v16 = *(_QWORD *)(v11 + 1824);
int Stash2Offset = 1832;// 230 * 8;//PlayerHero::ReqChangeItemSlot

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
int PartyOffset = 1912;// 1920;// 194 * 8;//UIPartyManagementPanel::onClickedSearcOkButton(__int64 result, const FName *a2)  1544

int TeamListSize = 1232;// Party::GetPartyMemberByHeroName


int Map3DPanelWrapperOffset = 10936;// 1327 * 8;//10616 1223 * 8; //UI3DWorldMap::removeImageIcon  9704
int UI3DWorldMapOffset = 2896;// 2880;// 1776; //UI3DMapPanel::ResetMapCenterToPlayer(UI3DMapPanel *this, unsigned __int16 a2)
int QuickSetBookOffset = 2040;// 2048;// 1696; //PlayerHero::SetUseAuto    UISignatureSkillPadPanel6::OnSwipeQuickSkillSlotButton  v32 = *(QuickSetBook **)(v39 + 1688);  QuickSetBook::SetUseAuto(v32, v33, v16, 0);





int NPCListMaxCountOffSet = 184;// 176;// 272; //  Game::snapshotHeroList     240;  Game::UpdateNpcAll

//int SkillOffset = 452; //AutoPlay2::arrived(AutoPlay2 *this, char a2)  result = AutoPlay2::SingleSkill(v5, *((_QWORD *)v5 + 51), *((_BYTE *)v5 + 452));
//int IsAttackFxOffset = 1040;//GameUI::StopAttackBtnFx(GameUI *this)      v3 = *(unsigned int **)(*(_QWORD *)this + 1040LL);

int Npc2nameOffset = 1056;// 744;// Npc::GetRecordName@<GameRecord2::Npc2::name((GameRecord2::Npc2 *)(result + 744));
int NpcGetRecordNameOffset = 4288;// 880; // Npc::GetRecordName
int NpcGradeOffset = 252;// 236; //GameRecord2::Npc2::grade(GameRecord2::Npc2 *this)


int NpcIsVisibleOffset = 1042;// 1330;// 1178;//Npc::IsVisible
int IsPlayerOffset = 1320;// 968; // UIPartyManagementPanel::makeInviteHeroListByFilteringZone    if ( v23 && *(_BYTE *)(v23 + 960) != 1 )      if ( v23 && *(_BYTE *)(v23 + 960) != 1 )


int UI3DWorldMapIconMaxOffSet = 9840;// 9520;// 288; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)    v21 = *(_DWORD *)(v19 + 288);
int UI3DWorldMapIconStartOffSet = UI3DWorldMapIconMaxOffSet - 72;// 216; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)   v18 = *(_QWORD *)(v15 + 216);

int UIChatMainOffset = 2856;// 2840;// 1720;  //UIChatPanel3::OnModifiedWriteBox(UIChatPanel3 *this, const FName *a2)

int SkillContext6Offset = 4256;// 4248;// 4240;// 4008;// 3416; //Game::GetSkillContext6 v3 = *(_QWORD *)(v2 + 4176);
int HyperRunController_Offset = 4240;// 4232;// 4224;// 3992;// 3384; //Game::GetHyperRunController@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)

int EquipCollectionBookOffset = 1784;// 224 * 8;//UIEquipCollectionPanel::RefreshAll(__int64 result, char a2)  v19 = (int *)v11[177];
int StorageShopUnknownOffset = 354 * 8;//2832 UIStashPanel::OnClickMoveToStashButton     Bag2::RequestMoveToStash(v162, *((_QWORD *)v6 + 352), (__int64)&v171, &v176);
//int SellShopUnknownOffset = 3912;//UIBuySellItemPopupPanel::onClickedOkButton     Bag2::RequestSellItem2(v17, v30, v31, *(signed __int16 *)(v5 + 3840), 1);


//int MsgObj_HeroGuildOffset = 1192;  //Hero::SetGuild(Hero *this, const MsgObj::GuildBroadcast *a2)      v7 = (char *)this + 1192;  v8 = (_QWORD*)(v6 & 0xFFFFFFFFFFFFFFFELL);
int GuildTextOffset = 4696;  //ICharacter::SetGuildText
int GameCameraOffset = 1144;// Game::CameraReset
int SetCameraOffset = 256;// Game::CameraReset

int EffectBoardOffset = 672; //UIHudPlayerInfoPanel::RefreshEffectList  v49 = *(EffectBoard **)(result + 672);

int IsFollowPartyLeaderOffset = 3544;// 3536; //PlayerHero::IsFollowPartyLeader   //Game::SetAttackTargetId
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
