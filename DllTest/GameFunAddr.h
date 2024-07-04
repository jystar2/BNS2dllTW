#pragma once

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;

//20240327


__int64_t _ZN8B2Client8instanceE = 0x5E7B620; //OK
__uint64_t _GameThreadTid = 0x5F43D38;
__int64_t _EnginePtr = 0x60D9428; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x39A2DE0; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1E1D6A0;

__int64_t _ZN7FMemory4FreeEPv = 0x1D2A090;
__int64_t _ZNK5FText8ToStringEv = 0x1D7CA40;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2F01220;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1FE0050;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1FFB430;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2F05D00;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2F02800;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2EB0B70;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F68C40; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2F003E0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2F457F0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x358DD40;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2ED9580;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2ED9830;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2ED9A20;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x39B7420;

__int64_t _ZN5Item212GetItemGradeEy = 0xC299B0;

__int64_t _ZN5Item211GetItemNameEy = 0xC29FA0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA66750;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA66B80;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2EFF980;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1FFAE90;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC26F76;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x116FFB7;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x1499D10;

__int64_t _ClosePanelStartAddr = 0x5EA4FB0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x149E430;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x14AFDC0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x16661C0;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2F1B780;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x22726A0;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB61020;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x3374120;

__int64_t _ZN4Game9FindAgentEy = 0xB67B30;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB3D420;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA67070;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xE1E810;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x15AC730;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11E5C70;
__int64_t _ZN8Tutorial3EndEbb = 0xEBD000;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xBA0BD0;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD82AA0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD828B0;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0xA04780;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA4C330;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA793A0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA79630;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA73F30;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA4B490;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCFF410;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBDCCC0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB34D80;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA67B80;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC94C90;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x3373C40;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCF5710;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB8BE10;
__int64_t _ZN4Game10PickTargetEyb = 0xB75730;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x3386940;
__int64_t __GetFB2ScalabilityController = 0x31FB180;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA490D0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0x1004560;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE66450;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE57680;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE40BA0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x130CAA0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12F4440;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9B1E00;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xB08FB0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xED8FB0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA68DA0;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x119ADB0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16D1240;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x121AD70;

__int64_t OFF_ProcessDeferredMessage = 0x2034E60;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x69BF80;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x39B5A50; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA8EB30;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9B1CB0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB3F5A0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA8D260;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA19260;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2F92610;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3A63660;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A67100;




/*


//20240320



__int64_t _ZN8B2Client8instanceE = 0x5E994E0; //OK
__uint64_t _GameThreadTid = 0x5F61BB8;
__int64_t _EnginePtr = 0x60F72A8; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x39B9710; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1E33CB0;

__int64_t _ZN7FMemory4FreeEPv = 0x1D406A0;
__int64_t _ZNK5FText8ToStringEv = 0x1D93050;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2F17840;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1FF6660;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x2011A40;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2F1C320;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2F18E20;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2EC71A0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F7E4F0; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2F16A00;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2F5B460;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x35A4670;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2EEFBB0;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2EEFE60;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2EF0050;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x39CDD50;

__int64_t _ZN5Item212GetItemGradeEy = 0xC25DC0;

__int64_t _ZN5Item211GetItemNameEy = 0xC263B0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA63290;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA636C0;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2F15FA0;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x20114A0;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC23386;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x116B1D7;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x14946B0;

__int64_t _ClosePanelStartAddr = 0x5EC2E60; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x1498DD0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x14AA760;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1660B60;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2F31D80;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x2288CB0;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB5D1D0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x338AD70;

__int64_t _ZN4Game9FindAgentEy = 0xB63CE0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB39600;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA63BB0;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xE1A2B0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x15A70D0;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11E13E0;
__int64_t _ZN8Tutorial3EndEbb = 0xEB8A40;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB9D180;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD7E540;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD7E350;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0xA00B40;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA48E80;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA75E90;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA76120;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA70A20;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA47FE0;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCFAEF0;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBD9260;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB30F60;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA646C0;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC90790;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x338A890;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCF1200;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB883D0;
__int64_t _ZN4Game10PickTargetEyb = 0xB71CF0;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x339D590;
__int64_t __GetFB2ScalabilityController = 0x3210910;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA45C20;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFFFFA0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE61E90;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE530C0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE3C5E0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1308240;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12EFBE0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9AE600;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xB059D0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xED49F0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA658E0;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x1196030; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16CBBE0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x12164B0;

__int64_t OFF_ProcessDeferredMessage = 0x204B470;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x699880;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x39CC380; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA8B600;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9AE4B0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB3B780;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA89D30;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA15990;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2FA7DA0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3A7A030;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A7DAD0;






//20240313


__int64_t _ZN8B2Client8instanceE = 0x5E984E0; //OK
__uint64_t _GameThreadTid = 0x5F60BB8;
__int64_t _EnginePtr = 0x60F62A8; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x39B9290; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1E33830;

__int64_t _ZN7FMemory4FreeEPv = 0x1D40220;
__int64_t _ZNK5FText8ToStringEv = 0x1D92BD0;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2F173C0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1FF61E0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x20115C0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2F1BEA0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2F189A0;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2EC6D20;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F7E070; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2F16580;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2F5AFE0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x35A41F0;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2EEF730;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2EEF9E0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2EEFBD0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x39CD8D0;

__int64_t _ZN5Item212GetItemGradeEy = 0xC25DC0;

__int64_t _ZN5Item211GetItemNameEy = 0xC263B0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA63290;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA636C0;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2F15B20;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x2011020;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC23386;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x116B1D7;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x14946B0;

__int64_t _ClosePanelStartAddr = 0x5EC1E60; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x1498DD0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x14AA760;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1660B60;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2F31900;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x2288830;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB5D1D0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x338A8F0;

__int64_t _ZN4Game9FindAgentEy = 0xB63CE0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB39600;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA63BB0;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xE1A2B0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x15A70D0;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11E13E0;
__int64_t _ZN8Tutorial3EndEbb = 0xEB8A40;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB9D180;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD7E540;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD7E350;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0xA00B40;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA48E80;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA75E90;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA76120;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA70A20;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA47FE0;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCFAEF0;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBD9260;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB30F60;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA646C0;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC90790;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x338A410;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCF1200;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB883D0;
__int64_t _ZN4Game10PickTargetEyb = 0xB71CF0;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x339D110;
__int64_t __GetFB2ScalabilityController = 0x3210490;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA45C20;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFFFFA0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE61E90;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE530C0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE3C5E0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1308240;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12EFBE0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9AE600;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xB059D0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xED49F0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA658E0;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x1196030; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16CBBA0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x12164B0;

__int64_t OFF_ProcessDeferredMessage = 0x204AFF0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x699880;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x39CBF00; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA8B600;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9AE4B0;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB3B780;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA89D30;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA15990;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2FA7920;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3A79BB0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A7D650;


//20240221


__int64_t _ZN8B2Client8instanceE = 0x5E8ACF0; //OK
__uint64_t _GameThreadTid = 0x5F532A8;
__int64_t _EnginePtr = 0x60E8958; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x39AFF60; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1E2A250;

__int64_t _ZN7FMemory4FreeEPv = 0x1D36C70;
__int64_t _ZNK5FText8ToStringEv = 0x1D89620;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2F0A5C0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2F0F3C0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1FECCD0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x20080C0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2F14290;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2F109B0;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2EBF8C0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2F76B40; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2F0E580;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2F53850;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x359ADD0;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2EE78F0;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2EE7BB0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2EE7DB0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x39C45A0;

__int64_t _ZN5Item212GetItemGradeEy = 0xC218E0;

__int64_t _ZN5Item211GetItemNameEy = 0xC21ED0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA5F300;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA5F730;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2F0DB20;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x2007B20;

//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xC1EEA6;
//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0x1163A67;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x148C730;

__int64_t _ClosePanelStartAddr = 0x5EB45C0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x1490E50;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x14A27E0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1658870;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2F2A000;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x227F450;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xB591F0;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x3381420;

__int64_t _ZN4Game9FindAgentEy = 0xB5FD00;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB354C0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA5FC20;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xE14EB0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x159F150;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x11D9A30;
__int64_t _ZN8Tutorial3EndEbb = 0xEB3180;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB99070;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD79170;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD78F80;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9FCBD0;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA44F00;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA71DA0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA72030;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA6C930;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA44060;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCF5B20;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBD4F30;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB2CE20;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA60730;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC8B990;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x3380F40;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCEBE30;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB842B0;
__int64_t _ZN4Game10PickTargetEyb = 0xB6DCF0;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x3393C30;
__int64_t __GetFB2ScalabilityController = 0x3208160;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA41CA0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xFF8910;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE5C690;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE4D8D0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xE37030;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x13008C0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12E8260;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x9AA8C0;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xB01830;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xECF110;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA61950;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x118E800; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x16C3800;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x120EB00;

__int64_t OFF_ProcessDeferredMessage = 0x2041B20;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x695930;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x39C2BD0; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA87490;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x9AA770;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB37640;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA85BC0;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0xA11A20;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2FA03E0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x3A711B0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3A750C0;











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
int PKTargetOffset = 4432;// 4424;// 4376; // PlayerHero::SetCounterAttackableTargetId  425*8
int MaxHpOffset = 196;// 188; //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
int NowHpOffset = 132;// 124;// 124;// 112;
int NowMpOffset = 136;// 124;// PlayerHeroDisplay::UpdateFocusBar
int MaxMpOffset = 2344 + 8;// 2304 + 8;// 2288 + 8;// 2240;// 2248;// 2248;// 1864;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
int MaxMpOffset2 = 248;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)

int AgentMaxMpOffset = 312;// 304;// 292;//AgentDisplay::UpdateFocusBar

int ICharacterOffset = 880;// 912;// 880; //AgentDisplay::UpdateFocusBar

int AgentOffset = 136;// 120;// 72;// 64;// 56;// 104;//UI3DWorldMap::refreshMyPosIcon
int PlayerHeroDisplayOffset = 376;// 368;// PlayerHero::GetPlayerHeroDisplay

int MoneyOffSet = 179 + 1;//PlayerHero::getMoney(PlayerHero *this, int a2)


int Game_IsAutoPlay_Offset1 = 1608;// 1592; //Game::IsAutoPlay(__int64 a1)
int Game_IsAutoPlay_Offset2 =  433;// 425;



int MapID_Offset = 40;// 4 * 8;// AutoPlay2::SingleCombat(AutoPlay2 *this) AutoPlay2::setMoveParam(v11, v44[17],
int ZoneID_Offset = 5432;// 5416;;//UIMiniMapPanel::RefreshDistrictName;  
int ZoneName_Offset = 3088;// 3072;// 1952;//UIMiniMapPanel::setPlaceText     utf8_copy((char *)(v4 + 800), 256, v3);
int ZoneTypeOffset = 260;// 252; // Agent::IsInSafetyArea  Game::IsAvailablePk(Game *this) 

int GetAttackTargetId_Offset = 1704;// 1688;// Game::GetAttackTargetId(__int64 a1)

int EquipSet_Offset = 1976;// 1936;//ItemHelper::FindItemFuncType    v39 = *(EquipSet **)(v34 + 1856);

int ShowActionButtonOffset = 44728;// 34512;//  //UISignatureSkillPadPanel6::IsShowActionButton
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


int NpcIsVisibleOffset = 1090;// 1058;// //Npc::IsVisible
int IsPlayerOffset = 1368;// 1352;  // UIPartyManagementPanel::makeInviteHeroListByFilteringZone    if ( v23 && *(_BYTE *)(v23 + 960) != 1 )      if ( v23 && *(_BYTE *)(v23 + 960) != 1 )


int UI3DWorldMapIconMaxOffSet = 9824;// 9840;// 9520;//UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)    v21 = *(_DWORD *)(v19 + 288);
int UI3DWorldMapIconStartOffSet = UI3DWorldMapIconMaxOffSet - 72;// 216; //UI3DWorldMap::getUI3DMapObjectMapIconObject@<X0>(__int64 result@<X0>, __int64 a2@<X1>, _QWORD *a3@<X8>)   v18 = *(_QWORD *)(v15 + 216);

int UIChatMainOffset = 2856;// 2840;  //UIChatPanel3::OnModifiedWriteBox(UIChatPanel3 *this, const FName *a2)

int SkillContext6Offset = 4416;// 4360;   //Game::GetSkillContext6 v3 = *(_QWORD *)(v2 + 4176);
int HyperRunController_Offset = 4400;// 4392;// 4344; //Game::GetHyperRunController@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)

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

int IsFollowPartyLeaderOffset = 3688;// 3680;// 3640; //PlayerHero::IsFollowPartyLeader   //Game::SetAttackTargetId
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
        v5 = v4 + 64i64 * v3;
        if (*(__int64*)v5 == a2)
            break;
        v3 = *(int*)(v5 + 56);
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
