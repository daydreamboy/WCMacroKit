//
//  Test_MacroAssert.m
//  Test
//
//  Created by wesley_chen on 2020/8/20.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroAssert : XCTestCase

@end

@implementation Test_MacroAssert

- (void)test_NSAssertThenReturnNil {
    NSString *nilValue = [self callee_NSAssertThenReturnNil];
    NSAssert(nilValue == nil, @"should be nil");
    
    // TODO:
    // NSAssertThenBreak
    // NSAssertThenContinue
}

- (void)test_NSAssertThenReturnNO {
    BOOL noValue = [self callee_NSAssertThenReturnNO];
    NSAssert(noValue == NO, @"should be NO");
}

- (void)test_NSAssertThenReturn {
    NSAssertThenReturn(NO, @"test NSAssertThenReturn");
    
    NSLog(@"will never output");
}

#pragma mark - Callee

- (NSString *)callee_NSAssertThenReturnNil {
    NSAssertThenReturnNil(NO, @"test NSAssertThenReturnNil");
    
    return @"a string";
}

- (BOOL)callee_NSAssertThenReturnNO {
    NSAssertThenReturnNO(NO, @"test NSAssertThenReturnNO");
    
    return YES;
}
@end
