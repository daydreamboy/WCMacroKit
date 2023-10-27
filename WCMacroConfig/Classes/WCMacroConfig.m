//
//  WCMacroConfig.m
//  AppTest
//
//  Created by wesley_chen on 2023/10/26.
//

#import "WCMacroConfig.h"

@implementation WCMacroConfig

+ (BOOL)isXcode13OrLatterCompiled {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 150000
    return YES;
#else
    return NO;
#endif
}

+ (BOOL)isXcode14OrLatterCompiled {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 160000
    return YES;
#else
    return NO;
#endif
}

+ (BOOL)isXcode15OrLatterCompiled {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 170000
    return YES;
#else
    return NO;
#endif
}

+ (BOOL)isDefinedDEBUG {
#if DEBUG
    return YES;
#else
    return NO;
#endif
}

@end
