//
//  Test_GCCMacro.m
//  Test
//
//  Created by wesley_chen on 2023/1/7.
//

#import <XCTest/XCTest.h>

@interface Test_GCCMacro : XCTestCase

@end

@implementation Test_GCCMacro

- (void)test___PRETTY_FUNCTION__ {
    printf ("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
}

- (void)test_check__PRETTY_FUNCTION__ {
#if defined(__GNUC__)
    printf ("__PRETTY_FUNCTION__ = %s\n", __PRETTY_FUNCTION__);
#endif
}

@end
