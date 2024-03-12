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

- (void)test_WCDumpValue {
    char c = 'A';
    double d = 8.0;
    const float f = 3.375;
    int i = 10;
    long l = 1000L;
    long long ll = 1000LL;
    char s[] = "Hello,world";
    
    unsigned int ui = 20;
    
    WCDumpValue(c);
    WCDumpValue(d);
    WCDumpValue(f);
    WCDumpValue(i);
    WCDumpValue(l);
    WCDumpValue(ll);
    WCDumpValue(s);
    WCDumpValue(ui);
}

- (void)test_WCDumpClassByName {
    WCDumpClassByName("Test_MacroLog");
}

- (void)test_WCDumpMetaClassByName {
    WCDumpMetaClassByName("Test_MacroLog");
}

- (void)test_WCLog {
    NSString *message = @"message"      @", a.k.a msg";
    
    NSLog(@"[ApolloSDK] " @"log: %@", message);
    WCLog(@"log: %@", message);
    WCLog(@"This is a log");
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
