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

#if __has_include("WCMacroKit.h")

#import "WCMacroAssert.h"
#import "WCMacroBlock.h"
#import "WCMacroColor.h"
#import "WCMacroCompatibility.h"
#import "WCMacroDelegate.h"
#import "WCMacroLog.h"
#import "WCMacroSafeValue.h"
#import "WCMacroString.h"
#import "WCMacroSynthesize.h"
#import "WCMacroTool.h"
#import "WCMacroUncategoried.h"
#import "WCMacroVersion.h"
#import "WCCallerTool.h"

#elif __has_include(<WCMacroKit/WCMacroKit.h>)

#import <WCMacroKit/WCMacroAssert.h>
#import <WCMacroKit/WCMacroBlock.h>
#import <WCMacroKit/WCMacroColor.h>
#import <WCMacroKit/WCMacroCompatibility.h>
#import <WCMacroKit/WCMacroDelegate.h>
#import <WCMacroKit/WCMacroLog.h>
#import <WCMacroKit/WCMacroSafeValue.h>
#import <WCMacroKit/WCMacroString.h>
#import <WCMacroKit/WCMacroSynthesize.h>
#import <WCMacroKit/WCMacroTool.h>
#import <WCMacroKit/WCMacroUncategoried.h>
#import <WCMacroKit/WCMacroVersion.h>
#import <WCMacroKit/WCCallerTool.h>

#endif

