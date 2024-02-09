#pragma once

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;

//20240207


__int64_t _ZN8B2Client8instanceE = 0x5E59E10; //OK
__uint64_t _GameThreadTid = 0x5F22168;
__int64_t _EnginePtr = 0x60B77E8; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x3988360; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1E065A0;

__int64_t _ZN7FMemory4FreeEPv = 0x1D12FC0;
__int64_t _ZNK5FText8ToStringEv = 0x1D65970;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2EE6910;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2EEB710;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1FC9020;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1FE4410;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2EF05E0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2EECD00;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2E9BC10;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F52E90; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2EEA8D0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2F2FBA0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x3573550;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2EC3C40;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2EC3F00;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2EC4100;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x399C9A0;

__int64_t _ZN5Item212GetItemGradeEy = 0xC185E0;

__int64_t _ZN5Item211GetItemNameEy = 0xC18BD0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA60230;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA60660;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2EE9E70;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1FE3E70;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC15C26;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x1153B07;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x146E680;

__int64_t _ClosePanelStartAddr = 0x5E835D0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x1472DA0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x1484700;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x16394F0;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2F06350;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x225B7A0;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB515F0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x335A260;

__int64_t _ZN4Game9FindAgentEy = 0xB580B0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB2DFF0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA60B50;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xE0ABA0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x1580300;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11C85C0;
__int64_t _ZN8Tutorial3EndEbb = 0xEA7F10;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB90130;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD6EEC0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD6ECD0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9F8720;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA428C0;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA742E0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA74570;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA6EDB0;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA41A20;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCEC000;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBCBFE0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB25950;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA61660;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC821A0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x3359D80;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCE2340;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB7B930;
__int64_t _ZN4Game10PickTargetEyb = 0xB65B90;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x336C970;
__int64_t __GetFB2ScalabilityController = 0x31E44A0;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA3EA00;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFEA180;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE51810;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE42AE0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE2C670;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x12E8B10;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12D04D0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9A8540;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAFA390;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xEC3CF0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA62880;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x117EDD0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16A43E0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x11FB520;

__int64_t OFF_ProcessDeferredMessage = 0x201DE70;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x6956C0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x399AFD0; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA87090;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9A83F0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB2FEF0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA857C0;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA0D1A0;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2F7C730;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3A48FC0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A4CED0;






/*


//20240124


__int64_t _ZN8B2Client8instanceE = 0x5E00110; //OK
__uint64_t _GameThreadTid = 0x5EC7CE8;
__int64_t _EnginePtr = 0x605D1A8; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x393F950; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1DC6250;

__int64_t _ZN7FMemory4FreeEPv = 0x1CD2D80;
__int64_t _ZNK5FText8ToStringEv = 0x1D25730;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2EA74B0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2EAC230;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1F88D60;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1FA4150;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2EB0D70;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2EAD820;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2E5B8C0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F12900; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2EAB3F0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2EEF890;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x352BB60;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2E84480;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2E84740;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2E84940;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x3953F90;

__int64_t _ZN5Item212GetItemGradeEy = 0xC0D2C0;

__int64_t _ZN5Item211GetItemNameEy = 0xC0D8B0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA5B850;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA5BC80;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2EAA990;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1FA3BB0;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC0ACF6;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x112B8D7;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x143DF40;

__int64_t _ClosePanelStartAddr = 0x5E29530; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x1442640;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x1453F10;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1605FC0;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2EC6430;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x221B460;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB47CC0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x3313EB0;

__int64_t _ZN4Game9FindAgentEy = 0xB4E8E0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB24760;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA5C170;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xDF92E0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x154DB60;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11A7D00;
__int64_t _ZN8Tutorial3EndEbb = 0xE95BD0;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB85B90;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD5DCC0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD5DAD0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9F5850;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA3F5E0;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA6F840;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA6FAC0;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA6A340;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA3E740;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCDE880;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBC1340;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB1C310;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA5CC70;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC76C50;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x33139D0;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCD4EB0;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB719A0;
__int64_t _ZN4Game10PickTargetEyb = 0xB5C030;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x3326460;
__int64_t __GetFB2ScalabilityController = 0x31A3260;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA3B730;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFCF300;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE400D0;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE31430;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE1B1D0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x12B3DE0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x128F020;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9A5F10;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAF2520;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xEB1780;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA5DE80;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x1154B10; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16702F0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x11E2960;

__int64_t OFF_ProcessDeferredMessage = 0x1FDDBB0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x6942F0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x39525C0; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA82AA0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9A5DC0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB26660;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA811E0;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA0A1F0;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2F3C1A0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x39FFFB0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A031F0;





//20240110



__int64_t _ZN8B2Client8instanceE = 0x5DE5778; //OK
__uint64_t _GameThreadTid = 0x5EACD68;
__int64_t _EnginePtr = 0x6042168; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x392AB00; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1DB8260;

__int64_t _ZN7FMemory4FreeEPv = 0x1CC4D90;
__int64_t _ZNK5FText8ToStringEv = 0x1D17740;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E98DF0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2E9DB70;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1F7A660;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1F95A50;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2EA26C0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2E9F170;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2E4D1B0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F04250; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2E9CD30;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2EE11E0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x3518400;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2E75D90;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2E76050;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2E76250;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x393F140;

__int64_t _ZN5Item212GetItemGradeEy = 0xC096B0;

__int64_t _ZN5Item211GetItemNameEy = 0xC09CA0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA59EF0;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA5A320;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2E9C2D0;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1F954B0;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC070A6;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x1125007;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x1435C00;

__int64_t _ClosePanelStartAddr = 0x5E0E860; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x143A2F0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x144BBB0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x15FD120;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2EB7D80;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x220CD30;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB44390;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x3300920;

__int64_t _ZN4Game9FindAgentEy = 0xB4AF20;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB21380;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA5A810;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xDF43A0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x1545060;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11A11F0;
__int64_t _ZN8Tutorial3EndEbb = 0xE90860;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB82000;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD58E30;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD58C40;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9F41F0;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA3D570;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA6DE20;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA6E0A0;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA68970;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA3C6D0;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCDF100;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBBD720;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB18F70;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA5B300;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC783D0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x3300440;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCD5F10;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB6DF70;
__int64_t _ZN4Game10PickTargetEyb = 0xB58530;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x33132E0;
__int64_t __GetFB2ScalabilityController = 0x3194A60;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA397B0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFC9920;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE3AEF0;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE2C5E0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE16170;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x12ABE40;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12871C0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9A4A80;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAEF250;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xEAC3E0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA5C510;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x114E160; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x1666F10;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x11DBC70;

__int64_t OFF_ProcessDeferredMessage = 0x1FCF4B0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x692EF0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x393D770; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA808C0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9A4930;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB23280;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA7F000;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA087B0;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2F2DAF0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x39EB8A0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x39EEA40;






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
int PKTargetOffset = 4424;// 4376; // PlayerHero::SetCounterAttackableTargetId  425*8
int MaxHpOffset = 196;// 188; //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
int NowHpOffset = 132;// 124;// 124;// 112;
int NowMpOffset = 136;// 124;// PlayerHeroDisplay::UpdateFocusBar
int MaxMpOffset = 2344 + 8;// 2304 + 8;// 2288 + 8;// 2240;// 2248;// 2248;// 1864;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
int MaxMpOffset2 = 248;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)

int AgentMaxMpOffset = 312;// 304;// 292;//AgentDisplay::UpdateFocusBar

int ICharacterOffset = 880;// 864;// 1040;//115 * 8 //AgentDisplay::UpdateFocusBar

int AgentOffset = 136;// 120;// 72;// 64;// 56;// 104;//UI3DWorldMap::refreshMyPosIcon
int PlayerHeroDisplayOffset = 376;// 368;// PlayerHero::GetPlayerHeroDisplay

int MoneyOffSet = 179 + 1;//PlayerHero::getMoney(PlayerHero *this, int a2)


int Game_IsAutoPlay_Offset1 = 1608;// 1592; //Game::IsAutoPlay(__int64 a1)
int Game_IsAutoPlay_Offset2 =  433;// 425;



int MapID_Offset = 40;// 4 * 8;// AutoPlay2::SingleCombat(AutoPlay2 *this) AutoPlay2::setMoveParam(v11, v44[17],
int ZoneID_Offset = 5416;// 675 * 8;// 535 * 8;//UIMiniMapPanel::RefreshDistrictName;  
int ZoneName_Offset = 3088;// 3072;// 1952;//UIMiniMapPanel::setPlaceText     utf8_copy((char *)(v4 + 800), 256, v3);
int ZoneTypeOffset = 260;// 252; // Agent::IsInSafetyArea  Game::IsAvailablePk(Game *this) 

int GetAttackTargetId_Offset = 1704;// 1688;// Game::GetAttackTargetId(__int64 a1)

int EquipSet_Offset = 1976;// 1936;//ItemHelper::FindItemFuncType    v39 = *(EquipSet **)(v34 + 1856);

int ShowActionButtonOffset = 34512;// 3976;// 2496; //UISignatureSkillPadPanel6::IsShowActionButton
int QuestJournalOffset = 1832;// 1808; //UIQuestHudPanel::makeBulletinQuestDataIdList
int QuestSize =  120;// 120;// 14 * 8;  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)


int Bag2Offset = 1944;// 1904; //UIItemDetailBasePanel::checkAttachableBead    v16 = *(_QWORD *)(v11 + 1824);
int Stash2Offset = 1960;// 1920;  //PlayerHero::ReqChangeItemSlot

int TradeBagOffset = 4080;// 4064;// 2816; //UITradePanel::OnClickSlotButton  //_ZN10UITradeBag17OnClickSlotButtonEi向上一層
int UITradeBagItemCircularViewOffset = 152;// UITradeBag::OnClickSlotButton

int UIInventoryPanelTabIndexOffset = 2834;// 2833;// 2817;//UIInventoryPanel2::OnClickItemSlotButton 下  //v46 = *((char *)this + 2817);    v46 = *((char *)this + 2817);    //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
int UIInventoryPanelStartAddressOffset = 2856;// 2840;//UIInventoryPanel2::OnClickItemSlotButton 下 //v47   v47 = *((_QWORD *)this + 355);    //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
int UIItemCircularViewOffset = 3088;// 3072;// 2056; //UIInventoryPanel2::ScrollToSpcificItemGridIndex   UIInventoryPanel2::OnClickItemSlotButton 下 UIItemCircularView::GetGridDataIndex((UIInventoryPanel2 *)((char *)v5 + 3072), v4);

int UISellItemCircularViewOffset = 4008;// 4000; //  UICitizenShopPanel2::OnClickBagSlotButton 下 v25 = UIItemCircularView::GetGridDataIndex(v3 + 4000, v49);
int UISellInventoryPanelTabIndexOffset = 2868;// 2860;//UICitizenShopPanel2::OnClickBagSlotButton 下    v24 = *(_BYTE *)(v3 + 2860);     if ( v24 >= 0 && *(_BYTE *)(v3 + 4240) > v24 )
int UISellInventoryPanelTabMaxOffset = 4248;// 4240; //UICitizenShopPanel2::OnClickBagSlotButton 下    v24 = *(_BYTE *)(v3 + 2860);     if ( v24 >= 0 && *(_BYTE *)(v3 + 4240) > v24 )
int UISellInventoryPanelStartAddressOffset = 3024;// 3016;//UICitizenShopPanel2::OnClickBagSlotButton 下     v26 = *(_QWORD *)(v3 + 3016);  v28 = Bag2::GetItemByInstanceId(v19, *(_QWORD *)(*(_QWORD *)(v27 + v26) + 8i64 * v25));


int ItemForgeUIOffset = 112;// 128; //GameUI::Initialize(GameUI *this)    v6 = (ItemForgeUI *)*((_QWORD *)v2 + 14);   UIItemForgePanel::OnClickedSkipUnsafeResultButton  

int EnterSleepModeOffSet = 3520;// 3504;// 3488;// 2272; //UISleepModePanel::Open  UISleepModePanel::SetSleepState(   *(_BYTE *)(v7 + 2264) = 1; 


int AutoMovePathOffset = 368;// 360; // AutoPlay2::MinimapMove(       if ( AutoMovePath::FindPath(v7 + 360, v7 + 36, 1LL) & 1 )
int PartyOffset = 2040;// 2000;//  //UIPartyManagementPanel::onClickedSearcOkButton(__int64 result, const FName *a2)  1544

int TeamListSize = 1248;// 1232;// Party::GetPartyMemberByHeroName


int Map3DPanelWrapperOffset = 11120; //10936;// 1327 * 8;//10616 1223 * 8; //UI3DWorldMap::removeImageIcon  9704
int UI3DWorldMapOffset = 2896;//UI3DMapPanel::ResetMapCenterToPlayer(UI3DMapPanel *this, unsigned __int16 a2)
int QuickSetBookOffset = 2152;// 2112;// //PlayerHero::SetUseAuto    UISignatureSkillPadPanel6::OnSwipeQuickSkillSlotButton  v32 = *(QuickSetBook **)(v39 + 1688);  QuickSetBook::SetUseAuto(v32, v33, v16, 0);





int NPCListMaxCountOffSet = 416;// 400;    Game::snapshotHeroList     240;  Game::UpdateNpcAll

//int SkillOffset = 452; //AutoPlay2::arrived(AutoPlay2 *this, char a2)  result = AutoPlay2::SingleSkill(v5, *((_QWORD *)v5 + 51), *((_BYTE *)v5 + 452));
//int IsAttackFxOffset = 1040;//GameUI::StopAttackBtnFx(GameUI *this)      v3 = *(unsigned int **)(*(_QWORD *)this + 1040LL);

int Npc2nameOffset = 1088;// 1072;// 1064;// 1056;// 744;// Npc::GetRecordName@<GameRecord2::Npc2::name((GameRecord2::Npc2 *)(result + 744));
int NpcGetRecordNameOffset = 4320;// 4304;// 4296;// 4288;// 880; // Npc::GetRecordName
int NpcGradeOffset = 252;// 236; //GameRecord2::Npc2::grade(GameRecord2::Npc2 *this)


int NpcIsVisibleOffset = 1058;// 1042;// 1330;// 1178;//Npc::IsVisible
int IsPlayerOffset = 1368;// 1352;  // UIPartyManagementPanel::makeInviteHeroListByFilteringZone    if ( v23 && *(_BYTE *)(v23 + 960) != 1 )      if ( v23 && *(_BYTE *)(v23 + 960) != 1 )


int UI3DWorldMapIconMaxOffSet = 9824;// 9840;// 9520;//UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)    v21 = *(_DWORD *)(v19 + 288);
int UI3DWorldMapIconStartOffSet = UI3DWorldMapIconMaxOffSet - 72;// 216; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)   v18 = *(_QWORD *)(v15 + 216);

int UIChatMainOffset = 2856;// 2840;  //UIChatPanel3::OnModifiedWriteBox(UIChatPanel3 *this, const FName *a2)

int SkillContext6Offset = 4408;// 4360;   //Game::GetSkillContext6 v3 = *(_QWORD *)(v2 + 4176);
int HyperRunController_Offset = 4392;// 4344; //Game::GetHyperRunController@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)

int EquipCollectionBookOffset = 1912;// 1872; //UIEquipCollectionPanel::RefreshAll(__int64 result, char a2)  v19 = (int *)v11[177];
int StorageShopUnknownOffset = 2840;// 2832;// 354 * 8;//2832 UIStashPanel::OnClickMoveToStashButton     Bag2::RequestMoveToStash(v162, *((_QWORD *)v6 + 352), (__int64)&v171, &v176);
//int SellShopUnknownOffset = 3912;//UIBuySellItemPopupPanel::onClickedOkButton     Bag2::RequestSellItem2(v17, v30, v31, *(signed __int16 *)(v5 + 3840), 1);


int MsgObj_HeroGuildOffset = 1232;  //Hero::SetGuild(Hero *this, const MsgObj::GuildBroadcast *a2)      v7 = (char *)this + 1192;  v8 = (_QWORD*)(v6 & 0xFFFFFFFFFFFFFFFELL);
//int GuildTextOffset = 4696;  //ICharacter::SetGuildText
int GuildTextOffset1 = 1240;// 1224; //ICharacter::SetGuildText 之上  HeroDisplay::UpdateNamePlate
int GuildTextOffset2 = 1296;// 1280; //ICharacter::SetGuildText 之上  HeroDisplay::UpdateNamePlate




int GameCameraOffset = 1144;// Game::CameraReset
int SetCameraOffset = 256;// Game::CameraReset

int EffectBoardOffset = 680;// 672; //UIHudPlayerInfoPanel::RefreshEffectList  v49 = *(EffectBoard **)(result + 672);

int IsFollowPartyLeaderOffset = 3680;// 3640; //PlayerHero::IsFollowPartyLeader   //Game::SetAttackTargetId
int GameRecord2_Npc2_CannotBeTargetedOffSet = 504; //GameRecord2::Npc2::CannotBeTargeted



//int SkipUnsafeOffset = 2328; //未找到ItemForgeUI::ToggleSkipUnsafeResult(__int64 a1, UIItemForgePanel **a2)   UIItemForgePanel::OnClickedSkipUnsafeResultButton
int UIPanelMax = 0x7E + 6 + 1;  //+1是DimPanel  //Tutorial::getPanelTypeByUIPanel   ////UIPanelManager::ClosePanel 中 考慮改UIPanelManager::ClosePanel  的做法



int CoorOffset = 30 * 4;// 24 * 4; //Agent::GetPos(Agent *this, float *a2, float *a3, float *a4)
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
std::string SignatureSkillPadMobileName = "bpSignatureSkillPadMobile";

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
