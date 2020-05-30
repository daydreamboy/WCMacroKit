//
//  Test_MacroDelegate.m
//  Test
//
//  Created by wesley_chen on 2020/5/30.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

#define UITextFieldDelegateEnabled 0

#if UITextFieldDelegateEnabled
#define UITextFieldDelegateProtocol UITextFieldDelegate
#else
WCDummyProtocol(UITextFieldDelegate)
#define UITextFieldDelegateProtocol WCDummyProtocol_UITextFieldDelegate
#endif

@interface Test_MacroDelegate : XCTestCase <UITextFieldDelegateProtocol>

@end

@implementation Test_MacroDelegate

- (void)setUp {
    NSLog(@"\n");
}

- (void)tearDown {
    NSLog(@"\n");
}

#pragma mark - Delegate caller

- (void)test_DELEGATE_SAFE_CALL2 {
    DELEGATE_SAFE_CALL2(self, @selector(delegateMethodWithSender:YESBoolValue:), self, @(YES));
}

#pragma mark > Sample methods

- (void)delegateMethodWithSender:(id)sender YESBoolValue:(NSNumber *)yesOrNo {
    XCTAssert(sender == self);
    XCTAssert([yesOrNo boolValue] == YES);
}

@end
