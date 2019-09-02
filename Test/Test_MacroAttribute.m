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


@interface Test_MacroAttribute : XCTestCase

@end

@implementation Test_MacroAttribute

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

@end
