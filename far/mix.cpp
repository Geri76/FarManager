/*
mix.cpp

���� ������ ��������������� �������

*/

/* Revision: 1.80 17.06.2001 $ */

/*
Modify:
  17.06.2001 IS
    - ��� � ExpandEnvironmentStr: �� ����������� ��, ���
      ExpandEnvironmentStrings ���������� �������� ���������� ��������� � ANSI
      ������ ���������� ��������������� �������������, �����
      ExpandEnvironmentStr ���������� ������ � OEM, � �� � ��������� ���������.
  14.06.2001 KM
    ! ��������� ������� ����. ����� ������ ������.
  08.06.2001 SVS
    + �������� ���� ����� ���������� ����-�� ��������, ��� �� ������� ������
      ������� �����������.
  30.05.2001 SVS
    ! ShellCopy::CreatePath �������� �� ������ � �������� ������� CreatePath()
  21.05.2001 OT
    ! ����������� ��������� ������� ������� � Execute()
  17.05.2001 SKV
    + ��� detach console ������ ���� ������ "��������" hotkey
    - ���� ��� detach console ������ "������" ctrl,alt,shift,
      �� ����������� �� ������.
  06.05.2001 DJ
    ! �������� #include
  29.04.2001 ��
    + ��������� NWZ �� ����������
  01.05.2001 SVS
    ! mktemp - ������� ����� ��������� ������ � ������� �������� (strupr)
  28.04.2001 VVM
    + GetSubstName() ��������� ��� ��������
  24.04.2001 SVS
    - ���� � ��������� (� ������ DJ)
  13.04.2001 VVM
    + ���� CREATE_DEFAULT_ERROR_MODE ��� CreateProcess.
  08.06.2001 SVS
    ! � Add_PATHEXT() ���������� ���������������� GetCommaWord().
    ! ExpandPATHEXT() ������� �� �������������.
    ! � ExpandEnvironmentStr(), ConvertNameToFull()
      ��������� alloca() ������ malloc().
  06.06.2001 SVS
    + ExpandPATHEXT() - ���������� ���������� ����� � ������ %PATHEXT%
      ��� ���� �������� %PATHEXT% �������� � ���������� �������.
  03.04.2001 SVS
    + Add_PATHEXT()
  30.03.2001 SVS
    + FarGetLogicalDrives - �������� ������ GetLogicalDrives, � ������
      ������� ���������� ������
  24.03.2001 tran
    + qsortex
  20.03.2001 tran
    + FarRecursiveSearch - �������� void *param
  20.03.2001 SKV
    - ��� ���� ���� � �������� ������� ��� ������.
  16.03.2001 SVS
    + ������� DriveLocalToRemoteName() - �������� �� ����� ����� RemoteName
  15.03.2001 SKV
    - ���� � �������� ������� ��� detach far console.
  12.03.2001 SVS
    ! ��������� � ����� � ����������� � ������ int64
  02.03.2001 IS
    ! ��������� ExpandEnvironmentStr, ��� �� ����������� ��� ��� - ����� ����
      ���������� �����.
  21.02.2001 VVM
    ! GetFileOwner()::��� ��/2000 ���������� Needed ���������������
      ���������� �� ���������.
  14.02.2001 SKV
    ! ��������� ����� ��������� �������.
  12.02.2001 SKV
    + ��������� ���-������ ������� �� ����������������
       �������� � ��� �����������.
  23.01.2001 SVS
    ! ExpandEnvironmentStr ����� ����������� �������� ������...
    ! ��������� ����� ������� VK_F16 ��� ������������ ����!
  23.01.2001 SVS
    ! ������� ��������� ������ �������� ���������� ������ �
      ExpandEnvironmentStr()
  21.01.2001 SVS
    ! ������� GetString - ��������� � stddlg.cpp
  05.01.2001 SVS
    ! ������� GetSubstName - ��������� � flink.cpp
    ! ������� InsertCommas, PointToName, GetPathRoot, CmpName, ConvertWildcards,
      QuoteSpace, QuoteSpaceOnly, TruncStr, TruncPathStr, Remove???Spaces,
      HiStrlen, AddEndSlash, NullToEmpty, CenterStr, GetCommaWord,
      RemoveHighlights, IsCaseMixed, IsCaseLower, Unquote,
      ��������� � strmix.cpp
  03.01.2001 SVS
    ! ������� SetFarTitle, ScrollBar, ShowSeparator
      ��������� � interf.cpp
    ! ������� MkLink, GetNumberOfLinks
      ��������� � flink.cpp
  03.01.2001 SVS
    ! ConvertDate - ����������� �������� ������� (���� �� �� ���� ���������)
  22.12.2000 SVS
    ! ������� ��������� ����:
      KeyNameToKey -> keyboard.cpp
      InputRecordToKey -> keyboard.cpp
      KeyToText -> keyboard.cpp
      ���, ��� �������� SysLog -> syslog.cpp
      Eject -> eject.cpp
      Xlat  -> xlat.cpp
      *Clipboard* -> clipboard.cpp
  21.12.2000 SVS
    + KEY_DTDAY, KEY_DTMONTH, KEY_DTYEAR - ��������� ���������� � �������� :-)
  14.12.2000 SVS
    + �������� ��� ��� ���������� Eject ������� ��������� ���
      Win9x & WinNT/2K
  06.12.2000 IS
    ! ������ ������� AddEndSlash �������� � ������ ������ ������, �����
      ���������� ��������� ��� ������������� ��������� ����� �� �����, �������
      ����������� ����.
  24.11.2000 SVS
    ! XLat ������� ��������� ����������� :-))) ��� �� �� �������� �� �������!
  08.11.2000 SVS
    - ���� � ������� ConvertNameToFull.
  04.11.2000 SVS
    + XLAT_SWITCHKEYBBEEP � XLat �������������.
    ! ��������� �������� � FarBsearch, InputRecordToKey, FarQsort, FarSprintf,
      FarAtoi64, FarAtoi, FarItoa64, FarItoa, KeyNameToKey, KeyToText,
      FarSscanf, AddEndSlash, RemoveTrailingSpaces, RemoveLeadingSpaces,
      TruncStr, TruncPathStr, QuoteSpaceOnly
  03.11.2000 OT
    ! ����������� ����������� ������� ��������
  02.11.2000 OT
    ! �������� �������� �� ����� ������, ����������� ��� ��� �����.
  26.10.2000 SVS
    ! � MkTemp ������� ����� ������� ���������� � ANSI
  25.10.2000 SVS
    ! ��������� OpenLogStream
    ! � MkTemp ������� ����� ���� � �� ������, ��� ��� ��������� � ANSI
  25.10.2000 IS
    ! ������� mktemp �� ����� ��������������� ������� �������, �.�. ����������
      ������� �������� � ������ (�������� �� Multiarc'�)
  23.10.2000 SVS
    ! ����������� ������ SysLog :-)
      ���������� � ������� ���������� ����� AT ;-)
  20.10.2000 SVS
    ! ProcessName: Flags ������ ���� DWORD, � �� int
  20.10.2000 SVS
    + SysLog
  16.10.2000 tran
    + PasteFromClipboardEx(int max);
  09.10.2000 IS
    + ����� ������� ��� ��������� ����� �����: ProcessName, ConvertWildcards
  27.09.2000 skv
    + DeleteBuffer. ������� ��, ��� ������ PasteFromClipboard.
  24.09.2000 SVS
    + ������� KeyNameToKey - ��������� ���� ������� �� �����
      ���� ��� �� ����� ��� ��� ������ - ������������ -1
  20.09.2000 SVS
    ! ������ FolderPresent (����, ������ ����� ������� :-(
  20.09.2000 SVS
    ! ��������� � ������� Xlat()
  19.09.2000 SVS
    + ������� FolderPresent - "���������� �� �������"
  19.09.2000 SVS
    + IsFolderNotEmpty ������� "�������"
    ! ������� FarMkTemp - ���������!
  18.09.2000 skv
    + � IsCommandExeGUI �������� �� ������� .bat � .cmd � ���. ����������
  18.09.2000 SVS
    ! FarRecurseSearch -> FarRecursiveSearch
    ! ����������� �������� � ������� FarMkTemp :-)))
  14.09.2000 SVS
    + ������� FarMkTemp - ��������� ����� ���������� ����� � ������ �����.
  10.09.2000 SVS
    ! KeyToText ���������� BOOL
  10.09.2000 tran
    + FSF/FarRecurseSearch
  10.09.2000 SVS
    ! �������-�� ������� ���������� ��� ��� QWERTY -> Xlat.
  08.09.2000 SVS
    - QWERTY - �������� ������� :-)))
    ! QWERTY -> Transliterate
    ! QWED_SWITCHKEYBLAYER -> EDTR_SWITCHKEYBLAYER
    + KEY_CTRLSHIFTDEL, KEY_ALTSHIFTDEL
  07.09.2000 SVS
    + ������� GetFileOwner ���� �������� �������� :-)
    + ������� GetNumberOfLinks ���� �������� �������� :-)
    + �������� FarBsearch ��� �������� (������� bsearch)
  05.09.2000 SVS 1.19
    + QWERTY - ������� ������������� QWERTY<->������
  31.08.2000 tran 1.18
    + InputRecordToKey
  29.08.2000 SVS
    - ������� ������������ ������� FarSscanf
  28.08.2000 SVS
    ! ��������� ��� FarQsort
    ! �� FarAtoa64, �� FarAtoi64
    + FarItoa64
  25.08.2000 SVS
    ! ������� GetString ����� ��� �������������� ����� (FIB_BUTTONS) ����������
      ��������� � ������ <Ok> & <Cancel>
  24.08.2000 SVS
    + � ������� KeyToText ��������� ��������� ������
      KEY_CTRLALTSHIFTPRESS, KEY_CTRLALTSHIFTRELEASE
  09.08.2000 SVS
    + FIB_NOUSELASTHISTORY - ���� ��� ������������� ���� �������� ��
      ������� �������� ��������!!! (int function GetString())
  01.08.2000 SVS
    ! ������� ����� ������ GetString ����� ���� �������� ��� ���� ������
    ! �������������� ��������� � KeyToText - ������ ������
  31.07.2000 SVS
    ! ������� GetString ����� ��� ���� �������� - ��������� �� ���������� �����!
    ! ���� � GetString ������ History, �� ����������� ��� � DIF_USELASTHISTORY
  25.07.2000 SVS
    ! ������� KeyToText ������� ���������������� - ����� � ������ FSF
    ! �������, ���������� � ������ FSF ������ ����� WINAPI!!!
  23.07.2000 SVS
    ! ������� GetString ����� ����� WINAPI
  18.07.2000 tran 1.08
    ! ������� ���� ��������� � ScrollBar
  13.07.2000 IG
    - � VC, ������, ������ ������� ���: 0x4550 == 'PE', ����
      ������ �������� ��������� (������� IsCommandExeGUI)
  13.07.2000 SVS
    ! ��������� ��������� ��� ������������� new/delete/realloc
  11.07.2000 SVS
    ! ��������� ��� ����������� ���������� ��� BC & VC
  07.07.2000 tran
    - trap under win2000, or console height > 210
      bug was in ScrollBar ! :)))
  07.07.2000 SVS
    + �������������� ������� ��������� �����: RemoveExternalSpaces
    ! ������� ��� 2-� �������:
        RemoveLeadingSpaces
        RemoveTrailingSpaces
      ���������� char*
  05.07.2000 SVS
    + ��������� ������� ExpandEnvironmentStr
  28.06.2000 IS
    ! ������� Unquote ����� �������������
  25.06.2000 SVS
    ! ���������� Master Copy
    ! ��������� � �������� ���������������� ������
*/

#include "headers.hpp"
#pragma hdrstop

#include "plugin.hpp"
#include "global.hpp"
#include "fn.hpp"
#include "flink.hpp"
#include "treelist.hpp"
#include "lang.hpp"
#include "keys.hpp"
#include "savefpos.hpp"
#include "chgprior.hpp"
#include "filepanels.hpp"
#include "panel.hpp"
#include "scantree.hpp"
#include "savescr.hpp"
#include "ctrlobj.hpp"
#include "scrbuf.hpp"

static DWORD IsCommandExeGUI(char *Command);

long filelen(FILE *FPtr)
{
  SaveFilePos SavePos(FPtr);
  fseek(FPtr,0,SEEK_END);
  return(ftell(FPtr));
}


DWORD NTTimeToDos(FILETIME *ft)
{
  WORD DosDate,DosTime;
  FILETIME ct;
  FileTimeToLocalFileTime(ft,&ct);
  FileTimeToDosDateTime(&ct,&DosDate,&DosTime);
  return(((DWORD)DosDate<<16)|DosTime);
}


void ConvertDate(FILETIME *ft,char *DateText,char *TimeText,int TimeLength,
                 int Brief,int TextMonth,int FullYear,int DynInit)
{
  static int WDateFormat,WDateSeparator,WTimeSeparator;
  static int Init=FALSE;
  static SYSTEMTIME lt;
  int DateFormat,DateSeparator,TimeSeparator;
  if (!Init)
  {
    WDateFormat=GetDateFormat();
    WDateSeparator=GetDateSeparator();
    WTimeSeparator=GetTimeSeparator();
    GetLocalTime(&lt);
    Init=TRUE;
  }
  DateFormat=DynInit?GetDateFormat():WDateFormat;
  DateSeparator=DynInit?GetDateSeparator():WDateSeparator;
  TimeSeparator=DynInit?GetTimeSeparator():WTimeSeparator;

  int CurDateFormat=DateFormat;
  if (Brief && CurDateFormat==2)
    CurDateFormat=0;

  SYSTEMTIME st;
  FILETIME ct;

  if (ft->dwHighDateTime==0)
  {
    if (DateText!=NULL)
      *DateText=0;
    if (TimeText!=NULL)
      *TimeText=0;
    return;
  }

  FileTimeToLocalFileTime(ft,&ct);
  FileTimeToSystemTime(&ct,&st);

  if (TimeText!=NULL)
  {
    char *Letter="";
    if (TimeLength==6)
    {
      Letter=(st.wHour<12) ? "a":"p";
      if (st.wHour>12)
        st.wHour-=12;
      if (st.wHour==0)
        st.wHour=12;
    }
    if (TimeLength<7)
      sprintf(TimeText,"%02d%c%02d%s",st.wHour,TimeSeparator,st.wMinute,Letter);
    else
    {
      char FullTime[100];
      sprintf(FullTime,"%02d%c%02d%c%02d.%03d",st.wHour,TimeSeparator,
              st.wMinute,TimeSeparator,st.wSecond,st.wMilliseconds);
      sprintf(TimeText,"%.*s",TimeLength,FullTime);
    }
  }

  if (DateText!=NULL)
  {
    int Year=st.wYear;
    if (!FullYear)
      Year%=100;
    if (TextMonth)
    {
      char *Month=MSG(MMonthJan+st.wMonth-1);
      switch(CurDateFormat)
      {
        case 0:
          sprintf(DateText,"%3.3s %2d %02d",Month,st.wDay,Year);
          break;
        case 1:
          sprintf(DateText,"%2d %3.3s %02d",st.wDay,Month,Year);
          break;
        default:
          sprintf(DateText,"%02d %3.3s %2d",Year,Month,st.wDay);
          break;
      }
    }
    else
      switch(CurDateFormat)
      {
        case 0:
          sprintf(DateText,"%02d%c%02d%c%02d",st.wMonth,DateSeparator,st.wDay,DateSeparator,Year);
          break;
        case 1:
          sprintf(DateText,"%02d%c%02d%c%02d",st.wDay,DateSeparator,st.wMonth,DateSeparator,Year);
          break;
        default:
          sprintf(DateText,"%02d%c%02d%c%02d",Year,DateSeparator,st.wMonth,DateSeparator,st.wDay);
          break;
      }
  }

  if (Brief)
  {
    DateText[TextMonth ? 6:5]=0;
    if (lt.wYear!=st.wYear)
      sprintf(TimeText,"%5d",st.wYear);
  }
}


int GetDateFormat()
{
  char Info[100];
  GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_IDATE,Info,sizeof(Info));
  return(atoi(Info));
}


int GetDateSeparator()
{
  char Info[100];
  GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_SDATE,Info,sizeof(Info));
  return(*Info);
}


int GetTimeSeparator()
{
  char Info[100];
  GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_STIME,Info,sizeof(Info));
  return(*Info);
}


int Execute(char *CmdStr,int AlwaysWaitFinish,int SeparateWindow,int DirectRun)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  char ExecLine[1024],CommandName[NM];
  char OldTitle[512];
  int ExitCode;
  /* $ 13.04.2001 VVM
    + ���� CREATE_DEFAULT_ERROR_MODE. ���-�� ��������� ��� ������ */
  DWORD CreateFlags=CREATE_DEFAULT_ERROR_MODE;
  /* VVM $ */

  int Visible,Size;
  GetCursorType(Visible,Size);
  SetCursorType(TRUE,-1);

  int PrevLockCount=ScrBuf.GetLockCount();
  ScrBuf.SetLockCount(0);
  ScrBuf.Flush();

  ChangePriority ChPriority(THREAD_PRIORITY_NORMAL);

  GetConsoleTitle(OldTitle,sizeof(OldTitle));
  memset(&si,0,sizeof(si));
  si.cb=sizeof(si);

  int NT=WinVer.dwPlatformId==VER_PLATFORM_WIN32_NT;
  int OldNT=NT && WinVer.dwMajorVersion<4;

  *CommandName=0;
  GetEnvironmentVariable("COMSPEC",CommandName,sizeof(CommandName));

  /* $ 14.06.2001 KM
     ! ��������� ����� ���� �� ����� � ����� ��������� � ���������
       ������� ���������� ����� �������.
  */
/*  Panel *PassivePanel=CtrlObject->Cp()->GetAnotherPanel(CtrlObject->Cp()->ActivePanel);
  if (WinVer.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS &&
      PassivePanel->GetType()==FILE_PANEL)
    for (int I=0;CmdStr[I]!=0;I++)
      if (isalpha(CmdStr[I]) && CmdStr[I+1]==':' && CmdStr[I+2]!='\\')
      {
        char SavePath[NM],PanelPath[NM],SetPathCmd[NM];
        GetCurrentDirectory(sizeof(SavePath),SavePath);
        PassivePanel->GetCurDir(PanelPath);
        sprintf(SetPathCmd,"%s /C chdir %s",CommandName,QuoteSpace(PanelPath));
        CreateProcess(NULL,SetPathCmd,NULL,NULL,FALSE,CreateFlags,NULL,NULL,&si,&pi);
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
        chdir(SavePath);
      }*/
  /* KM $ */

  char *CmdPtr=CmdStr;
//  while (isspace(*CmdPtr))
//    CmdPtr++;

  DWORD GUIType=IsCommandExeGUI(CmdPtr);

  if (DirectRun && !SeparateWindow)
    strcpy(ExecLine,CmdPtr);
  else
  {
    sprintf(ExecLine,"%s /C",CommandName);
    if (!OldNT && (SeparateWindow || GUIType && (NT || AlwaysWaitFinish)))
    {
      strcat(ExecLine," start");
      if (AlwaysWaitFinish)
        strcat(ExecLine," /wait");
      if (NT && *CmdPtr=='\"')
        strcat(ExecLine," \"\"");
    }
    strcat(ExecLine," ");
    char *CmdEnd=CmdPtr+strlen (CmdPtr)-1;
    if (NT && *CmdPtr == '\"' && *CmdEnd == '\"' && strchr (CmdPtr+1, '\"') != CmdEnd)
    {
      strcat (ExecLine, "\"");
      strcat (ExecLine, CmdPtr);
      strcat (ExecLine, "\"");
    }
    else
      strcat(ExecLine,CmdPtr);
  }

  SetFarTitle(CmdPtr);
  FlushInputBuffer();

  /*$ 15.03.2001 SKV
    ���� ��������� ��������� ������� �� ������ � �.�.
  */
  CONSOLE_SCREEN_BUFFER_INFO sbi;
  GetConsoleScreenBufferInfo(hConOut,&sbi);
  /* SKV$*/

  ChangeConsoleMode(InitialConsoleMode);

  if (SeparateWindow && OldNT)
    CreateFlags|=CREATE_NEW_CONSOLE;


  if (SeparateWindow==2)
  {
    char AnsiLine[NM];
    SHELLEXECUTEINFO si;
    OemToChar(CmdPtr,AnsiLine);

    if (PointToName(AnsiLine)==AnsiLine)
    {
      char FullName[2*NM];
      sprintf(FullName,".\\%s",AnsiLine);
      strcpy(AnsiLine,FullName);
    }

    memset(&si,0,sizeof(si));
    si.cbSize=sizeof(si);
    si.fMask=SEE_MASK_NOCLOSEPROCESS|SEE_MASK_FLAG_DDEWAIT;
    si.lpFile=AnsiLine;
    si.lpVerb=GetShellAction((char *)si.lpFile);
    si.nShow=SW_SHOWNORMAL;
    SetFileApisToANSI();
    ExitCode=ShellExecuteEx(&si);
    SetFileApisToOEM();
    pi.hProcess=si.hProcess;
  }
  else
    ExitCode=CreateProcess(NULL,ExecLine,NULL,NULL,0,CreateFlags,
                           NULL,NULL,&si,&pi);

  StartExecTime=clock();
  if (ExitCode)
  {
    if (!SeparateWindow && !GUIType || AlwaysWaitFinish)
    {
      /*$ 12.02.2001 SKV
        ����� ����� ;)
        ��������� ��������� ������� �� ���������������� ��������.
        ������� ������� � System/ConsoleDetachKey
      */
      if(Opt.ConsoleDetachKey>0)
      {
        HANDLE h[2];
        HANDLE hConOut=GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hConInp=GetStdHandle(STD_INPUT_HANDLE);
        h[0]=pi.hProcess;
        h[1]=hConInp;
        INPUT_RECORD ir[256];
        DWORD rd;

        int vkey=0,ctrl=0;
        TranslateKeyToVK(Opt.ConsoleDetachKey,vkey,ctrl,NULL);
        int alt=ctrl&PKF_ALT;
        int shift=ctrl&PKF_SHIFT;
        ctrl=ctrl&PKF_CONTROL;

        while(WaitForMultipleObjects(2,h,FALSE,INFINITE)!=WAIT_OBJECT_0)
        {
          if(PeekConsoleInput(h[1],ir,256,&rd) && rd)
          {
            int stop=0;
            for(int i=0;i<rd;i++)
            {
              PINPUT_RECORD pir=&ir[i];
              if(pir->EventType==KEY_EVENT)
              {
                if(vkey==pir->Event.KeyEvent.wVirtualKeyCode &&
                  (alt?(pir->Event.KeyEvent.dwControlKeyState&LEFT_ALT_PRESSED || pir->Event.KeyEvent.dwControlKeyState&RIGHT_ALT_PRESSED):!(pir->Event.KeyEvent.dwControlKeyState&LEFT_ALT_PRESSED || pir->Event.KeyEvent.dwControlKeyState&RIGHT_ALT_PRESSED)) &&
                  (ctrl?(pir->Event.KeyEvent.dwControlKeyState&LEFT_CTRL_PRESSED || pir->Event.KeyEvent.dwControlKeyState&RIGHT_CTRL_PRESSED):!(pir->Event.KeyEvent.dwControlKeyState&LEFT_CTRL_PRESSED || pir->Event.KeyEvent.dwControlKeyState&RIGHT_CTRL_PRESSED)) &&
                  (shift?(pir->Event.KeyEvent.dwControlKeyState&SHIFT_PRESSED):!(pir->Event.KeyEvent.dwControlKeyState&SHIFT_PRESSED))
                  )
                {

                  HICON hSmallIcon=NULL,hLargeIcon=NULL;
                  if(hFarWnd)
                  {
                    hSmallIcon=CopyIcon((HICON)SendMessage(hFarWnd,WM_SETICON,0,(LPARAM)0));
                    hLargeIcon=CopyIcon((HICON)SendMessage(hFarWnd,WM_SETICON,1,(LPARAM)0));
                  }
                  ReadConsoleInput(hConInp,ir,256,&rd);
                  CloseConsole();
                  FreeConsole();
                  AllocConsole();

                  /*$ 17.05.2001 SKV
                    ���� ���� ����� HOTKEY, �� ������ ������ ��� ������.
                  */
                  if(hFarWnd)
                  {
                    SendMessage(hFarWnd,WM_SETHOTKEY,0,(LPARAM)0);
                  }
                  /* SKV$*/


                  /*$ 20.03.2001 SKV
                    ��� ����� ��� ������ :-\
                  */
                  SetConsoleScreenBufferSize(hConOut,sbi.dwSize);
                  SetConsoleWindowInfo(hConOut,TRUE,&sbi.srWindow);
                  SetConsoleScreenBufferSize(hConOut,sbi.dwSize);

                  /* SKV$*/

                  Sleep(100);
                  InitConsole(0);

                  hFarWnd=0;
                  InitDetectWindowedMode();

                  if (hFarWnd)
                  {
                    if(Opt.SmallIcon)
                    {
                      char FarName[NM];
                      GetModuleFileName(NULL,FarName,sizeof(FarName));
                      ExtractIconEx(FarName,0,&hLargeIcon,&hSmallIcon,1);
                    }
                    if (hLargeIcon!=NULL)
                      SendMessage(hFarWnd,WM_SETICON,1,(LPARAM)hLargeIcon);
                    if (hSmallIcon!=NULL)
                      SendMessage(hFarWnd,WM_SETICON,0,(LPARAM)hSmallIcon);
                  }

                  stop=1;
                  break;
                }
              }
            }
            if(stop)break;
          }
          Sleep(100);
        }
      }
      else
      {
        WaitForSingleObject(pi.hProcess,INFINITE);
      }
      /* SKV$*/
    }
    int CurScrX=ScrX,CurScrY=ScrY;
//    ReopenConsole();

//OT    GetVideoMode();
//OT    if (CurScrX!=ScrX || CurScrY!=ScrY)
//OT      CtrlObject->Cp()->SetScreenPositions();
    GetExitCodeProcess(pi.hProcess,(LPDWORD)&ExitCode);
    if (SeparateWindow!=2)
      CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    ScrBuf.FillBuf();
    ScrBuf.SetLockCount(PrevLockCount);
  }
  else
  {
    if (SeparateWindow!=2)
      Message(MSG_WARNING|MSG_ERRORTYPE,1,MSG(MError),MSG(MCannotExecute),SeparateWindow==2 ? CmdPtr:ExecLine,MSG(MOk));
    ExitCode=-1;
  }
  SetFarConsoleMode();
  GetCursorType(Visible,Size);
  if (WinVer.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS &&
      WinVer.dwBuildNumber<=0x4000457)
    WriteInput(VK_F16,SKEY_VK_KEYS);
  /* ���� ���� �������� ������� �������, ��������
     mode con lines=50 cols=100
     �� ��� �� ���� �� ��������� ������� �������.
     ��� ����� ���� ���� ��������� ������ ��� :-)
  */
  GenerateWINDOW_BUFFER_SIZE_EVENT(-1,-1);
  SetConsoleTitle(OldTitle);
  return(ExitCode);
}


char* GetShellAction(char *FileName)
{
  char Value[80],*ExtPtr;
  LONG ValueSize;
  if ((ExtPtr=strrchr(FileName,'.'))==NULL)
    return(NULL);
  ValueSize=sizeof(Value);
  if (RegQueryValue(HKEY_CLASSES_ROOT,(LPCTSTR)ExtPtr,(LPTSTR)Value,&ValueSize)!=ERROR_SUCCESS)
    return(NULL);
  strcat(Value,"\\shell");

  HKEY hKey;
  if (RegOpenKey(HKEY_CLASSES_ROOT,Value,&hKey)!=ERROR_SUCCESS)
    return(NULL);

  static char Action[80];
  ValueSize=sizeof(Action);
  if (RegQueryValueEx(hKey,"",NULL,NULL,(unsigned char *)Action,(LPDWORD)&ValueSize)!=ERROR_SUCCESS)
    return(NULL);
  RegCloseKey(hKey);
  return(*Action==0 ? NULL:Action);
}


DWORD IsCommandExeGUI(char *Command)
{
  char FileName[4096],FullName[4096],*EndName,*FilePart;
  if (*Command=='\"')
  {
    OemToChar(Command+1,FileName);
    if ((EndName=strchr(FileName,'\"'))!=NULL)
      *EndName=0;
  }
  else
  {
    OemToChar(Command,FileName);
    if ((EndName=strpbrk(FileName," \t/"))!=NULL)
      *EndName=0;
  }
  int GUIType=FALSE;

  SetFileApisToANSI();

  /*$ 18.09.2000 skv
    + to allow execution of c.bat in current directory,
      if gui program c.exe exists somewhere in PATH,
      in FAR's console and not in separate window.
      for(;;) is just to prevent multiple nested ifs.
  */
  for(;;)
  {
    sprintf(FullName,"%s.bat",FileName);
    if(GetFileAttributes(FullName)!=-1)break;
    sprintf(FullName,"%s.cmd",FileName);
    if(GetFileAttributes(FullName)!=-1)break;
  /* skv$*/

    if (SearchPath(NULL,FileName,".exe",sizeof(FullName),FullName,&FilePart))
    {
      SHFILEINFO sfi;
      DWORD ExeType=SHGetFileInfo(FullName,0,&sfi,sizeof(sfi),SHGFI_EXETYPE);
      GUIType=HIWORD(ExeType)>=0x0300 && HIWORD(ExeType)<=0x1000 &&
              /* $ 13.07.2000 IG
                 � VC, ������, ������ ������� ���: 0x4550 == 'PE', ����
                 ������ �������� ���������.
              */
              HIBYTE(ExeType)=='E' && (LOBYTE(ExeType)=='N' || LOBYTE(ExeType)=='P');
              /* IG $ */
    }
/*$ 18.09.2000 skv
    little trick.
*/
    break;
  }
  /* skv$*/
  SetFileApisToOEM();
  return(GUIType);
}


int ToPercent(unsigned long N1,unsigned long N2)
{
  if (N1 > 10000)
  {
    N1/=100;
    N2/=100;
  }
  if (N2==0)
    return(0);
  if (N2<N1)
    return(100);
  return((int)(N1*100/N2));
}



/* $ 09.10.2000 IS
    + ����� ������� ��� ��������� ����� �����
*/
// ���������� ��� �����: �������� � ������, �������, ������������� �� �����
int WINAPI ProcessName(char *param1, char *param2, DWORD flags)
{
 int skippath=flags&PN_SKIPPATH;

 if(flags&PN_CMPNAME)
    return CmpName(param1, param2, skippath);

 if(flags&PN_CMPNAMELIST)
 {
  int Found=FALSE;
  static char FileMask[NM],*MaskPtr;
  MaskPtr=param1;
  while ((MaskPtr=GetCommaWord(MaskPtr,FileMask))!=NULL)
  if (CmpName(FileMask,param2,skippath))
  {
    Found=TRUE;
    break;
  }
  return Found;
 }

 if(flags&PN_GENERATENAME)
    return ConvertWildcards(param1, param2, flags & 0xFF);

 return FALSE;
}
/* IS $ */

/*
void ShowHeap()
{
  _HEAPINFO hi;

  Log( "" );
  Log( "   Size   Status" );
  Log( "   ----   ------" );
  hi._pentry=NULL;
  while( _rtl_heapwalk( &hi ) == _HEAPOK )
    Log( "%7u    %s", hi._size, hi._useflag ? "used" : "free" );
}


void CheckHeap(int NumLine)
{
  if (_heapchk()==_HEAPBADNODE)
  {
    char Line[10];
    sprintf(Line,"%d",NumLine);
    Message(MSG_WARNING,1,MSG(MError),"Heap broken",Line,MSG(MOk));
  }
}


void Log(char *fmt,...)
{
  va_list argptr;
  va_start(argptr,fmt);
  char OutStr[1024];
  vsprintf(OutStr,fmt,argptr);

  char FarFileName[NM];
  GetModuleFileName(NULL,FarFileName,sizeof(FarFileName));
  strcpy(strrchr(FarFileName,'\\')+1,"far.log");
  FILE *LogFile=fopen(FarFileName,"ab");
  if (LogFile!=NULL)
  {
    SYSTEMTIME tm;
    GetLocalTime(&tm);
    fprintf(LogFile,"%02d:%02d:%02d %s\r\n",tm.wHour,tm.wMinute,tm.wSecond,OutStr);
    fclose(LogFile);
  }
  va_end(argptr);
}
*/


/* $ 01.11.2000 OT
  ����������� ������. ������ ������� ������ � ������������ �������
  �������� ������ ������ � ������ ����� ����������� ����� �����.
  ���� ������ ������ ���, �� ����������� �� ����������
*/
void CharBufferToSmallWarn(int BufSize, int FileNameSize)
{
  char Buf2 [80];
  sprintf (Buf2,MSG(MBuffSizeTooSmall_2), FileNameSize, BufSize);
  Message(MSG_WARNING,1,MSG(MWarning),MSG(MBuffSizeTooSmall_1),Buf2,MSG(MOk));
}

int ConvertNameToFull(char *Src,char *Dest, int DestSize)
{
  int Result = 0;
//  char *FullName = (char *) malloc (DestSize);
//  char *AnsiName = (char *) malloc (DestSize);
  char *FullName = (char *) alloca (DestSize);
  char *AnsiName = (char *) alloca (DestSize);
  *((int *)FullName) = 0;
  *((int *)AnsiName) = 0;

//  char FullName[NM],AnsiName[NM],
  char *NamePtr=PointToName(Src);
  Result+=strlen(Src);

  if (NamePtr==Src && (NamePtr[0]!='.' || NamePtr[1]!=0))
  {
    Result+=GetCurrentDirectory(DestSize,FullName);
    Result+=AddEndSlash(FullName);
    if (Result < DestSize) {
      strncat(FullName,Src,Result);
      strncpy(Dest,FullName,Result);
      Dest [Result] = '\0';
    } else {
      CharBufferToSmallWarn(DestSize,Result+1);
    }
    goto end;
  }
  if (isalpha(Src[0]) && Src[1]==':' || Src[0]=='\\' && Src[1]=='\\')
    if (*NamePtr && (*NamePtr!='.' || NamePtr[1]!=0 && (NamePtr[1]!='.' || NamePtr[2]!=0)))
      if (strstr(Src,"\\..\\")==NULL && strstr(Src,"\\.\\")==NULL)
      {
        if (Dest!=Src)
          strcpy(Dest,Src);
        goto end;
      }

  SetFileApisToANSI();
  OemToChar(Src,AnsiName);
  /* $ 08.11.2000 SVS
     ������ DestSize ������������� sizeof(FullName)...
  */
  if (GetFullPathName(AnsiName,DestSize,FullName,&NamePtr))
    CharToOem(FullName,Dest);
  else
    strcpy(Dest,Src);
  /* SVS $*/
  SetFileApisToOEM();
end:
//  free (FullName);
//  free (AnsiName);
  return Result;
}


void ConvertNameToShort(char *Src,char *Dest)
{
  char ShortName[NM],AnsiName[NM];
  SetFileApisToANSI();
  OemToChar(Src,AnsiName);
  if (GetShortPathName(AnsiName,ShortName,sizeof(ShortName)))
    CharToOem(ShortName,Dest);
  else
    strcpy(Dest,Src);
  SetFileApisToOEM();
}


int GetFileTypeByName(char *Name)
{
  HANDLE hFile=CreateFile(Name,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,
                          NULL,OPEN_EXISTING,0,NULL);
  if (hFile==INVALID_HANDLE_VALUE)
    return(FILE_TYPE_UNKNOWN);
  int Type=GetFileType(hFile);
  CloseHandle(hFile);
  return(Type);
}


int GetDirInfo(char *Title,char *DirName,unsigned long &DirCount,
               unsigned long &FileCount,int64 &FileSize,
               int64 &CompressedFileSize,int64 &RealSize,
               unsigned long &ClusterSize,clock_t MsgWaitTime,
               int EnhBreak)
{
  SaveScreen SaveScr;
  ScanTree ScTree(FALSE);
  WIN32_FIND_DATA FindData;
  char FullName[NM];
  int MsgOut=0;
  clock_t StartTime=clock();
  char FullDirName[NM],DriveRoot[NM];

  SetCursorType(FALSE,0);
//  ConvertNameToFull(DirName,FullDirName, sizeof(FullDirName));
  if (ConvertNameToFull(DirName,FullDirName, sizeof(FullDirName)) >= sizeof(FullDirName)){
    return -1;
  }
  GetPathRoot(FullDirName,DriveRoot);

  if ((ClusterSize=GetClusterSize(DriveRoot))==0)
  {
    DWORD SectorsPerCluster=0,BytesPerSector=0,FreeClusters=0,Clusters=0;

    if (GetDiskFreeSpace(DriveRoot,&SectorsPerCluster,&BytesPerSector,&FreeClusters,&Clusters))
      ClusterSize=SectorsPerCluster*BytesPerSector;
  }

  DirCount=FileCount=0;
  FileSize=CompressedFileSize=RealSize=0;
  ScTree.SetFindPath(DirName,"*.*");
  while (ScTree.GetNextName(&FindData,FullName))
  {
    if (!CtrlObject->Macro.IsExecuting())
    {
      INPUT_RECORD rec;
      switch(PeekInputRecord(&rec))
      {
        case 0:
        case KEY_IDLE:
          break;
        case KEY_NONE:
        case KEY_ALT:
        case KEY_CTRL:
        case KEY_SHIFT:
        case KEY_RALT:
        case KEY_RCTRL:
          GetInputRecord(&rec);
          break;
        case KEY_ESC:
        case KEY_BREAK:
          GetInputRecord(&rec);
          return(0);
        default:
          if (EnhBreak)
            return(-1);
          GetInputRecord(&rec);
          break;
      }
    }
    if (!MsgOut && MsgWaitTime!=0xffffffff && clock()-StartTime > MsgWaitTime)
    {
      SetCursorType(FALSE,0);
      Message(0,0,Title,MSG(MScanningFolder),DirName);
      MsgOut=1;
    }
    if (FindData.dwFileAttributes & FA_DIREC)
      DirCount++;
    else
    {
      FileCount++;
      int64 CurSize(FindData.nFileSizeHigh,FindData.nFileSizeLow);
      FileSize+=CurSize;
      if (FindData.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED)
      {
        DWORD CompressedSize,CompressedSizeHigh;
        CompressedSize=GetCompressedFileSize(FullName,&CompressedSizeHigh);
        if (CompressedSize!=0xFFFFFFFF || GetLastError()==NO_ERROR)
          CurSize.Set(CompressedSizeHigh,CompressedSize);
      }
      CompressedFileSize+=CurSize;
      if (ClusterSize>0)
      {
        RealSize+=CurSize;
        int Slack=(CurSize%ClusterSize).PLow();
        if (Slack>0)
          RealSize+=ClusterSize-Slack;
      }
    }
  }
  return(1);
}


int GetPluginDirInfo(HANDLE hPlugin,char *DirName,unsigned long &DirCount,
               unsigned long &FileCount,int64 &FileSize,
               int64 &CompressedFileSize)
{
  struct PluginPanelItem *PanelItem=NULL;
  int ItemsNumber,ExitCode;
  DirCount=FileCount=0;
  FileSize=CompressedFileSize=0;
  if ((ExitCode=FarGetPluginDirList(((struct PluginHandle *)hPlugin)->PluginNumber,
      ((struct PluginHandle *)hPlugin)->InternalHandle,DirName,
      &PanelItem,&ItemsNumber))==TRUE)
  {
    for (int I=0;I<ItemsNumber;I++)
    {
      if (PanelItem[I].FindData.dwFileAttributes & FA_DIREC)
        DirCount++;
      else
      {
        FileCount++;
        int64 CurSize(PanelItem[I].FindData.nFileSizeHigh,PanelItem[I].FindData.nFileSizeLow);
        FileSize+=CurSize;
        if (PanelItem[I].PackSize==0 && PanelItem[I].PackSizeHigh==0)
          CompressedFileSize+=CurSize;
        else
        {
          int64 AddSize(PanelItem[I].PackSizeHigh,PanelItem[I].PackSize);
          CompressedFileSize+=AddSize;
        }
      }
    }
  }
  if (PanelItem!=NULL)
    FarFreeDirList(PanelItem);
  return(ExitCode);
}


/* $ 07.09.2000 SVS
   ������� GetFileOwner ���� �������� �������� :-)
*/
int WINAPI GetFileOwner(char *Computer,char *Name,char *Owner)
{
  SECURITY_INFORMATION si;
  SECURITY_DESCRIPTOR *sd;
  char sddata[500];
  DWORD Needed;
  *Owner=0;
  si=OWNER_SECURITY_INFORMATION|GROUP_SECURITY_INFORMATION;
  sd=(SECURITY_DESCRIPTOR *)sddata;

  char AnsiName[NM];
  OemToChar(Name,AnsiName);
  SetFileApisToANSI();
  int GetCode=GetFileSecurity(AnsiName,si,sd,sizeof(sddata),&Needed);
  SetFileApisToOEM();

  /* $ 21.02.2001 VVM
      ! ��� ��/2000 ���������� Needed ��������������� ���������� �� ���������. */
  if (!GetCode || (Needed>sizeof(sddata)))
    return(FALSE);
  /* VVM $ */
  PSID pOwner;
  BOOL OwnerDefaulted;
  if (!GetSecurityDescriptorOwner(sd,&pOwner,&OwnerDefaulted))
    return(FALSE);
  char AccountName[200],DomainName[200];
  DWORD AccountLength=sizeof(AccountName),DomainLength=sizeof(DomainName);
  SID_NAME_USE snu;
  if (!LookupAccountSid(Computer,pOwner,AccountName,&AccountLength,DomainName,&DomainLength,&snu))
    return(FALSE);
  CharToOem(AccountName,Owner);
  return(TRUE);
}
/* SVS $*/


/* $ 19.09.2000 SVS
   ������� "�������" �� ���� ���������� ������ ������� `strcmp'
*/
int IsFolderNotEmpty(char *Name)
{
  register DWORD P;
  WIN32_FIND_DATA fdata;
  char FileName[NM];
  ScanTree ScTree(FALSE,FALSE);
  ScTree.SetFindPath(Name,"*.*");
  while (ScTree.GetNextName(&fdata,FileName))
  {
    // ������� �������.
    P=(*(DWORD*)FileName)&0x00FFFFFF;
    if((P&0xFFFF) != 0x002E && P != 0x002E2E )
//    if (strcmp(FileName,".")!=0 && strcmp(FileName,"..")!=0)
      return(TRUE);
  }
  return(FALSE);
}
/* SVS $ */

int DeleteFileWithFolder(char *FileName)
{
  char FolderName[NM],*Slash;
  SetFileAttributes(FileName,0);
  remove(FileName);
  strcpy(FolderName,FileName);
  if ((Slash=strrchr(FolderName,'\\'))!=NULL)
    *Slash=0;
  return(RemoveDirectory(FolderName));
}


char* FarMSG(int MsgID)
{
  return(Lang.GetMsg(MsgID));
}


BOOL GetDiskSize(char *Root,int64 *TotalSize,int64 *TotalFree,int64 *UserFree)
{
typedef BOOL (WINAPI *GETDISKFREESPACEEX)(
    LPCTSTR lpDirectoryName,
    PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    PULARGE_INTEGER lpTotalNumberOfBytes,
    PULARGE_INTEGER lpTotalNumberOfFreeBytes
   );
  static GETDISKFREESPACEEX pGetDiskFreeSpaceEx=NULL;
  static int LoadAttempt=FALSE;
  int ExitCode;

  ULARGE_INTEGER uiTotalSize,uiTotalFree,uiUserFree;
  uiUserFree.u.LowPart=uiUserFree.u.HighPart=0;
  uiTotalSize.u.LowPart=uiTotalSize.u.HighPart=0;
  uiTotalFree.u.LowPart=uiTotalFree.u.HighPart=0;

  if (!LoadAttempt && pGetDiskFreeSpaceEx==NULL)
  {
    HMODULE hKernel=GetModuleHandle("kernel32.dll");
    if (hKernel!=NULL)
      pGetDiskFreeSpaceEx=(GETDISKFREESPACEEX)GetProcAddress(hKernel,"GetDiskFreeSpaceExA");
    LoadAttempt=TRUE;
  }
  if (pGetDiskFreeSpaceEx!=NULL)
  {
    ExitCode=pGetDiskFreeSpaceEx(Root,&uiUserFree,&uiTotalSize,&uiTotalFree);
    if (uiUserFree.u.HighPart>uiTotalFree.u.HighPart)
      uiUserFree.u=uiTotalFree.u;
  }

  if (pGetDiskFreeSpaceEx==NULL || ExitCode==0 ||
      uiTotalSize.u.HighPart==0 && uiTotalSize.u.LowPart==0)
  {
    DWORD SectorsPerCluster,BytesPerSector,FreeClusters,Clusters;
    ExitCode=GetDiskFreeSpace(Root,&SectorsPerCluster,&BytesPerSector,
                              &FreeClusters,&Clusters);
    uiTotalSize.u.LowPart=SectorsPerCluster*BytesPerSector*Clusters;
    uiTotalSize.u.HighPart=0;
    uiTotalFree.u.LowPart=SectorsPerCluster*BytesPerSector*FreeClusters;
    uiTotalFree.u.HighPart=0;
    uiUserFree.u=uiTotalFree.u;
  }
  TotalSize->Set(uiTotalSize.u.HighPart,uiTotalSize.u.LowPart);
  TotalFree->Set(uiTotalFree.u.HighPart,uiTotalFree.u.LowPart);
  UserFree->Set(uiUserFree.u.HighPart,uiUserFree.u.LowPart);
  return(ExitCode);
}


void DeleteDirTree(char *Dir)
{
  if (*Dir==0 || (Dir[0]=='\\' || Dir[0]=='/') && Dir[1]==0 ||
      Dir[1]==':' && (Dir[2]=='\\' || Dir[2]=='/') && Dir[3]==0)
    return;
  char FullName[NM];
  WIN32_FIND_DATA FindData;
  ScanTree ScTree(TRUE);

  ScTree.SetFindPath(Dir,"*.*");
  while (ScTree.GetNextName(&FindData,FullName))
  {
    SetFileAttributes(FullName,0);
    if (FindData.dwFileAttributes & FA_DIREC)
    {
      if (ScTree.IsDirSearchDone())
        RemoveDirectory(FullName);
    }
    else
      DeleteFile(FullName);
  }
  SetFileAttributes(Dir,0);
  RemoveDirectory(Dir);
}



int GetClusterSize(char *Root)
{
  struct ExtGetDskFreSpc
  {
    WORD ExtFree_Size;
    WORD ExtFree_Level;
    DWORD ExtFree_SectorsPerCluster;
    DWORD ExtFree_BytesPerSector;
    DWORD ExtFree_AvailableClusters;
    DWORD ExtFree_TotalClusters;
    DWORD ExtFree_AvailablePhysSectors;
    DWORD ExtFree_TotalPhysSectors;
    DWORD ExtFree_AvailableAllocationUnits;
    DWORD ExtFree_TotalAllocationUnits;
    DWORD ExtFree_Rsvd[2];
  } DiskInfo;

  struct _DIOC_REGISTERS
  {
    DWORD reg_EBX;
    DWORD reg_EDX;
    DWORD reg_ECX;
    DWORD reg_EAX;
    DWORD reg_EDI;
    DWORD reg_ESI;
    DWORD reg_Flags;
  } reg;

  BOOL fResult;
  DWORD cb;

  if (WinVer.dwPlatformId!=VER_PLATFORM_WIN32_WINDOWS ||
      WinVer.dwBuildNumber<0x04000457)
    return(0);

  HANDLE hDevice = CreateFile("\\\\.\\vwin32", 0, 0, NULL, 0,
                              FILE_FLAG_DELETE_ON_CLOSE, NULL);

  if (hDevice==INVALID_HANDLE_VALUE)
    return(0);

  DiskInfo.ExtFree_Level=0;

  reg.reg_EAX = 0x7303;
  reg.reg_EDX = (DWORD)Root;
  reg.reg_EDI = (DWORD)&DiskInfo;
  reg.reg_ECX = sizeof(DiskInfo);
  reg.reg_Flags = 0x0001;

  fResult=DeviceIoControl(hDevice,6,&reg,sizeof(reg),&reg,sizeof(reg),&cb,0);

  CloseHandle(hDevice);
  if (!fResult || (reg.reg_Flags & 0x0001))
    return(0);
  return(DiskInfo.ExtFree_SectorsPerCluster*DiskInfo.ExtFree_BytesPerSector);
}



/* $ 02.03.2001 IS
   ���������� ���������� �����
   �������� � �������� ��������������� ������ ������� ������
     ExpandEnvironmentStrings.
*/
DWORD WINAPI ExpandEnvironmentStr(char *src, char *dest, size_t size)
{
  DWORD ret=0;
  if(size)
  {
   /* $ 17.06.2001 IS
        ����� ��, ��� ExpandEnvironmentStrings ���������� �������� ����������
        ��������� � ANSI
   */
   char *tmpDest=(char *)alloca(size+1),
        *tmpSrc=(char *)alloca(strlen(src)+1);
   if(tmpDest && tmpSrc)
   {
     OemToChar(src, tmpSrc);

     if(ExpandEnvironmentStrings(tmpSrc,tmpDest,size))
       strncpy(dest, tmpDest, size);
     else
     {
       strncpy(tmpDest, tmpSrc, size);
       strcpy(dest, tmpDest);
     }
     CharToOem(dest, dest);
     ret=strlen(dest);
   }
   /* IS $ */
  }
  return ret;
}
/* IS $ */

/* $ 25.07.2000 SVS
   �������� ������ ������� ����������� �������, ����������� � WINAPI
*/
char *WINAPI FarItoa(int value, char *string, int radix)
{
  if(string)
    return itoa(value,string,radix);
  return NULL;
}
/* $ 28.08.2000 SVS
  + FarItoa64
*/
char *WINAPI FarItoa64(__int64 value, char *string, int radix)
{
  if(string)
    return _i64toa(value, string, radix);
  return NULL;
}
/* SVS $ */
int WINAPI FarAtoi(const char *s)
{
  if(s)
    return atoi(s);
  return 0;
}
__int64 WINAPI FarAtoi64(const char *s)
{
  if(s)
    return _atoi64(s);
  return 0i64;
}

void WINAPI FarQsort(void *base, size_t nelem, size_t width,
                     int (__cdecl *fcmp)(const void *, const void *))
{
  if(base && fcmp)
    qsort(base,nelem,width,fcmp);
}

/* $ 24.03.2001 tran
   ����� �����...*/
void WINAPI FarQsortEx(void *base, size_t nelem, size_t width,
                     int (__cdecl *fcmp)(void *, void *,void *user),void *user)
{
  if(base && fcmp)
    qsortex((char*)base,nelem,width,fcmp,user);
}
/* tran $ */

int WINAPIV FarSprintf(char *buffer,const char *format,...)
{
  int ret=0;
  if(buffer && format)
  {
    va_list argptr;
    va_start(argptr,format);
    ret=vsprintf(buffer,format,argptr);
    va_end(argptr);
  }
  return ret;
}

/* $ 29.08.2000 SVS
   - ������� ������������ ������� FarSscanf
   ������� - �.�. � VC ���� vsscanf, �� �������� ������������� (����� ��
   ���������� VC sscanf � "����������" �� ����
*/
#if defined(_MSC_VER)
extern "C" {
int __cdecl _input (FILE *stream,const unsigned char *format,va_list arglist);
};
#endif

int WINAPIV FarSscanf(const char *buffer, const char *format,...)
{
  if(!buffer || !format)
    return 0;
#if defined(_MSC_VER)
  // ������ ����� ������������� sscanf :-)
  va_list arglist;
  FILE str;
  FILE *infile = &str;
  int retval;

  va_start(arglist, format);

  infile->_flag = _IOREAD|_IOSTRG|_IOMYBUF;
  infile->_ptr = infile->_base = (char *) buffer;
  infile->_cnt = strlen(buffer);

  retval = (_input(infile,(const unsigned char *)format,arglist));

  return(retval);
#else
  va_list argptr;
  va_start(argptr,format);
  int ret=vsscanf(buffer,format,argptr);
  va_end(argptr);
  return ret;
#endif
}
/* 29.08.2000 SVS $ */
/* SVS $ */


/* $ 07.09.2000 SVS
   �������� FarBsearch ��� �������� (������� bsearch)
*/
void *WINAPI FarBsearch(const void *key, const void *base, size_t nelem, size_t width, int (__cdecl *fcmp)(const void *, const void *))
{
  if(key && fcmp && base)
    return bsearch(key,base,nelem,width,fcmp);
  return NULL;
}
/* SVS $ */


/* $ 10.09.2000 tran
   FSF/FarRecurseSearch */
void WINAPI FarRecursiveSearch(char *InitDir,char *Mask,FRSUSERFUNC Func,DWORD Flags,void *Param)
{
  if(Func) // SVS: � ���������? :-(
  {
    ScanTree ScTree(Flags& FRS_RETUPDIR,Flags & FRS_RECUR);
    WIN32_FIND_DATA FindData;
    char FullName[NM];

    ScTree.SetFindPath(InitDir,Mask);
    while (ScTree.GetNextName(&FindData,FullName))
    {
      //if (func(FindData,FullName)==0)
      if (Func(&FindData,FullName,Param) == 0)
          break;
    }
  }
}
/* tran 10.09.2000 $ */

/* $ 14.09.2000 SVS
 + ������� FarMkTemp - ��������� ����� ���������� ����� � ������ �����.
    Dest - �������� ���������� (������ ���� ���������� �������, �������� NM
    Template - ������ �� �������� ������� mktemp, �������� "FarTmpXXXXXX"
   ������ ���� NULL, ���� ��������� �� Dest.
*/
/* $ 18.09.2000 SVS
  �� �� ������� ������� :-)))
*/
/* $ 25.10.2000 IS
 ! ������� mktemp �� ����� ��������������� ������� �������, �.�. ����������
   ������� �������� � ������ (�������� �� Multiarc'�)
   �������� Prefix - ������, ����������� �� ������ ������� ����� ����������
   �����. ������������ ������ ������ 3 ������� �� ���� ������.
*/
char* WINAPI FarMkTemp(char *Dest, char *Prefix)
{
  if(Dest && Prefix && *Prefix)
  {
    char TempPath[NM],TempName[NM];
    int Len;
    TempPath[Len=GetTempPath(sizeof(TempPath),TempPath)]=0;
    /* $ 25.10.2000 SVS
       �������� �������, ��� ������� ������ ���� � ANSI
       � ����� ��???!!!
    */
//    char Pref[32];
//    OemToChar(Prefix,Pref);
//    if(GetTempFileName(TempPath,Pref,0,TempName))
    if(GetTempFileName(TempPath,Prefix,0,TempName))
    {
      strcpy(Dest,strupr(TempName));
      return Dest;
    }
    /* SVS $ */
  }
  return NULL;
}
/* IS $ */
/* SVS 18.09.2000 $ */
/* SVS $ */

/*$ 27.09.2000 skv
  + �������� ������ ����������� ����� new char[n];
    ������� ��� �������� ������������� PasteFromClipboard
*/
void WINAPI DeleteBuffer(char *Buffer)
{
  if(Buffer)delete [] Buffer;
}
/* skv$*/

// �������� �� ����� ����� RemoteName
char* DriveLocalToRemoteName(int DriveType,char Letter,char *Dest)
{
  int NetPathShown=FALSE, IsOK=FALSE;
  char LocalName[8]=" :",RemoteName[NM];
  DWORD RemoteNameSize=sizeof(RemoteName);

  *LocalName=Letter;
  *Dest=0;

  if (DriveType==DRIVE_REMOTE)
  {
    SetFileApisToANSI();
    if (WNetGetConnection(LocalName,RemoteName,&RemoteNameSize)==NO_ERROR)
    {
      NetPathShown=TRUE;
      IsOK=TRUE;
    }
    SetFileApisToOEM();
  }
  if (!NetPathShown)
    if (GetSubstName(DriveType,LocalName,RemoteName,sizeof(RemoteName)))
      IsOK=TRUE;

  if(IsOK)
  {
    CharToOem(RemoteName,RemoteName);
    strcpy(Dest,RemoteName);
  }
  return Dest;
}

/*
  FarGetLogicalDrives
  �������� ������ GetLogicalDrives, � ������ ������� ���������� ������
  HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer
  NoDrives:DWORD
    ��������� 26 ��� ���������� ����� ������ �� A �� Z (������ ������ ������).
    ���� ����� ��� ������������� 0 � ����� ��� �������� 1.
    ���� A ����������� ������ ��������� ������ ��� �������� �������������.
    ��������, �������� 00000000000000000000010101(0x7h)
    �������� ����� A, C, � E
*/
DWORD WINAPI FarGetLogicalDrives(void)
{
  static DWORD LogicalDrivesMask = 0;
  DWORD NoDrives=0;
  if ((!Opt.RememberLogicalDrives) || (LogicalDrivesMask==0))
    LogicalDrivesMask=GetLogicalDrives();

  if(!Opt.Policies.ShowHiddenDrives)
  {
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer",0,KEY_QUERY_VALUE,&hKey)==ERROR_SUCCESS && hKey)
    {
      int ExitCode;
      DWORD Type,Size=sizeof(NoDrives);
      ExitCode=RegQueryValueEx(hKey,"NoDrives",0,&Type,(BYTE *)&NoDrives,&Size);
      RegCloseKey(hKey);
      if(ExitCode != ERROR_SUCCESS)
        NoDrives=0;
    }
  }
  return LogicalDrivesMask&(~NoDrives);
}

// �������������� �������� ������� PATHEXT � ��������� :-)
// ������� ���������� ������ ����������, ��� ���� ��������� ��, ��� ����
//   � %PATHEXT% �  ���� � Dest.
char *Add_PATHEXT(char *Dest)
{
  char Buf[1024];
  if(GetEnvironmentVariable("PATHEXT",Buf,sizeof(Buf)))
  {
    char Tmp[32]="*";
    char *Ptr,ArgName[NM];

    if((Ptr=GetCommaWord((Ptr=strlwr(Buf)),ArgName,';')) != NULL)
    {
      if(*Dest && Dest[strlen(Dest)-1] != ',')
        strcat(Dest,",");
      while(Ptr)
      {
        strcpy(Tmp+1,ArgName);
        Ptr=GetCommaWord(Ptr,ArgName,';');
        if(!strstr(Dest,Tmp))
        {
          strcat(Dest,Tmp);
          if(Ptr)
            strcat(Dest,",");
        }
      }
    }
  }
  // ������ ������� - � ����!
  if(*Dest && Dest[strlen(Dest)-1] == ',')
    Dest[strlen(Dest)-1]=0;
  return Dest;
}

void CreatePath(char *Path)
{
  char *ChPtr;
  ChPtr=Path;
  while(*ChPtr)
  {
    if (*ChPtr=='\\')
    {
      *ChPtr=0;

      char DirName[NM];
      strcpy(DirName,Path);
      if (Opt.CreateUppercaseFolders && !IsCaseMixed(DirName))
        LocalStrupr(DirName);

      if (CreateDirectory(DirName,NULL))
        TreeList::AddTreeName(DirName);
      *ChPtr='\\';
    }
    ChPtr++;
  }
  if (CreateDirectory(Path,NULL))
    TreeList::AddTreeName(Path);
}
