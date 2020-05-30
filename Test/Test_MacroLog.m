//
//  Test_MacroLog.m
//  Test
//
//  Created by wesley_chen on 2020/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroLog : XCTestCase

@end

@implementation Test_MacroLog

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

#pragma mark - WCDumpXXX

- (void)test_WCDumpBool {
    WCDumpBool(YES);
    WCDumpBool(NO);
    
    BOOL boolValue = YES;
    WCDumpBool(boolValue);
    boolValue = NO;
    WCDumpBool(boolValue);
    
    WCDumpBool([self class] == [super class]);
}

- (void)test_WCDumpObject {
    WCDumpObject([self class]);
    WCDumpObject([super class]);
    WCDumpObject([self superclass]);
    
    WCDumpObject(@"");
    
    id nilValue = nil;
    WCDumpObject(nilValue);
    
    NSString *emptyStr= @"";
    WCDumpObject(emptyStr);
}

- (void)test_WCLog {
    NSString *message = @"message"      @", a.k.a msg";
    
    NSLog(@"[ApolloSDK] " @"log: %@", message);
    WCLog(@"log: %@", message);
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
    LogError(errorNil); // Will not print
    
    __unused NSError *error = [NSError errorWithDomain:@"domain" code:-1 userInfo:@{ NSLocalizedDescriptionKey: @"CAUTION! An error occurred." }];
    LogError(error); // Will print
}

- (void)test_ALog {
    ALog(@"%@", @"test Alert");
}

@end
