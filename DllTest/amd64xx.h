#pragma once

extern "C" void __stdcall fake_UButton_SlateHandleReleased(__uint64_t a, __uint64_t b);
extern "C" void __stdcall fake_UButton_SlateHandleClicked(__uint64_t a, __uint64_t b);
extern "C" void __stdcall fake_UButton_SlateHandlePressed(__uint64_t a);
extern "C" void __stdcall fake_Game_AutoPlayMapMove(__uint64_t, __uint64_t, __uint64_t,  float);
extern "C" void __stdcall fake_UISleepModePanel_OnClose(__uint64_t a, __uint64_t b);


extern "C" void __stdcall fake_AutoPlay2_Finish(__uint64_t a);


extern "C" void __stdcall fake_AutoPlay2_changePlayState(__uint64_t a, __uint64_t b, __uint64_t c);

extern "C" void __stdcall fake_HyperRunController_SetImpossibleAutoMoveEb(__uint64_t a, char b);
extern "C" void __stdcall fake_HyperRunController_PlayHyperRunEh(__uint64_t a, char b);

extern "C" void __stdcall fake_AutoPlay2_SingleCombat(__uint64_t a);
extern "C" void __stdcall fake_Game_PickTarget(__uint64_t a,  __uint64_t b , char c);

extern "C" void __stdcall func2();