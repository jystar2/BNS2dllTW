#pragma once

#include <string>
#include <iostream>
#include <thread>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "HttpRequest.h"
#include "json/json.h"
#include "CompareString.h"
#include "MinHook.h"
#include "bo64_header.h"

typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
typedef unsigned __int64 __uint64_t;
typedef __int64 __int64_t;



__uint64_t  SoBaseAddress = 0;
int IsInitiatedHook = 0;

#if defined _M_X64
#pragma comment(lib, "libMinHook.x64.lib")
#elif defined _M_IX86
#pragma comment(lib, "libMinHook.x86.lib")
#endif




// Helper function for MH_CreateHookApi().
template <typename T>
inline MH_STATUS MH_CreateHookApiEx(LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal)
{
    return MH_CreateHookApi(pszModule, pszProcName, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}

typedef int (WINAPI* MESSAGEBOXW)(HWND, LPCWSTR, LPCWSTR, UINT);

// Pointer for calling original MessageBoxW.
MESSAGEBOXW fpMessageBoxW = NULL;

// Detour function which overrides MessageBoxW.
int WINAPI DetourMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    return fpMessageBoxW(hWnd, L"Hooked!", lpCaption, uType);
}

int InitHook() {
    // Initialize MinHook.
    std::wstring user_name = L"TryHook1";
    //MessageBox(NULL, user_name.c_str(), TEXT("caption"), 0);
  
    if (IsInitiatedHook == 0) {
        if (MH_Initialize() != MH_OK)
        {
            DEBUG_PRINT("[+] MH_Initialize Fail!\n");
            return 1;
        }
    }

    /*
    // Create a hook for MessageBoxW, in disabled state.
    if (MH_CreateHookApiEx(L"user32", "MessageBoxW", &DetourMessageBoxW, &fpMessageBoxW) != MH_OK)
    {
        return 1;
    }
    user_name = L"TryHook2";
    //MessageBox(NULL, user_name.c_str(), TEXT("caption"), 0);
    // Enable the hook for MessageBoxW.
    if (MH_EnableHook(&MessageBoxW) != MH_OK)
    {
        return 1;
    }

    // Expected to tell "Hooked!".
    MessageBoxW(NULL, L"Not hooked...", L"MinHook Sample", MB_OK);

    // Disable the hook for MessageBoxW.
    if (MH_DisableHook(&MessageBoxW) != MH_OK)
    {
        return 1;
    }

    // Expected to tell "Not hooked...".
    MessageBoxW(NULL, L"Not hooked...", L"MinHook Sample", MB_OK);

    // Uninitialize MinHook.
    if (MH_Uninitialize() != MH_OK)
    {
        return 1;
    }
    */
    return 0;
}

template <typename T>
void HookGameFunByAddr(void* handle, __uint64_t FuncAddr, void* MyFunc, T** Old_Func) {

    __uint64_t TmpFuncAddress = 0;

    TmpFuncAddress = (__uint64_t)((__uint64_t)((__uint64_t)SoBaseAddress + (__uint64_t)FuncAddr));
    DEBUG_PRINT("[+] SoBaseAddress: %lx\n", SoBaseAddress);
    DEBUG_PRINT("[+] FuncAddr2: %lx\n", FuncAddr);

    DEBUG_PRINT("[+] TmpFuncAddress: %lx\n", TmpFuncAddress);
    MH_CreateHook(reinterpret_cast<LPVOID>(TmpFuncAddress), (LPVOID)MyFunc, reinterpret_cast<LPVOID*>(Old_Func));

    MH_EnableHook(reinterpret_cast<LPVOID>(TmpFuncAddress));
    DEBUG_PRINT("[+] Hook_OldFunctionAddr: %p\n", *(void**)Old_Func);

}

template <typename T>
void HookNormalFunByAddr(void* handle, __uint64_t FuncAddr, void* MyFunc, T** Old_Func) {

    void* TmpFuncAddress;

    TmpFuncAddress = (void*)(FuncAddr);

    DEBUG_PRINT("[+] HookNormalFunByAddr: %p\n", TmpFuncAddress);
    MH_CreateHook((LPVOID)TmpFuncAddress, (LPVOID)MyFunc, reinterpret_cast<LPVOID*>(Old_Func));

    MH_EnableHook(TmpFuncAddress);
    DEBUG_PRINT("[+] Hook_OldFunctionAddr: %p\n", *(void**)Old_Func);

}

void SetFuncAddr(void* handle, __uint64_t FuncAddr, void* MyFunc) {
    int* TmpFuncAddress;

    //DEBUG_PRINT("[+] GetFunctionAddr: %x\n", (int)TmpFuncAddress);
    *(__uint64_t**)MyFunc = (__uint64_t*)(SoBaseAddress + FuncAddr);
}




