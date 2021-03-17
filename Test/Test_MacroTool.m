//
//  Test_MacroTool.m
//  Test
//
//  Created by wesley_chen on 2019/3/9.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroTool : XCTestCase

@end

@implementation Test_MacroTool

- (void)setUp {
    [super setUp];
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
    [super tearDown];
}

#pragma mark - Test Methods

- (void)test_NSArrayFromVaList {
    NSArray *output;
    
    // Case 1
    output = [self showAlertWithTitle:@"title" message:@"message", @"button1", @1, @"button2", @2, nil];
    XCTAssertTrue(output.count == 4);
    XCTAssertEqualObjects(output[0], @"button1");
    XCTAssertEqualObjects(output[1], @1);
    XCTAssertEqualObjects(output[2], @"button2");
    XCTAssertEqualObjects(output[3], @2);
    
    // Case 2
    output = [self showAlertWithTitle:@"title" message:@"message", nil];
    XCTAssertNotNil(output);
    XCTAssertTrue(output.count == 0);
}

- (void)test_DICT_MERGE {
    NSDictionary *dict1;
    NSDictionary *dict2;
    NSDictionary *output;
    
    // Case 1
    output = DICT_MERGE(dict1, dict2);
    XCTAssertNotNil(output);
    XCTAssertTrue(output.count == 0);
    
    // Case 2
    dict1 = @{ @"1": @1, @"2": @2 };
    dict2 = @{ @"3": @3 };
    output = DICT_MERGE(dict1, dict2);
    XCTAssertTrue(output.count == 3);
}

- (void)test_DICT_MERGE_M {
    NSDictionary *dict1;
    NSDictionary *dict2;
    NSMutableDictionary *output;
    
    // Case 1
    output = DICT_MERGE_M(dict1, dict2);
    XCTAssertNotNil(output);
    XCTAssertTrue(output.count == 0);
    
    // Case 2
    dict1 = @{ @"1": @1, @"2": @2 };
    dict2 = @{ @"3": @3 };
    output = DICT_MERGE_M(dict1, dict2);
    [output addEntriesFromDictionary:@{ @"4": @4 }];
    XCTAssertTrue(output.count == 4);
}

#pragma mark - Dummy Methods

- (NSArray *)showAlertWithTitle:(NSString *)title message:(NSString *)message, ... NS_REQUIRES_NIL_TERMINATION {
    NSArray *args = NSArrayFromVaList(message);
    return args;
}

@end
