//
//  WCMacroKit.h
//  WCMacroKit
//
//  Created by wesley_chen on 2018/7/25.
//

#import <UIKit/UIKit.h>

//! Project version number for WCMacroKit.
FOUNDATION_EXPORT double WCMacroKitVersionNumber;

//! Project version string for WCMacroKit.
FOUNDATION_EXPORT const unsigned char WCMacroKitVersionString[];

#if __has_include(<WCMacroKit/WCMacroKit.h>)

#import <WCMacroKit/WCMacroAssert.h>
#import <WCMacroKit/WCMacroAttribute.h>
#import <WCMacroKit/WCMacroAttributedString.h>
#import <WCMacroKit/WCMacroBlock.h>
#import <WCMacroKit/WCMacroBreakpoint.h>
#import <WCMacroKit/WCMacroCode.h>
#import <WCMacroKit/WCMacroColor.h>
#import <WCMacroKit/WCMacroCompatibility.h>
#import <WCMacroKit/WCMacroDebug.h>
#import <WCMacroKit/WCMacroDelegate.h>
#import <WCMacroKit/WCMacroDollarSign.h>
#import <WCMacroKit/WCMacroError.h>
#import <WCMacroKit/WCMacroLog.h>
#import <WCMacroKit/WCMacroSafeValue.h>
#import <WCMacroKit/WCMacroString.h>
#import <WCMacroKit/WCMacroSynthesize.h>
#import <WCMacroKit/WCMacroThread.h>
#import <WCMacroKit/WCMacroTime.h>
#import <WCMacroKit/WCMacroTool.h>
#import <WCMacroKit/WCMacroUILayout.h>
#import <WCMacroKit/WCMacroUncategoried.h>
#import <WCMacroKit/WCMacroVersion.h>
#import <WCMacroKit/WCMacroWarning.h>
#import <WCMacroKit/WCCallerTool.h>

#elif __has_include("WCMacroKit.h")

#import "WCMacroAssert.h"
#import "WCMacroAttribute.h"
#import "WCMacroAttributedString.h"
#import "WCMacroBlock.h"
#import "WCMacroBreakpoint.h"
#import "WCMacroCode.h"
#import "WCMacroColor.h"
#import "WCMacroCompatibility.h"
#import "WCMacroDebug.h"
#import "WCMacroDelegate.h"
#import "WCMacroDollarSign.h"
#import "WCMacroError.h"
#import "WCMacroLog.h"
#import "WCMacroSafeValue.h"
#import "WCMacroString.h"
#import "WCMacroSynthesize.h"
#import "WCMacroThread.h"
#import "WCMacroTime.h"
#import "WCMacroTool.h"
#import "WCMacroUILayout.h"
#import "WCMacroUncategoried.h"
#import "WCMacroVersion.h"
#import "WCMacroWarning.h"
#import "WCCallerTool.h"

#endif

