//
//  Test_DelegateCaller_DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE.m
//  Test
//
//  Created by wesley_chen on 2018/4/23.
//

#import <XCTest/XCTest.h>
#import "WCMacroKit.h"

@interface Test_DelegateCaller_DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE : XCTestCase

@end

@implementation Test_DelegateCaller_DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)test_INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE {    
    
    BOOL returnYES = INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, @"returnYES", BOOL, NO);
    XCTAssertTrue(returnYES);
    
    int returnInt = INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, @"returnInt", int, 0);
    XCTAssert(returnInt == 1);
    
    double returnDouble = INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, @"returnDouble", double, 0);
    XCTAssert(returnDouble == 3.14);
    
    CGFloat returnCGFloat = INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, @"returnCGFloat", CGFloat, 0);
    XCTAssert(returnCGFloat == 3.15f);
    
    int returnDefaultInt = INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(self, @"returnInt2", int, 0);
    XCTAssert(returnDefaultInt == 0);
}

- (void)test_INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE {
    BOOL returnWithBoolString = INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, @"returnWithBoolString:", BOOL, NO, @"true");
    XCTAssertTrue(returnWithBoolString);
    
    int returnWithIntString = INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, @"returnWithIntString:", int, 0, @"1");
    XCTAssert(returnWithIntString == 1);
    
    int returnWithNilString = INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, @"returnWithNilString:", int, 0, nil);
    XCTAssert(returnWithNilString == -1);
    
    double returnWithDoubleString = INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(self, @"returnWithDoubleString:", double, 0, @"3.14");
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
