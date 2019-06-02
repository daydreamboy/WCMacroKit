//
//  Test_MacroSafeValue.m
//  Test
//
//  Created by wesley_chen on 2019/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroSafeValue : XCTestCase

@end

@implementation Test_MacroSafeValue

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)test_doubleValueOfJSONValue {
    id JSONValue;
    double output;
    
    // Case 1
    JSONValue = @(3.14);
    output = doubleValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14);
    
    JSONValue = @"3.14";
    output = doubleValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14);
    
    JSONValue = @"3.14a";
    output = doubleValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14);
    
    JSONValue = nil;
    output = doubleValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
    
    JSONValue = [NSDictionary dictionary];
    output = doubleValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
}

- (void)test_floatValueOfJSONValue {
    id JSONValue;
    float output;
    
    JSONValue = @(3.14);
    output = floatValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14f);
    
    JSONValue = @"3.14";
    output = floatValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14f);
    
    JSONValue = @"3.14a";
    output = floatValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3.14f);
    
    JSONValue = nil;
    output = floatValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
    
    JSONValue = [NSDictionary dictionary];
    output = floatValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
}

- (void)test_intValueOfJSONValue {
    id JSONValue;
    int output;
    
    // Case 1
    JSONValue = @(3.14);
    output = intValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3.14";
    output = intValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3a";
    output = intValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = nil;
    output = intValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
    
    JSONValue = [NSDictionary dictionary];
    output = intValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
}

- (void)test_integerValueOfJSONValue {
    id JSONValue;
    NSInteger output;
    
    // Case 1
    JSONValue = @(3.14);
    output = integerValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3.14";
    output = integerValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3a";
    output = integerValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = nil;
    output = integerValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
    
    JSONValue = [NSDictionary dictionary];
    output = integerValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
}

- (void)test_longLongValueOfJSONValue {
    id JSONValue;
    long long output;
    
    // Case 1
    JSONValue = @(3.14);
    output = longLongValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3.14";
    output = longLongValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = @"3a";
    output = longLongValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 3);
    
    JSONValue = nil;
    output = longLongValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
    
    JSONValue = [NSDictionary dictionary];
    output = longLongValueOfJSONValue(JSONValue);
    XCTAssertTrue(output == 0);
}

- (void)test_boolValueOfJSONValue {
    id JSONValue;
    BOOL output;
    
    // Case 1
    JSONValue = @(3.14);
    output = boolValueOfJSONValue(JSONValue);
    XCTAssertTrue(output);
    
    JSONValue = @"3.14";
    output = boolValueOfJSONValue(JSONValue);
    XCTAssertTrue(output);
    
    JSONValue = nil;
    output = boolValueOfJSONValue(JSONValue);
    XCTAssertFalse(output);
    
    JSONValue = [NSDictionary dictionary];
    output = boolValueOfJSONValue(JSONValue);
    XCTAssertFalse(output);
}

- (void)test_stringValueOfJSONValue {
    id JSONValue;
    NSString *output;
    
    // Case 1
    JSONValue = @(3.14);
    output = stringValueOfJSONValue(JSONValue);
    XCTAssertEqualObjects(output, @"3.14");
    
    JSONValue = @"3.14";
    output = stringValueOfJSONValue(JSONValue);
    XCTAssertEqualObjects(output, @"3.14");
    
    JSONValue = nil;
    output = stringValueOfJSONValue(JSONValue);
    XCTAssertNil(output);
    
    JSONValue = [NSDictionary dictionary];
    output = stringValueOfJSONValue(JSONValue);
    XCTAssertNil(output);
}

@end
