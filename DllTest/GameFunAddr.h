#pragma once

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;


//20230906


__int64_t _ZN8B2Client8instanceE = 0x5D0CE28; //OK
__uint64_t _GameThreadTid = 0x5DD0728;
__int64_t _EnginePtr = 0x5F65658; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x3873AA0; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1D0B190;

__int64_t _ZN7FMemory4FreeEPv = 0x1C17A80;
__int64_t _ZNK5FText8ToStringEv = 0x1C6A460;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DF05C0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DF5430;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1ECD620;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1EE8A10;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2DF9FB0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2DF69D0;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2DA15D0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E56600; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2DF45F0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E384E0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x3463290;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2DCAF40;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2DCB200;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2DCB400;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x3888230;

__int64_t _ZN5Item212GetItemGradeEy = 0xBF2210;

__int64_t _ZN5Item211GetItemNameEy = 0xBF2800;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA39DF0;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA3A220;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2DF3AA0;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1EE8470;


//__int64_t _ZN16UISleepModePanel12OnClosePanelEv =  0xBEF9F6;
__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13B7AE0;

__int64_t _ClosePanelStartAddr = 0x5D32B10; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13BC4A0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x13CC890;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x1574100;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E12EF0;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x215FBD0;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAF2A60;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x324AB50;

__int64_t _ZN4Game9FindAgentEy = 0xAFDD40;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB0FED0;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA3A710;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD8D590;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14BD440;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x1138160;
__int64_t _ZN8Tutorial3EndEbb = 0xE682D0;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB36B50;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD2B950;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD2B760;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9DC270;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA21900;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA4D4E0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA4D760;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA482B0;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA20AD0;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCABBC0;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA98B0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xB03390;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA3B200;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC821A0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x324A670;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xCA0B40;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB2DAD0;
__int64_t _ZN4Game10PickTargetEyb = 0xB15920;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x325CA60;
__int64_t __GetFB2ScalabilityController = 0x30E6AA0;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA1E740;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF90860;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE0F260;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xE05080;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDF33B0;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1241130;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x1220F60;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x991390;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAC6610;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE47DA0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA3C410;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10EC5B0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15DD660;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x116CC10;

__int64_t OFF_ProcessDeferredMessage = 0x1F224D0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x6851B0;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x3886850; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA5E3E0;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x991270;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB124D0;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA5CF00;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9F0950;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E7FED0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x39351A0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x39385C0;






/*


//20230830


__int64_t _ZN8B2Client8instanceE = 0x5D06068; //OK
__uint64_t _GameThreadTid = 0x5DC99E8;
__int64_t _EnginePtr = 0x5F5E988; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x386D6C0; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1D01D80;

__int64_t _ZN7FMemory4FreeEPv = 0x1C0E670;
__int64_t _ZNK5FText8ToStringEv = 0x1C61050;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DE92B0;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DEE120;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1EC4220;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1EDF610;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2DF2CA0;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2DEF6C0;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2D9A2F0;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E4F2F0; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2DED2E0;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E311D0;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x345BFF0;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2DC3C60;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2DC3F20;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2DC4120;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x3881E50;

__int64_t _ZN5Item212GetItemGradeEy = 0xBEC500;

__int64_t _ZN5Item211GetItemNameEy = 0xBECAF0;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA33F60;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA34390;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2DEC790;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1EDF070;

__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13AED80;

__int64_t _ClosePanelStartAddr = 0x5D2BDE0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13B3740;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x13C3B30;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x156B2B0;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E0BBE0;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x2156490;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAECF80;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x3243820;

__int64_t _ZN4Game9FindAgentEy = 0xAF8260;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB0A390;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA34880;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD87430;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14B46D0;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x112F4E0;
__int64_t _ZN8Tutorial3EndEbb = 0xE616B0;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB30FE0;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD257F0;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD25600;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9D68C0;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA1BA90;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA47650;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA478D0;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA42420;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA1AC60;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCA5D00;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA3C50;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xAFD8B0;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA35370;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC7C2E0;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x3243340;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xC9AC80;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB27F70;
__int64_t _ZN4Game10PickTargetEyb = 0xB0FDE0;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x3255710;
__int64_t __GetFB2ScalabilityController = 0x30DF7B0;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA188D0;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF89710;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE08F00;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xDFED20;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDED080;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x12384B0;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x12182E0;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x98BA20;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAC0BC0;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE41810;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA36580;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10E3930; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15D4810;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x1163F90;

__int64_t OFF_ProcessDeferredMessage = 0x1F18FF0;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x67F840;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x3880470; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA58580;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x98B900;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB0C990;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA570A0;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9EAFA0;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E78BC0;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x392EDA0;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x39321C0;


//20230823

__int64_t _ZN8B2Client8instanceE = 0x5D07068; //OK
__uint64_t _GameThreadTid = 0x5DCA9E8;
__int64_t _EnginePtr = 0x5F5F988; //OK
__int64_t _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode = 0x386E450; //OK
__int64_t _ZNK5FName8ToStringEv = 0x1D02B10;

__int64_t _ZN7FMemory4FreeEPv = 0x1C0F400;
__int64_t _ZNK5FText8ToStringEv = 0x1C61DE0;

//__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DEA040;

__int64_t _ZN10UTextBlock14GetDisplayTextEv = 0x2DEEEB0;

__int64_t _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags = 0x1EC4FB0;

__int64_t _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags = 0x1EE03A0;

__int64_t _ZNK7UWidget9IsVisibleEv = 0x2DF3A30;
__int64_t _ZNK7UWidget12GetIsEnabledEv = 0x2DF0450;

__int64_t _ZNK9UCheckBox15GetCheckedStateEv = 0x2D9B080;
__int64_t _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE = 0x2E50080; //UWidgetTree__GetAllWidgets
__int64_t _ZNK7UWidget17GetCachedGeometryEv = 0x2DEE070;

__int64_t _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_ = 0x2E31F60;
__int64_t _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D = 0x345CD80;

__int64_t _ZN7UButton18SlateHandleClickedEv = 0x2DC49F0;

__int64_t _ZN7UButton18SlateHandlePressedEv = 0x2DC4CB0;

__int64_t _ZN7UButton18SlateHandleReleaseEv = 0x2DC4EB0;

__int64_t _ZN7UEngine9SetMaxFPSEf = 0x3882BE0;

__int64_t _ZN5Item212GetItemGradeEy = 0xBED290;

__int64_t _ZN5Item211GetItemNameEy = 0xBED880;

__int64_t _ZNK4Bag218RequestConsumeItemExiy = 0xA34CF0;

__int64_t _ZNK4Bag218RequestDestroyItemExsi = 0xA35120;

__int64_t _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv = 0x2DED520;
__int64_t _ZNK14FWeakObjectPtr3GetEv = 0x1EDFE00;

__int64_t _ZN16UISleepModePanel12OnClosePanelEv = 0x13AFB10;

__int64_t _ClosePanelStartAddr = 0x5D2CDE0; //UIPanelManager::ClosePanel 中

__int64_t _ZN16UISleepModePanel4OpenEv = 0x13B44D0;
__int64_t _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb = 0x13C48C0;

__int64_t _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb = 0x156C040;

__int64_t _ZN10UScrollBox15SetScrollOffsetEf = 0x2E0C970;

__int64_t _ZN14STableViewBase15SetScrollOffsetEf = 0x2157220;

__int64_t _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch = 0xAEDD10;

__int64_t _ZNK10ICharacter14HasMoveCommandEv = 0x32445B0;

__int64_t _ZN4Game9FindAgentEy = 0xAF8FF0;

__int64_t _ZNK8EquipSet10IsEquippedEx = 0xB0B120;

__int64_t _ZNK4Bag222RequestDisassembleItemExi = 0xA35610;

__int64_t _ZNK5Quest26GetQuestMissionProgressMaxEv = 0xD881C0;
__int64_t _ZN10UITradeBag17OnClickSlotButtonEi = 0x14B5460;
__int64_t _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei = 0x1130270;
__int64_t _ZN8Tutorial3EndEbb = 0xE62440;
// 以下数据全在 _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch ず

__int64_t _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv = 0xB31D70;
__int64_t _ZN17PlayerHeroDisplay14StopMoveOnPathEv = 0xD26580;
__int64_t _ZN17PlayerHeroDisplay15StopDestGimmickEv = 0xD26390;
__int64_t _ZN12AgentDisplay16ClearActionTimerEv = 0x9D7650;
//以下数据全在 AutoPlay2::MinimapMove 内
__int64_t _ZN9AutoPlay26FinishEv = 0xA1C820;
__int64_t _ZN9AutoPlay212setMoveParamEy7FVectorf = 0xA483E0;

__int64_t _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf = 0xA48660;

__int64_t _ZN9AutoPlay215changePlayStateE14AutoPlayState2b = 0xA431B0;

__int64_t _ZN12AutoMovePath8FindPathERK7FVectorb = 0xA1B9F0;

//__int64_t _ZNK10PlayerHero18GetWeaponGroupTypeEv =  0x0;
__int64_t _ZN10PlayerHero10SetUseAutoEhab = 0xCA6A90;

__int64_t _ZN8Grocery221ProcessUseGroceryItemEiixyybb = 0xBA49E0;

__int64_t _ZNK8EquipSet12GetEquipSlotEas = 0xAFE640;
__int64_t _ZNK4Bag216RequestEquipItemEhsxhb = 0xA36100;

__int64_t _ZN3Npc13GetRecordNameEv = 0xC7D070;
__int64_t _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D = 0x32440D0;
__int64_t _ZNK5Party28RequestInvitePartyByHeroNameEPKc = 0xC9BA10;
__int64_t _ZN4Game17SetAttackTargetIdEybb = 0xB28D00;
__int64_t _ZN4Game10PickTargetEyb = 0xB10B70;

__int64_t _ZN24FB2ScalabilityController9SetMaxFPSEf = 0x32564A0;
__int64_t __GetFB2ScalabilityController = 0x30E0540;

__int64_t _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode = 0xA19660;

__int64_t _ZN10UIChatMain17sendMessageEscapeEv = 0xF8A4A0;

__int64_t _ZN18HyperRunController21SetImpossibleAutoMoveEb = 0xE09C90;
__int64_t _ZN18HyperRunController12PlayHyperRunEh = 0xDFFAB0;

__int64_t _ZN13SkillContext623CheckCanHitTargetByAutoEy = 0xDEDE10;

__int64_t _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi = 0x1239240;

__int64_t _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi = 0x1219070;

__int64_t _ZN12DataManager322GetEquipCollectionDictEv = 0x98C7B0;

__int64_t _ZN18B2ClientTextFormat7GetTextEPKc = 0xAC1950;

__int64_t _ZNK6Stash222RequestMoveToInventoryEysi = 0xE425A0;
__int64_t _ZNK4Bag218RequestMoveToStashEysi = 0xA37310;
__int64_t _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei = 0x10E46C0; //SysM.Stash.RegistFail.Registered 的那FUNCTION

__int64_t _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb = 0x15D55A0;
__int64_t _ZN18UIItemCircularView16GetGridDataIndexEi = 0x1164D20;

__int64_t OFF_ProcessDeferredMessage = 0x1F19D80;

__int64_t _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii = 0x67F840;
__uint64_t _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb = 0x3881200; //aShowui 

__uint64_t _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv = 0xA59310;

__uint64_t _ZN12DataManager319GetEffectManualDictEv = 0x98C690;
__uint64_t _EffectManualDict_GetEffectByIdEv = 0xB0D720;

__uint64_t _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv = 0xA57E30;
__uint64_t _ZN5Agent18IsAttackPlayerHeroEv = 0x9EBD30;

__int64_t _ZN11UUserWidget21GetPrivateStaticClassEv = 0x2E79950;
__int64_t _ZN6AB2HUD21GetPrivateStaticClassEv = 0x392FB30;
__int64_t _ZN19AB2PlayerController21GetPrivateStaticClassEv = 0x3932F50;




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
int PKTargetOffset = 4288;// 4272;// PlayerHero::SetCounterAttackableTargetId  425*8
int MaxHpOffset = 188;// 172;//AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
int NowHpOffset = 124;// 124;// 112;
int NowMpOffset = 128;// 124;// PlayerHeroDisplay::UpdateFocusBar
int MaxMpOffset = 2248 + 8;// 2240;// 2248;// 2248;// 1864;//PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
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

int EquipSet_Offset = 1864;// 1848;//ItemHelper::FindItemFuncType    v39 = *(EquipSet **)(v34 + 1856);

int ShowActionButtonOffset = 3992;// 3976;// 2496; //UIActionMenuPanel6::IsShowActionButton(UIActionMenuPanel6 *this)






int QuestJournalOffset = 1736;// 1720;// 1728;// 1344; //UIQuestHudPanel::makeBulletinQuestDataIdList
int QuestSize =  120;// 120;// 14 * 8;  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)

int Bag2Offset = 1832;// 1816;// 1824;// 182 * 8; //UIItemDetailBasePanel::checkAttachableBead    v16 = *(_QWORD *)(v11 + 1824);
int Stash2Offset = 1848;// 1832;// 230 * 8;//PlayerHero::ReqChangeItemSlot

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
int PartyOffset = 1928;// 1912;// 1920;// 194 * 8;//UIPartyManagementPanel::onClickedSearcOkButton(__int64 result, const FName *a2)  1544

int TeamListSize = 1232;// Party::GetPartyMemberByHeroName


int Map3DPanelWrapperOffset = 10936;// 1327 * 8;//10616 1223 * 8; //UI3DWorldMap::removeImageIcon  9704
int UI3DWorldMapOffset = 2896;// 2880;// 1776; //UI3DMapPanel::ResetMapCenterToPlayer(UI3DMapPanel *this, unsigned __int16 a2)
int QuickSetBookOffset = 2056;// 2040;// //PlayerHero::SetUseAuto    UISignatureSkillPadPanel6::OnSwipeQuickSkillSlotButton  v32 = *(QuickSetBook **)(v39 + 1688);  QuickSetBook::SetUseAuto(v32, v33, v16, 0);





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

int SkillContext6Offset = 4272;// 4256;// 4248;// 4240;// 4008;// 3416; //Game::GetSkillContext6 v3 = *(_QWORD *)(v2 + 4176);
int HyperRunController_Offset = 4256;// 4240;// 4232;// 4224;// 3992;// 3384; //Game::GetHyperRunController@<X0>(__int64 result@<X0>, _QWORD *a2@<X8>)

int EquipCollectionBookOffset = 1800;// 1784;// 224 * 8;//UIEquipCollectionPanel::RefreshAll(__int64 result, char a2)  v19 = (int *)v11[177];
int StorageShopUnknownOffset = 354 * 8;//2832 UIStashPanel::OnClickMoveToStashButton     Bag2::RequestMoveToStash(v162, *((_QWORD *)v6 + 352), (__int64)&v171, &v176);
//int SellShopUnknownOffset = 3912;//UIBuySellItemPopupPanel::onClickedOkButton     Bag2::RequestSellItem2(v17, v30, v31, *(signed __int16 *)(v5 + 3840), 1);


//int MsgObj_HeroGuildOffset = 1192;  //Hero::SetGuild(Hero *this, const MsgObj::GuildBroadcast *a2)      v7 = (char *)this + 1192;  v8 = (_QWORD*)(v6 & 0xFFFFFFFFFFFFFFFELL);
int GuildTextOffset = 4696;  //ICharacter::SetGuildText
int GameCameraOffset = 1144;// Game::CameraReset
int SetCameraOffset = 256;// Game::CameraReset

int EffectBoardOffset = 672; //UIHudPlayerInfoPanel::RefreshEffectList  v49 = *(EffectBoard **)(result + 672);

int IsFollowPartyLeaderOffset = 3560;// 3544;// 3536; //PlayerHero::IsFollowPartyLeader   //Game::SetAttackTargetId
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
