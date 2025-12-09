//
//  Test_MacroLog.m
//  Test
//
//  Created by wesley_chen on 2020/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

#define WCLogModule @"[Test_MacroLog] "
#undef WCLog
#define WCLog WCLogPrefix

@interface Test_MacroLog : XCTestCase

@end

@implementation Test_MacroLog

- (void)test_WCDebugLog {
    NSString *message = @"message"      @", a.k.a msg";
    
    NSLog(@"[ApolloSDK] " @"log: %@", message);
    WCDebugLog(@"log:`%@`", message);
    WCDebugLog(@"This is a log");
}

- (void)test_XLog {
    
    NSLog(@"Hello");
    
    NSLog((@"[ONEVoIP] %s [Line %d] " @"%@"), __PRETTY_FUNCTION__, __LINE__, @"var");
    
    ALog(@"%@", @"test Alert");
    CLog(@"%@", @"test Critial");
    ELog(@"%@", @"test Error");
    WLog(@"%@", @"test Warning");
    NLog(@"%@", @"test Notice");
    ILog(@"%@", @"test Info");
    DLog(@"%@", @"test Debug");
    
    __unused NSError *errorNil;
    LogError(@"%@", errorNil); // Will not print
    
    __unused NSError *error = [NSError errorWithDomain:@"domain" code:-1 userInfo:@{ NSLocalizedDescriptionKey: @"CAUTION! An error occurred." }];
    LogError(@"%@", error); // Will print
}

- (void)test_ALog {
    ALog(@"%@", @"test Alert");
}

@end
