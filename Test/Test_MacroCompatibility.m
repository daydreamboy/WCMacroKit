//
//  Test_MacroCompatibility.m
//  Test
//
//  Created by wesley_chen on 2020/2/25.
//

#import <XCTest/XCTest.h>
#import <WCMacroKit/WCMacroKit.h>

@interface Test_MacroCompatibility : XCTestCase

@end

@implementation Test_MacroCompatibility

- (void)test_iflet {
    iflet(NSString *value, [self returnNil]) {
        NSString *newValue = [NSString stringWithFormat:@"%@", value];
        NSLog(@"%@", newValue);
    }
    else {
        NSLog(@"value is nil");
    }

    iflet(NSString *value, [self notReturnNil]) {
        NSString *newValue = [NSString stringWithFormat:@"%@", value];
        NSLog(@"%@", newValue);
    }
    else {
        NSLog(@"value is nil");
    }
    
    NSString *returnValue;
    
    do {
        iflet(NSString *value, [self notReturnNil]) {
            NSString *newValue = [NSString stringWithFormat:@"%@", value];
            NSLog(@"%@", newValue);
            returnValue = newValue;
            goto end;
            // Note: break not work here, because iflet is not a ture if clause
            //break;
        }
        
        NSLog(@"should not print");
    } while (NO);
    end:
    NSLog(@"the end");
}

- (void)test_ifletwhere {
    ifletwhere(NSString *value, [self returnNil], [value isKindOfClass:[NSString class]] && [value hasPrefix:@"I"]) {
        NSString *newValue = [NSString stringWithFormat:@"%@", value];
        NSLog(@"%@", newValue);
    }
    else {
        NSLog(@"value is nil or not have a prefix 'I'");
    }
    
    ifletwhere(NSString *value, [self notReturnNil], [value isKindOfClass:[NSString class]] && [value hasPrefix:@"I"]) {
        NSString *newValue = [NSString stringWithFormat:@"%@", value];
        NSLog(@"`%@` have a prefix 'I'", newValue);
    }
    else {
        NSLog(@"value is nil");
    }
}

- (void)test_XCODE15_OR_LATER_COMPILED {
#if XCODE15_OR_LATER_COMPILED
    NSLog(@"This code is compiled with Xcode15 or later");
#else
    NSLog(@"This code is NOT compiled with Xcode15 or later");
#endif
}

#pragma mark - Dummy Methods

- (NSString *)returnNil {
    return nil;
}

- (NSString *)notReturnNil {
    return @"It's not nil";
}

@end
