////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Copyright (c) 2012 Microsoft Corporation.  All Rights Reserved.
//
//   Module Name:
//      ClassifyFunctions_ProxyCallouts.cpp
//
//   Abstract:
//      This module contains prototypes for WFP Classify functions for proxying connections and 
//         sockets.
//
//   Author:
//      Dusty Harper      (DHarper)
//
//   Revision History:
//
//      [ Month ][Day] [Year] - [Revision]-[ Comments ]
//      May       01,   2010  -     1.0   -  Creation
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CLASSIFY_PROXY_H
#define CLASSIFY_PROXY_H

_IRQL_requires_(DISPATCH_LEVEL)
_IRQL_requires_same_
_Function_class_(KDEFERRED_ROUTINE)
VOID ProxyUsingInjectionMethodDeferredProcedureCall(_In_ KDPC* pDPC,
                                                    _In_opt_ PVOID pContext,
                                                    _In_opt_ PVOID pArg1,
                                                    _In_opt_ PVOID pArg2);

#if(NTDDI_VERSION >= NTDDI_WIN7)
//WIN7,WIN8,WIN10,...
_IRQL_requires_(DISPATCH_LEVEL)
_IRQL_requires_same_
_Function_class_(KDEFERRED_ROUTINE)
VOID ProxyByALERedirectDeferredProcedureCall(_In_ KDPC* pDPC,
                                             _In_opt_ PVOID pContext,
                                             _In_opt_ PVOID pArg1,
                                             _In_opt_ PVOID pArg2);
//ALE重定向代理分类处理Classify Callout函数
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyProxyByALERedirect(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                                _Inout_opt_ VOID* pNetBufferList,
                                _In_opt_ const VOID* pClassifyContext,
                                _In_ const FWPS_FILTER* pFilter,
                                _In_ UINT64 flowContext,
                                _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);
//注入代理分类处理Classify Callout函数
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyProxyByInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                              _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                              _Inout_opt_ VOID* pNetBufferList,
                              _In_opt_ const VOID* pClassifyContext,
                              _In_ const FWPS_FILTER* pFilter,
                              _In_ UINT64 flowContext,
                              _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);

#else
//WIN7以下
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyProxyByALERedirect(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                                _Inout_opt_ VOID* pNetBufferList,
                                _In_ const FWPS_FILTER* pFilter,
                                _In_ UINT64 flowContext,
                                _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);

_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyProxyByInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                              _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                              _Inout_opt_ VOID* pNetBufferList,
                              _In_ const FWPS_FILTER* pFilter,
                              _In_ UINT64 flowContext,
                              _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);

#endif /// (NTDDI_VERSION >= NTDDI_WIN7)

#endif /// CLASSIFY_PROXY_H
