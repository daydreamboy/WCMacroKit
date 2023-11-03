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

@end
