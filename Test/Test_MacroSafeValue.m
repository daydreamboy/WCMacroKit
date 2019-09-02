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

- (void)test_JSONObjectFromJSONString {
    id output;
    
    // Case 1
    output = JSONObjectFromJSONString(
    {
        "attr" : {
            "viewValue" : [
                           {
                               "style" : {
                                   "width" : 12,
                                   "height" : 11
                               },
                               "attr" : {
                                   "viewValue" : "https:\/\/img.alicdn.com\/tfs\/TB1G9HKX6rguuRjy0FeXXXcbFXa-120-110.png",
                                   "viewType" : "webImage",
                                   "imageType" : "url",
                                   "image" : "https:\/\/img.alicdn.com\/tfs\/TB1G9HKX6rguuRjy0FeXXXcbFXa-120-110.png"
                               }
                           },
                           {
                               "style" : {
                                   "fontColor" : "#878787",
                                   "fontSize" : 10
                               },
                               "attr" : {
                                   "textType" : "text",
                                   "viewValue" : "收起",
                                   "viewType" : "text",
                                   "text" : "收起"
                               }
                           }
                           ],
            "viewType" : "horizontal"
        },
        "action" : {
            "actionType" : "custom",
            "actionValue" : "event.header.subTitle.click"
        }
    }
    );
    
    XCTAssertNotNil(output);
    XCTAssertTrue([output isKindOfClass:[NSDictionary class]]);
    
    // Case 2
    output = JSONObjectFromJSONString({"a":b});
    XCTAssertNil(output);
}

- (void)test_TEMP_FILE_PATH_NEW {
    NSString *filePath1 = TEMP_FILE_PATH_NEW(nil);
    NSString *filePath2 = TEMP_FILE_PATH_NEW(@"txt");
    
    NSLog(@"%@", filePath1);
    NSLog(@"%@", filePath2);
}

- (void)test_NSDICTIONARY_SAFE_WRAP {
    NSDictionary *dict;
    id keyMaybeNil = nil;
    id valueMaybeNil = nil;
    
    // Case 1
    dict = NSDICTIONARY_SAFE_WRAP(@{
                                    keyMaybeNil: @"value"
                                    });
    XCTAssertNil(dict);
    
    // Case 2
    dict = NSDICTIONARY_SAFE_WRAP(@{
                                    @"key": valueMaybeNil
                                    });
    XCTAssertNil(dict);
    
    // Case 3
    dict = NSDICTIONARY_SAFE_WRAP(@{
                                    keyMaybeNil: @"value",
                                    @"key": valueMaybeNil
                                    });
    XCTAssertNil(dict);
    
    
    // Case 4
    dict = NSDICTIONARY_SAFE_WRAP(@{
                                    @"key1": @"value1",
                                    @"key2": @"value2"
                                    });
    XCTAssertTrue(dict.count == 2);
    XCTAssertNotNil(dict);
}

- (void)test_NSARRAY_SAFE_WRAP {
    NSArray *arr;
    id objectMaybeNil = nil;
    
    // Case 1
    arr = NSARRAY_SAFE_WRAP(@[ @"1", @"2", objectMaybeNil ]);
    XCTAssertNil(arr);
    
    // Case 2
    arr = NSARRAY_SAFE_WRAP(@[ @"1", @"2", @"3" ]);
    XCTAssertTrue(arr.count == 3);
    XCTAssertNotNil(arr);
}

#pragma mark - Dollor Sign

- (void)test_$dict {
    NSDictionary *dict;
    id keyMaybeNil = nil;
    id valueMaybeNil = nil;
    
    // Case 1
    dict = $dict(@{
                   keyMaybeNil: @"value"
                   });
    XCTAssertNil(dict);
    
    // Case 2
    dict = $dict(@{
                   @"key": valueMaybeNil
                   });
    XCTAssertNil(dict);
    
    // Case 3
    dict = $dict(@{
                   keyMaybeNil: @"value",
                   @"key": valueMaybeNil
                   });
    XCTAssertNil(dict);
    
    
    // Case 4
    dict = $dict(@{
                   @"key1": @"value1",
                   @"key2": @"value2"
                   });
    XCTAssertTrue(dict.count == 2);
    XCTAssertNotNil(dict);
}

- (void)test_$arr {
    NSArray *arr;
    id objectMaybeNil = nil;
    
    // Case 1
    arr = $arr(@[ @"1", @"2", objectMaybeNil ]);
    XCTAssertNil(arr);
    
    // Case 2
    arr = $arr(@[ @"1", @"2", @"3" ]);
    XCTAssertTrue(arr.count == 3);
    XCTAssertNotNil(arr);
}

@end
