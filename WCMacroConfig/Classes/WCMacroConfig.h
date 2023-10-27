//
//  WCMacroConfig.h
//  AppTest
//
//  Created by wesley_chen on 2023/10/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WCMacroConfig : NSObject

/**
 Check code if compiled by Xcode13 or later
 */
+ (BOOL)isXcode13OrLatterCompiled;
+ (BOOL)isXcode14OrLatterCompiled;
+ (BOOL)isXcode15OrLatterCompiled;
+ (BOOL)isDefinedDEBUG;

@end

NS_ASSUME_NONNULL_END
