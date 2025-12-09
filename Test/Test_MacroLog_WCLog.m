//
//  Test_MacroLog_WCLog.m
//  Test
//
//  Created by wesley_chen on 2022/12/23.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroLog_WCLog : XCTestCase

@end

@implementation Test_MacroLog_WCLog

- (void)test_WCLog {
    NSString *message = @"message"      @", a.k.a msg";
    
    NSLog(@"[ApolloSDK] " @"log: %@", message);
    WCDebugLog(@"log: %@", message);
    WCDebugLog(@"This is a log");
}

@end
