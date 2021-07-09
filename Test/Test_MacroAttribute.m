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

WC_DECLARE_EXTERNAL_FUNC(NSString *, someLog(NSString *message));
WC_DECLARE_EXTERNAL_FUNC(void, someLogWithoutReturn(NSString *message));

@interface Test_MacroAttribute : XCTestCase

@end

@implementation Test_MacroAttribute

- (void)test_WC_DECLARE_EXTERNAL_FUNC {
    NSString *output;
    output = someLog(@"1");
    XCTAssertEqualObjects(output, @"1");
    
    output = someLog(@"2");
    XCTAssertEqualObjects(output, @"2");
    
    someLogWithoutReturn(@"3");
}

@end
