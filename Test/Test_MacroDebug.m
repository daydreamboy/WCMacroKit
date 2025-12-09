//
//  Test_MacroDebug.m
//  Test
//
//  Created by wesley_chen on 2025/12/9.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroDebug : XCTestCase

@end

@implementation Test_MacroDebug

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
    
    WCDumpPrimitiveValue(c);
    WCDumpPrimitiveValue(d);
    WCDumpPrimitiveValue(f);
    WCDumpPrimitiveValue(i);
    WCDumpPrimitiveValue(l);
    WCDumpPrimitiveValue(ll);
    WCDumpPrimitiveValue(s);
    WCDumpPrimitiveValue(ui);
    
    WCDumpPrimitiveValue(self);
    
    // Compile Error: Cannot take the address of an rvalue of type 'BOOL' (aka '_Bool')
    //WCDumpPrimitiveValue(YES);
}

- (void)test_WCDumpClassByName {
    WCDumpClassByName("Test_MacroLog");
}

- (void)test_WCDumpMetaClassByName {
    WCDumpMetaClassByName("Test_MacroLog");
}

@end
