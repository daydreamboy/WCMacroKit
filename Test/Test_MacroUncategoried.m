//
//  Test_MacroUncategoried.m
//  Test
//
//  Created by wesley_chen on 2020/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroUncategoried : XCTestCase

@end

@implementation Test_MacroUncategoried

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

- (void)test_NILABLE {
    NSString *nilString;
    NSArray *arr = @[@"aString"];
    
    // @warning Only use NILABLE wrap/re-wrap values of literal NSDictionary
    NSDictionary *dict = @{
                           @"maybe nil": NILABLE(nilString), // Ok, value is nil
                           @"arr": NILABLE(arr),
                           @"dict": @{ @"key": @"value"},
                           };
    
    XCTAssertEqualObjects(dict[@"maybe nil"], @"(null)");
    XCTAssertNotNil(dict[@"arr"]);
    XCTAssertEqual(dict[@"arr"], arr);
    XCTAssertEqual(NILABLE(dict[@"arr"]), arr);
    NSDictionary *dictValue = NILABLE(dict[@"dict"]);
    XCTAssertTrue([dictValue isKindOfClass:[NSDictionary class]]);
}

#pragma mark -

- (void)test_FrameSetSize {
    CGSize size;
    CGRect frame;
    CGRect output;
    
    // Case 1
    size = CGSizeMake(200, 200);
    frame = CGRectMake(10, 10, 100, 100);
    output = FrameSetSize(frame, size.width, size.height);
    XCTAssertTrue(output.size.width == 200 && output.size.height == 200);
    
    // Case 2
    size = CGSizeMake(200, 200);
    frame = CGRectMake(10, 10, 100, 100);
    output = FrameSetSize(frame, size.width, NAN);
    XCTAssertTrue(output.size.width == 200 && output.size.height == 100);
}

- (void)test_TIMESTAMP_FOR_CURRENT_FILE {
    NSLog(@"current file timestamp: %@", TIMESTAMP_FOR_CURRENT_FILE);
}

- (void)test_CHECK_VALUE_suite {
    // Case 1
    CHECK_VALUE_BEGIN(NSString *, link1, @"this is initial value")
    CHECK_VALUE_END

    XCTAssertEqualObjects(link1, @"this is initial value");

    // Case 2
    NSDictionary *dict2 = @{
        @"value": @"1",
    };
    CHECK_VALUE_BEGIN(NSString *, link2, @"this is initial value")
    CHECK_VALUE_CASE(dict2[@"value"], STR_IF_NOT_EMPTY(tempValue_))
    CHECK_VALUE_END

    XCTAssertEqualObjects(link2, @"1");
    
    // Case 3
    NSDictionary *dict3 = @{
        @"value1": @"",
        @"value2": @"2",
    };
    CHECK_VALUE_BEGIN(NSString *, link3, @"this is initial value")
    CHECK_VALUE_CASE(dict3[@"value1"], STR_IF_NOT_EMPTY(tempValue_))
    CHECK_VALUE_CASE(dict3[@"value2"], STR_IF_NOT_EMPTY(tempValue_))
    CHECK_VALUE_END

    XCTAssertEqualObjects(link3, @"2");
    
    // Case 4
    NSDictionary *dict4 = @{
        @"value": @"1",
    };
    CHECK_VALUE_BEGIN(NSString *, link4, nil)
    CHECK_VALUE_CASE(dict4[@"value"], STR_IF_NOT_EMPTY(tempValue_))
    CHECK_VALUE_END

    XCTAssertEqualObjects(link4, @"1");
}

@end
