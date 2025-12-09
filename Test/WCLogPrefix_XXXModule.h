//
//  MacroLogPrefixTest.h
//  WCMacroKit
//
//  Created by wesley_chen on 2022/12/23.
//

#ifndef MacroLogPrefixTest_h
#define MacroLogPrefixTest_h

#import <WCMacroKit/WCMacroKit.h>

#define WCLogModule @"[TestTarget]"
#undef WCDebugLog
#define WCDebugLog WCDebugLogPrefix

#endif /* MacroLogPrefixTest_h */
