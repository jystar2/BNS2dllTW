// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
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
#include "SocketInOut.h"
#include "SetHookGameFunHelper.h"
#include "GameFunAddr.h"
#include "UsefulPlugin.h"
#include "UTF16toUTF8_header.h"
#include "amd64xx.h"

//#include <curl/curl.h>


#if defined(GNUC)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored “-Wdeprecated-declarations”
#elif defined(_MSC_VER)
#pragma warning(disable : 4996)
#endif


#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma comment (lib, "jsoncpp.lib")



#define LOG_TAG "INJECT_LOAD"


//std::wstring GameName = L"Lineage2M.exe";
//std::wstring GameName = L"ProjectLH.exe";
std::wstring GameName = L"B2.exe";



int (*old_GetLevel) (int);
void HandleRecv(SOCKET clientSocket, std::string TmpStr);
HHOOK hookHandle;
HWND g_hMainWnd ;
unsigned int g_dwMainThreadId ;





typedef struct TPOINT
{
    LONG  x;
    LONG  y;
};


LONG_PTR OldWndProc = 0;
uint64_t LastFixCursorPosTime = 0;
TPOINT g_bkpint;
int IsFixCursorPos = 0;
bool g_is_WM_MOUSEMOVE = false;
HWND g_MainWnd = NULL;
CRITICAL_SECTION g_critical;

typedef BOOL(WINAPI* ClientToScreen_t)(HWND hWnd, LPPOINT lpPoint);
ClientToScreen_t old_ClientToScreen;


typedef BOOL(WINAPI* GetCursorPos_t)(LPPOINT lpPoint);
GetCursorPos_t old_GetCursorPos;
BOOL WINAPI fake_GetCursorPos(LPPOINT lpPoint)
{
    /*
    EnterCriticalSection(&g_critical);
    //ALOGD("fake_GetCursorPos g_is_WM_MOUSEMOVE %d,%d", g_bkpint.x, g_bkpint.y );

   // lpPoint->x = g_bkpint.x;
   // lpPoint->y = g_bkpint.y;

    //old_GetCursorPos(lpPoint);
    LeaveCriticalSection(&g_critical);
    */

    if (IsFixCursorPos == 1) {
        time_t timestamp_sec;
        uint64_t CurrentTime = time(&timestamp_sec);
        if (CurrentTime - LastFixCursorPosTime <= 2) {
            HWND g_GameWindowHwnd = GetProcessMainWindow();
            lpPoint->x = g_bkpint.x;
            lpPoint->y = g_bkpint.y;
            old_ClientToScreen(g_GameWindowHwnd, lpPoint);
        }
        else {
            IsFixCursorPos = 0;
        }
    }

    // GENERAL_PRINT("[+]fake_GetCursorPos  \n");
    if (NeedGetUI == 1) {
        //if (MainThreadTid != 0 && MainThreadTid == (unsigned int)GetCurrentThreadId()) {
        //GameThreadTid = MainThreadTid
        //if (GameThreadTid != 0) {
        //if (MainThreadTid != 0) {
        //    unsigned int GameTid = MainThreadTid; //*(unsigned int*)GameThreadTid;

     
        if (GameThreadTid != 0) {

            unsigned int GameTid = *(unsigned int*)GameThreadTid;

            if (GameTid == (unsigned int)GetCurrentThreadId() && GameTid != 0) {
                if (StartCallFunction != 0) {

                    //GENERAL_PRINT("[+]GameTid = %d   MainThreadTid= %d  \n", GameTid, MainThreadTid);
                    GENERAL_PRINT("[+]fake_GetCursorPos StartCallFunction = %d  \n", StartCallFunction);

                }
                mmemcmp(0, 0, 0);
             
            }
        }

    
        //}
    }
    else {
       
        if (IsHandlingCommand == 0) {  //防上Thread未讀完相撞
            IsHelperFunctioning = 1;

            if (DontAttackSwitch == 1 || ReactDontAttackSwitch == 1 || PriorityAttackSwitch == 1) {
                if (NeedHelperSelect) { //&& StartCallFunction == 0
                    if (MainThreadTid != 0) {
                        unsigned int GameTid = *(unsigned int*)GameThreadTid;
                        if (GameTid == (unsigned int)GetCurrentThreadId() && GameTid != 0) {
                            //GENERAL_PRINT("[+]IsHelperFunctioning = %d  \n", IsHelperFunctioning);
                          
                            if (IsGameHooked == 1 && IsPassGameHooked == 1) {
                                //GENERAL_PRINT("[+]SetNoAttackList 1\n");
                                ReadActorList();
                                if (DontAttackSwitch == 1 || ReactDontAttackSwitch == 1) {
                                    SetNoAttackList();
                                }
                                /*
                                if (PriorityAttackSwitch == 1) {
                                    if (IsReplacedGroupMonsterAddress == 0) {
                                        ResetPriorityAttackList();
                                    }
                                    else {
                                        ReAddPriorityAttackList();
                                    }

                                }
                                */
                                //GENERAL_PRINT("[+]SetNoAttackList 2\n");
                                //HelperPickTargetFunction();
                            }
                          
                            NeedHelperSelect = 0;

                        }
                    }
                }
            }
           
            IsHelperFunctioning = 0;

        }
          

    }



    if (IsFixCursorPos == 0) {
        return old_GetCursorPos(lpPoint);
    }
    return TRUE;
}




void Set_g_bkpint(int x, int y) {

    // EnterCriticalSection(&g_critical);
    g_bkpint.x = x;
    g_bkpint.y = y;

    time_t timestamp_sec;
    uint64_t CurrentTime = time(&timestamp_sec);
    LastFixCursorPosTime = CurrentTime;

    //LeaveCriticalSection(&g_critical);
}

BOOL fake_ClientToScreen(HWND hWnd, LPPOINT lpPoint)
{

    // EnterCriticalSection(&g_critical);

     //ALOGD("fake_ClientToScreen = 11");
    if (IsFixCursorPos == 1) {
        time_t timestamp_sec;
        uint64_t CurrentTime = time(&timestamp_sec);
        if (CurrentTime - LastFixCursorPosTime <= 2) {
            lpPoint->x = g_bkpint.x;
            lpPoint->y = g_bkpint.y;
        }
    }


    //ALOGD("fake_ClientToScreen %d,%d", g_bkpint.x, g_bkpint.y);

   //LeaveCriticalSection(&g_critical);


    return old_ClientToScreen(hWnd, lpPoint);
}

int SendBackReturn(int clientSocket, char* TmpStr)
{
    int iResult = send(clientSocket, TmpStr, strlen(TmpStr), 0);
    return iResult;
}


void print1(void)

{

    printf("hello world1\n");

}

void print2(void)

{

    GENERAL_PRINT("[+]hello world2\n");

}


void WaitHelperThreadDone() {
    int i = 0;
    time_t timestamp_sec; /* timestamp in second */
    __int64_t CurrentTime = time(&timestamp_sec);
    // GENERAL_PRINT("[+]WaitHelperThreadDone = %d", IsHelperFunctioning)
    if (IsHelperFunctioning != 0) {
        //GENERAL_PRINT("[+]IsHelperFunctioning1 = %d", IsHelperFunctioning)
        for (i = 0; i < 5000; i++) {
            usleep(1 * 500);
            time_t timestamp_sec2;
            __int64_t CurrentTime2 = time(&timestamp_sec2);
            if (CurrentTime2 - CurrentTime > 5) {
                break;
            }
            if (IsHelperFunctioning == 0) {
                break;
            }
        }
        // GENERAL_PRINT("[+]IsHelperFunctioning2 = %d", IsHelperFunctioning)
        IsHelperFunctioning = 0;
    }
}

void HandleRecv(SOCKET clientSocket, std::string TmpStr)
{

    Json::Reader reader;
    Json::FastWriter writer;
    Json::Value Readroot, UIroot , SendRoot , DataObj;
    std::string TmpVersion = "", ReturnStr = "{}";
    float TmpXCoor = 0, TmpYCoor = 0, TmpZCoor = 0;

    HttpRequest* httpReq;
    std::string res = "", cmd = "", link = "";
    int HaveData = 0, i = 0;
    time_t timestamp_sec;
    __uint64_t CurrentTime, TmpElement = 0;

    struct CoorType TmpCoor;
    __int64_t TmpMapID = 0;
    memset(buf, 0, sizeof(buf));
    memset(Largebuf,0, sizeof(Largebuf));
    memset(Resultbuf, 0, sizeof(Resultbuf));

    try {

        DEBUG_PRINT("[+]HandleRecv = %s\n",TmpStr.c_str());
        if (reader.parse(TmpStr, Readroot))
        {
            if (!Readroot["type"].isNull())
            {
                int FunctionType = Readroot["type"].asInt();
                if (!Readroot["cmd"].isNull())
                {
                    GENERAL_PRINT("[+]%s Function = %d cmd=%s", CurrentPlayerName, FunctionType, Readroot["cmd"].asString().c_str())
                }
                else {
                    GENERAL_PRINT("[+]%s Function = %d", CurrentPlayerName, FunctionType)
                }

                time_t timestamp_sec;
                CurrentTime = time(&timestamp_sec);
                LastConnectTime = CurrentTime;


                IsHandlingCommand = 1;
                WaitHelperThreadDone();

                switch (FunctionType) {
                case 0://UI
        
                    if (!Readroot["cmd"].isNull())
                    {
                        DEBUG_PRINT("[+]UI \n");

                        cmd = Readroot["cmd"].asString();
                        DEBUG_PRINT("[+]UI cmd = %s \n", cmd.c_str());
                        if (cmd == "GetUIElement") {
                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();
                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());
                            }


                            StartCallFunction = 91;
                            CurrentTime = time(&timestamp_sec);
                            if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                WaitMainThreadDone2();
                            }
                            if (StartCallFunction != 0) {
                                StartCallFunction = 0;

                             //   GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 0);
                                strcpy(Resultbuf, ReturnStr.c_str());
                            }

                            ReturnStr = Resultbuf;

                        }
                        else if (cmd == "GetUIElementEx" || cmd == "ClickUI") {
                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();
                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());
                            }

                            StartCallFunction = 92;
                            CurrentTime = time(&timestamp_sec);
                            if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                WaitMainThreadDone2();
                            }
                            if (StartCallFunction != 0) {
                                StartCallFunction = 0;

                               // GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 1);
                                strcpy(Resultbuf, ReturnStr.c_str());
                            }

                            ReturnStr = Resultbuf;
                        }
                        else  if (cmd == "GetIsUIHeadList") {

                            // DEBUG_PRINT("[+] GetIsUIHeadList!!!!!!!!!!!!!");

                            StartCallFunction = 88;
                            CurrentTime = time(&timestamp_sec);
                            if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                WaitMainThreadDone2();
                            }

                            if (StartCallFunction != 0) {
                                StartCallFunction = 0;
                              //  ReadAllUI();
                            }
                            //    DEBUG_PRINT("[+] GetIsUIHeadList2!!!!!!!!!!!!!");


                            int TmpElement = 0;
                            int ElementIsShow = 0;

                            if (UICheckListCount > 0) {
                                for (i = 1; i <= UICheckListCount; i++)
                                {
                                    if (UICheckList[i].IsUsed == 1)
                                    {

                                        snprintf(buf, sizeof(buf), "{\"UIid\":%d,\"UIName\":\"%s\",\"IsShow\":%d}", i, UICheckList[i].Text, UICheckList[i].IsShow);

                                        if (strlen(buf) + strlen(Largebuf) < sizeof(Largebuf))
                                        {
                                            if (HaveData == 1) {
                                                strcat(Largebuf, ",");//SplitLine
                                            }
                                            strcat(Largebuf, buf);
                                        }
                                        HaveData = 1;

                                    }
                                }
                            }

                            CreateJson("UIHeadList", Largebuf, Resultbuf, ResultbufSize);
                            ReturnStr = Resultbuf;
                        }
                        else  if (cmd == "GetChildUIListByName") {
                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();
                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());

                                TmpElement = FoundUIByTree(GlobalResult, 1);
                                if (TmpElement != 0)
                                {
                                    DEBUG_PRINT("[+]TmpElement = %lld \n", TmpElement);
                                    if (UWidget_IsVisible(TmpElement)) {
                                        struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(TmpElement);
                                        if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                                        }
                                        else {
                                            GlobalTmpVal = TmpElement;
                                            StartCallFunction = 89;
                                            CurrentTime = time(&timestamp_sec);
                                            if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                                WaitMainThreadDone2();
                                            }
                                            if (StartCallFunction != 0) {
                                                StartCallFunction = 0;
                                            //    GetChildUIList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 0);
                                                strcpy(Resultbuf, ReturnStr.c_str());
                                            }

                                            CreateJson("UIHeadList", Largebuf, Resultbuf, ResultbufSize);
                                            ReturnStr = Resultbuf;
                                        }
                                    }
                                }
                            }
                        }
                        else  if (cmd == "ChildUIList") {
                            if (!Readroot["obj"].isNull())
                            {
                                link = Readroot["obj"].asString();
                                GlobalTmpVal = strtoull(link.c_str(), 0, 16);

                                if (GlobalTmpVal != 0)
                                {
                                    StartCallFunction = 89;
                                    CurrentTime = time(&timestamp_sec);
                                    if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                        WaitMainThreadDone2();
                                    }
                                    if (StartCallFunction != 0) {
                                        StartCallFunction = 0;
                                    //    GetChildUIList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 0);
                                        strcpy(Resultbuf, ReturnStr.c_str());
                                    }

                                    CreateJson("ChildUIList", Largebuf, Resultbuf, ResultbufSize);
                                    ReturnStr = Resultbuf;
                                }


                                DEBUG_PRINT("[+]GlobalTmpVal = %lld \n", GlobalTmpVal);
                            }
                        }
                        else  if (cmd == "GetAllChildUIList") {
                            link = Readroot["obj"].asString();
                            GlobalTmpVal = strtoull(link.c_str(), 0, 16);

                            //if (GlobalTmpVal != 0)
                           // {
                                StartCallFunction = 90;
                                CurrentTime = time(&timestamp_sec);

                                if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                    WaitMainThreadDone2();
                                }

                                DEBUG_PRINT("[+]StartCallFunction = 90 Finish \n");

                                if (StartCallFunction != 0) {
                                    StartCallFunction = 0;
                                  //  GetChildUIList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 1);
                                    strcpy(Resultbuf, ReturnStr.c_str());
                                }

                                DEBUG_PRINT("[+]StrLen(Resultbuf) \n",strlen(Resultbuf));

                                CreateJson("ChildUIList", Largebuf, Resultbuf, ResultbufSize);
                                ReturnStr = Resultbuf;
                            //}

                        }
                        else if (cmd == "DumpAllUI") {


                            StartCallFunction = 87;
                            CurrentTime = time(&timestamp_sec);
                            if (IsCallingFunStarted == 1 && CurrentTime - LastCallingFunTime < 15) {
                                WaitMainThreadDone2();
                            }

                            SendRoot = GlobalSendRoot;

                            ReturnStr = writer.write(SendRoot);
                            DEBUG_PRINT("[+]ReturnStr = %s\n", ReturnStr.c_str());
                        }
                        else if (cmd == "AddSearchUIHead") {

                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();
                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());

                                int TmpTarget1 = 0;
                                for (i = 1; i <= UICheckListCount; i++)
                                {
                                    if (UICheckList[i].IsUsed == 1) {
                                        if (strcmp(GlobalResult, UICheckList[i].Text) == 0) {
                                            TmpTarget1 = 1;
                                            break;
                                        }
                                    }
                                }

                                if (TmpTarget1 == 0) {
                                    for (i = 1; i <= 500; i++)
                                    {
                                        if (UICheckList[i].IsUsed == 0) {

                                            UICheckList[i].IsUsed = 1;
                                            strcpy(UICheckList[i].Text, GlobalResult);
                                            UICheckList[i].IsShow = 0;
                                            UICheckListCount = i;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else if (cmd == "IsLoadingScreen") {
                        __uint64_t B2Client_instance = 0;
                            if (LHGameInstanceAddr != 0) {
                                __uint64_t B2Client_instance = *LHGameInstanceAddr;
                            }
                            if (B2Client__IsShowLoadingScreen(B2Client_instance)) {
                                SendRoot["Result"] = true;
                            }
                            else {
                                SendRoot["Result"] = false;
                            }
                            
                            ReturnStr = writer.write(SendRoot);
                        }
                        else if (cmd == "GetForgeSkipUnsafe") {
                            __uint64_t GameUIPtr = GetGameUI();

                            /*
                            __uint64_t ItemForgeUIPtr = *(__uint64_t*)(GameUIPtr + ItemForgeUIOffset);
                            char IsSkip = *(char*)(ItemForgeUIPtr + SkipUnsafeOffset); //ItemForgeUI::ToggleSkipUnsafeResult(__int64 a1, UIItemForgePanel **a2)
                            */
                            char IsSkip = 0;

                            if (LHGameInstanceAddr != 0) {
                                __uint64_t B2Client_instance = *LHGameInstanceAddr;
                                if (B2Client_instance) {
                                    IsSkip = B2Client_GetContentsOptionSkipEnchantResultPopup(B2Client_instance);
                                }
                            }


                            SendRoot["Result"] = IsSkip;
                            ReturnStr = writer.write(SendRoot);
                        }
                        else if (cmd == "test") {
                            __int64_t UIMangerPtr = GetUIManager();    // UIPanelAddr = GetUIPanel(UIMangerPtr,i);

                            if (UIMangerPtr != 0) {
                                for (size_t i = 0; i < 2000; i++)
                                {
                                    GetUIPanelList(UIMangerPtr);
                                }
                              
               
                            }
                        }
                        

                    
                    }

                  
                    //SendBackReturn(clientSocket, Resultbuf);

                    break;
                case 1://Click UI
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();

                        if (cmd == "ClickLink" || cmd == "PressLink" || cmd == "ForceClick") {
                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();

                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());


                                if (cmd == "ClickLink") {
                                    DEBUG_PRINT("[+] Click TmpElement = %lld \n", TmpElement);
                                    StartCallFunction = 21;
                                }
                                else  if (cmd == "ForceClick") {
                                    DEBUG_PRINT("[+] Click TmpElement = %lld \n", TmpElement);
                                    StartCallFunction = 26;
                                }
                                else if (cmd == "PressLink") {
                                    StartCallFunction = 22;
                                    WaitMainThreadDone2();
                                    usleep(200);

                                    memset(GlobalResult, 0, 3000);
                                    strcpy(GlobalResult, link.c_str());
                                    StartCallFunction = 25;

                                }
                                WaitMainThreadDone2();
                            }
                        }
                        else  if (cmd == "ScrollUI") {
                            if (!Readroot["link"].isNull())
                            {
                                link = Readroot["link"].asString();

                                memset(GlobalResult, 0, 3000);
                                strcpy(GlobalResult, link.c_str());


                                RandomVal = Readroot["Offset"].asFloat();

                                if (RandomVal) {

                                }


                                StartCallFunction = 30;

                                WaitMainThreadDone2();
                            }
                        }
                        else  if (cmd == "ScrollMap") {
                            if (!Readroot["x"].isNull())
                            {

                                TmpXCoor = Readroot["x"].asFloat();
                                TmpYCoor = Readroot["y"].asFloat();

                                DestCoor.XCoor = TmpXCoor;
                                DestCoor.YCoor = TmpYCoor;

                                StartCallFunction = 32;

                                WaitMainThreadDone2();
                            }
                        }
                        else if (cmd == "CapScreen") {
                            if (!Readroot["Text"].isNull())
                            {

                                InviteMemberName = Readroot["Text"].asString();
                                StartCallFunction = 86;

                                WaitMainThreadDone2();
                            }
                        }
                        else  if (cmd == "PassTutorial") {
                            StartCallFunction = 10;
                            WaitMainThreadDone2();


                        }

                    }
                    else {
                        if (!Readroot["obj"].isNull())
                        {
                            DEBUG_PRINT("[+]UI \n");

                            GlobalTmpVal = strtoull(Readroot["obj"].asString().c_str(), 0, 16);
                            DEBUG_PRINT("[+]GlobalTmpVal = %lld \n", GlobalTmpVal);
                            if (GlobalTmpVal != 0)
                            {
                                StartCallFunction = 27;
                                WaitMainThreadDone2();
                            }

                            SendRoot["Result"] = true;
                        }
                        else {
                            SendRoot["Result"] = false;
                        }
                        ReturnStr = writer.write(SendRoot);
                    }
                    

                   
                    

                    break;
                case 2://ReadPlayerInfo


                    DEBUG_PRINT("[+]GetPlayerLVExp");

                    memset(PKTargetName, 0, 300);
                    PKAttackerHp = 0;
                    PKAttackerMaxHp = 0;
                    PKAttackerMp = 0;
                    PKAttackerMaxMp = 0;

                    StartCallFunction = 23;
                    WaitMainThreadDone2();

                    char ObjAddress[50];
                    memset(ObjAddress, 0, 50);
                    snprintf(ObjAddress, 50, "%llx", AttackerPlayerID);
                    AttackerPlayerIDStr = ObjAddress;

                    // DEBUG_PRINT("[+] getMyHp Result = %f/%f", MyHp,MyMaxHp);
                    snprintf(buf, sizeof(buf), "{\"Lv\":%d,\"EXP\":%f,\"MaxEXP\":%f,\"hp\":%d,\"maxhp\":%d,\"mp\":%d,\"maxmp\":%d,\"name\":\"%s\",\"ServerName\":\"%s\",\"MoveState\":%d,\"gold\":%ld,\"Diamond\":%ld,\"IsAuto\":%d,\"IsFollowLeader\":%d,\"PlayState\":%d,\"IsFight\":%d,\"IsActionBtn\":%d,\"IsPK\":%d,\"AttackerID\":\"%s\",\"Atkname\":\"%s\",\"NowBagCount\":%d,\"MaxBagCount\":%d,\"Money2\":%ld,\"Money3\":%ld,\"Money4\":%ld,\"Money5\":%ld,\"Money6\":%ld,\"Money7\":%ld,\"Money8\":%ld,\"Money9\":%ld,\"Money10\":%ld,\"Money11\":%ld,\"Money12\":%ld,\"Money13\":%ld,\"Money14\":%ld,\"Money15\":%ld,\"Money16\":%ld,\"Money17\":%ld,\"Money18\":%ld,\"Money19\":%ld,\"Money20\":%ld,\"Money21\":%ld,\"Money22\":%ld,\"Money23\":%ld}"
                        , CurrentLv, CurrentExp, MaximumExp, MyHp, MyMaxHp, MyMp, MyMaxMp, CurrentPlayerName, CurrentServerName, IsMoving, MyMoney, MyDiamond, isAutoBattle, IsFollowPartyLeader, AutoPlayState, IsFighting, IsShowActionButton, IsPK, AttackerPlayerIDStr, PKTargetName, NowItemCount, MaxItemCount
                        , MyOtherMoney2, MyOtherMoney3, MyOtherMoney4, MyOtherMoney5, MyOtherMoney6, MyOtherMoney7, MyOtherMoney8, MyOtherMoney9, MyOtherMoney10, MyOtherMoney11, MyOtherMoney12, MyOtherMoney13, MyOtherMoney14, MyOtherMoney15, MyOtherMoney16, MyOtherMoney17, MyOtherMoney18, MyOtherMoney19, MyOtherMoney20, MyOtherMoney21, MyOtherMoney22, MyOtherMoney23);
                    ReturnStr = buf;

                    break;
                case 3://GetMyPos


                    StartCallFunction = 24;
                    WaitMainThreadDone2();

                  


                    snprintf(buf, sizeof(buf), "{\"MapName\":\"%s\",\"ZoneName\":\"%s\",\"MapID\":%d,\"ZoneID\":%lld,\"ZoneType\":%d,\"x\":%f,\"y\":%f,\"z\":%f}", MyMapName, MyZoneName, MyMapID, MyZoneID, MyZoneType, MyXCoor, MyYCoor, MyZCoor);

                    //DEBUG_PRINT("[+] ServerPosition  MyMapID = %d x = %f y = %f z = %f", MyMapID,MyXCoor,MyYCoor,MyZCoor);
                    ReturnStr = buf;


                    break;
                case 4: //ReadNPC / Actor


                    StartCallFunction = 16;
                    WaitMainThreadDone2();

                    ReturnStr = GlobalResultStr;

                    break;
                case 7://任務
              
                    StartCallFunction = 7;
                    WaitMainThreadDone2();

                    ReturnStr = GlobalResultStr;

                    break;
                case 8://获取背包
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();
                        if (cmd == "Bag") {
                            DEBUG_PRINT("[+] ReadBagItem1  \n");
                            StartCallFunction = 5;
                            WaitMainThreadDone2();


                            //RefreshItem = 1;
                            if (BagItemCount > 0)
                            {
                                HaveData = 0;
                                DEBUG_PRINT("[+] ReadBagItem  \n");
                                for (int i = 0; i <= BagItemCount; i++) {
                                    if (BagItem[i].IsUsed == 1)
                                    {
                                        snprintf(buf, sizeof(buf), "{\"id\":%d,\"Pos\":%d,\"Bag\":%d,\"ItemID\":%lld,\"obj\":\"%llx\",\"Type\":%d,\"EType\":%d,\"ESubType\":%d,\"Count\":%d,\"Grade\":%d,\"NameID\":\"%s\",\"isEquiped\":%d,\"isLock\":%d,\"BLv\":%d,\"NameHex\":\"%s\",\"Wei\":%f,\"Decompose\":%d,\"isEquip\":%d}", i, BagItem[i].id, BagItem[i].BagType, BagItem[i].ItemID, (__int64_t)BagItem[i].Pointer, BagItem[i].ItemType, BagItem[i].EquipItemType, BagItem[i].EquipItemSubType, BagItem[i].Count, BagItem[i].ItemGrade, BagItem[i].NameID, BagItem[i].isEquiped, BagItem[i].isLock, BagItem[i].EnhanceLv, BagItem[i].name, BagItem[i].ItemWeight, BagItem[i].isDeCompsable, BagItem[i].isEquipItem);

                                        if (strlen(buf) + strlen(Largebuf) < sizeof(Largebuf))
                                        {
                                            if (HaveData == 1) {
                                                strcat(Largebuf, ",");//SplitLine
                                            }
                                            strcat(Largebuf, buf);
                                        }
                                        HaveData = 1;
                                    }
                                }
                            }

                            CreateJson("ItemData", Largebuf, Resultbuf, ResultbufSize);
                            ReturnStr = Resultbuf;
                            // SendBackReturn(clientSocket, Resultbuf);
                        }
                        else if (cmd == "StorageList") {
                            DEBUG_PRINT("[+] ReadStorageItem1  \n");
                            StartCallFunction = 45;
                            WaitMainThreadDone2();


                            //RefreshItem = 1;
                            if (StorageItemCount > 0)
                            {
                                HaveData = 0;
                                DEBUG_PRINT("[+] ReadStorageItem  \n");
                                for (int i = 0; i <= StorageItemCount; i++) {
                                    if (StorageItem[i].IsUsed == 1)
                                    {
                                        snprintf(buf, sizeof(buf), "{\"id\":%d,\"Pos\":%d,\"Bag\":%d,\"ItemID\":%lld,\"obj\":\"%llx\",\"Type\":%d,\"EType\":%d,\"ESubType\":%d,\"Count\":%d,\"Grade\":%d,\"NameID\":\"%s\",\"isEquiped\":%d,\"isLock\":%d,\"BLv\":%d,\"NameHex\":\"%s\",\"Wei\":%f,\"Decompose\":%d,\"isEquip\":%d}", i, StorageItem[i].id, StorageItem[i].BagType, StorageItem[i].ItemID, (__int64_t)StorageItem[i].Pointer, StorageItem[i].ItemType, StorageItem[i].EquipItemType, StorageItem[i].EquipItemSubType, StorageItem[i].Count, StorageItem[i].ItemGrade, StorageItem[i].NameID, StorageItem[i].isEquiped, StorageItem[i].isLock, StorageItem[i].EnhanceLv, StorageItem[i].name, StorageItem[i].ItemWeight, StorageItem[i].isDeCompsable, StorageItem[i].isEquipItem);

                                        if (strlen(buf) + strlen(Largebuf) < sizeof(Largebuf))
                                        {
                                            if (HaveData == 1) {
                                                strcat(Largebuf, ",");//SplitLine
                                            }
                                            strcat(Largebuf, buf);
                                        }
                                        HaveData = 1;
                                    }
                                }
                            }

                            CreateJson("StorageData", Largebuf, Resultbuf, ResultbufSize);
                            ReturnStr = Resultbuf;
                            // SendBackReturn(clientSocket, Resultbuf);
                        }else  if (cmd == "GetStorage") {
                            if (!Readroot["obj"].isNull())
                            {
                               // FakePara1 = Readroot["id"].asInt();
                                FakeObject = Readroot["obj"].asString();
                                FakePara2 = Readroot["Count"].asInt();
                                StartCallFunction = 46;
                                WaitMainThreadDone2();

                            }
                        }
                        else  if (cmd == "Save") {
                            if (!Readroot["obj"].isNull())
                            {
                                // FakePara1 = Readroot["id"].asInt();
                                FakeObject = Readroot["obj"].asString();
                                FakePara2 = Readroot["Count"].asInt();
                                StartCallFunction = 47;
                                WaitMainThreadDone2();

                            }
                        }
                        else  if (cmd == "SelectSellItem") {
                            DEBUG_PRINT("[+] ReadBagItem1  \n");

                            CallResult = 0;
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 49;
                                WaitMainThreadDone2();

                                usleep(500 * 1000);

                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 53;
                                WaitMainThreadDone2();

                            }


                            SendRoot["Result"] = CallResult;
                            ReturnStr = writer.write(SendRoot);
                        }else if (cmd == "SelectTradeItem") {
                            DEBUG_PRINT("[+] ReadBagItem1  \n");

                            CallResult = 0;
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 48;
                                WaitMainThreadDone2();

                                usleep(500 * 1000);

                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 8;
                                WaitMainThreadDone2();

                            }

                            
                            SendRoot["Result"] = CallResult;
                            ReturnStr = writer.write(SendRoot);

                            // SendBackReturn(clientSocket, Resultbuf);
                        } else if (cmd == "SelectBagItem") {
                            CallResult = 0;
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 44;
                                WaitMainThreadDone2();

                                usleep(500 *1000);

                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 9;
                                WaitMainThreadDone2();

                            }

                            SendRoot["Result"] = CallResult;
                            ReturnStr = writer.write(SendRoot);
                        }else  if (cmd == "Use") {
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 3;
                                WaitMainThreadDone2();

                            }
                        }
                        else  if (cmd == "OpenUse") {
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 12;
                                WaitMainThreadDone2();

                            }
                        }
                        else  if (cmd == "Equip") {
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakePara2 = Readroot["switch"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 14;
       
                                WaitMainThreadDone2();

                            }
                        }
                        else  if (cmd == "Delete") {
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakePara2 = Readroot["Count"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                StartCallFunction = 4;
                                WaitMainThreadDone2();
                            }
                        }
                        else  if (cmd == "DeCompose") {
                            if (!Readroot["id"].isNull())
                            {
                                FakePara1 = Readroot["id"].asInt64();
                                FakeObject = Readroot["obj"].asString();
                                FakePara2 = Readroot["Count"].asInt64();
                                StartCallFunction = 6;
                                WaitMainThreadDone2();
                            }
                        }


                    }
                    break;
                case 9://MOVETO
                    if (!Readroot["MapID"].isNull())
                    {
                        TmpMapID = Readroot["MapID"].asInt();
                        TmpXCoor = Readroot["x"].asFloat();
                        TmpYCoor = Readroot["y"].asFloat();
                        TmpZCoor = Readroot["z"].asFloat();

                        DestCoor.XCoor = TmpXCoor;
                        DestCoor.YCoor = TmpYCoor;
                        DestCoor.ZCoor = TmpZCoor;

                        FakePara1 = TmpMapID;

                        GENERAL_PRINT("[+]MoveToMapXYZ is MapID = %d  X = %f  Y = %f  Z = %f  \n", TmpMapID, DestCoor.XCoor, DestCoor.YCoor, DestCoor.ZCoor);

                        StartCallFunction = 2;
                        WaitMainThreadDone2();

                        if (IsNeedHyperRun == 1) {
                            SendRoot["HyperRun"] = 1;
                            /*
                            Sleep(1000);
                            IsNeedHyperRun = 0;
                            StartCallFunction = 40;
                            WaitMainThreadDone2();
                            */
                        }
                        else {
                            SendRoot["HyperRun"] = 0;
                        }
                        ReturnStr = writer.write(SendRoot);
                    }

                    break;
                case 21://MOVETO
                    if (!Readroot["MapID"].isNull())
                    {
                        TmpMapID = Readroot["MapID"].asInt();
                        TmpXCoor = Readroot["x"].asFloat();
                        TmpYCoor = Readroot["y"].asFloat();
                        TmpZCoor = Readroot["z"].asFloat();

                        DestCoor.XCoor = TmpXCoor;
                        DestCoor.YCoor = TmpYCoor;
                        DestCoor.ZCoor = TmpZCoor;

                        FakePara1 = TmpMapID;

                        GENERAL_PRINT("[+]MoveToMapXYZ is MapID = %d  X = %f  Y = %f  Z = %f  \n", TmpMapID, DestCoor.XCoor, DestCoor.YCoor, DestCoor.ZCoor);

                        StartCallFunction = 1;
                        WaitMainThreadDone2();
                        if (IsNeedHyperRun == 1) {
                            SendRoot["HyperRun"] = 1;
                            /*
                            Sleep(1000);
                          
                            */
                        }
                        else {
                            SendRoot["HyperRun"] = 0;
                        }
                        ReturnStr = writer.write(SendRoot);
                    }

                    break;
                case 22://HyperRun
                    IsNeedHyperRun = 0;
                    StartCallFunction = 40;
                    WaitMainThreadDone2();
                    break;
                case 11://StopMove
                    StartCallFunction = 13;
                    WaitMainThreadDone2();
                    break;
                case 10://TargetInfo

                    DEBUG_PRINT("[+]TargetInfo");



                    StartCallFunction = 31;
                    WaitMainThreadDone2(); 


                    // DEBUG_PRINT("[+] getMyHp Result = %f/%f", MyHp,MyMaxHp);
                    snprintf(buf, sizeof(buf), "{\"Hp\":%d,\"MaxHp\":%d,\"Mp\":%d,\"MaxMp\":%d,\"name\":\"%s\",\"id\":%lld,\"ActorID\":\"%llx\"}", AttackerHp, AttackerMaxHp, AttackerMp, AttackerMaxMp, CurrentTargetName, NowTargetID, NowTargetID);
                    ReturnStr = buf;

                    break;
      
                case 12://Select Target


                    if (!Readroot["ActorID"].isNull())
                    {
                        FakeObject = Readroot["ActorID"].asString();
                        StartCallFunction = 37;
                        WaitMainThreadDone2();
                    }
                    break;
                case 13://Attack Target

      
                    if (!Readroot["ActorID"].isNull())
                    {
                        FakeObject = Readroot["ActorID"].asString();
                        StartCallFunction = 38;
                        WaitMainThreadDone2();
                    }
                    break;
                case 14://Attack Target in Range


                    if (!Readroot["ActorID"].isNull())
                    {
                        FakeObject = Readroot["ActorID"].asString();
                        StartCallFunction = 39;
                        
                        WaitMainThreadDone2();
                    }
                    SendRoot["Result"] = CallResult;
                    ReturnStr = writer.write(SendRoot);

                    break;
                case 18: //QuitSleepMode
                    RandomVal = 60;
                    if (!Readroot["flag"].isNull())
                    {
                        
                        if (Readroot["flag"].asInt() == 1) {
                            FakePara1 = 3;
                            StartCallFunction = 17;
                            WaitMainThreadDone2();
                            usleep(1000 * 1000);

                            FakePara1 = 2;
                            StartCallFunction = 17;
                            WaitMainThreadDone2();
                        }
                        else {
                            FakePara1 = Readroot["flag"].asInt();
                            StartCallFunction = 17;
                            WaitMainThreadDone2();
                        }
           
                    }

                    DEBUG_PRINT("[+]ReturnStr = %s\n", ReturnStr.c_str());
                    break;
                case 19: // Set Auto
                    if (!Readroot["flag"].isNull())
                    {
                        FakePara1 = Readroot["flag"].asInt64();
                        StartCallFunction = 35;

                        WaitMainThreadDone2();
                    }

                    break;
                case 20: // Escape

                    StartCallFunction = 36;

                    WaitMainThreadDone2();

                    break;

                    

                    
                case 30://Teaminfo

                    DEBUG_PRINT("[+]Teaminfo");
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();
                        if (cmd == "Get") {
                            StartCallFunction = 11;
                            WaitMainThreadDone2();

                            //RefreshItem = 1;

                            DEBUG_PRINT("[+] ReadTeamList  \n");
                            for (i = 0; i < 50; i++) {
                                if (TeamList[i].IsUsed == 1)
                                {

                                    //DEBUG_PRINT( "[+] BagItemid  %d  \n", BagItem[i].id);  
                                    
                                    snprintf(buf, sizeof(buf), "{\"id\":%d,\"PlayerID\":%ld,\"MapID\":%d,\"IsLeader\":%d,\"Pos\":%d,\"Name\":\"%s\",\"NowHP\":%ld,\"MaxHP\":%ld,\"Map\":\"%s\",\"x\":%f,\"y\":%f,\"z\":%f}", i, TeamList[i].PlayerID, TeamList[i].MapID, TeamList[i].IsLeader, TeamList[i].Pos, TeamList[i].PlayerName, TeamList[i].NowHP, TeamList[i].MaxHP, TeamList[i].PlayerMap, TeamList[i].PosX, TeamList[i].PosY, TeamList[i].PosZ);

                                    if (strlen(buf) + strlen(Largebuf) < sizeof(Largebuf))
                                    {
                                        if (HaveData == 1) {
                                            strcat(Largebuf, ",");//SplitLine
                                        }
                                        strcat(Largebuf, buf);
                                    }
                                    HaveData = 1;
                                }
                            }

                            CreateJson("TeamData", Largebuf, Resultbuf, ResultbufSize);
                            ReturnStr = Resultbuf;

                        }
                        else if (cmd == "Invite") {
                            InviteMemberName = Readroot["name"].asString();
                            StartCallFunction = 15;
                            WaitMainThreadDone2();
                        }
                    }

                    break;
                case 31:

                    if (!Readroot["Pos"].isNull())
                    {
                        FakePara1 = Readroot["Switch"].asInt();
                        FakePara2 = Readroot["Pos"].asInt();
                        StartCallFunction = 33;
                        WaitMainThreadDone2();

                    }

                    break;
                case 32:
                    StartCallFunction = 41;
                    WaitMainThreadDone2();

                    ReturnStr = GlobalResultStr;

                    break;
                case 33:
                    if (!Readroot["index"].isNull())
                    {
                        FakePara1 = Readroot["index"].asInt();
                        StartCallFunction = 42;
                        WaitMainThreadDone2();

                    }

                    break;
                case 34:
             
                    StartCallFunction = 43;
                    WaitMainThreadDone2();

                    ReturnStr = GlobalResultStr;

                    break;

                case 39: // 過濾

                    if (!Readroot["cmd"].isNull())
                    {
                        if (Readroot["cmd"].asString() == "GetDontAttackList") {
                            StartCallFunction = 71;
                            WaitMainThreadDone2();
                            ReturnStr = GlobalResultStr;
                        }
                        else if (Readroot["cmd"].asString() == "DontAttack") {

                            int PDontAttackSwitch = DontAttackSwitch;
                            if (!Readroot["Switch"].isNull())
                            {
                                DontAttackSwitch = Readroot["Switch"].asInt();
                            }

                            if (!Readroot["data"].isNull())
                            {
                                for (int i = 0; i <= 1000; i++)
                                {
                                    DontAttackList[i].IsUsed = 0;
                                }


                                for (int i = 0; i < Readroot["data"].size(); i++)
                                {
                                    DontAttackList[i + 1].IsUsed = 1;
                                    DontAttackList[i + 1].name = "";
                                    Json::Value v = Readroot["data"][i];

                                    if (!v["name"].empty())
                                    {
                                        DontAttackList[i + 1].name = v["name"].asString();
                                    }

                                    DontAttackListCount = i + 1;
                                }
                            }

                            if (DontAttackSwitch == 1 || PDontAttackSwitch == 1) {
                                StartCallFunction = 72;
                                WaitMainThreadDone2();

                                if (!Readroot["data"].isNull())
                                {
                                    for (int i = 0; i <= 3000; i++)
                                    {
                                        ChangedDontAttackList[i].IsUsed = 0;
                                    }
                                }
                            }

                        }
                        /*
                        else if (Readroot["cmd"].asString() == "ReactDontAttack") {

                            int PReactDontAttackSwitch = ReactDontAttackSwitch;
                            if (!Readroot["Switch"].isNull())
                            {
                                ReactDontAttackSwitch = Readroot["Switch"].asInt();
                            }

                            if (!Readroot["data"].isNull())
                            {
                                for (int i = 0; i <= 1000; i++)
                                {
                                    ReactDontAttackList[i].IsUsed = 0;

                                }
                                for (int i = 0; i < Readroot["data"].size(); i++)
                                {
                                    ReactDontAttackList[i + 1].IsUsed = 1;
                                    ReactDontAttackList[i + 1].name = "";
                                    Json::Value v = Readroot["data"][i];

                                    if (!v["name"].empty())
                                    {
                                        ReactDontAttackList[i + 1].name = v["name"].asString();
                                    }

                                    ReactDontAttackListCount = i + 1;
                                }
                            }

                            if (ReactDontAttackSwitch == 1 || PReactDontAttackSwitch == 1) {
                                StartCallFunction = 72;
                                WaitMainThreadDone2();
                            }



                        }
                      
                        else if (Readroot["cmd"].asString() == "PriorityAttack") {
                            int PPriorityAttackSwitch = PriorityAttackSwitch;
                            if (!Readroot["Switch"].isNull())
                            {
                                PriorityAttackSwitch = Readroot["Switch"].asInt();
                            }
                            if (!Readroot["data"].isNull())
                            {
                                for (int i = 0; i <= 1000; i++)
                                {
                                    PriortyAttackList[i].IsUsed = 0;
                                }
                                for (int i = 0; i < Readroot["data"].size(); i++)
                                {
                                    PriortyAttackList[i + 1].IsUsed = 1;
                                    PriortyAttackList[i + 1].name = "";
                                    Json::Value v = Readroot["data"][i];

                                    if (!v["name"].empty())
                                    {
                                        PriortyAttackList[i + 1].name = v["name"].asString();
                                    }

                                    PriortyAttackListCount = i + 1;
                                }
                                // PriortyAttackList = Readroot["data"];
                            }
                            if (PriorityAttackSwitch == 1 || PPriorityAttackSwitch == 1) {
                                StartCallFunction = 73;
                                WaitMainThreadDone2();
                            }


                        }
                        else if (Readroot["cmd"].asString() == "SetScanInterval") {
                            int PPriorityAttackSwitch = PriorityAttackSwitch;
                            if (!Readroot["Switch"].isNull())
                            {
                                IsSetScanInterval = Readroot["Switch"].asInt();
                                SettedScanInterval = Readroot["Value"].asInt();
                            }
                        }
                        */
                    }
                    break;
                case 60://視角

                    TmpXCoor = Readroot["x"].asInt();
                    TmpYCoor = Readroot["y"].asInt();
                    TmpZCoor = Readroot["z"].asInt();


                    FakePara1 = (__int64_t)TmpXCoor;
                    FakePara2 = (__int64_t)TmpYCoor;
                    FakePara3 = (__int64_t)TmpZCoor;

                    StartCallFunction = 50;
                    WaitMainThreadDone2();

                case 25://Buff List

                    StartCallFunction = 51;
                    WaitMainThreadDone2();

                    DEBUG_PRINT("[+] EffectMaxCount = %d  \n", EffectMaxCount);
                    if (EffectMaxCount > 0)
                    {
                        DEBUG_PRINT("[+] GetEffectData  \n");
                        for (i = 1; i <= EffectMaxCount; i++) {
                            if (EffectData[i].IsUsed == 1)
                            {

                                snprintf(buf, sizeof(buf), "{\"id\":%d,\"Type\":%d,\"Name\":\"%s\"}", EffectData[i].id, EffectData[i].Type, EffectData[i].name);

                                if (strlen(buf) + strlen(Largebuf) < sizeof(Largebuf))
                                {
                                    if (HaveData == 1) {
                                        strcat(Largebuf, ",");//SplitLine
                                    }
                                    strcat(Largebuf, buf);
                                }
                                HaveData = 1;
                            }
                        }
                    }

                    CreateJson("EffectData", Largebuf, Resultbuf, ResultbufSize);
                    ReturnStr = Resultbuf;


                    break;
                case 80:
                    RandomVal = 60;
                    if (!Readroot["rate"].isNull())
                    {
                        DEBUG_PRINT("[+]UI \n");

                        RandomVal = Readroot["rate"].asFloat();
                        //UEngine_SetMaxFPS(0, RandomVal);
                        StartCallFunction = 20;
                        WaitMainThreadDone2();
                    }

                    DEBUG_PRINT("[+]ReturnStr = %s\n", ReturnStr.c_str());
                    break;
                case 88:
                    DataObj["pid"] = (int)GetCurrentProcessId();
                    DataObj["hwnd"] = (int)GetProcessMainWindow();
                    TmpVersion = PluginVer;
                    DataObj["Version"] = TmpVersion;
                    
                    if (IsPassGameHooked == 0) {
                        DataObj["GameStatus"] = 0;
                    }
                    else {
                        if (IsGameHooked == 1) {
                            DataObj["GameStatus"] = 2;
                        }
                        else if (IsGameVersionPass == 0){
                            DataObj["GameStatus"] = 98;
                        }
        

                        time_t timestamp_sec; /* timestamp in second */
                        int CurrentTime = time(&timestamp_sec);

                        if (LastHelperThreadTime != 0 && CurrentTime - LastHelperThreadTime > 120) {
                            DataObj["GameStatus"] = 99;
                        }
                    }

                  //  DataObj["GameVerPass"] = IsGameVersionPass;

                    




                    SendRoot["data"] = DataObj;
                  
                   // ReturnStr = SendRoot.toStyledString(); //會有空格換行,很大
                  
                    ReturnStr = writer.write(SendRoot);
                    DEBUG_PRINT("[+]ReturnStr = %s\n", ReturnStr.c_str());
                    break;
                case 89:

                    IsDumpSo = 1;
                    SoBaseAddress = GetBaseAddress();
                    IsDumpSo = 0;
                    break;
                case 98: //取得IP

    
                    httpReq = new HttpRequest("aigamebot.selfip.com", 8088);
                    res = httpReq->HttpGet("aigamebot.selfip.com", 8088, "/OLD_SERVER/checkip.php", "");
                    DEBUG_PRINT("[+]IP=%s\n", res.c_str());
                    if (res.length() > 0) {
                        res = Replace(res, "\r", "");
                    }
                    
                    SendRoot["IPAddress"] = res;
                    ReturnStr = writer.write(SendRoot);

                    delete[] httpReq;
                    break;
                case 200:
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();
                        // ShowWindow(GetProcessMainWindow(), 9);

                        if (!Readroot["NoFront"].isNull())
                        {
                            int NoFront = Readroot["NoFront"].asInt();
                            if (NoFront != 1) {
                                SetActiveWindow(GetProcessMainWindow());
                                SetForegroundWindow(GetProcessMainWindow());
                            }
                        }
                        else {
                            SetActiveWindow(GetProcessMainWindow());
                            SetForegroundWindow(GetProcessMainWindow());
                        }

                        GENERAL_PRINT("[+]SetForegroundWindow\n");
                        if (cmd == "LeftDown") {
                            StartCallFunction = 301;
                            WaitMainThreadDone2();

                            //  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                        }
                        else if (cmd == "LeftUp") {
                            StartCallFunction = 302;
                            WaitMainThreadDone2();


                            //mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        }
                        else if (cmd == "LeftClick") {

                            StartCallFunction = 303;
                            WaitMainThreadDone2();


                            //mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        }
                        else if (cmd == "MoveTo") {


                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);
                            RecordCursorX = Readroot["x"].asInt();
                            RecordCursorY = Readroot["y"].asInt();


                            StartCallFunction = 304;
                            WaitMainThreadDone2();

                            //   GENERAL_PRINT("[+]MoveTo %d %d \n", Readroot["x"].asInt(), Readroot["y"].asInt());
                            //   SendMessage(GetProcessMainWindow(), WM_MOUSEMOVE, 0, MAKELPARAM(Readroot["x"].asInt(), Readroot["y"].asInt()));
                             //  SetCursorPos(rect.left + Readroot["x"].asInt(), rect.top + Readroot["y"].asInt() ); //+ 30

                        }
                        else if (cmd == "KeyDown") {

                            FakePara1 = Readroot["vk_code"].asInt();

                            StartCallFunction = 305;
                            WaitMainThreadDone2();



                            //keybd_event( Readroot["vk_code"].asInt(), 0, KEYEVENTF_KEYDOWN, 0);
                        }
                        else if (cmd == "KeyUp") {

                            FakePara1 = Readroot["vk_code"].asInt();
                            StartCallFunction = 306;
                            WaitMainThreadDone2();



                            // keybd_event(Readroot["vk_code"].asInt(), 0, KEYEVENTF_KEYUP, 0);
                        }

                    }
                    break;

                case 202:
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();
                        // ShowWindow(GetProcessMainWindow(), 9);

                        SetActiveWindow(GetProcessMainWindow());
                        SetForegroundWindow(GetProcessMainWindow());

                        GENERAL_PRINT("[+]SetForegroundWindow\n");
                        if (cmd == "LeftDown") {

                            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                        }
                        else if (cmd == "LeftUp") {
                            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        }
                        else if (cmd == "MoveTo") {
                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);

                            //   GENERAL_PRINT("[+]MoveTo %d %d \n", Readroot["x"].asInt(), Readroot["y"].asInt());
                            //   SendMessage(GetProcessMainWindow(), WM_MOUSEMOVE, 0, MAKELPARAM(Readroot["x"].asInt(), Readroot["y"].asInt()));
                            SetCursorPos(rect.left + Readroot["x"].asInt(), rect.top + Readroot["y"].asInt() + 0);

                        }
                        else if (cmd == "KeyDown") {
                            //  SendMessage(g_hMainWnd, WM_KEYDOWN, 32, 0);

                            keybd_event(Readroot["vk_code"].asInt(), 0, KEYEVENTF_KEYDOWN, 0);
                        }
                        else if (cmd == "KeyUp") {
                            //    SendMessage(g_hMainWnd, WM_KEYUP, 32, 0); 
                            keybd_event(Readroot["vk_code"].asInt(), 0, KEYEVENTF_KEYUP, 0);
                        }

                    }
                    break;

                case 201:
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();

                        GENERAL_PRINT("[+]SetForegroundWindow\n");
                        if (cmd == "LeftDown") {

                            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                        }
                        else if (cmd == "LeftUp") {
                            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        }
                        else if (cmd == "MoveTo") {
                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);

                            //   GENERAL_PRINT("[+]MoveTo %d %d \n", Readroot["x"].asInt(), Readroot["y"].asInt());
                            //   SendMessage(GetProcessMainWindow(), WM_MOUSEMOVE, 0, MAKELPARAM(Readroot["x"].asInt(), Readroot["y"].asInt()));
                            SetCursorPos(rect.left + Readroot["x"].asInt(), rect.top + Readroot["y"].asInt() + 0);

                        }
                        else if (cmd == "KeyDown") {
                            SendMessage(g_hMainWnd, WM_KEYDOWN, Readroot["vk_code"].asInt(), 0);
                        }
                        else if (cmd == "KeyUp") {
                            SendMessage(g_hMainWnd, WM_KEYUP, Readroot["vk_code"].asInt(), 0);
                        }

                    }
                    break;
                case 250:
                    if (!Readroot["cmd"].isNull())
                    {
                        cmd = Readroot["cmd"].asString();
                        if (cmd == "Size") {

                            int Width = Readroot["w"].asInt();
                            int Height = Readroot["h"].asInt();

                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);
                            MoveWindow(GetProcessMainWindow(), rect.left, rect.top, Width, Height, true);
                        }
                        else if (cmd == "GetSize") {
                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);
                            int Width = rect.right - rect.left;
                            int Height = rect.bottom - rect.top;
                            SendRoot["Width"] = Width;
                            SendRoot["Height"] = Height;
                            ReturnStr = writer.write(SendRoot);
                        }
                        else if (cmd == "Move") {
                            RECT rect;
                            GetWindowRect(GetProcessMainWindow(), &rect);

                            int X = Readroot["x"].asInt();
                            int Y = Readroot["y"].asInt();
                            int Width = rect.right - rect.left;
                            int Height = rect.bottom - rect.top;

                            MoveWindow(GetProcessMainWindow(), X, Y, Width, Height, true);
                        }
                    }


                    break;
                default:
                    break;
                }

                IsHandlingCommand = 0;

                GENERAL_PRINT("[+]%s Function Out2= %d", CurrentPlayerName, FunctionType)

            }
        }
        DataObj.clear();
        SendRoot.clear();
        Readroot.clear();
        UIroot.clear();
   
    }
    catch (const char* msg) {
        DEBUG_PRINT("[+]HandleRecv Error: %s\n", msg);
    }
    /*
    for (size_t i = 0; i < 10000; i++)
    {
        ReturnStr = ReturnStr + "{}";
    }
    */

    try {

      
        char SendLengthStr[9] ;
        memset(SendLengthStr, 0, 9);
        snprintf(SendLengthStr, 9, "%08d", ReturnStr.length());
        DEBUG_PRINT("[+]ReturnStr.length() = %s\n", SendLengthStr);

        int iResult = send(clientSocket, SendLengthStr, 8, 0);
        if (iResult == SOCKET_ERROR) {
            DEBUG_PRINT("[+]send Length failed with error: %d\n", WSAGetLastError());
        }
        if ((int)ReturnStr.length() > 0) {
            DEBUG_PRINT("[+]ReturnStr = %s\n", ReturnStr.c_str());
            iResult = send(clientSocket, ReturnStr.c_str(), (int)ReturnStr.length(), 0);
            if (iResult == SOCKET_ERROR) {
                DEBUG_PRINT("[+]send failed with error: %d\n", WSAGetLastError());
            }
        }
       
      //  DEBUG_PRINT("[+]Bytes Sent: %s\n", ReturnStr.c_str());
       // DEBUG_PRINT("[+]Bytes Sent: %ld\n", iResult);
    }
    catch (const char* msg) {
        DEBUG_PRINT("[+]HandleRecv Sent Error: %s\n", msg);
    }
}

void WriteFile(char* filename, char* Content, uint64_t size) {


    std::ofstream fout;
   // std::ofstream fout(filename);
    fout.open(filename, std::ios::out | std::ios::binary);

    // Validate that the file is open.
    if (!fout.is_open()) {
        return;
    }


    // Write the size to file.
   // fout << m_size << std::endl;

    fout.write((char*)Content, size);

    fout.close();

    /*
    FILE* file;
    file = fopen(filename, "w");
    fwrite(Content, 1, size, file);

    fclose(file);

            */
}


void AppendFile(char* filename, char* Content, uint64_t size) {


    std::ofstream fout;
    // std::ofstream fout(filename);
    fout.open(filename, std::ios::ios_base::app | std::ios::binary);

    // Validate that the file is open.
    if (!fout.is_open()) {
        return;
    }


    // Write the size to file.
   // fout << m_size << std::endl;

    fout.write((char*)Content, size);

    fout.close();

    /*
    FILE* file;
    file = fopen(filename, "ab+");
    fwrite(Content, 1, size, file);

    fclose(file);
    */

}

uint64_t GetBaseAddress() {
  
        LPCVOID pAddress = 0x00;
        MEMORY_BASIC_INFORMATION memInfo;
        char Type[10];
        char Protect[10];
        wchar_t dlpath[1024];

        uint64_t ResultAddress = 0;
        int DumpIndex = 0;
        int FileOneWriteSize = 0;
        int indexCount = 0;

        DEBUG_PRINT("[+] GetBaseAddress in \n");

        try {
            while (VirtualQuery(pAddress, &memInfo, sizeof(memInfo)) != 0)
            {
                indexCount = indexCount + 1;
                ZeroMemory(Type, 10);
                ZeroMemory(Protect, 10);
                ZeroMemory(dlpath, 1024);
                //DEBUG_PRINT("[+] indexCount = %d \n", indexCount);
                if (memInfo.State == MEM_FREE)
                {
                    DEBUG_PRINT(Type, "FREE");
                }
                else if (memInfo.Type == MEM_IMAGE)
                {
                    DEBUG_PRINT(Type, "Image");
                }
                else if (memInfo.Type == MEM_MAPPED)
                {
                    DEBUG_PRINT(Type, "mapped");
                }
                else if (memInfo.Type == MEM_PRIVATE)
                {
                    DEBUG_PRINT(Type, "private");
                }
                //DEBUG_PRINT("  %s  |", Type);
                //DEBUG_PRINT("  %lld  |", memInfo.RegionSize);
                if (memInfo.AllocationProtect == PAGE_READONLY)
                {
                    snprintf(Protect, 10, "_R_");
                }
                else if (memInfo.AllocationProtect == PAGE_READWRITE)
                {
                    snprintf(Protect, 10, "_RW_");
                }
                else if (memInfo.AllocationProtect == PAGE_EXECUTE)
                {
                    snprintf(Protect, 10, "_E_");
                }
                else if (memInfo.AllocationProtect == PAGE_EXECUTE_READWRITE)
                {
                    snprintf(Protect, 10, "_ERW_");
                }
                else if (memInfo.AllocationProtect == PAGE_EXECUTE_READ)
                {
                    snprintf(Protect, 10, "_ER_");
                }
                else if (memInfo.AllocationProtect == PAGE_EXECUTE_WRITECOPY)
                {
                    snprintf(Protect, 10, "_ERC_");
                }
            
                if (memInfo.AllocationProtect == PAGE_EXECUTE_WRITECOPY)
                {
                    DWORD r = GetModuleFileName((HMODULE)memInfo.AllocationBase, dlpath, sizeof(dlpath));
                   // DEBUG_PRINT("[+] dlpath %s ", dlpath);
                   // DEBUG_PRINT("[+]  %s  |", Protect);
                }
                if (dlpath != 0) {
                    if (wcsstr(dlpath, GameName.c_str())) {
                        // DEBUG_PRINT("[+]基地址：0x%p  Size=%lx", memInfo.BaseAddress, (uint64_t)memInfo.RegionSize);
                        // DEBUG_PRINT("[+]  %s  |", Protect);

                        // DEBUG_PRINT("[+]  %ls \n", dlpath);
                        if (ResultAddress == 0) {
                            ResultAddress = (uint64_t)memInfo.BaseAddress;
                        }

                        char FileName[513];

                        // snprintf(FileName, 512, "D:\\Dump\\BNS%d.m", DumpIndex);
                        // DEBUG_PRINT("[+]基地址： FileName=%s", FileName);
                        snprintf(FileName, 512, "D:\\Dump\\BNS.m");

                        if (DumpIndex > 0) {
                            uint64_t WriteSize = 0;
                            if (DumpIndex == 1) {
                               // WriteSize = FileOneWriteSize;
                                WriteSize = memInfo.RegionSize;
                            }
                            else {
                                WriteSize = memInfo.RegionSize;
                            }

                            if (IsDumpSo == 1) {
                                // if (DumpIndex <= 2) {
                               //AppendFile(FileName, (char*)memInfo.BaseAddress, WriteSize);
                                AppendFile(FileName, (char*)memInfo.BaseAddress, WriteSize);
                                DEBUG_PRINT("[+]p1： FileOneWriteSize=%lx\n", FileOneWriteSize);
                                DEBUG_PRINT("[+]p1： memInfo.BaseAddress=%lx\n", memInfo.BaseAddress);
                                DEBUG_PRINT("[+]p1： memInfo.RegionSize=%lx\n", memInfo.RegionSize);
                                // }
                               //  else {
                                   //  DEBUG_PRINT("[+]Finish out  = %lx \n", ResultAddress);
                                     //  goto outFindAddress;
                                       //return ResultAddress;
                               //  }
                            }
                          

                        }
                        else { //Header //前提是Virtual Address不變
                       
                            if (IsDumpSo == 1) {

                                char ChangeArr[] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0 ,0x0 };
                                char* OutPutArr = new char[memInfo.RegionSize];
                                DEBUG_PRINT("[+]p0： FileName= %s", FileName);
                                memcpy(OutPutArr, (char*)memInfo.BaseAddress, memInfo.RegionSize);

                                int ExeHeaderBegin = *(unsigned int*)((uint64_t)OutPutArr + 0x3C); //0x220
                                short NumberOfSections = *(unsigned short*)((uint64_t)OutPutArr + ExeHeaderBegin + 0x6);

                                int SECTION_HEADER_Start = ExeHeaderBegin + 0x108;
                                if (NumberOfSections > 0) {
                                    for (int i = 0; i < NumberOfSections; i++)
                                    {
                                        *(unsigned int*)((uint64_t)OutPutArr + SECTION_HEADER_Start + (unsigned int)(i * 0x28) + 0x10) = *(unsigned int*)((uint64_t)OutPutArr + SECTION_HEADER_Start + (unsigned int)(i * 0x28) + 0x8);
                                        *(unsigned int*)((uint64_t)OutPutArr + SECTION_HEADER_Start + (unsigned int)(i * 0x28) + 0x14) = *(unsigned int*)((uint64_t)OutPutArr + SECTION_HEADER_Start + (unsigned int)(i * 0x28) + 0xC);
                                    }
                                }


                                memcpy(OutPutArr + ExeHeaderBegin + 0x30, ChangeArr, 8);

                                // *(unsigned int*)((uint64_t)OutPutArr + 0x33C) = 0x1000;
                                // uint64_t WriteSize = *(unsigned int*)((uint64_t)OutPutArr + 0x33C);
                                // FileOneWriteSize = *(unsigned int*)((uint64_t)OutPutArr + 0x338);
                                uint64_t WriteSize = memInfo.RegionSize;
                                //char ChangeArr2[] = { 0x0, 0x0, 0x0, 0x0 };
                                //memcpy(OutPutArr + 0x2E4, ChangeArr2, 4);

                                //*(unsigned int*)((uint64_t)OutPutArr + 0x2EC) = 0x1000;

                                DEBUG_PRINT("[+]p0： WriteSize=%lx\n", WriteSize);
                                WriteFile(FileName, (char*)OutPutArr, WriteSize);
                            }

                        }


                        DumpIndex = DumpIndex + 1;
                    }
                }
                



                // DEBUG_PRINT("\n");//换行
                pAddress = (PVOID)((PBYTE)pAddress + memInfo.RegionSize);//指针运算 先转PBYTE是因为 RegionSize是Byte
            };
        }
        catch (const char* msg) {
            DEBUG_PRINT("[+]Error SoBaseAddress: %s\n", msg);
        }
        outFindAddress:

        DEBUG_PRINT("[+]SoBaseAddress = %lx \n", ResultAddress);

        return ResultAddress;
}




uint64_t ReadValidAddress() {

    LPCVOID pAddress = 0x00;
    MEMORY_BASIC_INFORMATION memInfo;
    char Type[10];
    char Protect[10];
    int CanRead = 0;

    GlobalAddressBegin.clear();
    GlobalAddressSize.clear();
    GlobalAddressCanRead.clear();

    try {
        while (VirtualQuery(pAddress, &memInfo, sizeof(memInfo)) != 0)
        {
            int CanRead = 0;

            if (memInfo.AllocationProtect == PAGE_READONLY)
            {
                CanRead = 1;
            }
            else if (memInfo.AllocationProtect == PAGE_READWRITE)
            {
                CanRead = 1;
            }
            else if (memInfo.AllocationProtect == PAGE_EXECUTE_READWRITE)
            {
                CanRead = 1;
            }
            else if (memInfo.AllocationProtect == PAGE_EXECUTE_READ)
            {
                CanRead = 1;
            }


            GlobalAddressBegin.push_back((uint64_t)memInfo.BaseAddress);
            GlobalAddressSize.push_back((uint64_t)memInfo.RegionSize);
            GlobalAddressCanRead.push_back(CanRead);


       
            // DEBUG_PRINT("\n");//换行
            pAddress = (PVOID)((PBYTE)pAddress + memInfo.RegionSize);//指针运算 先转PBYTE是因为 RegionSize是Byte
        };
    }
    catch (const char* msg) {

    }

    return 0;
}



int IsValidAddress(uint64_t Address) {

    for (int i = 0; i < GlobalAddressBegin.size(); i++)   //size()是指容器裏當前有多少個使用的元素；  
    {
        if (Address >= (uint64_t)GlobalAddressBegin[i] && Address <= (uint64_t)GlobalAddressBegin[i]  + (uint64_t)GlobalAddressSize[i] && GlobalAddressCanRead[i] == 1) {
            return 1;
        }
    }
    return 0;
}



void GetFNameStr(char* output, __uint64_t TmpAddress) {
    long Ret = 0;
    if (TmpAddress != 0) {
        // DEBUG_PRINT("[+] GetFNameStr1  \n");

        *(__uint64_t*)((__uint64_t)&FixedFNameMem.A + 8) = 0;
        InitFMem(&FixedFNameMem);

        GetFNameString(TmpAddress,(__uint64_t)&FixedFNameMem.A); //From UObject

       // DumpMemory256((char*)FixedFNameMem.A);
        strcpy(output, UTF16ToUTF8((char*)FixedFNameMem.A));
        FMemory_Free(FixedFNameMem.A);
    }

}


__uint64_t GetGameInstanceE()
{
    if (LHGameInstanceAddr == 0) {
        return 0;
    }
    __uint64_t TmpGameInstance = 0;
    __uint64_t B2Client_instance = *LHGameInstanceAddr;
    DEBUG_PRINT("[+] B2Client_instance= %lx  \n", B2Client_instance);
    if (B2Client_instance != 0) {
        TmpGameInstance = *(unsigned __int64*)(B2Client_instance + Game_Offset); //Game::
    }
     DEBUG_PRINT("[+] GameInstance Out= %lx  \n",TmpGameInstance);

    return TmpGameInstance;

}


__uint64_t GetGameUI()
{
    if (LHGameInstanceAddr == 0) {
        return 0;
    }
    __uint64_t TmpGameUI = 0;
    __uint64_t B2Client_instance = *LHGameInstanceAddr;
   //DEBUG_PRINT("[+]GetGameUI B2Client_instance= %lx  \n", B2Client_instance);
    if (B2Client_instance != 0) {
        TmpGameUI = *(__uint64_t*)(B2Client_instance + GameUIOffset);
    }
   // DEBUG_PRINT("[+] TmpGameUI Out= %lx  \n", TmpGameUI);

    return TmpGameUI;

}



__uint64_t UWidget_IsVisible(__uint64_t a){
   

    return UWidget_GetVisibility(a);

    /*
    if (UWidget_GetVisibility(a) == 0) {
        return 1;
    }
    else {
        return 0;
    }
    */
}

__int64_t __fastcall Game__GetAttackTargetId(__int64_t a)
{
    __int64_t v1; // x8
    __int64_t result; // x0

    v1 = *(__int64_t*)(a + GetAttackTargetId_Offset);
    if (v1)
        result = *(__int64_t*)(v1 + 40);
    else
        result = 0LL;
    return result;
}

int Game_IsAutoPlay(__int64_t a)
{
    __int64_t v1; // x8
    unsigned __int8 result; // x0
    int v3; // w8

    v1 = *(__int64_t*)(a + Game_IsAutoPlay_Offset1);
    result = 0;
    if (v1)
    {
        if (!*(unsigned __int8*)(v1 + Game_IsAutoPlay_Offset2))
        {
            v3 = *(unsigned __int8*)(v1 + 8);
            if (v3 != 3)
            {
                if (v3) {
                    result = 1;
                }
            }
        }
    }
    return result;
}


__int64_t GetUIPanel(__int64_t UIMangerPtr, int Index) {


    __int64_t UIPanelAddr = 0;

    if (UIMangerPtr != 0) {
        __int64_t v3 = *(__int64_t *)(UIMangerPtr) + 16LL * Index;
        __int64_t v5 = *(__int64_t*)(v3 + 8);
        return v5;
    }


   
    return 0;

}


int GetWidgetStr(__uint64_t TmpUObject, char* UObjectTypeName, char* FTextContent, int FTextContentsize) {

    int HasText = 0;
    struct FMemeryType TmpMem;

    int TextLen = 0;
    __uint64_t ImageSourcePathAddr;
    __uint64_t SRichTextBlockPtr = 0;
    __uint64_t TmpA = 0;
    std::string TmpStr = "";
      DEBUG_PRINT("[+] GetWidgetStr UObjectTypeName=%s",UObjectTypeName ) ;

    if (strcmp(UObjectTypeName, "TextBlock") == 0) {
        //  DEBUG_PRINT("[+] TSTextBlock " ) ;
        InitFMem(&TmpMem);
        //TextBlock_GetDisplayText((__uint64_t)&TmpMem.A,TmpUObject);
        TextBlock_GetDisplayText(TmpUObject, (__uint64_t)&TmpMem.A);
        // DEBUG_PRINT("[+] TSTextBlock Text Address=%x",TmpMem.A ) ;
   
        if (TmpMem.A != 0) {
            TmpA = FTextToString((__uint64_t)&TmpMem.A);
            // DEBUG_PRINT("[+] TSTextBlock Text Address=%x",TmpA ) ;
            if (TmpA != 0) {
                TextLen = *(int*)(TmpA + 8);
                if (TextLen > 0) {
                    TmpStr = UTF16ToUTF8(*(char**)TmpA);
                    memset(FTextContent, '\0', FTextContentsize);

                
                        if (TmpStr.size() >= FTextContentsize) {
                            memcpy(FTextContent, TmpStr.c_str(), FTextContentsize -1);
                        }
                        else {
                            snprintf(FTextContent, FTextContentsize, "%s", TmpStr.c_str());
                        }
               

                    HasText = 1;
                    //   DEBUG_PRINT("[+] TSTextBlock Text=%s sizeof FTextContent=%d", FTextContent,FTextContentsize) ;
                }
            }
        }
       
    }
    else if (strcmp(UObjectTypeName, "RichTextBlock") == 0) {

        // if (*(__uint64_t*)(TmpUObject + ButtonIconNameOffset) != 0){
             //      DEBUG_PRINT("[+] SRichTextBlockPtr" ) ;
        SRichTextBlockPtr = *(__uint64_t*)(TmpUObject + SRichTextBlockOffSet); //ULMRichTextBlock::SetText   if ( !*((_QWORD *)v2 + 107) )
      // DEBUG_PRINT("[+] SRichTextBlockPtr Text Address=%lx",SRichTextBlockPtr ) ;
        if (SRichTextBlockPtr != 0) {
            //  DEBUG_PRINT("[+] SRichTextBlockPtr Text Address=%lx",SRichTextBlockPtr ) ;
            InitFMem(&TmpMem);
            TmpMem.A = *(__uint64_t*)(SRichTextBlockPtr + SRichTextBlockTextOffSet); //SRichTextBlock::SetText     FText::operator=((_QWORD *)(a1 + 496), a2);
          //  DEBUG_PRINT("[+]  TmpMem.A  Address=%lx", TmpMem.A) ;
            TmpA = FTextToString((__uint64_t)&TmpMem.A);
            // DEBUG_PRINT("[+] TmpUObject + 107=%lx",*(__uint64_t*)(TmpUObject + 107*8) ) ;

            // DEBUG_PRINT("[+] TSTextBlock Text Address=%lx",TmpA ) ;
            if (TmpA != 0) {
                TextLen = *(int*)(TmpA + 8);
                if (TextLen > 0) {
                    TmpStr = UTF16ToUTF8(*(char**)TmpA);
                    memset(FTextContent, '\0', FTextContentsize);
                    if (TmpStr.size() >= FTextContentsize) {
                        memcpy(FTextContent, TmpStr.c_str(), FTextContentsize);
                    }
                    else {
                        snprintf(FTextContent, FTextContentsize, "%s", TmpStr.c_str());
                    }
                    HasText = 1;
                    //        DEBUG_PRINT("[+] TSTextBlock Text=%s sizeof FTextContent=%d", FTextContent,TextLen) ;
                }
            }
        }
    }



    else if (strcmp(UObjectTypeName, "Image") == 0) {  // ULMImage::SetTexture(ULMImage *this, UObject *a2)
      // DEBUG_PRINT("[+] LMImage ") ;
         //      DEBUG_PRINT("[+] Image ") ;
        if (*(__uint64_t*)(TmpUObject + ImageNamePathOffset) != 0) {

            //DEBUG_PRINT("[+] TSImage SourcePathAddr = %d",*(__uint64_t*)(TmpUObject + ImageNamePathOffset)+ 24) ;
       
            ImageSourcePathAddr = *(__uint64_t*)(TmpUObject + ImageNamePathOffset) + 24;
            if (ImageSourcePathAddr != 0) {
                memset(FTextContent, '\0', FTextContentsize);

            // InitFMem(&TmpMem);
            // GetFNameString((__uint64_t)ImageSourcePathAddr,(__uint64_t)&TmpMem.A);
            // snprintf(FTextContent, FTextContentsize, "%s", UTF16ToUTF8((char*)TmpMem.A));

            // GetFNameStr(FTextContent,(__uint64_t)ImageSourcePathAddr);
            
                GetFNameString((__uint64_t)ImageSourcePathAddr, (__uint64_t)&TmpMem.A);

                TmpStr = UTF16ToUTF8((char*)TmpMem.A);
                memset(FTextContent, '\0', FTextContentsize);
                if (TmpStr.size() >= FTextContentsize) {
                    memcpy(FTextContent, TmpStr.c_str(), FTextContentsize);
                }
                else {
                    snprintf(FTextContent, FTextContentsize, "%s", TmpStr.c_str());
                }

                FMemory_Free(TmpMem.A);
                HasText = 1;
            }

     

            // FMemory_Free(TmpMem.A);

    
            //DEBUG_PRINT("[+] TSImage SourcePath =%s", FTextContent) ;
        }

    }

    /*
     else if (strcmp(UObjectTypeName, "NkButton") == 0) {  //參考UTSWidgetSlot_Skill::SetButtonIcon
        // DEBUG_PRINT("[+] TSButton ") ;

         //   DEBUG_PRINT("[+] TSButton Addr2 = %x",*(int*)(TmpUObject + 288)) ;

         if (*(__uint64_t*)(TmpUObject + ButtonIconNameOffset) != 0) {
             ImageSourcePathAddr = *(__uint64_t*)(TmpUObject + ButtonIconNameOffset) + 24;

             InitFMem(&TmpMem);
             //GetFNameString((int)&TmpMem.A,(int)ImageSourcePathAddr);
             GetFNameString((__uint64_t)ImageSourcePathAddr, (__uint64_t)&TmpMem.A);

             // DEBUG_PRINT("[+] TSButton Image Source ImageSourcePathAddr=%x", ImageSourcePathAddr) ;

             memset(FTextContent, '\0', FTextContentsize);

             //DEBUG_PRINT("[+] TSButton Image Source Path=%s", UTF16ToUTF8((char*)TmpMem.A)) ;

             snprintf(FTextContent, FTextContentsize, "%s", UTF16ToUTF8((char*)TmpMem.A));

             FMemory_Free(TmpMem.A);

             HasText = 1;
             //DEBUG_PRINT("[+] TSButton Image Source Path=%s", FTextContent) ;
         }
     }
     */
     /*
       else if (strcmp(UObjectTypeName, "CanvasPanel") == 0) {  // ULMImage::SetTexture(ULMImage *this, UObject *a2)
           __int64 v2 = *((signed int*)TmpUObject + 78);
           std::string FinalImageName = "";
           std::string ImageName = "";
           __uint64_t v4 = 0;
           DEBUG_PRINT("[+] v2=%d", v2);
           if (v2 > 0) {
               for (int i = 0; i < v2; i++)
               {
                   ImageSourcePathAddr = *(__uint64_t*)((__uint64_t)(*((__uint64_t*)TmpUObject + 38) + 144LL) + 26*8 * i);
                   GetFNameString((__uint64_t)ImageSourcePathAddr, (__uint64_t)&TmpMem.A);
                   memset(FTextContent, '\0', FTextContentsize);
                   snprintf(FTextContent, FTextContentsize, "%s", UTF16ToUTF8((char*)TmpMem.A));
                   ImageName = FTextContent;
                   if (FinalImageName != "") {
                       FinalImageName = FinalImageName + "|";
                   }
                   FinalImageName = FinalImageName + ImageName;
                   HasText = 1;
               }
               memset(FTextContent, '\0', FTextContentsize);
               snprintf(FTextContent, FTextContentsize, "%s", FinalImageName.c_str());

           }
       
    }*/ else if (strcmp(UObjectTypeName, "Border") == 0) {  // ULMImage::SetTexture(ULMImage *this, UObject *a2)
    /*
        if (*(__uint64_t*)(TmpUObject + 55*8) != 0) {


            ImageSourcePathAddr = *(__uint64_t*)(TmpUObject + 55 * 8) + 24;

            memset(FTextContent, '\0', FTextContentsize);
            GetFNameString((__uint64_t)ImageSourcePathAddr, (__uint64_t)&TmpMem.A);
            memset(FTextContent, '\0', FTextContentsize);
            snprintf(FTextContent, FTextContentsize, "%s", UTF16ToUTF8((char*)TmpMem.A));
            FMemory_Free(TmpMem.A);

            HasText = 1;

        }
        
        /*
            if (*(__uint64_t*)(TmpUObject + 352 + 80) != 0) {


                ImageSourcePathAddr = *(__uint64_t*)(TmpUObject + 352 + 80) + 24;  //UBorder::SetBrushFromTexture //FSlateBrush::SetResourceObject

                memset(FTextContent, '\0', FTextContentsize);
                GetFNameString((__uint64_t)ImageSourcePathAddr, (__uint64_t)&TmpMem.A);
                memset(FTextContent, '\0', FTextContentsize);
                snprintf(FTextContent, FTextContentsize, "%s", UTF16ToUTF8((char*)TmpMem.A));
                FMemory_Free(TmpMem.A);

                HasText = 1;

            }
        */
    }else if (strcmp(UObjectTypeName, "WidgetSwitcher") == 0) {  //參考UTSWidgetSlot_Skill::SetButtonIcon 

        TmpA = UWidgetSwitcher_GetActiveWidgetIndex(TmpUObject);
        memset(FTextContent, '\0', FTextContentsize);
        snprintf(FTextContent, FTextContentsize, "%ld", TmpA);
        HasText = 1;
    }

    else {

        HasText = 0;
    }


    return HasText;

}


__int64 UWidgetSwitcher_GetActiveWidgetIndex(__int64 a1) //UWidgetSwitcher::GetActiveWidgetIndex SWidgetSwitcher 是  ANDROID  + 8 偏移 return 是+4
{
    __int64 v1; // rbx
    __int64 v2; // rcx
    __int64 v3; // rcx

    v1 = *(__int64*)(a1 + 320);  //Andrioid 的加8
    if (!v1)
        return *(unsigned int*)(a1 + 312);   //Andrioid 的加4
    if (*(unsigned int*)(v1 + 696))
    {
        v2 = *(__int64*)(v1 + 688);
        if (v2)
        {
            if ((*(unsigned __int8 (**)(void))(*(__int64*)v2 + 40i64))())
            {
                if (*(unsigned int*)(v1 + 696)) {
                    v3 = *(__int64*)(v1 + 688);
                    *(unsigned int*)(v1 + 680) = (*(__int64 (**)(void))(*(__int64*)v3 + 72i64))();
                }
                else {
                    v3 = 0i64;
                }
            }
        }
    }
    return *(unsigned int*)(v1 + 680);
}

__uint64_t FMemory_Free(__uint64_t a)
{
    __uint64_t TmpResult = 0;
    __uint64_t B = 1;
    if (a != 0) {
          TmpResult = FMemory_Free_Real(a); //
    }
    return TmpResult;
}




__uint64_t GameUI_GetPanel(int Index) {
    __uint64_t GameUIPtr = GetGameUI();

    if (GameUIPtr != 0) {
        __uint64_t v3 = *(__uint64_t*)GameUIPtr + 16 * Index;
        __uint64_t v5 = *(__uint64_t*)(v3 + 8);
        return v5;
    }
    return 0;
}

__uint64_t GameUI_FindPanelType(int PreIndex,__uint64_t TargetAddr) {
    __uint64_t GameUIPtr = GetGameUI();

    if (GameUIPtr != 0) {
        for (int Index = 0; Index < UIPanelMax; Index++)
        {
            __uint64_t v3 = *(__uint64_t*)GameUIPtr + 16 * Index;
            if (v3 != 0) {
                __uint64_t v5 = *(__uint64_t*)(v3 + 8);
                if (v5 == TargetAddr) {
                    return Index;
                }
            }
        }
    }
    return PreIndex;
}



__uint64_t GameUI_GetPanelByName(std::string TmpTarget) {
    __uint64_t GameUIPtr = GetGameUI();
    __uint64_t v5 = 0;
    if (GameUIPtr != 0) {

        int NowUIPanelMax = 0;
        if (ClosePanelStartAddr) {
            __uint64_t GameUIPtr = GetGameUI();
            if (GameUIPtr != 0) {
                char* UIPanelManager = (char*) (*(__uint64_t*)GameUIPtr);
                if (UIPanelManager) {
                    char Type = *UIPanelManager;
                    NowUIPanelMax = *((int*)ClosePanelStartAddr + 6 * Type + 4);
                    //GENERAL_PRINT("[+]NowUIPanelMax  = %d \n", NowUIPanelMax);
                    if (NowUIPanelMax > 0) {
                        for (int Index = 0; Index < NowUIPanelMax; Index++)
                        {
                            char* v2 = UIPanelManager;
                            __uint64_t v5 = *(__uint64_t*)&v2[16 * *(unsigned __int8*)(*((__uint64_t*)ClosePanelStartAddr + 3 * Type + 1) + Index) + 8];
                            if (v5) {
                                char IsOpened = *(char*)(v5 + IsPanel2OpenOffset); //UIPanelManager::closePanelAll(__int64 result, char a2)
                                if (IsOpened) {
                                    char UIPanelName[500];
                                    GetFNameStr(UIPanelName, (__uint64_t)(v5 + 24)); //From UObject
                                    if (strcmp(UIPanelName, TmpTarget.c_str()) == 0) {
                                        return v5;
                                    }
                                    // GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(UIStashPanel + 16) + 24));
                                   // GENERAL_PRINT("[+]GameUI_GetPanelByName UIPanelName = %s \n", UIPanelName);
                                }
                            }
                        }
                    }
                }
                

            }
        }

      
    
        /*
        for (int Index = 0; Index <= UIPanelMax; Index++)
        {
            __uint64_t v3 = *(__uint64_t*)GameUIPtr + 16 * Index;
            __uint64_t v5 = rU64(v3, 8);
            if (v5) {
                char UIPanelName[500];
                GetFNameStr(UIPanelName, (__uint64_t)(v5 + 24)); //From UObject
                if (strcmp(UIPanelName, TmpTarget.c_str()) == 0) {
                    return v5;
                }
                // GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(UIStashPanel + 16) + 24));
               // DEBUG_PRINT("[+]UIPanelName = %s \n", UIPanelName);
            }
        }
        */
    }
    return 0;
}

int __fastcall UUserWidget_IsInViewport(__uint64_t Tmpthis)
{
    __uint64_t v1; // x8
    unsigned int* v2; // x8
    unsigned int v3 = 0; // off

    if (!*((__uint64_t*)Tmpthis + 85))
        return 0LL;
    v1 = *((__uint64_t*)Tmpthis + 86);
    if (!v1)
        return 0LL;
    v2 = (unsigned int*)(v1 + 8);
    if ((__uint64_t)v2 != 0) {
        v3 = *v2;
    }
    if (v3 != 0) {
        return 1;
    }
    else {
        return 0;
    }
 
}

__int64_t GetPlayerHero(){
    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __int64_t PlayerHero = *(__int64_t*)(GameInstance + AgentOffset); // Game::GetPlayerHeroDisplay
        return PlayerHero;
    }
    return 0;
}


__uint64_t GameRecord2_EquipCollectionConditionInfo__equipCollectionConditions(__int64_t Tmpthis)
{
    __uint64_t result; // x0

    if (*(__uint64_t*)Tmpthis) {
        result = **(__uint64_t**)(Tmpthis);
    }
    else {
        result = 0;
    }

    return result;
}


__uint64_t GameRecord2_EquipCollection_equipCollectionConditionInfos(__int64_t Tmpthis)
{
    __uint64_t result; // x0

    if (*(__uint64_t*)Tmpthis) {
        result = *(__uint64_t*)(*(__uint64_t*)Tmpthis + 32);
    }
    else {
        result = 0;
    }
        
    return result;
}

int GetDictionaryMax(__int64_t DictPtr) {
    __int64_t MaxPtr = *(__int64_t*)(DictPtr + 16);

    __int64_t v6 = *(__int64_t*)(MaxPtr);

    int Count = 0;
    __int64_t v8 = v6;
    for (int i = 0; i < 60000; i++)
    {
        if (v8 == MaxPtr) {
            break;
        }
        Count = Count + 1;
        v8 = *(__int64_t*)v8;
    }
    return Count;
}


__uint64_t GetDictionaryItem(__uint64_t DictPtr,int Index) {
    __uint64_t MaxPtr = *(__uint64_t*)(DictPtr + 16);

    __uint64_t v6 = *(__uint64_t*)(MaxPtr);

    int Count = 0;
    __uint64_t Result = 0;

    __uint64_t v8 = v6;
    for (int i = 0; i < 60000; i++)
    {
        
        if (v8 == MaxPtr) {
            break;
        }

        if (Index == Count) {
            Result = *(__uint64_t*)(v8 + (3 * 8));
            break;
        }


        Count = Count + 1;
        v8 = *(__uint64_t*)v8;
    }
    return Result;
}


bool __fastcall EquipCollection__IsCompleted(__int64 a1)
{
    int* v2; // rdx
    __int64 v3; // rdi
    int v4; // ebx
    signed __int64 i; // r8
    int v6; // eax
    __int64* v7; // rcx

    if (!*(__int64*)(a1 + 16))
        return 0;
    v2 = *(int**)(a1 + 24);
    v3 = 0;
    v4 = 0;
    for (i = (signed __int64)&v2[2 * *(signed int*)(a1 + 32)]; v2 != (int*)i; v4 = v6)
    {
        v6 = v4 + 1;
        if (!*v2)
            v6 = v4;
        v2 += 2;
    }
    v7 = (__int64*)*(__int64*)(GameRecord2_EquipCollection_equipCollectionConditionInfos((__int64_t)(a1 + 16)) + 8);
    if (v7)
        v3 = (v7[1] - *v7) >> 3;
    return v4 == (int)v3;
}


std::string DumpEquipCollectList() {

    std::string Result = "[]";
    Json::Value TmpRoot;
    Json::FastWriter writer;
    char CollectionName[1000];
    char ItemName[1000];
    
    int MaxConut = 0;

    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
        if (PlayerHero != 0) {
           // __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
            __uint64_t EquipCollectionBook = *(__uint64_t*)(PlayerHero + EquipCollectionBookOffset); //UIEquipCollectionPanel::RefreshAll(__int64 result, char a2)  v19 = (int *)v11[177];
            


            __uint64_t EquipCollectionDictPtr = DataManager_GetEquipCollectionDictEv();
            DEBUG_PRINT("[+] EquipCollectionDictPtr =%llx  \n", EquipCollectionDictPtr);
            MaxConut = GetDictionaryMax(EquipCollectionDictPtr);
            DEBUG_PRINT("[+] MaxConut =%d   \n", MaxConut);

            for (int j = 0; j < MaxConut; j++)
            {
                __uint64_t GameRecord2_EquipCollection = GetDictionaryItem(EquipCollectionDictPtr,j);
                DEBUG_PRINT("[+] GameRecord2_EquipCollection =%lx   \n", GameRecord2_EquipCollection);
                if (GameRecord2_EquipCollection != 0) {

                    unsigned int EquipCollection_id = GameRecord2_EquipCollection_id((__uint64_t*)GameRecord2_EquipCollection);
                    DEBUG_PRINT("[+] EquipCollection_id =%d   \n", EquipCollection_id);
                    if (EquipCollection_id != 0) {

                        __int64 EquipCollection = EquipCollectionBook_GetEquipCollection((__int64_t*)EquipCollectionBook, EquipCollection_id);
                        DEBUG_PRINT("[+] EquipCollection =%lx   \n", EquipCollection);

                        int IsCompletedInt = 0;

                        if (EquipCollection != 0) {

                            bool IsCompleted = EquipCollection__IsCompleted(EquipCollection);
                            if (IsCompleted) {
                                IsCompletedInt = 1;
                            }
                            else {
                                IsCompletedInt = 0;
                            }
                        }


                        DEBUG_PRINT("[+] EquipCollection =%llx  \n", EquipCollection);
                        DEBUG_PRINT("[+] IsCompletedInt =%d   \n", IsCompletedInt);

                        if (GameRecord2_EquipCollection_equipCollectionConditionInfos(GameRecord2_EquipCollection) != 0) {


                            char* CollectionNamePtr = *(char**)(*(int64*)(GameRecord2_EquipCollection)+8);
                            if ((int64)CollectionNamePtr != 0) {
                                memset(CollectionName, '\0', 1000);
                                strcpy(CollectionName, CollectionNamePtr);
                            }
                            std::string CollectionNameStr = CollectionName;
                            DEBUG_PRINT("[+] CollectionName =%s   \n", CollectionName);



                            struct FMemeryType TmpMem3;
                            InitFMem(&TmpMem3);
                            if (CollectionNamePtr != 0) {
                                B2ClientTextFormat_GetText((int64)&TmpMem3.A, (int64)CollectionNamePtr);
                                if (TmpMem3.A != 0) {
                                    CollectionNameStr = (char*)*(int64*)TmpMem3.A;
                                }
                            }

                            Json::Value TmpChild;
                            TmpChild["EquipCollectionid"] = EquipCollection_id;
                            TmpChild["Name"] = CollectionNameStr;
                            TmpChild["IsCompleted"] = IsCompletedInt;




                           // DEBUG_PRINT("[+] equipCollectionConditionsPtr =%llx   \n", GameRecord2_EquipCollection_equipCollectionConditionInfos(GameRecord2_EquipCollection));
                            __uint64_t equipCollectionConditionsPtr = *(__uint64_t*)(GameRecord2_EquipCollection_equipCollectionConditionInfos(GameRecord2_EquipCollection) + 8);
                         //   DEBUG_PRINT("[+] equipCollectionConditionsPtr =%llx   \n", equipCollectionConditionsPtr);



                            __uint64_t equipCollectionConditionsStart = *(__uint64_t*)(equipCollectionConditionsPtr);
                            __uint64_t equipCollectionConditionsEnd = *(__uint64_t*)(equipCollectionConditionsPtr + 8);
                          //  DEBUG_PRINT("[+] equipCollectionConditionsStart =%lx   \n", equipCollectionConditionsStart);
                           // DEBUG_PRINT("[+] equipCollectionConditionsEnd =%lx   \n", equipCollectionConditionsEnd);


                            for (int k = 0; k < 100; k++)
                            {
                                if (equipCollectionConditionsStart + 8 * k == equipCollectionConditionsEnd) {
                                    break;
                                }

                                if (equipCollectionConditionsStart + 8 * k != equipCollectionConditionsEnd) {
                                        
                                    __uint64_t RealequipCollectionConditionsPtr = GameRecord2_EquipCollectionConditionInfo__equipCollectionConditions(equipCollectionConditionsStart + 8*k);
                                    __uint64_t Prev39 = *(__uint64_t*)(RealequipCollectionConditionsPtr + 8);

                                    if (Prev39 != 0) {
                                        __uint64_t v39End = *(__uint64_t*)(Prev39 + 8);
                                        __uint64_t v39 = *(__uint64_t*)(Prev39);
                                      //  DEBUG_PRINT("[+] v39 =%lx   \n", v39);
                                       // DEBUG_PRINT("[+] v39End =%lx   \n", v39End);

                                            
                                        unsigned int IsReg = 0;

                                        for (int i = 0; i < 10; i++)
                                        {

                                           // DEBUG_PRINT("[+] v392 =%lx   \n", v39);

                                            unsigned int itemId = **(unsigned int**)v39;
                                            unsigned int enchantLevel = (unsigned int)*(char*)(*(__uint64_t*)v39 + 64); //GameRecord2::EquipCollectionCondition::enchantLevel


                                            if (EquipCollection == 0) {
                                                IsReg = 0;
                                            }
                                            else {
                                                __uint64_t v11 = *((__uint64_t*)EquipCollection + 3);
                                                if (*(unsigned int*)(v11 + 8LL * i) == itemId && *(char*)(v11 + 8LL * i + 4) >= enchantLevel) {
                                                    IsReg = 1;
                                                }
                                            }

                                            v39 = v39 + 8;

                                            // DEBUG_PRINT("[+] v39 = %lx  \n", v39);

                                            if (v39 == v39End) {
                                                break;
                                            }

                                        }

                                        v39End = *(__uint64_t*)(Prev39 + 8);
                                        v39 = *(__uint64_t*)(Prev39);

                                        // DEBUG_PRINT("[+] IsCompletedInt =%d   \n", IsCompletedInt);

                                        for (int i = 0; i < 10; i++)
                                        {

                                           // DEBUG_PRINT("[+] v392 =%lx   \n", v39);

                                            unsigned int itemId = **(unsigned int**)v39;
                                            unsigned int enchantLevel = (unsigned int)*(char*)(*(__uint64_t*)v39 + 64); //GameRecord2::EquipCollectionCondition::enchantLevel
                                            //__uint64_t TmpGameRecord2_EquipCollection = *(__uint64_t*)(v39 + 16);
                                            //DEBUG_PRINT("[+] itemId =%d   \n", itemId);

                                            // char* TmpNamePtr = (char*)(*(__uint64_t*)TmpGameRecord2_EquipCollection + 8);




                                            Json::Value TmpChild2;
                                            TmpChild2["index"] = k;
                                            TmpChild2["Subindex"] = i;
                                            TmpChild2["enchantLevel"] = enchantLevel;
                                            TmpChild2["itemId"] = itemId;


                                            struct FMemeryType TmpMem;
                                            InitFMem(&TmpMem);

                                            // EnhanceVal = *(char*)(ULHItem + 60);
                                            int TmpItemGrade = (int)(char)Item2_GetItemGrade((int)itemId);

                                            TmpMem.A = Item2_GetItemName((int)itemId);
                                          //  DEBUG_PRINT("[+] Post TmpItemGrade = %d ", TmpItemGrade);

                                            memset(ItemName, '\0', 1000);
                                           // DEBUG_PRINT("[+] Count ");
                                            if (TmpMem.A != 0) {
                                                strcpy(ItemName, (char*)TmpMem.A);
                                          //      DEBUG_PRINT("[+] Count2 ");
                                            }

                                            std::string ItemNameStr = ItemName;
                                            TmpChild2["Grade"] = TmpItemGrade;
                                            TmpChild2["Name"] = ItemNameStr;

                                            TmpChild2["IsReg"] = IsReg;

                                            /*
                                            if (EquipCollection == 0) {
                                                TmpChild2["IsReg"] = 0;
                                            }
                                            else {
                                                __uint64_t v11 = *((__uint64_t*)EquipCollection + 3);
                                                if (*(unsigned int*)(v11 + 8LL * i) == itemId && *(char*)(v11 + 8LL * i + 4) >= enchantLevel) {
                                                    TmpChild2["IsReg"] = 1;
                                                }
                                                else {
                                                    TmpChild2["IsReg"] = 0;
                                                }

                                            }
                                            */

                                            TmpChild["Detail"].append(TmpChild2);


                                            // DEBUG_PRINT("[+] v391 = %lx  \n", v39);
                                            v39 = v39 + 8;

                                            // DEBUG_PRINT("[+] v39 = %lx  \n", v39);

                                            if (v39 == v39End) {
                                                break;
                                            }

                                            // DEBUG_PRINT("[+] enchantLevel =%lx   \n", v39);
                                        }
                                            
                                    }



                     

                                    


                                }
                            }
                            TmpRoot.append(TmpChild);
                                
                        }
                        
                       
                      //  }
                        
                    }

                    
                }
                

            }

            /*
            int MaxConut = *(int*)(EquipCollectionBook + 18 * 4);
            DEBUG_PRINT("[+] MaxConut =%d   \n", MaxConut);

   

            int DictionaryMax = GetDictionaryMax(EquipCollectionDictPtr);

            DEBUG_PRINT("[+] DictionaryMax =%llx  \n", DictionaryMax);

            __uint64_t v33 = *((__uint64_t*)EquipCollectionBook + 8);
            if (!v33) {
                v33 = (signed __int64)EquipCollectionBook + 56;
            }
                
            for (int j = 0; j < MaxConut; j++)
            {
                int v34 = *(int*)(v33 + 4 * j);
                if ((int)v34 == -1) {
                }
                else {
                    DEBUG_PRINT("[+] v34 =%d   \n", v34);
                    __uint64_t v35 = *(__uint64_t*)EquipCollectionBook;
                    __uint64_t* v37 = (__uint64_t*)(v35 + 56LL * v34 + 8);
                    __uint64_t GameRecord2_EquipCollection = (__uint64_t)(v37 + 16);
                    DEBUG_PRINT("[+] GameRecord2_EquipCollection =%lx   \n", GameRecord2_EquipCollection);
                    if (GameRecord2_EquipCollection_equipCollectionConditions(GameRecord2_EquipCollection) != 0) {
                        DEBUG_PRINT("[+] equipCollectionConditionsPtr =%lx   \n", GameRecord2_EquipCollection_equipCollectionConditions(GameRecord2_EquipCollection));
                        __uint64_t equipCollectionConditionsPtr = *(__uint64_t*)(GameRecord2_EquipCollection_equipCollectionConditions(GameRecord2_EquipCollection) + 8);
                        DEBUG_PRINT("[+] equipCollectionConditionsPtr =%lx   \n", equipCollectionConditionsPtr);

                        __uint64_t equipCollectionConditionsStart = *(__uint64_t*)(equipCollectionConditionsPtr);
                        __uint64_t equipCollectionConditionsEnd = *(__uint64_t*)(equipCollectionConditionsPtr + 8);
                        DEBUG_PRINT("[+] equipCollectionConditionsStart =%lx   \n", equipCollectionConditionsStart);
                        DEBUG_PRINT("[+] equipCollectionConditionsEnd =%lx   \n", equipCollectionConditionsEnd);
                        if (equipCollectionConditionsStart != equipCollectionConditionsEnd) {
                            __uint64_t v39 = equipCollectionConditionsStart;
                            for (int i = 0; i < 10; i++)
                            {

                                unsigned int itemId = **(unsigned int**)v39;
                                unsigned int enchantLevel = (unsigned int)*(char*)(*(__uint64_t*)v39 + 56); //GameRecord2::EquipCollectionCondition::enchantLevel
                                __uint64_t TmpGameRecord2_EquipCollection = *(__uint64_t*)(v39 + 16);
                                DEBUG_PRINT("[+] itemId =%d   \n", itemId);

                                char* TmpNamePtr = (char*)(*(__uint64_t*)TmpGameRecord2_EquipCollection + 8);

                                v39 = v39 + 8;
                                if (v39 == equipCollectionConditionsEnd) {
                                    break;
                                }
                            }

                        }
                    }
                   
                }
            }
            */
           

        }
    }

    if (MaxConut > 0) {
        Result = writer.write(TmpRoot);
        // DEBUG_PRINT("[+] Result =%s   \n", Result.c_str());
    }

    GlobalResultStr = Result;

    return GlobalResultStr;
}



std::string GetMissionList() {

    std::string Result = "[]";
    Json::Value TmpRoot;
    Json::FastWriter writer;
    signed int TotalQuestCount = 0;
    int64 QuestPtr = 0, GameRecord2QuestPtr = 0;
    char* QuestNamePtr;
    char Questcategory = 0, NowStep = 0;
    unsigned int Questid;
    unsigned int NowCount = 0, MaxCount = 0;
    std::string QuestNameStrEn;
    std::string QuestNameStr;
    char QuestName[1000];

    __int64_t PlayerHero = GetPlayerHero();
    if (PlayerHero != 0) {
        int64 QuestJournalPtr = *(int64*)(PlayerHero + QuestJournalOffset);  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)
        if (QuestJournalPtr != 0) {
            TotalQuestCount = *((signed int*)QuestJournalPtr + 2);
           //  GENERAL_PRINT("[+] TotalQuestCount =%d   \n", TotalQuestCount);
            if (TotalQuestCount > 0) {
                for (int i = 0; i < TotalQuestCount; i++)
                {
                    QuestPtr = (*(int64*)QuestJournalPtr + QuestSize * i);
                  //  GENERAL_PRINT("[+] QuestPtr =%llx   \n", QuestPtr);
                    GameRecord2QuestPtr = QuestPtr + 88;
                    if (QuestPtr != 0) {
                        Questcategory = *(char*)(*(int64*)(GameRecord2QuestPtr) + 4); //GameRecord2::Quest::category
                        Questid = 0;
                        if (*(int64*)(GameRecord2QuestPtr)) {
                            Questid = **(unsigned int**)(GameRecord2QuestPtr);
                        }

                      //  GENERAL_PRINT("[+] Questid =%d   \n", Questid);
                        QuestNamePtr = *(char**)(*(int64*)(GameRecord2QuestPtr)+ 72); //GameRecord2::Quest::name
                        if ((int64)QuestNamePtr != 0) {
                            memset(QuestName, '\0', 1000);
                            strcpy(QuestName, QuestNamePtr);
                        }

            
                        QuestNameStrEn = QuestName;
                        QuestNameStr = QuestNameStrEn;

                        struct FMemeryType TmpMem3;
                        InitFMem(&TmpMem3);
                        if (QuestNamePtr != 0) {
                            B2ClientTextFormat_GetText((int64)&TmpMem3.A, (int64)QuestNamePtr);
                            if (TmpMem3.A != 0) {
                                QuestNameStr = (char*)*(int64*)TmpMem3.A;
                            }
                        }


                   
                      //  GENERAL_PRINT("[+] QuestNameStr =%s   \n", QuestNameStr.c_str());
                        Json::Value TmpChild;
                        TmpChild["index"] = i;
                        TmpChild["Questid"] = Questid;
                        TmpChild["type"] = Questcategory;
                        TmpChild["EnName"] = QuestNameStrEn;
                        TmpChild["Name"] = QuestNameStr;

                        MaxCount = Quest_GetQuestMissionProgressMax(QuestPtr);
                        TmpChild["MaxCount"] = MaxCount;
                      //  GENERAL_PRINT("[+] MaxCount =%d   \n", MaxCount);
                        NowStep = *(unsigned char*)(QuestPtr );
                        TmpChild["NowStep"] = NowStep;

                        NowCount = *(unsigned short*)(QuestPtr + 12) ; //Quest::GetMissionProgressByPointNum

                       // GENERAL_PRINT("[+] NowCount =%d   \n", NowCount);
                        /*
                        signed int QuestIDListCount = *((signed int*)QuestJournalPtr + 6);  //QuestJournal::checkRemainQuestCompleteCount(QuestJournal *this, unsigned int a2)
                        if (QuestIDListCount > 0) {
                            int64 v25 = *((int64*)QuestJournalPtr + 2);
                            for (int j = 0; j < QuestIDListCount; j++)
                            {
                                if (Questid == *(unsigned int*)(v25 + 16 * j)) {
                                    NowCount = *(unsigned short*)(v25 + 16 * j + 4);
                                }
                            }
                        }
                        */
                        TmpChild["NowCount"] = NowCount;

                        // GENERAL_PRINT("[+] NowCount =%d   \n", NowCount);

                        TmpRoot.append(TmpChild);

                    }

                }
            }
        }
        
           
        
    }

    if (TotalQuestCount > 0) {
        Result = writer.write(TmpRoot);
       // DEBUG_PRINT("[+] Result =%s   \n", Result.c_str());
    }

    GlobalResultStr = Result;

    return GlobalResultStr;
}


void DumpEffectData()
{
    //EffectBoard::GetBuffEffect
    int BuffMaxCountOffset = 72;
    int BuffStartOffset = BuffMaxCountOffset - 72;//352; //ULMRObjectPoolManager::GetOrCreate<LMRDamageAction>
    int BuffPre1 = BuffMaxCountOffset - 64;// 360; //ULMRObjectPoolManager::GetOrCreate<LMRDamageAction>
    int BuffPre2 = BuffMaxCountOffset - 20;// 404; //ULMRObjectPoolManager::GetOrCreate<LMRDamageAction>
    int BuffPre3 = BuffMaxCountOffset - 8;// 416; //ULMRObjectPoolManager::GetOrCreate<LMRDamageAction>
    int BuffSizeOffset = 24;
    std::vector<int> TmpList;
    int HasBuffAdded = 0;

    EffectMaxCount = 0;

    for (int i = 0; i <= 1000; i++) {
        EffectData[i].IsUsed = 0;
    }



    __int64_t PlayerHero = GetPlayerHero();
    if (PlayerHero != 0) {
        int64 EffectBoardPtr = *(int64*)(PlayerHero + EffectBoardOffset);  //QuestJournal::GetQuestCount(QuestJournal *this, unsigned __int8 a2)
        if (EffectBoardPtr != 0) {
            if (*(int*)(EffectBoardPtr + BuffPre1) != *(int*)(EffectBoardPtr + BuffPre2)) {  //ULMRQuestManager::CompleteQuest

                int MaxCount = *(int*)(EffectBoardPtr + BuffMaxCountOffset);
                DEBUG_PRINT("[+]MaxCount = %x \n", MaxCount);

                __uint64_t v7 = 0;
                if (*(__uint64_t*)(EffectBoardPtr + BuffPre3)) {
                    v7 = *(__uint64_t*)(EffectBoardPtr + BuffPre3);
                }
                else {
                    v7 = EffectBoardPtr + BuffMaxCountOffset - 16;
                }
        

                if (v7) {
                    __uint64_t v14 = v7;
                    for (int i = 0; i < MaxCount; i++) {

                        int v8 = *(int*)(v14 + 4 * i);
                        DEBUG_PRINT("[+] i =%d   \n", i);
                        DEBUG_PRINT("[+] v8 =%d   \n", v8);

                        for (int k = 0; k < 1000; k++)
                        {

                            if (v8 != -1) { // && v8 <= MaxCount
                                __uint64_t BuffData = rU64(rU64(EffectBoardPtr, BuffStartOffset) + BuffSizeOffset * v8 + 8,0); // *(__uint64_t*)(ULMRBuffManager + BuffStartOffset) + BuffSizeOffset * v8 + 8;
                               // DEBUG_PRINT("[+]*(__uint64_t*)(BuffData + 8) = %llx \n", rU64(BuffData, 40)); // *(__uint64_t*)(BuffData + 40)
                                __uint64_t PreBuffData = rU64(BuffData, 0);
                                if (PreBuffData != 0) {  //GameRecord2::Effect3::id
                                    int Effect3id = rU32(PreBuffData, 0);

                                   // GENERAL_PRINT("[+] Effect3id =%lld   \n", Effect3id);

                                    __uint64_t EffectManualDict = DataManager3_GetEffectManualDictEv();
                                    if (EffectManualDict != 0) {
                                        __uint64_t  GameRecord2_EffectManual = EffectManualDict_GetEffectByIdEv(EffectManualDict, Effect3id);

                                        if (*(__uint64_t*)GameRecord2_EffectManual) {

                                            //GameRecord2::EffectManual::nameAlias 
                                            __uint64_t  NameIDPtr = (*(__uint64_t*)GameRecord2_EffectManual + 24);
                                            if (NameIDPtr) {
                                                __uint64_t NameID = *(__uint64_t*)(NameIDPtr);
                                              //  GENERAL_PRINT("[+] NameID =%lld   \n", NameID);



                                                std::string CollectionNameStr = "";
                                                struct FMemeryType TmpMem3;
                                                InitFMem(&TmpMem3);
                                                if (NameID != 0) {
                                                    B2ClientTextFormat_GetText((int64)&TmpMem3.A, (int64)NameID);
                                                    if (TmpMem3.A != 0) {
                                                        CollectionNameStr = (char*)*(int64*)TmpMem3.A;
                                                    }
                                                }

                                                HasBuffAdded = 0;
                                                if (TmpList.size() > 0) {
                                                    for (int b = 0; b < TmpList.size(); b++)   //size()是指容器裏當前有多少個使用的元素；
                                                    {
                                                        if (TmpList[b] == Effect3id) {
                                                            HasBuffAdded = 1;
                                                        }
                                                    }

                                                }

                                                if (HasBuffAdded == 0) {

                                                    DEBUG_PRINT("[+]NameID = %x \n", NameID);

                                                    //GameRecord2::Effect3::totalDur

                                                    //if ((unsigned __int8)GameRecord2::Effect3::durType((GameRecord2::Effect3*)a2) == 3)

                                                    //DEBUG_PRINT("[+]EffectName = %s \n", EffectName);

                                                    for (int j = 1; j <= 1000; j++) {
                                                        if (EffectData[j].IsUsed == 0) {
                                                            EffectData[j].IsUsed = 1;
                                                            EffectData[j].id = Effect3id;
                                                           // EffectData[j].Type = BuffType;
                                                            if (strlen(CollectionNameStr.c_str()) > 0 && strlen(CollectionNameStr.c_str()) < 500) {
                                                                strcpy(EffectData[j].name, CollectionNameStr.c_str());
                                                            }
                                                            EffectMaxCount = j;
                                                            break;
                                                        }
                                                    }

                                                            //GameRecord2::Effect3::totalDur

                                                    TmpList.push_back(Effect3id);
                                                }

                                            }

                                            

                                        }
                                        
                                    }
                                   
                                }
                            }
                            else {
                                break;
                            }
                            v8 = *(int*)(*(__uint64_t*)(EffectBoardPtr + BuffStartOffset) + BuffSizeOffset * v8 + (BuffSizeOffset - 8));
                            if ((int)v8 == -1) {
                                break;
                            }
                        }
                    }
                }
            }


            
        }
    }
            
}


std::string GetMapIconList() {

    std::string Result = "[]";
    Json::Value TmpRoot;
    Json::FastWriter writer;
    signed int MapIconCount = 0, TotalMapIconCount = 0;
    char MapIconName[500];
    char MapIconobjectText[500];
    std::string NameText;
    std::string objectText;
    int NowCount = 0;
    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        ReadValidAddress();
        if (GameInstance != 0) {
            __int64_t UI3DMapPanel = 0;
            __int64_t UI3DWorldMap = 0;
            //UI3DMapPanel = GameUI_GetPanel(UI3DWorldMapType); 
            UI3DMapPanel = GameUI_GetPanelByName(UI3DWorldMapName);
            if (UI3DMapPanel != 0) {
                UI3DWorldMap = UI3DMapPanel + UI3DWorldMapOffset;  //UI3DMapPanel::OnTabSelectInfoPopupAppearMonster

                    for (int i = 0; i <= 6; i++)
                    {
                        int64 v19 = UI3DWorldMap + 80LL * i;
                        MapIconCount = *(int*)(v19 + UI3DWorldMapIconMaxOffSet);
                        //GENERAL_PRINT("[+] MapIconCount =%d  \n", MapIconCount);
                 
                        if (MapIconCount > 0) {
                            for (int j = 0; j < MapIconCount; j++)
                            {
                                int64 UI3DWorldMapIconStart = *(int64*)(v19 + UI3DWorldMapIconStartOffSet);
                               // GENERAL_PRINT("[+] UI3DWorldMapIconStart =%llx  \n", UI3DWorldMapIconStart);
                                int64 v22 = *(int64*)(v19 + UI3DWorldMapIconMaxOffSet - 8);
                               // GENERAL_PRINT("[+] v22 =%llx  \n", v22);
                                if (v22 != 0) {
                                    int v6 = *(int*)(v22 + 4 * j );
                                    //GENERAL_PRINT("[+] v6 =%d  \n", v6);
                                    if ((int)v6 != -1 ) { //&& v6 > 0

                                        NowCount = 0;
                                       
                                        while (1)
                                        {
                                            
                                            unsigned int v25 = *(unsigned int*)(UI3DWorldMapIconStart + (v6 * 32));
                                           // GENERAL_PRINT("[+] v25 =%d  \n", v25);
                                            if (v6 != -1) { //&& v6 != 0
                                                int64 v23 = UI3DWorldMapIconStart + 32 * v6;
                                                int64 UI3DMapObjectMapIconPtr = *(int64*)(v23 + 8);

                                              //  GENERAL_PRINT("[+] UI3DMapObjectMapIconPtr =%llx  \n", UI3DMapObjectMapIconPtr);
                                                if (UI3DMapObjectMapIconPtr != 0) {
                                                    struct FMemeryType TmpMem;
                                                    InitFMem(&TmpMem);
                                                    UI3DWorldMap_getUI3DMapObjectMapIconObject(UI3DWorldMap, (int64)&TmpMem.A, v25);

                                                    if (TmpMem.A != 0) {
                                                        int64 GameRecord2_MapIconObjectPtr = UI3DMapObjectMapIconPtr + 32;

                                                        if (*(int64*)GameRecord2_MapIconObjectPtr != 0) {


                                                            //GENERAL_PRINT("[+] *(int64*)GameRecord2_MapIconObjectPtr =%llx   \n", *(int64*)GameRecord2_MapIconObjectPtr);
                                                            if (IsValidAddress(GameRecord2_MapIconObjectPtr) == 1) {
                                                                if (IsValidAddress(*(int64*)GameRecord2_MapIconObjectPtr + 4) == 1) {

                                                                    memset(MapIconName, 0, 500);
                                                                    memset(MapIconobjectText, 0, 500);

                                                                    unsigned int MapIconObjectid = **(unsigned int**)GameRecord2_MapIconObjectPtr;
                                                                    char objectKindType = *(char*)(*(int64*)GameRecord2_MapIconObjectPtr + 4); //GameRecord2::MapIconObject::objectKindType
                                                                    //GENERAL_PRINT("[+]objectKindType  =%d   \n", objectKindType);
                                                                    char objectType = *(char*)(*(int64*)GameRecord2_MapIconObjectPtr + 5); //GameRecord2::MapIconObject::objectType
                                                                  //  GENERAL_PRINT("[+]objectType  =%d   \n", objectType);
                                                                    int index = v25;

                                                                  //  GENERAL_PRINT("[+]IsValidAddress  =%d   \n", IsValidAddress(*(int64*)GameRecord2_MapIconObjectPtr + 16));
                                                                    if (IsValidAddress(*(int64*)GameRecord2_MapIconObjectPtr + 16) == 1) {
                                                                        if (*(int64*)(*(int64*)GameRecord2_MapIconObjectPtr + 16) != 0) {
                                                                            char* nameAlias = (char*)*(int64*)(*(int64*)GameRecord2_MapIconObjectPtr + 16); //GameRecord2::MapIconObject::nameAlias







                                                                            strcpy(MapIconName, nameAlias);


                                                                            /*
                                                                            GENERAL_PRINT("[+] nameAlias =%s  \n", nameAlias);
                                                                            if (IsValidAddress(*(int64*)GameRecord2_MapIconObjectPtr + 72) == 1) {
                                                                                if (*(int64*)(*(int64*)GameRecord2_MapIconObjectPtr + 72 != 0)) {
                                                                                    if (IsValidAddress(*(int64*)(*(int64*)GameRecord2_MapIconObjectPtr + 72) == 1)) {
                                                                                        char* ObjectTextAlias = (char*)*(int64*)(*(int64*)GameRecord2_MapIconObjectPtr + 72);
                                                                                        GENERAL_PRINT("[+] ObjectTextAlias =%s  \n", ObjectTextAlias);
                                                                                        strcpy(MapIconobjectText, ObjectTextAlias);
                                                                                    }

                                                                                }
                                                                            }
                                                                    */




                                                                        }

                                                                    }

                                                                    NameText = MapIconName;
                                                                    objectText = MapIconobjectText;


                                                                    Json::Value TmpChild;
                                                                    TmpChild["Type"] = i;
                                                                    // TmpChild["SubType"] = j;
                                                                    TmpChild["objectType"] = (int)objectType;
                                                                    TmpChild["name"] = NameText;
                                                                    TmpChild["id"] = MapIconObjectid;
                                                                    
                                                                   // TmpChild["objectText"] = objectText;
                                                                    TmpChild["index"] = index;


                                                                    TmpRoot.append(TmpChild);
                                                                    NowCount = NowCount + 1;

                                                                }
                                                            }
                                                        }

                                                    }


                                                }

                                            }

                                           // GENERAL_PRINT("[+] index  v25 =%d  \n", v25);
                                       
                                            v6 = *(unsigned int*)(UI3DWorldMapIconStart + 32 * v6 + 24);
                                            if ((int)v6 == -1) {
                                                break;
                                            }

                                            
                                        }
                                       
                                        
                                        

                         

                                      //  GENERAL_PRINT("[+] NowCount =%d  \n", NowCount);

                                        
                                    }

                                }
                            }
                        }
                        //GENERAL_PRINT("[+] MapIconCount =%d  \n", MapIconCount);

                        TotalMapIconCount = TotalMapIconCount + NowCount;
                    }
            


            }
            

        }
    }

    if (TotalMapIconCount > 0) {
        Result = writer.write(TmpRoot);
        // DEBUG_PRINT("[+] Result =%s   \n", Result.c_str());
    }

    GlobalResultStr = Result;

    return GlobalResultStr;
}



int GetUIPanelList(__uint64_t UIMangerPtr) { // ALHHUD::GetWidgetData

    __int64_t GameUI = UIMangerPtr;
    __int64_t IPanel = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (UiElement[i].IsUsed == 1) {
            UiElement[i].IsUsed = 0;
        }
        else {
            break;
        }
    }

    //GameUI::GetPanel
    //Tutorial::getPanelTypeByUIPanel


    int Count = 0;


    int i;


    __int64_t v11;
    __int64_t* v15;
    struct FMemeryType TmpMem;
    InitFMem(&TmpMem);
    TmpMem.A = 0;
    TmpMem.B = 0;
    TmpMem.C = -1;
    char UIPanelName[500];

//    DEBUG_PRINT("[+] GetUIPanelList Begin:%d ", Count);
    v11 = UserWidget_GetPrivateStaticClass();
    GetObjectsOfClass(v11, (__uint64_t)&TmpMem.A, 1, 16, 0);
    int v12 = (unsigned int)(TmpMem.B);
    i = -1;
    

    int v13 = i + 1;
    __int64_t v14 = TmpMem.A;
    for (i = v13; v13 < (int)(TmpMem.B); i = ++v13)
    {
        if (*(__int64_t*)(TmpMem.A + 8 * v13))
            break;
    }

   // DEBUG_PRINT("[+] TmpMem.B =%d   \n", TmpMem.B);

    while (v13 >= 0 && v13 < v12)
    {
        v15 = *(__int64_t**)(v14 + 8 * v13);

        if (IsUUserWidget((__uint64_t)v15)) {
            if (UUserWidget_GetIsVisible((__uint64_t)v15) == true) {
              //  if (UWidget_IsVisible((__int64_t)v15)) {
                //if (UUserWidget_IsInViewport((__uint64_t)v15) ) {

                    for (int j = 0; j < 1000; j++)
                    {

                        if (UiElement[j].IsUsed == 0) {
                            UiElement[j].IsUsed = 1;
                            UiElement[j].Pointer = (__uint64_t)v15;
                            UiElement[j].index = Count;

                            //  GetFNameStr(UIPanelName, (__int64_t)(UiElement[j].Pointer + 24)); //From UObject
                           //   DEBUG_PRINT("[+] IsPanelVisible::   j =  UIPanelName =%s   \n", UIPanelName);
                              // IsPanelVisible = UTSWidgetBase_IsPanelVisible(UIPanelAddr);
                          // DEBUG_PRINT("[+] UIPanelName =%s  Index =%d Addr =%lx \n" , UIPanelName,i,UiElement[i].Pointer); 


                            int NowUIPanelMax = 0;
                            if (ClosePanelStartAddr) {
                                __uint64_t GameUIPtr = GetGameUI();
                                if (GameUIPtr != 0) {
                                    char* UIPanelManager = (char*) (*(__uint64_t*)GameUIPtr);
                                    if (UIPanelManager) {
                                        char Type = *UIPanelManager;
                                        NowUIPanelMax = *((int*)ClosePanelStartAddr + 6 * Type + 4);
                                       // GENERAL_PRINT("[+]NowUIPanelMax  = %d \n", NowUIPanelMax);
                                        if (NowUIPanelMax > 0) {
                                            for (int Index = 0; Index < NowUIPanelMax; Index++)
                                            {
                                                char* v2 = UIPanelManager;
                                                __uint64_t IPanel = *(__uint64_t*)&v2[16 * *(unsigned __int8*)(*((__uint64_t*)ClosePanelStartAddr + 3 * Type + 1) + Index) + 8];
                                                if (IPanel) {

                                                    char IsOpened = *(char*)(IPanel + IsPanel2OpenOffset); //UIPanelManager::closePanelAll(__int64 result, char a2)
                                                    if (IsOpened) {
                                                        __uint64_t v17 = *(__uint64_t*)(IPanel + 32);
                                                        if (v17 != 0) {
                                                            __uint64_t ICustomWidget = *(__uint64_t*)(v17 + 24);

                                                            if (ICustomWidget != 0) {

                                                                __uint64_t TmpUUserWidget = WeakObjectPtr_Get(ICustomWidget + 8);
                                                                if (TmpUUserWidget != 0) {
                                                                    GetFNameStr(UIPanelName, (__uint64_t)(TmpUUserWidget + 24)); //From UObject
                                                                    // GENERAL_PRINT("[+] TmpUUserWidget =%s  Show = 1 v15 = %llx  TmpUUserWidget = %llx  \n", UIPanelName, v15, TmpUUserWidget);
                                                                }
                                                            }
                                                        }

                                                    }
                                                    else {
                                                        __uint64_t v17 = *(__uint64_t*)(IPanel + 32);
                                                        if (v17 != 0) {
                                                            __uint64_t ICustomWidget = *(__uint64_t*)(v17 + 24);

                                                            if (ICustomWidget != 0) {

                                                                __uint64_t TmpUUserWidget = WeakObjectPtr_Get(ICustomWidget + 8);
                                                                if (TmpUUserWidget == (__uint64_t)v15) {
                                                                    UiElement[j].IsUsed = 0;

                                                                    GetFNameStr(UIPanelName, (__uint64_t)(TmpUUserWidget + 24)); //From UObject
                                                                  //  GENERAL_PRINT("[+] TmpUUserWidget =%s  Show = 0 !!!  \n", UIPanelName);

                                                                }
                                                            }
                                                        }

                                                    }

                               
                                                }
                                            }
                                        }
                                    }
                                }
                            }


                            /*
                            for (int k = 0; k <= UIPanelMax; k++)
                            {
                                IPanel = GetUIPanel(UIMangerPtr, k);
                                if (IPanel != 0) {
                                    char IsOpened = *(char*)(IPanel + IsPanel2OpenOffset); //UIPanelManager::closePanelAll(__int64 result, char a2)
                                    if (IsOpened) {

                                        char UIPanelName[500];
                                        GetFNameStr(UIPanelName, (__uint64_t)(IPanel + 24)); //From UObject
                                        GENERAL_PRINT("[+]GameUI_GetPanelByName UIPanelName = %s \n", UIPanelName);

                                        __uint64_t v17 = *(__uint64_t*)(IPanel + 32);
                                        if (v17 != 0) {
                                            __uint64_t ICustomWidget = *(__uint64_t*)(v17 + 24);

                                            if (ICustomWidget != 0) {

                                                __uint64_t TmpUUserWidget = WeakObjectPtr_Get(ICustomWidget + 8);
                                                if (TmpUUserWidget != 0) {
                                                    GetFNameStr(UIPanelName, (__uint64_t)(TmpUUserWidget + 24)); //From UObject


                                                    // GENERAL_PRINT("[+] TmpUUserWidget =%s  Show = 1 v15 = %llx  TmpUUserWidget = %llx  \n", UIPanelName, v15, TmpUUserWidget);

                                                }
                                            }
                                        }

                                    }
                                    else {
                                        __uint64_t v17 = *(__uint64_t*)(IPanel + 32);
                                        if (v17 != 0) {
                                            __uint64_t ICustomWidget = *(__uint64_t*)(v17 + 24);

                                            if (ICustomWidget != 0) {

                                                __uint64_t TmpUUserWidget = WeakObjectPtr_Get(ICustomWidget + 8);
                                                if (TmpUUserWidget == (__uint64_t)v15) {
                                                    UiElement[j].IsUsed = 0;

                                                    GetFNameStr(UIPanelName, (__uint64_t)(TmpUUserWidget + 24)); //From UObject
                                                  //  GENERAL_PRINT("[+] TmpUUserWidget =%s  Show = 0 !!!  \n", UIPanelName);

                                                }
                                            }
                                        }

                                    }
                                }
                            }
                            */
                            if (UiElement[j].IsUsed == 1) {

                                char UIPanelName[500];
                                GetFNameStr(UIPanelName, (__uint64_t)(UiElement[j].Pointer + 24)); //From UObject
                                //GENERAL_PRINT("[+]GameUI_GetPanelByName UIPanelName = %s \n", UIPanelName);

                                Count = Count + 1;
                            }


                            break;
                        }
                    }
                    //  }
               // }
               
                    


                

            }


        }

        v12 = (int)(TmpMem.B);
        v13 = i + 1;
        v14 = TmpMem.A;
        for (i = v13; v13 < (int)(TmpMem.B); i = ++v13)
        {
            if (*(__int64_t*)(TmpMem.A + 8 * v13))
                break;
        }
    }

    if (TmpMem.A != 0) {
        FMemory_Free(TmpMem.A);
    }


    DEBUG_PRINT("[+] GetUIPanelList Count:%d ", Count);
    return Count;

}

__uint64_t GetUIManager() {
    


    return GetGameUI();
}

__uint64_t UTSWidgetPanel_GetWidgetTree(__uint64_t UIPanelAddr) { //UUserWidget::GetRootWidget
    __uint64_t TreePtr = 0;
    __uint64_t TreeRoot = 0;
    TreePtr = *(__uint64_t*)(UIPanelAddr + 448);
    //DEBUG_PRINT("[+] TreePtr =%lx   \n",TreePtr);
    if (TreePtr != 0) {
        TreeRoot = *(__uint64_t*)(TreePtr + 48);
        //  DEBUG_PRINT("[+] TreeRoot =%lx   \n",TreeRoot);
    }
    return TreeRoot;


}

__uint64_t UWidget_GetParent(__uint64_t a)
{
    __uint64_t v1; // x8
    __uint64_t result; // x0

    v1 = *((__uint64_t*)a + 7);
    if (v1)
        result = *(__uint64_t*)(v1 + 48);
    else
        result = 0LL;
    return result;
}

__uint64_t GameInstance_GetGameViewportClient(__uint64_t a)
{
    __uint64_t v1; // x8
    __uint64_t result; // x0

    v1 = *((__uint64_t*)a + 7);
    if (v1)
        result = *(__uint64_t*)(v1 + 544);
    else
        result = 0LL;
    return result;
}




__uint64_t FoundUIByTree(char* TreeStr, int IsIgnoreHide)
{

    multi_tok_t s = init();
    int i;
    const char* PreWidgetTreeStr = "[WidgetTree]";
    char WidgetTreeStr[100];
    memset(WidgetTreeStr, 0, 100);
    strcpy(WidgetTreeStr, (char*)PreWidgetTreeStr);

    const char* BlurryStr = "<#>";
    const char* delims = "-->";
    char* TmpStr;
    char* BlurrySearchPos;
    char* WidgetSearchPos;
    int IsBlurrySearch = 0;
    int IsBlurryWidgetTreeSearch = 0;
    __uint64_t ResultPtr = 0;

    int IsFoundPanel = 0;
    unsigned int  IsPanelVisible = 0;

    __uint64_t ThisElementPtr;
    int ChildCount;
    __uint64_t ChildElement;
    __uint64_t TmpElementName;
    __uint64_t UIMangerPtr = 0;
    __uint64_t UIPanelAddr = 0;
    char UIPanelName[300];
    char UObjectName[200];
    int TmpMaxPanel = 0;
    int IsSaveTreeNodeTxt = 0;
    char* TmpStr2 = NULL;
    int Count = 0;


     DEBUG_PRINT( "[+]Find  is %s  \n", TreeStr);  

    if (LHGameInstanceAddr != 0) {
        __uint64_t B2Client_instance = *LHGameInstanceAddr;
        if (B2Client__IsShowLoadingScreen(B2Client_instance) != 0) {
            return 0;
        }
    }


    IsLastWidgetVisible = 0;

    if (TreeStr) {
        ToLowerCase(TreeStr);
    }
    if (WidgetTreeStr) {
        ToLowerCase(WidgetTreeStr);
    }

    TmpStr = multi_tok(TreeStr, &s, delims);  //split
    //DEBUG_PRINT( "[+]Find Root UI Panel is %s  \n", TmpStr);  

    if (TmpStr != NULL) {

        WidgetSearchPos = strstr(TmpStr, WidgetTreeStr);
        //   GENERAL_PRINT( "[+] WidgetSearchPos= %p \n",WidgetSearchPos);  
        if (WidgetSearchPos)
        {
            *WidgetSearchPos = (char)0;
            IsBlurryWidgetTreeSearch = 1;
        }

        BlurrySearchPos = strstr(TmpStr, BlurryStr);
        if (BlurrySearchPos)
        {
            *BlurrySearchPos = (char)0;
            IsBlurrySearch = 1;
        }
        else {
            IsBlurrySearch = 0;
        }

        if (CheckPatchSystemBox == 1) {
            // TmpMaxPanel = MaxUIPanel + 1;
            CheckPatchSystemBox = 0;
        }
        else {
            // TmpMaxPanel = MaxUIPanel;
        }
    
        UIMangerPtr = GetUIManager();    // UIPanelAddr = GetUIPanel(UIMangerPtr,i);
      
        if (UIMangerPtr != 0) {
            if (IsBotEnded == 0) {
                WaitGetUIDone();
            }

            if (EverClosedHook == 0) {
                Count = GetUIPanelList(UIMangerPtr);
            }
            else {
                Count = UiPanelCount;
            }
            DEBUG_PRINT("[+]Count =%d  \n", Count);
          
            if (Count > 0) {
                for (i = 0; i <= Count; i++)
                {

                    if (EverClosedHook == 0) {
                        if (UiElement[i].IsUsed == 1) {
                            UIPanelAddr = UiElement[i].Pointer;
                        }
                    }
                    else {
                        if (UiPanel[i].IsUsed == 1) {
                            UIPanelAddr = UiPanel[i].Pointer;
                        }
                    }

                 
                   
                    if (EverClosedHook == 0 || UiPanel[i].Show > 0) {//
                    // UIPanelAddr = GetUIPanel(UIMangerPtr,i);   
                      
                        if (UIPanelAddr != 0) {
                        
                            
                            IsPanelVisible = 0;
                            if (IsUUserWidget(UIPanelAddr)) {
                                IsPanelVisible = UUserWidget_GetIsVisible(UIPanelAddr); //
                                if (IsPanelVisible == 1) {
                                    ChildElement = UTSWidgetPanel_GetWidgetTree(UIPanelAddr);
                                    if (UWidget_IsVisible(ChildElement) == 0) {
                                        IsPanelVisible = 0;
                                    }
                                }
                               
                            }

                            DEBUG_PRINT("[+]IsPanelVisible = %ld \n", IsPanelVisible);
                    
                            if (IsPanelVisible > 0 || IsIgnoreHide == 1) {

                                GetFNameStr(UIPanelName, (__uint64_t)(UIPanelAddr + 24)); //From UObject
                                if (UIPanelName) {
                                    ToLowerCase(UIPanelName);
                                }
                                if (TmpStr) {
                                    ToLowerCase(TmpStr);
                                }
                                

                                DEBUG_PRINT( "[+]TmpStr = %s UIPanelName = %s \n",TmpStr,UIPanelName);  
                         
                                IsFoundPanel = 0;
                                if (IsBlurrySearch == 1) //找到 UIPanel
                                {
                                    if (strstr((char*)UIPanelName, TmpStr)) {
                                        IsFoundPanel = 1;
                                    }
                                }
                                else {
                                    if (strcmp((char*)UIPanelName, TmpStr) == 0) {
                                        IsFoundPanel = 1;

                                    }
                                }

                                if (IsFoundPanel == 1) //找到 UIPanel
                                {
                                     DEBUG_PRINT( "[+]Found  UIPanel \n");  

                                    if (IsBlurryWidgetTreeSearch == 1) //找到 UIPanel
                                    {
                                        //   DEBUG_PRINT( "[+]IsBlurryWidgetTreeSearch = 1 \n");  
                                        ThisElementPtr = UTSWidgetPanel_GetWidgetTree(UIPanelAddr);

                                    }
                                    else {
                                        //    DEBUG_PRINT( "[+]IsBlurryWidgetTreeSearch = 0 \n");  
                                        ResultPtr = UIPanelAddr;
                                        return ResultPtr;
                                    }

                                     DEBUG_PRINT( "[+]TThisElementPtr = %lx \n",ThisElementPtr);  
                                     
                                      
                                    if (ThisElementPtr != 0)
                                    {
                                        IsSaveTreeNodeTxt = 0;

                                        ResultPtr = ThisElementPtr;
                                        for (i = 0; i < 1000; i++)
                                        {

                                            if (IsSaveTreeNodeTxt == 1) {
                                                TmpStr = TmpStr2;
                                            }
                                            else {
                                                TmpStr = multi_tok(NULL, &s, delims);
                                            }

                                            DEBUG_PRINT("[+]IsSaveTreeNodeTxt = %d \n", IsSaveTreeNodeTxt);

                                            if (TmpStr) {
                                                ToLowerCase(TmpStr);
                                            }

                                           
                                            DEBUG_PRINT("[+]WidgetSearchPos = %d \n", WidgetSearchPos);
                                            if (TmpStr != NULL) {
                                                DEBUG_PRINT("[+]TmpStr != NULL \n");
                                                WidgetSearchPos = strstr(TmpStr, WidgetTreeStr);

                                                DEBUG_PRINT("[+]TmpStr WidgetSearchPos != NULL \n");
                                                TmpStr2 = multi_tok(NULL, &s, delims);
                                                if (TmpStr2 != NULL) {
                                                    IsSaveTreeNodeTxt = 1;
                                                }
                                                else {
                                                    IsSaveTreeNodeTxt = 0;
                                                }

                                                DEBUG_PRINT("[+]GetChildElementByName  \n");
                                                if (IsSaveTreeNodeTxt == 0) {
                                                    ResultPtr = GetChildElementByName(ThisElementPtr, TmpStr, IsIgnoreHide, 1);
                                                }
                                                else {
                                                    ResultPtr = GetChildElementByName(ThisElementPtr, TmpStr, IsIgnoreHide, 0);
                                                }
                                                //DEBUG_PRINT( "[+]Found ChildRoot UI = %s \n", TmpStr );  

                                            //DEBUG_PRINT( "[+]GetChildElementByName = %x \n", ResultPtr);



                                                if (ResultPtr == 0) {
                                                    break;
                                                }
                                                else {
                                                    ThisElementPtr = ResultPtr;
                                                }
                                            }
                                            else { // Found Complete
                                                if (WidgetSearchPos) {
                                                    IsLastWidgetVisible = 1;
                                                }
                                                break;
                                            }
                                        }
                                        break;

                                    }
                                    
                                      
                                }
                                
                            }
                       
                        }
                         
                    }

                   
                }
            }
       
        }
        
    }

    DEBUG_PRINT( "[+] Leave FoundUIByTree \n");  
   
    return ResultPtr;

}



__uint64_t GetChildElementByName(__uint64_t ParentElement, char* ChildElementName, int IsIgnoreHide, int IsLastTreeNode)
{
    int ChildCount = 0;
    __uint64_t ChildElement = 0;
    int i;
    int IsBlurrySearch = 0;
    int IsWidgetTree = 0;
    int IsFoundChild = 0;
    int ElementIsShow = 0;
    __uint64_t result;
    struct FMemeryType TmpParentWW;
    __uint64_t* BeginAddress;
    __uint64_t TmpUObject;

    
    const char* BlurryStr = "<#>";
    const char* PreWidgetTreeStr = "[WidgetTree]";
    char WidgetTreeStr[100];
    memset(WidgetTreeStr, 0, 100);
    strcpy(WidgetTreeStr,(char*) PreWidgetTreeStr);
    char* BlurrySearchPos;

    char UObjectName[200];
    char UObjectTypeName[300];


    if (ChildElementName) {
        ToLowerCase(ChildElementName);
    }
    if (WidgetTreeStr) {
        ToLowerCase(WidgetTreeStr);
    }

    BlurrySearchPos = strstr(ChildElementName, WidgetTreeStr);
    if (BlurrySearchPos)
    {
        //DEBUG_PRINT( "[+] BlurrySearchPos=%x \n",(int)BlurrySearchPos);  
        *BlurrySearchPos = (char)0;
        IsWidgetTree = 1;
    }

    BlurrySearchPos = strstr(ChildElementName, BlurryStr);
    if (BlurrySearchPos)
    {
        //DEBUG_PRINT( "[+] BlurrySearchPos=%x \n",(int)BlurrySearchPos);  
        *BlurrySearchPos = (char)0;
        IsBlurrySearch = 1;
    }


  //  DEBUG_PRINT("[+]GetChildElementByName1 \n");

    InitFMem(&FixedAllChildWidgetMem);

    result = old_GetAllChildWidgets((__uint64_t)&ParentElement - 48, (__uint64_t)&FixedAllChildWidgetMem.A);//;


    BeginAddress = (__uint64_t*)FixedAllChildWidgetMem.A; //*(int**)b;
    //ChildCount = FixedAllChildWidgetMem.B;//*(int *)(b + 4);
    if (*(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8) == 0) {
        ChildCount = 0;
    }
    else {
        ChildCount = *(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8);
    }

    DEBUG_PRINT("[+]ChildCount = %d \n", ChildCount);


    if (ChildCount > 0 && ParentElement != 0)
    {
        for (i = 0; i < ChildCount; i++) {

            TmpUObject = BeginAddress[i];

            if (TmpUObject != 0) {
                if (UWidget_GetParent(TmpUObject) == ParentElement || IsWidgetTree == 1 || IsLastTreeNode == 1) {

                    GetFNameStr(UObjectName, (__uint64_t)(TmpUObject + 24));
                    if (UObjectName) {
                        ToLowerCase(UObjectName);
                    }

                    DEBUG_PRINT("[+] 22UObjectName=%s ChildElementName=%s \n", UObjectName, ChildElementName);



                    IsFoundChild = 0;

                    if (IsBlurrySearch == 0)
                    {
                        if (strcmp(UObjectName, ChildElementName) == 0)
                        {
                            IsFoundChild = 1;
                        }
                    }
                    else {
                        if (strstr(UObjectName, ChildElementName))
                        {
                            IsFoundChild = 1;
                        }
                    }

                    // DEBUG_PRINT( "[+] IsFoundChild=%d \n",IsFoundChild);  


                    if (IsFoundChild == 1)
                    {
                       // DEBUG_PRINT("[+] IsFoundChild1 =%s \n", UObjectName);
                        /*
                        if (UWidget_IsVisible(TmpUObject) > 0 && IsIgnoreHide == 0)
                        {
                            ChildElement = TmpUObject;
                        }
                        else if (IsIgnoreHide == 1) {
                            */
                        ChildElement = TmpUObject;
                        // }
                         //  DEBUG_PRINT( "[+] ChildElement=%lx \n",ChildElement);  
                        if (IsWidgetTree == 1) {
                            //  DEBUG_PRINT( "[+] ChildElement2=%lx \n",ChildElement);  
                            if (IsUUserWidget(TmpUObject)) {
                               // DEBUG_PRINT("[+] Found =%s \n", UObjectName);
                                ChildElement = UTSWidgetPanel_GetWidgetTree(TmpUObject);
                                if ( IsIgnoreHide == 0) {
                                    if (UUserWidget_GetIsVisible(TmpUObject) == 0) {
                                     //   DEBUG_PRINT("[+] UUserWidget_GetIsVisible1  =0\n");
                                   //     ChildElement = 0;
                                    }
                                    else {
                                     //   DEBUG_PRINT("[+] UUserWidget_GetIsVisible =1 \n");
                                        if (ChildElement != 0) {
                                            if (UWidget_IsVisible(ChildElement) == 0) {
                                            //    DEBUG_PRINT("[+] UWidget_IsVisible =0 \n");
                                                ChildElement = 0;
                                            }
                                        }
                                       // break;
                                    }
                                }
                                else {
                                   // DEBUG_PRINT("[+] IsIgnoreHide =1 \n");
                                   // break;
                                }
                            }else {
                              //  DEBUG_PRINT("[+] ChildElement22  =0\n");
                                ChildElement = 0;
                            }
                            //  DEBUG_PRINT( "[+] ChildElement3=%lx IsIgnoreHide=%d \n",ChildElement,IsIgnoreHide);  
                        }
                    }
                    else {
                        GetFNameStr(UObjectTypeName, (__int64_t)(*(__int64_t*)(TmpUObject + 16) + 24));

                        if (strcmp(UObjectTypeName, "CircularView") == 0) {
                            DEBUG_PRINT("[+] UObjectName = %s UObjectTypeName = %s \n", UObjectName, UObjectTypeName);


                            //UCircularView::GetDisplayedWidgetsNum
                            int ListCount = *(int*)(TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset + 8);//ULHLoopListView::GetNumItems
                            __uint64_t ItemPtr = 0;
                            __uint64_t WidgetPtr = 0;

                            DEBUG_PRINT("[+] ListCount=%d \n", ListCount);

                            for (int k = 0; k < ListCount; k++)
                            {
                                __uint64_t EntryWidgetsPtr = TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset;

                                WidgetPtr = *(__uint64_t*)(*(__uint64_t*)EntryWidgetsPtr + 8 * k);
                                if (WidgetPtr != 0) {


                                    GetFNameStr(UObjectName, (__uint64_t)(WidgetPtr + 24));  //From UObject    //參考UWidgetTree::FindWidget //Uobject真名地址 參考 UObjectBase::AddObject
                                    if (UObjectName) {
                                        ToLowerCase(UObjectName);
                                    }
                                    IsFoundChild = 0;

                                    if (IsBlurrySearch == 0)
                                    {
                                        if (strcmp(UObjectName, ChildElementName) == 0)
                                        {
                                            IsFoundChild = 1;
                                        }
                                    }
                                    else {
                                        if (strstr(UObjectName, ChildElementName))
                                        {
                                            IsFoundChild = 1;
                                        }
                                    }

                                    DEBUG_PRINT("[+] IsFoundChild=%d \n", IsFoundChild);



                                    if (IsFoundChild == 1)
                                    {
                                        //DEBUG_PRINT("[+] IsFoundChild2 =%s \n", UObjectName);
                                        if (IsWidgetTree == 1) {

                                            if (IsUUserWidget(WidgetPtr)) {
                                                ChildElement = UTSWidgetPanel_GetWidgetTree(WidgetPtr);
                                                if (IsIgnoreHide == 0) {
                                                    if (UUserWidget_GetIsVisible(TmpUObject) == 0) {
                                                        //ChildElement = 0;
                                                                //     DEBUG_PRINT("[+] ChildElement33  =0\n");
                                                       
                                                    }else {
                                                        if (ChildElement != 0) {
                                                            if (UWidget_IsVisible(ChildElement) == 0) {
                                                                ChildElement = 0;
                                                            //    DEBUG_PRINT("[+] ChildElement44  =0\n");
                                                            }
                                                        }
                                                        
                                                       // break;
                                                    }
                                                }
                                                else {
                                                   // break;
                                                }
                                            }
                                            else {
                                                ChildElement = 0;
                                              //  DEBUG_PRINT("[+] ChildElement55  =0\n");
                                            }
                                           // DEBUG_PRINT("[+] IsWidgetTree=%d \n", IsWidgetTree);
                                            //if (UUserWidget_GetIsVisible(WidgetPtr) == 0 && IsIgnoreHide == 0) {
                                            //    ChildElement = 0;
                                            //}
                                            //  DEBUG_PRINT( "[+] ChildElement3=%lx IsIgnoreHide=%d \n",ChildElement,IsIgnoreHide);  
                                        }else {

                                            ChildElement = WidgetPtr;

                                           // DEBUG_PRINT("[+] ChildElement66  =%lx\n", ChildElement);
                                            break;
                                        } /*
                                        struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(WidgetPtr);
                                        if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                                            ChildElement = 0;
                                        }
                                        */
                                    }




                                }
                            }

                        }
                    }




                }
            }
            
        }
    }

    FMemory_Free(FixedAllChildWidgetMem.A);
    //  DEBUG_PRINT( "[+] TmpParentWW before \n");  
   // *(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8) = 0;
    // DEBUG_PRINT( "[+] TmpParentWW after \n");  

   // DEBUG_PRINT("[+] ChildElement =%llx \n", ChildElement);

    return ChildElement;
}





std::string GetUIElementByTree(char* TreeStr, char* TmpResult, int SizeOfTmpResult, int IsIgnoreHide)
{
    //DEBUG_PRINT( "[+] Enter GetUIElementByTree \n");  
    unsigned int ElementIsShow;
    __uint64_t ElementIsEnable = 0;

    char FTextContent[2000];
    char UObjectTypeName[200];
    char TmpHex[4000];


    int HasText = 0;

    __uint64_t TmpElement = 0;

    struct CoorType PixelCoor;
    struct CoorType ViewPortCoor;
    char ObjAddress[50];
    std::string ObjStr = "";
    std::string TxtStr = "";
    Json::Value TmpChild;
    Json::FastWriter writer;


  
    TmpElement = FoundUIByTree(TreeStr, IsIgnoreHide);
  
    if (TmpElement != 0)
    {
       // DEBUG_PRINT("[+] GetUIElementByTree 2\n");
        if (IsLastWidgetVisible) {
            ElementIsShow = 1;
            ElementIsEnable = 1;
        }
        else {
            ElementIsShow = UWidget_IsVisible(TmpElement);
            ElementIsEnable = UWidget_GetIsEnabled(TmpElement);
        }

    
        GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(TmpElement + 16) + 24));


        memset(FTextContent, '\0', 2000);
        HasText = GetWidgetStr(TmpElement, UObjectTypeName, FTextContent, sizeof(FTextContent));
        TxtStr = FTextContent;

       DEBUG_PRINT("[+] GetUIElementByTree 3\n");

        struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(TmpElement);
        if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
            ElementIsShow = 0;
        }

        DEBUG_PRINT("[+] GetUIElementByTree 9\n");


        //    DEBUG_PRINT( "[+] Enter GetUIElementByTree 3\n");  



      
         memset(ObjAddress, 0, 50);
         snprintf(ObjAddress, 50, "%llx", TmpElement);
         ObjStr = ObjAddress;



        TmpChild["obj"] = ObjStr;
        TmpChild["IsRunn"] = ElementIsShow;
        TmpChild["IsEn"] = ElementIsEnable;
        TmpChild["w"] = UISizeCoor.width;
        TmpChild["h"] = UISizeCoor.height;
        TmpChild["x"] = UISizeCoor.X;
        TmpChild["y"] = UISizeCoor.Y;
        TmpChild["txt"] = TxtStr;
        TmpChild["Result"] = 1;

    }
    else {
        TmpChild["obj"] = "0";
        TmpChild["IsRunn"] = 0;
        TmpChild["IsEn"] = 0;
        TmpChild["w"] = 0;
        TmpChild["h"] = 0;
        TmpChild["x"] = 0;
        TmpChild["y"] = 0;
        TmpChild["txt"] = TxtStr;
        TmpChild["Result"] = 0;

    }
    std::string TmpResultStr = writer.write(TmpChild); 


    TmpChild.clear();

    strcpy(TmpResult, TmpResultStr.c_str());
    return TmpResultStr;
}



void GetPlayerLVExp() { ////PlayerHero::SetLvExp(PlayerHero *this, __int16 a2, __int64 a3)

    __uint64_t TmpLongInt = 0;
    __uint64_t TmpLongInt2 = 0;
    int LevelPage = 0;
    int MaxLevel = 0;
    int TmpVal = 0;
    int TmpLV = 0;
    struct FMemeryType TmpMem;
    InitFMem(&TmpMem);

    CurrentLv = 0;
    MaximumExp = 0;
    CurrentExp = 0;
    // result = GetMyActorLocation((int)&TmpPoint.XCoor);
    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
        if (PlayerHero != 0) {
            CurrentLv = *(unsigned short*)(PlayerHero + 1288); //PlayerHero::SetLvExp(PlayerHero *this, __int16 a2, __int64 a3)  PlayerHero::SetLevel
            MyMoney = *(__uint64_t*)(PlayerHero + 0 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2)
            MyDiamond = *(__uint64_t*)(PlayerHero + 1*8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency

            MyOtherMoney2 = *(__uint64_t*)(PlayerHero + 2 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney3 = *(__uint64_t*)(PlayerHero + 3 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney4 = *(__uint64_t*)(PlayerHero + 4 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney5 = *(__uint64_t*)(PlayerHero + 5 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney6 = *(__uint64_t*)(PlayerHero + 6 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney7 = *(__uint64_t*)(PlayerHero + 7 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney8 = *(__uint64_t*)(PlayerHero + 8 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney9 = *(__uint64_t*)(PlayerHero + 9 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney10 = *(__uint64_t*)(PlayerHero + 10 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney11 = *(__uint64_t*)(PlayerHero + 11 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney12 = *(__uint64_t*)(PlayerHero + 12 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney13 = *(__uint64_t*)(PlayerHero + 13 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney14 = *(__uint64_t*)(PlayerHero + 14 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney15 = *(__uint64_t*)(PlayerHero + 15 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney16 = *(__uint64_t*)(PlayerHero + 16 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney17 = *(__uint64_t*)(PlayerHero + 17 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney18 = *(__uint64_t*)(PlayerHero + 18 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney19 = *(__uint64_t*)(PlayerHero + 19 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney20 = *(__uint64_t*)(PlayerHero + 20 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney21 = *(__uint64_t*)(PlayerHero + 21 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney22 = *(__uint64_t*)(PlayerHero + 22 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
            MyOtherMoney23 = *(__uint64_t*)(PlayerHero + 23 * 8 + MoneyOffSet * 8); //PlayerHero::GetMoney(PlayerHero *this, int a2) //Account::GetCurrency
         
            IsFollowPartyLeader = (int)*(char*)(PlayerHero + IsFollowPartyLeaderOffset);


            __uint64_t v183 = (*(__int64(__fastcall**)(__uint64_t))(*(__uint64_t*)PlayerHero + 120LL))(PlayerHero);  //電腦版是  -8    (128 -8)   //PlayerHeroDisplay::UpdateNamePlate(__int64 result)  PlayerHero::GetName  電腦版的名字儲存方式跟ANDROID 版本不同
            char* v29;
            if (v183 != 0 && v183 != -1) {
                if (*(char*)v183 != 0) {
                    v29 = (char*)v183;
                    if ((__uint64_t)v29 != 0) {
                        if (strlen(v29) < 300) {
                            strcpy(CurrentPlayerName, v29);
                        }
                    }
                }
        
            }
            DEBUG_PRINT("[+]CurrentPlayerName = %s", CurrentPlayerName);
            //DEBUG_PRINT("[+]v29 = %llx", v29);

           // DumpMemory256(v29);
        
        }

        memset(CurrentServerName, '\0', 300);
        char* TmpServerNamePtr =  (char*)B2Client_GetAccountLoginHistroy_LastConnectedWorldName();
        if (strlen(TmpServerNamePtr) < 300) {
            strcpy(CurrentServerName, TmpServerNamePtr);
        }

        __uint64_t GetBagPtr = GetBag2(); //Bag2::HaveEmptySlot(Bag2 *this)
        if (GetBagPtr != 0) {
            NowItemCount = (int)*((signed __int16*)GetBagPtr + 4);
            MaxItemCount = (int)*((signed __int16*)GetBagPtr + 24);

        }

        //__uint64_t Account = GetAccountData();
       // if (Account != 0) {
          
           // MyDiamond = *(__uint64_t*)(Account + 3 * 8); //PlayerHero::GetCurrency(PlayerHero * this, int a2) //Account::GetCurrency
       // }

 
    }



}




int64_t PlayerHero__GetPlayerHeroDisplay(int64_t a) //ULHWidget_Scene_SleepMode::UpdateHPMP
{
    return *(int64_t*)(a + PlayerHeroDisplayOffset);
}

void GetIsMoving() { //FNkStallManager::_ProcessStallStayPrevState


    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
        
        if (PlayerHero != 0) {
            __uint64_t PlayerHeroDisplay = PlayerHero__GetPlayerHeroDisplay(PlayerHero);

            DEBUG_PRINT("[+] PlayerHeroDisplay:%llx--end--", CurrentPlayerName);
            if (PlayerHeroDisplay != 0) {
                __uint64_t ICharacter = *(__uint64_t*)(PlayerHeroDisplay + ICharacterOffset); //layerHeroDisplay::IsMoving(PlayerHeroDisplay *this)
                DEBUG_PRINT("[+] ICharacter:%llx--end--", ICharacter);
                if (ICharacter != 0 && ICharacter != -1) {
                    IsMoving = (int)ICharacter_HasMoveCommand(ICharacter);
                }
                DEBUG_PRINT("[+] IsMoving:%d--end--", IsMoving);

                NowTargetID = Game__GetAttackTargetId(GameInstance);
                DEBUG_PRINT("[+] NowTargetID:%lx--end--", NowTargetID);
                if (NowTargetID != 0) {
                    IsFighting = 1;
                }
                else {
                    IsFighting = 0;
                }
                isAutoBattle = Game_IsAutoPlay(GameInstance);


                __int64_t UIActionMenuPanel6 = 0;
                //UIActionMenuPanel6 = GameUI_GetPanel(UIActionMenuPanel6Type); //UIActionMenuPanel6::GetPanelType()
                UIActionMenuPanel6 = GameUI_GetPanelByName(UIActionMenuPanel6Name); //UIActionMenuPanel6::GetPanelType()
                if (UIActionMenuPanel6 != 0) {
                    IsShowActionButton = *(char*)(UIActionMenuPanel6 + ShowActionButtonOffset);
                 }

              
                AutoPlayState = 0;
                __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                if (AutoPlay2) {
                    AutoPlayState = *(char*)(AutoPlay2 + 10);
                }

                DEBUG_PRINT("[+] IsMoving:%x--end--", IsMoving);
            }
        }
    }


}

__uint64_t GetULHInventoryMgr()
{
    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t ULHInventoryMgrPtr = *(__uint64_t*)(*(__uint64_t*)(GameInstance + 424) + 88);
        return ULHInventoryMgrPtr;
    }
    return 0;
}

__uint64_t GetBag2()//Grocery2::CheckCoolTime(
{
    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t Bag2Ptr  = 0;
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t InterPtr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (InterPtr != 0) {
            Bag2Ptr = *(__uint64_t*)(InterPtr + Bag2Offset);
        }

        return Bag2Ptr;
    }
    return 0;
}

__uint64_t GetStash2()//Grocery2::CheckCoolTime(
{
    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t Bag2Ptr = 0;
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t InterPtr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (InterPtr != 0) {
            Bag2Ptr = *(__uint64_t*)(InterPtr + Stash2Offset);
        }

        return Bag2Ptr;
    }
    return 0;
}

__uint64_t GetItemDepotPtr(__uint64_t Bag2Ptr)//Bag2::IsContain(Bag2 *this, const Item2 *a2)
{
    __uint64_t ItemDepotPtr = Bag2Ptr + 24;
     return ItemDepotPtr;
    
    return 0;
}

__uint64_t GetStorageItemDepotPtr(__uint64_t Bag2Ptr)//Bag2::IsContain(Bag2 *this, const Item2 *a2)
{
    __uint64_t ItemDepotPtr = Bag2Ptr + 16;
    return ItemDepotPtr;

    return 0;
}


LRESULT CALLBACK WndProcHook(int nCode, WPARAM wParam, LPARAM lParam) {
  
   
    /*
    if (NeedGetUI == 1) {
        if (GameThreadTid != 0) {
            //unsigned int GameTid = *(unsigned int*)GameThreadTid;

            //if (GameTid == (unsigned int)GetCurrentThreadId() && GameTid != 0) {
                if (MainThreadTid != 0 && MainThreadTid == (unsigned int)GetCurrentThreadId()) {

                    if (StartCallFunction != 0) {
                        //GENERAL_PRINT("[+]GameTid = %d   MainThreadTid= %d  \n", GameTid, MainThreadTid);
                        GENERAL_PRINT("[+]fake_GetCursorPos StartCallFunction = %d  \n", StartCallFunction);
                    }

                    mmemcmp(0, 0, 0);
                }
            //}
        }
    }
  */
 
    return CallNextHookEx(hookHandle, nCode,
        wParam, lParam);
}


// Helper method for convenience
HWND GetProcessMainWindow()
{
    HWND hWnd = GetWindow(GetDesktopWindow(), GW_CHILD);
    hWnd = GetWindow(hWnd, GW_HWNDFIRST);

    while (hWnd)
    {
        DWORD dwPid = 0;
        GetWindowThreadProcessId(hWnd, &dwPid);
        if (dwPid == GetCurrentProcessId() && GetParent(hWnd) == NULL &&
            (GetWindowLong(hWnd, GWL_STYLE) & WS_VISIBLE))
            return hWnd;
        hWnd = GetWindow(hWnd, GW_HWNDNEXT);
    }

    return NULL;
}


int StartSOInfoThread(int N) //Authorize pass 之後
{
    DEBUG_PRINT("[+] StartSOInfoThread  \n");
    Sleep(3000);


  


    RECT rect;
    for (int i = 0; i < 60; i++)
    {
        g_hMainWnd = GetProcessMainWindow();
        DEBUG_PRINT("[+] g_hMainWndAppear = %d  \n", g_hMainWnd); //)
        if (g_hMainWnd != 0) {
            GetWindowRect(g_hMainWnd, &rect);
            int Width = rect.right - rect.left;
            int Height = rect.bottom - rect.top;
          //  DEBUG_PRINT("[+] Window Size = %d  %d   %d   %d \n", rect.left, rect.right, rect.top, rect.bottom); //)
            DEBUG_PRINT("[+] Window Size = %d  x %d \n", Width, Height); //)
            if (Width > 0 && Height > 0 && (rect.left > 0 || rect.right > 0) && (rect.bottom > 0 || rect.top > 0)  > 0) {
                break;
            }
        }

        usleep(1000 * 1000);
    }
   // Sleep(500);

    SoBaseAddress = GetBaseAddress();
    DEBUG_PRINT("[+] SoBaseAddress = %lx \n", SoBaseAddress);
    SetGameFunAddr();

    SetAndCheckGameVerion();


    IsGameHooked = 1;

    if (IsGameVersionPass == 0) {
        IsGameHooked = 0;
    }

    IsPassGameHooked = 1;
    return 1;
}


void usleep(int microsec)
{
    Sleep((int)(microsec / 1000));
}


struct EnumData {
    DWORD dwProcessId;
    HWND hWnd;
};

BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam) {
    // Retrieve storage location for communication data
    EnumData& ed = *(EnumData*)lParam;
    DWORD dwProcessId = 0x0;
    // Query process ID for hWnd
    GetWindowThreadProcessId(hWnd, &dwProcessId);
    // Apply filter - if you want to implement additional restrictions,
    // this is the place to do so.
    if (ed.dwProcessId == dwProcessId) {
        // Found a window matching the process ID
        ed.hWnd = hWnd;
        // Report success
        SetLastError(ERROR_SUCCESS);
        // Stop enumeration
        return FALSE;
    }
    // Continue enumeration
    return TRUE;
}

HWND FindWindowFromProcessId(DWORD dwProcessId) {
    EnumData ed = { dwProcessId };
    if (!EnumWindows(EnumProc, (LPARAM)&ed) &&
        (GetLastError() == ERROR_SUCCESS)) {
        return ed.hWnd;
    }
    return NULL;
}


int SetAndCheckGameVerion() {
    void* handle = 0;
    SetFuncAddr(handle, _ZN7FMemory4FreeEPv, &FMemory_Free_Real);

    int TmpPass = 1;
    //檢查版本
    for (int i = 0; i < 7; i++)
    {
        if (*(char*)((char*)FMemory_Free_Real + i) != FMemoryFreeArray[i]) {
            IsGameHooked = 0;
            TmpPass = 0;
        }
    }
    IsGameVersionPass = TmpPass;
    return IsGameVersionPass;
}


void SetGameFunAddr()
{

   void* handle = 0;



   SetFuncAddr(handle, __GetFB2ScalabilityController, &GetFB2ScalabilityController);


   SetFuncAddr(handle, _ZN8B2Client8instanceE, &LHGameInstanceAddr);
   SetFuncAddr(handle, _EnginePtr, &EnginePtr);
  // SetFuncAddr(handle, _UWolrldPtr, &UWolrldPtr);

  // SetFuncAddr(handle, _GameObject2_ClientConfig, &GameObject2_ClientConfigPtr);
   

   SetFuncAddr(handle, _ClosePanelStartAddr, &ClosePanelStartAddr);
   SetFuncAddr(handle, _ZNK7UEngine25GetWorldFromContextObjectEPK7UObject18EGetWorldErrorMode, &UEngine_GetWorldFromContextObject);
   SetFuncAddr(handle, _GameThreadTid, &GameThreadTid);


    SetFuncAddr(handle, _ZNK5FName8ToStringEv, &GetFNameString);
    //SetFuncAddr(handle, _ZN5FNameC2EPKDs9EFindName ,&FindFName);  




    SetFuncAddr(handle, _ZNK5FText8ToStringEv, &FTextToString);
    SetFuncAddr(handle, _ZN10UTextBlock14GetDisplayTextEv, &TextBlock_GetDisplayText);



    SetFuncAddr(handle, _ZNK18UObjectBaseUtility11GetFullNameEPK7UObjectR7FString20EObjectFullNameFlags, &GetUObjectFullPathName);


  //  SetFuncAddr(handle, _ZNK7UWidget9GetParentEv, &UWidget_GetParent);
    SetFuncAddr(handle, _ZNK7UWidget9IsVisibleEv, &UWidget_GetVisibility);


    SetFuncAddr(handle, _ZNK7UWidget12GetIsEnabledEv, &UWidget_GetIsEnabled);  //_ZNK7UWidget12GetIsEnabledEv

    SetFuncAddr(handle, _ZNK9UCheckBox15GetCheckedStateEv, &UCheckBox_GetCheckedState);

    SetFuncAddr(handle, _ZN11UWidgetTree15GetChildWidgetsEP7UWidgetR6TArrayIS1_22TSizedDefaultAllocatorILi32EEE, &old_GetAllChildWidgets);
    SetFuncAddr(handle, _Z17GetObjectsOfClassPK6UClassR6TArrayIP7UObject22TSizedDefaultAllocatorILi32EEEb12EObjectFlags20EInternalObjectFlags, &GetObjectsOfClass);  //From ALHPlayerController_InGame::ClickWorldScreenInternal



   // SetFuncAddr(handle, _ZNK15UWidgetSwitcher20GetActiveWidgetIndexEv, &UWidgetSwitcher_GetActiveWidgetIndex); //自己實現


    SetFuncAddr(handle, _ZNK7UWidget17GetCachedGeometryEv, &UWidget_GetCachedGeometry);

    SetFuncAddr(handle, _ZN22USlateBlueprintLibrary15LocalToViewportEP7UObjectRK9FGeometry9FVector2DRS5_S6_, &USlateBlueprintLibrary_LocalToViewport);
    SetFuncAddr(handle, _ZNK19UGameViewportClient15GetViewportSizeER9FVector2D, &old_GameViewportClient_GetViewportSize);
   // SetFuncAddr(handle, _ZNK13UGameInstance21GetGameViewportClientEv, &GameInstance_GetGameViewportClient);

    SetFuncAddr(handle, _ZNK14FWeakObjectPtr3GetEv, &WeakObjectPtr_Get);

    SetFuncAddr(handle, _ZN16UISleepModePanel12OnClosePanelEv, &UISleepModePanel_OnClose);
    SetFuncAddr(handle, _ZN16UISleepModePanel12OnClosePanelEv, &UISleepModePanel_OnClosePtr);


    SetFuncAddr(handle, _ZN16UISleepModePanel4OpenEv, &UISleepModePanel_Open);
    SetFuncAddr(handle, _ZN16UISleepModePanel13SetSleepStateENS_11ESleepStateEb, &UISleepModePanel_SetSleepState);
    SetFuncAddr(handle, _ZN14UIPanelManager9OpenPanelE11UIPanelTypeb, &UIPanelManager_OpenPanel);
    


    SetFuncAddr(handle, _ZNK4Bag222RequestDisassembleItemExi, &Bag2_RequestDisassembleItem); //APlayerController::GetViewportSize(

    






    SetFuncAddr(handle, _ZN7UButton18SlateHandleClickedEv, &UButton_SlateHandleClicked);
    SetFuncAddr(handle, _ZN7UButton18SlateHandlePressedEv, &UButton_SlateHandlePressed);
    SetFuncAddr(handle, _ZN7UButton18SlateHandleReleaseEv, &UButton_SlateHandleReleased);


    SetFuncAddr(handle, _ZN7UButton18SlateHandleClickedEv, &RealSlateHandleClickedPtr);
    SetFuncAddr(handle, _ZN7UButton18SlateHandlePressedEv, &RealSlateHandlePressedPtr);
    SetFuncAddr(handle, _ZN7UButton18SlateHandleReleaseEv, &RealSlateHandleReleasePtr);


    DEBUG_PRINT("[+] RealSlateHandleReleasePtr = %llx  \n", RealSlateHandleReleasePtr); //)



    SetFuncAddr(handle, _ZN7UEngine9SetMaxFPSEf, &UEngine_SetMaxFPS);  //

    SetFuncAddr(handle, _ZN11UUserWidget21GetPrivateStaticClassEv, &UserWidget_GetPrivateStaticClass);  //
    SetFuncAddr(handle, _ZN6AB2HUD21GetPrivateStaticClassEv, &AB2HUD_GetPrivateStaticClass);  //    
    SetFuncAddr(handle, _ZN19AB2PlayerController21GetPrivateStaticClassEv, &AB2PlayerController_GetPrivateStaticClass);  //

    

    SetFuncAddr(handle, _ZN5Item212GetItemGradeEy, &Item2_GetItemGrade);  //
    SetFuncAddr(handle, _ZN5Item211GetItemNameEy, &Item2_GetItemName);  //

    SetFuncAddr(handle, _ZN3Npc13GetRecordNameEv, &Npc_GetRecordName);  //
    SetFuncAddr(handle, _ZN4Game17SetAttackTargetIdEybb, &Game_SetAttackTargetId);  //




    SetFuncAddr(handle, _ZNK4Bag218RequestConsumeItemExiy, &Bag2_RequestConsumeItem);  //
    SetFuncAddr(handle, _ZNK4Bag218RequestDestroyItemExsi, &Bag2_RequestDestroyItem);  //
    

    SetFuncAddr(handle, _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch, &Game_AutoPlayMapMove);  //
    SetFuncAddr(handle, _ZN4Game15AutoPlayMapMoveEy7FVectorfPKch, &Game_AutoPlayMapMovePtr);  //
    

    SetFuncAddr(handle, _ZNK10ICharacter14HasMoveCommandEv, &ICharacter_HasMoveCommand);  //
    

    SetFuncAddr(handle, _ZN10UScrollBox15SetScrollOffsetEf, &UScrollBox_SetScrollOffset);  //
    SetFuncAddr(handle, _ZN14STableViewBase15SetScrollOffsetEf, &STableViewBase_SetScrollOffset);  //
    SetFuncAddr(handle, _ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D, &Map3DPanel_HandleSwipeDeltaEvent);  //


   // SetFuncAddr(handle, _ZN8Tutorial8NextStepEv, &Tutorial_NextStep);  
    SetFuncAddr(handle, _ZN4Game9FindAgentEy, &Game_FindAgent);  //
    
    SetFuncAddr(handle, _ZNK8EquipSet10IsEquippedEx, &EquipSet_IsEquipped);  //

    SetFuncAddr(handle, _ZNK5Quest26GetQuestMissionProgressMaxEv, &Quest_GetQuestMissionProgressMax);  //

    SetFuncAddr(handle, _ZN10UITradeBag17OnClickSlotButtonEi, &UITradeBag_OnClickSlotButton);  //
    SetFuncAddr(handle, _ZN17UIInventoryPanel221OnClickItemSlotButtonERK5FNamei, &UIInventoryPanel_OnClickItemSlotButton);  //

    SetFuncAddr(handle, _ZN19CircularViewWrapper21ScrollToIndexIntoViewEi27EICircularScrollDestinationb, &CircularViewWrapper_ScrollToIndexIntoView);  //
    SetFuncAddr(handle, _ZN18UIItemCircularView16GetGridDataIndexEi, &UIItemCircularView_GetGridDataIndex);  //


    SetFuncAddr(handle, _ZNK6Stash222RequestMoveToInventoryEysi, &Stash2_RequestMoveToInventory);  //
    SetFuncAddr(handle, _ZNK4Bag218RequestMoveToStashEysi, &Bag2_RequestMoveToStash);  //
    SetFuncAddr(handle, _ZN19UICitizenShopPanel220OnClickBagSlotButtonERK5FNamei, &UICitizenShopPanel_OnClickBagSlotButtonERK5FName);  //
    
  //  SetFuncAddr(handle, _ZN12UIStashPanel11refreshItemEv, &UIStashPanel_refreshItem);  //


    SetFuncAddr(handle, _ZN8Tutorial3EndEbb, &Tutorial_End);  //

    SetFuncAddr(handle, _ZN24FB2ScalabilityController9SetMaxFPSEf, &FB2ScalabilityController_SetMaxFPS);  //
    
    SetFuncAddr(handle, _ZN9AutoPlay26CombatERK7FVector12AutoPlayMode, &AutoPlay_Combat);  //

    SetFuncAddr(handle, _ZN4Game10PickTargetEyb, &Game_PickTarget);  //
    SetFuncAddr(handle, _ZN4Game10PickTargetEyb, &Game_PickTargetPtr);  //

    

   // g_dwThisModuleSize = GetModuleSize(g_hThisModule);
   // InitGameData(g_hMainWnd);

    //Check Version Correct

    
    SetFuncAddr(handle, _ZN4Game34checkAvailableAutoMoveWhatHyperRunEv, &Game_checkAvailableAutoMoveWhatHyperRun);  //
    SetFuncAddr(handle, _ZN17PlayerHeroDisplay14StopMoveOnPathEv, &PlayerHeroDisplay_StopMoveOnPath);  //
    SetFuncAddr(handle, _ZN17PlayerHeroDisplay15StopDestGimmickEv, &PlayerHeroDisplay_StopDestGimmick);  //
    SetFuncAddr(handle, _ZN12AgentDisplay16ClearActionTimerEv, &AgentDisplay_ClearActionTimer);  //
    SetFuncAddr(handle, _ZN9AutoPlay26FinishEv, &AutoPlay2_Finish);  //
    SetFuncAddr(handle, _ZN9AutoPlay26FinishEv, &AutoPlay2_FinishPtr);  //
    

    SetFuncAddr(handle, _ZN9AutoPlay214setCommonParamEPKch, &AutoPlay2_setCommonParam);  //
    SetFuncAddr(handle, _ZN9AutoPlay212setMoveParamEy7FVectorf, &AutoPlay2_setMoveParam);  //
    SetFuncAddr(handle, _ZN9AutoPlay219setMoveParamDungeonEy7FVectorf, &AutoPlay2_setMoveParamDungeon);  //
    SetFuncAddr(handle, _ZN9AutoPlay215changePlayStateE14AutoPlayState2b, &AutoPlay2_changePlayState);  //
    SetFuncAddr(handle, _ZN9AutoPlay215changePlayStateE14AutoPlayState2b, &AutoPlay2_changePlayStatePtr);  //

    
    SetFuncAddr(handle, _ZN12AutoMovePath8FindPathERK7FVectorb, &AutoMovePath_FindPath);  //
    SetFuncAddr(handle, __UpdateAutoBattleUIAndMessage, &UpdateAutoBattleUIAndMessage);  //


    SetFuncAddr(handle, _ZN8Grocery221ProcessUseGroceryItemEiixyybb, &Grocery_ProcessUseGroceryItem);  //


   // SetFuncAddr(handle, _ZNK10PlayerHero18GetWeaponGroupTypeEv, &PlayerHero_GetWeaponGroupType);  //
    SetFuncAddr(handle, _ZN10PlayerHero10SetUseAutoEhab, &PlayerHero_SetUseAuto);  //


    SetFuncAddr(handle, _ZNK8EquipSet12GetEquipSlotEas, &EquipSet_GetEquipSlot);  //
    SetFuncAddr(handle, _ZNK4Bag216RequestEquipItemEhsxhb, &Bag2_RequestEquipItem);  //
    
    SetFuncAddr(handle, _ZN10UIChatMain17sendMessageEscapeEv, &ChatMain_sendMessageEscape);  //

    
    SetFuncAddr(handle, _ZNK5Party28RequestInvitePartyByHeroNameEPKc, &Party_RequestInvitePartyByHeroName);  //


    SetFuncAddr(handle, _ZN18HyperRunController21SetImpossibleAutoMoveEb, &HyperRunController_SetImpossibleAutoMoveEb);  //
    SetFuncAddr(handle, _ZN18HyperRunController21SetImpossibleAutoMoveEb, &HyperRunController_SetImpossibleAutoMoveEbPtr);  //
    
    SetFuncAddr(handle, _ZN18HyperRunController12PlayHyperRunEh, &HyperRunController_PlayHyperRunEh);  //
    SetFuncAddr(handle, _ZN18HyperRunController12PlayHyperRunEh, &HyperRunController_PlayHyperRunEhPtr);  //


    SetFuncAddr(handle, _ZN13SkillContext623CheckCanHitTargetByAutoEy, &SkillContext6_CheckCanHitTargetByAutoEy);
    SetFuncAddr(handle, _ZN4Game20AutoPlayAttackTargetEybb, &Game_AutoPlayAttackTarget);
    SetFuncAddr(handle, _ZN4Game16SetPickedAgentIdEyb, &Game_SetPickedAgentId);

    SetFuncAddr(handle, _ZN9AutoPlay212SingleCombatEv, &AutoPlay2_SingleCombat);
    SetFuncAddr(handle, _ZN9AutoPlay212SingleCombatEv, &AutoPlay2_SingleCombatPtr);
    
    SetFuncAddr(handle, _ZN9AutoPlay211SingleSkillEyh, &AutoPlay2_SingleSkill);

    SetFuncAddr(handle, _ZN4Game12UnlockTargetEv, &Game_UnlockTarget);

    SetFuncAddr(handle, _ZN12UI3DWorldMap29getUI3DMapObjectMapIconObjectEi, &UI3DWorldMap_getUI3DMapObjectMapIconObject);
    SetFuncAddr(handle, _ZN12UI3DMapPanel21OnWorldMapIconTouchedEi, &UI3DMapPanel_OnWorldMapIconTouched);

    SetFuncAddr(handle, _ZN12DataManager322GetEquipCollectionDictEv, &DataManager_GetEquipCollectionDictEv);
    SetFuncAddr(handle, _ZN18B2ClientTextFormat7GetTextEPKc, &B2ClientTextFormat_GetText);

    SetFuncAddr(handle, _ZN12DataManager319GetEffectManualDictEv, &DataManager3_GetEffectManualDictEv);
    SetFuncAddr(handle, _EffectManualDict_GetEffectByIdEv, &EffectManualDict_GetEffectByIdEv);

    SetFuncAddr(handle, _ZN8B2Client45GetAccountLoginHistroy_LastConnectedWorldNameEv, &B2Client_GetAccountLoginHistroy_LastConnectedWorldName);
    SetFuncAddr(handle, _ZN5Agent18IsAttackPlayerHeroEv, &Agent_IsAttackPlayerHero);


    SetFuncAddr(handle, OFF_ProcessDeferredMessage, &fake_SendMessagew);
    //HookGameFunByAddr(handle, _ZN18ALHGameMode_InGame12DisplayCountEv, (void*)&HookFloat, &old_UNkUiManager_Tick);  //

    SetFuncAddr(handle, _ZN6TArrayIDs22TSizedDefaultAllocatorILi32EEE13ResizeForCopyEii, &DefaultAllocator_ResizeForCopy);
    SetFuncAddr(handle, _ZN18FScreenshotRequest17RequestScreenshotERK7FStringbb, &FScreenshotRequest_RequestScreenshot);
    
    SetFuncAddr(handle, _ZN8B2Client39GetContentsOptionSkipEnchantResultPopupEv, &B2Client_GetContentsOptionSkipEnchantResultPopup);


    //SetFuncAddr(handle, _ZN7UEngine29GetFirstLocalPlayerControllerEPK6UWorld, &UEngine_GetFirstLocalPlayerController);
   // SetFuncAddr(handle, _ZN11AController18SetControlRotationERK8FRotator, &AController_SetControlRotation);

    

  //  HookGameFunByAddr(handle, _ZN9ULHButton20LHSlateHandleClickedEv, (void*)&Testing_Fun2, &old_Testing_Fun2);  //
    DEBUG_PRINT("[+] HookGameFunByAddr  \n"); //)
}


bool UUserWidget_GetIsVisible(__uint64_t a1)
{
    __uint64_t v1; // x8
    unsigned int* v2; // x8
    unsigned int v3; // off
    if (!*((__uint64_t*)a1 + 86)) {
        return 0LL;
    }
    v1 = *((__uint64_t*)a1 + 87);
    if (!v1) {
        return 0LL;
    }
      
    v2 = (unsigned int*)(v1 + 8);
    if ((__uint64_t)v2 > 0) {
        return true;
    }
    else {
        return false;
    }
}



__uint64_t Testing_Fun2(__uint64_t a, __uint64_t b)
{
    __uint64_t result = 0;

    result = old_Testing_Fun2(a, b);//;

    DEBUG_PRINT("[+] Testing_Fun2: result =%ld  a =%lx b =%lx  \n", result, a, b); //)

    return result;
}


__uint64_t HookFloat(__uint64_t a) //1秒1次
{

    //  ItemUseMgrUpdateing = 1;
      //DEBUG_PRINT("[+] UNkUiManager_Tick::  \n") ;     
    __uint64_t result;

    MainThreadTid = GetCurrentThreadId();

    result = old_UNkUiManager_Tick(a);//;

    int i = 0;
    int IsPanelVisible = 0;
    int UIMangerPtr = 0;
    int UIPanelAddr = 0;
    // char UIPanelName[300];


    return result;
}


void WaitGetUIDone() {
    int i = 0;
    if (GettingUI == 1) {
        for (i = 0; i < 1000; i++) {
            usleep(10 * 1000);
            if (GettingUI == 0) {
                break;
            }
        }
    }
}




void WaitMainThreadDone2() {
    int i = 0;

    time_t timestamp_sec; /* timestamp in second */
    __int64_t CurrentTime = time(&timestamp_sec);

    if (StartCallFunction != 0) {
        for (i = 0; i < 5000; i++) {
            usleep(1 * 1000);
            time_t timestamp_sec2;
            __int64_t CurrentTime2 = time(&timestamp_sec2);
            if (CurrentTime2 - CurrentTime > 5) {
                break;
            }
            if (StartCallFunction == 0) {
                break;
            }
        }
        if (StartCallFunction != 0) {
            GENERAL_PRINT("[+] CallFunction Fail:: %d", StartCallFunction);
        }

    }
}

void WaitMainThreadDone() {
    int i = 0;
    int Success = 0;

    time_t timestamp_sec; /* timestamp in second */
    __int64_t CurrentTime = time(&timestamp_sec);

    if (StartCallFunction != 0) {

        for (i = 0; i < 5000; i++) {
            usleep(1 * 1000);
            time_t timestamp_sec2;
            __int64_t CurrentTime2 = time(&timestamp_sec2);
            if (CurrentTime2 - CurrentTime > 5) {
                break;
            }
            if (StartCallFunction == 0) {
                Success = 1;
                break;
            }
        }
        /*
           */

        if (Success == 0)
        {
            if (IsCallingFun == 0 && StartCallFunction != 1 && StartCallFunction != 2) {
                IsCallingFun = 1;
                FakeCallGameFunction();
            }
            IsCallingFun = 0;
            DEBUG_PRINT("[+] Extra Call:: ");
        }

        if (IsCallingFun != 0) {
            IsCallingFun = 0;
        }

        if (StartCallFunction != 0) {
            StartCallFunction = 0;
        }

    }

}



int IsMapChanging() {
    return 0;
}


void ReadAllUI() {
    int64_t TmpElement = 0;
    int64_t ElementIsShow = 0;
   // DEBUG_PRINT("[+] ReadAllUI::");
    if (UICheckListCount > 0) {
        for (int i = 1; i <= UICheckListCount; i++)
        {
            if (UICheckList[i].IsUsed == 1)
            {
                memset(UICheckStr, '\0', 500);
                strcpy(UICheckStr, UICheckList[i].Text);
                UICheckList[i].IsShow = 0;

                DEBUG_PRINT("[+] ReadAllUI1:: %s", UICheckList[i].Text);
                TmpElement = FoundUIByTree(UICheckStr, 0);
                if (TmpElement != 0)
                {
                    if (IsLastWidgetVisible) {
                        ElementIsShow = 1;
                    }
                    else {
                        ElementIsShow = UWidget_IsVisible(TmpElement);
                    }

                    DEBUG_PRINT("[+] ReadAllUI2:: ");

                    struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(TmpElement);
                    if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                        ElementIsShow = 0;
                    }

                    DEBUG_PRINT("[+] ReadAllUI3:: ");

                    UICheckList[i].IsShow = (int)ElementIsShow;
                }


            }
        }
    }
}


struct CoorType GetCurrentCoor() { //UI3DWorldMap::refreshMyPosIcon(__int64 result)
    struct CoorType TmpPoint;
    // result = GetMyActorLocation((int)&TmpPoint.XCoor);
    __int64_t GameInstance = GetGameInstanceE();

    if (GameInstance != 0) {
        __int64_t Agent = *(__int64_t*)(GameInstance + AgentOffset);
        if (Agent != 0) {
            TmpPoint.XCoor = (float)*(signed int*)(Agent + CoorOffset);
            TmpPoint.YCoor = (float)*(signed int*)(Agent + CoorOffset + 4);
            TmpPoint.ZCoor = (float)*(signed int*)(Agent + CoorOffset + 8);
        }

    }



    return TmpPoint;
}


void GetPlayerHP() //ULHWidget_Scene_SleepMode::UpdateHPMP
{
    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __int64_t PlayerHero = *(__int64_t*)(GameInstance + AgentOffset); // Game::GetPlayerHeroDisplay
        if (PlayerHero != 0) {
           // GENERAL_PRINT("[+]PlayerHero = %llx", PlayerHero);
            __int64_t PlayerHeroDisplay = *(__int64_t*)(PlayerHero + PlayerHeroDisplayOffset);
            if (PlayerHeroDisplay != 0) {
               // __int64_t MyAgent = *(__int64_t*)(PlayerHeroDisplay + 312); // AgentDisplay::getMyAgent(__int64 a1, _QWORD *a2)
                __int64_t MyAgent = PlayerHero;
             //   GENERAL_PRINT("[+]MyAgent = %llx", MyAgent);
                if (MyAgent != 0) {
                    try {
                        int v9 = *(int*)(MyAgent + NowHpOffset);
                       // GENERAL_PRINT("[+]v9 = %d", v9);

                        MyHp = (int)(float)(v9 & ~(v9 >> 31)); //AgentDisplay::UpdateBar   ICharacterNameOffSetr(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
                        MyMaxHp = (int)(float)*(signed int*)(MyAgent + MaxHpOffset);
                       // GENERAL_PRINT("[+]MyMaxHp = %d", MyMaxHp);
                        MyMp = (int)(float)*(signed int*)(MyAgent + NowMpOffset); //PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
                     
                      //  GENERAL_PRINT("[+]MyMp = %d", MyMp);
                        if (*(__int64_t*)(MyAgent + MaxMpOffset) != 0) {
                            MyMaxMp = (int)(float)*(signed int*)(*(__int64_t*)(MyAgent + MaxMpOffset) + MaxMpOffset2);
                        }
                       // GENERAL_PRINT("[+]MyMaxMp = %d", MyMaxMp);
                    }
                    catch (const char* e1) {
                        GENERAL_PRINT("[+]GetPlayerHP Error Catch : %s", e1);
                    }
                }
            
            }

         

          //  TmpPoint.XCoor = (float)*(signed int*)(Agent + CoorOffset);
          //  TmpPoint.YCoor = (float)*(signed int*)(Agent + CoorOffset + 4);
          //  TmpPoint.ZCoor = (float)*(signed int*)(Agent + CoorOffset + 8);
        }
    }
}


void GetPKTargetInfo() //ULHWidget_Scene_SleepMode::UpdateHPMP
{
    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __int64_t PlayerHero = *(__int64_t*)(GameInstance + AgentOffset); // Game::GetPlayerHeroDisplay
        if (PlayerHero != 0) {

            memset(PKTargetName, 0, 300);
            PKAttackerHp = 0;
            PKAttackerMaxHp = 0;
            PKAttackerMp = 0;
            PKAttackerMaxMp = 0;
            IsPK = 0;

  
            AttackerPlayerID = *(__uint64_t*)(PlayerHero + PKTargetOffset);
            if (AttackerPlayerID != 0) {
                IsPK = 1;
            }

            if (AttackerPlayerID != 0) {
                struct FMemeryType TmpMem;   //FGeometry::ToString
                InitFMem(&TmpMem);
                __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, AttackerPlayerID);
                // GENERAL_PRINT("[+]TmpAgent = %llx", TmpAgent);
                 if (TmpMem.A != 0) {

                     try{
                         int v9 = *(int*)(TmpMem.A + NowHpOffset);
                         PKAttackerHp = (int)(float)(v9 & ~(v9 >> 31)); //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
                         PKAttackerMaxHp = (int)(float)*(signed int*)(TmpMem.A + MaxHpOffset);
                         PKAttackerMp = (int)(float)*(signed int*)(TmpMem.A + NowMpOffset); //PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
                         PKAttackerMaxMp = (int)(float)*(signed int*)(TmpMem.A + AgentMaxMpOffset);


                         __uint64_t v183 = (*(__int64(__fastcall**)(__uint64_t))(*(__uint64_t*)TmpMem.A + 120LL))(TmpMem.A);  //電腦版是  -8    (128 -8)  //PlayerHeroDisplay::UpdateNamePlate(__int64 result) 
                         char* v29;
                         if (v183 != 0 && v183 != -1) {
                             if (*(char*)v183 != 0) {
                                 v29 = (char*)v183;
                                 if ((__uint64_t)v29 != 0) {
                                     if (strlen(v29) < 300) {
                                         strcpy(PKTargetName, v29);
                                     }
                                 }
                             }

                         }

                         /*
                         __uint64_t v58 = *((__uint64_t*)TmpMem.A + 7); //PlayerHeroDisplay::UpdateNamePlate(__int64 result)  電腦版的名字儲存方式跟ANDROID 版本不同
                         __uint64_t v60 = v58 & 0xFFFFFFFFFFFFFFFELL;

                         GENERAL_PRINT("[+]v60 = %llx", v60);

                         char* v29;
                         if (v60 != 0 && v60 != -1) {
                             if (*((__uint64_t*)v60 + 3) >= 0x10) {
                                 v29 = *(char**)v60;
                             }
                             else {
                                 v29 = (char*)v60;
                             }
                             if ((__uint64_t)v29 != 0) {
                                 if (strlen(v29) < 300) {
                                     strcpy(PKTargetName, v29);
                                 }
                             }
                         }
                         */
                     }
                     catch (const char* e1) {
                         GENERAL_PRINT("[+]GetPKTargetInfo Error Catch : %s", e1);
                     }



                 }
                 else {
                     IsPK = 0;
                 }
            }

        }
    }
}


void SetQuickSlotAuto(char Switch,char Pos) {

    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __int64_t PlayerHero = *(__int64_t*)(GameInstance + AgentOffset); // Game::GetPlayerHeroDisplay
        if (PlayerHero != 0) {
            //__int64_t QuickSetBook = *(__int64_t*)(PlayerHero + QuickSetBookOffset);

            //if (QuickSetBook != 0) {
                char v29 = (*(__int64(__fastcall**)(__int64))(*(__int64*)PlayerHero + 200i64))(PlayerHero);
                PlayerHero_SetUseAuto(PlayerHero, v29, (char)Pos, (char)Switch);
               //char WeaponGroupType = PlayerHero_GetWeaponGroupType(PlayerHero);
              // QuickSetBook_SetUseAuto(QuickSetBook, WeaponGroupType, (char)Pos, (char)Switch);
           // }

        }
    }

}

void GetTargetInfor() //ULHWidget_Scene_SleepMode::UpdateHPMP
{
    char ActorName[300];
    char ActorName16[600];
    char GuildName16[600];
    

    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __int64_t PlayerHero = *(__int64_t*)(GameInstance + AgentOffset); // Game::GetPlayerHeroDisplay
        if (PlayerHero != 0) {

            memset(CurrentTargetName, 0, 300);
            AttackerHp = 0;
            AttackerMaxHp = 0;
            AttackerMp = 0;
            AttackerMaxMp = 0;


            NowTargetID = Game__GetAttackTargetId(GameInstance);

            GENERAL_PRINT("[+]F10 NowTargetID = %llx", NowTargetID);
          //  AttackerPlayerID = *(__uint64_t*)(PlayerHero + PKTargetOffset);
            if (NowTargetID != 0) {
                struct FMemeryType TmpMem;   //FGeometry::ToString
                InitFMem(&TmpMem);
                __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, NowTargetID);
                GENERAL_PRINT("[+]F10 TmpMem.A = %llx", TmpMem.A);
                if (TmpMem.A != 0) {

                    memset(ActorName, 0, 300);
                    memset(ActorName16, 0, 600);
                    memset(GuildName16, 0, 600);

                  //  DEBUG_PRINT("[+]ICharacter = %llx", ICharacter);
                    try
                    {
                        int v9 = *(int*)(TmpMem.A + NowHpOffset);
                        AttackerHp = (int)(float)(v9 & ~(v9 >> 31)); //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
                        AttackerMaxHp = (int)(float)*(signed int*)(TmpMem.A + MaxHpOffset);
                       // GENERAL_PRINT("[+]F10 2 AttackerHp = %x  AttackerMaxHp= %x ", AttackerHp, AttackerMaxHp);

                        AttackerMp = (int)(float)*(signed int*)(TmpMem.A + NowMpOffset); //PlayerHeroDisplay::UpdateFocusBar(PlayerHeroDisplay *this)
                        AttackerMaxMp = (int)(float)*(signed int*)(TmpMem.A + AgentMaxMpOffset);


                        __uint64_t v183 = (*(__int64(__fastcall**)(__uint64_t))(*(__uint64_t*)TmpMem.A + 120LL))(TmpMem.A);  //電腦版是  -8    (128 -8)  //PlayerHeroDisplay::UpdateNamePlate(__int64 result) 
                        char* v29;
                        if (v183 != 0 && v183 != -1) {
                            if (*(char*)v183 != 0) {
                                v29 = (char*)v183;
                                if ((__uint64_t)v29 != 0) {
                                    if (strlen(v29) < 300) {
                                       // strcpy(ActorName, v29);
                                        strcpy(CurrentTargetName, v29);
                                    }
                                }
                            }
                        }

                        /*
                        __uint64_t TmpAgentDisplay = PlayerHero__GetPlayerHeroDisplay(TmpMem.A);
                        if (TmpAgentDisplay != 0) {
                            __uint64_t ICharacter = *(__uint64_t*)(TmpAgentDisplay + ICharacterOffset);

                            if (ICharacter != 0 && ICharacter != -1) {

                                __uint64_t v21 = WeakObjectPtr_Get(ICharacter + 12);
                                if (v21 != 0) {
                                    //   DEBUG_PRINT("[+] v21  = %llx  ", v21);
                                    __uint64_t v22 = *(__uint64_t*)(v21 + ICharacterNameOffSet);
                                    //DEBUG_PRINT("[+] v22  = %llx  ", v22);
                                    unsigned int v24 = *(unsigned int*)(v21 + ICharacterNameOffSet + 12);
                                    //  DEBUG_PRINT("[+] v24  = %d  ", v24);
                                    if (v22 != 0) {

                                        if (v24 > 0 && v24 < 300) {
                                            memcpy(ActorName16, (char*)v22, v24*2);
                                            strcpy(CurrentTargetName, UTF16ToUTF8((char*)ActorName16));
                                        }
                                    }
                                }
                            }
                        }
                        */

                        /*
                        GENERAL_PRINT("[+]F10 5 AttackerMp = %x  AttackerMaxMp= %x ", AttackerMp, AttackerMaxMp);
                        __uint64_t v58 = *(__uint64_t*)((__uint64_t)TmpMem.A + 56); //PlayerHeroDisplay::UpdateNamePlate(__int64 result)  電腦版的名字儲存方式跟ANDROID 版本不同
                        __uint64_t v60 = v58 & 0xFFFFFFFFFFFFFFFELL;

                        GENERAL_PRINT("[+]F10 v60 = %llx", v60);

                        char* v29;
                        if (v60 != 0 && v60 != -1) {

                            if (*((__uint64_t*)v60 + 3) >= 0x10) {
                                v29 = *(char**)v60;
                            }
                            else {
                                v29 = (char*)v60;
                            }

                            if ((__uint64_t)v29 != 0) {
                                if (strlen(v29) < 300) {
                                    strcpy(CurrentTargetName, v29);
                                }
                            }
                        }
                        */
                    }
                    catch (const char* e1){
                        GENERAL_PRINT("[+]F10 Error Catch : %s", e1);
                    }


                }
            }

            //  TmpPoint.XCoor = (float)*(signed int*)(Agent + CoorOffset);
            //  TmpPoint.YCoor = (float)*(signed int*)(Agent + CoorOffset + 4);
            //  TmpPoint.ZCoor = (float)*(signed int*)(Agent + CoorOffset + 8);
        }
    }
}

int GetCurrentMap() {  //ULHWidget_MapMove::SetAreaNameText 向上找 用他的FUNCTION
    //v34 = ULHMapMgr::GetMapIndex(*(ULHMapMgr **)(LHGameInstance + 392));
    //result = UMapInfoSheet::GetRecord(v33, v34);
     // v36 = result;
    // if ( (_QWORD)v37 )
    //  result = FMemory::Free((FMemory *)v37, v35);
   // if ( v36 )
    //  result = ULHWidget_MapMove::SetAreaNameText(v22, *(_DWORD *)(v36 + 64), v4);
    MyMapID = -1;
    MyZoneID = -1;
    MyZoneType = 0;
    memset(MyMapName, '\0', 400);
    memset(MyZoneName, '\0', 400);

    struct FMemeryType TmpMem;
    struct FMemeryType TmpMem2;
    struct FMemeryType TmpMem3;


    __int64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        MyMapID = *(int*)(GameInstance + MapID_Offset);// AutoPlay2::SingleCombat(AutoPlay2 *this) AutoPlay2::setMoveParam(v11, v44[17],
        if (GameInstance != 0) {   
            __uint64_t InterPtr = *(__uint64_t*)(GameInstance + AgentOffset); //Game::IsAvailablePk(Game *this)
            if (InterPtr != 0) {
                MyZoneType = (char)*(int*)(InterPtr + ZoneTypeOffset ); //Game::IsAvailablePk(Game *this)
               // GENERAL_PRINT("[+] MyZoneType =%d  \n", MyZoneType);
            }


            __int64_t UIMiniMapPanel = 0;
            // UIMiniMapPanel = GameUI_GetPanel(UIMiniMapPanelType); //UISleepModePanel::PreTick  GameUI::GetPanel(v13, 0x1Cu, v283);
            UIMiniMapPanel = GameUI_GetPanelByName(UIMiniMapPanelName); //UISleepModePanel::PreTick  GameUI::GetPanel(v13, 0x1Cu, v283);


            if (UIMiniMapPanel != 0) {
                UIMiniMapPanelType = GameUI_FindPanelType(UIMiniMapPanelType, UIMiniMapPanel); //UISleepModePanel::PreTick  GameUI::GetPanel(v13, 0x1Cu, v283);
                IsGetUIMiniMapPanelType = 1;
            }
            else {
                if (IsGetUIMiniMapPanelType == 1) {
                    UIMiniMapPanel = GameUI_GetPanel(UIMiniMapPanelType);
                }
            }

            if (UIMiniMapPanel) {
                MyZoneID = *(__int64_t*)(UIMiniMapPanel + ZoneID_Offset); //UIMiniMapPanel::RefreshDistrictName;
                strcpy(MyZoneName, (char*)(UIMiniMapPanel + ZoneName_Offset));//UIMiniMapPanel::setPlaceText
            }
          

          //  GENERAL_PRINT("[+] MyZoneID =%lld  \n", MyZoneID);
           // GENERAL_PRINT("[+] MyZoneName =%s  \n", MyZoneName);
        }
    }

   // MyMapID = (int)MapIndex;

    // DEBUG_PRINT("[+] MyMapID: MyMapID =%d  \n",MyMapID);


    return MyMapID;
}




void GetChildUIPanelList(__uint64_t ParentElement, char* buf, int bufsize, char* Largebuf, int Largebufsize, char* Resultbuf, int Resultbufsize, int IsGetAllChild)
{

    DEBUG_PRINT("[+] GetChildUIPanelList in =%lx \n", ParentElement);
    char TmpHex[4000];
    char FTextContent[2000];
    char UObjectName[200];
    char UObjectTypeName[200];
    int HaveData = 0;
    __uint64_t UIMangerPtr = GetUIManager();    // UIPanelAddr = GetUIPanel(UIMangerPtr,i);
    __uint64_t  UIPanelAddr = 0;
    __uint64_t  ThisElementPtr = 0;
    
    int ElementIsShow = 0;
    if (UIMangerPtr != 0) {
        int Count = GetUIPanelList(UIMangerPtr);
        if (Count > 0) {
            for (int i = 0; i < Count; i++)
            {
                if (UiElement[i].IsUsed == 1) {
                    UIPanelAddr = UiElement[i].Pointer;

                    if (UIPanelAddr != 0) {

                        if (IsUUserWidget(UIPanelAddr)) {
                            ElementIsShow = UUserWidget_GetIsVisible(UIPanelAddr); //上下一樣
                            ThisElementPtr = UTSWidgetPanel_GetWidgetTree(UIPanelAddr);
                            if (ElementIsShow == 1) {
                                if (ThisElementPtr != 0) {
                                    if (UWidget_IsVisible(ThisElementPtr) == 0) {
                                        ElementIsShow = 0;
                                    }
                                }
                            }
                           
                           
                        }
                        else {
                            ElementIsShow = UWidget_IsVisible(UIPanelAddr); //上下一樣
                        }

                        if (ElementIsShow == 1) {
                            //struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(UIPanelAddr);
                            //if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                           //     ElementIsShow = 0;
                           // }

                            if (ElementIsShow == 1) {
                                GetFNameStr(UObjectName, (__uint64_t)(UIPanelAddr + 24));
                                GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(UIPanelAddr + 16) + 24));

                                snprintf(buf, bufsize, "{\"Result\":0,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"\",\"Hex\":\"\",\"IsRunn\":1,\"IsEn\":1}", UObjectName, UObjectTypeName, UIPanelAddr);

                                if (HaveData == 1) {
                                    strcat(Largebuf, ",");//SplitLine
                                }
                                strcat(Largebuf, buf);
                                HaveData = 1;
                            }
                           
                        }
                    }
                }
            }
        }
    }
    DEBUG_PRINT("[+] GENERAL_PRINT out  \n");

}



void GetChildUIList(__uint64_t ParentElement, char* buf, int bufsize, char* Largebuf, int Largebufsize, char* Resultbuf, int Resultbufsize, int IsGetAllChild)
{
    int i;
    int HasText = 0;
    char TmpHex[4000];
    char FTextContent[2000];
    char UObjectName[200];
    char UObjectTypeName[200];


    int HaveData = 0;
    __uint64_t ElementIsShow = 0;
    __uint64_t ElementIsEnable;
    int ChildCount = 0;
    __uint64_t result = 0;
    __uint64_t* BeginAddress;
    __uint64_t TmpUObject;

    memset(buf, '\0', bufsize);
    memset(Largebuf, '\0', Largebufsize);
    memset(Resultbuf, '\0', Resultbufsize);

    DEBUG_PRINT("[+] ParentElement=%llx \n", ParentElement);

    InitFMem(&FixedAllChildWidgetMem);

    result = old_GetAllChildWidgets((__uint64_t)&ParentElement - 48, (__uint64_t)&FixedAllChildWidgetMem.A);//;

    if (*(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8) == 0) { //ChildCount = TmpParentWW.B;//*(int *)(b + 4);
        ChildCount = 0;
    }
    else {
        ChildCount = *(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8);
    }

    BeginAddress = (__uint64_t*)FixedAllChildWidgetMem.A; //*(int**)b;
    if (ChildCount == 0) {
        result = 0;
    }


    GetFNameStr(UObjectName, (__uint64_t)(ParentElement + 24));
    GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(ParentElement + 16) + 24));

    DEBUG_PRINT("[+]<<<< Parent Name =%s  Type =%s  ChildCount =%d  \n",UObjectName,UObjectTypeName,result);


    if (ChildCount > 0 && ParentElement != 0) {
        for (i = 0; i < ChildCount; i++) {
            TmpUObject = BeginAddress[i];

            //DEBUG_PRINT("[+] TmpUObject = %llx \n", TmpUObject);

            if (UWidget_GetParent(TmpUObject) == ParentElement || IsGetAllChild == 1) {

            //    DEBUG_PRINT("[+] UObjectName = %d / %d \n", i, ChildCount);

                GetFNameStr(UObjectName, (__uint64_t)(TmpUObject + 24));  //From UObject    //參考UWidgetTree::FindWidget //Uobject真名地址 參考 UObjectBase::AddObject
                GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(TmpUObject + 16) + 24));

             //   DEBUG_PRINT("[+] UObjectName2 = %d / %d \n", i, ChildCount);

                if (strcmp(UObjectTypeName, "CircularView") == 0) {
                    DEBUG_PRINT("[+] UObjectName = %s UObjectTypeName = %s \n", UObjectName, UObjectTypeName);


                    //UCircularView::GetDisplayedWidgetsNum
                    int ListCount = *(int*)(TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset + 8);//ULHLoopListView::GetNumItems
                    __uint64_t ItemPtr = 0;
                    __uint64_t WidgetPtr = 0;
                    DEBUG_PRINT("[+]ListCount = %d \n", ListCount);
                    for (int k = 0; k < ListCount; k++)
                    {
                        __uint64_t EntryWidgetsPtr = TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset ;
                        DEBUG_PRINT("[+]EntryWidgetsPtr = %x \n", EntryWidgetsPtr);
                        WidgetPtr = *(__uint64_t*)(*(__uint64_t*)EntryWidgetsPtr + 8 * k);

                        if (WidgetPtr != 0) {

                            if (IsUUserWidget(WidgetPtr)) {
                                ElementIsShow = UUserWidget_GetIsVisible(WidgetPtr); //上下一樣
                                ElementIsEnable = 1;
                            }
                            else {
                                ElementIsShow = UWidget_IsVisible(WidgetPtr); //上下一樣
                                ElementIsEnable = UWidget_GetIsEnabled(WidgetPtr);
                            }

               

                            struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(WidgetPtr);
                            if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                                ElementIsShow = 0;
                            }
                            DEBUG_PRINT("[+] ElementIsShow = %d \n", ElementIsShow);


                            GetFNameStr(UObjectName, (__uint64_t)(WidgetPtr + 24));  //From UObject    //參考UWidgetTree::FindWidget //Uobject真名地址 參考 UObjectBase::AddObject
                            GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(WidgetPtr + 16) + 24));

                            DEBUG_PRINT("[+] ChildName =%s Type=%s  IsShow = %lx  \n", UObjectName, UObjectTypeName, ElementIsShow);
                            HasText = GetWidgetStr(WidgetPtr, UObjectTypeName, FTextContent, sizeof(FTextContent));

                            if (HasText == 1) {
                                memset(TmpHex, '\0', sizeof(TmpHex));
                                StrToHex(FTextContent, TmpHex);
                                if (strstr(FTextContent, "\"")) {
                                    std::string TmpFText = FTextContent;
                                    TmpFText = Replace(TmpFText, "\"", "@$Quao$@");
                                    //ReplaceStr(FTextContent, "\"", "@$Quao$@", Resultbuf, Resultbufsize);
                                    snprintf(buf, bufsize, "{\"Result\":1,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"%s\",\"Hex\":\"%s\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, WidgetPtr, Resultbuf, TmpHex, ElementIsShow, ElementIsEnable);
                                }
                                else {
                                    snprintf(buf, bufsize, "{\"Result\":1,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"%s\",\"Hex\":\"%s\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, WidgetPtr, FTextContent, TmpHex, ElementIsShow, ElementIsEnable);
                                }

                            }
                            else {
                                snprintf(buf, bufsize, "{\"Result\":0,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"\",\"Hex\":\"\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, WidgetPtr, ElementIsShow, ElementIsEnable);
                            }

                            DEBUG_PRINT("[+] ChildName =%s Type=%s  Text =\"%s\" IsShow = %lx  \n", UObjectName, UObjectTypeName, FTextContent, ElementIsShow);

                            if (HaveData == 1) {
                                strcat(Largebuf, ",");//SplitLine
                            }
                            strcat(Largebuf, buf);
                            HaveData = 1;
                            
                        }
                    }
                    GetFNameStr(UObjectName, (__uint64_t)(TmpUObject + 24));  //From UObject    //參考UWidgetTree::FindWidget //Uobject真名地址 參考 UObjectBase::AddObject
                    GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(TmpUObject + 16) + 24));

                }




                ElementIsShow = UWidget_IsVisible(TmpUObject);
                ElementIsEnable = UWidget_GetIsEnabled(TmpUObject);
                DEBUG_PRINT("[+] ChildName =%s Type=%s  IsShow = %lx  \n", UObjectName, UObjectTypeName, ElementIsShow);
                HasText = GetWidgetStr(TmpUObject, UObjectTypeName, FTextContent, 2000);
                //HasText = 0;

                if (HasText == 1) {
                    memset(TmpHex, '\0', sizeof(TmpHex));
                    StrToHex(FTextContent, TmpHex);
                    if (strstr(FTextContent, "\"")) {

                        std::string TmpFText = FTextContent;
                        TmpFText = Replace(TmpFText, "\"", "@$Quao$@");
                        snprintf(buf, bufsize, "{\"Result\":1,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"%s\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, TmpUObject, TmpFText.c_str(), ElementIsShow, ElementIsEnable);
                    }
                    else {
                        snprintf(buf, bufsize, "{\"Result\":1,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"%s\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, TmpUObject, FTextContent, ElementIsShow, ElementIsEnable);
                    }

                }
                else {
                    snprintf(buf, bufsize, "{\"Result\":0,\"Name\":\"%s\",\"Type\":\"%s\",\"obj\":\"%llx\",\"txt\":\"\",\"Hex\":\"\",\"IsRunn\":%ld,\"IsEn\":%ld}", UObjectName, UObjectTypeName, TmpUObject, ElementIsShow, ElementIsEnable);
                }

                DEBUG_PRINT("[+] ChildName =%s Type=%s  Text =\"%s\" IsShow = %lx  \n", UObjectName, UObjectTypeName, FTextContent, ElementIsShow);

                if (HaveData == 1) {
                    strcat(Largebuf, ",");//SplitLine
                }
                strcat(Largebuf, buf);
                HaveData = 1;

            }

        }

    }

    DEBUG_PRINT("[+]Largebuf len = %d",strlen(Largebuf));

    DEBUG_PRINT("[+] GetChildUIList FixedAllChildWidgetMem Finish \n");

    if (FixedAllChildWidgetMem.A != 0) {
        FMemory_Free(FixedAllChildWidgetMem.A);
    }

  //  *(int*)((__uint64_t)&FixedAllChildWidgetMem.A + 8) = 0;

    DEBUG_PRINT("[+] GetChildUIList Finish2 \n");

}

int IsClassEqual(__int64_t TargetClass, __int64_t AActor) {
    int Result = 0;
    __int64_t v40 = 0, v41 = 0, v42 = 0, v37 = 0;
    if (AActor != 0) {
        v40 = TargetClass;
        v41 = *((__int64_t*)AActor + 2);
        v42 = *(signed int*)(v40 + 64);
        Result = 1;
        if ((signed int)v42 > * (signed int*)(v41 + 64) || *(__int64_t*)(*(__int64_t*)(v41 + 56) + 8 * v42) != v40 + 56) {
            Result = 0;
        }
    }
    return Result;

}

__int64_t GetManager(__int64_t v11) {

    if (v11 == 0) {
        return 0;
    }
    // GENERAL_PRINT("[+]GetManager = 1");
    int i;
    struct FMemeryType TmpMem;
    InitFMem(&TmpMem);
    __int64_t unknown, v1;
    __int64_t Result = 0;
    __uint64_t v15;

    GetObjectsOfClass(v11, (__uint64_t)&TmpMem.A, 1, 16, 0);

    // GENERAL_PRINT("[+]GetManager = 2");
    int v12 = (unsigned int)(TmpMem.B);
    i = -1;

    //GENERAL_PRINT("[+]v12 = %d", v12);

    int ActorCount = 0;

    int v13 = i + 1;
    __int64_t v14 = TmpMem.A;
    for (i = v13; v13 < (int)(TmpMem.B); i = ++v13)
    {
        if (*(__int64_t*)(TmpMem.A + 8 * v13))
            break;
    }


    int IsUsed = 0;
    char type = 0;
    struct FMemeryType TmpMem2;
    int ActorHp = 0, ActorMaxHp = 0;
    int UBaseObjectID = 0;

    while (v13 >= 0 && v13 < v12)
    {
        v15 = *(__int64_t*)(v14 + 8 * v13);


        if (IsClassEqual(v11, v15)) {
            Result = v15;
        }

        v12 = (int)(TmpMem.B);
        v13 = i + 1;
        v14 = TmpMem.A;
        for (i = v13; v13 < (int)(TmpMem.B); i = ++v13)
        {
            if (*(__int64_t*)(TmpMem.A + 8 * v13))
                break;
        }
    }

    if (TmpMem.A != 0) {
        FMemory_Free(TmpMem.A);
    }
    return Result;
}


void FakeCallGameFunction()
{
    int TmpResult;
    
    


    if (StartCallFunction == 1)
    {
        // usleep(600000*1000);
        AutoRunToPos(FakePara1, DestCoor.XCoor, DestCoor.YCoor, DestCoor.ZCoor);  //ULHMapMgr::SetAutoMove
    }
    else if (StartCallFunction == 2)
    {
        AutoRunToPosByNoTeleport(FakePara1,DestCoor.XCoor, DestCoor.YCoor, DestCoor.ZCoor);
    }
    else if (StartCallFunction == 3)
    {
        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    __uint64_t Bag2Ptr = GetBag2();
                    __uint64_t Item2Ptr = BagItem[FakePara1].item2Ptr;

                    if (Bag2Ptr != 0) {

                        __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                        // __uint64_t v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                        __uint64_t v42 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr);
                        __uint64_t v41 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr);
                        __uint64_t v32 = Item2__CastGroceryItem(Item2Ptr, Item2Ptr);
                        /*
                        if (v32 != 0) {
                            __uint64_t v79 = Grocery2_GetSubKey(v32);
                            __uint64_t  v80 = Grocery2_GetSubValue(v32);
                           // BagItem[i].isDeCompsable = Grocery2_IsDisassemble(TmpCastItem);
                            Grocery_ProcessUseGroceryItem(v42, (unsigned int)v41, TmpItemID, v79, v80, 0, 0);

                            //
                        }
                        */

                        Bag2_RequestConsumeItem(Bag2Ptr, TmpItemID, 1, 0);


                        DEBUG_PRINT("[+] UseItem: %ld  \n", FakePara1);

                    }
                }
                


               
            }
        }

    }
    else if (StartCallFunction == 12)
    {
        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    __uint64_t Bag2Ptr = GetBag2();
                    __uint64_t Item2Ptr = BagItem[FakePara1].item2Ptr;
                    __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                    // __uint64_t v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                    __uint64_t v42 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr);
                    __uint64_t v41 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr);
                    __uint64_t v32 = Item2__CastGroceryItem(Item2Ptr, Item2Ptr);
                    if (v32 != 0) {
                        __uint64_t v79 = Grocery2_GetSubKey(v32);
                        __uint64_t  v80 = Grocery2_GetSubValue(v32);
                        // BagItem[i].isDeCompsable = Grocery2_IsDisassemble(TmpCastItem);
                        Grocery_ProcessUseGroceryItem(v42, (unsigned int)v41, TmpItemID, v79, v80, 0, 0);

                        //  Bag2_RequestConsumeItem(Bag2Ptr, TmpItemID, 1, 0);
                    }

                }


                DEBUG_PRINT("[+] UseItem: %ld  \n", FakePara1);
            }
        }

    }
    else if (StartCallFunction == 4)
    {
        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    __uint64_t Bag2Ptr = GetBag2();
                    __uint64_t Item2Ptr = BagItem[FakePara1].item2Ptr;
                    __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                    __int16 v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                    //  __uint64_t v11 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr);

                    if (FakePara2 >= BagItem[FakePara1].Count) {
                        FakePara2 = BagItem[FakePara1].Count;
                    }

                    Bag2_RequestDestroyItem(Bag2Ptr, TmpItemID, v12, (int)FakePara2);
                    DEBUG_PRINT("[+] DestroyItem: %ld  \n", FakePara1);
                }
            }
        }
    }
    else if (StartCallFunction == 5) {
        ReadBagItem();
    }
    else if (StartCallFunction == 6) {
        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    __uint64_t Bag2Ptr = GetBag2();
                    __uint64_t Item2Ptr = BagItem[FakePara1].item2Ptr;
                    __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                    // __uint64_t v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                    __uint64_t v11 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr);

                    if (FakePara2 >= BagItem[FakePara1].Count) {
                        FakePara2 = BagItem[FakePara1].Count;
                    }

                    Bag2_RequestDisassembleItem(Bag2Ptr, TmpItemID, (int)FakePara2); //v11
                    DEBUG_PRINT("[+] Decompose Item: %ld  \n", FakePara1);
                }
            }
        }
    }
    else if (StartCallFunction == 7) {
        GetMissionList();

    }
    else if (StartCallFunction == 48) {
        CallResult = 0;
        ReadBagItem();



        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {

                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetTradeBagFNameID(BagItem[FakePara1].InstanceId);
                    DEBUG_PRINT("[+] index: %d  \n", index);
                    // if (FNameID != 0) {
                     //    TmpMem.A = FNameID;
                    if (index > -1) {
                        __int64_t UITradePanel = 0;
                        //UITradePanel = GameUI_GetPanel(TradePanelID); //UITradeItemList::OnClickSlotForFavarites(UITradeItemList * this, const FName * a2)
                        UITradePanel = GameUI_GetPanelByName(TradePanelName);
                        if (UITradePanel != 0) {
                            DEBUG_PRINT("[+] UITradePanel: %llx  \n", UITradePanel);
                            __int64_t UITradeBag = UITradePanel + TradeBagOffset; //UITradePanel::OnClickSlotButton(UITradePanel *this, const FName *a2) UITradeBag::OnClickSlotButton(__int64 a1, __int64 a2)
                            if (UITradeBag != 0) {
                                DEBUG_PRINT("[+] UITradeBag: %llx  \n", UITradeBag);
                                CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UITradeBag + UITradeBagItemCircularViewOffset), index, 0, 1);

                                CallResult = 1;
                            }
                        }
                    }

                    // }
                }




            }
        }
    }
    else if (StartCallFunction == 8) {
        CallResult = 0;
        ReadBagItem();

        

        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
 
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetTradeBagFNameID(BagItem[FakePara1].InstanceId);
                    DEBUG_PRINT("[+] index: %d  \n", index);
                   // if (FNameID != 0) {
                    //    TmpMem.A = FNameID;
                    if (index > -1) {
                        __int64_t UITradePanel = 0;
                        //UITradePanel = GameUI_GetPanel(TradePanelID); //UITradeItemList::OnClickSlotForFavarites(UITradeItemList * this, const FName * a2)
                        UITradePanel = GameUI_GetPanelByName(TradePanelName);
                        if (UITradePanel != 0) {
                            DEBUG_PRINT("[+] UITradePanel: %llx  \n", UITradePanel);
                            __int64_t UITradeBag = UITradePanel + TradeBagOffset; //UITradePanel::OnClickSlotButton(UITradePanel *this, const FName *a2) UITradeBag::OnClickSlotButton(__int64 a1, __int64 a2)
                            if (UITradeBag != 0) {
                                DEBUG_PRINT("[+] UITradeBag: %llx  \n", UITradeBag);
                                CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UITradeBag + UITradeBagItemCircularViewOffset), index, 0, 1);

                                UITradeBag_OnClickSlotButton(UITradeBag, index);
                                //UITradeBag_OnClickSlotButton(UITradeBag, TmpMem.A);
                                CallResult = 1;
                            }
                        }
                    }
                       
                   // }
                }

                
               

            }
        }
    }
    
    else if (StartCallFunction == 44) {
        CallResult = 0;

        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetBagItemFNameID(BagItem[FakePara1].InstanceId);

                    //TmpMem.A = FNameID;
                    if (index > -1) {
                        __int64_t UIInventoryPanel = 0;
                        //UIInventoryPanel = GameUI_GetPanel(UIInventoryPanelID);
                        UIInventoryPanel = GameUI_GetPanelByName(UIInventoryPanelName);
                        GENERAL_PRINT("[+] UIInventoryPanel: %lx  \n", UIInventoryPanel);
                        if (UIInventoryPanel != 0) {

                            CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UIInventoryPanel + UIItemCircularViewOffset), index, 0, 1);

                        }
                    }
                }
            }
        }

    }
    else if (StartCallFunction == 9) {
        CallResult = 0;

        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetBagItemFNameID(BagItem[FakePara1].InstanceId);

                    //TmpMem.A = FNameID;
                    if (index > -1) {

                        __int64_t UIInventoryPanel = 0;
                        //UIInventoryPanel = GameUI_GetPanel(UIInventoryPanelID);
                        UIInventoryPanel = GameUI_GetPanelByName(UIInventoryPanelName);
                        GENERAL_PRINT("[+] UIInventoryPanel: %lx  \n", UIInventoryPanel);
                        if (UIInventoryPanel != 0) {

                            CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UIInventoryPanel + UIItemCircularViewOffset), index, 0, 1);

                            if (RealIndexReturn > -1) {
                                GENERAL_PRINT("[+] RealIndexReturn: %d  \n", RealIndexReturn);
                                UIInventoryPanel_OnClickItemSlotButton(UIInventoryPanel, (__int64_t)&TmpMem.A, RealIndexReturn);//UIInventoryPanel2::OnClickItemSlotButton
                            }
                           
                            CallResult = 1;
                        }
                    }
                  
                }
            }
        }
    }
    else if (StartCallFunction == 10) {
        __uint64_t GameUIPtr = GetGameUI();

        __uint64_t Tutorial = *(__uint64_t*)(GameUIPtr + 96);  //UISignatureSkillPadPanel6::ReceiveKeyboardDown

        struct FMemeryType TmpMem;
        InitFMem(&TmpMem);
        if (Tutorial != 0) {
            GENERAL_PRINT("[+] Tutorial Pass  \n");

            Tutorial_End(Tutorial,0,0);
        }

    }
    else if (StartCallFunction == 11) {
        GetTeamList();

    }
  
    else if (StartCallFunction == 13) {
        SetStopMove();

    }
    else if (StartCallFunction == 14) {
        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
            DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
            if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                if (BagItem[FakePara1].IsUsed == 1)
                {

                    __uint64_t Bag2Ptr = GetBag2();
                    __uint64_t Item2Ptr = BagItem[FakePara1].item2Ptr;

                    if (Bag2Ptr != 0) {
                        __uint64_t TmpCastEquipItem = Item2__CastEquipItem(Item2Ptr, Item2Ptr);
                        if (TmpCastEquipItem != 0) {  //UIEquipSlotItemDetailProcessor::ProcessFuncButton
                            __uint64_t v50 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 128))(Item2Ptr);
                            __uint64_t v52 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 128))(Item2Ptr);
                            __int64_t EquipSet = GetEquipSetPtr();
                          

                            __uint64_t v53 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                            char v51 = EquipSet_GetEquipSlot(EquipSet, v50, (unsigned short)v53);
                            __uint64_t v54 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);

                            if (FakePara2 == 1) {
                                Bag2_RequestEquipItem(Bag2Ptr, *(char*)(EquipSet + 8), (unsigned short)v53, v54, v51, 1);
                            }
                            else {
                                Bag2_RequestEquipItem(Bag2Ptr, *(char*)(EquipSet + 8), (unsigned short)v53, v54, v51, 0);
                            }


                        }

                    }




                }
            }
        }
    }
    else if (StartCallFunction == 15) {
        __int64_t PartyMgrAddr = GetParty();
        Party_RequestInvitePartyByHeroName(PartyMgrAddr, (char*)InviteMemberName.c_str(),0);

    }
    else if (StartCallFunction == 16) {
        GlobalResultStr = ReadActorList();

    }
    else if (StartCallFunction == 17) {
        
       

        __int64_t UISleepModePanel = 0;
        __int64_t UISleepModePanel2 = 0;
       // UISleepModePanel = GameUI_GetPanel(SleepModeType); //UISleepModePanel::GetPanelType(UISleepModePanel *this)
       // UISleepModePanel2 = GameUI_GetPanel(SleepModeType2); //UISleepModePanel::GetPanelType(UISleepModePanel *this)

        UISleepModePanel = GameUI_GetPanelByName(SleepModeTypePanelName); //UISleepModePanel::GetPanelType(UISleepModePanel *this)
        UISleepModePanel2 = GameUI_GetPanelByName(SleepModeTypePanel2Name); //UISleepModePanel::GetPanelType(UISleepModePanel *this)

         
        if (FakePara1 == 0) {
            if (UISleepModePanel != 0) {
                UISleepModePanel_OnClose(UISleepModePanel, 0);
               // fake_UISleepModePanel_OnClose(UISleepModePanel,0);
            }
            
        }
        else if (FakePara1 == 3) {
         
            if (UISleepModePanel == 0) {
                DEBUG_PRINT("[+] No Panel");
                __uint64_t GameUIPtr = GetGameUI();
                if (GameUIPtr != 0) {
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel, 0);
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel2, 0);
                    
                }
            }

            if (UISleepModePanel != 0) {
                UISleepModePanel_Open(UISleepModePanel);
            }
          
        }
        else if (FakePara1 == 2) {
          
            if (UISleepModePanel == 0) {
                DEBUG_PRINT("[+] No Panel");
                __uint64_t GameUIPtr = GetGameUI();
                if (GameUIPtr != 0) {
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel, 0);
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel2, 0);
                }
            }

            if (UISleepModePanel != 0) {
                UISleepModePanel_SetSleepState(UISleepModePanel, 2, 1);
            }
        }
        else if (FakePara1 == 4) {

            if (UISleepModePanel == 0) {
                DEBUG_PRINT("[+] No Panel");
                __uint64_t GameUIPtr = GetGameUI();
                if (GameUIPtr != 0) {
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel, 0);
                    UIPanelManager_OpenPanel(GameUIPtr, UISleepModePanel2, 0);
                }
            }
        
            DEBUG_PRINT("[+] UISleepModePanel");
            if (UISleepModePanel != 0) {
                *(char*)(UISleepModePanel + EnterSleepModeOffSet) = 2;
                UISleepModePanel_Open(UISleepModePanel);
            }
            

        }


   

    }

    else if (StartCallFunction == 18) {      //ULHWorldMap::CheckCamMoveCpompleteAction 
      
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 19) {      //ULHWorldMap::CheckCamMoveCpompleteAction 
    

     
        StartCallFunction = 0;

    }
    else if (StartCallFunction == 20) {

        __uint64_t TmpFB2ScalabilityControllerPtr = GetFB2ScalabilityController();
        if (TmpFB2ScalabilityControllerPtr != 0) {
            if (TmpFB2ScalabilityControllerPtr != 0) {
                FB2ScalabilityController_SetMaxFPS(TmpFB2ScalabilityControllerPtr, RandomVal);
            }
        }

        
        UEngine_SetMaxFPS(0, RandomVal);
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 21) { //ClickLink

        GENERAL_PRINT("[+]StartCallFunction = %s \n", GlobalResult);
        __uint64_t TmpElement = FoundUIByTree(GlobalResult, 1);
        if (TmpElement != 0)
        {
            GENERAL_PRINT("[+]TmpElement1 = %lld \n", TmpElement);
            if (UWidget_IsVisible(TmpElement) && UWidget_GetIsEnabled(TmpElement) ) {

                GlobalTmpVal = TmpElement;
                GENERAL_PRINT("[+]GlobalTmpVal11 = %lld \n", GlobalTmpVal);
                char UObjectTypeName[500];
                memset(UObjectTypeName, 0, 500);
                GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(GlobalTmpVal + 16) + 24));
                GENERAL_PRINT("[+]UObjectTypeName = %s \n", UObjectTypeName);
 

                char TmpMemA[1500];
                memset(TmpMemA, '\0', 1500);
                GENERAL_PRINT("[+]GlobalTmpVal = %lld \n", GlobalTmpVal);
               
                //try {
                //    fake_UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
                //}
                //catch (...) {

                //}
                if (strcmp(UObjectTypeName, "Button") == 0) {
                    UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
                    try {
                     //   fake_UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
                    }
                    catch (...) {

                    }
                }

                GENERAL_PRINT("[+]GlobalTmpVal2 = %lld \n", GlobalTmpVal);
                StartCallFunction = 0;
                GENERAL_PRINT("[+]fake_GetCursorPos StartCallFunction = %d  \n", StartCallFunction);
            }
        }
    }
    else if (StartCallFunction == 30) { //

        __uint64_t TmpElement = FoundUIByTree(GlobalResult, 1);
        if (TmpElement != 0)
        {
            DEBUG_PRINT("[+]TmpElement = %lld \n", TmpElement);
           

            GlobalTmpVal = TmpElement;
            char UObjectTypeName[500];


            GetFNameStr(UObjectTypeName, (__uint64_t)(GlobalTmpVal + 24)); //From UObject
            // DEBUG_PRINT("[+]UIPanelName = %s \n",  UIPanelName);
            GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(GlobalTmpVal + 16) + 24));

            if (strcmp(UObjectTypeName,"CircularView") == 0) {
                __uint64_t  STableViewBase = *(__uint64_t*)(GlobalTmpVal + STableViewBaseOffset);
                if (STableViewBase) {
                    STableViewBase_SetScrollOffset(STableViewBase, RandomVal);
                }
                    

            }
            else {
                  
                UScrollBox_SetScrollOffset(GlobalTmpVal, RandomVal);
            }

        }

    }
   
    else if (StartCallFunction == 32) { //_ZN11IMap3DPanel21HandleSwipeDeltaEventE9FVector2D

        __int64_t Map3DPanelPanel = 0;
        //Map3DPanelPanel = GameUI_GetPanel(UI3DWorldMapType); //UISleepModePanel::GetPanelType(UISleepModePanel *this)
        Map3DPanelPanel = GameUI_GetPanelByName(UI3DWorldMapName);
        if (Map3DPanelPanel != 0) {
            __int64_t UI3DWorldMap = Map3DPanelPanel + UI3DWorldMapOffset;
            GENERAL_PRINT("[+]UI3DWorldMap = %lx \n", UI3DWorldMap);
            __int64_t Map3DPanelWrapper = *(__int64_t*)(UI3DWorldMap + Map3DPanelWrapperOffset);
            GENERAL_PRINT("[+]Map3DPanelWrapper = %lx \n", Map3DPanelWrapper);
            if (Map3DPanelWrapper != 0) {
                __int64_t IMap3DPanel = *(__int64_t*)(Map3DPanelWrapper + 3 * 8);
                if (IMap3DPanel != 0) {
                    GENERAL_PRINT("[+]DestCoor.XCoor = %f \n", DestCoor.XCoor);
                    GENERAL_PRINT("[+]DestCoor.YCoor = %f \n", DestCoor.YCoor);
                    Map3DPanel_HandleSwipeDeltaEvent(IMap3DPanel,*(__int64_t*)&DestCoor.XCoor, 0);
                }
            }
        }

    } else if (StartCallFunction == 27) { //Click obj

        if (GlobalTmpVal != 0)
        {
            char TmpMemA[1500];
            memset(TmpMemA, '\0', 1500);
            UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
            //fake_UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
            StartCallFunction = 0;
            
        }
    }
    else if (StartCallFunction == 26) { //ForceClick

        __uint64_t TmpElement = FoundUIByTree(GlobalResult, 1);
        if (TmpElement != 0)
        {
            DEBUG_PRINT("[+]TmpElement = %lld \n", TmpElement);
   
            GlobalTmpVal = TmpElement;

            char TmpMemA[1500];
            memset(TmpMemA, '\0', 1500);
            UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
            //fake_UButton_SlateHandleClicked(GlobalTmpVal, (__uint64_t)TmpMemA);
            StartCallFunction = 0;

        }
    }
    else if (StartCallFunction == 22) {
        __uint64_t TmpElement = FoundUIByTree(GlobalResult, 1);
        if (TmpElement != 0)
        {
            DEBUG_PRINT("[+]TmpElement = %lld \n", TmpElement);

            GlobalTmpVal = TmpElement;

            char TmpMemA[300];
            memset(TmpMemA, '\0', 300);
            UButton_SlateHandlePressed(GlobalTmpVal);
            //fake_UButton_SlateHandlePressed(GlobalTmpVal);
        }

    }
    else if (StartCallFunction == 25) {

        __uint64_t TmpElement = FoundUIByTree(GlobalResult, 1);
        if (TmpElement != 0)
        {
            DEBUG_PRINT("[+]TmpElement = %lld \n", TmpElement);
            GlobalTmpVal = TmpElement;

            char TmpMemA[1500];
            memset(TmpMemA, '\0', 1500);

            UButton_SlateHandleReleased(GlobalTmpVal);
           // fake_UButton_SlateHandleReleased(GlobalTmpVal, (__uint64_t)TmpMemA);

        }

        StartCallFunction = 0;
    }
    else if (StartCallFunction == 23) {

        CurrentExp = 0;
        MaximumExp = 0;
        CurrentLv = 0;

        GetPlayerLVExp();
        DEBUG_PRINT("[+]{\"Lv\":%d,\"EXP\":%f,\"MaxEXP\":%f}--end--", CurrentLv, CurrentExp, MaximumExp);

        // GetCurrentPlayerName();
        DEBUG_PRINT("[+] PlayerName:%s--end--", CurrentPlayerName);
        GetPlayerHP();
        DEBUG_PRINT("[+] GetPlayerHP:--end--");
        GetIsMoving();
        DEBUG_PRINT("[+] GetPKTargetInfo:--end--");
        GetPKTargetInfo();
        StartCallFunction = 0;

    }
    else if (StartCallFunction == 24) {

        struct CoorType TmpCoor;
        __int64_t TmpMapID = 0;

       // GENERAL_PRINT("[+]GetMyPos1 \n");
        TmpMapID = GetCurrentMap();
        //GENERAL_PRINT("[+]GetMyPos2 \n");

        TmpCoor = GetCurrentCoor();

        MyMapID = TmpMapID;

        MyXCoor = TmpCoor.XCoor;
        MyYCoor = TmpCoor.YCoor;
        MyZCoor = TmpCoor.ZCoor;
       // GENERAL_PRINT("[+]GetMyPos3 \n");
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 87) { //Dump ALL UI
        Json::Value UIroot;
        GlobalSendRoot = DumpAllUI(UIroot);
        StartCallFunction = 0;
     }
    else if (StartCallFunction == 31) {

        GetTargetInfor();
        DEBUG_PRINT("[+] AttackerHp:%d, AttackerHp:%d AttackerMp:%d AttackerMaxMp:%dCurrentTargetName=%s ", AttackerHp, AttackerMaxHp, AttackerMp, AttackerMaxMp, CurrentTargetName);
        StartCallFunction = 0;

    }
    else if (StartCallFunction == 33) {


        SetQuickSlotAuto((char) FakePara1, (char)FakePara2);
        DEBUG_PRINT("[+] AttackerHp:%d, AttackerHp:%d AttackerMp:%d AttackerMaxMp:%dCurrentTargetName=%s ", AttackerHp, AttackerMaxHp, AttackerMp, AttackerMaxMp, CurrentTargetName);
        StartCallFunction = 0;

    }
    else if (StartCallFunction == 35) {

        SetAuto((char)FakePara1);
        StartCallFunction = 0;

    }
    else if (StartCallFunction == 36) {


        __int64_t ChatPanel3Panel = 0;
       // ChatPanel3Panel = GameUI_GetPanel(UIChatPanel3PanelType); //UISleepModePanel::GetPanelType(UISleepModePanel *this)
        ChatPanel3Panel = GameUI_GetPanelByName(UIChatPanel3PanelName); //UISleepModePanel::GetPanelType(UISleepModePanel *this)
        

        if (ChatPanel3Panel != 0) {
            UIChatPanel3PanelType = GameUI_FindPanelType(UIChatPanel3PanelType, ChatPanel3Panel); //UISleepModePanel::PreTick  GameUI::GetPanel(v13, 0x1Cu, v283);
            IsGetUIChatPanel3PanelType = 1;
        }else{
            if (IsGetUIChatPanel3PanelType == 1) {
                ChatPanel3Panel = GameUI_GetPanel(UIChatPanel3PanelType);
            }
        }
        


        if (ChatPanel3Panel != 0) {
            __int64_t ChatMain = ChatPanel3Panel + UIChatMainOffset;
            ChatMain_sendMessageEscape(ChatMain);
        }
    }
   
    
    else if (StartCallFunction == 37) {

        __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
        GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
        __uint64_t GameInstance = GetGameInstanceE();
        if (GameInstance != 0) {
            struct FMemeryType TmpMem;   //FGeometry::ToString
            InitFMem(&TmpMem);

            if (TmpPtr == 0) {
                Game_SetAttackTargetId(GameInstance, 0, 0,0);
            }
            else {
                __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, TmpPtr);
                GENERAL_PRINT("[+] TmpMem.A: %llx  \n", TmpMem.A);
                // GENERAL_PRINT("[+]TmpAgent = %llx", TmpAgent);
                if (TmpMem.A != 0) {

                    GENERAL_PRINT("[+] SetAttackTargetId: %llx  \n", TmpPtr);

                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                    if (AutoPlay2) {

                        int IsDead = 0;

                        GENERAL_PRINT("[+] IsDead = %d \n", IsDead);
                        if (IsDead == 0) {

                            Game_SetAttackTargetId(GameInstance, TmpPtr, 1,0);
                            CallResult = 1;
                        }

                    }
                }

            }
        }
        StartCallFunction = 0;
    }
        else if (StartCallFunction == 38) {
            CallResult = 0;
            __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
            GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
            __uint64_t GameInstance = GetGameInstanceE();
            if (GameInstance != 0) {
                if (TmpPtr == 0) {
                    Game_SetAttackTargetId(GameInstance, 0, 0,0);
                }
                else {
                    struct FMemeryType TmpMem;   //FGeometry::ToString
                    InitFMem(&TmpMem);
                    __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, TmpPtr);
                    GENERAL_PRINT("[+] TmpMem.A: %llx  \n", TmpMem.A);
                    // GENERAL_PRINT("[+]TmpAgent = %llx", TmpAgent);
                    if (TmpMem.A != 0) {


                        //  Game_UnlockTarget(GameInstance);
                       //   Game_AutoPlayAttackTarget(GameInstance, TmpPtr, 0, 1);
                        //  Game_SetPickedAgentId(GameInstance, 0, 0);
                        //fake_Game_PickTarget(GameInstance, TmpPtr, 0);
                        Game_PickTarget(GameInstance, TmpPtr, 0);

                    }
                }

            }
            StartCallFunction = 0;
        }

    else if (StartCallFunction == 39) {
        CallResult = 0;
        __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
        GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
        __uint64_t GameInstance = GetGameInstanceE();
        if (GameInstance != 0) {
            if (TmpPtr == 0) {
                // Game_SetAttackTargetId(GameInstance, 0, 0,0);
            }
            else {
                struct FMemeryType TmpMem;   //FGeometry::ToString
                InitFMem(&TmpMem);
                __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, TmpPtr);
                GENERAL_PRINT("[+] TmpMem.A: %llx  \n", TmpMem.A);
                // GENERAL_PRINT("[+]TmpAgent = %llx", TmpAgent);
                if (TmpMem.A != 0) {

                    GENERAL_PRINT("[+] SetAttackTargetId: %llx  \n", TmpPtr);

                    __uint64_t SkillContext6Ptr = GetSkillContext6();
                    if (SkillContext6Ptr != 0) {
                        __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                        if (AutoPlay2) {
                            int CanAttackInRange = SkillContext6_CheckCanHitTargetByAutoEy(SkillContext6Ptr, TmpPtr);
                            if (CanAttackInRange) {
                                int IsDead = 0;

                                GENERAL_PRINT("[+] IsDead = %d \n", IsDead);
                                if (IsDead == 0) {
                                    GENERAL_PRINT("[+] AutoPlay2_SingleCombat \n");
                                    // AutoPlay2_SingleSkill(AutoPlay2, *(__int64_t*)(AutoPlay2 + 408));
                                     //
                                     //*(char*)(AutoPlay2 + 10) = 3;
                                    // fake_AutoPlay2_changePlayState(AutoPlay2, 5,1);
                                     //*(char*)(AutoPlay2 + 10) = 5;
                                    // Game_AutoPlayAttack(GameInstance);
                                     // Game_AutoPlayAttack(GameInstance);
                                    // Game_UnlockTarget(GameInstance);
                                    Game_PickTarget(GameInstance, TmpPtr, 0);
                                    //fake_Game_PickTarget(GameInstance, TmpPtr, 0);

                                    CallResult = 1;

                                    //Game_AutoPlayAttackTarget(GameInstance, TmpPtr, 1, 1);
                                     //Game_SetPickedAgentId(GameInstance, 0, 0);
                                     // Game_PickTarget(GameInstance, TmpPtr, 1);

                                      //Game_PickTarget(GameInstance, TmpPtr, 1);
                                }

                            }
                        }
                    }


                }
            }

        }
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 40) {
        GetIsMoving();
        if (IsMoving == 1) {
            __uint64_t HyperRunController = GetHyperRunController(); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
            GENERAL_PRINT("[+] HyperRunController:1  \n");
            if (HyperRunController) {
                //fake_HyperRunController_SetImpossibleAutoMoveEb(HyperRunController, 1);
                HyperRunController_SetImpossibleAutoMoveEb(HyperRunController, 1);
            }

            HyperRunController = GetHyperRunController(); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);
            GENERAL_PRINT("[+] HyperRunController_SetImpossibleAutoMoveEb:1  \n");
            if (HyperRunController) {
                //fake_HyperRunController_PlayHyperRunEh(HyperRunController, 2u);
                HyperRunController_PlayHyperRunEh(HyperRunController, 2u);
            }

        }

    }
    else if (StartCallFunction == 41) {
        GlobalResultStr = GetMapIconList();

    }
    else if (StartCallFunction == 42) {
        __int64_t UI3DMapPanel = 0;
        __int64_t UI3DWorldMap = 0;
        //UI3DMapPanel = GameUI_GetPanel(UI3DWorldMapType);
        UI3DMapPanel = GameUI_GetPanelByName(UI3DWorldMapName);
        if (UI3DMapPanel != 0) {
            UI3DMapPanel_OnWorldMapIconTouched(UI3DMapPanel, (unsigned int)FakePara1, 0);
        }
    }
    else if (StartCallFunction == 43) {

        DumpEquipCollectList();
    }else if (StartCallFunction == 45) {
        ReadStorageItem();
    }else if (StartCallFunction == 46) {
        DEBUG_PRINT("[+] StartCallFunction == 46  \n");

        __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);

        ReadStorageItem();
        DEBUG_PRINT("[+] StorageItemCount: %d  \n", StorageItemCount);
        for (int i = 0; i <= StorageItemCount; i++) {
            if (StorageItem[i].IsUsed == 1)
            {
                if (TmpPtr == (__uint64_t)StorageItem[i].Pointer) {
                    __uint64_t Stash2Ptr = GetStash2();
                    DEBUG_PRINT("[+] Stash2PtrStash2Ptr: %llx  \n", Stash2Ptr);

                    __uint64_t Item2Ptr = StorageItem[i].item2Ptr;
                    if (Stash2Ptr != 0) {
                        DEBUG_PRINT("[+] Stash2PtrStash2Ptr: %llx  \n", Stash2Ptr);

                        __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                        // __uint64_t v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);

                        //Bag2::IsStackableSlot

                        __int64 v36 = 0;
                        //__int64 v36 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr); //ItemCount
                        if (FakePara2 <= StorageItem[i].Count) {
                            v36 = FakePara2;
                        }

                        if (FakePara2 <= v36) {
                            v36 = FakePara2;
                        }

                        __int64 v37 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);  //Pos

                       // __uint64_t TmpItemID2 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr); //ItemID
                       // unsigned __int16 v37 = (unsigned __int16)GetEmptyBagItemSlot(TmpItemID2, v36);

                        DEBUG_PRINT("[+] v37: %d  \n", v37);
                        DEBUG_PRINT("[+] v36: %lld  \n", v36);

                        DEBUG_PRINT("[+] TmpItemID: %lld  \n", TmpItemID);
                        if (v37 > -1) {
                            __uint64_t  UIStashPanel = GameUI_GetPanelByName("bpStashPanel");
                            if (UIStashPanel != 0) {
                               // UIStashPanel_refreshItem(UIStashPanel);
                                Stash2_RequestMoveToInventory(Stash2Ptr, *(__uint64_t*)(UIStashPanel + StorageShopUnknownOffset), (unsigned __int16)v37, (int)v36);
                            }
                            
                        }
                   
                    }
                    break;
                }
            }
        }
    }
    else if (StartCallFunction == 47) {
        DEBUG_PRINT("[+] StartCallFunction == 47  \n");

        __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);

        ReadBagItem();
        DEBUG_PRINT("[+] StorageItemCount: %d  \n", StorageItemCount);

        for (int i = 0; i <= BagItemCount; i++) {
            if (BagItem[i].IsUsed == 1)
            {
                DEBUG_PRINT("[+] TmpPtr: %llx    BagItem[i].Pointer=%llx\n", TmpPtr, BagItem[i].Pointer);
                if (TmpPtr == (__uint64_t)BagItem[i].Pointer) {
                    __uint64_t Bag2Ptr = GetBag2();

                    __uint64_t Item2Ptr = BagItem[i].item2Ptr;
                    if (Bag2Ptr != 0) {
           
                        __uint64_t TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                        // __uint64_t v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                        //Bag2::IsStackableSlot
                        __int64 v36 = 0;
                        //__int64 v36 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64))(Item2Ptr); //ItemCount
                        if (FakePara2 <= BagItem[i].Count) {
                            v36 = FakePara2;
                        }

                        __int64 v37 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);  //Pos
                        //__uint64_t TmpItemID2 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr); //ItemID
                       // unsigned __int16 v37 = (unsigned __int16)GetEmptyBagItemSlot(TmpItemID2, v36);

                        DEBUG_PRINT("[+] v37: %d  \n", v37);
                        DEBUG_PRINT("[+] v36: %lld  \n", v36);

                        DEBUG_PRINT("[+] TmpItemID: %lld  \n", TmpItemID);
                        if (v37 > -1) {
                            __uint64_t  UIStashPanel = GameUI_GetPanelByName("bpStashPanel");
                            if (UIStashPanel != 0) {
                                Bag2_RequestMoveToStash(Bag2Ptr, *(__uint64_t*)(UIStashPanel + StorageShopUnknownOffset), (unsigned __int16)v37, (int)v36);
                            }
                        }
                    }
                    break;
                }
            }
        }

    }
    else if (StartCallFunction == 49) {
        CallResult = 0;

        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                GENERAL_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetSellBagItemFNameID(BagItem[FakePara1].InstanceId);

                    //TmpMem.A = FNameID;
                    if (index > -1) {
                        __int64_t UICitizenShopPanel2 = 0;
                        //UICitizenShopPanel2 = GameUI_GetPanel(59);
                        UICitizenShopPanel2 = GameUI_GetPanelByName(ShopPanel2Name);
                        GENERAL_PRINT("[+] UICitizenShopPanel2: %lx  \n", UICitizenShopPanel2);
                        if (UICitizenShopPanel2 != 0) {

                            char UIPanelName[500];
                            GetFNameStr(UIPanelName, (__uint64_t)(UICitizenShopPanel2 + 24)); //From UObject
                            GENERAL_PRINT("[+]UICitizenShopPanel2 UIPanelName = %s \n", UIPanelName);

                            CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UICitizenShopPanel2 + UISellItemCircularViewOffset), index, 0, 1);

                        }
                    }
                }
            }
        }

    }
    else if (StartCallFunction == 53) {
        CallResult = 0;

        ReadBagItem();
        if ((int)FakePara1 <= BagItemCount) {
            if (BagItem[FakePara1].IsUsed == 1)
            {
                __uint64_t TmpPtr = strtoull(FakeObject.c_str(), NULL, 16);
                DEBUG_PRINT("[+] TmpPtr: %llx  \n", TmpPtr);
                if (TmpPtr == (__uint64_t)BagItem[FakePara1].Pointer) {
                    struct FMemeryType TmpMem;
                    InitFMem(&TmpMem);
                    int index = GetSellBagItemFNameID(BagItem[FakePara1].InstanceId);

                    //TmpMem.A = FNameID;
                    if (index > -1) {

                        __int64_t UICitizenShopPanel2 = 0;
                        //UIInventoryPanel = GameUI_GetPanel(UIInventoryPanelID);
                        //UICitizenShopPanel2 = GameUI_GetPanel(59);
                        UICitizenShopPanel2 = GameUI_GetPanelByName(ShopPanel2Name);
                        DEBUG_PRINT("[+] UICitizenShopPanel2: %lx  \n", UICitizenShopPanel2);
                        if (UICitizenShopPanel2 != 0) {

                            char UIPanelName[500];
                            GetFNameStr(UIPanelName, (__uint64_t)(UICitizenShopPanel2 + 24)); //From UObject
                            GENERAL_PRINT("[+]UICitizenShopPanel2 UIPanelName = %s \n", UIPanelName);

                            CircularViewWrapper_ScrollToIndexIntoView(*(__int64_t*)(UICitizenShopPanel2 + UISellItemCircularViewOffset), index, 0, 1);
                            if (RealIndexReturn > -1) {
                                UICitizenShopPanel_OnClickBagSlotButtonERK5FName(UICitizenShopPanel2, (__int64_t)&TmpMem.A, RealIndexReturn);//UIInventoryPanel2::OnClickItemSlotButton
                            }
                          
                            CallResult = 1;
                        }
                    }

                }
            }
        }
    }
    else if (StartCallFunction == 50) {

        int DefaultYaw = (int)FakePara1;
        int DefaultPitch = (int)FakePara2;
        int DefaultDolly = (int)FakePara3;

        /*
        __uint64_t GameObject2_ClientConfig = (*GameObject2_ClientConfigPtr + 56);
        if (*GameObject2_ClientConfigPtr) {
            __uint64_t cameraConfig = *(__uint64_t*)(*(__uint64_t*)GameObject2_ClientConfig + 32i64);
            if (cameraConfig) {
                __uint64_t cameraConfig1 = *(__uint64_t*)cameraConfig;
                if (cameraConfig1) {
                    DefaultYaw = *(int*)(cameraConfig1 + 48);
                    DefaultPitch = *(int*)(cameraConfig1 + 52);
                    DefaultDolly = *(int*)(cameraConfig1 + 56);
                    GENERAL_PRINT("[+] DefaultYaw=%d", DefaultYaw);
                    GENERAL_PRINT("[+] DefaultPitch=%d", DefaultPitch);
                    GENERAL_PRINT("[+] DefaultDolly=%d", DefaultDolly);
                }
             //{"type":60,"x":132,"y":8,"z":700}
                
            }
        }
        */


         __uint64_t B2Client_instance = *LHGameInstanceAddr;
        if (B2Client_instance != 0) {
            __int64_t GameCamera = *(__int64_t*)(B2Client_instance + GameCameraOffset); //Game::CameraReset   _ZN4Game17SetAttackTargetIdEybb找下來
            if (GameCamera) {
                //GENERAL_PRINT("[+] GameCamera=%llx", GameCamera);
                (*(void(__fastcall**)(__int64, __int64, __int64, __int64))(*(__int64*)GameCamera + SetCameraOffset))(GameCamera, DefaultYaw, DefaultPitch, DefaultDolly);
            }
        }

        /*
        __uint64_t UEngine = *EnginePtr;
        if (UEngine != 0) {
            GENERAL_PRINT("[+] UEngine");
            __uint64_t UWorld = *UWolrldPtr;
            __uint64_t PreMgrPtr = AB2PlayerController_GetPrivateStaticClass();
            //__uint64_t PreMgrPtr = AB2HUD_GetPrivateStaticClass();
    
            if (PreMgrPtr) {
                __uint64_t PlayerController = GetManager(PreMgrPtr);
               // if (AB2HUD != 0) {
                  //  GENERAL_PRINT("[+] AB2HUD = %llx", AB2HUD);
                    //__uint64_t PlayerController = *(__uint64_t*)(AB2HUD + 70 * 8);


                    //__uint64_t PlayerController = UEngine_GetFirstLocalPlayerController(UEngine, UWorld);
                    if (PlayerController) {
                        GENERAL_PRINT("[+] AController_SetControlRotation= %f", *(float*)(PlayerController + 269 * 4));
                        // *(float*)(PlayerController + 269 * 4) = DestCoor.XCoor;

                        GENERAL_PRINT("[+] AController_SetControlRotation2");
                        AController_SetControlRotation(PlayerController, (__uint64_t)&DestCoor.XCoor);
                    }
               // }
            }
           
        }

        */
        
    }
    else if (StartCallFunction == 51)
    {
         DumpEffectData();
    }
    else if (StartCallFunction == 71) {
        GetBlackNoAttackList();

        StartCallFunction = 0;
    }
    else if (StartCallFunction == 72) {
        ResetBlackNoAttackList();

        StartCallFunction = 0;
    }
    else if (StartCallFunction == 86) {
        char UTF8Text[1000];
        char UTF16[1000];
        char* UTF16Text;
        struct FMemeryType TmpMem;
        InitFMem(&TmpMem);

        memset(UTF8Text, 0, 1000);
        memset(UTF16, 0, 1000);
        strcpy(UTF8Text, InviteMemberName.c_str());
        UTF16Text = UTF8ToUTF16(UTF8Text);

        int Strlen = utf8_strlen(InviteMemberName) + 1;

        DefaultAllocator_ResizeForCopy((__uint64_t)&TmpMem.A, Strlen, 0);
        memcpy((void*)TmpMem.A, UTF16Text, Strlen * 2);

        GENERAL_PRINT("[+] TmpMem.A=%lx", TmpMem.A);
        GENERAL_PRINT("[+] TmpMem.B=%lx", TmpMem.B);
        GENERAL_PRINT("[+] TmpMem.C=%lx", TmpMem.C);

        // TmpMem.A = (__uint64_t)UTF16Text;
        TmpMem.B = (__uint64_t)(Strlen);//
        TmpMem.C = (__uint64_t)(Strlen * 2);

        GENERAL_PRINT("[+] FScreenshotRequest_RequestScreenshot");
        //UGameViewportClient_RequestBugScreenShot(GameViewportClient, (__uint64_t)UTF16Text,1);

        FScreenshotRequest_RequestScreenshot((__uint64_t)&TmpMem.A, 1, 0);


    }
    else if (StartCallFunction == 88) { //GET ALL UI
        DEBUG_PRINT("[+] ReadAllUI!!!!!!!!!!!!!");
        ReadAllUI();
        StartCallFunction = 0;
     }
    else if (StartCallFunction == 89) {
        GetChildUIList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 0);
        StartCallFunction = 0;
     }
    else if (StartCallFunction == 90) {
        DEBUG_PRINT("[+]StartCallFunction 90");

        if (GlobalTmpVal == 0) {
            DEBUG_PRINT("[+]GetChild panel list");
            GetChildUIPanelList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 1);
        }
        else {
            DEBUG_PRINT("[+]GetChild ui list");
            GetChildUIList(GlobalTmpVal, buf, sizeof(buf), Largebuf, sizeof(Largebuf), Resultbuf, sizeof(Resultbuf), 1);
        }    
        DEBUG_PRINT("[+]GetChildUIList Finish3");
        DEBUG_PRINT("[+]Largebuf strlen=%d" , strlen(Largebuf));
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 91) {
        GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 0);
        StartCallFunction = 0;
      }
    else if (StartCallFunction == 92) {
        GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 1);
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 93) {
        GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 0);
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 95) {
        GetUIElementByTree(GlobalResult, Resultbuf, sizeof(Resultbuf), 0);
        StartCallFunction = 0;
    }
    else if (StartCallFunction == 301) {
        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            My_SendMessagew(_hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(RecordCursorX, RecordCursorY));
        }
    }
    else if (StartCallFunction == 302) {
        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            My_SendMessagew(_hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(RecordCursorX, RecordCursorY));
            IsFixCursorPos = 0;
        }
    }
    else if (StartCallFunction == 303) {
        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            My_SendMessagew(_hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(RecordCursorX, RecordCursorY));
            Sleep(50);
            My_SendMessagew(_hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(RecordCursorX, RecordCursorY));
            IsFixCursorPos = 0;
        }
    }
    else if (StartCallFunction == 304) {

        Set_g_bkpint(RecordCursorX, RecordCursorY);
        IsFixCursorPos = 1;

        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            My_SendMessagew(_hwnd, WM_MOUSEMOVE, 0, MAKELPARAM(RecordCursorX, RecordCursorY)); //覃蚚涴跺疑砉羶伅虴彆
        }

        Set_g_bkpint(RecordCursorX, RecordCursorY);
        //IsFixCursorPos = 0;

    }
    else if (StartCallFunction == 305) {
        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            DWORD lparam = 1u;
            if ((int)FakePara1 == VK_RCONTROL)
                lparam |= 1u << 24;
            lparam |= oem_code((int)FakePara1) << 16;
            My_SendMessagew(_hwnd, WM_KEYDOWN, (int)FakePara1, lparam);
        }
    }
    else if (StartCallFunction == 306) {
        HWND _hwnd = GetProcessMainWindow();
        if (_hwnd != 0) {
            DWORD lparam = 1u;
            if ((int)FakePara1 == VK_RCONTROL)lparam |= 1u << 24;
            lparam |= oem_code((int)FakePara1) << 16;
            lparam |= 1u << 30;
            lparam |= 1u << 31;
            My_SendMessagew(_hwnd, WM_KEYUP, (int)FakePara1, lparam);
        }
    }


    StartCallFunction = 0;

}






void AutoRunToPos(__uint64_t MapID, float X, float Y, float Z) //AutoPlay2::worldPickMove
{
    DEBUG_PRINT("[+] AutoRunToPosByNoTeleport: MapID =%d  \n", MapID);



    struct CoorType TmpPoint;
    struct CoorType TmpPoint2;
    TmpPoint.XCoor = X;
    TmpPoint.YCoor = Y;
    TmpPoint.ZCoor = Z;

    struct FMemeryType TmpMem;
    InitFMem(&TmpMem);

    struct FMemeryType TmpMem2;
    InitFMem(&TmpMem2);

    __uint64_t v16 = 0;

    // TmpMem.C = TmpMem2.A;
     //int i = TryFunction(TmpMem2.A, TmpMem2.B, TmpMem2.C);

    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        // fake_Game_AutoPlayMapMove(GameInstance, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 100.0);
        std::string TmpText = "UI.HUD.Text.AutoTravelToComplete";
        char TmpMemA[1000];
        memset(TmpMemA, '\0', 1000);

        strcpy(TmpMemA, TmpText.c_str());

        //Game_AutoPlayMapMove(GameInstance, (int)MapID, (__uint64_t)&TmpPoint.XCoor,  100.0, (__uint64_t)TmpMemA, 1);


        GENERAL_PRINT("[+] Game_checkAvailableAutoMoveWhatHyperRun:  \n");
        if (Game_checkAvailableAutoMoveWhatHyperRun(GameInstance) == 1) {
            __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);

            if (PlayerHero != 0) {
                __uint64_t PlayerHeroDisplay = PlayerHero__GetPlayerHeroDisplay(PlayerHero);
                if (PlayerHeroDisplay != 0) {
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopMoveOnPath:  \n");
                   // PlayerHeroDisplay_StopMoveOnPath(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopDestGimmick:  \n");
                   // PlayerHeroDisplay_StopDestGimmick(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] AgentDisplay_ClearActionTimer:  \n");
                   // AgentDisplay_ClearActionTimer(PlayerHeroDisplay);

                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                    GENERAL_PRINT("[+] AutoPlay2_Finish:  \n");
                    // fake_AutoPlay2_Finish(AutoPlay2);

                    if (AutoPlay2 != 0) {
                        char v16 = 0;
                        


                        // GENERAL_PRINT("[+] AutoPlay2_setCommonParam:  \n");
                        // AutoPlay2_setCommonParam(AutoPlay2, (__uint64_t)TmpMemA, 1);

                        GENERAL_PRINT("[+] IsDungeon:  \n");
                        char IsDungeon = *(char*)(AutoPlay2 + IsDungeonOffset);
                        GENERAL_PRINT("[+] IsDungeon = %d  \n", IsDungeon);
                        if (IsDungeon == 0) {
                            GENERAL_PRINT("[+] AutoPlay2_setMoveParam:  \n");
                            AutoPlay2_setMoveParam(AutoPlay2, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 0.0);
                        }
                        else {
                            GENERAL_PRINT("[+] AutoPlay2_setMoveParamDungeon:  \n");
                            AutoPlay2_setMoveParamDungeon(AutoPlay2, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 0.0);
                        }
                        GENERAL_PRINT("[+] AutoMovePath_FindPath:  \n");


                        // if (!v16)
                   // {
                        v16 = *((char*)AutoPlay2 + 9);
                        if (v16 == 2)
                        {
                            if (*((char*)AutoPlay2 + 8) == 2) {
                                AutoPlay2_Finish(AutoPlay2);
                                //fake_AutoPlay2_Finish(AutoPlay2);
                            }
                            v16 = *((char*)AutoPlay2 + 9);
                        }

                        if (v16 == 0) { //AutoPlay2::worldPickMove
                            *(char*)(AutoPlay2 + 9) = 1;

                            if (*((char*)AutoPlay2 + 8) == 0) {
                                *((char*)AutoPlay2 + 8) = 2;
                            }
                            if (*((char*)AutoPlay2 + 8) != 0) {
                                //fake_AutoPlay2_changePlayState(AutoPlay2, 10,1);
                                AutoPlay2_changePlayState(AutoPlay2, 10, 1);
                            }
                        }

                       
                       

        

                        GENERAL_PRINT("[+] AutoMovePath_FindPath:1  \n");
                        if (AutoMovePath_FindPath(AutoPlay2 + AutoMovePathOffset, (__uint64_t)&TmpPoint.XCoor, 1)) {
                            GENERAL_PRINT("[+] AutoMovePath_FindPath Success 1  \n");


                            int TmpMapID = GetCurrentMap();
                            DEBUG_PRINT("[+]GetMyPos2 \n");
                            CoorType TmpCoor2 = GetCurrentCoor();
                            MyMapID = TmpMapID;
                            MyXCoor = TmpCoor2.XCoor;
                            MyYCoor = TmpCoor2.YCoor;
                            MyZCoor = TmpCoor2.ZCoor;

                            int IsRun = 0;
                            if (MyMapID == MapID) {
                                float Distance = sqrtf((abs(MyXCoor - X) * abs(MyXCoor - X)) + (abs(MyYCoor - Y) * abs(MyYCoor - Y)) + (abs(MyZCoor - Z) * abs(MyZCoor - Z)));
                                if (Distance > 700) {
                                    IsRun = 1;
                                }
                            }
                            else {
                                IsRun = 1;
                            }

                            if (IsRun == 1) {

                                IsNeedHyperRun = 1;
                                
                            }






                            // }

                            GENERAL_PRINT("[+] fake_AutoPlay2_changePlayState:1  \n");
                            // fake_AutoPlay2_changePlayState(AutoPlay2, 1,1);



                            GENERAL_PRINT("[+] UpdateAutoBattleUIAndMessage:1  \n");
                            //   UpdateAutoBattleUIAndMessage();


                        }
                        else {
                            GENERAL_PRINT("[+] AutoMovePath_FindPath Fail  \n");
                            //  fake_AutoPlay2_Finish(AutoPlay2);
                        }
                        GENERAL_PRINT("[+] fake_AutoPlay2_Finish  \n");
                    }

                }

            }
        }




    }

}


int TryFunction(__uint64_t a, __uint64_t b, __uint64_t c) //_ZN11UxSingletonI12FNkAiManagerE11ms_instanceE
{
    a = a + 1;
    b = b + 1;
    c = c + 1;
    a = a - 1;
    b = b - 1;
    c = c - 1;

    return a;
}

void SetAuto( char State) //_ZN11UxSingletonI12FNkAiManagerE11ms_instanceE
{


    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
        if (AutoPlay2 != 0) {
            if (State == 0) {
                GENERAL_PRINT("[+] SetAuto 1  \n");
                *(unsigned __int8*)(AutoPlay2 + Game_IsAutoPlay_Offset2) = 0;
                *(unsigned __int8*)(AutoPlay2 + 8) = 0;

                //fake_AutoPlay2_changePlayState(AutoPlay2, 0,0);
                AutoPlay2_changePlayState(AutoPlay2, 0, 0);

                /*
                    if (Game_IsAutoPlay(GameInstance) == 1) {
                        AutoPlay2_Finish(AutoPlay2);
                    }
                */
                GENERAL_PRINT("[+] SetAuto 2 \n");
               // AutoPlay_Combat(AutoPlay2, AutoPlay2 + 24, 0);
            }
            else {

                AutoPlay_Combat(AutoPlay2, AutoPlay2 + 24, 1); //AutoPlay2::EndQuest(__int64 result, int a2, char a3)
            }
   
        }
    }

}

void SetStopMove() //_ZN11UxSingletonI12FNkAiManagerE11ms_instanceE
{
    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
        __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);

        if (PlayerHero != 0) {
            __uint64_t PlayerHeroDisplay = PlayerHero__GetPlayerHeroDisplay(PlayerHero);


            if (PlayerHeroDisplay != 0) {

                __uint64_t ICharacter = *(__uint64_t*)(PlayerHeroDisplay + ICharacterOffset); //layerHeroDisplay::IsMoving(PlayerHeroDisplay *this)
                DEBUG_PRINT("[+] ICharacter:%llx--end--", ICharacter);
                if (ICharacter != 0 && ICharacter != -1) {
                    IsMoving = (int)ICharacter_HasMoveCommand(ICharacter);
                }

                if (IsMoving) {
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopMoveOnPath:  \n");
                    PlayerHeroDisplay_StopMoveOnPath(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopDestGimmick:  \n");
                    PlayerHeroDisplay_StopDestGimmick(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] AgentDisplay_ClearActionTimer:  \n");
                    AgentDisplay_ClearActionTimer(PlayerHeroDisplay);


                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                    GENERAL_PRINT("[+] AutoPlay2_Finish:  \n");
                    char v16 = 0;
                    if (*(char*)(AutoPlay2 + 9) == 2)
                    {
                        if (*((char*)AutoPlay2 + 8) == 2) {
                            //fake_AutoPlay2_Finish(AutoPlay2);
                            AutoPlay2_Finish(AutoPlay2);
                        }
                        v16 = *((char*)AutoPlay2 + 9);
                    }
                }
                
            }
            

        }
    }

}


__uint64_t GetHyperRunController()
{


    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t HyperRunControllerPtr = 0;
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t PlayerHeroPtr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (PlayerHeroPtr != 0) {
            HyperRunControllerPtr = *(__uint64_t*)(PlayerHeroPtr + HyperRunController_Offset);
        }

        return HyperRunControllerPtr;
    }
}


void AutoRunToPosByNoTeleport(__uint64_t MapID,  float X, float Y, float Z) //_ZN11UxSingletonI12FNkAiManagerE11ms_instanceE
{

    DEBUG_PRINT("[+] AutoRunToPosByNoTeleport: MapID =%d  \n",MapID);



    struct CoorType TmpPoint;
    struct CoorType TmpPoint2;
    TmpPoint.XCoor = X;
    TmpPoint.YCoor = Y;
    TmpPoint.ZCoor = Z;

    struct FMemeryType TmpMem;
    InitFMem(&TmpMem);

    struct FMemeryType TmpMem2;
    InitFMem(&TmpMem2);

    __uint64_t v16 = 0;

   // TmpMem.C = TmpMem2.A;
    //int i = TryFunction(TmpMem2.A, TmpMem2.B, TmpMem2.C);

    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {
       // fake_Game_AutoPlayMapMove(GameInstance, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 100.0);
        std::string TmpText = "UI.HUD.Text.AutoTravelToComplete";
        char TmpMemA[1000];
        memset(TmpMemA, '\0', 1000);

        strcpy(TmpMemA, TmpText.c_str());

        //Game_AutoPlayMapMove(GameInstance, (int)MapID, (__uint64_t)&TmpPoint.XCoor,  100.0, (__uint64_t)TmpMemA, 1);


        GENERAL_PRINT("[+] Game_checkAvailableAutoMoveWhatHyperRun:  \n");
        if (Game_checkAvailableAutoMoveWhatHyperRun(GameInstance) == 1) {
            __uint64_t PlayerHero = *(__uint64_t*)(GameInstance + AgentOffset); //result = PlayerHero::GetPlayerHeroDisplay(*(_QWORD *)(v6 + 104), &v42);

            if (PlayerHero != 0) {
                __uint64_t PlayerHeroDisplay = PlayerHero__GetPlayerHeroDisplay(PlayerHero);
                if (PlayerHeroDisplay != 0) {
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopMoveOnPath:  \n");
                    PlayerHeroDisplay_StopMoveOnPath(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] PlayerHeroDisplay_StopDestGimmick:  \n");
                    PlayerHeroDisplay_StopDestGimmick(PlayerHeroDisplay);
                    GENERAL_PRINT("[+] AgentDisplay_ClearActionTimer:  \n");
                    AgentDisplay_ClearActionTimer(PlayerHeroDisplay);

                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                    GENERAL_PRINT("[+] AutoPlay2_Finish:  \n");
                    // fake_AutoPlay2_Finish(AutoPlay2);

                    if (AutoPlay2 != 0) {
                        char v16 = 0;
                        if (*(char*)(AutoPlay2 + 9) == 2)
                        {
                            if (*((char*)AutoPlay2 + 8) == 2) {
                                //fake_AutoPlay2_Finish(AutoPlay2);
                                AutoPlay2_Finish(AutoPlay2);
                            }
                            v16 = *((char*)AutoPlay2 + 9);
                        }
                        // GENERAL_PRINT("[+] AutoPlay2_setCommonParam:  \n");


                       

                        // AutoPlay2_setCommonParam(AutoPlay2, (__uint64_t)TmpMemA, 1);

                        GENERAL_PRINT("[+] IsDungeon:  \n");
                        char IsDungeon = *(char*)(AutoPlay2 + IsDungeonOffset);
                        GENERAL_PRINT("[+] IsDungeon = %d  \n", IsDungeon);
                        if (IsDungeon == 0) {
                            GENERAL_PRINT("[+] AutoPlay2_setMoveParam:  \n");
                            AutoPlay2_setMoveParam(AutoPlay2, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 100.0);
                        }
                        else {
                            GENERAL_PRINT("[+] AutoPlay2_setMoveParamDungeon:  \n");
                            AutoPlay2_setMoveParamDungeon(AutoPlay2, (int)MapID, (__uint64_t)&TmpPoint.XCoor, 100.0);
                        }
                        GENERAL_PRINT("[+] AutoMovePath_FindPath:  \n");




                        // if (!v16)
                   // {
                        *(char*)(AutoPlay2 + 9) = 1;
                        if (*((char*)AutoPlay2 + 8) != 2) {
                            *((char*)AutoPlay2 + 8) = 2;
                        }


  



                   


                        GENERAL_PRINT("[+] AutoMovePath_FindPath:1  \n");
                        if (AutoMovePath_FindPath(AutoPlay2 + AutoMovePathOffset, (__uint64_t)&TmpPoint.XCoor, 1)) {
                            GENERAL_PRINT("[+] AutoMovePath_FindPath Success 1  \n");


                            int TmpMapID = GetCurrentMap();
                            DEBUG_PRINT("[+]GetMyPos2 \n");
                            CoorType TmpCoor2 = GetCurrentCoor();
                            MyMapID = TmpMapID;
                            MyXCoor = TmpCoor2.XCoor;
                            MyYCoor = TmpCoor2.YCoor;
                            MyZCoor = TmpCoor2.ZCoor;

                            int IsRun = 0;
                            if (MyMapID == MapID) {
                                float Distance = sqrtf((abs(MyXCoor - X) * abs(MyXCoor - X)) + (abs(MyYCoor - Y) * abs(MyYCoor - Y)) + (abs(MyZCoor - Z) * abs(MyZCoor - Z)));
                                if (Distance > 700) {
                                    IsRun = 1;
                                }
                            }
                            else {
                                IsRun = 1;
                            }

                            if (IsRun == 1) {
                                IsNeedHyperRun = 1;

                               
                            }
                           



                           

                            // }

                            GENERAL_PRINT("[+] fake_AutoPlay2_changePlayState:1  \n");
                            // fake_AutoPlay2_changePlayState(AutoPlay2, 1,1);


       


                            GENERAL_PRINT("[+] UpdateAutoBattleUIAndMessage:1  \n");
                            //   UpdateAutoBattleUIAndMessage();




                        }
                        else {
                            GENERAL_PRINT("[+] AutoMovePath_FindPath Fail  \n");
                          //  fake_AutoPlay2_Finish(AutoPlay2);
                        }
                        GENERAL_PRINT("[+] fake_AutoPlay2_Finish  \n");
                    }
                    
                }

            }
        }

        


    }


}




int mmemcmp(const void* ptr1, const void* ptr2, size_t num){
int result = 0;

    //result = old_memcmp(ptr1, ptr2, num);

   // DEBUG_PRINT("[+] mmemcmp = %d  \n", MainThreadTid);
    if (MainThreadTid != 0 && MainThreadTid == (unsigned int)GetCurrentThreadId() && IsDoingmemcmp == 0) { //
        IsDoingmemcmp = 1;

       // DEBUG_PRINT("[+] memcmp = 1  \n");

        //GENERAL_PRINT("[+] MainThreadTid = %ld \n",MainThreadTid) ; 
        /*
        if (EverClosedHook == 0) {
            if (MH_DisableHook(&_ZN18ALHGameMode_InGame12DisplayCountEv) != MH_OK)
            {
                DEBUG_PRINT("[+]Close Hook\n");
            }
            EverClosedHook = 1;
        }
        */
    
        if (NeedGetUI == 1) {
            
            GettingUI = 1;
            //DEBUG_PRINT("[+] NeedGetUI = 1  \n");


            time_t timestamp_sec;
            __uint64_t CurrentTime = time(&timestamp_sec);
            LastHelperThreadTime = CurrentTime;

            int i = 0;
            int IsPanelVisible = 0;
            __uint64_t UIMangerPtr = 0;
            __uint64_t UIPanelAddr = 0;
            int Count = 0;
            char UIPanelName[500];
            char UObjectTypeName[500];

            
  
            if (StartCallFunction != 0) // && StartCallFunction != 1 && StartCallFunction != 2
            {

                GettingUI = 0;

                if (IsCallingFun == 0) {
                    IsCallingFun = 1;
                    FakeCallGameFunction();
                    IsCallingFun = 0;
                }

                //      GENERAL_PRINT("[+] StartCallFunction::     \n") ;
            }
 
         
            LastCallingFunTime = time(&Globaltimestamp_sec);
            IsCallingFunStarted = 1;

            GettingUI = 0;
            NeedGetUI = 0;
        }
     
        IsDoingmemcmp = 0;
    }


    return result;
}


int UIThread(int N)
{
    usleep(5000 * 1000);

    while (!end_Healing) {
        DEBUG_PRINT("[+]IsGameHooked = %d \n", IsGameHooked);
        if (IsGameHooked == 1) {

            for (int i = 0; i < 100; i++)
            {
                g_hMainWnd = GetProcessMainWindow();
                DEBUG_PRINT("[+] g_hMainWnd = %d  \n", g_hMainWnd); //)
                if (g_hMainWnd != 0) {
                    usleep(4000 * 1000);
                    g_hMainWnd = GetProcessMainWindow();
                    DEBUG_PRINT("[+] g_hMainWnd = %d  \n", g_hMainWnd); //)
                    if (g_hMainWnd != 0) {
                        break;
                    }

                    //break;
                }
                usleep(1000 * 1000);
            }
            

            g_dwMainThreadId = GetWindowThreadProcessId(g_hMainWnd, NULL);
            MainThreadTid = g_dwMainThreadId;
            DEBUG_PRINT("[+] g_dwMainThreadId = %d  \n", g_dwMainThreadId); //)


            /*
            MSG msg;
            while (GetMessage(&msg, NULL, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            */
            break;
        }
        usleep(1000 * 1000);
    }

    if (IsGameHooked == 1) {
        usleep(3000 * 1000);
        hookall();

        //  hookWindowProc();
         // hookHandle = SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)WndProcHook, NULL, g_dwMainThreadId);
        //  GENERAL_PRINT("[+] hookHandle = %d  \n", hookHandle); //)
       // GENERAL_PRINT("[+] hookall  \n"); //)

    }

    int TmpCount = 0;
    while (!end_Healing) {

        time_t timestamp_sec;
        __uint64_t CurrentTime;
        CurrentTime = time(&timestamp_sec);
        if ((StartCallFunction != 0 && NeedGetUI == 0) || CurrentTime - LastCallingFunTime > 2) { // || 

            if (IsGameHooked == 1) {
              
                NeedGetUI = 1;
                
               // g_hMainWnd = GetProcessMainWindow();
               // SendMessage(g_hMainWnd, WM_USER + 0x901, (DWORD)100, (DWORD)200);
               // GENERAL_PRINT("[+]SendMessage NeedGetUI \n");


                for (int i = 0; i < 3000; i++)
                {
                    if (NeedGetUI == 0) {
                        break;
                    }
                    else {
                        usleep(1000);
                    }
                }
                  
            }
            /*
            */
        }

        if (IsGameHooked == 1) {
            if (DontAttackSwitch == 1 || ReactDontAttackSwitch == 1 || PriorityAttackSwitch == 1) {
                //if (TmpCount > 10) { //CurrentTime - LastCallingFunTime2 > 0 &&
                NeedHelperSelect = 1;

                TmpCount = 0;
                LastCallingFunTime2 = CurrentTime;
                // }
                TmpCount = TmpCount + 1;
            }
        }

        usleep(5 * 1000);
    }
    return NULL;
}


int IsUUserWidget(__uint64_t a) {
    __uint64_t v40 = 0, v41 = 0, v42 = 0, v37 = 0;
    int IsUserWidget = 0;

    v40 = UserWidget_GetPrivateStaticClass(); // ULMTargetingSystem::GetTargetDetail
    v41 = *((__uint64_t*)a + 2);
    v42 = *(signed int*)(v40 + 64);
    IsUserWidget = 1;
    if ((signed int)v42 > *(signed int*)(v41 + 64) || *(__uint64_t*)(*(__uint64_t*)(v41 + 56) + 8 * v42) != v40 + 56) {
        IsUserWidget = 0;
    }
    return IsUserWidget;

}





Json::Value DumpAllUI(Json::Value Root) {

    __uint64_t UIMangerPtr = GetUIManager();    // UIPanelAddr = GetUIPanel(UIMangerPtr,i);
    int Count = 0,i  = 0;
    __uint64_t  UIPanelAddr = 0, IsPanelVisible = 0;
    char UIPanelName[500];
    char UIPanelName2[500];
    __uint64_t ResultPtr = 0, ChildElement = 0;
    char ObjAddress[50];
    std::string ObjStr = "";

    DEBUG_PRINT("[+]GameUI =%d  \n", UIMangerPtr);
    if (UIMangerPtr != 0) {
        if (IsBotEnded == 0) {
            WaitGetUIDone();
        }

         Count = GetUIPanelList(UIMangerPtr);

        DEBUG_PRINT("[+]Count =%d  \n", Count);

        if (Count > 0) {
            for (i = 0; i < Count; i++)
            {

                if (EverClosedHook == 0) {
                    if (UiElement[i].IsUsed == 1) {
                        UIPanelAddr = UiElement[i].Pointer;
                    }
                }
                else {
                    if (UiPanel[i].IsUsed == 1) {
                        UIPanelAddr = UiPanel[i].Pointer;
                    }
                }

                DEBUG_PRINT("[+]FoundUIByTree  1  = \n");

                if (EverClosedHook == 0 || UiPanel[i].Show > 0) {//
                // UIPanelAddr = GetUIPanel(UIMangerPtr,i);   

                    if (UIPanelAddr) {

                        IsPanelVisible = 0; //
                        if (IsUUserWidget(UIPanelAddr)) {
                            IsPanelVisible = UUserWidget_GetIsVisible(UIPanelAddr); //
                            if (IsPanelVisible == 1) {
                                ChildElement = UTSWidgetPanel_GetWidgetTree(UIPanelAddr);
                                if (UWidget_IsVisible(ChildElement) == 0) {
                                    IsPanelVisible = 0;
                                }
                            }
                            
                        }
                      //  DEBUG_PRINT("[+]IsPanelVisible = %ld \n", IsPanelVisible);
                        struct FMemeryType TmpMem;
                        InitFMem(&TmpMem);
                        char UObjectPathName[1000];
                        char UObjectTypeName[500];
                        if (IsPanelVisible != 0 ) {

                            GetFNameStr(UIPanelName, (__uint64_t)(UIPanelAddr + 24)); //From UObject
                           // DEBUG_PRINT("[+]UIPanelName = %s \n",  UIPanelName);
                            GetFNameStr(UObjectTypeName, (__uint64_t)(*(__uint64_t*)(UIPanelAddr + 16) + 24));
                         //   DEBUG_PRINT("[+]UObjectTypeName = %s \n", UObjectTypeName);

                           // DEBUG_PRINT("[+]UObjectPathName1");
                           // GetUObjectFullPathName(UIPanelAddr, (__uint64_t)&TmpMem.A, 0, 0);
                          //  DEBUG_PRINT("[+]UObjectPathName2");
                            //strcpy(UObjectPathName, UTF16ToUTF8((char*)TmpMem.A));
                           // DEBUG_PRINT("[+]UObjectPathName = %s \n", UObjectPathName);

                            //DEBUG_PRINT("[+]Found  UIPanel \n");

                            ResultPtr = 0;
                          //  DEBUG_PRINT("[+]IsUUserWidget = %d \n", IsUUserWidget(UIPanelAddr));
                           // if (IsUUserWidget(UIPanelAddr) == 1) //找到 UIPanel
                           // {
                               // DEBUG_PRINT("[+]IsUUserWidget = 1 \n");

                                ResultPtr = UTSWidgetPanel_GetWidgetTree(UIPanelAddr);
                                DEBUG_PRINT("[+]UIPanelName   = %s \n", UIPanelName);



                              //  GetFNameStr(UIPanelName2, (__uint64_t)(ResultPtr + 24)); //From UObject
                               // DEBUG_PRINT("[+]UIPanelName2    =  %s \n", UIPanelName2);





                              //  DEBUG_PRINT("[+]ResultPtr = %lx \n", ResultPtr);
                                std::string NowUIPanelName = UIPanelName;
                                std::string NowUObjectTypeName = UObjectTypeName;

                                Json::Value TmpChild;
                                memset(ObjAddress, 0, 50);
                                snprintf(ObjAddress, 50, "%llx", UIPanelAddr);
                                ObjStr = ObjAddress;

                                TmpChild["obj"] = ObjStr;
                                TmpChild["IsRunn"] = 1;
                                TmpChild["link"] = NowUIPanelName;
                                TmpChild["clsname"] = NowUObjectTypeName;
                                TmpChild["name"] = NowUIPanelName;
         
                                struct UISizeCoorType UISizeCoor = GetUISizeCoorInfo(UIPanelAddr);
                                TmpChild["w"] = UISizeCoor.width;
                                TmpChild["h"] = UISizeCoor.height;
                                TmpChild["x"] = UISizeCoor.X;
                                TmpChild["y"] = UISizeCoor.Y;

                                if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
                                    TmpChild["IsRunn"] = 0;
                                }
                                else {
                                    TmpChild = DumpChildElementByName(TmpChild, ResultPtr,1);
                                }

                                Root["obj"] = "0";
                                Root["IsRunn"] = 1;
                                Root["IsEn"] = 1;
                                Root["link"] = "";
                                Root["son"].append(TmpChild);
                            //}
                        }
                    }
                }

                DEBUG_PRINT("[+]FoundUIByTree  2  = \n");
            }
        }

    }
    return Root;
}

bool  UWorld_IsGameWorld(__int64 a1)
{
    unsigned __int8 v1; // al
    signed long v2; // ecx
    bool result; // al

    v1 = *(unsigned __int8*)(a1 + 322) -1;
    result = 0;
    if (v1 > 5) {
        result = 0LL;
    }
    else {
        result = (0x35u >> v1) & 1;
    }
       
    return result;
}

__int64 UEngine_GetWorldContextFromWorld(__int64 a1, __int64 a2) //UWorld::GetGameViewport   電腦版+8
{
    __int64 v2; // rax
    signed __int64 v3; // rcx

    v2 = *(__uint64_t*)(a1 + 3216);
    v3 = v2 + 8 * *(signed int*)(a1 + 3224);
    if (v2 == v3)
        return 0i64;
    while (*(__uint64_t*)(*(__uint64_t*)v2 + 648) != a2)
    {
        v2 += 8;
        if (v2 == v3)
            return 0;
    }
    __uint64_t result = *(__uint64_t*)v2;

    return result;
}
__int64 UWorld__GetGameViewport(__int64 UEngine,__int64 a1)
{
    __int64 result; // rax

    result = UEngine_GetWorldContextFromWorld(UEngine, a1);
    if (result)
        result = *(__int64*)(result + 544);
    return result;
}


struct CoorType GetUIXY(__uint64_t TmpUObject) {
    struct CoorType PixelCoor;
    struct FGeometry ScreenGeo2;
    struct CoorType ViewPortCoor;
    struct FGeometry ScreenGeo3;

    struct FGeometry* TmpGeo;
    struct FGeometry ScreenGeo;

    struct FGeometry InGeo;

    struct FGeometry CachedGeo;

    struct CoorType ResultCoor;
    float interX = 0, interY = 0;

    __uint64_t UEngine = *EnginePtr;
    if (UEngine != 0) {
        // if (ScreenX == 0 || ScreenY == 0) {
        __uint64_t UWorld = UEngine_GetWorldFromContextObject(UEngine, TmpUObject, 1);
        if (UWorld != 0) {
            if (UWorld_IsGameWorld(UWorld)) {
               // DEBUG_PRINT("[+]GetUIXY\n");
                __uint64_t GameViewportClient = UWorld__GetGameViewport(UEngine, UWorld);
                if (GameViewportClient != 0) {
                    old_GameViewportClient_GetViewportSize(GameViewportClient, (__uint64_t)&ScreenGeo.width);
                    ScreenX = ScreenGeo.width;
                    ScreenY = ScreenGeo.height;

                    struct GMemeryType TmpMem;
                    InitGMem(&TmpMem);
                    char buff[200];
                    memset(buff, 0, 200);
                    __int64_t v10 = *(__int64_t*)(GameViewportClient + 256);

                    if (v10 != 0) {
                        __int64 Retrun = (*(__int64(__fastcall**)(__int64, float*))(*(__int64*)v10 + 8i64))(v10, (float*)buff);

                        TmpGeo = (struct FGeometry*)UWidget_GetCachedGeometry(TmpUObject);

                        if (TmpGeo != 0) {
                            float v8 = TmpGeo->a11;
                            float v7 = TmpGeo->a12;

                            float v17 = *(float*)((__int64_t)buff + 36);
                            float v18 = *(float*)((__int64_t)buff + 40);
                            float v19 = *(float*)((__int64_t)buff + 28);
                            float v20 = *(float*)((__int64_t)buff + 32);

                            float v21 = *(float*)((__int64_t)buff + 44);
                            float v22 = *(float*)((__int64_t)buff + 48);
                            float  v23 = 1.0 / (float)((float)(v19 * v18) - (float)(v20 * v17));
                            float v24 = (float)((float)(v8 * (float)(v18 * v23)) - (float)(v7 * (float)(v17 * v23)))
                                + (float)((float)(v22 * (float)(v17 * v23)) - (float)(v21 * (float)(v18 * v23)));

                            // float v24 = (float)((float)(v8 * (float)(v18 * v23)) + (float)(v7 * (float)(v17 * v23))) + (float)((float)(v22 * (float)(v18 * v23)));


                            float v25 = (float)((float)(v21 * (float)(v20 * v23)) - (float)(v22 * (float)(v19 * v23)))
                                + (float)((float)(v7 * (float)(v19 * v23)) - (float)(v8 * (float)(v20 * v23)));

                            float v26 = (float)(v25 / *(float*)((__int64_t)buff + 4)) * ScreenY;

                            float inter = (float)(v24 / *(float*)(__int64_t)buff);
                            //   DEBUG_PRINT("[+] X = %f  Y = %f\n", inter);

                            interX = ScreenGeo.width * inter;
                            interY = v26;
                        }
                        
                    }


                    //   DEBUG_PRINT("[+] v17 = %f  v18 = %f v19 = %f v20 = %f  v21 = %f  v22 = %f v23 = %f\n", v17, v18, v19, v20, v21, v22, v23);
                    //   DEBUG_PRINT("[+] v24 = %f  v25 = %f  v26 = %f   *(float*)((__int64_t)buff ) = %f     *(float*)((__int64_t)buff + 4) = %f  v21 = %f  v22 = %f\n", v24, v25, v26, *(float*)((__int64_t)buff), *(float*)((__int64_t)buff + 4), v21, v22);

                     //  DEBUG_PRINT("[+] X = %f  Y = %f\n", interX, interY);

                     //  DEBUG_PRINT("[+] ScreenX = %f  ScreenY = %f\n", ScreenGeo.width, ScreenGeo.height);
                }
            }
        }
        
    }
    ResultCoor.XCoor = interX;
    ResultCoor.YCoor = interY;
    return ResultCoor;
}

struct UISizeCoorType GetUISizeCoorInfo(__uint64_t TmpUObject) {
    struct UISizeCoorType Result;
    int width = 0, height = 0;
    int X = 0, Y = 0;
    float interX = 0, interY = 0;
    struct CoorType PixelCoor;
    struct FGeometry ScreenGeo2;
    struct CoorType ViewPortCoor;
    struct FGeometry ScreenGeo3;

    struct FGeometry* TmpGeo;
    struct FGeometry ScreenGeo;

    struct FGeometry InGeo;

    struct FGeometry CachedGeo;
    // DEBUG_PRINT("[+] GetUIElementByTree 5\n");
    TmpGeo = (struct FGeometry*)UWidget_GetCachedGeometry(TmpUObject);

    if ((__uint64_t)TmpGeo != 0)
    {
       // DEBUG_PRINT("[+] GetUIElementByTree 6\n");

        //if (ScreenX == 0 && ScreenY == 0) { //UNkUiManager::Init(UNkUiManager *this)

       
       
        /*
        InGeo.width = 0.0;
        InGeo.height = 0.0;
        InGeo.X = 0;
        InGeo.Y = 0;
        PixelCoor.XCoor = 0.0;
        PixelCoor.YCoor = 0.0;
        ViewPortCoor.XCoor = 0.0;
        ViewPortCoor.YCoor = 0.0;
       */
       // TmpGeo = (struct FGeometry*)UWidget_GetCachedGeometry(TmpUObject);

      //  memcpy((char*)&CachedGeo.width, (char*)TmpGeo,4*13);
      //  USlateBlueprintLibrary_LocalToViewport(TmpUObject, (__uint64_t)&CachedGeo.width, (__uint64_t)&InGeo.width, (__uint64_t)&PixelCoor.XCoor, (__uint64_t)&ViewPortCoor.XCoor);

        PixelCoor = GetUIXY(TmpUObject);
       // DEBUG_PRINT("[+]PixelCoor\n");
        if (ScreenX > 0 && ScreenY > 0) {
            X = (int)PixelCoor.XCoor;//TmpGeo->X; // / TmpGeo->scale ;//; //interX; //
            Y = (int)PixelCoor.YCoor;//TmpGeo->Y; // / TmpGeo->scale ;// ; //interY;//
           // DEBUG_PRINT("[+] X = %d  Y = %d\n", X, Y);
         //   DEBUG_PRINT("[+] ViewPortCoor.XCoor = %f ViewPortCoor.YCoor = %f TmpGeo->a7= %f  scale= %f \n", ViewPortCoor.XCoor, ViewPortCoor.YCoor, (float)TmpGeo->a7, (float)TmpGeo->scale);
          //  DEBUG_PRINT("[+] a11 = %f  a12 = %f\n", TmpGeo->a11, TmpGeo->a12);
            //X = (int)(float)ViewPortCoor.XCoor; //(int)(float)TmpGeo->a11;
           // Y = (int)(float)ViewPorGetChildUIListtCoor.YCoor; //(int)(float)TmpGeo->a12;
            //width = (TmpGeo->width * TmpGeo->a7 / ScreenX) * 1280;  //* (ScreenX / 1280) ; //
            //height = (TmpGeo->height * TmpGeo->a7 / ScreenY) * 720; // * (ScreenY / 720); //
            width = static_cast<int>((int)((float)TmpGeo->width * (float)TmpGeo->a7));  //* (ScreenX / 1280) ; //
            height = static_cast<int>((int)((float)TmpGeo->height * (float)TmpGeo->a7));  // * (ScreenY / 720); //
        }

    }
    else {
        width = 0;
        height = 0;
        X = 0;
        Y = 0;
    }

    Result.width = width;
    Result.height = height;
    Result.X = X;
    Result.Y = Y;

    return Result;
}


Json::Value AddUIElementToJson(Json::Value RootLink,  __uint64_t TmpUObject,int IsWidgetTree) {
    char UObjectName[200];
    char UObjectTypeName[300];
    __uint64_t IsVisible = 0, IsEnabled = 0;
    struct UISizeCoorType UISizeCoor;
    char FTextContent[2000];
    int ChildCount = 0, HasText = 0;
    std::string NowUObjectTypeName = "";
    std::string TxtStr = "";
    char ObjAddress[50];
    std::string ObjStr = "";
    std::string NowObjectName = "";
    std::string ThisLink = "";

    __uint64_t ChildElement = 0;

    GetFNameStr(UObjectName, (__int64_t)(TmpUObject + 24));
    GetFNameStr(UObjectTypeName, (__int64_t)(*(__int64_t*)(TmpUObject + 16) + 24));

    if (IsUUserWidget(TmpUObject) == 1) //找到 UIPanel
    {
        if (UUserWidget_GetIsVisible(TmpUObject) > 0)
        {
            IsVisible = 1;
        }
        else {
            IsVisible = 0;
        }

        if (IsVisible == 1) {
            ChildElement = UTSWidgetPanel_GetWidgetTree(TmpUObject);
            if (ChildElement != 0) {
                if (UWidget_IsVisible(ChildElement) == 0) {
                    IsVisible = 0;
                }
            }
        }
        
        
    }
    else {

        if (UWidget_IsVisible(TmpUObject) > 0)
        {
            IsVisible = 1;
        }
        else {
            IsVisible = 0;
        }
    }

    if (UWidget_GetIsEnabled(TmpUObject) > 0)
    {
        IsEnabled = 1;
    }
    else {
        IsEnabled = 1;
    }

    UISizeCoor = GetUISizeCoorInfo(TmpUObject);

    // DEBUG_PRINT("[+] Get Size XY\n");
  //   DEBUG_PRINT("[+] End GetSize XY 9\n");

    memset(FTextContent, '\0', 2000);
    HasText = GetWidgetStr(TmpUObject, UObjectTypeName, FTextContent, sizeof(FTextContent));
    if (HasText == 1) {
        TxtStr = FTextContent;
    }
    else {
        TxtStr = "";
    }



    Json::Value TmpChild;

    memset(ObjAddress, 0, 50);
    snprintf(ObjAddress, 50, "%llx", TmpUObject);
    ObjStr = ObjAddress;

    TmpChild["obj"] = ObjStr;
    TmpChild["IsRunn"] = 1;
    TmpChild["IsEn"] = IsEnabled;
    TmpChild["w"] = UISizeCoor.width;
    TmpChild["h"] = UISizeCoor.height;
    TmpChild["txt"] = TxtStr;
    TmpChild["x"] = UISizeCoor.X;
    TmpChild["y"] = UISizeCoor.Y;

    if (UISizeCoor.width <= 0 && UISizeCoor.height <= 0) {
        TmpChild["IsRunn"] = 0;
    }

    NowUObjectTypeName = UObjectTypeName;
    TmpChild["clsname"] = NowUObjectTypeName;


    if (!RootLink.isNull()) {
        NowObjectName = UObjectName;
        if (IsWidgetTree == 1) {
            ThisLink = RootLink.asString() + "[WidgetTree]-->" + NowObjectName;
        }
        else {
            ThisLink = RootLink.asString() + "-->" + NowObjectName;
        }

        TmpChild["link"] = ThisLink;
    }
    else {
        NowObjectName = UObjectName;
        ThisLink = NowObjectName;
        TmpChild["link"] = ThisLink;
    }

    return TmpChild;

}




Json::Value DumpChildElementByName(Json::Value Root, __uint64_t ParentElement,int IsWidgetTree) {
    struct UISizeCoorType UISizeCoor;
    struct FMemeryType TmpParentWW;
    __int64_t result;
    __uint64_t* BeginAddress;
    int ChildCount = 0, HasText = 0;
    char UObjectName[200];
    char UObjectTypeName[300];
    char FTextContent[2000];

    
    __uint64_t TmpUObject, ChildElement;
    __uint64_t IsVisible = 0, IsEnabled = 0;

    std::string ThisLink = "";
    char ObjAddress[50];
    std::string ObjStr = "";
    std::string NowObjectName = "";
    std::string NowUObjectTypeName = "";
    std::string TxtStr = "";

    
    InitFMem(&TmpParentWW);
  //  DEBUG_PRINT("[+] DumpChildElementByName in \n");

    result = old_GetAllChildWidgets((__uint64_t)&ParentElement - 48, (__uint64_t)&TmpParentWW.A);//;



    BeginAddress = (__uint64_t*)TmpParentWW.A; //*(int**)b;
    //ChildCount = FixedAllChildWidgetMem.B;//*(int *)(b + 4);
    if (*(int*)((__uint64_t)&TmpParentWW.A + 8) == 0) {
        ChildCount = 0;
    }
    else {
        ChildCount = *(int*)((__uint64_t)&TmpParentWW.A + 8);
    }
   // DEBUG_PRINT("[+] DumpChildElementByName ChildCount=%d \n", ChildCount);

    if (ChildCount > 0 && ParentElement != 0)
    {


        for (int i = 0; i < ChildCount; i++) {

            TmpUObject = BeginAddress[i];

                GetFNameStr(UObjectName, (__int64_t)(TmpUObject + 24));
                GetFNameStr(UObjectTypeName, (__int64_t)(*(__int64_t*)(TmpUObject + 16) + 24));

           // if (UWidget_GetParent(TmpUObject) == ParentElement  ) {
                Json::Value TmpChild;
                TmpChild = AddUIElementToJson(Root["link"], TmpUObject, IsWidgetTree);
               
               
               // DEBUG_PRINT("[+] UObjectName=%s \n", UObjectName);

                if (TmpChild["IsRunn"].asInt() == 0) {

                }else{
                    if (IsUUserWidget(TmpUObject) == 1) //找到 UIPanel
                    {

                        ChildElement = UTSWidgetPanel_GetWidgetTree(TmpUObject);

                        //  DEBUG_PRINT( "[+] ChildElement3=%lx IsIgnoreHide=%d \n",ChildElement,IsIgnoreHide);  
                        TmpChild = DumpChildElementByName(TmpChild, ChildElement,1);
                    }
                    else {
                      //  ChildElement = TmpUObject;
                     //   TmpChild = DumpChildElementByName(TmpChild, ChildElement, 0);
                    }
            

                    
                    Root["son"].append(TmpChild);

                    if (strcmp(UObjectTypeName, "CircularView") == 0) {
                        DEBUG_PRINT("[+] UObjectName = %s UObjectTypeName = %s \n", UObjectName, UObjectTypeName);

                        int ListCount = *(int*)(TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset + 8);//ULHLoopListView::GetNumItems
                        __uint64_t ItemPtr = 0;
                        __uint64_t WidgetPtr = 0;

                        DEBUG_PRINT("[+] !!!!!!!!!!!!!!!! ListCount = %d \n", ListCount);

                        for (int k = 0; k < ListCount; k++)
                        {
                            __uint64_t EntryWidgetsPtr = TmpUObject + UCircularView_GetCustomDisplayedEntryWidgetsOffset;

                            ItemPtr = *(__uint64_t*)(*(__uint64_t*)EntryWidgetsPtr + 8 * k);
                            if (ItemPtr != 0) {

                                __uint64_t TmpChildElement = ItemPtr;
                                if (IsUUserWidget(ItemPtr) == 1) //找到 UIPanel
                                {

                                    Json::Value TmpChild;
                                    TmpChild = AddUIElementToJson(Root["link"], TmpChildElement, IsWidgetTree);

                                    TmpChildElement = UTSWidgetPanel_GetWidgetTree(ItemPtr);


                                    TmpChild = DumpChildElementByName(TmpChild, TmpChildElement,1);

                                    Root["son"].append(TmpChild);
                                }
                                else {
                                    TmpChildElement = ItemPtr;

                                    Json::Value TmpChild;
                                    TmpChild = AddUIElementToJson(Root["link"], TmpChildElement, 0);
        

                                    TmpChild = DumpChildElementByName(TmpChild, TmpChildElement,0);

                                    Root["son"].append(TmpChild);
                                }

                            }
                        }
                    }

                    
                    

                }

           // }
        }
    }

   // *(int*)((__uint64_t)&TmpParentWW.A + 8) = 0;
    FMemory_Free(TmpParentWW.A);

    return Root;
}

__int64_t GetEquipSetPtr()
{
    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t EquipSetPtr = 0;
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t PlayerHeroPtr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (PlayerHeroPtr != 0) {
            EquipSetPtr = *(__uint64_t*)(PlayerHeroPtr + EquipSet_Offset);
        }

        return EquipSetPtr;
    }
    return 0;

}

__int64_t GetSkillContext6()
{
    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t SkillContext6Ptr = 0;
    if (GameInstance != 0) {    //ULHWidget_Inventory::ShowItemTooltipContainer
        __uint64_t PlayerHeroPtr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (PlayerHeroPtr != 0) {
            SkillContext6Ptr = *(__uint64_t*)(PlayerHeroPtr + SkillContext6Offset);
        }

        return SkillContext6Ptr;
    }
    return 0;

}

/*
__uint64_t GetItemFNameIDBPos(__uint64_t UIItemGridWidget , int Pos) { //UIItemGridWidget::ReceiveTabEventItemSlot2
    __int64_t v31 = UIItemGridWidget + 16 * *(unsigned int*)(UIItemGridWidget + TradeBagItemStartOffset);
    DEBUG_PRINT("[+] v31=%llx", v31);
    if (v31 != 0) {
        signed int ItemCount = *(signed int*)(v31 + TradeBagItemCountOffset);
        __uint64_t v7 = TradeBagItemGridSize;
        __uint64_t v11 = *(__uint64_t*)(v31 + TradeBagItemCountOffset - 8);
        DEBUG_PRINT("[+] ItemCount=%d", ItemCount);
        if (ItemCount > 0) {
            for (int i = 0; i < ItemCount; i++)
            {

                __uint64_t v32 = v11 + i * v7;
                __uint64_t* v33 = (__uint64_t*)(v32 + 88);
                __uint64_t v46 = *(__uint64_t*)v33;

                __uint64_t v30 = *(__uint64_t*)(v46 + 24); //unsigned int* v30 = *(unsigned int**)(v46 + 24);

                __uint64_t FNameID = v30;

                int ItemPos = (int)*(unsigned __int16*)v32;

                DEBUG_PRINT("[+] ItemPos=%d", ItemPos);

                if (Pos + 1 == ItemPos) {
                    DEBUG_PRINT("[+] ItemPos=%d", ItemPos);
                    return FNameID;
                }

            }
        }
    }
    
    return 0;
}
*/


int GetTradeBagFNameID(__uint64_t InstanceId)
{
    __int64_t UITradePanel = 0;
    //UITradePanel = GameUI_GetPanel(TradePanelID); //UITradeItemList::OnClickSlotForFavarites(UITradeItemList * this, const FName * a2)
    UITradePanel = GameUI_GetPanelByName(TradePanelName);
    __int64_t UITradeBag = UITradePanel + TradeBagOffset; //UITradePanel::OnClickSlotButton(UITradePanel *this, const FName *a2) UITradeBag::OnClickSlotButton(__int64 a1, __int64 a2)
    if (UITradeBag) {
        DEBUG_PRINT("[+] UITradeBag=%llx", UITradeBag);
        __int64_t UIItemCircularView = (UITradeBag + UITradeBagItemCircularViewOffset);
        if (UIItemCircularView) {
            int MaxCount = *(int*)(UIItemCircularView + 24); //UIItemCircularView::GetUIItemSlot
            DEBUG_PRINT("[+] MaxCount=%llx", MaxCount);
            if (MaxCount > 0) {
                for (int i = 0; i < MaxCount; i++)
                {
                    int DataIndex =  i;//  UIItemCircularView_GetGridDataIndex(UIItemCircularView, i);//
                    DEBUG_PRINT("[+] DataIndex=%llx", DataIndex);
                    if (DataIndex > -1) {

                        int v56 = (int)*(char*)UITradeBag;
                        DEBUG_PRINT("[+] v56=%d", v56);
                        __int64_t StartAddress = *(__int64_t*)(UITradeBag + 24);
                        DEBUG_PRINT("[+] StartAddress=%llx", StartAddress);
                        __int64_t TmpInstanceId = *(__int64_t*)(*(__int64_t*)(StartAddress + 32 * v56) + 8LL * DataIndex);  //this = Bag2::GetItemByInstanceId(v14, *(_QWORD *)(*(_QWORD *)(v57 + 32 * v56) + 8LL * (int)this));
                        if (TmpInstanceId == InstanceId) {
                            return i;
                        }
                    }


                }
            }
           
          

           // return GetItemFNameIDBPos(UIItemGridWidget, Pos);
        }
    }
    return -1;
}



int GetBagItemFNameID(__uint64_t InstanceId) //UIInventoryPanel2::OnClickItemSlotButton
{
    RealIndexReturn = -1;
    __int64_t UIInventoryPanel = 0;
    //UIInventoryPanel = GameUI_GetPanel(UIInventoryPanelID); 
    UIInventoryPanel = GameUI_GetPanelByName(UIInventoryPanelName);

   // char UIPanelName[500];
   // GetFNameStr(UIPanelName, (__uint64_t)(UIInventoryPanel + 24)); //From UObject
    //DEBUG_PRINT("[+] UIPanelName=%s", UIPanelName);

    __int64_t UIItemCircularView = (UIInventoryPanel + UIItemCircularViewOffset);
    if (UIItemCircularView) {

        __int64_t StartAddress = rU64(UIInventoryPanel ,UIInventoryPanelStartAddressOffset); //v47   v47 = *((_QWORD *)this + 355);
        int v56 = (int)*(char*)(UIInventoryPanel + UIInventoryPanelTabIndexOffset);  //v46 = *((char *)this + 2817);      v46 = *((char *)this + 2817);
        DEBUG_PRINT("[+] v56=%d", v56);
        DEBUG_PRINT("[+] StartAddress=%llx", StartAddress);
        int MaxCount = rU32(rU64(StartAddress , 32 * v56), 8);
       // int MaxCount = *(int*)(UIItemCircularView + 24); //UIItemCircularView::GetUIItemSlot
        DEBUG_PRINT("[+] MaxCount=%llx", MaxCount);
        if (MaxCount > 0) {
            for (int i = 0; i < MaxCount; i++)
            {
                int DataIndex = i;//  UIItemCircularView_GetGridDataIndex(UIItemCircularView, i);//
                DEBUG_PRINT("[+] DataIndex=%llx", DataIndex);
                if (DataIndex > -1) {
                    //if (DataIndex < *(int*)(*(__int64_t*)(StartAddress + 32 * v56) + 8)) {
                    if (DataIndex < MaxCount) {
                        __int64_t TmpInstanceId = *(__int64_t*)(*(__int64_t*)(StartAddress + 32 * v56) + 8LL * DataIndex);  //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
                        if (TmpInstanceId == InstanceId) {

                            int MaxCount2 = *(int*)(UIItemCircularView + 24); //UIItemCircularView::GetUIItemSlot
                            DEBUG_PRINT("[+] MaxCount2=%llx", MaxCount2);
                            if (MaxCount2 > 0) {
                                for (int j = 0; j < MaxCount2; j++)
                                {
                                    int DataIndex2 = UIItemCircularView_GetGridDataIndex(UIItemCircularView, j);
                                    if (DataIndex2 == DataIndex) {
                                        RealIndexReturn = j;
                                    }
                                }
                            }


                            return i;
                        }
                    }
                   
                }


            }
        }
    }
 

    return -1;

}

int GetSellBagItemFNameID(__uint64_t InstanceId) //UIInventoryPanel2::OnClickItemSlotButton
{
    RealIndexReturn = -1;
    __int64_t UICitizenShopPanel2 = 0;
    UICitizenShopPanel2 = GameUI_GetPanelByName(ShopPanel2Name);
    //UICitizenShopPanel2 = GameUI_GetPanel(59);

    // char UIPanelName[500];
    // GetFNameStr(UIPanelName, (__uint64_t)(UIInventoryPanel + 24)); //From UObject
     //DEBUG_PRINT("[+] UIPanelName=%s", UIPanelName);

    __int64_t UIItemCircularView = (UICitizenShopPanel2 + UISellItemCircularViewOffset);
    if (UIItemCircularView) {
        int v56 = (int)*(char*)(UICitizenShopPanel2 + UISellInventoryPanelTabIndexOffset);  //v46 = *((char *)this + 2817);      v46 = *((char *)this + 2817);
        DEBUG_PRINT("[+] v56=%d", v56);
        __int64_t StartAddress = *(__int64_t*)(UICitizenShopPanel2 + UISellInventoryPanelStartAddressOffset); //v47   v47 = *((_QWORD *)this + 355);

        DEBUG_PRINT("[+] v56=%d", v56);
        DEBUG_PRINT("[+] StartAddress=%llx", StartAddress);
        int MaxCount = rU32(rU64(StartAddress, 32 * v56), 8);
       // int MaxCount = *(int*)(UIItemCircularView + 24); //UIItemCircularView::GetUIItemSlot
        DEBUG_PRINT("[+] MaxCount=%llx", MaxCount);
        if (MaxCount > 0) {
            for (int i = 0; i < MaxCount; i++)
            {
                int DataIndex = i;//  UIItemCircularView_GetGridDataIndex(UIItemCircularView, i);//
                DEBUG_PRINT("[+] DataIndex=%llx", DataIndex);
                if (DataIndex > -1) {

                  
                    DEBUG_PRINT("[+] StartAddress=%llx", StartAddress);
                    if (DataIndex < *(int*)(*(__int64_t*)(StartAddress + 32 * v56) + 8)) {
                        __int64_t TmpInstanceId = *(__int64_t*)(*(__int64_t*)(StartAddress + 32 * v56) + 8LL * DataIndex);  //result = Bag2::GetItemByInstanceId((Bag2 *)v33, *(_QWORD *)(*(_QWORD *)(v47 + 32 * v46) + 8LL * (int)result));
                        if (TmpInstanceId == InstanceId) {

                            int MaxCount2 = *(int*)(UIItemCircularView + 24); //UIItemCircularView::GetUIItemSlot
                            GENERAL_PRINT("[+] MaxCount2=%llx", MaxCount2);
                            if (MaxCount2 > 0) {
                                for (int j = 0; j < MaxCount2; j++)
                                {
                                    int DataIndex2 = UIItemCircularView_GetGridDataIndex(UIItemCircularView, j);
                                    if (DataIndex2 == DataIndex) {
                                        RealIndexReturn = j;
                                    }
                                }
                            }

                            return i;
                        }
                    }

                }


            }
        }
    }


    return -1;

}


int GetEmptyBagItemSlot(__uint64_t ItemID, __int64 Count)
{
   int  Result = -1;
   __int64_t FirstItemAddr = 0, ItemDepotPtr = 0;
   __int64_t NextItemAddr = 0;
   __int64_t ThisItemAddr = 0, TmpItemPtr =0;
   int Maximum = 0,k = 0;

   __uint64_t Bag2Ptr = GetBag2();
   __uint64_t TmpCastItem = 0;

   DEBUG_PRINT("[+] Bag2Ptr=%d", Bag2Ptr);
   if (Bag2Ptr != 0)
   {
       ItemDepotPtr = GetItemDepotPtr(Bag2Ptr);
       DEBUG_PRINT("[+] ItemDepotPtr=%d", ItemDepotPtr);

       Maximum = *(int*)(ItemDepotPtr + 4 * 4); //FNkInventoryManager::_FindItem(FNkInventoryManager *this, __int64 a2)   v3 = *(_DWORD *)&v2[4 * ((*((_DWORD *)this + 40) - 1) & ((signed int)a2 + 23 * HIDWORD(a2)))];
       DEBUG_PRINT("[+] Maximum=%d", Maximum);

       for (k = 0; k < Maximum; k++)
       {
           FirstItemAddr = (*(__uint64_t*)(ItemDepotPtr + 8) + k * 8);
           TmpItemPtr = *(__uint64_t*)(FirstItemAddr);

           if ((__uint64_t)TmpItemPtr == 0) {
               Result = k;

               DEBUG_PRINT("[+] Empty Result=%d", Result);

               break;
           }
       }


       for (k = 0; k < Maximum; k++)
       {
           FirstItemAddr = (*(__uint64_t*)(ItemDepotPtr + 8) + k * 8);
           TmpItemPtr = *(__uint64_t*)(FirstItemAddr);

       
           __uint64_t Item2Ptr = TmpItemPtr;
           if ((__uint64_t)TmpItemPtr != 0) {

               __uint64_t TmpItemID2 = (*(__uint64_t(__fastcall**)(__uint64_t))(*(__uint64_t*)Item2Ptr + 56))(Item2Ptr);
               DEBUG_PRINT("[+] Empty TmpItemID2=%ld   ItemID=%ld ", TmpItemID2, ItemID);
               if (TmpItemID2 == ItemID && ItemID != 0) {
                   __int64 TmpItemCount = (*(__int64(__fastcall**)(__int64))(*(__int64*)TmpItemPtr + 64LL))(Item2Ptr); //Bag2::GetStackCountByItemRecordId 電腦版本要-8
                   __int64 MaxStackCount = (*(__int64(__fastcall**)(__int64))(*(__int64*)TmpItemPtr + 136))(Item2Ptr);

                   DEBUG_PRINT("[+] Empty TmpItemCount=%ld   MaxStackCount=%ld ", TmpItemCount, MaxStackCount);

                   if ((TmpItemCount + Count) <= MaxStackCount) {

                       int v12 = (*(__int64(__fastcall**)(__int64))(*(__int64*)TmpItemPtr + 48))(TmpItemPtr);

                       Result = v12;

                       break;
                   }
               }
           }
       }
   }
   return Result;
}

void ReadStorageItem()
{
    int i = 0, j = 0, k = 0, Pos = 0, m = 0;
    __int64_t FirstItemAddr = 0, ItemDepotPtr = 0;
    __int64_t NextItemAddr = 0;
    __int64_t ThisItemAddr = 0;
    __int64_t TmpItemPtr;
    __int64_t TmpItemNamePtr = 0;
    int TmpItemCount = 0;
    char ItemName[500];
    char ItemUnknownName[1000];
    int ItemNameLen;
    __int64_t TmpItemID, TmpItemID2;
    __uint64_t Item2Ptr;
    __int64_t TmpTextPtr;

    unsigned int InfoId;

    struct GMemeryType TmpGMem;

    char EnhanceVal;
    char TmpItemGrade;
    int IsEquip = 0;
    __int64_t IsEquiped = 0;
    int TmpItemCanTrade = 0;

    struct FMemeryType TmpMem;

    __int64_t TmpA;
    int TextLen = 0, nameLen = 0, Maximum = 0;
    int TmpItemLocked = 0;
    float TmpItemWeight = 0;
    struct FMemeryType TmpMem3;

    for (i = 0; i <= StorageItemCount; i++)
    {
        if (StorageItem[i].IsUsed == 1)
        {
            StorageItem[i].IsUsed = 0;
            StorageItem[i].Pointer = 0;
            StorageItem[i].id = 0;
            StorageItem[i].Count = 0;

        }            //DEBUG_PRINT("[+] DeleteBagItem: %d \n", i);
    }
    StorageItemCount = 0;

    char* v2;

    DEBUG_PRINT("[+] ReadStorageItem=");

    __uint64_t Stash2Ptr = GetStash2();
    __uint64_t TmpCastItem = 0;

    DEBUG_PRINT("[+] Stash2Ptr=%d", Stash2Ptr);
    if (Stash2Ptr != 0)
    {
        ItemDepotPtr = GetStorageItemDepotPtr(Stash2Ptr);
        DEBUG_PRINT("[+] ItemDepotPtr=%d", ItemDepotPtr);

        Maximum = *(int*)(ItemDepotPtr + 4 * 4); //FNkInventoryManager::_FindItem(FNkInventoryManager *this, __int64 a2)   v3 = *(_DWORD *)&v2[4 * ((*((_DWORD *)this + 40) - 1) & ((signed int)a2 + 23 * HIDWORD(a2)))];
        DEBUG_PRINT("[+] Maximum=%d", Maximum);


        for (k = 0; k < Maximum; k++)
        {

            FirstItemAddr = (*(__uint64_t*)(ItemDepotPtr + 8) + k * 8);
            TmpItemPtr = *(__uint64_t*)(FirstItemAddr);

            if ((__uint64_t)TmpItemPtr != 0) {

                Item2Ptr = TmpItemPtr; //ULHInventoryMgr::Find(ULHInventoryMgr *this, __int64 a2, ULHItem **a3)
                DEBUG_PRINT("[+] Item2Ptr = %llx", Item2Ptr);

                if (Item2Ptr != 0) {
                    for (i = StorageItemCount; i <= 1000; i++)
                    {
                        if (StorageItem[i].IsUsed == 0)
                        {
                            TmpItemID = Item2Ptr; //ULHItem::GetGameItemInfo
                            TmpItemCount = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64LL))(Item2Ptr); //Bag2::GetStackCountByItemRecordId 電腦版本要-8

                            //TmpItemID2 = ULHInventoryMgr_GetItem(ULHInventoryMgrPtr, 0, TmpItemID);
                          //  DEBUG_PRINT("[+] Post TmpItemID = %lx TmpItemID2 = %lx", TmpItemID, TmpItemID2);


                            StorageItem[i].IsUsed = 1;
                            StorageItem[i].id = k;
                            StorageItem[i].Pointer = (char*)TmpItemPtr;
                            StorageItem[i].item2Ptr = Item2Ptr;

                            TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr);
                            Pos = (*(unsigned __int16(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                            DEBUG_PRINT("[+] Pos = %d ", Pos);

                            TmpItemID2 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                            DEBUG_PRINT("[+] Pos = %d ", Pos);
                            DEBUG_PRINT("[+] TmpItemID2 = %llx ", TmpItemID2);

                            StorageItem[i].isLock = *(char*)(Item2Ptr + 80);//Item2::SetLock(__int64 result, char a2)

                            StorageItem[i].InstanceId = TmpItemID2; //ItemDepot::GetItemByInstanceId
                            StorageItem[i].ItemID = TmpItemID;
                            StorageItem[i].Count = TmpItemCount;


                            StorageItem[i].ItemType = Item2__GetItemType(Item2Ptr);
                            DEBUG_PRINT("[+]  StorageItem[i].ItemType = %x ", StorageItem[i].ItemType);
                            StorageItem[i].isDeCompsable = 0;
                            StorageItem[i].isEquipItem = 0;
                            StorageItem[i].isEquiped = 0;
                            StorageItem[i].EnhanceLv = 0;
                            StorageItem[i].EquipItemType = 0;

                            __uint64_t MaxStackCount = (*(__uint64_t(__fastcall**)(__uint64_t))(*(__uint64_t*)TmpItemPtr + 136))(Item2Ptr);//Bag2::IsStackableSlot
                            BagItem[i].MaxStackCount = MaxStackCount;
                            DEBUG_PRINT("[+]  StorageItem[i].MaxStackCount = %lld ", StorageItem[i].MaxStackCount);


                            TmpCastItem = Item2__CastEquipItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                StorageItem[i].isDeCompsable = EquipItem__IsDisassemble(TmpCastItem);

                                StorageItem[i].EquipItemSubType = EquipItem__GetWeaponType(TmpCastItem);

                                StorageItem[i].EquipItemType = (char)(*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 128))(Item2Ptr);
                                // StorageItem[i].EquipItemType = EquipItem__GetEquipSlotType(TmpCastItem); 有問題 //UIItemDetailPanelProcessor::processEquip
                                StorageItem[i].EnhanceLv = *((unsigned int*)TmpCastItem + 52);//EquipItem::GetEnchantLevel(EquipItem *this)
                                StorageItem[i].isEquipItem = 1;
                                __uint64_t EquipSetPtr = GetEquipSetPtr();
                                if (EquipSetPtr != 0) {
                                    StorageItem[i].isEquiped = (int)(char)EquipSet_IsEquipped(EquipSetPtr, TmpItemID2);

                                }
                            }


                            TmpCastItem = Item2__CastGroceryItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                StorageItem[i].isDeCompsable = Grocery2_IsDisassemble(TmpCastItem);
                            }
                            TmpCastItem = Item2__CastBeadItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                StorageItem[i].isDeCompsable = Bead2_IsDisassemble(TmpCastItem);
                            }
                            TmpCastItem = Item2__CastDressItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                StorageItem[i].isDeCompsable = Dress2_IsDisassemble(TmpCastItem);
                            }





                            // DEBUG_PRINT("[+] Count = %d", StorageItem[i].Count);

                            InitFMem(&TmpMem);

                            // EnhanceVal = *(char*)(ULHItem + 60);
                            TmpItemGrade = Item2_GetItemGrade((int)TmpItemID);

                            StorageItem[i].ItemGrade = (int)TmpItemGrade;
                            TmpMem.A = Item2_GetItemName((int)TmpItemID);


                            DEBUG_PRINT("[+] Post TmpItemGrade = %d ", TmpItemGrade);

                            memset(ItemName, '\0', sizeof(ItemName));
                            //  snprintf(ItemName, 400, "%s", UTF16ToUTF8((char*)TmpMem3.A));
                             // DumpMemory256((char*)&TmpMem.A);
                            DEBUG_PRINT("[+] Count ");
                            if (TmpMem.A != 0) {
                                //  DumpMemory256((char*)TmpMem.A);
                                strcpy(StorageItem[i].name, (char*)TmpMem.A);
                                DEBUG_PRINT("[+] Count2 ");

                                //if (*(__uint64_t*)TmpMem.A != 0) {
                                 //   DumpMemory256(*(char**)TmpMem.A);
                                 //   DEBUG_PRINT("[+] ItemName =%s ", ItemName);

                                //}
                            }



                            /*
                            __int64_t ULHGameSingletonPtr = *ULHGameSingletonAddr;//ULHWidget_MapMove::SetAreaNameText
                            if (ULHGameSingletonPtr != 0) {
                                // DEBUG_PRINT("[+] ULHGameSingletonPtr =%lx ", ULHGameSingletonPtr) ;
                                __int64_t ULHTableMgrPtr = *(__int64_t*)(ULHGameSingletonPtr + 40);
                                InitFMem(&TmpMem3);
                               // fake_ULHTableMgr_GetTableText((long)&ULHTableMgr_GetTableText, ULHTableMgrPtr, ItemNameID, (__uint64_t)&TmpMem3.A);

                                // TmpTextPtr = GetItemNameForRichBindText(ULHItem);
                                // DEBUG_PRINT("[+] TmpTextPtr =%lx ", TmpTextPtr) ;

                                if (TmpMem3.B != 0) {
                                    int TextLen = TmpMem3.B;
                                    DEBUG_PRINT("[+] TextLen =%d", TextLen);
                                    if (TextLen > 0) {


                                        DEBUG_PRINT("[+] ItemName =%s ", ItemName);
                                        nameLen = strlen(ItemName);

                                        if (nameLen < 80)
                                        {
                                            strcpy(StorageItem[i].name, ItemName);
                                            StrToHex(StorageItem[i].name, StorageItem[i].NameInHex);
                                        }

                                        //   DEBUG_PRINT("[+] TSTextBlock Text=%s sizeof FTextContent=%d", FTextContent,FTextContentsize) ;
                                    }
                                }
                                if (TmpMem3.A != 0) {
                                    FMemory_Free(TmpMem3.A);
                                }
                            }

                            */

                            StorageItemCount = StorageItemCount + 1;
                            break;

                        }
                    }
                }



            }
            else {
                //  break;
            }



        }

    }


}



void ReadBagItem()
{
    int i = 0, j = 0, k = 0, Pos = 0, m = 0;
    __int64_t FirstItemAddr = 0, ItemDepotPtr = 0;
    __int64_t NextItemAddr = 0;
    __int64_t ThisItemAddr = 0;
    __int64_t TmpItemPtr;
    __int64_t TmpItemNamePtr = 0;
    int TmpItemCount = 0;
    char ItemName[500];
    char ItemUnknownName[1000];
    int ItemNameLen;
    __int64_t TmpItemID, TmpItemID2;
    __uint64_t Item2Ptr;
    __int64_t TmpTextPtr;

    unsigned int InfoId;

    struct GMemeryType TmpGMem;

    char EnhanceVal;
    char TmpItemGrade;
    int IsEquip = 0;
    __int64_t IsEquiped = 0;
    int TmpItemCanTrade = 0;

    struct FMemeryType TmpMem;

    __int64_t TmpA;
    int TextLen = 0, nameLen = 0, Maximum = 0;
    int TmpItemLocked = 0;
    float TmpItemWeight = 0;
    struct FMemeryType TmpMem3;

    for (i = 0; i <= BagItemCount; i++)
    {
        if (BagItem[i].IsUsed == 1)
        {
            BagItem[i].IsUsed = 0;
            BagItem[i].Pointer = 0;
            BagItem[i].id = 0;
            BagItem[i].Count = 0;

        }            //DEBUG_PRINT("[+] DeleteBagItem: %d \n", i);
    }
    BagItemCount = 0;

    char* v2;

    DEBUG_PRINT("[+] ReadBagItem=");

    __uint64_t Bag2Ptr = GetBag2();
    __uint64_t TmpCastItem = 0;

    DEBUG_PRINT("[+] Bag2Ptr=%d", Bag2Ptr);
    if (Bag2Ptr != 0)
    {
        ItemDepotPtr = GetItemDepotPtr(Bag2Ptr);
        DEBUG_PRINT("[+] ItemDepotPtr=%d", ItemDepotPtr);

        Maximum = *(int*)(ItemDepotPtr + 4*4); //FNkInventoryManager::_FindItem(FNkInventoryManager *this, __int64 a2)   v3 = *(_DWORD *)&v2[4 * ((*((_DWORD *)this + 40) - 1) & ((signed int)a2 + 23 * HIDWORD(a2)))];
        DEBUG_PRINT("[+] Maximum=%d", Maximum);


        for (k = 0; k < Maximum; k++)
        {

            FirstItemAddr = (*(__uint64_t*)(ItemDepotPtr + 8)  + k * 8);
            TmpItemPtr = *(__uint64_t*)(FirstItemAddr);

            if ((__uint64_t)TmpItemPtr != 0) {

                Item2Ptr = TmpItemPtr; //ULHInventoryMgr::Find(ULHInventoryMgr *this, __int64 a2, ULHItem **a3)
                DEBUG_PRINT("[+] Item2Ptr = %llx", Item2Ptr);

                if (Item2Ptr != 0) {
                    for (i = BagItemCount; i <= 1000; i++)
                    {
                        if (BagItem[i].IsUsed == 0)
                        {
                            TmpItemID = Item2Ptr; //ULHItem::GetGameItemInfo
                            TmpItemCount = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 64LL))(Item2Ptr); //Bag2::GetStackCountByItemRecordId 電腦版本要-8
                          
                            //TmpItemID2 = ULHInventoryMgr_GetItem(ULHInventoryMgrPtr, 0, TmpItemID);
                          //  DEBUG_PRINT("[+] Post TmpItemID = %lx TmpItemID2 = %lx", TmpItemID, TmpItemID2);


                            BagItem[i].IsUsed = 1;
                            BagItem[i].id = k;
                            BagItem[i].Pointer = (char*)TmpItemPtr;
                            BagItem[i].item2Ptr = Item2Ptr;

                            TmpItemID = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 56))(Item2Ptr);
                            Pos = (*(unsigned __int16(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 48))(Item2Ptr);
                            DEBUG_PRINT("[+] Pos = %d ", Pos);

                            TmpItemID2 = (*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 232))(Item2Ptr);
                            DEBUG_PRINT("[+] Pos = %d ", Pos);
                            DEBUG_PRINT("[+] TmpItemID2 = %llx ", TmpItemID2);

                            BagItem[i].isLock = *(char*)(Item2Ptr + 80);//Item2::SetLock(__int64 result, char a2)


                            BagItem[i].ItemID = TmpItemID;
                            BagItem[i].InstanceId = TmpItemID2; //ItemDepot::GetItemByInstanceId
                            BagItem[i].Count = TmpItemCount;

                        
                            BagItem[i].ItemType = Item2__GetItemType(Item2Ptr);
                            DEBUG_PRINT("[+]  BagItem[i].ItemType = %x ", BagItem[i].ItemType);
                            __uint64_t MaxStackCount = (*(__uint64_t(__fastcall**)(__uint64_t))(*(__uint64_t*)TmpItemPtr + 136))(Item2Ptr);//Bag2::IsStackableSlot
                            BagItem[i].MaxStackCount = MaxStackCount;

                            BagItem[i].isDeCompsable = 0;
                            BagItem[i].isEquipItem = 0;
                            BagItem[i].isEquiped = 0;
                            BagItem[i].EnhanceLv = 0;
                            BagItem[i].EquipItemType = 0;
                    

                            TmpCastItem = Item2__CastEquipItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                BagItem[i].isDeCompsable = EquipItem__IsDisassemble(TmpCastItem);
                                BagItem[i].EquipItemSubType = EquipItem__GetWeaponType(TmpCastItem);
                                BagItem[i].EquipItemType = (char)(*(__int64(__fastcall**)(__int64))(*(__int64*)Item2Ptr + 128))(Item2Ptr);
                               // BagItem[i].EquipItemType = EquipItem__GetEquipSlotType(TmpCastItem); 有問題 //UIItemDetailPanelProcessor::processEquip
                                BagItem[i].EnhanceLv = *((unsigned int*)TmpCastItem + 52);//EquipItem::GetEnchantLevel(EquipItem *this)
                                BagItem[i].isEquipItem = 1;
                                __uint64_t EquipSetPtr = GetEquipSetPtr();
                                if (EquipSetPtr != 0) {
                                    BagItem[i].isEquiped = (int)(char)EquipSet_IsEquipped(EquipSetPtr, TmpItemID2);

                                }
                            }

                            
                            TmpCastItem = Item2__CastGroceryItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                BagItem[i].isDeCompsable = Grocery2_IsDisassemble(TmpCastItem);
                            }
                            TmpCastItem = Item2__CastBeadItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                BagItem[i].isDeCompsable = Bead2_IsDisassemble(TmpCastItem);
                            }
                            TmpCastItem = Item2__CastDressItem(Item2Ptr, Item2Ptr);
                            if (TmpCastItem != 0) {
                                BagItem[i].isDeCompsable = Dress2_IsDisassemble(TmpCastItem);
                            }

   
                 


                           // DEBUG_PRINT("[+] Count = %d", BagItem[i].Count);

                            InitFMem(&TmpMem);

                           // EnhanceVal = *(char*)(ULHItem + 60);
                            TmpItemGrade = Item2_GetItemGrade((int)TmpItemID);

                            BagItem[i].ItemGrade = (int)TmpItemGrade;
                            TmpMem.A = Item2_GetItemName((int)TmpItemID);


                            DEBUG_PRINT("[+] Post TmpItemGrade = %d " , TmpItemGrade);

                            memset(ItemName, '\0', sizeof(ItemName));
                          //  snprintf(ItemName, 400, "%s", UTF16ToUTF8((char*)TmpMem3.A));
                           // DumpMemory256((char*)&TmpMem.A);
                            DEBUG_PRINT("[+] Count ");
                            if (TmpMem.A != 0) {
                              //  DumpMemory256((char*)TmpMem.A);
                                strcpy(BagItem[i].name, (char*)TmpMem.A);
                                DEBUG_PRINT("[+] Count2 ");
                               
                                //if (*(__uint64_t*)TmpMem.A != 0) {
                                 //   DumpMemory256(*(char**)TmpMem.A);
                                 //   DEBUG_PRINT("[+] ItemName =%s ", ItemName);
                                
                                //}
                            }
                           


                            /*
                            __int64_t ULHGameSingletonPtr = *ULHGameSingletonAddr;//ULHWidget_MapMove::SetAreaNameText
                            if (ULHGameSingletonPtr != 0) {
                                // DEBUG_PRINT("[+] ULHGameSingletonPtr =%lx ", ULHGameSingletonPtr) ;
                                __int64_t ULHTableMgrPtr = *(__int64_t*)(ULHGameSingletonPtr + 40);
                                InitFMem(&TmpMem3);
                               // fake_ULHTableMgr_GetTableText((long)&ULHTableMgr_GetTableText, ULHTableMgrPtr, ItemNameID, (__uint64_t)&TmpMem3.A);

                                // TmpTextPtr = GetItemNameForRichBindText(ULHItem);
                                // DEBUG_PRINT("[+] TmpTextPtr =%lx ", TmpTextPtr) ;

                                if (TmpMem3.B != 0) {
                                    int TextLen = TmpMem3.B;
                                    DEBUG_PRINT("[+] TextLen =%d", TextLen);
                                    if (TextLen > 0) {

                                       
                                        DEBUG_PRINT("[+] ItemName =%s ", ItemName);
                                        nameLen = strlen(ItemName);

                                        if (nameLen < 80)
                                        {
                                            strcpy(BagItem[i].name, ItemName);
                                            StrToHex(BagItem[i].name, BagItem[i].NameInHex);
                                        }

                                        //   DEBUG_PRINT("[+] TSTextBlock Text=%s sizeof FTextContent=%d", FTextContent,FTextContentsize) ;
                                    }
                                }
                                if (TmpMem3.A != 0) {
                                    FMemory_Free(TmpMem3.A);
                                }
                            }

                            */

                            BagItemCount = BagItemCount + 1;
                            break;

                        }
                    }
                }



            }
            else {
                //  break;
            }



        }

    }


}

__uint64_t GetParty() {
    __uint64_t GameInstance = GetGameInstanceE();
    __uint64_t v29 = 0;
    if (GameInstance != 0) {
        __uint64_t  DataManager3Ptr = *(__uint64_t*)(GameInstance + AgentOffset);
        if (DataManager3Ptr != 0) {
            v29 = *(__uint64_t*)(DataManager3Ptr + PartyOffset);
        }
        
    }
    return v29;
}



void GetTeamList() {
    int i = 0;
    int MemberCount = 0;

    __int64_t LeaderID = 0;
    struct FMemeryType TmpMem;
    char PlayerName[500];
    __int64_t v5 = 0;
    __int64_t MemberPtr;



    for (i = 0; i < 50; i++)
    {
        TeamList[i].IsUsed = 0;
    }

    __uint64_t GameInstance = GetGameInstanceE();
    __int64_t PartyMgrAddr = GetParty();

    int TeamListSize1 = TeamListSize; // Party::GetPartyMemberByHeroName(

    if (PartyMgrAddr != 0) {  //CBPartyMgr::IsMyPartyMember(CBPartyMgr *this, int a2, __int64 a3)
        GENERAL_PRINT("[+] CBPartyMgrPtr = %llx \n", PartyMgrAddr);

        if (PartyMgrAddr != 0) {
            MemberCount = 4;

            // GENERAL_PRINT("[+] MemberCount = %d \n",MemberCount);   

            if (MemberCount > 0) {
                v5 = PartyMgrAddr;
                for (i = 0; i <= MemberCount - 1; i++)
                {
                    
                    // GENERAL_PRINT("[+] i = %x \n",i);   

                     //GENERAL_PRINT("[+] Team v5 = %x \n",v5 + 16 + 18*8*i);   

                    MemberPtr = v5 + TeamListSize1 * i + 8;
                    GENERAL_PRINT("[+] MemberPtr = %llx \n", MemberPtr);

                    TeamList[i].MapID = *(int*)(MemberPtr + 24 * 4); // PartyMember::SetBasicInfo(PartyMember * this, const MsgObj::PartyMemberBasicProperty * a2)   //*((_DWORD *)v3 + 24) = *((_DWORD *)v2 + 17);

                    TeamList[i].PlayerID = *(__int64_t*)(v5 + TeamListSize1 * i + 16);  //CBPartyMgr::GetMemberName(CBPartyMgr *this, int
                    GENERAL_PRINT("[+] TeamList[i].PlayerID = %llx \n", TeamList[i].PlayerID);

                    TeamList[i].Pos = *(char*)(v5 + 8 + TeamListSize1 * i);

                    GENERAL_PRINT("[+] TTeamList[i].Pos = %d \n", TeamList[i].Pos);

                    if (TeamList[i].Pos == 1) {
                        TeamList[i].IsLeader = 1;
                    }
                    else {
                        TeamList[i].IsLeader = 0;
                    }

                    if (TeamList[i].PlayerID != 0 && TeamList[i].Pos > 0) {
                        TeamList[i].IsUsed = 1;

                        if ((char*)(v5 + 33 + TeamListSize1 * i) != 0) {
                            //GENERAL_PRINT("[+] TmpMem.A = %x \n",TmpMem.A);    
                            strcpy(PlayerName, (char*)(v5 + 33 + TeamListSize1 * i));   //Party::GetPartyMemberByHeroName(Party *this, const char *a2)
                            strcpy(TeamList[i].PlayerName, PlayerName);
                           // FMemory_Free(TmpMem.A);
                                GENERAL_PRINT("[+] Team PlayerName = %s \n",TeamList[i].PlayerName);    
                        }


                        __uint64_t MemberAgentID = *(__uint64_t*)(MemberPtr + 16);

                        GENERAL_PRINT("[+] Team MemberAgentID = %llx \n", MemberAgentID);
                        InitFMem(&TmpMem);
                        __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, MemberAgentID);
                        // GENERAL_PRINT("[+]F10 TmpMem.A = %llx", TmpMem.A);

                        TeamList[i].NowHP = 0;
                        TeamList[i].MaxHP = 0;

                        TeamList[i].PosX = 0;
                        TeamList[i].PosY = 0;
                        TeamList[i].PosZ = 0;

                        if (TmpMem.A != 0) {
                            int v9 = *(int*)(TmpMem.A + NowHpOffset);
                            TeamList[i].NowHP = (int)(float)(v9 & ~(v9 >> 31)); //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
                            TeamList[i].MaxHP = (int)(float)*(signed int*)(TmpMem.A + MaxHpOffset);

                            TeamList[i].PosX = (float)*(signed int*)(TmpMem.A + CoorOffset);
                            TeamList[i].PosY = (float)*(signed int*)(TmpMem.A + CoorOffset + 4);
                            TeamList[i].PosZ = (float)*(signed int*)(TmpMem.A + CoorOffset + 8);


                        }
            

                    }
                    else {
                        TeamList[i].IsUsed = 0;
                    }
                   


                    
 

                    //GENERAL_PRINT("[+] Team PlayerName: =%s IsLeader = %d NowHP = %lld MaxHP = %lld PlayerMap =%s \n",PlayerName,TeamList[i].IsLeader,TeamList[i].NowHP ,TeamList[i].MaxHP,TeamList[i].PlayerMap);               

                    //CBPartyMgr::GetMemberName
                }
            }
        }


    }


}


int __fastcall B2Client__IsShowLoadingScreen(__int64_t Tmpthis)
{
    __int64 v1; // x8
    int result = 0; // x0

    if (Tmpthis != 0) {
        v1 = *(__int64_t*)(Tmpthis + LoadingScreen_Offset);
        if (v1 != 0) {
            result = (int)*(unsigned __int8*)(v1 + 8);
        }
        else {
            result = 0LL;
        }
            
    }
   
    return result;
}

int wlen(unsigned short* strString)
{
    int i = 0;
    while (1)
    {
        if (strString[i] == 0)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    return i;
}

std::string IsNpc(__uint64_t ActorPtr) {
    
    
    if (ActorPtr != 0 ) {
        if (*(__uint64_t*)(ActorPtr + 8) != 0) {
            if (*(__uint64_t*)(*(__uint64_t*)(ActorPtr + 8) + 8) != 0) {
                if (*(__uint64_t*)(*(__uint64_t*)(ActorPtr + 8) + 8) != 0) {
                }
            }
        }
    }

}
 


std::string ReadActorList() {

    Json::Value ResultJson;
    // Game::UpdateNpcAll(__int64 result, char a2)
    //Game::FindAgent 
    char ActorName[300];
    char ActorName16[600];

    char GuildName[300];
    char GuildName2[300];
    char GuildName16[600];
    
    
    int ActorHp = 0, ActorMaxHp = 0;
    int HaveData = 0;
    int MaxCount = 0;
    __uint64_t v21 = 0, Agent  = 0, AgentID = 0;
    __int64_t AttackerID = 0;
    float PosX = 0, PosY = 0, PosZ = 0;
    char type = 0;
    char ObjAddress[50];
    int IsDead = 0, CanAttackInRange =0, ActorCount = 0;
    struct FMemeryType TmpMem;   //FGeometry::ToString

    for (int i = 0; i < 1500; i++)
    {
        ActorList[i].IsUsed = 0;
    }

    __uint64_t GameInstance = GetGameInstanceE();
    if (GameInstance != 0) {

        MaxCount = *(int *)(GameInstance + NPCListMaxCountOffSet);
        DEBUG_PRINT("[+]MaxCount=%d\n", MaxCount);
        if (MaxCount > 0) {
            DEBUG_PRINT("[+]MaxCount=%d\n", MaxCount);

            ReadValidAddress();

            for (int i = 0; i <= MaxCount; i++)
            {
                if (*(__uint64_t*)(GameInstance + (NPCListMaxCountOffSet - 40)) != 0) {

                    if (i == MaxCount) {
                        v21 = GameInstance + AgentOffset -8;
                    }
                    else {
                        v21 = *(__uint64_t*)(GameInstance + (NPCListMaxCountOffSet - 40)) + 32LL * (signed int)i;
                    }
    

                   // int v7 = *(int*)(v21 + 24);
                   // if (v7 == -1) {
                   //     break;
                   // }

                    AgentID = *(__uint64_t*)(v21);
                    Agent = *(__uint64_t*)(v21 + 8);

                    InitFMem(&TmpMem);
                    __uint64_t TmpAgent = Game_FindAgent(GameInstance, (__uint64_t)&TmpMem.A, AgentID);
                    // GENERAL_PRINT("[+]TmpAgent = %llx", TmpAgent);
                    if (TmpMem.A != 0) {
                        //    AttackerID = *(__int64_t*)(v21 + 384); //Game::SetTargetId((Game *)v11, *(_QWORD *)(v35 + 384));
                        AttackerID = 0;
                        CanAttackInRange = 0;

                        if (Agent == TmpMem.A) {
                            DEBUG_PRINT("[+]equal\n");
                        }

                        if (Agent != 0 && AgentID != 0) { //&& AttackerID != 0)
                            if (rU64(Agent,PlayerHeroDisplayOffset) != 0 ) { //&& *(__uint64_t*)(Agent + PlayerHeroDisplayOffset + 8) != 0

                                DEBUG_PRINT("[+]Agent=%llx\n", Agent);
                                int IsAttackMe = 0;

                                __uint64_t NPCDisplay = PlayerHero__GetPlayerHeroDisplay(Agent);
                                if (NPCDisplay != 0) {
                                    try
                                    {
                                        if (IsValidAddress(Agent + MaxHpOffset) == 1) {
                                            int v9 = *(int*)(Agent + NowHpOffset);
                                            ActorHp = (int)(float)(v9 & ~(v9 >> 31)); //AgentDisplay::UpdateBar(AgentDisplay *this)  //ICharacter::SetProgressBarPercentage
                                            ActorMaxHp = (int)(float)*(signed int*)(Agent + MaxHpOffset);
                                            type = 0;
                                            PosX = (float)*(signed int*)(Agent + CoorOffset);
                                            PosY = (float)*(signed int*)(Agent + CoorOffset + 4);
                                            PosZ = (float)*(signed int*)(Agent + CoorOffset + 8);
                                            DEBUG_PRINT("[+] ActorHp = %x  ActorMaxHp= %x ", ActorHp, ActorMaxHp);

                                            // GENERAL_PRINT("[+]F10 2 AttackerHp = %x  AttackerMaxHp= %x ", AttackerHp, AttackerMaxHp);
                                            InitFMem(&TmpMem);
                                            memset(ActorName, 0, 300);
                                            memset(ActorName16, 0, 600);
                                            memset(GuildName16, 0, 600);
                                            //  __uint64_t v29 = Npc_GetRecordName(Agent, (__uint64_t)&TmpMem.A);
                                            IsDead = 0;

                                            int ISNpc = 0;
                                            if (ActorMaxHp > 0) {


                                                __uint64_t v6 = rU64(Agent, 16);
                                                __uint64_t v24 = rU64(Agent,8);
                                                if (v6 == 0) {
                                                    IsDead = 1;
                                                }

                                                if (v24 != 0 && v6 != 0) {// && ISNpc == 1
                                                

                                                    char* v5 = *(char**)(Agent + 80);
                                                    if (rU8(v5, 27) == 1 || rU64(Agent , 124) <= 0) //AutoPlay2::checkTargetDead(AutoPlay2 *this)  Game::CheckAgentAlive
                                                    {
                                                        IsDead = 1;
                                                    }
                                                    

                                                    if ((*(unsigned __int8(__fastcall**)(__uint64_t*))(*(__uint64_t*)Agent + 80i64))((__uint64_t*)Agent))//Agent::IsEliteNpc
                                                    {
                                                        //__uint64_t v4 = *(__uint64_t*)(Agent + Npc2nameOffset);  // Npc::GetRecordName@<GameRecord2::Npc2::name((GameRecord2::Npc2 *)(result + 744));
                                                        __uint64_t GameRecord2_Npc2 = rU64(v24, Npc2nameOffset);
                                                        DEBUG_PRINT("[+] IsDead  = %d  ", IsDead);

                                                        if (GameRecord2_Npc2 != 0) {

                                                            ISNpc = 1;


                                                            __uint64_t IsVisiblePtr = (*(__uint64_t*)(Agent + PlayerHeroDisplayOffset) + NpcIsVisibleOffset); // Npc::IsVisible(Npc *this)
                                                            if (rU8((void*)IsVisiblePtr,0) == 1) {

                                                                           
                                                                type = rU8((void*)GameRecord2_Npc2, NpcGradeOffset); //GameRecord2::Npc2::grade(GameRecord2::Npc2 *this)

                                                                DEBUG_PRINT("[+] type  = %d  ", type);

                                                                if (type > 0 && type < 10) {

                                                                    __uint64_t v29 = rU64(GameRecord2_Npc2, 8);  //GameRecord2::Npc2::name

                                                                    if (v29 != 0) {

                                                                        DEBUG_PRINT("[+] v29  2= %llx  ", v29);
                                                                        if ((__uint64_t)v29 != 0) {

                                                                            if (IsValidAddress(Agent + NpcGetRecordNameOffset + 8) == 1) {  //Npc::GetRecordName
                                                                                Npc_GetRecordName(Agent, (__uint64_t)&TmpMem.A);

                                                                                __uint64_t v29 = *(__uint64_t*)(Agent + NpcGetRecordNameOffset);
                                                                                __uint64_t v22 = *(__uint64_t*)(Agent + NpcGetRecordNameOffset + 8);
                                                                                DEBUG_PRINT("[+] v22  2= %llx  ", v22);
                                                                                if ((__uint64_t)v29 != 0 && (__uint64_t)TmpMem.A != 0) {
                                                                                    __uint64_t v29 = *(__uint64_t*)(TmpMem.A);
                                                                                    if ((__uint64_t)v29 != 0) {
                                                                                        if (Len((char*)v29) > 0 && Len((char*)v29) < 300) {
                                                                                            memcpy(ActorName, (char*)v29, Len((char*)v29));
                                                                                        }
                                                                                    }
                                                                                }
                                                                                                    

                                                                                __uint64_t SkillContext6Ptr = GetSkillContext6();
                                                                                if (SkillContext6Ptr != 0) {
                                                                                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                                                                                    if (AutoPlay2) {
                                                                                        CanAttackInRange = SkillContext6_CheckCanHitTargetByAutoEy(SkillContext6Ptr, AgentID);

                                                                                    }
                                                                                }

                                                                                IsAttackMe = Agent_IsAttackPlayerHero(Agent);
                                                                            }
                                                                        }

                                                                    }

                                                                }
                                                                            
                                                            }
                                                                   

                                                            
                                                        }
                                                    }
                                            
                                                    /*
                                                    IsDead = 0;
                                                    __int64* v5 = *(__int64**)(Agent + 64);
                                                    if (IsValidAddress((__uint64_t)((char*)v5 + 27)) == 1) {
                                                        if (*((char*)v5 + 27) == 1 || *(__uint64_t*)(Agent + 124) <= 0) //AutoPlay2::checkTargetDead(AutoPlay2 *this)  Game::CheckAgentAlive
                                                        {
                                                            IsDead = 1;
                                                        }


                                                        // if ((*(__int64(__fastcall**)(__uint64_t*))(*(__uint64_t*)Agent + 80LL))((__uint64_t*)Agent) & 1)
                                                    // {
                                                        DEBUG_PRINT("[+] v4  = %llx  ", v4);
                                                        __uint64_t ICharacter = *(__uint64_t*)(NPCDisplay + ICharacterOffset);

                                                        if (ICharacter != 0 && ICharacter != -1) {
                                                            if (v4 != 0) {
                                                                DEBUG_PRINT("[+]NPC Name Address = %llx", *(__uint64_t*)(v4 + 8));
                                                                if (*(__uint64_t*)(v4 + 8) != 0  && *(__uint64_t*)(v4 + 16) != 0) {// && ISNpc == 1

                                                                    __uint64_t IsVisiblePtr = (*(__uint64_t*)(Agent + PlayerHeroDisplayOffset) + NpcIsVisibleOffset); // Npc::IsVisible(Npc *this)
                                                                    if (IsValidAddress(IsVisiblePtr) == 1) {


                                                                        if (*(char*)IsVisiblePtr != 0) { //IsVisible
                                                                            if (IsValidAddress(v4 + NpcGradeOffset) == 1) {
                                                                                type = *(unsigned __int8*)(v4 + NpcGradeOffset); //GameRecord2::Npc2::grade(GameRecord2::Npc2 *this)

                                                                                DEBUG_PRINT("[+] type  = %d  ", type);

                                                                                if (type > 0 && type < 10) {

                                                                                    __uint64_t v29 = *(__uint64_t*)(v4 + 8);  //GameRecord2::Npc2::name

                                                                                    if ((__uint64_t)v29 != 0) {
                         


                                                                                        DEBUG_PRINT("[+] v29  2= %llx  ", v29);
                                                                                        if ((__uint64_t)v29 != 0) {

                                                                                            if (IsValidAddress(Agent + NpcGetRecordNameOffset + 8) == 1) {  //Npc::GetRecordName
                                                                                                Npc_GetRecordName(Agent, (__uint64_t)&TmpMem.A);

                                                                                                __uint64_t v29 = *(__uint64_t*)(Agent + NpcGetRecordNameOffset);
                                                                                                __uint64_t v22 = *(__uint64_t*)(Agent + NpcGetRecordNameOffset + 8);
                                                                                                DEBUG_PRINT("[+] v22  2= %llx  ", v22);
                                                                                                if ((__uint64_t)v29 != 0 && (__uint64_t)TmpMem.A != 0) {
                                                                                                    __uint64_t v29 = *(__uint64_t*)(TmpMem.A);
                                                                                                    if ((__uint64_t)v29 != 0) {
                                                                                                        if (Len((char*)v29) > 0 && Len((char*)v29) < 300) {
                                                                                                            memcpy(ActorName, (char*)v29, Len((char*)v29));
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                ISNpc = 1;

                                                                                                __uint64_t SkillContext6Ptr = GetSkillContext6();
                                                                                                if (SkillContext6Ptr != 0) {
                                                                                                    __uint64_t AutoPlay2 = *(__int64_t*)(GameInstance + Game_IsAutoPlay_Offset1);
                                                                                                    if (AutoPlay2) {
                                                                                                        CanAttackInRange = SkillContext6_CheckCanHitTargetByAutoEy(SkillContext6Ptr, AgentID);

                                                                                                    }
                                                                                                }

                                                                                            }
                                                                                        }

                                                                                    }




                                                                                }
                                                                            }





                                                                        }
                                                                    }
                                                                }

                                                               

                                                            }

                                                        }
                                                    }
                                                    */
                                                    // }
                                                }

                                                memset(GuildName, 0, 300);
                                                memset(GuildName2, 0, 300);
                                                std::string GuildNameStr = "";
                                                std::string GuildName2Str = "";
                                                std::string ActorNameStr = "";
                                                std::string  ActorIDStr =  "";
                                                std::string  AttackerIDStr = "";
                                                int Isplayer = 0;
                                                DEBUG_PRINT("[+]ISNpc = %d", ISNpc);

                                                Json::Value TmpChild;
                                                TmpChild["id"] = i;

                                                

                                                if (ISNpc == 0) {
                                                    DEBUG_PRINT("[+]ISNpc = 0");
                                                    ActorNameStr = ActorName;
                                                    
                                                    
                                                    if (ActorNameStr == "") {
                                                        if (IsValidAddress(((__uint64_t)Agent + IsPlayerOffset)) == 1) {
                                                            DEBUG_PRINT("[+]960 = %d", *(char*)((__uint64_t)Agent + IsPlayerOffset)); // UIPartyManagementPanel::makeInviteHeroListByFilteringZone
                                                            if (*(char*)((__uint64_t)Agent + IsPlayerOffset) != 1) {
                                                               // if (IsValidAddress(*(__uint64_t*)((__uint64_t)Agent + 56)) == 1) {
                                                                    //    GENERAL_PRINT("[+]TmpMem.A + 960 = %d", *(char*)((__uint64_t)TmpMem.A + 960));
                                                                        //if (*(char*)((__uint64_t)TmpMem.A + 960) != 1) { //Game::snapshotHeroList(Game *this, __int64 a2)   UIPartyManagementPanel::makeInviteHeroListByFilteringZone
                                                                DEBUG_PRINT("[+]F10 5 AttackerMp = %x  AttackerMaxMp= %x ", AttackerMp, AttackerMaxMp);
                                                                    

                                                                    /*
                                                                    __uint64_t v58 = *((__uint64_t*)Agent + 149); //PlayerHeroDisplay::UpdateNamePlate(__int64 result)  電腦版的名字儲存方式跟ANDROID 版本不同
                                                                    __uint64_t v60 = v58 & 0xFFFFFFFFFFFFFFFELL;

                                                                    GENERAL_PRINT("[+]v60 = %llx", v60);

                                                                    char* v29;
                                                                    if (v60 != 0 && v60 != -1) {
                                                                        if (*((__uint64_t*)v60 + 3) >= 0x10) {
                                                                            v29 = *(char**)v60;
                                                                        }
                                                                        else {
                                                                            v29 = (char*)v60;
                                                                        }
                                                                        if ((__uint64_t)v29 != 0) {
                                                                            if (strlen(v29) < 300) {
                                                                                strcpy(PKTargetName, v29);
                                                                            }
                                                                        }
                                                                    }
                                                                    */

                                                                    __uint64_t v183 = (*(__int64(__fastcall**)(__uint64_t))(*(__uint64_t*)Agent + 120LL))(Agent);  //電腦版是  -8    (128 -8)  //PlayerHeroDisplay::UpdateNamePlate(__int64 result) 
                                                                    char* v29;
                                                                    if (v183 != 0 && v183 != -1) {
                                                                        if (*(char*)v183 != 0) {
                                                                            v29 = (char*)v183;
                                                                            if ((__uint64_t)v29 != 0) {
                                                                                if (strlen(v29) < 300) {
                                                                                    strcpy(ActorName, v29);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    
                                                                    Isplayer = 1;
                                                                 
                                                                    //Hero::SetGuild
                                                                    // Guild::setGuild
                                                                    //HeroDisplay::UpdateNamePlate  
                                                                   // Hero::SetGuild(Hero* this, const MsgObj::GuildBroadcast* a2)
                                                                    /*
                                                                    __uint64_t ICharacter = *(__uint64_t*)(NPCDisplay + ICharacterOffset);
                                                                    if (ICharacter) {
                                                                        if (IsValidAddress(ICharacter + 12) == 1) {
                                                                            __uint64_t v21 = WeakObjectPtr_Get(ICharacter + 12);
                                                                            if (v21 != 0) {
                                                                                DEBUG_PRINT("[+] v21  = %llx  ", v21);
                                                                                __uint64_t v22 = *(__uint64_t*)(v21 + GuildTextOffset); //ICharacter::SetGuildText
                                                                                DEBUG_PRINT("[+] v22  = %llx  ", v22);
                                                                                unsigned int v24 = *(unsigned int*)(v21 + GuildTextOffset + 8);
                                                                                DEBUG_PRINT("[+] v24  = %d  ", v24);
                                                                                if (v22 != 0) {
                                                                                    if (v24 > 0 && v24 < 300) {
                                                                                        memcpy(GuildName16, (char*)v22, v24 *2);
                                                                                        strcpy(GuildName, UTF16ToUTF8((char*)GuildName16));
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                   */
                                                                    IsAttackMe = Agent_IsAttackPlayerHero(Agent);
                                                                  
                                                               
                                                                    const char* v115;
                                                                    __uint64_t  v114 = rU64(Agent, 1200) & 0xFFFFFFFFFFFFFFFELL;

                                                                    if (IsBadReadPtr((void*)v114, 8) == false)
                                                                    {
                                                                        if (rU64(v114, 24) >= 0x10ui64) {
                                                                            v115 = (const char*)rU64(v114, 0);
                                                                        }
                                                                        else {
                                                                            v115 = (const char*) v114;
                                                                        }

                                                                        if ((__uint64_t)v115 != 0) {
                                                                            if (rU8((void*)v115, 0) != 0) {
                                                                                //if (IsBadReadPtr((void*)v115, 1) == false)
                                                                                //{
                                                                                if (strlen(v115) < 300) {
                                                                                    strcpy(GuildName, v115);
                                                                                }

                                                                                //}
                                                                            }
                                                                        }
                                                                    }
                                                                   


                                                                    v114 = rU64(Agent, 1256) & 0xFFFFFFFFFFFFFFFELL;

                                                                    if (IsBadReadPtr((void*)v114, 8) == false)
                                                                    {
                                                                        if (rU64(v114, 24) >= 0x10ui64) {
                                                                            v115 = (const char*)rU64(v114, 0);
                                                                        }
                                                                        else {
                                                                            v115 = (const char*)v114;
                                                                        }

                                                                        if ((__uint64_t)v115 != 0) {
                                                                            if (rU8((void*)v115, 0) != 0) {
                                                                                //if (IsBadReadPtr((void*)v115, 1) == false)
                                                                                //{
                                                                                if (strlen(v115) < 300) {
                                                                                    strcpy(GuildName2, v115);
                                                                                }

                                                                                //}
                                                                            }
                                                                        }
                                                                    }
                                                                    
                                  
                                                                    // }
                                                               // }
                                                            }
                                                        }
                                                    }

                                                    

                                                    if (Isplayer == 0) {
                                                        type = 3;
                                             
                                                    }
                                                    else {
                                                        type = 20;
                                                        
                                                    }

                                                    TmpChild["CanAtk"] = CanAttackInRange;
                                                    GuildNameStr = GuildName;
                                                    GuildName2Str = GuildName2;
                                                    
                                                }
                                                else {
                                                    
                                                    //TmpChild["CanAtk"] = CanAttackInRange;
                                                }

                                                ActorNameStr = ActorName;
                                                DEBUG_PRINT("[+] ActorNameStr = %s  ", ActorNameStr.c_str());

                                                memset(ObjAddress, 0, 50);
                                                snprintf(ObjAddress, 50, "%llx", AgentID);
                                                ActorIDStr = ObjAddress;

                                                TmpChild["ActorID"] = ActorIDStr;

                                                memset(ObjAddress, 0, 50);
                                                snprintf(ObjAddress, 50, "%llx", AttackerID);
                                                AttackerIDStr = ObjAddress;

                                                TmpChild["type"] = type;
                                                TmpChild["AttackerID"] = AttackerIDStr;
                                                TmpChild["Name"] = ActorNameStr;
                                                TmpChild["GuildName"] = GuildNameStr;
                                                TmpChild["GuildName2"] = GuildName2Str;
                                                
                                                TmpChild["NowHP"] = ActorHp;
                                                TmpChild["MaxHP"] = ActorMaxHp;

                                                TmpChild["IsDeadState"] = IsDead;
                                                TmpChild["ISNpc"] = ISNpc;
                                                TmpChild["IsAttackMe"] = IsAttackMe;
                                                

                                                TmpChild["x"] = PosX;
                                                TmpChild["y"] = PosY;
                                                TmpChild["z"] = PosZ;
                                                ResultJson.append(TmpChild);
                                                HaveData = 1;

                                                ActorList[ActorCount].IsUsed = 1;
                                                ActorList[ActorCount].ActorProxyPointer = Agent;
                                                ActorList[ActorCount].ObjectID = AgentID;
                                                ActorList[ActorCount].XCoor = PosX;
                                                ActorList[ActorCount].YCoor = PosY;
                                                ActorList[ActorCount].ZCoor = PosZ;
                                                ActorList[ActorCount].Type = type;
                                                ActorList[ActorCount].IsNpc = ISNpc;
                                                ActorList[ActorCount].NowHP = ActorHp;
                                                ActorList[ActorCount].MaxHP = ActorMaxHp;
                                                ActorList[ActorCount].IsAttackMe = IsAttackMe;


                                                memset(ActorList[ActorCount].Guildname, '\0', 500);
                                                snprintf(ActorList[ActorCount].Guildname, 500, "%s", GuildNameStr.c_str());
                                                memset(ActorList[ActorCount].name, '\0', 500);
                                                snprintf(ActorList[ActorCount].name, 500, "%s", ActorNameStr.c_str());
                                                ActorCount = ActorCount + 1;
                                            }



                                        }






                                    }
                                    catch (const char* e1) {
                                        GENERAL_PRINT("[+]F10 Error Catch : %s", e1);
                                    }
                                }
                            }

                        }
                    }
                    
                    
                }
              
            }

        }
    }

    Json::FastWriter writer;
    std::string TmpResultStr = "[]";
    if (HaveData == 1) {
        TmpResultStr = writer.write(ResultJson);
    }

    return TmpResultStr;

}



void SetNoAttackList() {
    char ComparingName[500];
    char* BlurrySearchPos;

    //GENERAL_PRINT("[+]SetNoAttackList  \n");

    for (int i = 0; i < 1500; i++)
    {
        if (ActorList[i].IsUsed == 1) {
            if (ActorList[i].IsNpc == 1 ) {
                if (DontAttackSwitch == 1) {
                    //  GENERAL_PRINT("[+]DontAttackListCount = %d \n", DontAttackListCount);

                    if (DontAttackListCount > 0) {
                        for (int j = 1; j <= DontAttackListCount; j++) {
                            if (DontAttackList[j].IsUsed == 1) {

                                //    GENERAL_PRINT("[+]DontAttackList[j].name = %s \n", DontAttackList[j].name.c_str());

                                int NeedChange = 0;
                                if (strstr(DontAttackList[j].name.c_str(), "#")) {
                                    memset(ComparingName, 0, 500);
                                    strcpy(ComparingName, DontAttackList[j].name.c_str());
                                    BlurrySearchPos = strstr(ComparingName, "#");
                                    if (BlurrySearchPos)
                                    {
                                        *BlurrySearchPos = (char)0;
                                    }
                                    if (strstr(ActorList[i].name, ComparingName)) {
                                        NeedChange = 1;
                                    }
                                }
                                if (strcmp(ActorList[i].name, DontAttackList[j].name.c_str()) == 0) {
                                    NeedChange = 1;
                                }

                                if (NeedChange == 1) {

                                    __uint64_t v6 = rU64(ActorList[i].ActorProxyPointer, 16);
                                    __uint64_t v24 = rU64(ActorList[i].ActorProxyPointer, 8);
                                    if (v24 != 0 && v6 != 0) {// && ISNpc == 1
                                            //__uint64_t v4 = *(__uint64_t*)(Agent + Npc2nameOffset);  // Npc::GetRecordName@<GameRecord2::Npc2::name((GameRecord2::Npc2 *)(result + 744));
                                        __uint64_t GameRecord2_Npc2 = rU64(v24, Npc2nameOffset);
                                        DEBUG_PRINT("[+] IsDead  = %d  ", IsDead);
                                        if (GameRecord2_Npc2 != 0) {
                                            __uint64_t Npc2id = rU64(GameRecord2_Npc2, 0);
                                            
                                           
                                            int IsAdded = 0;
                                            for (int k = 0; k < 3000; k++)
                                            {
                                                if (ChangedDontAttackList[k].IsUsed == 1) {
                                                    if (strcmp(ActorList[i].name, ChangedDontAttackList[k].name.c_str()) == 0) {
                                                        if (Npc2id == ChangedDontAttackList[k].FXNpcGroupDataID) {
                                                            IsAdded = 1;
                                                        }
                                                    }
                                                }
                                            }
                                            
                                            if (IsAdded == 0) {
                                                GENERAL_PRINT("[+]DontAttackList[j].name = %s Npc2id = %lld IsAdded =%d \n", DontAttackList[j].name.c_str(), Npc2id, IsAdded);
                                                for (int k = 0; k < 3000; k++)
                                                {
                                                    if (ChangedDontAttackList[k].IsUsed == 0) {
                                                        ChangedDontAttackList[k].IsUsed = 1;
                                                        ChangedDontAttackList[k].name = ActorList[i].name;
                                                        ChangedDontAttackList[k].OriginVal = *(char*)(GameRecord2_Npc2 + GameRecord2_Npc2_CannotBeTargetedOffSet);
                                                        ChangedDontAttackList[k].FXNpcGroupDataID = Npc2id;
                                                        ChangedDontAttackList[k].GameRecord2_Npc2 = GameRecord2_Npc2;
                                                        GENERAL_PRINT("[+]ChangedDontAttackList[k].OriginVal  =%d \n", ChangedDontAttackList[k].OriginVal);
                                                        break;
                                                    }
                                                }
                                                *(char*)(GameRecord2_Npc2 + 504) = 1;// UXTargetManager::IsBelowMobGradeLimit   if ( !v13 || *((_BYTE *)v13 + 20) != 1 || (*((_BYTE *)a2 + 216) & 2) != 0 )      
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void GetBlackNoAttackList() {

    Json::Value ResultJson;
    int HaveData = 0;
    for (int k = 0; k < 3000; k++)
    {
        if (ChangedDontAttackList[k].IsUsed == 1) {
            Json::Value TmpChild;
            std::string ActorNameStr = "";
            TmpChild["id"] = k;
            ActorNameStr = ChangedDontAttackList[k].name;
            TmpChild["Name"] = ActorNameStr;
            ResultJson.append(TmpChild);
            HaveData = 1;
        }
    }
    Json::FastWriter writer;
    std::string TmpResultStr = "[]";
    if (HaveData == 1) {
        TmpResultStr = writer.write(ResultJson);
    }
    GlobalResultStr = TmpResultStr;
}

void ResetBlackNoAttackList() {

    int IsAdded = 0;

    GENERAL_PRINT("[+] Restore Original NoAttack ");


    for (int k = 0; k < 3000; k++)
    {
        if (ChangedDontAttackList[k].IsUsed == 1) {
            __uint64_t Npc2id = rU64(ChangedDontAttackList[k].GameRecord2_Npc2, 0);
            if (Npc2id == ChangedDontAttackList[k].FXNpcGroupDataID) {
                *(char*)(ChangedDontAttackList[k].GameRecord2_Npc2 + GameRecord2_Npc2_CannotBeTargetedOffSet) = ChangedDontAttackList[k].OriginVal;// UXTargetManager::IsBelowMobGradeLimit   if ( !v13 || *((_BYTE *)v13 + 20) != 1 || (*((_BYTE *)a2 + 216) & 2) != 0 )
            }
            ChangedDontAttackList[k].IsUsed = 0;
        }
    }

}

void hookall()
{



    if (MH_Initialize() != MH_OK)
    {
        DEBUG_PRINT("[+] MH_Initialize Error");
        return;
    }


    void* ClientToScreen_addrs = GetProcAddress(GetModuleHandle(TEXT("user32.dll")), "ClientToScreen");

    DEBUG_PRINT("[+]ClientToScreen_addrs = %x", ClientToScreen_addrs);

    if (ClientToScreen_addrs)
    {
        if (MH_CreateHook((void*)ClientToScreen_addrs, &fake_ClientToScreen, reinterpret_cast<void**>(&old_ClientToScreen)) != MH_OK)
        {
            DEBUG_PRINT(" [+] ClientToScreen HOOK  Error");
            return;
        }
        if (MH_EnableHook((void*)ClientToScreen_addrs) != MH_OK)            //雄HOOK
        {
            DEBUG_PRINT("[+]MH_EnableHook ClientToScreen Error");
            return;
        }
    }


    void* GetCursorPos_addrs = GetProcAddress(GetModuleHandle(TEXT("user32.dll")), "GetCursorPos");
    DEBUG_PRINT("[+] GetCursorPos_addrs = %x", GetCursorPos_addrs);
    if (GetCursorPos_addrs)
    {
        if (MH_CreateHook((void*)GetCursorPos_addrs, &fake_GetCursorPos, reinterpret_cast<void**>(&old_GetCursorPos)) != MH_OK)
        {
            DEBUG_PRINT("[+] GetCursorPos HOOK  Error");
            return;
        }

        if (MH_EnableHook((void*)GetCursorPos_addrs) != MH_OK)            //启动HOOK
        {
            DEBUG_PRINT("[+] MH_EnableHook GetCursorPos Error");
            return;
        }
    }

}
void HideDll2(HMODULE hModule) {

    BYTE shellcode[0x1000];
    memset(shellcode, 0, 0x1000);

    WriteProcessMemory(GetCurrentProcess(), (LPVOID)hModule, shellcode, 0x1000, NULL);  //頭0x1000BYTE 清空

}

#define _WIN32_WINNT 0x0400
#pragma comment( lib, "user32.lib" )

#include <windows.h>
#include <stdio.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    std::wstring user_name = L"myown1";
    std::thread* th1;
    int i;

    /*
    DEBUG_PRINT("[+]PID=%d\n", GetCurrentProcessId());

    std::string String1 = "治癒藥水#";
    std::string String2 = "治癒藥水";
    std::string String3 = "強力治癒藥水";
    std::string String4 = "治癒藥水(刻印)";

    DEBUG_PRINT("[+] CompareName 1 =%d\n", CompareName(String1, String2));
    DEBUG_PRINT("[+] CompareName 2 =%d\n", CompareName(String1, String3));
    DEBUG_PRINT("[+] CompareName 3 =%d\n", CompareName(String1, String4));
    */
   // DEBUG_PRINT("[+]ul_reason_for_call=%d\n", ul_reason_for_call);



    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
       
        DEBUG_PRINT("[+]Enter dll\n");



       th1 = new std::thread(CreateNewSocket, 123);
       th1 = new std::thread(UIThread, 123);

       InitFMem(&FixedFNameMem);
       InitFMem(&FixedAllChildWidgetMem);
       InitFMem(&FixedAllChildWidgetMemB);
       InitFMem(&FixedAllChildWidgetMemC);
       for (i = 0; i < 1000; i++)
       {
           BagItem[i].IsUsed = 0;
           EffectData[i].IsUsed = 0;
       }

       HideDll2(hModule);

      //  Sleep(1000);
       // GetBaseAddress();
        DEBUG_PRINT("[+]Leave 123\n");
      //  MessageBox(NULL, user_name.c_str(), TEXT("caption"), 0);
        DEBUG_PRINT("[+]Leave 1213\n");
        //InitHook();
        //HookNormalFunByAddr(0, (__uint64_t)free, (void*)&mmemcmp, &old_memcmp);  //



        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}







