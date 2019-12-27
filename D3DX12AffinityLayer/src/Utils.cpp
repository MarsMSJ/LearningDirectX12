//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "d3dx12affinity.h"
#include "Utils.h"

#include <locale>
#include <codecvt>
#include <string>
#include <comdef.h>

#if defined(_UNICODE)
inline std::string ConvertString(const TCHAR* s)
{
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(s);
}
#else
inline std::string ConvertString(const TCHAR* s)
{
    return s;
}
#endif

void WriteHRESULTError(HRESULT const hr)
{
    _com_error err(hr, nullptr);
    DebugLog(L"HRESULT Failure: %d 0x%08X %s\n", hr, hr, ConvertString(err.ErrorMessage()).c_str());
}
