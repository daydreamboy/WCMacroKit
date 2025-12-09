//
//  Test_MacroLog_WCLogPrefix.m
//  Test
//
//  Created by wesley_chen on 2022/12/23.
//

#import <XCTest/XCTest.h>
// Note: no need import umbrella header,
// just import the wrapper header instead
//#import <WCMacroKit/WCMacroKit.h>
#import "WCLogPrefix_XXXModule.h"

@interface Test_MacroLog_WCLogPrefix : XCTestCase

@end

@implementation Test_MacroLog_WCLogPrefix

- (void)test_WCLogPrefix {
    NSString *message = @"message"      @", a.k.a msg";
    
    NSLog(@"[ApolloSDK] " @"log: %@", message);
    WCDebugLog(@"<print a log>|log:%@|", message);
    WCDebugLog(@"<This is a log>");
}

@end
