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

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)test_NSAssertOrReturnNil {
    NSString *nilValue = [self callee_NSAssertOrReturnNil];
    NSAssert(nilValue == nil, @"should be nil");
    
    // TODO:
    // NSAssertOrBreak
    // NSAssertOrContinue
}

- (void)test_NSAssertOrReturnNO {
    BOOL noValue = [self callee_NSAssertOrReturnNO];
    NSAssert(noValue == NO, @"should be NO");
}

- (void)test_NSAssertOrReturn {
    NSAssertOrReturn(NO, @"test NSAssertOrReturn");
    
    NSLog(@"will never output");
}

#pragma mark - Callee

- (NSString *)callee_NSAssertOrReturnNil {
    NSAssertOrReturnNil(NO, @"test NSAssertOrReturnNil");
    
    return @"a string";
}

- (BOOL)callee_NSAssertOrReturnNO {
    NSAssertOrReturnNO(NO, @"test NSAssertOrReturnNO");
    
    return YES;
}
@end
