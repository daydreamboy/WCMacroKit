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

#pragma mark - NSArray

- (void)test_NSARRAY_M_SAFE_SET {
    NSMutableArray *arrM1 = [NSMutableArray arrayWithObjects:@"1", @"2", @"3", @"4", @"5", nil];
    NSARRAY_M_SAFE_SET(arrM1, 0, @"6");
    XCTAssertEqualObjects(arrM1[0], @"6");
    
    NSMutableArray *arrM2 = [NSMutableArray array];
    NSARRAY_M_SAFE_SET(arrM1, 0, @"7");
    XCTAssertTrue(arrM2.count == 0);
}

- (void)test_NSARRAY_M_SAFE_ADD {
    NSMutableArray *arrM1 = [NSMutableArray array];

    NSARRAY_M_SAFE_ADD(arrM1, @"1");
    NSARRAY_M_SAFE_ADD(arrM1, @"2");
    NSARRAY_M_SAFE_ADD(arrM1, @"");
    id nilValue = nil;
    NSARRAY_M_SAFE_ADD(arrM1, nilValue);
    XCTAssertTrue(arrM1.count == 3);
    
    NSMutableArray *arrM2 = [NSMutableArray arrayWithObjects:@"1", @"2", @"3", nil];
    NSARRAY_M_SAFE_ADD(arrM2, @"4");
    NSARRAY_M_SAFE_ADD(arrM2, @"5");
    NSARRAY_M_SAFE_ADD(arrM2, nil);
    XCTAssertTrue(arrM2.count == 5);
}

- (void)test_NSARRAY_SAFE_GET {
    NSArray *arr1 = [NSArray arrayWithObjects:@"1", @"2", @"3", @"4", @"5", nil];
    NSString *firstObject = NSARRAY_SAFE_GET(arr1, 0);
    NSLog(@"%@", firstObject);
    
    XCTAssertEqualObjects(NSARRAY_SAFE_GET(arr1, 0), @"1");
    XCTAssertNil(NSARRAY_SAFE_GET(arr1, 5));
    
    NSArray *arr2 = nil;
    XCTAssertNil(NSARRAY_SAFE_GET(arr2, 0));
    
    NSArray *arr3 = [NSArray array];
    XCTAssertNil(NSARRAY_SAFE_GET(arr3, 0));
}

#pragma mark - NSDictionary

- (void)test_NSDICTIONARY_M_PAIRS_DEFINE {
    // Case 1
    NSDICTIONARY_M_PAIRS_DEFINE(dictM,
        NSDICTIONARY_M_PAIRS_SET(@"key1", @"string")
        NSDICTIONARY_M_PAIRS_SET(@"key1", @YES)
        NSDICTIONARY_M_PAIRS_SET(@"key1", @1)
    );
    
    XCTAssertTrue(dictM.count == 1);
    
    // Case 2
    NSDICTIONARY_M_PAIRS_DEFINE(dictM2,
        NSDICTIONARY_M_PAIRS_SET(@"key1", @"string")
        NSDICTIONARY_M_PAIRS_SET(@"key2", @YES)
        NSDICTIONARY_M_PAIRS_SET(@"key3", @1)
    );
    
    XCTAssertTrue(dictM2.count == 3);
    
    // Case 3
    NSDICTIONARY_M_PAIRS_DEFINE(dictM3,
        NSDICTIONARY_M_PAIRS_SET(@"key1", @"string")
        NSDICTIONARY_M_PAIRS_SET(@"key2", nil)
        NSDICTIONARY_M_PAIRS_SET(nil, @1)
    );
    
    XCTAssertTrue(dictM3.count == 1);
}

- (void)test_NSDICTIONARY_M_PAIRS_BEGIN_WITH_RETURN {

    NSMutableDictionary *data = NSDICTIONARY_M_PAIRS_RETURN(
        NSDICTIONARY_M_PAIRS_SET(@"a", @"A");
        NSDICTIONARY_M_PAIRS_SET(@"b", @"B");
        NSDICTIONARY_M_PAIRS_SET(@"c", nil);
        NSDICTIONARY_M_PAIRS_SET(nil, @"D");
    );
    
    XCTAssertTrue(data.count == 2);
    XCTAssertEqualObjects(data[@"a"], @"A");
    XCTAssertEqualObjects(data[@"a"], @"A");
    XCTAssertNil(data[@"c"]);
}

- (void)test_NSDICTIONARY_SAFE_GET {
    NSDictionary *dict;
    id value;
    
    // Case 1
    value = NSDICTIONARY_SAFE_GET(dict, @"keyNotExists", nil);
    XCTAssertNil(value);
    
    // Case 2
    dict = @{
             @"key": @"value"
             };
    value = NSDICTIONARY_SAFE_GET(dict, @"keyNotExists", nil);
    XCTAssertNil(value);

    // Case 3
    dict = @{
             @"key": [NSDate date]
             };
    value = NSDICTIONARY_SAFE_GET(dict, @"key", NSString);
    XCTAssertNil(value);
    
    value = NSDICTIONARY_SAFE_GET(dict, @"key", nil);
    XCTAssertNotNil(value);
    XCTAssertTrue([value isKindOfClass:[NSDate class]]);
    
    value = NSDICTIONARY_SAFE_GET(dict, @"key", @"");
    XCTAssertNotNil(value);
    XCTAssertTrue([value isKindOfClass:[NSDate class]]);
    
    // Case 4
    dict = @{
             @"key": @"date"
             };
    value = NSDICTIONARY_SAFE_GET(dict, @"key", NSString);
    XCTAssertEqualObjects(value, @"date");
}

#pragma mark > Safe Get Value

- (void)test_ValueOfXXX {
    NSDictionary *layoutJson = @{};
    NSString *name = ValueOfString(layoutJson[@"name"]);
    
    name = ([(layoutJson[@"name"]) isKindOfClass:[NSString class]] ? (layoutJson[@"name"]) : nil);
}

#pragma mark > Key Value Pair Suite

- (void)test_key_value_pair_suite {
    NSArray<KeyValuePairType> *pairs;
    
    pairs = @[
              KeyValuePair(@"cancel", nil),
              KeyValuePair(@"event", @"module"),
              @[@1, @2, @3]
              ];
    
    for (NSInteger i = 0; i < pairs.count; i++) {
        KeyValuePairType pair = pairs[i];
        
        if (i == 0) {
            NSString *key = KeyOfPair(pair);
            NSString *value = ValueOfPair(pair);
            
            XCTAssertEqualObjects(key, @"cancel");
            XCTAssertNil(value);
        }
        else if (i == 1) {
            NSString *key = KeyOfPair(pair);
            NSString *value = ValueOfPair(pair);
            
            XCTAssertEqualObjects(key, @"event");
            XCTAssertEqualObjects(value, @"module");
        }
        else if (i == 2) {
            BOOL isPair = KeyValuePairValidate(pair);
            XCTAssertFalse(isPair);
        }
    }
}

@end
