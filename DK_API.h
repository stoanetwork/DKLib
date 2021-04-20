#pragma once

#include "DKLibDef.h"
#include <vector>
#include "DKcommon.h"
#include "ToThousandStr.h"


//////////////////////////////////////////////////////////////////////////////////////
#if 0
CString ToCurrency(LONGLONG a_nVal);
CString ToCurrency(DOUBLE a_nVal);
CString FloatToComaString(DOUBLE a_val);
#endif
//CString ToCurrency(const CString& str);
//////////////////////////////////////////////////////////////////////////////////////
DK_API BOOL ParseLine(const CString& strIn, CString& left, CString& right, TCHAR token = _T('='));
DK_API BOOL ParseLineSep(const CString& strIn, std::vector<CString>& items, TCHAR token = _T('\t'), BOOL bIgnoreEmpty = FALSE);
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
template <typename T>
DOUBLE CalcPercent(T before, T after)
{
	if(before == 0)
		return 0;
	return (after/(DOUBLE)before) * 100 - 100.0;

}

//////////////////////////////////////////////////////////////////////////////////////
// val값대비 fPercent에 해당하는 값을 넘긴다.
template <typename T>
DOUBLE GetValPercent(T val, DOUBLE fPercent)
{
	if(fPercent == 0)
		return 0;
	return (DOUBLE)val * (1/fPercent);
}


//////////////////////////////////////////////////////////////////////////////////////
// 해당날이 그달의 몇째주 인지
DK_API int GetWeekOfMonth(const CTime& tm);

//////////////////////////////////////////////////////////////////////////////////////
DK_API BOOL SystemShutDown();

//////////////////////////////////////////////////////////////////////////////////////
DK_API void ErrMsgBox(LPCTSTR szFmt, ...);


//////////////////////////////////////////////////////////////////////////////////////
DK_API BOOL IsExistDirectory(const CString& path, BOOL bCreateIfNotExist = TRUE);

//////////////////////////////////////////////////////////////////////////////////////
DK_API BOOL IsExistFile(LPCTSTR szPath);

//////////////////////////////////////////////////////////////////////////////////////
DK_API CString GetDirectoryFromFilePath(const CString& strFilePath, int nDepth = 0); // nDepth: 상위 디렉토리 레벨 

//////////////////////////////////////////////////////////////////////////////////////
inline CString GetModuleRootDirectory()
{
	TCHAR szPath[MAX_PATH];
	::GetModuleFileName(AfxGetInstanceHandle(), szPath, MAX_PATH);
	return ::GetDirectoryFromFilePath(szPath);
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
DK_API CString ShowFolderSelectDialog(const CString& pathDef);

//////////////////////////////////////////////////////////////////////////////////////
DK_API CString COMErrMsg(HRESULT hre);

//////////////////////////////////////////////////////////////////////////////////////
DK_API BOOL IsNumeric(const CString& val, BOOL* bNatural = NULL);

//////////////////////////////////////////////////////////////////////////////////////
DK_API CString WinErrMsg(DWORD hre);

//////////////////////////////////////////////////////////////////////////////////////
DK_API CString ToString(const VARIANT& var, int nPrecision);
DK_API CString ToString(INT iVal);
DK_API CString ToString(LONGLONG llVal);
DK_API CString ToString(UINT uiVal);
DK_API CString ToString(ULONGLONG ullVal);
DK_API CString ToString(DOUBLE dVal, int nPrecision);
DK_API CString ToString(FLOAT fVal, int nPrecision);



inline LONGLONG ToLONGLONG(const VARIANT& var)
{
	return var.decVal.Lo64 * ((var.decVal.sign == 128) ? -1 : 1);
}

//////////////////////////////////////////////////////////////////////////////////////
template<class T>
inline CString ToThousand(T val)
{
	static ToThousandStr obj;
	obj = val;
	return obj.GetString();
}

inline INT ToINT(const CStringW& str)
{
	return ::_wtoi(str);
}

inline INT ToINT(const CStringA& str)
{
	return ::atoi(str);
}

inline LONGLONG ToLONGLONG(const CStringW& str)
{
	return ::_wtoi64(str);
}

inline LONGLONG ToLONGLONG(const CStringA& str)
{
	return ::_atoi64(str);
}


inline DOUBLE ToDOUBLE(const CStringW& str)
{
	return ::_wtof(str);
}
inline DOUBLE ToDOUBLE(const CStringA& str)
{
	return ::atof(str);
}

//////////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline T RoundUp(T val, double dig)
{
	return (std::floor((double)val * pow(10, dig) + 0.5) / pow(10, dig));
}
//////////////////////////////////////////////////////////////////////////////////////
DK_API void GetMACaddress(std::vector<CString>& cont);

//////////////////////////////////////////////////////////////////////////////////////
DK_API void PlayWave(const CString& strFileName);

//////////////////////////////////////////////////////////////////////////////////////
DK_API void SetKeyboard(HWND hWnd, BOOL bEng);

//////////////////////////////////////////////////////////////////////////////////////
DK_API WindowsVersion GetWindowsVersion();
