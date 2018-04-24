//
//  Test_DelegateCaller.m
//  Test
//
//  Created by wesley_chen on 2018/4/23.
//

#import <XCTest/XCTest.h>
#import "WCMacroKit.h"

@interface Test_DelegateCaller : XCTestCase

@end

@implementation Test_DelegateCaller

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)test_DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE {    
    
    BOOL returnYES = DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnYES"), BOOL, NO);
    XCTAssertTrue(returnYES);
    
    int returnInt = DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnInt"), int, 0);
    XCTAssert(returnInt == 1);
    
    double returnDouble = DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnDouble"), double, 0);
    XCTAssert(returnDouble == 3.14);
    
    CGFloat returnCGFloat = DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnCGFloat"), CGFloat, 0);
    XCTAssert(returnCGFloat == 3.15f);
    
    int returnDefaultInt = DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnInt2"), int, 0);
    XCTAssert(returnDefaultInt == 0);
}

- (void)test_DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE {
    BOOL returnWithBoolString = DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnWithBoolString:"), BOOL, NO, @"true");
    XCTAssertTrue(returnWithBoolString);
    
    int returnWithIntString = DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnWithIntString:"), int, 0, @"1");
    XCTAssert(returnWithIntString == 1);
    
    int returnWithNilString = DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnWithNilString:"), int, 0, nil);
    XCTAssert(returnWithNilString == -1);
    
    double returnWithDoubleString = DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, NSSelectorFromString(@"returnWithDoubleString:"), double, 0, @"3.14");
    XCTAssert(returnWithDoubleString == 3.14);
}

#pragma mark - Tested Callee Methods

#pragma mark > with no args

- (BOOL)returnYES {
    return YES;
}

- (int)returnInt {
    return 1;
}

- (double)returnDouble {
    return 3.14;
}

- (CGFloat)returnCGFloat {
    return 3.15f;
}

#pragma mark > with 1 args

- (BOOL)returnWithBoolString:(NSString *)string {
    return [string boolValue];
}

- (int)returnWithIntString:(NSString *)string {
    return [string intValue];
}

- (double)returnWithDoubleString:(NSString *)string {
    return [string doubleValue];
}

- (int)returnWithNilString:(NSString *)string {
    if (string == nil) {
        return -1;
    }
    return [string intValue];
}

@end
