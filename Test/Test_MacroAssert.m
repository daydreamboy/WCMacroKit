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

- (void)test_NSAssertThenDoNothing {
    NSAssertThenDoNothing(NO, @"result is NO will trigger this exception breakpoint");
}

- (void)test_NSAssertThenReturnNil {
    NSString *nilValue = [self callee_NSAssertThenReturnNil];
    NSAssert(nilValue == nil, @"should be nil");
}

- (void)test_NSAssertThenBreak {
    BOOL result = NO;
    
    // Case 1
    do {
        NSAssertThenBreak(NO, @"use this macro in loop%@", @(1));
        
        result = YES;
    } while (NO);
    
    XCTAssertFalse(result);
    
    // Case 2
    do {
        @try {
            [NSException raise:@"test" format:@"use this macro in loop%@", @(2)];
        }
        @catch (NSException *exception) {
            break;
        }
        
        result = YES;
    } while (NO);
    
    XCTAssertFalse(result);
    
    // Case 3
    NSInteger i = 0;
    for (; i < 10; ++i) {
        NSAssertThenBreak(NO, @"use this macro in loop%@", @(3));
        
        result = YES;
    }
    XCTAssertFalse(result);
    XCTAssertTrue(i == 0);
}

- (void)test_NSAssertThenContinue {
    BOOL result = NO;
    NSInteger i = 0;
    
    // Case 1
    for (; i < 10; ++i) {
        NSAssertThenContinue(NO, @"use this macro in loop%@", @(1));
        
        result = YES;
    }
    XCTAssertFalse(result);
    XCTAssertTrue(i == 10);
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
