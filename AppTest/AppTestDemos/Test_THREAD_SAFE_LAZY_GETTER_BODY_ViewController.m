//
//  Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController.m
//  AppTest
//
//  Created by wesley_chen on 01/03/2018.
//

#import "Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController.h"
#import "WCMacroKit.h"

@interface Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController ()
@property (nonatomic, strong) NSString *sharedString;
@end

@implementation Test_THREAD_SAFE_LAZY_GETTER_BODY_ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
    [NSThread detachNewThreadSelector:@selector(printSharedString) toTarget:self withObject:nil];
}

/*
- (NSString *)sharedString {
    NSTimeInterval timestamp = [[NSDate date] timeIntervalSince1970];
    if (!_sharedString) {
        _sharedString = [NSString stringWithFormat:@"str: %f", (double)timestamp];
    }

    return _sharedString;
}
 */

- (NSString *)sharedString {
    NSTimeInterval timestamp = [[NSDate date] timeIntervalSince1970];
    NSLog(@"now: %f", (double)timestamp);
    // Note: THREAD_SAFE_LAZY_GETTER_BODY带三个参数，后面的逗号不是参数分隔符
    THREAD_SAFE_LAZY_GETTER_BODY(sharedString,
                                 _sharedString,
                                 _sharedString = [NSString stringWithFormat:@"str: %f", (double)timestamp];
                                 )
}

#pragma mark - Thread Entry

- (void)printSharedString {
    // Note: 应该输出是一样的
    NSLog(@"%@", self.sharedString);
}

@end
