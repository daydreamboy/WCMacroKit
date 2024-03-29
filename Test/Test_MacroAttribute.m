//
//  Test_MacroAttribute.m
//  Test
//
//  Created by wesley_chen on 2019/9/1.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

WC_RESTRICT_SUBCLASSING
@interface SuperClassNotSupportClassing : NSObject
@end

@implementation SuperClassNotSupportClassing
@end

/*
@interface ChildClass : SuperClassNotSupportClassing
@end

@implementation ChildClass
@end
 */

WC_DECLARE_EXTERNAL_FUNC(NSString *, someLog(NSString *message), nil);
WC_DECLARE_EXTERNAL_FUNC(void, someLogWithoutReturn(NSString *message, NSString *type), 0);
WC_DECLARE_EXTERNAL_CONST(NSString *, global_const, @"");

// Error: should not declare the global constant again
//NSString *global_const = @"bbbbb";

@interface Test_MacroAttribute : XCTestCase

@end

@implementation Test_MacroAttribute

- (void)test_WC_DECLARE_EXTERNAL_FUNC {
    NSString *output;
    output = someLog(@"1");
    XCTAssertEqualObjects(output, @"1");
    
    output = someLog(@"2");
    XCTAssertEqualObjects(output, @"2");
    
    someLogWithoutReturn(@"3", @"info");
}

- (void)test_WC_DECLARE_EXTERNAL_CONST {
    NSLog(@"%@", global_const);
    XCTAssertEqualObjects(global_const, @"global_const");
}

@end
